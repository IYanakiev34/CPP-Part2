#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

class Options
{
    std::string d_options;
    std::string *d_args;
    size_t d_nArgs;

    class Destructor
    {
        Options *d_options;

    public:
        [[nodiscard]] bool optionsAvailable() const;
        Options &operator*() const;
        void operator=(Options *options); // NOLINT (we were told to use void return type)

    private:
        // Want the destructor to automatically be called when the program exits, so I don't want it called elsewhere
        ~Destructor();
    };

    /* Static objects are automatically destroyed when the program exits, and the Destructor destructor calls
       the Options destructor */
    static Destructor s_destructor;

public:
    Options(Options const &other) = delete;

    // NOTE changed int params to size_t (don't think argc is ever negative)
    static Options &initialize(size_t argc, char **argv);
    static Options &instance();

    // Made these nodiscard per clang advice
    [[nodiscard]] bool option(int ch) const;
    [[nodiscard]] size_t nArgs() const;

    // index operator(s) returning the indexed argument
    // don't think we need 2 since you don't change the options?
    std::string const &operator[](size_t idx) const;

private:
    Options(size_t argc, char **argv);
    ~Options();

    // Added fill options and fill args here
    void fillOptions(size_t argc, char **argv);
    void fillArgs(size_t argc, char **argv);
};

inline bool Options::option(int ch) const
{
    return d_options.find(static_cast<char>(ch)) != std::string::npos;
}

inline size_t Options::nArgs() const
{
    return d_nArgs;
}

inline bool Options::Destructor::optionsAvailable() const
{
    return d_options != nullptr;
}

inline Options &Options::Destructor::operator*() const
{
    return *d_options;
}

inline void Options::Destructor::operator=(Options *options)
{
    d_options = options;
}

inline Options::Destructor::~Destructor()
{
    delete d_options;
}

// Modified options destructor after adding the destructor class
inline Options::~Options()
{
    delete[] d_args;
}

#endif
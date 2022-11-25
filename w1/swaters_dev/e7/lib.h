#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <iostream>

class Options {
    std::string d_options;
    std::string *d_args;
    size_t d_nArgs;

    class Destructor;

    static Destructor s_destructor;

public:
    Options(Options const &other) = delete;

    static Options &initialize(size_t argc, char **argv);

    static Options &instance();

    [[nodiscard]] bool option(int ch) const;

    [[nodiscard]] size_t nArgs() const;

    // index operator(s) returning the indexed argument
    [[nodiscard]] std::string const &operator[](size_t idx) const;

private:
    Options(size_t argc, char **argv);

    void fillOptions(size_t argc, char **argv);

    void fillArgs(size_t argc, char **argv);

    ~Options();
};

class Options::Destructor {
public:
    ~Destructor();

    [[nodiscard]] bool optionsAvailable() const;

    Options &operator*() const;

    void operator=(Options *options); // NOLINT (told to make this void)

private:
    Options *d_options;
};

// Options inlines
inline bool Options::option(int ch) const {
    return d_options.find(static_cast<char>(ch)) != std::string::npos;
}

inline size_t Options::nArgs() const {
    return d_nArgs;
}

inline Options::~Options() {
    delete[] d_args;
}

// Destructor inline functions
inline bool Options::Destructor::optionsAvailable() const {
    return d_options != nullptr;
}

inline Options &Options::Destructor::operator*() const {
    return *d_options;
}

inline void Options::Destructor::operator=(Options *options) // NOLINT (see above)
{
    d_options = options;
}

inline Options::Destructor::~Destructor() {
    delete d_options;
}

#endif
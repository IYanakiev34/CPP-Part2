#ifndef INC_46_VSTRING_H
#define INC_46_VSTRING_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>


struct Vstring: private std::vector<std::string>
{
    typedef std::map<char, size_t> CharMap;
    typedef std::vector<std::string>::value_type value_type;

    explicit Vstring(std::istream &in);

    size_t count(CharMap &cmap, bool (*accept)(char, CharMap &));

    using std::vector<std::string>::push_back;

private:
    static size_t countChar(std::string const &str, CharMap &cmap,
                            bool (*accept)(char, CharMap &));
};

#endif //INC_46_VSTRING_H

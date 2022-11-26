#include "main.ih"

void copyFile(std::string const &from, std::string const &to)
{
    fs::copy_file(from, to);
    fs::last_write_time(from, fs::last_write_time(to));
}
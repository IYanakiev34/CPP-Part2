#include "main.ih"

void copyFile(std::string const &from, std::string const &to)
{
    fs::copy_file(from, to);
    fs::file_time_type orgTime = fs::last_write_time(from);
    fs::file_time_type newTime = fs::last_write_time(to);
    fs::last_write_time(to, newTime - (newTime - orgTime));
}
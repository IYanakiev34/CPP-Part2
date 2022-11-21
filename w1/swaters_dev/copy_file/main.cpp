
#include <string>
#include <iostream>
#include <filesystem>

int main() {
    std::string src, dst;
    std::getline(std::cin, src);
    std::getline(std::cin, dst);
    std::filesystem::copy_file(src, dst);
    std::filesystem::last_write_time(dst, std::filesystem::last_write_time(src));
    return 0;
}

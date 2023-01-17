#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

// filesystem copy
void copyFile1(string const &source, string const &dest)
{
    filesystem::copy(source, dest);
}

// copy generic algorithm
void copyFile2(istream &source, ostream &dest)
{
    copy(istreambuf_iterator<char>(source), istreambuf_iterator<char>(),
         ostreambuf_iterator<char>(dest));
}

// inserting from one stream to another
void copyFile3(istream &source, ostream &dest)
{
    dest << source.rdbuf();
}

// while next line insert line
void copyFile4(istream &source, ostream &dest)
{
    string line;
    while (getline(source, line))
        dest << line << endl;
}

// load into buffer and write buffer
void copyFile5(istream &source, ostream &dest)
{
    source.seekg(0, ios::end);
    size_t size = source.tellg();
    source.seekg(0, ios::beg);

    char *buffer = new char[size];
    source.read(buffer, size);
    dest.write(buffer, size);
    delete[] buffer;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}













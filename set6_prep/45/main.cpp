#include <memory>
#include <string>

using namespace std;

int main()
{
    /*
     * Wrong:
     * std::unique_ptr<char[]>(new char[10]);
     * std::unique_ptr<string *>(new string *[10]);
     * auto strPtrs = std::unique_ptr<string*[]>(new string*[10]);
     */
    unique_ptr<char[]>{new char[10]}; // NOLINT (don't intend to use)
    unique_ptr<string> strings[10];
    strings[0] = unique_ptr<string>{new string{"Hello"}};
}
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
    unique_ptr<unique_ptr<string>[]> strPtrs{new unique_ptr<string>[10]};
    strPtrs[0] = std::make_unique<string>("Hello"); // No leaks
}
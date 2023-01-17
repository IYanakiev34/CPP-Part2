#include "main.ih"

using namespace std;

int main()
{
    Vstring vstring(cin);
    Vstring::CharMap vmap;

    cout << "Vowels: " << vstring.count(vmap, vowels) << '\n';

    // Display all elements of vmap
    for_each(vmap.begin(),vmap.end(),
    [](Vstring::CharMap::value_type &pair)
    {
        cout << pair.first << ": " << pair.second << '\n';
    });
}
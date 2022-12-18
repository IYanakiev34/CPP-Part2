#include <iostream>
#include <set>

int main() {
    std::set<std::string> words;
    std::string word;
    while (std::cin >> word && word != "!")
        words.insert(word);
    for (auto const &setWord : words)
        std::cout << setWord << "\n";
}

#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> sortedWordCounts;
    std::string word;
    while (std::cin >> word && word != "!")
        ++sortedWordCounts[word];
    for (auto const& wordCount : sortedWordCounts)
        std::cout << wordCount.first << " " << wordCount.second << "\n";
}

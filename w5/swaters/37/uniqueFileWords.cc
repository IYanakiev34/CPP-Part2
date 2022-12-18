#include "main.ih"

std::vector<std::string> uniqueFileWords(std::string const &fname)
{
    // Open the file and verify success
    std::ifstream ifs(fname);
    if (!ifs.is_open())
        std::cerr << "Error opening file " << fname << std::endl;

    // Get the unique words
    std::unordered_set<std::string> words;
    std::string word;
    while (ifs >> word)
        words.insert(word);

    // Copy the words into a vector
    std::vector<std::string> vec{words.begin(), words.end()};
    return vec;
}
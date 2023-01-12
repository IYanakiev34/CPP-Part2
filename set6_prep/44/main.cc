#include "main.ih"

void usage()
{
    char const info[] = R"(You must specify the filename
        from which to read the student information)";

    std::cout << info << "\n";
}

int main(int argc, char **argv)
{
    std::vector<Student> students;
    if (argc < 2)
    {
        usage();
        return 1;
    }
    std::string const filename(argv[1]);
    std::ifstream file(filename);

    if (!file.is_open())
        std::cerr << "Couldn't open the file: " << filename << "\n";

    // Read students from file
    read(file, students);

    // Sort by last name
    sortByLastNames(students);

    // Put indcies into indices vector
    std::vector<int> indices = createIndices(students);

    // Sort by number
    sortByNumber(students, indices);

    // Write sorted by names
    std::cout << "Sorted by last names\n";
    writeNames(std::cout, students);
    std::cout << "\n";

    // Write sorted by numbers
    std::cout << "Sorted by numbers\n";
    writeNrs(std::cout, students, indices);
    std::cout << std::endl;
}

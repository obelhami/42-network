#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: The search string cannot be empty." << std::endl;
        return 1;
    }
    std::string outputFile = std::string(argv[1]) + ".replace";
    std::ofstream newFile(outputFile.c_str(), std::ios::out);
    if (!newFile)
    {
        std::cerr << "Error: Could not create the output file!" << std::endl;
        return 1;
    }

    std::string line;
    bool isEmpty = true;

    while (std::getline(file, line))
    {
        isEmpty = false;
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        newFile << line << std::endl;
    }
    if (isEmpty)
        std::cerr << "Warning: The input file is empty." << std::endl;

    file.close();
    newFile.close();
    return 0;
}

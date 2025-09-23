#include <iostream>
#include <cctype>
#include <string>

int main(int arc, char **arv)
{
    int i = 0, j;
    std::string str;

    if (arc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (arv[++i])
    {
        j = -1;
        while (arv[i][++j])
            str += (char)toupper(arv[i][j]);
    }
    std::cout << str << std::endl;
    return (0);
}

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// #include "MutantStack.hpp"
// #include <iostream>
// #include <string>

// int main() {
//     MutantStack<std::string> stringStack;

//     stringStack.push("Hello");
//     stringStack.push("World");
//     stringStack.push("This");
//     stringStack.push("Is");
//     stringStack.push("MutantStack!");

//     std::cout << "Top element: " << stringStack.top() << std::endl;

//     stringStack.pop();
//     std::cout << "After pop, size: " << stringStack.size() << std::endl;

//     // Iterate through stack elements
//     std::cout << "Stack contents:" << std::endl;
//     for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
//         std::cout << *it << std::endl;
//     }

//     return 0;
// }

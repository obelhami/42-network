#include "Span.hpp"
#include <vector>

int main()
{
    Span sp = Span(7);
    try
    {
        sp.addNumber(16);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(15);
        sp.addNumber(51);
        int arr[] = {18, 20, 25};
        std::vector<int> moreNumbers(arr, arr + 3); 
        sp.addNumber(moreNumbers.begin(), moreNumbers.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
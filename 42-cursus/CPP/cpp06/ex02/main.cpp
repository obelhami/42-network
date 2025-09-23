#include "Base.hpp"
#include "functions.hpp"  // or just declare function prototypes if separated

int main() {
    Base* obj = generate();

    std::cout << "Using pointer: ";
    identify(obj);

    std::cout << "Using reference: ";
    identify(*obj);

    delete obj;
    return 0;
}

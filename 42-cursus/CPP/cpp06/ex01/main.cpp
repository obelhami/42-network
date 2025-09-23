#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
using namespace std;

int main()
{
    // Create a Data object
    Data original;
    original.id = 1337;
    original.name = "Omar";

    // Serialize the pointer
    uintptr_t raw = Serialize::serialize(&original);
    std::cout << "Raw address (decimal): " << raw << std::endl;
    // Deserialize back to a pointer
    Data* recovered = Serialize::deserialize(raw);

    // Check if it’s the same pointer
    if (recovered == &original) {
        std::cout << "✅ Pointers match!" << std::endl;
        std::cout << "Recovered Data: id = " << recovered->id
                  << ", name = " << recovered->name << std::endl;
    } else {
        std::cout << "❌ Pointers do NOT match!" << std::endl;
    }
}
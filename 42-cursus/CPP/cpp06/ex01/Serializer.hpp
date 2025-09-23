#pragma once
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class  Serialize
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serialize();
};
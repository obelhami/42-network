#pragma once 

#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array {
private:
    T* array;
    unsigned int _size;
public:
    Array()
    {
        array = NULL;
        _size = 0;
    }
    Array(unsigned int n)
    {
        array = new T[n]();
        _size = n;
    }
    Array(const Array &object)
    {
        _size = object._size;
        array = new T[_size];
        for (unsigned int i = 0; i < _size;i++)
        {
            array[i] = object.array[i];
        }
    }
    Array &operator=(const Array &object)
    {
        if (this != &object)
        {
            delete[] array;
            _size = object._size;
            array = new T[_size];
            for (unsigned int i = 0; i < _size;i++)
            {
                array[i] = object.array[i];
            }
        }
        return *this;
    }
    ~Array() {
        delete[] array;
    }

    // Subscript operator with bounds checking
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return array[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return array[index];
    }

    // size() method
    unsigned int size() const {
        return _size;
    }
};


#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Alice";

    Data* ptr = &data;

    std::cout << "Original pointer: " << ptr << std::endl;

    uintptr_t raw = Serializer::serialize(ptr);

    std::cout << "Serialized value: " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Restored pointer: " << restored << std::endl;

    if (ptr == restored)
        std::cout << "SUCCESS: Pointers are equal!" << std::endl;
    else
        std::cout << "ERROR: Pointers are different!" << std::endl;

    std::cout << "Data ID: " << restored->id << std::endl;
    std::cout << "Data name: " << restored->name << std::endl;

    return 0;
}
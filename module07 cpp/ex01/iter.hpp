#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>


template <typename T_a, typename T_f>
void iter(T_a *array, const std::size_t length, T_f function){
    for(std::size_t i = 0; i < length; i++)
    {
        function(array[i]);
    }
}

#endif
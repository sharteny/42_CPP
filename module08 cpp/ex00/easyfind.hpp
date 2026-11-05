#ifndef EASYFAIND_HPP
#define EASYFINDE_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container,int value){
    typename T ::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}




#endif
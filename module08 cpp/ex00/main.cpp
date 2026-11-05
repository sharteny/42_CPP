#include "easyfind.hpp"

template <typename T>
void test(T &c, int value){
    try{
        typename T::iterator it = easyfind(c, value);
        std::cout << "found: " << *it << std::endl;
    }catch(const std::exception &e){
        std::cout << value << " - " <<  e.what() << std::endl;
    }
}


int main(){
    std::vector<int> v;
    std::list<int> l;
	std::deque<int> d;

    for (int i = 0; i < 5; i++){
        v.push_back(i * 3);
        l.push_back(i * 10);
        d.push_back(i + 9);
    }

    std::cout << "--- vector ---" << std::endl;
    test(v, 3);
    test(v, 77);

    std::cout << "--- list ---" << std::endl;
    test(l, 30);
    test(l, 50);

    std::cout << "--- deque ---" << std::endl;
    test(d, 11);
    test(d, 5);

    std::cout << "--- edge cases ---" << std::endl;
	std::vector<int> empty;
	test(empty, 1);

    std::vector<int> dup;
	dup.push_back(5);
	dup.push_back(1);
	dup.push_back(5);
	test(dup, 5);

    return 0;
}
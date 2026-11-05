#include "Span.hpp"

Span::Span():_max(0){}

Span::Span(unsigned int n): _max(n){}

Span::Span(const Span &other):_max(other._max), _number(other._number){}

Span &Span::operator=(const Span &other){
    if (this != &other){
        _max = other._max;
        _number = other._number;

    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int number){
    if(_number.size() >= _max)
        throw SpanFullException();
    _number.push_back(number);
}

int Span::longestSpan() const{
    if(_number.size() < 2)
        throw NotEnoughNumbers();
    int min = *std::min_element(_number.begin() , _number.end());
    int max = *std::max_element(_number.begin(), _number.end());
    return max - min;
}

int Span::shortestSpan() const{
    if(_number.size() < 2)
        throw NotEnoughNumbers();
    std::vector<int> tmp = _number;
    std::sort(tmp.begin(), tmp.end());
    int sh = tmp[1] - tmp[0];
    for(size_t i = 1;i < tmp.size(); i++){
        int diff = tmp[i] - tmp[i-1];
        if (diff < sh )
            sh = diff;
    }
    return sh;
}




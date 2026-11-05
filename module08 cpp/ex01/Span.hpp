#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>


class Span{
    private:
        unsigned int _max;
        std::vector<int> _number;
    
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

    class SpanFullException : public std::exception
    {
	    public:
		    const char* what() const throw()
		    {
		    	return ("Span is full");
		    }
    };
    class NotEnoughNumbers : public std::exception
    {
	    public:
		    const char* what() const throw()
		    {
			    return ("Not enough numbers to find a span");
		    }
    };
};

#endif
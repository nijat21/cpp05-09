#include "Span.hpp"

Span::Span(unsigned int _N) : N(_N) {}

Span::Span(const Span& src) {
    *this = src;
};

Span& Span::operator=(const Span& rhs) {
    if(this != &rhs) {
        this->N = rhs.N;
    }
    return *this;
};

Span::~Span(){};

void Span::addNumber(const int num){
    if(data.size() == N)
        throw SpanFullException();
    data.push_back(num);
};

Span& Span::shortestSpan(){
    if(N <= 1)
        throw NoSpanException();
    // logic to find the smallest difference between two numbers of this span
};

Span& Span::longestSpan(){
    if(N <= 1)
        throw NoSpanException();
    // logic to find the smallest difference between two numbers of this span

};
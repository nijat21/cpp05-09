#include "Span.hpp"
#include <cmath>
#include <limits>


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

unsigned int Span::size() const {
    return this->data.size();
}

unsigned int Span::findDiff(unsigned int i, unsigned int j) const {
    return abs(data[i] - data[j]);
}

unsigned int findShortest(const Span& sp) {
    // for each number check the difference with all different values O(n2)
    /* 
        Binary tree:
            - base case: 
    */
    unsigned int diff = std::numeric_limits<int>::max();

    for (unsigned int i = 0; i < sp.size(); i++) {
        for (unsigned int j = i; j < sp.size(); j++) {
            if(i != j){
                unsigned int d = sp.findDiff(i, j);
                diff = (d < diff) ? d : diff;
            }
        }
    }
    return diff;
}

unsigned int findLongest() {
}

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
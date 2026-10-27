#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>

Span::Span(unsigned int _N) : N(_N) {}

Span::Span(const Span &src) {
    *this = src;
};

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        this->N = rhs.N;
    }
    return *this;
};

Span::~Span() {};

void Span::addNumber(const int num) {
    if (data.size() == N)
        throw SpanFullException();
    data.push_back(num);
};

void Span::addRange(const std::vector<int>::iterator begin, const std::vector<int>::iterator end) {
    if (begin == end)
        return;
    for (std::vector<int>::iterator it = begin; it != end; ++it)
        addNumber(*it);
}

unsigned int Span::findExtreme(bool less) const {
    if (data.size() < 2)
        return -1;
    std::vector<int> sorted = data;
    std::sort(sorted.begin(), sorted.end());
    long long res = less ? std::numeric_limits<long long>::max() : 0;
    if (less) {
        for (std::size_t i = 1; i < sorted.size(); i++) {
            long long diff =
                static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1]);
            res = std::min(diff, res);
        }
    } else {
        res = static_cast<long long>(sorted.back()) - static_cast<long long>(sorted.front());
    }
    return static_cast<int>(res);
}

unsigned int Span::shortestSpan() {
    if (N <= 1)
        throw NoSpanException();
    return findExtreme(true);
};

unsigned int Span::longestSpan() {
    if (N <= 1)
        throw NoSpanException();
    return findExtreme(false);
};
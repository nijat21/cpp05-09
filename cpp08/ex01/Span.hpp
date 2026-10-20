#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
    public:
        Span(unsigned int _N);
        Span(const Span& src);
        Span& operator=(const Span& rhs);
        ~Span();

        void addNumber(const int num);
        unsigned int size() const;
        unsigned int findDiff(unsigned int i, unsigned int j) const;
        
        Span& shortestSpan();
        Span& longestSpan();

        class SpanFullException : public std::exception {
            virtual const char* what() const throw() {
                return "Span is already full!";
            };
        };
            
        class NoSpanException : public std::exception {
            virtual const char* what() const throw() {
                return "No span can be found!";
            };
        };
    
    private:
        Span();
        unsigned int N;
        std::vector<int> data;
};

#endif
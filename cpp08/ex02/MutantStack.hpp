#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
  public:
    MutantStack();
    MutantStack(const MutantStack &src);
    MutantStack &operator=(const MutantStack &rhs);
    ~MutantStack();

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP

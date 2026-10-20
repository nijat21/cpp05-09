#include "easyfind.hpp"
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &c, int val) {
    typename T::const_iterator it = std::find(c.begin(), c.end(), val);
    if (it == c.end())
        throw NotFoundException();
    return it;
};

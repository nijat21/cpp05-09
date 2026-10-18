#include "easyfind.hpp"
#include <algorithm>

template <typename T> typename T::iterator easyfind(const T &c, const int val) {
    typename T::iterator res = std::find(c.begin(), c.end(), val);
    if (res == c.end())
        throw NotFoundException();
    return res;
};

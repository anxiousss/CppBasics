#include <iostream>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last)
        return last;

    Iter result = first;
    while (++first != last) {
        if (*result != *first && ++result != first) {
            *result = std::move(*first);
        }
    }
    return ++result;
}
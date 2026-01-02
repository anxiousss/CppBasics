#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    int size = (int)v.size();
    for (int i = 0; i < size; ++i) {
        v.push_back(v[i]);
    }
}
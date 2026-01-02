#include <algorithm>
#include <vector>

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;
    filtered.resize(data.size());

    auto filteredLast = std::copy_if(
            data.begin(),
            data.end(),
            filtered.begin(),
            [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filteredLast);
}
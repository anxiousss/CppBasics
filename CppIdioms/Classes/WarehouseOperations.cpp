#include <iostream>
#include <vector>
#include <set>
#include <limits>

class Stock {
private:
    int counter = 0;
    std::set<std::pair<int, int>> setW;
    std::set<std::pair<int, int>> setV;
    std::vector<std::set<std::pair<int, int>>::iterator> itersW;
    std::vector<std::set<std::pair<int, int>>::iterator> itersV;

public:
    void Add(int w, int v);
    int GetByW(int min_w);
    int GetByV(int min_v);
};

void Stock::Add(int w, int v) {
    auto itW = setW.insert({w, -counter}).first;
    auto itV = setV.insert({v, -counter}).first;
    itersW.push_back(itW);
    itersV.push_back(itV);
    counter++;
}

int Stock::GetByW(int min_w) {
    auto it = setW.lower_bound({min_w, std::numeric_limits<int>::min()});
    if (it == setW.end()) return -1;

    int index = -it->second;
    setW.erase(it);
    setV.erase(itersV[index]);
    return index;
}

int Stock::GetByV(int min_v) {
    auto it = setV.lower_bound({min_v, std::numeric_limits<int>::min()});
    if (it == setV.end()) return -1;

    int index = -it->second;
    setV.erase(it);
    setW.erase(itersW[index]);
    return index;
}
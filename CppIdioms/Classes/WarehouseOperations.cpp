#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

enum class Type {
    W = 0,
    V = 1
};

class Stock {
private:
    struct box {
        int weight;
        int volume;
        int i;
    };

    int numer = 0;
    std::set<int> weights;
    std::set<int> volumes;
    std::vector<box> boxes;

    int Get(int value, Type type);

public:
    void Add(int w, int v);

    int GetByW(int min_w);

    int GetByV(int min_v);
};

void Stock::Add(int w, int v) {
    weights.insert(w);
    volumes.insert(v);
    boxes.push_back({w, v, numer});
    ++numer;
}

int Stock::Get(int min_value, Type type) {
    std::set<int>* main_values_set;
    std::set<int>* additional_values_set;
    if (type == Type::W) {
        main_values_set = &weights;
        additional_values_set = &volumes;
    } else {
        main_values_set = &volumes;
        additional_values_set = &weights;
    }

    auto it = std::find_if(main_values_set->begin(), main_values_set->end(),
                           [&min_value](int value) {return value >= min_value;});
    if (it == main_values_set->end()) {
        return -1;
    }

    int b_index = 0;
    for (const auto& b: boxes) {
        if ((b.weight == *it && type == Type::W) || (b.volume == *it && type == Type::V)) {
            main_values_set->erase(it);
            additional_values_set->erase(it);
            boxes.erase(boxes.begin() + b_index);
            return b_index;
        }
        ++b_index;
    }
    return -1;
}

int Stock::GetByW(int min_w) {
    return Get(min_w, Type::W);
}

int Stock::GetByV(int min_v) {
    return Get(min_v, Type::V);
}


int main() {
    Stock stock;
    stock.Add(30, 40);
    stock.Add(25, 45);
    stock.Add(20, 20);

    std::cout << stock.GetByV(30) << std::endl;
    std::cout << stock.GetByV(30) << std::endl;
}
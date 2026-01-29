#include <iostream>
#include <vector>
#include <limits>

enum class Type {
    W = 0,
    V = 1
};

class Stock {
private:
    int numer = 0;
    std::vector<int> weights;
    std::vector<int> volumes;
    std::vector<int> indices;

    int Get(int threshold, Type type);

public:
    void Add(int w, int v);

    int GetByW(int min_w);

    int GetByV(int min_v);
};

void Stock::Add(int w, int v) {
    weights.push_back(w);
    volumes.push_back(v);
    indices.push_back(numer++);
}

int Stock::Get(int threshold, Type type) {

    std::vector<int>* vec;

    if (type == Type::W) {
        vec = &weights;
    } else {
        vec = &volumes;
    }

    int min_value = std::numeric_limits<int>::max();
    bool found = false;

    int size = vec->size();
    int min_index = -1;
    for (int i = size - 1; i > -1; --i) {
        int num = (*vec)[i];
        if (num >= threshold) {
            if (!found || num < min_value) {
                min_value = num;
                min_index = i;
                found = true;
            }
        }
    }

    if (found) {
        int real_index = indices[min_index];
        if (min_index != static_cast<int>(size - 1)) {
            std::swap(weights[min_index], weights.back());
            std::swap(volumes[min_index], volumes.back());
            std::swap(indices[min_index], indices.back());
            weights.erase(weights.begin() + min_index);
            volumes.erase(volumes.begin() + min_index);
            indices.erase(indices.begin() + min_index);
        }  else {
            weights.pop_back();
            volumes.pop_back();
            indices.pop_back();
        }

        return real_index;
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
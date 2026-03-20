#include <cstddef>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    bool Empty() const;

    size_t Size() const;

    void Clear();

    const T& operator [] (size_t i) const;

    T& operator [] (size_t i);

    const T& At(size_t i) const;  // throws std::out_of_range on incorrect index

    T& At(size_t i);  // throws std::out_of_range on incorrect index

    const T& Front() const;

    T& Front();

    const T& Back() const;

    T& Back();

    void PushFront(const T& elem);

    void PushBack(const T& elem);
};

template<typename T>
void Deque<T>::PushBack(const T &elem) {
    tail.push_back(elem);
}

template<typename T>
void Deque<T>::PushFront(const T &elem) {
    head.push_back(elem);
}

template<typename T>
T &Deque<T>::Back() {
    return tail.empty() ? head[0] : tail[tail.size() - 1];
}

template<typename T>
const T &Deque<T>::Back() const {
    return tail.empty() ? head[0] : tail[tail.size() - 1];
}

template<typename T>
T &Deque<T>::Front() {
    return head.empty() ? tail[0] : head[head.size() - 1];
}

template<typename T>
const T &Deque<T>::Front() const {
    return head.empty() ? tail[0] : head[head.size() - 1];
}

template<typename T>
T &Deque<T>::At(size_t i) {
    if (i >= tail.size() + head.size())
        throw std::out_of_range("");
    return (*this)[i];
}

template<typename T>
const T &Deque<T>::At(size_t i) const {
    if (i >= tail.size() + head.size())
        throw std::out_of_range("");
    return (*this)[i];
}

template<typename T>
T &Deque<T>::operator[](size_t i) {
    if (i < head.size()) return head[head.size() - 1 - i];
    return tail[i - head.size()];
}

template<typename T>
const T &Deque<T>::operator[](size_t i) const {
    if (i < head.size()) return head[head.size() - 1 - i];
    return tail[i - head.size()];
}

template<typename T>
void Deque<T>::Clear() {
    head.clear();
    tail.clear();
}

template<typename T>
size_t Deque<T>::Size() const {
    return head.size() + tail.size();
}

template<typename T>
bool Deque<T>::Empty() const {
    return head.empty() && tail.empty();
}


int main() {
    Deque<int> deque;
    deque.PushBack(1);
    deque.PushBack(2);

    std::cout << deque.Front() << std::endl;
}
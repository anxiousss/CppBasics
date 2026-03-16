#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
public:
    Container c;
    using container_type = Container;
    using value_type = container_type::value_type;
    using size_type = Container::size_type;
    using reference = Container::reference;
    using const_reference = Container::const_reference;
    Queue();

    const_reference front() const {
        return c.front();
    }

    reference front() {
        return c.front();
    }

    void pop();

    size_type size() const {
        return c.size();
    }

    bool empty() const;

    void push(const value_type& el);

    bool operator==(const Queue<T, Container>& other);

    bool operator!=(const Queue<T, Container>& other);

};

template<typename T, typename Container>
void Queue<T, Container>::pop() {
//    c.pop_front();
}

template<typename T, typename Container>
bool Queue<T, Container>::operator!=(const Queue<T, Container> &other) {
    return c != other.c;
}

template<typename T, typename Container>
bool Queue<T, Container>::operator==(const Queue<T, Container> &other) {
    return c == other.c;
}

template<typename T, typename Container>
bool Queue<T, Container>::empty() const {
    return c.empty();
}


template<typename T, typename Container>
void Queue<T, Container>::push(const value_type& el) {
    c.push_back(el);
}


template<typename T, typename Container>
Queue<T, Container>::Queue() {
    c = Container();
}

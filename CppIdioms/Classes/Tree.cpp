#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;


public:
    [[nodiscard]] bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node) const {
    const Node* current = &root;
    auto it = node.begin();
    while (true) {
        if (it == node.end())
            return true;
        auto el = current->children.find(*it);
        if (el != current->children.end()) {
            current = &(el->second);
            ++it;
            continue;
        }
        return false;
    }
}

void Tree::Insert(const std::vector<std::string> &node) {
    Node* current = &root;
    auto it = node.begin();
    while (true) {
        if (it == node.end())
            return;

        if (current->children.find(*it) == current->children.end()) {
            current->children[*it] = Node();
        }

        current = &current->children[*it];
        ++it;
    }
}

void Tree::Delete(const std::vector<std::string> &node) {
    Node* current = &root;
    for (size_t i = 0; i < node.size() - 1; ++i) {
        auto it = current->children.find(node[i]);
        if (it == current->children.end()) {
            return;
        }
        current = &(it->second);
    }

    current->children.erase(node.back());
}

#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string seq;
    std::cin >> seq;

    std::stack<char> st;

    for (char c : seq) {
        if (st.empty() || !((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{'))) {
            st.push(c);
        } else {
            st.pop();
        }
    }

    if (st.empty()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
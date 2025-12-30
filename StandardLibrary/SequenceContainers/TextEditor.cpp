#include <iostream>
#include <vector>
#include <string>

void Down(int& cursor, std::vector<std::string>& text) {
    if (cursor == (int)text.size()) {
        return;
    }
    ++cursor;
}

void Up(int& cursor) {
    if (cursor == 0) {
        return;
    }
    --cursor;
}

void Ctrl_X(int& cursor,std::string& buffer, std::vector<std::string>& text) {
    if (text[cursor].empty()) {
        return;
    }
    buffer = text[cursor];
    text.erase(text.begin() + cursor);
}

void Ctrl_V(int& cursor, std::string& buffer, std::vector<std::string>& text) {
    if (buffer.empty()) {
        return;
    }
    text.insert(text.begin() + cursor, buffer);
    ++cursor;
}

int main() {
    std::vector<std::string> text;
    int cursor = 0;
    std::string buffer;
    std::string word;
    while (std::getline(std::cin, word) && !word.empty()) {
        text.push_back(word);
    }

    std::string cmd;
    while (std::getline(std::cin, cmd)) {
        if (cmd == "Down") {
            Down(cursor, text);
        } else if (cmd == "Up") {
            Up(cursor);
        } else if (cmd == "Ctrl+X") {
            Ctrl_X(cursor, buffer, text);
        } else if (cmd == "Ctrl+V") {
            Ctrl_V(cursor, buffer, text);
        }
    }

    for (std::string& w: text) {
        std::cout << w << std::endl;
    }
    return 0;
}
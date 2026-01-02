#include <iostream>
#include <vector>
#include <string>


int shift_position = 0;
std::string prev_cmd;

void Down(int& cursor, std::vector<std::string>& text) {
    if (cursor <= (int)text.size() - 1) {
        ++cursor;
    }
}

void Up(int& cursor) {
    if (cursor > 0) {
        --cursor;
    }
}

void Ctrl_X(int& cursor, std::vector<std::string>& buffer, std::vector<std::string>& text, bool& is_shifted) {
    buffer.clear();
    if (!text[cursor].empty()) {
        size_t start = std::min(shift_position, cursor);
        size_t end = shift_position ^ cursor ^ start;

        if (is_shifted) {
            for (size_t i = start; i < end; ++i) {
                buffer.push_back(text[start]);
                text.erase(text.begin() + start);
            }
            is_shifted = false;
            cursor -= end - start;
        } else {
            buffer.push_back(text[cursor]);
            text.erase(text.begin() + cursor);
        }
    }
}

void Ctrl_V(int& cursor, std::vector<std::string>& buffer, std::vector<std::string>& text, bool& is_shifted) {
    if (!buffer.empty()) {
        size_t buffer_size = buffer.size();
        if (is_shifted) {
            size_t start = std::min(shift_position, cursor);
            size_t end = shift_position ^ cursor ^ start;
            if (prev_cmd == "Up" || prev_cmd == "Down") {
                for (size_t i = start; i < buffer_size + start; ++i) {
                    text[i] = buffer[i - start];
                }
                for (size_t i = buffer_size + start; i < end; ++i) {
                    text.erase(text.begin() + buffer_size + start);
                }
            } else {
                for (size_t i = start; i < end; ++i) {
                    text.insert(text.begin() + i, buffer[i - start]);
                }
            }
            is_shifted = false;
        } else {
            for (size_t i = cursor; i < cursor + buffer_size; ++i) {
                text.insert(text.begin() + i, buffer[i - cursor]);
            }
        }
        ++cursor;
    }
}

int main() {
    std::vector<std::string> text;
    int cursor = 0;
    std::vector<std::string> buffer;
    std::string word;
    while (std::getline(std::cin, word) && !word.empty()) {
        text.push_back(word);
    }

    text.emplace_back("");
    std::string cmd;
    bool is_shifted = false;
    while (std::getline(std::cin, cmd)) {
        if (cmd == "Down") {
            Down(cursor, text);
        } else if (cmd == "Up") {
            Up(cursor);
        } else if (cmd == "Ctrl+X") {
            Ctrl_X(cursor, buffer, text, is_shifted);
        } else if (cmd == "Ctrl+V") {
            Ctrl_V(cursor, buffer, text, is_shifted);
        } else if (cmd == "Shift") {
            is_shifted = true;
            shift_position = cursor;
        }
        prev_cmd = cmd;
    }

    for (std::string& w: text) {
        std::cout << w << std::endl;
    }

    return 0;
}
#include <iostream>
#include <string>

bool NextToken(std::string_view& sv, const char& delimiter, std::string_view& token) {
    if (sv.empty())
        return false;

    auto positon = sv.find_first_of(delimiter);
    if (positon == std::string_view::npos) {
        token = sv;
        sv = "";
    } else {
        token = sv.substr(0, positon);
        sv = sv.substr(positon + 1);
    }
    return true;
}

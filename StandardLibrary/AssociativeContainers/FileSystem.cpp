#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> paths;

    std::string path;
    while (std::cin >> path) {
        for (int i = 0; i < (int)path.size(); ++i) {
            if (path[i] == '/'  && std::find(paths.begin(), paths.end(), path.substr(0, i + 1)) == paths.end() &&
                ((path.find('.') != std::string::npos) || std::count(path.begin(), path.end(), '/') > 1)) {
                paths.push_back(path.substr(0,  i + 1));
            }
        }
    }

    std::sort(paths.begin(), paths.end());

    for (const std::string& s: paths) {
        std::cout << s << std::endl;
    }
    return 0;
}
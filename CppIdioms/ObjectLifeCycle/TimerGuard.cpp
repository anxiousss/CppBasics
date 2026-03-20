#include <iostream>
#include <chrono>
#include <thread>
#include <type_traits>

class TimerGuard {
public:
    std::ostream& ostream;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::string_view msg;


    TimerGuard(std::string message = "", std::ostream& out = std::cout): ostream(out), msg(message) {
        start = std::chrono::high_resolution_clock::now();
    };

    ~TimerGuard() {
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        ostream << msg << ' '  << diff.count() << '\n';
    }
};

int main() {
    {
        TimerGuard timer("FirstLongFunction elapsed: ", std::cout);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
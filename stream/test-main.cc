#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

#include "print.h"

using namespace minimum;

struct Int {
    int y;
    Int(int x) : y(x) {
        // std::cout << "bl" << std::endl;
    }
    Int(const Int &x) : y(x.y) {
        // std::cout << "cp" << std::endl;
    }
    Int(Int &&x) :y(x.y) {
        // std::cout << "mv" << std::endl;
    }
    bool operator<(const Int&r) const {return y < r.y;}
};

std::ostream &operator<<(std::ostream &os, const Int &x) {
    return os << x.y;
}

void basic() {
    print("hello world") << std::endl;
    print(true) << std::endl;
    print(false) << std::endl;
    print(std::vector<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)})) << std::endl;
    print(std::pair<Int, Int>({Int(1),Int(2)})) << std::endl;
    print(std::set<Int>({Int(1),Int(2),Int(3),Int(4),Int(5),Int(6)})) << std::endl;
    auto Q = std::queue<Int>();
    for (auto &s : std::vector<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)})) {
        Q.push(s);
    }
    print(Q) << std::endl;
    auto D = std::deque<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)});
    print(D) << std::endl;
    using mp_t = std::map<std::string, Int>;
    auto Mp = mp_t({
        mp_t::value_type({"1", Int(2)}),
        mp_t::value_type({"3", Int(4)}),
    });
    print(Mp) << std::endl;
    using ump_t = std::unordered_map<std::string, Int>;
    auto uMp = ump_t({
        ump_t::value_type({"1", Int(2)}),
        ump_t::value_type({"3", Int(4)}),
    });
    print(uMp) << std::endl;
    using mp_t2 = std::multimap<std::string, Int>;
    auto Mp2 = mp_t2({
        mp_t2::value_type({"1", Int(2)}),
        mp_t2::value_type({"3", Int(4)}),
        mp_t2::value_type({"1", Int(2)}),
        mp_t2::value_type({"3", Int(4)}),
    });
    print(Mp2) << std::endl;
    using ump_t2 = std::unordered_multimap<std::string, Int>;
    auto uMp2 = ump_t2({
        ump_t2::value_type({"1", Int(2)}),
        ump_t2::value_type({"3", Int(4)}),
        ump_t2::value_type({"1", Int(2)}),
        ump_t2::value_type({"3", Int(4)}),
    });
    print(uMp2) << std::endl;
}

int main() {
    basic();
}

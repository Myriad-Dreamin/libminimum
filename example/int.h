#pragma once

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

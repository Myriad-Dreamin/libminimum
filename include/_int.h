#pragma once

#include <iostream>

struct Int {
    int y;
    Int(int x) : y(x) {
#ifdef TestBCM
        std::cout << "bl" << std::endl;
#endif
    }
    Int(const Int &x) : y(x.y) {
#ifdef TestBCM
        std::cout << "cp" << std::endl;
#endif
    }
    Int(Int &&x) :y(x.y) {
#ifdef TestBCM
        std::cout << "mv" << std::endl;
#endif
    }
    bool operator<(const Int&r) const {return y < r.y;}
};

std::ostream &operator<<(std::ostream &os, const Int &x) {
    return os << x.y;
}

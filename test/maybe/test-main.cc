
#define TestBCM
#include <print.h>
#include <_int.h>
#include <maybe.h>

using namespace minimum;
int main2();
int main3();
int main4();

int main() {
    Int u = 1;
    cout << "-------------------" << endl;
    maybe<Int> X;
    cout << bool(X) << ' ' << X.has_value() << endl;
    cout << "-------------------" << endl;
    X = Int(2);
    cout << "-------------------" << endl;
    cout << bool(X) << ' ' << X.has_value() << endl;
    cout << "-------------------" << endl;
    auto c = Int(2);
    cout << "-------------------" << endl;
    X = c;
    cout << bool(X) << ' ' << X.has_value() << endl;
    X = std::move(c);
    cout << bool(X) << ' ' << X.has_value() << endl;
    X = nothing<Int>();
    cout << bool(X) << ' ' << X.has_value() << endl;
    return main2();
}

int main2() {
    Int u = 2, v = 1;
    maybe<Int, Int> X;
    cout << "-------------------" << endl;
    X = nothing<Int, Int>(u);
    cout << bool(X) << ' ' << X.has_value() << endl;
    X = nothing<Int, Int>(std::move(u));
    cout << bool(X) << ' ' << X.has_value() << endl;    
    cout << "-----------main3--------" << endl;
    return main3();
}

using error = const char *;

struct Error {
    int ErrorCode;
    error Info;
};

maybe<Int, Error> Gen(bool c) {
    if (c) {
        // Int u = Int(1);
        return std::move(Int(1));
    } else {
        return nothing<Int, Error>((Error){1, "bad call"});
    }
}

int main3() {
    auto c = Gen(true);
    cout << "-------------------" << endl;
    if (c) {
        auto cp = c.just();
        cout << cp << endl;
        cout << "-------------------" << endl;
        Int &&ref = c.just();
        cout << ref << endl;
        cout << "-------------------" << endl;
        cout << c.just() << endl;
    }
    cout << "-------------------" << endl;
    auto d = Gen(false);
    if (d) {
        auto cp = d.just();
        cout << cp << endl;
        cout << "-------------------" << endl;
        cout << d.just() << endl;
    } else {
        // d.nothing();
    }
    cout << "-----------main4--------" << endl;
    return main4();
}

#include <optional>

std::optional<Int> Gen2(bool c) {
    if (c) {
        // Int u = Int(1);
        return std::move(Int(1));
    } else {
        return std::nullopt;
    }
}

int main4() {
    auto c = Gen2(true);
    cout << "-------------------" << endl;
    if (c) {
        auto cp = *c;
        cout << cp << endl;
        cout << "-------------------" << endl;
        Int &ref = *c;
        cout << ref << endl;
        cout << "-------------------" << endl;
        cout << *c << endl;
    }
    return 0;
}


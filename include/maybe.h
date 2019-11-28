#pragma once

#if __cplusplus >= 201703L
#include <any>
#endif

namespace minimum {

struct _nothing{};

template<typename just_t, typename nothing_t=_nothing>
struct maybe
{
    using maybe_t = maybe<just_t, nothing_t>;
// #if __cplusplus >= 201703L
    std::any maybe_v;
    bool just_b;

    maybe() { just_b = false; }

    template<typename just_x>
    maybe(just_x &&just_v,
        typename std::enable_if<
            std::is_same<typename std::decay<just_x>::type, just_t>::value
        >::type assert = void()) : maybe_v(std::forward<just_x>(just_v)) {
        just_b = true; }
    
    maybe(const just_t &r) : maybe_v(r), just_b(true) { std::cout << "...."; }
    maybe(just_t &&r) : maybe_v(std::move(r)), just_b(true) { }
    
    maybe(const maybe_t &r) : maybe_v(r.maybe_v), just_b(r.just_b) { std::cout << "...."; }
    maybe(maybe_t &&r) : just_b(r.just_b) { maybe_v.swap(r.maybe_v); }
    
    template<typename just_x>
    typename std::enable_if<
        std::is_same<typename std::decay<just_x>::type, just_t>::value
    , maybe_t &>::type operator=(just_x &&just_v) {
        maybe_v = std::forward<just_x>(just_v);
        just_b = true;
        return *this;
    }

    maybe_t &operator=(maybe_t &&r) {
        maybe_v.swap(r.maybe_v);
        just_b = r.just_b;
        return *this;
    }

    maybe_t &operator=(const maybe_t &r) {
        maybe_v = r.maybe_v;
        just_b = r.just_b;
        return *this;
    }



    template<typename nothing_x>
    maybe_t &make_nothing(nothing_x &&nothing_v) {
        just_b = false;
        maybe_v = std::forward<nothing_x>(nothing_v);
        return *this; }

    operator bool() const {
        return just_b;
    }

    bool has_value() const {
        return maybe_v.has_value();
    }

    just_t &&just() { return std::move(std::any_cast<just_t&>(maybe_v)); }
    auto nothing() { return std::move(std::any_cast<nothing_t&>(maybe_v)); }
    template<typename nothing_x>
    auto nothing_or(nothing_x &&nothing_v) {
        return maybe_v.has_value() ? std::move(std::any_cast<nothing_t&>(maybe_v)) : std::forward<nothing_x>(nothing_v); }
// #else
//     using just_t = just_t;
//     using nothing_t = nothing_t;
// #endif

};

template<typename just_t, typename nothing_t=_nothing, typename nothing_x>
inline auto nothing(nothing_x &&nothing_v) {
    return std::move(maybe<just_t, nothing_t>().make_nothing(std::forward<nothing_x>(nothing_v)));
}

template<typename just_t, typename nothing_t=_nothing>
inline auto nothing() {
    return maybe<just_t, nothing_t>();
}

template<typename just_t, typename nothing_t=_nothing>
inline maybe<just_t, nothing_t> just(just_t &&just_v) {
    return maybe<just_t, nothing_t>(just_v);
}

template<typename just_t, typename nothing_t=_nothing>
inline maybe<just_t, nothing_t> just() {
    return maybe<just_t, nothing_t>();
}


}

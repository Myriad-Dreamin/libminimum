#pragma once

#include <print.h>
#include <type_traits>

namespace minimum {


    template<typename stream_t>
    template<typename char_t, typename... Types>
    typename basic_printer<stream_t>::ostream &basic_printer<stream_t>::print(const std::basic_string<char_t> &x) {
        if (quoto)
        {
            os << '"';
        }
        os << x;
        if (quoto)
        {
            os << '"';
        }
        return os;
    }

    template<typename stream_t>
    basic_printer<stream_t>::basic_printer(basic_printer::ostream &os) : os(os) {}

    template<typename stream_t>
    template<typename default_t, typename... Types>
    typename std::enable_if<
            !is_iterable<default_t>::value &&
            !is_queue_like<default_t>::value,
            typename basic_printer<stream_t>::ostream& >::type basic_printer<stream_t>::print(const default_t &x) {
        return os << x;
    }

    template<typename stream_t>
    template<typename... Types>
    typename basic_printer<stream_t>::ostream &basic_printer<stream_t>::print(const char *x) {
        if (quoto)
        {
            os << '"';
        }
        os << x;
        if (quoto)
        {
            os << '"';
        }
        return os;
    }


    template<typename stream_t>
    template<typename... Types>
    typename basic_printer<stream_t>::ostream &basic_printer<stream_t>::print(const bool &x) {
        return os << (x ? "true" : "false");
    }

    template<typename stream_t>
    template<typename first_t, typename second_t, typename... Types>
    typename basic_printer<stream_t>::ostream &basic_printer<stream_t>::print(const std::pair<first_t, second_t> &x) {
        os << '(';
        print(x.first) << ',';
        print(x.second) << ')';
        return os;
    }

    template<typename stream_t>
    template<typename container_t, typename... Types>
    typename std::enable_if<
            !std::is_convertible<container_t, std::basic_string<typename container_t::value_type>>::value
            && is_iterable<container_t>::value, typename basic_printer<stream_t>::ostream &>::type
    basic_printer<stream_t>::print(const container_t &xs) {
        os << '{';
        bool vd = false;
        for (auto &x: xs)
        {
            if (vd)
                os << ',';
            else
                vd = true;
            print(x);
        }
        return os << '}';
    }

    template<typename stream_t>
    template<typename queue_t, typename... Types>
    typename std::enable_if<is_queue_like<queue_t>::value, typename basic_printer<stream_t>::ostream &>::type basic_printer<stream_t>::print(queue_t &x) {
        std::queue<typename queue_t::value_type> cacher;
        os << '<';
        bool vd = false;
        while (x.size())
        {
            if (vd)
                os << ',';
            else
                vd = true;
            print(x.front());
            cacher.emplace(std::move(x.front()));
            x.pop();
        }
        os << '>';
        while (cacher.size())
        {
            x.emplace(std::move(cacher.front()));
            cacher.pop();
        }
        return os;
    }

    template<typename stream_t>
    typename basic_printer<stream_t>::printer_t &basic_printer<stream_t>::operator<<(basic_printer::ostream &(*__pf)(ostream &)) {
        __pf(os);
        return *this;
    }

    template<typename stream_t>
    typename basic_printer<stream_t>::printer_t &basic_printer<stream_t>::operator<<(basic_printer::ios &(*__pf)(ios &)) {
        __pf(os);
        return *this;
    }

    template<typename stream_t>
    typename basic_printer<stream_t>::printer_t &basic_printer<stream_t>::operator<<(std::ios_base &(*__pf)(std::ios_base &)) {
        __pf(os);
        return *this;
    }

    template<typename stream_t>
    typename basic_printer<stream_t>::printer_t &basic_printer<stream_t>::operator<<(basic_printer::applyF f) {
        return f(*this);
        // std::endl;
    }

    template<typename stream_t>
    template<typename T>
    typename std::enable_if<!std::is_base_of<typename basic_printer<stream_t>::apply_t, T>::value,
        typename basic_printer<stream_t>::printer_t &>::type
    basic_printer<stream_t>::operator<<(T x) {
        print(x);
        return *this;

        // std::endl;
    }

    template<typename T>
    printer &print(T x) {
        return cout << x;
    }

    template<typename I>
    typename std::enable_if<is_iterator<I>::value, printer &>::type print(I ls, I rs) {
        return cout;
    }

    template<typename stream_t>
    basic_printer<stream_t> &endl(basic_printer<stream_t> &__printer) {
        __printer.os << std::endl;
        return __printer;
    }

    template<typename stream_t>
    basic_printer<stream_t> &ends(basic_printer<stream_t> &__printer) {
        __printer.os << std::ends;
        return __printer;
    }

    template<typename stream_t>
    basic_printer<stream_t> &flush(basic_printer<stream_t> &__printer) {
        __printer.os << std::flush;
        return __printer;
    }

    _quotoS quoto(bool quotoT) {
        return _quotoS(quotoT);
    }

    template<typename stream_t>
    basic_printer<stream_t> &operator<<(basic_printer<stream_t> &__printer, _basic_quotoS<stream_t> applyS) {
        __printer.quoto = applyS.q;
        return __printer;
    }

    template<typename stream_t>
    _basic_quotoS<stream_t>::_basic_quotoS(bool q) :q(q) {}

    printer cout(std::cout), cerr(std::cerr), clog(std::clog);

    wprinter wcout(std::wcout), wcerr(std::wcerr), wclog(std::wclog);

}

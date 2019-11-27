#pragma once

#include "type_traits.h"
#include <iostream>
#include <string>
#include <type_traits>
#include <cassert>

namespace minimum
{

template <typename stream_t>
struct basic_printer
{
	using ostream = std::basic_ostream<stream_t>;
	using char_type = typename ostream::char_type;
	using traits_type = typename ostream::traits_type;
	using ios = std::basic_ios<char_type, traits_type>;
	struct apply_t {};

	using printer_t = basic_printer<stream_t>;
	typedef printer_t &(*applyF)(printer_t &);
	ostream &os;
	bool quoto = false;
	basic_printer(ostream &os) : os(os) {}

	template <typename default_t, typename... Types>
	typename std::enable_if<
		!is_iterable<default_t>::value &&
		!is_queue_like<default_t>::value,
		ostream &>::type
	print(const default_t &x)
	{
		return os << x;
	}

	template <typename... Types>
	ostream &print(const std::basic_string<stream_t> &x)
	{
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

#if __cplusplus >= 201703L
	template <typename... Types>
	ostream &print(const std::basic_string_view<stream_t> &x)
	{
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
#endif

	template <typename... Types>
	ostream &print(const stream_t *x)
	{
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

	template <typename... Types>
	ostream &print(const bool &x)
	{
		return os << (x ? "true" : "false");
	}

	template <typename first_t, typename second_t, typename... Types>
	ostream &print(const std::pair<first_t, second_t> &x)
	{
		os << '(';
		print(x.first) << ',';
		print(x.second) << ')';
	}

	template <typename container_t, typename... Types>
	typename std::enable_if<is_iterable<container_t>::value, ostream &>::type
	print(const container_t &xs)
	{
		os << '{';
		bool vd = false;
		for (auto &x : xs)
		{
			if (vd)
				os << ',';
			else
				vd = true;
			print(x);
		}
		return os << '}';
	}

	template <typename queue_t, typename... Types>
	typename std::enable_if<is_queue_like<queue_t>::value, ostream &>::type
	print(queue_t &x)
	{
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

	printer_t &
	operator<<(ostream &(*__pf)(ostream &))
	{
		__pf(os);
		return *this;
	}

	printer_t &
	operator<<(ios &(*__pf)(ios &))
	{
		__pf(os);
		return *this;
	}

	printer_t &
	operator<<(std::ios_base &(*__pf)(std::ios_base &))
	{
		__pf(os);
		return *this;
	}

	printer_t &operator<<(applyF f)
	{
		return f(*this);
		// std::endl;
	}

	template <typename T>
	typename std::enable_if<!std::is_base_of<apply_t, T>::value, printer_t &>::type operator<<(T x)
	{
		print(x);
		return *this;

		// std::endl;
	}

	// template <typename I, typename... Types>
	// typename std::enable_if<is_iterator<I>::value>::type
	// print(I ls, I rs) {
	// 	for (;ls!=rs;ls++) {
	// 		std::cout <<
	// 	}
	// }
};

using printer = basic_printer<char>;

printer cout(std::cout), cerr(std::cerr), clog(std::clog);

using wprinter = basic_printer<wchar_t>;

wprinter wcout(std::wcout), wcerr(std::wcerr), wclog(std::wclog);

template <typename T>
printer &print(T x)
{
	return cout << x;
}

template <typename I>
typename std::enable_if<is_iterator<I>::value, printer &>::type
print(I ls, I rs)
{
	return cout;
}

template <typename stream_t>
basic_printer<stream_t> &
endl(basic_printer<stream_t> &__printer)
{
	__printer.os << std::endl;
	return __printer;
}

template <typename stream_t>
basic_printer<stream_t> &
ends(basic_printer<stream_t> &__printer)
{
	__printer.os << std::ends;
	return __printer;
}

template <typename stream_t>
basic_printer<stream_t> &
flush(basic_printer<stream_t> &__printer)
{
	__printer.os << std::flush;
	return __printer;
}

template<typename stream_t>
struct _basic_quotoS : public basic_printer<stream_t>::apply_t
{
	bool q;
	_basic_quotoS(bool q) :q(q) {}
};

using _quotoS = _basic_quotoS<char>;

_quotoS quoto(bool quotoT = true)
{
	return _quotoS(quotoT);
}

template <typename stream_t>
basic_printer<stream_t> &
operator<<(basic_printer<stream_t> &__printer, _basic_quotoS<stream_t> applyS)
{
	__printer.quoto = applyS.q;
	return __printer;
}

// auto &endl = basic_endl<char>;

} // namespace minimum
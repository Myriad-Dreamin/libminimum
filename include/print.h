#pragma once

#include "type_traits.h"
#include <iostream>
#include <string>
#include <type_traits>
#include <cassert>
#include <queue>

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
	basic_printer(ostream &os);

	template <typename default_t, typename... Types>
	typename std::enable_if<
		!is_iterable<default_t>::value &&
		!is_queue_like<default_t>::value,
		ostream &>::type
	print(const default_t &x);

	template <typename char_t, typename... Types>
	ostream &print(const std::basic_string<char_t> &x);

#if __cplusplus >= 201703L
	template <typename char_t, typename... Types>
	ostream &print(const std::basic_string_view<char_t> &x)
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
	ostream &print(const char *x);

	template <typename... Types>
	ostream &print(const bool &x);

	template <typename first_t, typename second_t, typename... Types>
	ostream &print(const std::pair<first_t, second_t> &x);

	template <typename container_t, typename... Types>
	typename std::enable_if<
        !std::is_convertible<container_t, std::basic_string<typename container_t::value_type>>::value
        && is_iterable<container_t>::value, ostream &>::type
	print(const container_t &xs);

	template <typename queue_t, typename... Types>
	typename std::enable_if<is_queue_like<queue_t>::value, ostream &>::type
	print(queue_t &x);

	printer_t &
	operator<<(ostream &(*__pf)(ostream &));

	printer_t &
	operator<<(ios &(*__pf)(ios &));

	printer_t &
	operator<<(std::ios_base &(*__pf)(std::ios_base &));

	printer_t &operator<<(applyF f);

	template <typename T>
	typename std::enable_if<!std::is_base_of<apply_t, T>::value, printer_t &>::type operator<<(T x);

	// template <typename I, typename... Types>
	// typename std::enable_if<is_iterator<I>::value>::type
	// print(I ls, I rs) {
	// 	for (;ls!=rs;ls++) {
	// 		std::cout <<
	// 	}
	// }
};


using printer = basic_printer<char>;

extern printer cout, cerr, clog;

using wprinter = basic_printer<wchar_t>;

extern wprinter wcout, wcerr, wclog;

template <typename T>
printer &print(T x);

    template <typename I>
typename std::enable_if<is_iterator<I>::value, printer &>::type
print(I ls, I rs);

template <typename stream_t>
basic_printer<stream_t> &
endl(basic_printer<stream_t> &__printer);

template <typename stream_t>
basic_printer<stream_t> &
ends(basic_printer<stream_t> &__printer);

template <typename stream_t>
basic_printer<stream_t> &
flush(basic_printer<stream_t> &__printer);

template<typename stream_t>
struct _basic_quotoS : public basic_printer<stream_t>::apply_t
{
	bool q;
	_basic_quotoS(bool q);
};

    using _quotoS = _basic_quotoS<char>;

_quotoS quoto(bool quotoT = true);

template <typename stream_t>
basic_printer<stream_t> &
operator<<(basic_printer<stream_t> &__printer, _basic_quotoS<stream_t> applyS);

// auto &endl = basic_endl<char>;

} // namespace minimum


#include "print.cc"

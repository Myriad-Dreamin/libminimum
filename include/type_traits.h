#pragma once

#include <type_traits>
#include <algorithm>
#include <iomanip>

namespace minimum {
		namespace __is_iterator_np
	{
		namespace detail
		{
			template <typename T>
			auto is_iterator_impl(int)
			-> decltype (
				++std::declval<T&>(), // operator ++
				void(*std::declval<T&>()), // operator*
				std::true_type{});

			template <typename T>
			std::false_type is_iterator_impl(...);
		}

	} // namespace __is_iterator_np

	template <typename T>
	using is_iterator = decltype(__is_iterator_np::detail::is_iterator_impl<T>(0));

	namespace __is_iterable_np
	{
		namespace detail
		{
			// To allow ADL with custom begin/end
			using std::begin;
			using std::end;

			template <typename T>
			auto is_iterable_impl(int)
			-> decltype (
				begin(std::declval<T&>()) != end(std::declval<T&>()), // begin/end and operator !=
				void(), // Handle evil operator ,
				++std::declval<decltype(begin(std::declval<T&>()))&>(), // operator ++
				void(*begin(std::declval<T&>())), // operator*
				std::true_type{});

			template <typename T>
			std::false_type is_iterable_impl(...);
		}
	} // namespace __is_iterable_np

	template <typename T>
	using is_iterable = decltype(__is_iterable_np::detail::is_iterable_impl<T>(0));

	namespace __is_queue_like_np
	{
		namespace detail
		{
			template <typename T>
			auto is_queue_like_impl(int)
			-> decltype (
				std::declval<T&>().push(std::declval<T&>().front()),
				std::declval<T&>().pop(),
				std::true_type{});

			template <typename T>
			std::false_type is_queue_like_impl(...);
		}

	} // namespace __is_queue_like_np

	template <typename T>
	using is_queue_like = decltype(__is_queue_like_np::detail::is_queue_like_impl<T>(0));

	namespace has_operator_pp_np
	{
		namespace detail
		{
			template <typename T>
			auto has_operator_pp_impl(int)
			-> decltype (
				// std::declval<T&>().push(std::declval<T&>().front()),
				++std::declval<T&>(),
				std::true_type{});

			template <typename T>
			std::false_type has_operator_pp_impl(...);
		}
		namespace detail0
		{
			template <typename T>
			auto has_operator_pp_impl(int)
			-> decltype (
				std::declval<T&>()++,
				std::true_type{});

			template <typename T>
			std::false_type has_operator_pp_impl(...);
		}
	} // namespace has_operator_pp_np

	template <typename T>
	using has_operator_pp = decltype(has_operator_pp_np::detail::has_operator_pp_impl<T>(0));

	template <typename T>
	using has_operator_spp = decltype(has_operator_pp_np::detail0::has_operator_pp_impl<T>(0));
}


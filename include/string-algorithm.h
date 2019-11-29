#pragma once

#include <string>
#include <vector>
#include "cxx17.h"
#include "type_traits.h"

namespace minimum {
    #ifdef IsCXX17
    #define maybe_string_view std::basic_string_view
    #else
    #define maybe_string_view std::basic_string
    #endif


	template<typename stream_t>
	struct traits {};

	template<>
	struct traits<char> {
		using string = std::basic_string<char>;
		using istream = std::basic_istream<char>;
		static const char line_end = '\n';
		static const char eof = EOF;
		static const char stp = '\0';
	};

    struct _algorithm_policy {
        static const bool emit_empty_chars = true;
    };


    template<class algorithm_policy=_algorithm_policy>
    struct __split_algorithm_impl {


        template<typename stream_t=char, class StringLike=maybe_string_view<stream_t>, class VectorLike=std::vector<StringLike>>
        typename std::enable_if<has_length<StringLike>::value, VectorLike &>::type split(
                const StringLike &s,
                const stream_t sep,
                VectorLike &res
        ) {
            using str = typename VectorLike::value_type;
            res.clear();
            // traits<stream_t>::string
            size_t ls = 0;
            for (int x = 0; x < s.length() ;x++) {
                if (s[x] == sep) {
                    if CXX17_STATIC_CONDITION (algorithm_policy::emit_empty_chars) {
                        if (x != ls) res.push_back(str(s.substr(ls, x-ls)));
                        while(x < s.length() && s[x] == sep) x++;
                    } else {
                        res.push_back(str(s.substr(ls, x-ls)));
                    }
                    ls = x;
                }
            }
            if(ls < s.length()) res.push_back(str(s.substr(ls)));
            return res;
        }

        template<typename stream_t=char, class StringLike=maybe_string_view<stream_t>, class VectorLike=std::vector<StringLike>>
        typename std::enable_if<!has_length<StringLike>::value, VectorLike &>::type split(
                const StringLike &s,
                const stream_t sep,
                VectorLike &res
        ) {
//            static_assert(std::is_same_v<StringLike, VectorLike>, "QAQ");
            return split(maybe_string_view<stream_t>(s), sep, res);
        }

//        template<typename stream_t=char,
//            class StringViewLikeA=maybe_string_view<stream_t>,
//            class StringViewLikeB=StringViewLikeA,
//            class VectorLike=std::vector<StringViewLikeA>>
//        typename std::enable_if<has_length<StringViewLikeA>::value && has_length<StringViewLikeB>::value, VectorLike &>::type &split_s(
//            const StringViewLikeA &s,
//            const StringViewLikeB &sep,
//            VectorLike &res
//        ) {
//            using str = typename VectorLike::value_type;
//            res.clear();
//            size_t ls = 0, sl = sep.length();
//            if (sl < 5) {
//                size_t pos = s.find(sep, 0);
//
//                while(pos != std::string::npos)
//                {
//                    res.push_back(str(s.substr(ls, pos-ls)));
//                    ls = pos + sl;
//                    pos = s.find(sep,ls+1);
//                }
//                res.push_back(str(s.substr(ls)));
//            } else {
//                size_t pos = s.find(sep, 0);
//
//                while(pos != std::string::npos)
//                {
//                    res.push_back(str(s.substr(ls, pos-ls)));
//                    ls = pos + sl;
//                    pos = s.find(sep,ls+1);
//                }
//                res.push_back(str(s.substr(ls)));
//            }
//            return res;
//        }
//
//        template<typename stream_t=char, class StringLike=maybe_string_view<stream_t>, class VectorLike=std::vector<StringLike>>
//        VectorLike &split_s(
//            const StringLike &s,
//            const stream_t *sep,
//            VectorLike &res
//        ) {
//            return split<char>(s, maybe_string_view<stream_t>(sep), res);
//        }
    };

    auto __algorithm_impl_instance = __split_algorithm_impl<>();

    template<typename string_t, typename split_t, typename res_t>
    res_t &split(string_t &&s, split_t &&sep, res_t &res) {
//        static_assert(std::is_same_v<std::is_same<string_t, split_t>, res_t>, "QQQ");
        return __algorithm_impl_instance.split(std::forward<string_t>(s), std::forward<split_t>(sep), res);
    }

	template<typename stream_t>
	bool get_till_nc(
		typename traits<stream_t>::istream &in,
		typename traits<stream_t>::string &res,
		const stream_t line_end=traits<stream_t>::line_end) {
		for (stream_t s;in.get(s);) {
			if (s == line_end) {
				return true;
			}
			res.push_back(s);
		}
		return res.size() != 0;
	}

	template<typename stream_t>
	bool get_till(
		typename traits<stream_t>::istream &in,
		typename traits<stream_t>::string &res,
		const stream_t line_end=traits<stream_t>::line_end) {
		res.clear();
		return get_till_nc(in, res, line_end);
	}

	template<typename stream_t>
	bool till(
		typename traits<stream_t>::istream &in,
		const stream_t line_end=traits<stream_t>::line_end) {
		typename traits<stream_t>::string nil;
		return get_till(in, nil, line_end);
	}

	template<typename stream_t, typename Res>
	using trim_func = Res (*)(stream_t ch);

	template<typename stream_t>
	typename traits<stream_t>::string &trim(
		typename traits<stream_t>::string &str,
		int(*predict)(int)
	) {
		int x = 0,y = str.length() - 1;
		for (; y >= 0 && predict(str[y]); y--);
		for (; x <= y && predict(str[x]); x++);
		str = str.substr(x, y+1);
		return str;
	}

	template<typename stream_t>
	typename traits<stream_t>::string &trim_space(
		typename traits<stream_t>::string &str
	) {
		return trim<stream_t>(str, isspace);
	}

	template<typename stream_t>
	std::vector<typename traits<stream_t>::string> &split_space(
		const typename traits<stream_t>::string &s,
		std::vector<typename traits<stream_t>::string> &res
	) {
		res.clear();
		// traits<stream_t>::string
		size_t ls = 0;
		for (int x = 0; x < s.length() ;x++) {
			if (isspace(s[x])) {
				if (x != ls) res.push_back(s.substr(ls, x-ls));
				while(x < s.length() && isspace(s[x])) x++;
				ls = x;
			}
		}
		if (ls != s.length()) res.push_back(s.substr(ls));
		return res;
	}

#undef maybe_string_view
}
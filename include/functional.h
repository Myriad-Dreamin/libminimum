#pragma once

namespace minimum
{
	template<typename T, typename F>
	T &map(T &vec, const F &f) {
		for (auto &element: vec) {
			element = f(element);
		}
		return vec;
	}

    template<typename S, typename T, typename F>
    T &map_st(S &svec, T &tvec, const F &f) {
        tvec.resize(svec.size());
        for (size_t i = 0; i < svec.size(); i++) {
            tvec[i] = f(svec[i]);
        }
        return tvec;
    }

    template<typename S, typename T, typename F>
    T map_st_copy(S &s_vec, const F &f) {
        T t_vec;
        t_vec.resize(s_vec.size());
        for (size_t i = 0; i < s_vec.size(); i++) {
            t_vec[i] = f(s_vec[i]);
        }
        return t_vec;
    }

	template<typename T, typename F>
	T &map_void(T &vec, const F &f) {
		for (auto &element: vec) {
			f(element);
		}
		return vec;
	}

	template<typename Iterator, typename Receiver>
	Receiver fold(Iterator _begin, Iterator _end, void (*folder)(Receiver&, const decltype(*_begin)&), Receiver recv = Receiver()) {
		for (; _begin != _end; _begin++) {
			folder(recv, *_begin);
		}
		return recv;
	}

} // namespace functional

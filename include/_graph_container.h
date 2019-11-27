#pragma once

#include <map>

namespace minimum {
    template<typename __node_t, typename __edge_id_t>
    struct __graph_node_container {
        using edge_id_t = __edge_id_t;
        using node_t = __node_t;
		std::map<node_t, edge_id_t> __head;

        void init(int _=0) {
			__head.clear();
        }

        // must inline
        inline edge_id_t head(const node_t &n) const {
            return __head.at(n);
        }

        // must inline
        inline edge_id_t &head(const node_t &n) {
            return __head[n];
        }

        // must inline
        inline bool count(const node_t &n) const {
            return __head.count(n);
        }
    };
    
    template<typename __node_t, int64_t VSize, typename edge_t, typename edge_t::edge_id_t __null_edge_id>
    struct __fixed_integral_graph_node_container {
        using edge_id_t = typename edge_t::edge_id_t;
        using node_t = __node_t;

		static constexpr int64_t vsize_v = VSize;
		edge_id_t __head[vsize_v];
        
		void init(int n = VSize) {
#ifdef _DEBUG
            assert(("n <= VSize", n <= VSize));
#endif
            std::fill(__head, __head + n, __null_edge_id);
		}

        // must inline
        inline edge_id_t head(node_t n) const {
            return __head[n];
        }

        // must inline
        inline edge_id_t &head(node_t n) {
            return __head[n];
        }

        // must inline
        inline bool count(node_t n) const {
            return __head[n] != __null_edge_id;
        }
    };

    template<typename __node_t, typename __edge_t, typename node_container, typename __edge_t::edge_id_t __null_edge_id>
    struct __graph_edge_container {
        using edge_id_t = typename __edge_t::edge_id_t;
        using node_t = __node_t;
        using edge_t = __edge_t;
        static const edge_id_t null_edge_id = __null_edge_id;
        static const edge_id_t begin_edge_id = null_edge_id + 1;

        std::vector<edge_t> e;
		edge_id_t mal;

        node_container &noder;

        __graph_edge_container(node_container &noder) :noder(noder) {
        }

        void init(int _=0) {
			mal = begin_edge_id;
        }

        // must inline
        inline const edge_t & _at_e(edge_id_t id) const {
            return e[id - begin_edge_id];
        }
        
        // must inline
        inline edge_t & _at_e(edge_id_t id) {
            return e[id - begin_edge_id];
        }
        
        // must inline
        inline edge_t & edge(edge_id_t id) {
            return e[id - begin_edge_id];
        }

        // must inline
        inline edge_id_t next(edge_id_t id) const {
            return e[id - begin_edge_id].nx;
        }

        // must inline
        inline edge_id_t next(edge_id_t id) {
            return e[id - begin_edge_id].nx;
        }

        // must inline
        inline edge_t & _alloc_e(const node_t &u, const node_t &v) {
            e.push_back(edge_t());
            auto &edge = e[mal - begin_edge_id]; auto &hu = noder.head(u);
            edge.to = v;
            edge.nx = hu; hu = mal++;
            return edge;
        }
    };

    template<typename __node_t, typename node_container,
        int64_t ESize, bool undirected, typename __edge_t, typename __edge_t::edge_id_t __null_edge_id = 0>
    struct __fixed_graph_edge_container {
        using edge_id_t = typename __edge_t::edge_id_t;
        using node_t = __node_t;
        using edge_t = __edge_t;
		static constexpr int64_t esize_v = undirected ? (ESize << 1) : ESize;
        static const edge_id_t null_edge_id = __null_edge_id;

        edge_t e[esize_v];
		edge_id_t mal;
        
        node_container &noder;

        __fixed_graph_edge_container(node_container &noder) :noder(noder) {
        }

		void init(int _=0) {
			mal = null_edge_id + 1;
		}

        // must inline
        inline const edge_t & _at_e(edge_id_t id) const {
            return e[id];
        }
        
        // must inline
        inline edge_t & _at_e(edge_id_t id) {
            return e[id];
        }
        
        // must inline
        inline edge_t & edge(edge_id_t id) {
            return e[id];
        }

        // must inline
        inline edge_id_t next(edge_id_t id) const {
            return e[id].nx;
        }

        // must inline
        inline edge_id_t next(edge_id_t id) {
            return e[id].nx;
        }

        inline edge_t & _alloc_e(const node_t &u, const node_t &v) {
            auto &edge = e[mal]; auto &hu = noder.head(u);
            edge.to = v;
            edge.nx = hu; hu = mal++;
            return edge;
        }
    };
}


#pragma once

#include <stdint.h>
#include "_edge.h"
#include "_graph.h"


namespace minimum {
    template<typename node_type, int64_t VSize, int64_t ESize, bool undirected,
        typename edge_id_t, typename edge_t, edge_id_t __null_edge_id = 0, typename Match=void>
    struct __fixed_graph_container {
		static constexpr int64_t esize_v = undirected ? (ESize << 1) : ESize;
        edge_t e[esize_v];
		std::map<node_type, edge_id_t> __head;
		edge_id_t mal;
        static const edge_id_t null_edge_id = __null_edge_id;
		__fixed_graph_container() {
			init();
		}

		__fixed_graph_container(int n) {
			init(n + 1);
		}

		void init(int n = VSize) {
			__head.clear();
			mal = null_edge_id + 1;
		}

        // must inline
        inline edge_id_t head(const node_type &n) const {
            return __head.at(n);
        }

        // must inline
        inline bool count(const node_type &n) const {
            return __head.count(n);
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

        inline edge_t & _alloc_e(const node_type &u, const node_type &v) {
            auto &edge = e[mal]; auto &hu = __head[u];
            edge.to = v;
            edge.nx = hu; hu = mal++;
            return edge;
        }
    };

    template<typename node_type, int64_t VSize, int64_t ESize, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = Edge<edge_id_t, node_type>,
        typename container_t = __fixed_graph_container<node_type, VSize, ESize, undirected, edge_id_t, edge_t> >
    using fixed_graph = __graph<node_type, undirected, edge_id_t, edge_t, container_t>;

    
	template<typename node_type, int64_t VSize, int64_t ESize, typename weighter, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = WeightedEdge<edge_id_t, node_type, weighter>,
        typename container_t = __fixed_graph_container<node_type, VSize, ESize, undirected, edge_id_t, edge_t> >
	using fixed_weighted_graph = __weighted_graph<node_type, weighter, undirected, edge_id_t, edge_t, container_t>;
}
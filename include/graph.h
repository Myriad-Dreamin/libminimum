#pragma once

#include "cxx17.h"
#include <map>
#include "_graph.h"
#include "_edge.h"

namespace minimum {
    template<typename node_type, typename edge_id_t, typename edge_t, bool undirected, edge_id_t __null_edge_id = 0>
    struct __default_graph_container {
        std::vector<edge_t> e;
		std::map<node_type, edge_id_t> __head;
        static const edge_id_t null_edge_id = __null_edge_id;
        static const edge_id_t begin_edge_id = null_edge_id + 1;
		edge_id_t mal;
		__default_graph_container() {
			init();
		}

		void init() {
			__head.clear();
			mal = begin_edge_id;
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
        inline edge_t & _alloc_e(const node_type &u, const node_type &v) {
            e.push_back(edge_t());
            auto &edge = e[mal - begin_edge_id]; auto &hu = __head[u];
            edge.to = v;
            edge.nx = hu; hu = mal++;
            return edge;
        }
    };
    
    template<typename node_type, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = Edge<edge_id_t, node_type>,
        typename container_t = __default_graph_container<node_type, edge_id_t, edge_t, undirected> >
    using graph = __graph<node_type, undirected, edge_id_t, edge_t, container_t>;

    
	template<typename node_type, typename weighter, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = WeightedEdge<edge_id_t, node_type, weighter>,
        typename container_t = __default_graph_container<node_type, edge_id_t, edge_t, undirected> >
	using weighted_graph = __weighted_graph<node_type, weighter, undirected, edge_id_t, edge_t, container_t>;
}

#pragma once

#include "_graph_container.h"
#include "graph_container.h"
#include <stdint.h>
#include <algorithm>
#include "_edge.h"
#include "_graph.h"


namespace minimum {

    template<typename node_t, int64_t ESize, bool undirected, typename edge_t, typename edge_t::edge_id_t __null_edge_id = 0>
    using __default_fix_graph_container = graph_container<
        __graph_node_container<node_t, typename edge_t::edge_id_t>,
        __fixed_graph_edge_container<node_t, __graph_node_container<node_t, typename edge_t::edge_id_t>, ESize, undirected, edge_t,
            __null_edge_id> >;

    template<typename node_t, int64_t ESize, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = Edge<edge_id_t, node_t>,
        typename container_t = __default_fix_graph_container<node_t, ESize, undirected, edge_t> >
    using fixed_graph = __graph<node_t, undirected, edge_id_t, edge_t, container_t>;
    
	template<typename node_t, int64_t ESize, typename weighter, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = WeightedEdge<edge_id_t, node_t, weighter>,
        typename container_t = __default_fix_graph_container<node_t, ESize, undirected, edge_t> >
	using fixed_weighted_graph = __weighted_graph<node_t, weighter, undirected, edge_id_t, edge_t, container_t>;

    template<typename node_t, int64_t VSize, int64_t ESize, bool undirected, typename edge_t, typename edge_t::edge_id_t __null_edge_id = 0>
    using __default_fixed_integral_graph_container = graph_container<
        __fixed_integral_graph_node_container<node_t, VSize, edge_t, __null_edge_id>,
        __fixed_graph_edge_container<node_t, __fixed_integral_graph_node_container<node_t, VSize, edge_t, __null_edge_id>,
            ESize, undirected, edge_t, __null_edge_id> >;

    template<typename node_t, int64_t VSize, int64_t ESize, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = Edge<edge_id_t, node_t>,
        typename container_t = __default_fixed_integral_graph_container<node_t, VSize, ESize, undirected, edge_t> >
    using fixed_integral_graph = __graph<node_t, undirected, edge_id_t, edge_t, container_t>;

    
	template<typename node_t, int64_t VSize, int64_t ESize, typename weighter, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = WeightedEdge<edge_id_t, node_t, weighter>,
        typename container_t = __default_fixed_integral_graph_container<node_t, VSize, ESize, undirected, edge_t> >
	using fixed_integral_weighted_graph = __weighted_graph<node_t, weighter, undirected, edge_id_t, edge_t, container_t>;
}
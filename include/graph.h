#pragma once

#include "_graph_container.h"
#include "graph_container.h"
#include "cxx17.h"
#include "_graph.h"
#include "_edge.h"

namespace minimum {
    
    template<typename node_t, typename edge_t, typename edge_t::edge_id_t __null_edge_id = 0>
    using __default_graph_container = graph_container<
        __graph_node_container<node_t, typename edge_t::edge_id_t>,
        __graph_edge_container<node_t, edge_t, __graph_node_container<node_t, typename edge_t::edge_id_t>,
            __null_edge_id> >;
    
    template<typename node_t, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = Edge<edge_id_t, node_t>,
        typename container_t = __default_graph_container<node_t, edge_t> >
    using graph = __graph<node_t, undirected, edge_id_t, edge_t, container_t>;

    
	template<typename node_t, typename weighter, bool undirected = false, typename edge_id_t = int32_t,
        typename edge_t = WeightedEdge<edge_id_t, node_t, weighter>,
        typename container_t = __default_graph_container<node_t, edge_t> >
	using weighted_graph = __weighted_graph<node_t, weighter, undirected, edge_id_t, edge_t, container_t>;
}

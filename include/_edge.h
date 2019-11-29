#pragma once

#include <iostream>

namespace minimum {
	template<typename __edge_id_t, typename node_type>
	struct Edge {
        using edge_id_t = __edge_id_t;
		edge_id_t nx;
		node_type to;
		Edge();
		Edge(edge_id_t nx, node_type to);
	};

    template<typename edge_id_t, typename node_type>
	std::ostream &operator<< (std::ostream &os, Edge<edge_id_t, node_type> &e);


    template<typename __edge_id_t, typename node_type, typename weighter>
	struct WeightedEdge: public Edge<__edge_id_t, node_type> {
        using edge_id_t = __edge_id_t;
		weighter w;

		WeightedEdge();
		WeightedEdge(const edge_id_t &nx, const node_type &to, const weighter &w);
	};

    template<typename edge_id_t, typename node_type, typename weighter>
	std::ostream &operator<< (std::ostream &os, WeightedEdge<edge_id_t, node_type, weighter> &e);
}

#include "_edge.cc"

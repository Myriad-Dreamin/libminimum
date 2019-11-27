#pragma once

#include <iostream>

namespace minimum {
	template<typename __edge_id_t, typename node_type>
	struct Edge {
        using edge_id_t = __edge_id_t;
		edge_id_t nx;
		node_type to;
		Edge() {
			nx = 0;
		};
		Edge(edge_id_t nx, node_type to): nx(nx), to(to) {};
	};

	template<typename edge_id_t, typename node_type>
	std::ostream &operator<< (std::ostream &os, Edge<edge_id_t, node_type> &e) {
		os << "(" << e.nx << ", " << e.to << ")";
		return os;
	}


	template<typename __edge_id_t, typename node_type, typename weighter>
	struct WeightedEdge: public Edge<__edge_id_t, node_type> {
        using edge_id_t = __edge_id_t;
		weighter w;

		WeightedEdge():Edge<edge_id_t, node_type>() {};
		WeightedEdge(const edge_id_t &nx, const node_type &to, const weighter &w): Edge<edge_id_t, node_type>(nx, to), w(w) {};
	};

	template<typename edge_id_t, typename node_type, typename weighter>
	std::ostream &operator<< (std::ostream &os, WeightedEdge<edge_id_t, node_type, weighter> &e) {
		os << "(" << e.nx << ", " << e.to << ", " << e.w << ")";
		return os;
	}
}

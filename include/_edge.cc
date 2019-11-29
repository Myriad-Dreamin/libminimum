#pragma once

#include <_edge.h>

namespace minimum {
#define edge_class Edge<__edge_id_t, node_type>
#define weighted_edge_class WeightedEdge<__edge_id_t, node_type, weighter>

    template<typename __edge_id_t, typename node_type>
    edge_class::Edge() {
        nx = 0;
    }

    template<typename __edge_id_t, typename node_type>
    edge_class::Edge(edge_id_t nx, node_type to): nx(nx), to(to) {}

    template<typename edge_id_t, typename node_type>
    std::ostream &operator<<(std::ostream &os, Edge<edge_id_t, node_type> &e) {
        os << "(" << e.nx << ", " << e.to << ")";
        return os;
    }

    template<typename __edge_id_t, typename node_type, typename weighter>
    weighted_edge_class::WeightedEdge():Edge<edge_id_t, node_type>() {}

    template<typename __edge_id_t, typename node_type, typename weighter>
    weighted_edge_class::WeightedEdge(const edge_id_t &nx, const node_type &to,
                                                                 const weighter &w): Edge<edge_id_t, node_type>(nx, to), w(w) {}

    template<typename edge_id_t, typename node_type, typename weighter>
    std::ostream &operator<<(std::ostream &os, WeightedEdge<edge_id_t, node_type, weighter> &e) {
        os << "(" << e.nx << ", " << e.to << ", " << e.w << ")";
        return os;
    }

#undef edge_class
#undef weighted_edge_class
}
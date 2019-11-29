#pragma once

#include <_graph.h>
#include "cxx17.h"


namespace minimum {
#define graph_class __graph<node_type, undirected, edge_id_t, edge_t, __container_t>
#define weighted_graph_class __weighted_graph<node_type, weighter, undirected, edge_id_t, edge_t, __container_t>

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    graph_class::__graph() :container_t() {
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    void
    graph_class::add_edge(const node_type &u, const node_type &v) {
        if CXX17_STATIC_CONDITION (undirected) {
            container_t::_alloc_e(u, v);
            container_t::_alloc_e(v, u);
        } else {
            container_t::_alloc_e(u, v);
        }
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::partial_node_iterator
    graph_class::at(const node_type &u) {
        return partial_node_iterator(*this, u);
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::partial_edge_iterator
    graph_class::at_e(const node_type &u) {
        return partial_edge_iterator(*this, u);
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::const_partial_node_iterator
    graph_class::at(const node_type &u) const {
        return const_partial_node_iterator(*this, u);
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::const_partial_edge_iterator
    graph_class::at_e(const node_type &u) const {
        return const_partial_edge_iterator(*this, u);
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::__base_edge_iterator &
    graph_class::__base_edge_iterator::operator++() {
        edge_id = view.next(edge_id);
        return *this;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::__base_edge_iterator &
    graph_class::__base_edge_iterator::operator++(int) {
        return operator++();
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    bool graph_class::__base_edge_iterator::operator!=(
            const __graph::__base_edge_iterator &i) const {
        return edge_id != i.edge_id;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    bool graph_class::__base_edge_iterator::operator==(
            const __graph::__base_edge_iterator &i) const {
        return edge_id == i.edge_id;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    graph_class::__base_const_edge_iterator::__base_const_edge_iterator(
            const __graph::graph_t &g, edge_id_t edge_id):view(g), edge_id(edge_id) {}

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::__base_const_edge_iterator &
    graph_class::__base_const_edge_iterator::operator++() {
        edge_id = view.next(edge_id);
        return *this;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    typename graph_class::__base_const_edge_iterator &
    graph_class::__base_const_edge_iterator::operator++(int) {
        return operator++();
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    bool graph_class::__base_const_edge_iterator::operator!=(
            const __graph::__base_const_edge_iterator &i) const {
        return edge_id != i.edge_id;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    bool graph_class::__base_const_edge_iterator::operator==(
            const __graph::__base_const_edge_iterator &i) const {
        return edge_id == i.edge_id;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    graph_class::node_iterator::node_iterator(__graph::graph_t &g,
                                              edge_id_t edge_id): f_class(g, edge_id) {}

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    node_type &graph_class::node_iterator::operator*() {
        // std::cout << "call" << std::endl;
        return f_class::view._at_e(f_class::edge_id).to;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    graph_class::const_node_iterator::const_node_iterator(
            const __graph::graph_t &g, edge_id_t edge_id): f_class(g, edge_id) {}

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    const node_type &
    graph_class::const_node_iterator::operator*() const {
        // std::cout << "call const" << std::endl;
        return f_class::view._at_e(f_class::edge_id).to;
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    graph_class::edge_iterator::edge_iterator(__graph::graph_t &g,
                                              edge_id_t edge_id): f_class(g, edge_id) {}

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    edge_t &graph_class::edge_iterator::operator*() {
        return f_class::view._at_e();
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    graph_class::const_edge_iterator::const_edge_iterator(
            const __graph::graph_t &g, edge_id_t edge_id): f_class(g, edge_id) {}

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    const edge_t &
    graph_class::const_edge_iterator::operator*() const {
        return f_class::view._at_e();
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    template<class iterator>
    graph_class::partial_iterator<iterator>::partial_iterator(
            __graph::graph_t &g, const node_type &u):view(g), u(u) {}

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    template<class iterator>
    iterator graph_class::partial_iterator<iterator>::begin() {
        if (!view.count(u)) {
            return end();
        }
        return iterator(view, view.head(u));
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    template<class iterator>
    iterator graph_class::partial_iterator<iterator>::end() {
        return iterator(view, container_t::null_edge_id);
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    template<class iterator>
    graph_class::const_partial_iterator<iterator>::const_partial_iterator(
            const __graph::graph_t &g, const node_type &u):view(g), u(u) {}

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    template<class iterator>
    iterator graph_class::const_partial_iterator<iterator>::begin() {
        if (!view.count(u)) {
            return end();
        }
        return iterator(view, view.head(u));
    }

    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    template<class iterator>
    iterator graph_class::const_partial_iterator<iterator>::end() {
        return iterator(view, container_t::null_edge_id);
    }

    template<typename node_type, typename weighter, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    void
    weighted_graph_class::addedge(const node_type &u,
                                  const node_type &v,
                                  const weighter &w) {
        if CXX17_STATIC_CONDITION (undirected) {
            _addedge(u, v, w);
            _addedge(v, u, w);
        } else {
            _addedge(u, v, w);
        }
    }

    template<typename node_type, typename weighter, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    weighted_graph_class::__weighted_graph(): f_class() {}

    template<typename node_type, typename weighter, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    weighted_graph_class::__weighted_graph(int n): f_class(n) {}

    template<typename node_type, typename weighter, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    void
    weighted_graph_class::addedge(const node_type &u,
                                  const node_type &v) {
        f_class::addedge(u, v);
    }

    template<typename node_type, typename weighter, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    void
    weighted_graph_class::_addedge(const node_type &u,
                                   const node_type &v,
                                   const weighter &w) {
        auto &edge = f_class::container_t::_alloc_e(u, v);
        edge.w = w;
    }

#undef graph_class
#undef weighted_graph_class
}
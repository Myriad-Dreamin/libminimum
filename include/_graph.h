#pragma once

#include <stdint.h>


namespace minimum {
    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    struct __graph : public __container_t {
		using graph_t = __graph<node_type, undirected, edge_id_t, edge_t, __container_t>;
		using container_t = __container_t;
		
		__graph() :container_t() {
		}

		__graph(int n) :container_t(n) {
		}

		void addedge(const node_type &u, const node_type &v) {
			if CXX17_STATIC_CONDITION (undirected) {
                container_t::_alloc_e(u, v);
                container_t::_alloc_e(v, u);
			} else {
                container_t::_alloc_e(u, v);
			}
		}

        struct __base_edge_iterator {
			graph_t &view;
			edge_id_t edge_id;
			__base_edge_iterator(graph_t &g, edge_id_t edge_id):view(g), edge_id(edge_id) {}
			__base_edge_iterator &operator++() {
				edge_id = view.next(edge_id);
				return *this;
			}
			__base_edge_iterator &operator++(int) {
				return operator++();
			}
			bool operator!=(const __base_edge_iterator &i) const {
				return edge_id != i.edge_id;
			}
			bool operator==(const __base_edge_iterator &i) const {
				return edge_id == i.edge_id;
			}
		};

        struct __base_const_edge_iterator {
			const graph_t &view;
			edge_id_t edge_id;
			__base_const_edge_iterator(const graph_t &g, edge_id_t edge_id):view(g), edge_id(edge_id) {}
			__base_const_edge_iterator &operator++() {
				edge_id = view.next(edge_id);
				return *this;
			}
			__base_const_edge_iterator &operator++(int) {
				return operator++();
			}
			bool operator!=(const __base_const_edge_iterator &i) const {
				return edge_id != i.edge_id;
			}
			bool operator==(const __base_const_edge_iterator &i) const {
				return edge_id == i.edge_id;
			}
		};

		struct node_iterator: public __base_edge_iterator {
			using f_class = __base_edge_iterator;
			node_iterator(graph_t &g, edge_id_t edge_id): f_class(g, edge_id) {}
			node_type &operator*() {
                // std::cout << "call" << std::endl;
				return f_class::view._at_e(f_class::edge_id).to;
			}
		};

        struct const_node_iterator: public __base_const_edge_iterator {
			using f_class = __base_const_edge_iterator;
			const_node_iterator(const graph_t &g, edge_id_t edge_id): f_class(g, edge_id) {}
			const node_type &operator*() const {
                // std::cout << "call const" << std::endl;
				return f_class::view._at_e(f_class::edge_id).to;
			}
		};

		struct edge_iterator: public __base_edge_iterator {
			using f_class = __base_edge_iterator;
			edge_iterator(graph_t &g, edge_id_t edge_id): f_class(g, edge_id) {}
			edge_t &operator*() {
				return f_class::view._at_e();
			}
		};

		struct const_edge_iterator: public __base_const_edge_iterator {
			using f_class = __base_const_edge_iterator;
			const_edge_iterator(const graph_t &g, edge_id_t edge_id): f_class(g, edge_id) {}
			const edge_t &operator*() const {
				return f_class::view._at_e();
			}
		};

		template<class iterator>
		struct partial_iterator {
			graph_t &view;
			const node_type &u;
			partial_iterator(graph_t &g, const node_type &u):view(g), u(u) {};

			iterator begin() {
				if (!view.count(u)) {
					return end();
				}
				return iterator(view, view.head(u));
			}
			iterator end() {
				return iterator(view, container_t::null_edge_id);
			}
		};

		template<class iterator>
		struct const_partial_iterator {
			const graph_t &view;
			const node_type &u;
			const_partial_iterator(const graph_t &g, const node_type &u):view(g), u(u) {};

			iterator begin() {
				if (!view.count(u)) {
					return end();
				}
				return iterator(view, view.head(u));
			}
			iterator end() {
				return iterator(view, container_t::null_edge_id);
			}
		};

		using partial_node_iterator = partial_iterator<node_iterator>;
		partial_node_iterator at(const node_type &u) {
			return partial_node_iterator(*this, u);
		}

		using partial_edge_iterator = partial_iterator<edge_iterator>;
		partial_edge_iterator at_e(const node_type &u) {
			return partial_edge_iterator(*this, u);
		}

		using const_partial_node_iterator = const_partial_iterator<const_node_iterator>;
		const_partial_node_iterator at(const node_type &u) const {
			return const_partial_node_iterator(*this, u);
		}

		using const_partial_edge_iterator = const_partial_iterator<const_edge_iterator>;
		const_partial_edge_iterator at_e(const node_type &u) const {
			return const_partial_edge_iterator(*this, u);
		}
	};


	template<typename node_type, typename weighter, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    struct __weighted_graph: public __graph<node_type, undirected, edge_id_t, edge_t, __container_t> {
		using f_class = __graph<node_type, undirected, edge_id_t, edge_t, __container_t>;
		__weighted_graph(): f_class() {}
		__weighted_graph(int n): f_class(n) {}

		void addedge(const node_type &u, const node_type &v, const weighter &w) {
			if CXX17_STATIC_CONDITION (undirected) {
				_addedge(u, v, w);
				_addedge(v, u, w);
			} else {
				_addedge(u, v, w);
			}
		}

		void addedge(const node_type &u, const node_type &v) {
			f_class::addedge(u, v);
		}

		private:
			void _addedge(const node_type &u, const node_type &v, const weighter &w) {
                auto &edge = f_class::container_t::_alloc_e(u, v);
				edge.w = w;
			}
	};
}


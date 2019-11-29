#pragma once

#include <stdint.h>


namespace minimum {
    template<typename node_type, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    struct __graph : public __container_t {
		using graph_t = __graph<node_type, undirected, edge_id_t, edge_t, __container_t>;
		using container_t = __container_t;
		
		__graph();

		__graph(int n) :container_t(n) {
		}

        virtual void add_edge(const node_type &u, const node_type &v);

        struct __base_edge_iterator {
			graph_t &view;
			edge_id_t edge_id;
			__base_edge_iterator(graph_t &g, edge_id_t edge_id):view(g), edge_id(edge_id) {}
			__base_edge_iterator &operator++();
			__base_edge_iterator &operator++(int);
			bool operator!=(const __base_edge_iterator &i) const;
			bool operator==(const __base_edge_iterator &i) const;
		};

        struct __base_const_edge_iterator {
			const graph_t &view;
			edge_id_t edge_id;
			__base_const_edge_iterator(const graph_t &g, edge_id_t edge_id);
			__base_const_edge_iterator &operator++();
			__base_const_edge_iterator &operator++(int);
			bool operator!=(const __base_const_edge_iterator &i) const;
			bool operator==(const __base_const_edge_iterator &i) const;
		};

		struct node_iterator: public __base_edge_iterator {
			using f_class = __base_edge_iterator;
			node_iterator(graph_t &g, edge_id_t edge_id);
			node_type &operator*();
		};

        struct const_node_iterator: public __base_const_edge_iterator {
			using f_class = __base_const_edge_iterator;
			const_node_iterator(const graph_t &g, edge_id_t edge_id);
			const node_type &operator*() const;
		};

		struct edge_iterator: public __base_edge_iterator {
			using f_class = __base_edge_iterator;
			edge_iterator(graph_t &g, edge_id_t edge_id);
			edge_t &operator*();
		};

		struct const_edge_iterator: public __base_const_edge_iterator {
			using f_class = __base_const_edge_iterator;
			const_edge_iterator(const graph_t &g, edge_id_t edge_id);
			const edge_t &operator*() const;
		};

		template<class iterator>
		struct partial_iterator {
			graph_t &view;
			const node_type &u;
			partial_iterator(graph_t &g, const node_type &u);;

			iterator begin();
			iterator end();
		};

		template<class iterator>
		struct const_partial_iterator {
			const graph_t &view;
			const node_type &u;
			const_partial_iterator(const graph_t &g, const node_type &u);;

			iterator begin();
			iterator end();
		};

		using partial_node_iterator = partial_iterator<node_iterator>;
		partial_node_iterator at(const node_type &u);

		using partial_edge_iterator = partial_iterator<edge_iterator>;
		partial_edge_iterator at_e(const node_type &u);

		using const_partial_node_iterator = const_partial_iterator<const_node_iterator>;
		const_partial_node_iterator at(const node_type &u) const;

		using const_partial_edge_iterator = const_partial_iterator<const_edge_iterator>;
		const_partial_edge_iterator at_e(const node_type &u) const;
	};


    template<typename node_type, typename weighter, bool undirected, typename edge_id_t, typename edge_t, typename __container_t>
    struct __weighted_graph: public __graph<node_type, undirected, edge_id_t, edge_t, __container_t> {
		using f_class = __graph<node_type, undirected, edge_id_t, edge_t, __container_t>;
		__weighted_graph();
		__weighted_graph(int n);

		void addedge(const node_type &u, const node_type &v, const weighter &w);

		void addedge(const node_type &u, const node_type &v);

		private:
			void _addedge(const node_type &u, const node_type &v, const weighter &w);
	};
}

#include "_graph.cc"


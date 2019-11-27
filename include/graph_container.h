#pragma once


namespace minimum {
    template<typename __node_container, typename __edge_container>
    struct graph_container {
        using node_container_t = __node_container;
        using edge_container_t = __edge_container;
        using edge_id_t = typename edge_container_t::edge_id_t;
        using node_t = typename node_container_t::node_t;
        using edge_t = typename edge_container_t::edge_t;
        static constexpr edge_id_t null_edge_id = edge_container_t::null_edge_id;

        node_container_t noder;
        edge_container_t edger;

		graph_container() :noder(), edger(noder) {
            init();
		}

		graph_container(int n) : noder(), edger(noder) {
			init(n);
		}

		graph_container(int n, int m) : noder(), edger(noder) {
			init(n, m);
		}

		void init() {
            noder.init();
            edger.init();
		}

		void init(int n) {
            noder.init(n);
            edger.init();
		}

		void init(int n, int m) {
            noder.init(n);
            edger.init(m);
		}

        // must inline
        inline edge_id_t head(const node_t &n) const {
            return noder.head(n);
        }

        // must inline
        inline bool count(const node_t &n) const {
            return noder.count(n);
        }

        // must inline
        inline const edge_t & _at_e(edge_id_t id) const {
            return edger._at_e(id);
        }
        
        // must inline
        inline edge_t & _at_e(edge_id_t id) {
            return edger._at_e(id);
        }
        
        // must inline
        inline edge_t & edge(edge_id_t id) {
            return edger.edge(id);
        }

        // must inline
        inline edge_id_t next(edge_id_t id) const {
            return edger.next(id);
        }

        // must inline
        inline edge_id_t next(edge_id_t id) {
            return edger.next(id);
        }

        // must inline
        inline edge_t & _alloc_e(const node_t &u, const node_t &v) {
            return edger._alloc_e(u, v);
        }
    };
}
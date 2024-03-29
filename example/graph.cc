
#include <print.h>
#include <graph.h>
#include <fixed_graph.h>

using namespace minimum;


int main2() {
    
    using fgraph_t = fixed_integral_graph<int, 100, 100>;
    fgraph_t fg;
    fg.add_edge(2, 3);
    fg.add_edge(2, 4);
    for(auto &e: fg.at(2)) {
        cout << e << endl;
    }
    const auto &fg_const = fg;
    fgraph_t::const_partial_node_iterator fpti = fg_const.at(2);
    for(int e : fpti) {
        cout << e << endl;
    }
    return 0;
}

int main() {
#ifdef NFix
    using graph_t = graph<int>;
    graph_t g;
    g.addedge(2, 3);
    g.addedge(2, 4);
    for(auto &e: g.at(2)) {
        cout << e << endl;
    }
    const auto &g_const = g;
    graph_t::const_partial_node_iterator pti = g_const.at(2);
    for(auto e = pti.begin(); e != pti.end(); e++) {
        cout << *e << endl;
    }
#endif
#ifdef Fix
    using fgraph_t = fixed_graph<int, 100>;
    fgraph_t fg;
    fg.add_edge(2, 3);
    fg.add_edge(2, 4);

    for(auto &e: fg.at(2)) {
        cout << e << endl;
    }
    const auto &fg_const = fg;
    fgraph_t::const_partial_node_iterator fpti = fg_const.at(2);
    for(int e : fpti) {
        cout << e << endl;
    }
#endif
    
    return main2();
}


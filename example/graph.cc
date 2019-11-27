
#include <print.h>
#include <graph.h>
#include <fixed_graph.h>

using namespace minimum;

int main2();

int main() {
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

    return main2();
}


int main2() {
    using graph_t = fixed_graph<int, 100, 100>;
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
    
    return 0;
}

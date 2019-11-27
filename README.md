# libminimum
all file is head only
## `print.h`
#### Hello world
```cpp
#include <bits/minimum.h>

using namespace minimum;

int main() {
    cout << quoto(true) << "hello world" << endl;
}
```

see the example
```bash
kamiyoru@kamiya:~/work/cpp/minimum-lib$ cd example/
kamiyoru@kamiya:~/work/cpp/minimum-lib/example$ 
kamiyoru@kamiya:~/work/cpp/minimum-lib/example$ make print-hello-world
mkdir -p build
g++   -DHelloWorld print.cc -I../include -o build/example -fmax-errors=1
build/example
"hello world"
```

#### Print Containers

```cpp
#include <vector>
#include <set>
#include <queue>
#include <bits/minimum.h>

using namespace minimum;

int main() {
    cout << std::vector<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)}) << endl;
    cout << std::set<Int>({Int(1),Int(2),Int(3),Int(4),Int(5),Int(6)}) << endl;
    cout << std::deque<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)}) << endl;
}
```

see the example

```bash
kamiyoru@kamiya:~/work/cpp/minimum-lib/example$ make print-serial-container 
mkdir -p build
g++   -DSerialContainer print.cc -I../include -o build/example -fmax-errors=1
build/example
{3,3,4,4,5,7}
{1,2,3,4,5,6}
{3,3,4,4,5,7}
```

## `graph.h/fixed_graph.h`

`graph.h`

```cpp
#include <graph.h>

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
}
```

see the example

```bash
E:\project\cpp\work\libminimum\example (master)
$ make graph-nfix
mkdir -p build
g++   -DNFix graph.cc -I../include -o build/example -fmax-errors=1
build/example
4
3
4
3
```

`fixed_graph.h`

```cpp
#include <fixed_graph.h>

int main() {
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
}
```

see the example

```bash
E:\project\cpp\work\libminimum\example (master)
$ make graph-nfix
mkdir -p build
g++   -DNFix graph.cc -I../include -o build/example -fmax-errors=1
build/example
4
3
4
3
```


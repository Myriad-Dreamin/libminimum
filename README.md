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

```bash
kamiyoru@kamiya:~/work/cpp/minimum-lib/example$ make print-serial-container 
mkdir -p build
g++   -DSerialContainer print.cc -I../include -o build/example -fmax-errors=1
build/example
{3,3,4,4,5,7}
{1,2,3,4,5,6}
{3,3,4,4,5,7}
```
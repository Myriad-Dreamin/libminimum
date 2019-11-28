#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

#include <bits/minimum.h>
#include <_int.h>

using namespace minimum;

int main() {
#ifdef HelloWorld
    cout << quoto(true) << "hello world" << endl;
#endif
#ifdef Boolean
    cout << true << ' ' << false << endl;
#endif
#ifdef Pair
    cout << std::pair<Int, Int>({Int(1),Int(2)}) << endl;
#endif
#ifdef SerialContainer
    cout << std::vector<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)}) << endl;
    cout << std::set<Int>({Int(1),Int(2),Int(3),Int(4),Int(5),Int(6)}) << endl;
    cout << std::deque<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)}) << endl;
#endif
#ifdef QueueLikeContainer
    auto Q = std::queue<Int>();
    for (auto &s : std::vector<Int>({Int(3),Int(3),Int(4),Int(4),Int(5),Int(7)})) {
        Q.push(s);
    }
    cout << Q <<endl;
#endif
#ifdef CombiningContainer
    using mp_t = std::map<std::string, Int>;
    auto Mp = mp_t({
        mp_t::value_type({"1", Int(2)}),
        mp_t::value_type({"3", Int(4)}),
    });
    cout << Mp << endl;
#endif
    cout << flush << quoto(false);
}



#include <print.h>
#include <string-algorithm.h>
#include <vector>
#include <string>

using namespace minimum;

int main() {
    std::vector<std::basic_string<char>> res;
    cout << quoto(true) << split("1 2", ' ', res) << endl;
    cout << quoto(true) << split("1 2 ", ' ', res);
    cout << quoto(true) << split("1234 2 ", ' ', res);
}
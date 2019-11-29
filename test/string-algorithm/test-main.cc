

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <_int.h>

#include <print.h>
#include <string-algorithm.h>
#include <vector>
#include <string>
#include <functional.h>

using namespace minimum;
using sv = std::vector<std::string>;
struct RR {
    const char* Res;
    sv Ret;
};

class CheckSplitTest : public::testing::TestWithParam<RR>
{
};

TEST_P(CheckSplitTest, NoException) /* NOLINT */
{
    std::vector<std::basic_string<char>> res;
    auto &param = GetParam();
    ASSERT_THAT(split(param.Res, ' ', res), testing::ContainerEq(param.Ret));
}


INSTANTIATE_TEST_SUITE_P(TrueReturn, CheckSplitTest, testing::Values( /* NOLINT */
        (RR){"1 2 ", sv({"1", "2"})},
        (RR){"111  222", sv({"111", "222"})},
        (RR){"111  222    ", sv({"111", "222"})},
        (RR){"  111  222    ", sv({"111", "222"})},
        (RR){"11 1  222", sv({"11","1", "222"})},
        (RR){" 11 1  222 ", sv({"11","1", "222"})},
        (RR){"", sv()}));


template <typename T>
class CheckSplitTemplateTest : public testing::Test {
public:
};

typedef testing::Types<std::string, const char *
#ifdef IsCXX17
    , std::string_view
#endif
> MyTypes;
TYPED_TEST_CASE(CheckSplitTemplateTest, MyTypes); /* NOLINT */

TYPED_TEST(CheckSplitTemplateTest, NoException) { /* NOLINT */
    std::vector<std::basic_string<char>> res;
//    static_assert(std::is_same_v<CheckSplitTemplateTest<TypeParam>, int>, "QAQ");
    ASSERT_THAT(split(TypeParam("123 456"), ' ', res), testing::ContainerEq(
            sv({"123", "456"})));
}




int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
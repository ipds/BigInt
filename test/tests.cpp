#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <gtest/gtest.h>
#include "../src/BigInt.h"

using namespace std;

struct MathematicalFunctions__Test : testing::Test{
    BigInt x{};
    BigInt y{};
    BigInt z{};
    int operation{};
};
struct data{
    int operation;
    string first_value;
    string second_value;
    string expected_value;
};

struct Tests : MathematicalFunctions__Test, testing::WithParamInterface<data> {
    Tests(){
        operation = GetParam().operation;
        x.Set(GetParam().first_value);
        y.Set(GetParam().second_value);
        z.Set(GetParam().expected_value);
    }
};

TEST_P(Tests, MathematicalFunctions__Test){
    switch(operation){
        case 1:
            x.Add(y);
            break;
        case 2:
            x.Subtract(y);
            break;
        case 3:
            x.Multiply(y);
            break;
    }
    EXPECT_EQ(x.GetString(), z.GetString());
}

INSTANTIATE_TEST_CASE_P(Default, Tests, testing::Values(
        data{1, "678790747883923920920028757859992219", "848392020204342020292929982", "678790748732315941124370778152922201"},
        data{2, "67880878546789678", "567879809876789", "67312998736912889"},
        data{3, "9258683947823747724789274", "727272897654345678908765432567849", "6733589903199553686845072768838020884722681017350232451626"}
));

int main (int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
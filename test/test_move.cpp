#include "../include/move_test.hpp"

void movePositionTest() {
    DummyPlayer p;
    Move m(&p, 3, 5);

    auto pos = m.getPosition();
    EXPECT_EQ(pos.first, 3);
    EXPECT_EQ(pos.second, 5);
}

void movePlayerTest() {
    DummyPlayer p;
    Move m(&p, 0, 0);

    EXPECT_EQ(m.getplayer(), &p);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    testing::RegisterTest("MoveTests", "Position", nullptr, nullptr, __FILE__, __LINE__, []() -> testing::Test* {
        struct T : testing::Test {
            void TestBody() override {
                movePositionTest();
            }
        };
        return new T;
    });

    testing::RegisterTest("MoveTests", "Player", nullptr, nullptr, __FILE__, __LINE__, []() -> testing::Test* {
        struct T : testing::Test {
            void TestBody() override {
                movePlayerTest();
            }
        };
        return new T;
    });

    return RUN_ALL_TESTS();
}

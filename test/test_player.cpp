#include <gtest/gtest.h>
#include "../include/MockPlayer.hpp"

// Test getters
TEST(PlayerTest, GettersWorkCorrectly) {
    MockPlayer player("Abdo", "Human", 3, 1, 5, 'X');

    EXPECT_EQ(player.getName(), "Abdo");
    EXPECT_EQ(player.getType(), "Human");
    EXPECT_EQ(player.getNumWin(), 3);
    EXPECT_EQ(player.getNumLose(), 1);
    EXPECT_EQ(player.getNumPlayed(), 5);
    EXPECT_EQ(player.getSymbol(), 'X');
    EXPECT_EQ(player.getLevel(), 1);
    EXPECT_EQ(player.getConsecutiveWins(), 0);
}

// Test setters
TEST(PlayerTest, SettersUpdateValues) {
    MockPlayer player("X", "AI", 0, 0, 0, 'O');

    player.setName("NewName");
    player.setType("Human");
    player.setSymbol('X');
    player.setLevel(5);

    EXPECT_EQ(player.getName(), "NewName");
    EXPECT_EQ(player.getType(), "Human");
    EXPECT_EQ(player.getSymbol(), 'X');
    EXPECT_EQ(player.getLevel(), 5);
}

// Test invalid symbol
TEST(PlayerTest, ThrowsOnInvalidSymbol) {
    MockPlayer player("Abdo", "Human", 0, 0, 0, 'X');
    EXPECT_THROW(player.setSymbol('Z'), std::invalid_argument);
}

// Test updateStats for win
TEST(PlayerTest, UpdateStatsIncrementsCorrectlyOnWin) {
    MockPlayer player("Abdo", "Human", 0, 0, 0, 'X');

    player.updateStats(true);  // win #1
    EXPECT_EQ(player.getNumWin(), 1);
    EXPECT_EQ(player.getNumPlayed(), 1);
    EXPECT_EQ(player.getConsecutiveWins(), 1);
    EXPECT_EQ(player.getLevel(), 1);

    player.updateStats(true);  // win #2
    player.updateStats(true);  // win #3 → should level up
    EXPECT_EQ(player.getNumWin(), 3);
    EXPECT_EQ(player.getConsecutiveWins(), 0); // reset after 3 wins
    EXPECT_EQ(player.getLevel(), 2);
}

// Test updateStats for loss
TEST(PlayerTest, UpdateStatsResetsConsecutiveWinsOnLoss) {
    MockPlayer player("Abdo", "Human", 2, 0, 2, 'X');

    player.updateStats(true);  // win #1
    EXPECT_EQ(player.getConsecutiveWins(), 1);

    player.updateStats(false);  // loss → reset streak
    EXPECT_EQ(player.getConsecutiveWins(), 0);
    EXPECT_EQ(player.getNumLose(), 1);
    EXPECT_EQ(player.getNumPlayed(), 4);  // 2 + 2 updates
}

// Test resetProgress
TEST(PlayerTest, ResetProgressResetsAllStats) {
    MockPlayer player("Abdo", "Human", 5, 3, 10, 'O');
    player.setLevel(4);
    player.updateStats(true);  // to increase consecutiveWins
    player.resetProgress();

    EXPECT_EQ(player.getNumWin(), 0);
    EXPECT_EQ(player.getNumLose(), 0);
    EXPECT_EQ(player.getNumPlayed(), 0);
    EXPECT_EQ(player.getLevel(), 1);
    EXPECT_EQ(player.getConsecutiveWins(), 0);
}

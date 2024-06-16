#include "gtest/gtest.h"
#include <vector>

#include "gameMachinery.h"
#include "banner.h"

class AdjustStringRowsTest : public ::testing::Test {
protected:
    void SetUp() override {
        window.create(sf::VideoMode(800, 600), "Test Window");
    }

    void TearDown() override {
        window.close();
    }

    sf::RenderWindow window;
};

TEST(DrawMapTest, CorrectOutput) {
    std::vector<std::vector<char>> board = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'}
    };

    // Przekierowanie wyjścia do strumienia
    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

    drawMap(board);

    // Przywrócenie std::cout
    std::cout.rdbuf(old);

    std::string expectedOutput =
        " X | O | X \n"
        "-----------\n"
        " O | X | O \n"
        "-----------\n"
        " X | O | X \n";

    ASSERT_EQ(buffer.str(), expectedOutput);
}

TEST(UserSelectedTeamCorrectlyTest, ValidInput) {
    char input = 'x';
    ASSERT_TRUE(userSelectedTeamCorrectly(&input));
    ASSERT_EQ(input, 'X');

    input = 'o';
    ASSERT_TRUE(userSelectedTeamCorrectly(&input));
    ASSERT_EQ(input, 'O');

    input = 'X';
    ASSERT_TRUE(userSelectedTeamCorrectly(&input));
    ASSERT_EQ(input, 'X');

    input = 'O';
    ASSERT_TRUE(userSelectedTeamCorrectly(&input));
    ASSERT_EQ(input, 'O');
}

TEST(UserSelectedTeamCorrectlyTest, InvalidInput) {
    char input = 'a';
    ASSERT_FALSE(userSelectedTeamCorrectly(&input));
    ASSERT_EQ(input, 'a');
}

TEST(UserSelectedRowOrColumnCorrectlyTest, ValidInput) {
    ASSERT_TRUE(userSelectedRowOrColumnCorrectly('1'));
    ASSERT_TRUE(userSelectedRowOrColumnCorrectly('2'));
    ASSERT_TRUE(userSelectedRowOrColumnCorrectly('3'));
}

TEST(UserSelectedRowOrColumnCorrectlyTest, InvalidInput) {
    ASSERT_FALSE(userSelectedRowOrColumnCorrectly('0'));
    ASSERT_FALSE(userSelectedRowOrColumnCorrectly('4'));
    ASSERT_FALSE(userSelectedRowOrColumnCorrectly('a'));
}

TEST(CheckIfGameFinishedTest, GameDRAW) {
    std::vector<std::vector<char>> board = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'O', 'X', 'O'}
    };
    EXPECT_EQ(MATCH_RESULT_DRAW,checkIfGameFinished(board, 'X'));
    EXPECT_EQ(MATCH_RESULT_DRAW,checkIfGameFinished(board, 'O'));
}

TEST(CheckIfGameFinishedTest, HorizontalWinTest){
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    
    EXPECT_EQ(MATCH_RESULT_WIN,checkIfGameFinished(board, 'X'));
    
}

TEST(CheckIfGameFinishedTest, VerticalWinTest) {
    std::vector<std::vector<char>> board = {
        {'O', '_', '_'},
        {'O', '_', '_'},
        {'O', '_', '_'}
    };
    EXPECT_EQ(MATCH_RESULT_WIN, checkIfGameFinished(board, 'O'));
}

TEST(CheckIfGameFinishedTest, DiagonalWinTest1) {
    std::vector<std::vector<char>> board = {
        {'X', '_', '_'},
        {'_', 'X', '_'},
        {'_', '_', 'X'}
    };
    EXPECT_EQ(MATCH_RESULT_WIN, checkIfGameFinished(board, 'X'));
}

TEST(CheckIfGameFinishedTest, DiagonalWinTest2) {
    std::vector<std::vector<char>> board = {
        {'_', '_', 'O'},
        {'_', 'O', '_'},
        {'O', '_', '_'}
    };
    EXPECT_EQ(MATCH_RESULT_WIN, checkIfGameFinished(board, 'O'));
}

// Test for unknown result (game not finished)
TEST(CheckIfGameFinishedTest, GameNotFinishedTest) {
    std::vector<std::vector<char>> board = {
        {'X', '_', '_'},
        {'_', 'O', '_'},
        {'_', '_', '_'}
    };
    EXPECT_EQ(MATCH_RESULT_UNKNOWN, checkIfGameFinished(board, 'X'));
    EXPECT_EQ(MATCH_RESULT_UNKNOWN, checkIfGameFinished(board, 'O'));
}

TEST(CheckIfGameFinishedTest, IncorrectBoardValuesTest) {
    std::vector<std::vector<char>> board = {
        {'X', 'p', '_'},
        {'_', 'O', 'p'},
        {'_', '_', '_'}
    };
    EXPECT_EQ(MATCH_RESULT_IMPOSSIBLE, checkIfGameFinished(board, 'X'));
    EXPECT_EQ(MATCH_RESULT_IMPOSSIBLE, checkIfGameFinished(board, 'O'));
}

TEST_F(AdjustStringRowsTest, AdjustsStringCorrectly) {
    std::string text = "It is a really, really very long string that needs to be adjusted to the width of the window exactly at that  point .";
    
    adjustStringRowsToCurrentWindowSize(window, text,15);

    // Expected result (for example, splitting the string into multiple lines)
    std::string expected = "It is a really, really very long string that needs to be adjusted to the width of the window exactly at that  poi\n      nt .";

    EXPECT_EQ(text, expected);
}

TEST_F(AdjustStringRowsTest,  LeaveShortString ) {
    std::string text = "It .";
    
    adjustStringRowsToCurrentWindowSize(window, text,15);

    // Expected result (for example, splitting the string into multiple lines)
    std::string expected = "It .";

    EXPECT_EQ(text, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"
#include <vector>

#include "gameMachinery.h"

extern void drawMap(const std::vector<std::vector<char>> &currentBoard);
extern bool userSelectedTeamCorrectly(char *userInput);
extern bool userSelectedRowOrColumnCorrectly(char userInput);
extern bool checkIfGameFinished(const std::vector<std::vector<char>> &currentBoard, char currentPlayer);

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

TEST(CheckIfGameFinishedTest, GameNotFinished) {
    std::vector<std::vector<char>> board = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'O', 'X', 'O'}
    };
    ASSERT_FALSE(checkIfGameFinished(board, 'X'));
    ASSERT_FALSE(checkIfGameFinished(board, 'O'));
}

TEST(CheckIfGameFinishedTest, GameFinished) {
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X'},
        {'O', 'X', 'O'},
        {'O', 'O', 'X'}
    };
    ASSERT_TRUE(checkIfGameFinished(board, 'X'));

    board = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {'X', 'O', 'X'}
    };
    ASSERT_TRUE(checkIfGameFinished(board, 'X'));

    board = {
        {'X', 'O', 'O'},
        {'O', 'X', 'O'},
        {'O', 'O', 'X'}
    };
    ASSERT_TRUE(checkIfGameFinished(board, 'X'));

    board = {
        {'O', 'O', 'X'},
        {'X', 'O', 'X'},
        {'X', 'X', 'O'}
    };
    ASSERT_TRUE(checkIfGameFinished(board, 'O'));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
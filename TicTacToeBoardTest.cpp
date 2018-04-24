/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, outOfBoundsPlace)
{
	TicTacToeBoard test;
	ASSERT_EQ(test.placePiece(-1, BOARDSIZE+1), Invalid);
}

TEST(TicTacToeBoardTest, outOfBoundsGet)
{
	TicTacToeBoard test;
	ASSERT_EQ(test.getPiece(-1, BOARDSIZE+1), Invalid);
}

TEST(TicTacToeBoardTest, pieceAlreadyThere)
{
	TicTacToeBoard test;
	Piece p1 = test.placePiece(0,0);
	Piece p2 = test.placePiece(0,0);
	ASSERT_EQ(p1, p2);
}

TEST(TicTacToeBoardTest, toggles)
{
	TicTacToeBoard test;
	Piece p1 = test.placePiece(0,0);
	Piece p2 = test.placePiece(0,1);
	ASSERT_NE(p1, p2);
}

TEST(TicTacToeBoardTest, boardUpdates)
{
	TicTacToeBoard test;
	Piece p1 = test.getPiece(0,0);
	Piece p2 = test.placePiece(0,0);
	ASSERT_NE(p1, p2);
}
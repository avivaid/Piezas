/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


// ==============TESING DROPPICE FUNTION============================================
TEST(PiezasTest, placePiaceTestFail1)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(-10), Invalid);
}

TEST(PiezasTest, placePiaceTestFail2)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(10), Invalid);
}

TEST(PiezasTest, dropPiaceTestPass)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(1), X);
}


TEST(PiezasTest, dropPiaceInvalid)
{
	Piezas b; 
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(2);
	ASSERT_EQ(b.dropPiece(2), Blank);
}

// ==============TESING getPiaceFuntion FUNTION============================================
TEST(PiezasTest, pieceAtTestInvalid)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(-10), Invalid);
}

TEST(PiezasTest, pieceAtInvalid2)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(10), Invalid);
}

TEST(PiezasTest, pieceAtPass)
{
	Piezas b; 
	b.dropPiece(1)
	ASSERT_EQ(b.pieceAt(0,1), X);
}
 
TEST(PiezasTest, pieceAtInvalid)
{
	Piezas b; 
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(2);
	ASSERT_EQ(b.dropPiece(2), Blank);
}

// ==============TESING reset FUNTION============================================


TEST(PiezasTest, resetTest)
{
	Piezas b; 
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(2);
	ASSERT_EQ(b.pieceAt(0,2), Blank);
}

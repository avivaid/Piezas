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
//1
TEST(PiezasTest, placePiaceTestFail1)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(-10), Invalid);
}
//2
TEST(PiezasTest, placePiaceTestFail2)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(10), Invalid);
}
//3
TEST(PiezasTest, dropPiaceTestPass)
{
	Piezas b; 
	b.reset();
	ASSERT_EQ(b.dropPiece(1), X);
}

//4
TEST(PiezasTest, dropPiaceInvalid)
{
	Piezas b; 
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(2);
	ASSERT_EQ(b.dropPiece(2), Blank);
}
TEST(PiezasTest, dropPieaceTest2Blank)
{
	Piezas b; 
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(3);
	b.dropPiece(3);
	ASSERT_EQ(b.dropPiece(3), Blank);
}

// ==============TESING getPiaceFuntion FUNTION============================================
//1
TEST(PiezasTest, pieceAtTestInvalid)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(-10), Invalid);
}
//2
TEST(PiezasTest, pieceAtInvalid2)
{
	Piezas b; 
	ASSERT_EQ(b.dropPiece(10), Invalid);
}
//3
TEST(PiezasTest, pieceAtPass)
{
	Piezas b; 
	b.dropPiece(1); 
	ASSERT_EQ(b.pieceAt(0,1), X);
}
//4
TEST(PiezasTest, pieceAtBlank)
{
	Piezas b; 
	ASSERT_EQ(b.pieceAt(0,1), Blank);
}

// ==============TESING reset FUNTION============================================

//1
TEST(PiezasTest, resetTest)
{
	Piezas b; 
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(3);
	b.dropPiece(3);
	b.reset();
	ASSERT_EQ(b.pieceAt(0,2), Blank);
}
//2
TEST(PiezasTest, resetTest2)
{
	Piezas b; 
	b.dropPiece(0);  //0
	b.dropPiece(0); //X
	b.dropPiece(0); //o
	b.dropPiece(1); //x
	b.dropPiece(1); //o
	b.dropPiece(1); //x
	b.dropPiece(2); //0
	b.dropPiece(2); //x
	b.dropPiece(2);//o
	b.dropPiece(3); //x
	b.dropPiece(3);//o
	b.dropPiece(3);//x
	b.reset();
	b.dropPiece(3);//x
	ASSERT_EQ(b.pieceAt(0,3), X);
}
// ==============TESING turn switch FUNTION============================================

//1
TEST(PiezasTest, turnSwitchTestPass)
{
	Piezas b; 
	b.dropPiece(2);
	b.dropPiece(2);
	ASSERT_EQ(b.pieceAt(1,2), O);
}
//2
TEST(PiezasTest, turnSwitchTestInvaildPass)
{
	Piezas b; 
	b.dropPiece(-10);
	b.dropPiece(1);
	ASSERT_EQ(b.pieceAt(0 ,1), O);
}
//3
TEST(PiezasTest, resettTurnChange)
{
	Piezas b; 
	b.dropPiece(0); //x
	b.dropPiece(0); //o 
	b.dropPiece(0); //x
	b.dropPiece(1); //o
	b.dropPiece(1); //x
	b.dropPiece(1); //o
	b.dropPiece(2);//x 
	b.dropPiece(2); //o 
	b.dropPiece(2); //x 
	b.dropPiece(3); //o
	b.dropPiece(3);//x 
	b.reset(); 
	b.dropPiece(3); //x
	ASSERT_EQ(b.pieceAt(0,3), O);
}


// ==============TESING game state FUNTION============================================
//1
TEST(PiezasTest, gameStateDraw)
{
	Piezas b; 
	b.dropPiece(0); //x
	b.dropPiece(0);  // o
	b.dropPiece(0); // x
	b.dropPiece(1); //0 
	b.dropPiece(1); // x
	b.dropPiece(1); // o 
	b.dropPiece(2); //x 
	b.dropPiece(2); //o 
	b.dropPiece(2); //x  
	b.dropPiece(3); // o 
	b.dropPiece(3); // x
	b.dropPiece(3); // o  
	ASSERT_EQ(b.gameState(), Blank);
}

//2

TEST(PiezasTest, gameStateInvalid)
{
	Piezas b; 
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(2);
	ASSERT_EQ(b.gameState(), Invalid);
}

TEST(PiezasTest, gameStateWin)
{
	Piezas b; 
	b.dropPiece(0); //x 
	b.dropPiece(1);// o
	b.dropPiece(0); // x
	b.dropPiece(2); //o
	b.dropPiece(0); //x
	b.dropPiece(2); // o
	b.dropPiece(2); //x 
	b.dropPiece(1); // o
	b.dropPiece(3); // x
	b.dropPiece(3); //o 
	b.dropPiece(3); //x 
	b.dropPiece(1);	 //o 
	ASSERT_EQ(b.gameState(), O);
}


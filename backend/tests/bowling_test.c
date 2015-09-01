#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"

TEST_GROUP(BowlingTest);

TEST_GROUP_RUNNER(BowlingTest)
{
	RUN_TEST_CASE(BowlingTest, TestAllZeroes);
	RUN_TEST_CASE(BowlingTest, TestAllOnes);	
	RUN_TEST_CASE(BowlingTest, TestSpare);	
	RUN_TEST_CASE(BowlingTest, TestStrike);
	RUN_TEST_CASE(BowlingTest, TwoStrikesInRow);
	RUN_TEST_CASE(BowlingTest, TenStrikesInRow);
}

TEST_SETUP(BowlingTest)
{
	initialise();
}

TEST_TEAR_DOWN(BowlingTest)
{
}

// Prvi test - promasena sva bacanja
TEST(BowlingTest, TestAllZeroes)
{
	int i;
	for (i = 0; i < MAX_NUM_OF_THROWS; i++)
	knockDown(0);
	TEST_ASSERT_EQUAL(0, score());
}

// Drugi test - srusen jedan cunj u svim bacanjima
TEST(BowlingTest, TestAllOnes)
{
	int i;
	for (i = 0; i < MAX_NUM_OF_THROWS; i++)
	knockDown(1);
	TEST_ASSERT_EQUAL(21, score());
}

// Treci test - spare u drugom bacanju (5+5), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestSpare)
{
	int i;
	knockDown(5);
	knockDown(5);
	for (i = 0; i < MAX_NUM_OF_THROWS - 2; i++)
	knockDown(1);
	TEST_ASSERT_EQUAL(30, score());
}

// Cetvrti test - strike u prvom bacanju (10), ostala bacanja po 1 cunj 
TEST(BowlingTest, TestStrike)
{
	int i;
	knockDown(10);
	for (i = 0; i < MAX_NUM_OF_THROWS - 2; i++)
	knockDown(1);
	TEST_ASSERT_EQUAL(31, score());
}

// Peti test - strike u prvom i drugom bacanju, ostala bacanja po 1 cunj 
TEST(BowlingTest, TwoStrikesInRow)
{
	int i;
	knockDown(10);
	knockDown(10);
	for (i = 0; i < MAX_NUM_OF_THROWS - 4; i++)
	knockDown(1);
	TEST_ASSERT_EQUAL(50, score());
}
// Sesti test -strike u svakom bacanju(svaki put po 10 poena)
TEST(BowlingTest, TenStrikesInRow)
{
	int i;
	for(i = 0; i < MAX_NUM_OF_THROWS; i++)
	{
	 knockDown(10);	
	}
 	TEST_ASSERT_EQUAL(300, score());
}

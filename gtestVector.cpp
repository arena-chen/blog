#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

class TestVector : public ::testing::Test
{
protected:
    vector<int> currVector;

    virtual void SetUp()
    {
        int values [] = { 1, 2, 3 };

        currVector = vector<int> (values, values + 3);
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestVector, init_all_elements_with_value)
{
    vector<int> vec;
    int num = 3;
    int val = 7;

    vec = vector<int> (num, val);

    EXPECT_EQ(vec[0], val);
    EXPECT_EQ(vec[1], val);
    EXPECT_EQ(vec[2], val);
}

TEST_F(TestVector, init_with_array)
{
    int values [] = { 1, 2, 3 };

    vector<int> vec;
    vec = vector<int> (values, values + 3);

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST_F(TestVector, push_back)
{
    currVector.push_back(4);

    EXPECT_EQ(currVector[0], 1);
    EXPECT_EQ(currVector[1], 2);
    EXPECT_EQ(currVector[2], 3);
    EXPECT_EQ(currVector[3], 4);
}

TEST_F(TestVector, insert)
{
    vector<int>::iterator it;

    it = currVector.begin();
    currVector.insert(it, 9);
 
    EXPECT_EQ(currVector[0], 9);
    EXPECT_EQ(currVector[1], 1);
    EXPECT_EQ(currVector[2], 2);
    EXPECT_EQ(currVector[3], 3);
}

TEST_F(TestVector, reverse)
{
    reverse(currVector.begin(), currVector.end());

    EXPECT_EQ(currVector[0], 3);
    EXPECT_EQ(currVector[1], 2);
    EXPECT_EQ(currVector[2], 1);
}

bool compareDecreasing(int value1, int value2)
{
    return (value1 > value2);
}

TEST_F(TestVector, sort)
{
    currVector.push_back(8);
    currVector.push_back(5);

    EXPECT_EQ(currVector[0], 1);
    EXPECT_EQ(currVector[1], 2);
    EXPECT_EQ(currVector[2], 3);
    EXPECT_EQ(currVector[3], 8);
    EXPECT_EQ(currVector[4], 5);

    sort(currVector.begin(), currVector.end());

    EXPECT_EQ(currVector[0], 1);
    EXPECT_EQ(currVector[1], 2);
    EXPECT_EQ(currVector[2], 3);
    EXPECT_EQ(currVector[3], 5);
    EXPECT_EQ(currVector[4], 8);

    sort(currVector.begin(), currVector.end(), compareDecreasing);

    EXPECT_EQ(currVector[0], 8);
    EXPECT_EQ(currVector[1], 5);
    EXPECT_EQ(currVector[2], 3);
    EXPECT_EQ(currVector[3], 2);
    EXPECT_EQ(currVector[4], 1);
}

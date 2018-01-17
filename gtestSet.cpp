#include <gtest/gtest.h>
#include <string>

using namespace std;

class TestSet : public ::testing::Test
{
protected:
    set<int> allValues;

    virtual void SetUp()
    {
        int values [] = { 11, 22, 33, 44 };
        allValues = set<int> (values, values + 4);
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestSet, initialize)
{
    int currValues [] = { 1, 3, 5, 7 };
    set<int> currSet(currValues, currValues + 4);
    set<int>::iterator it;

    it = currSet.begin();
    EXPECT_EQ(*it, 1);

    it++;

    EXPECT_EQ(*it, 3);
}

TEST_F(TestSet, begin)
{
    set<int>::iterator it;

    it = allValues.begin();
    EXPECT_EQ(*it, 11);

    it++;

    EXPECT_EQ(*it, 22);
}

TEST_F(TestSet, find)
{
    EXPECT_EQ(*allValues.find(22), 22);
    EXPECT_EQ(allValues.find(6), allValues.end());
}

TEST_F(TestSet, insert)
{
    EXPECT_EQ(allValues.find(6), allValues.end());

    allValues.insert(6);

    EXPECT_EQ(*allValues.find(6), 6);
}

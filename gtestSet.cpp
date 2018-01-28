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

TEST_F(TestSet, initIntArray)
{
    int currValues [] = { 3, 7, 5, 1 };
    set<int> currSet(currValues, currValues + 4);
    set<int>::iterator it;

    it = currSet.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 3);
}

TEST_F(TestSet, initCharArray)
{
    char currValues [] = { 'k', 'a', 'e', 'c' };
    set<char> currSet(currValues, currValues + 4);
    set<char>::iterator it;

    it = currSet.begin();
    EXPECT_EQ(*it++, 'a');
    EXPECT_EQ(*it++, 'c');
}

TEST_F(TestSet, initStringArray)
{
    string currValues [] = { "Ab", "A", "bd", "ba", "a", "ab" };
    set<string> currSet(currValues, currValues + 6);
    set<string>::iterator it;

    it = currSet.begin();

    EXPECT_EQ(*it++, "A");
    EXPECT_EQ(*it++, "Ab");
    EXPECT_EQ(*it++, "a");
    EXPECT_EQ(*it++, "ab");
    EXPECT_EQ(*it++, "ba");
    EXPECT_EQ(*it++, "bd");
}

struct classcomp {
  bool operator() (const string& lhs, const string& rhs) const
  {return lhs>rhs;}
};


TEST_F(TestSet, initStringArrayComp)
{
    string currValues [] = { "Ab", "A", "bd", "ba", "a", "ab" };
    set<string,classcomp> currSet(currValues, currValues + 6);
    set<string>::iterator it;

    it = currSet.begin();

    EXPECT_EQ(*it++, "bd");
    EXPECT_EQ(*it++, "ba");
    EXPECT_EQ(*it++, "ab");
    EXPECT_EQ(*it++, "a");
    EXPECT_EQ(*it++, "Ab");
    EXPECT_EQ(*it++, "A");
}

TEST_F(TestSet, begin)
{
    set<int>::iterator it;

    it = allValues.begin();
    EXPECT_EQ(*it++, 11);
    EXPECT_EQ(*it++, 22);
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

TEST_F(TestSet, count)
{
    EXPECT_EQ(allValues.count(22), 1);
    EXPECT_EQ(allValues.count(6), 0);
}

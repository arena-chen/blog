#include <gtest/gtest.h>
#include <string>

using namespace std;

class TestMap : public ::testing::Test
{
protected:
    map<int,int> tMap;

    virtual void SetUp()
    {
        tMap[5] = 2;
        tMap[7] = 1;
        tMap[8] = 9;
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestMap, first_second)
{
    map<int,int>::iterator it;

    it = tMap.begin();
    EXPECT_EQ(it->first,  5);
    EXPECT_EQ(it->second, 2);

    it++;
    it++;

    EXPECT_EQ(it->first,  8);
    EXPECT_EQ(it->second, 9);
}

TEST_F(TestMap, find)
{
    EXPECT_EQ(tMap.find(5)->second,  2);
    EXPECT_EQ(tMap.find(6), tMap.end());
}

TEST_F(TestMap, insert)
{
    EXPECT_EQ(tMap.find(6), tMap.end());

    tMap.insert(pair<int,int>(6, 11));

    EXPECT_EQ(tMap.find(6)->second, 11);
}

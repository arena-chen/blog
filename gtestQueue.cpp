#include <gtest/gtest.h>
#include <queue>

using namespace std;

class TestSet : public ::testing::Test
{
protected:
    queue<int> allValues;

    virtual void SetUp()
    {
        allValues.push(11);
        allValues.push(22);
        allValues.push(33);
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestSet, front)
{
    EXPECT_EQ(allValues.front(), 11);
}

TEST_F(TestSet, back)
{
    EXPECT_EQ(allValues.back(), 33);
}

TEST_F(TestSet, pop)
{
    EXPECT_EQ(allValues.front(), 11);
    EXPECT_EQ(allValues.back(), 33);

    allValues.pop();

    EXPECT_EQ(allValues.front(), 22);
    EXPECT_EQ(allValues.back(), 33);
}

TEST_F(TestSet, empty)
{
    EXPECT_EQ(allValues.empty(), 0);

    allValues.pop();
    allValues.pop();
    allValues.pop();

    EXPECT_EQ(allValues.empty(), 1);
}

TEST_F(TestSet, size)
{
    EXPECT_EQ(allValues.size(), 3);

    allValues.pop();
    allValues.pop();
    allValues.pop();

    EXPECT_EQ(allValues.size(), 0);
}

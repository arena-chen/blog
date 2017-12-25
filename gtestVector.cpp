#include <gtest/gtest.h>
#include <vector>

using namespace std;

class TestVector : public ::testing::Test
{
protected:
    vector<int> vec;

    virtual void SetUp()
    {
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestVector, push_back)
{
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST_F(TestVector, insert)
{
    vector<int>::iterator it;

    it = vec.begin();
    vec.insert(it, 9);
 
    EXPECT_EQ(vec[0], 9);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], 2);
    EXPECT_EQ(vec[3], 3);
}

TEST_F(TestVector, reverse)
{
    reverse(vec.begin(), vec.end());

    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 1);
}

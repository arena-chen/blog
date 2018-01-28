#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(TestString, push_back)
{
    string word = "blogger";

    word.push_back('_');
    word.push_back('z');

    EXPECT_EQ(word, "blogger_z");
}

TEST(TestString, pop_back)
{
    string word = "blogger";

    word.pop_back();
    word.pop_back();

    EXPECT_EQ(word, "blogg");
}

TEST(TestString, begin)
{
    string word = "blogger";

    string::iterator it = word.begin();

    EXPECT_EQ(*it, 'b');

    it++;

    EXPECT_EQ(*it, 'l');
}

TEST(TestString, rbegin)
{
    string word = "blogger";

    string::reverse_iterator rit = word.rbegin();

    EXPECT_EQ(*rit, 'r');

    rit++;

    EXPECT_EQ(*rit, 'e');
}

TEST(TestString, erase)
{
    string::iterator it;

    string word = "blogger";

    it = word.begin();

    it++;

    word.erase(it);

    EXPECT_EQ(word, "bogger");

    word.erase(it);

    EXPECT_EQ(word, "bgger");
}

TEST(TestString, reverse)
{
    string word = "blogger";

    reverse(word.begin(), word.end());

    EXPECT_EQ(word, "reggolb");
}

TEST(TestString, to_string)
{
    string word = "blogger";
    int val = 100;

    word += to_string(val);

    EXPECT_EQ(word, "blogger100");
}

TEST(TestString, compare)
{
    string word = "blogger";
    string strA = "blog";

    EXPECT_NE(strA.compare(0, strA.size(), word), 0);

    EXPECT_EQ(strA.compare("blog"), 0);
    EXPECT_EQ(strA == "blog", 1);
}

TEST(TestString, substr)
{
    string word = "blogger";
    int len = 4;

    string strA = word.substr(0, len);
    EXPECT_EQ(strA, "blog");
}

TEST(TestString, relation)
{
    string word0 = "aa";
    string word1 = "aaa";
    string word2 = "aab";
    EXPECT_EQ((word0 >= "aa"), true);
    EXPECT_EQ((word0 == "aa"), true);
    EXPECT_EQ((word0 < word1), true);
    EXPECT_EQ((word1 > word0), true);
    EXPECT_EQ((word1 < word2), true);
}

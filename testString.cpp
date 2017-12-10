#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    string word = "blogger";
    cout << "word = " << word << endl; // word = blogger

    word.push_back('_');
    word.push_back('z');
    cout << "word = " << word << endl; // word = blogger_z

    word.pop_back();
    cout << "word = " << word << endl; // word = blogger_

    word.pop_back();
    cout << "word = " << word << endl; // word = blogger

    string::reverse_iterator rit = word.rbegin();
    cout << "*rit = " << *rit << endl; // *rit = r
    rit++;
    cout << "*rit = " << *rit << endl; // *rit = e

    string::iterator it = word.begin();
    word.erase(it);
    cout << "word = " << word << endl; // word = logger

    reverse(word.begin(), word.end());
    cout << "word = " << word << endl; // word = reggol


    int val = 100;
    word += to_string(val);

    cout << "word = " << word << endl; // word = reggol100

    string strA = "regg";
    cout << "strA = " << strA << endl; // strA = regg

    if (strA.compare(0, strA.size(), word) != 0)
        cout << "strA is different from word" << endl;

    string strB = word.substr(0, strA.size());
    cout << "strB = " << strB << endl; // strB = regg

    if (strA.compare(strB) == 0)
        cout << "strA is the same as strB" << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    string word = "blogger";
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

    return 0;
}

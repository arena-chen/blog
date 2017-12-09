#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVec(vector<int> &vec);

int main(int argc, char **argv)
{
    vector<int> vec;
    vector<int>::iterator it;
    int idx;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    printVec(vec);
    // vec = 1, 2, 3

    it = vec.begin();
    vec.insert(it, 9);
   
    printVec(vec);
    // vec = 9, 1, 2, 3

    reverse(vec.begin(), vec.end());

    printVec(vec);
    // vec = 3, 2, 1, 9

    return 0;
}

void printVec(vector<int> &vec)
{
    int idx;

    cout << "vec = ";
    for (idx = 0; idx < vec.size(); idx++)
    {
        cout << vec[idx];
        if (idx != vec.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

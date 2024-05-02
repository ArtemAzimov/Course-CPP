#include <iostream>
#include <set>

using namespace std;

int main()
{
    //declaring a set
    set<int> mySet;

    //inserting elements into the set
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(3);  //inserting a duplicate element

    //printing the elements of the set
    for(const auto& elem : mySet)
    {
        cout << elem << \" ";
    }
    cout << endl;

    //declaring a multiset
    multiset<int> myMultiSet;

    //inserting elements into the multiset
    myMultiSet.insert(3);
    myMultiSet.insert(1);
    myMultiSet.insert(4);
    myMultiSet.insert(3);  //inserting a duplicate element

    //printing the elements of the multiset
    for(const auto& elem : myMultiSet)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

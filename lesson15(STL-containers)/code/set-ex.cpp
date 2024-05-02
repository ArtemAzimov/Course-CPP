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

    //iterating through the set using iterators
    set<int>::iterator it;
    for(it=mySet.begin(); it!=mySet.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //checking if an element exists in the set
    if(mySet.count(2))
    {
        cout << "Element with value 2 exists" << endl;
    }
    else
    {
        cout << "Element with value 2 does not exist" << endl;
    }

    //erasing an element from the set
    mySet.erase(3);

    //printing the elements of the set using a range-based for loop
    for(const auto& elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    //size of the set
    cout << "Size of the set: " << mySet.size() << endl;

    return 0;
}

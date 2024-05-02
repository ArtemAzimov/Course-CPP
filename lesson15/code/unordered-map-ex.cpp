#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    // declaring an unordered_map
    unordered_map<string, int> myMap;

    // inserting key-value pairs into the unordered_map
    myMap["John"] = 25;
    myMap["Jane"] = 30;
    myMap["Bob"] = 18;
    myMap["Alice"] = 22;
    myMap["John"] = 27; // updating the value for the "John" key

    // printing the values associated with keys using a range-based for loop
    for(const auto& kvp : myMap)
    {
        cout << kvp.first << ": " << kvp.second << endl;
    }

    // declaring an unordered_set
    unordered_set<int> mySet;

    // inserting elements into the unordered_set
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(3); // inserting a duplicate element

    // printing the elements of the unordered_set using a range-based for loop
    for(const auto& elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

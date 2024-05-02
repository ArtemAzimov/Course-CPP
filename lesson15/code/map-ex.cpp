#include <iostream>
#include <map>

using namespace std;

int main()
{
    //declaring a map
    map<int, string> myMap;

    //inserting elements into the map
    myMap.insert(pair<int,string>(1,"Hello"));
    myMap.insert(pair<int,string>(2,"World"));
    myMap.insert(pair<int,string>(3,"C++"));

    //accessing elements using the subscript operator[]
    cout << "Element at key 2: " << myMap[2] << endl;

    //iterating through the map using iterators
    map<int, string>::iterator it;
    for(it=myMap.begin(); it!=myMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }

    //erasing an element from the map
    myMap.erase(2);

    //checking if an element exists in the map
    if(myMap.count(2))
    {
        cout << "Element with key 2 exists" << endl;
    }
    else
    {
        cout << "Element with key 2 does not exist" << endl;
    }

    return 0;
}

#include <iostream>
#include <queue>
 
using namespace std;
 
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
 
    while (!q.empty())
    {
        cout << q.front() << \" "; // выводит 10 20 30
        q.pop();
    }
 
    return 0;
}

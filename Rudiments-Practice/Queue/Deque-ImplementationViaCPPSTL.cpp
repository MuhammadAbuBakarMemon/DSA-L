#include <iostream>
#include <deque>
using namespace std;

// Basically Deque is a double ended queue 
/*
It allows functions of enqueue, dequeue, and peek 
from both front and rear each  
*/

int main(void)
{

    deque<int> d;

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    d.push_front(4);

    // cout << d.pop_front() << " " << d.pop_back();
    // this is incorrect because of the fact that pop_front() and pop_back() are both functions with a return type of void, so on line 22 the compiler throws 
    // errors
    // so we use this instead,   

    int f = d.front();
    d.pop_front();
    cout << "Popped front: " << f << endl;

    int r = d.back();
    d.pop_back();
    cout << "Popped back: " << r << endl;
    
    return 0;
}
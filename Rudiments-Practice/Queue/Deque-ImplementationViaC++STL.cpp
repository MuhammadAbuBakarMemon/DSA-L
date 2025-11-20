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

    cout << d.pop_front() << " " << d.pop_back()
    
    return 0;
}
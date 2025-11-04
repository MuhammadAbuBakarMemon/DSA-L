#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    
    int ray[] = {6, 8, 0, 1, 3};
    // int size = sizeof(ray)/sizeof(ray[0]);

    // stack <int> st;
    // int *ng = new int [size];

    // for (int m = size - 1; m >= 0; m--)
    // {

    //     // popping out / removing invalid elements from stack 
    //     while (st.size() > 0 && ray[m] > st.top())
    //     {
    //         st.pop();
    //     }

    //     // if (st.empty())
    //     if (st.size() == 0)
    //     {
    //         ng[m] = -1;
    //     }
    //     else 
    //     {
    //         ng[m] = st.top();
    //     }

    //     st.push(ray[m]);
    // }

    // double practicing I guess 
    
    size_t size = sizeof(ray)/sizeof(ray[0]);

    stack <int> st;
    int* ng = new int [size];

    for (int m = size - 1; m >= 0; m--)
    {

        while(st.size() > 0 && ray[m] > st.top())
        {
            st.pop();
        }

        if (st.size() == 0)
        {
            ng[m] = -1;
        }
        else 
        {
            ng[m] = st.top(); 
        }

        st.push(ray[m]);

    }

    for (int m = 0; m < size; m++)
    {
        cout << ng[m] << " ";
    }
    cout << endl;

    delete[] ng;

    return 0;
}
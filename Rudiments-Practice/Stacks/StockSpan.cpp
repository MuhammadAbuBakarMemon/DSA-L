#include <iostream>
#include <stack>
using namespace std;

/*

TIME COMPLEXITY = n + n = O(n)
SPACE COMPLEXITY = O(n)

*/

int main(void)
{

    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int iterator = sizeof(price) / sizeof(price[0]);

    int ans[iterator] = {0};
    stack <int> st;

    for (int m = 0; m < iterator; m++)
    {
        
        while (st.size() > 0 && price[st.top()] <= price[m])
        {
            st.pop();
        }

        // if (st.empty())
        if (st.size() == 0)
        {
            // claculating span of the stock
            ans[m] = m + 1;
        }
        else 
        {
            ans[m] = m - st.top();
        }
        
        st.push(m);
 
    }

    for (int x = 0; x < iterator; x++)
    {
        cout << ans[x] << " ";
    }
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

// this version of the answer has a greater time complexity consumption 

void nextGreaterElement(int *nums1, int size1, int *nums2, int size2)
{

    // finding out the next greater element for all elements present in nums2

    stack <int> st; 
    int* ng2 = new int [size2];

    for (int m = size2 - 1; m >= 0; m--)
    {

        while (st.size() > 0 && st.top() < nums2[m])
        {
            st.pop();
        }

        if (st.size() == 0)
        {
            ng2[m] = -1;
        }
        else 
        {
            ng2[m] = st.top();
        }

        st.push(nums2[m]);

    }

    // for (int i = 0; i < size2; i++)
    // {
    //     cout << ng2[i] << " ";
    // }
    // cout << endl;

    int* resng = new int [size1];
    int idx;

    for (int m = 0; m < size1; m++)
    {

        for (int n = 0; n < size2; n++)
        {
            if (nums1[m] == nums2[n])
            {
                idx = n;
            }
        }

        resng[m] = ng2[idx];

    }

    for (int i = 0; i < size1; i++)
    {
        cout << resng[i] << " ";
    }
    cout << endl;

    // return resng;
    
}

int main(void)
{

    int nums1[] = {4, 1, 2};

    int nums2[] = {1, 3, 4, 2};

    nextGreaterElement(nums1, 3, nums2, 4);
    
    return 0;
}
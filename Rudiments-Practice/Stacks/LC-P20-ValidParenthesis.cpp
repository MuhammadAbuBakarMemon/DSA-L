#include <iostream>
using namespace std;

// TIME COMPLEXITY = O(n)
/* Becasue we iterate our string once */
// SPACE COMPLEXITY = O(n)
/*Because in the worst case all the characters in the string are opening characters and we push all of them into the stack*/


bool isValid(const string& str)
{
    stack <char> st;

    for (int m = 0; m < str.size(); m++)
    {
        if (str[m] == '[' || '{' || '(')
        {
            st.push(str[m]);
        }
        
        else 
        {
            // case that handles when closing characters are greater than the opening characters

            if (st.size() == 0)
            {
                return false;
            }

            if (str[m] == ']' && st.top() == ']'|| str[m] == '}' && st.top() == '}' || str[m] == ')' && st.top() == ')')
            {
                st.pop();
            }
            else 
            {
                return false;
            }
        }
    }

    // this checks for the case when the number of opening characters are greater than the closing characters in
    // our string as if that is the case then the for loop would  have eneded and our stack would be non-empgty 
    // and in that case we do not need our function to return true
    return (st.size() == 0);
}

int main(void)
{
    
    return 0;
}
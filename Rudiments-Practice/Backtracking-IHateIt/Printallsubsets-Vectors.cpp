#include <iostream>
#include <vector>
using namespace std;

void pSubRay(vector<int>& ray, vector<int>& ans, int x)
{

    if (x == ray.size())
    {
        for (int m : ans)
        {
            cout  << m << " ";
        }

        cout << endl;
        return;
    }

    //Inclusion
    ans.push_back(ray[x]);
    pSubRay(ray, ans, x + 1);

    //Exculsion 
    ans.pop_back();
    pSubRay(ray, ans, x + 1);

}

int main(void)
{
    
    vector<int> ray = {1, 2, 3};
    vector<int> ans;

    pSubRay(ray, ans, 0);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int sp;
    int ep;

    Interval(int m, int n)
    {
        sp = m;
        ep = n;
    }
};

struct Metadata
{
    int dur;
    int ogidx;
};

vector<int> prodSortedIntervals(vector<Interval> in)
{
    vector<int> SortedIntervals;
    vector<Metadata> list;

    for (int i = 0; i < in.size(); i++)
    {
        int dur = in[i].ep - in[i].sp;
        list.push_back(dur, i);
    }

    int n = list.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(list[j].dur < list[j + 1].dur)
            {
                Metadata temp = list[j];
                list[j] = list[j+1];
                list[j+ 1] = temp;
            }
        }
    }

    for (int m = 0; m < n; m++)
    {
        SortedIntervals.push_back(list[m].ogidx);
    }

    return SortedIntervals;
}

vector<int> conflict(vector<Interval> in, vector<int> si)
{

    int siz = in.size();
    vector<int> NoOfConflictInSortedIntervals(siz, 0);

    for (int m = 0; m < siz - 1; m++)
    {
        for (int n = m + 1; n < siz; n++)
        {
            int stMax = (in[m].sp > in[n].sp) ? in[m].sp : in[n].sp;
            int endMin = (in[m].ep < in[n].ep) ? in[m].ep : in[n].ep;

            if (stMax < endMin)
            {
                NoOfConflictInSortedIntervals[m++];
                NoOfConflictInSortedIntervals[n++];
            }
        }
    }

    vector<int> result;
    for (int m = 0; m < n; m++)
    {
        result[m].push_back(NoOfConflictInSortedIntervals[si[m]]); 
    }

    return result;
}

int main(void)
{
    vector<Interval> IntervalArray = {(2,4), (5,9), (10,12), (3,9), (7,11)};

    return 0;
}
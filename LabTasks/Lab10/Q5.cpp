// Given an array arr[] and a positive integer k, Find the top k elements which have
// the highest frequency in the array. If more than one element has same frequency then
// priorities the larger element over the smaller one.

#include <iostream>
#include <algorithm>
using namespace std;

struct Node 
{
    int value;
    int frequency; 
};

void merge(int ray[], int st, int end, int mid)
{

    int i = st;
    int j = mid + 1;

    int* temp = new int [end - st + 1];
    int it = 0;

    while (i <= mid && j <= end)
    {
        if (ray[i] > ray[j])
        {
            temp[it++] = ray[i++];
        }
        else 
        {
            temp[it++] = ray[j++];
        }
    }

    while (i <= mid)
    {
        temp[it++] = ray[i++];
    }

    while (j <= end)
    {
        temp[it++] = ray[j++];
    }

    for (int m = 0; m < it; m++)
    {
        ray[st + m] = temp[m];
    }

}

void mergesort(int ray[], int st, int end)
{

    if (st < end)
    {

        int mid = st + (end - st) / 2;

        mergesort(ray, st, mid);
        mergesort(ray, mid + 1, end);

        merge(ray, st, end, mid);

    }
}

// the heapify function that ensures that we build our maxheap with O(n) Time complexity 
// i is the index os the array for which we wan the heap function to run and satisfy the heap structure in our array

void heapifysink(Node heap[], int size, int c)
{

    // largest always stors the index of ou array
    int lar = c;
    int left = 2 * c + 1;
    int right = 2 * c + 2;

    // first possibility that the frequency of the left child is greater in the frequncy at the largest index in the array of Nodes
    if (left < size)
    {
        if (heap[left].frequency > heap[lar].frequency)
        {
            lar = left;
        }
        // else if the fequencies are equal we need to check for the possibility for which index has the higher value 
        else if (heap[left].frequency == heap[lar].frequency)
        {
            if (heap[left].value > heap[lar].value)
            {
                lar = left;
            }
            
        }
    }

    if (right < size)
    {
        if (heap[right].frequency > heap[lar].frequency)
        {
            lar = right;
        }
        else if (heap[right].frequency == heap[lar].frequency)
        {
            if (heap[right].value > heap[lar].value)
            {
                lar = right;
            }
        }
        
    }

    if (lar != c)
    {
        swap(heap[lar], heap[c]);
        heapifysink(heap, size, lar);
    }

}

Node extractMax(Node heap[], int size)
{

    Node root = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifysink(heap, size, 0);

    return root;

}

void prioritySolve(int ray[], int k, int size)
{

    mergesort(ray, 0, size - 1);

    Node* distinctNode = new Node [size];
    int distinctCount = 0;

    int currval = ray[0];
    int freq = 1;
    
    for (int m = 1; m < size; m++)
    {
        if (ray[m] == currval)
        {
            freq++;
        }
        else 
        {
            distinctNode[distinctCount].value = currval;
            distinctNode[distinctCount].frequency = freq;

            distinctCount++;
            currval = ray[m];
            freq = 1;
        }
    }

    // for the last group/element obtained.....
    //  we addit manually as it was not taken into account/catered for in the above loop
    distinctNode[distinctCount].value = currval;
    distinctNode[distinctCount].frequency = freq;
    distinctCount++;


    // noe we use our array to start and build our max heap, as per our requirements

    for (int m = (distinctCount - 1) / 2; m >= 0; m--)
    {
        heapifysink(distinctNode, distinctCount, m);
    }

    // now we will extract the top k elements as specified to us iun the question 
    
    cout << "Top " << k << " elements: ";

    // for (int m = 0; m < k && k < size; m++)
    // here we have to choose the condition we have to think analytically here, the above commented out condition's 2nd part is incorrect
    // because this will just check if the number of nodes we are asking to extract were lesser than the total number of nodes present in the start 
    // and this will remian true for all the rest of the times  

    // but if we think through this and see that wheneer we extract an element out we reduce the size by 1 
    // another candidate for the second condition could be that we try for this k > distinctcount
    //  but this also fails as when we reduce the nummber of elements in heap we have also obtained 1 max element from our heap, so now technically we only  
    // need to extract out k - 1 elements now 

// the correct logic would be that the loop fails when the elements we want to extract from our heap are all extracted or we runout of elements from our 
// heap  

    for (int m = 0; m < k && distinctCount > 0; m++)
    {
        Node Top = extractMax(distinctNode, distinctCount);
        cout << "Node: " << Top.value << " ";
        
    }

    delete[] distinctNode;
    
}

int main(void)
{
    
    int mab[] = {1, 1, 2, 2, 3, 3, 4};
    int n = sizeof(mab)/sizeof(mab[0]);

    int k = 2;

    prioritySolve(mab, k, n);

    return 0;
}
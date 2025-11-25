#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// could've also done this inside the class but I wanted to go with the global array approach 

int heap[100];
int heaps = 0;

// below are 2 utility max heap functions used in their respective scenarios 

// helper function used to sink values down or fix the heap downwards, when the updated value becomes smaller
void heapifysink(int i)
{
    int lar = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heaps && heap[left] > heap[lar])
    {
        lar = left;
    }

    if (right < heaps && heap[right] > heap[lar])
    {
        lar = right;
    }

    if (lar != i)
    {
        swap(heap[lar], heap[i]);
        heapifysink(lar);
    }
}

// helper function used to fix the heap upwards, by swimmming upwards, used when the updated value becomes larger 

void heapifysiftup(int m)
{
    //  logic is we keep on repeating until that particular element is not the root because fromn there we can not swim upwards
    //   and until when element at the updated index is greater than it's parent since this is a max heap..... 
    while (m > 0 && heap[(m - 1) / 2] < heap[m])
    {
        swap(heap[(m - 1) / 2], heap[m]);
        m = (m - 1) / 2;
    }
}

void update_key(int i, int new_val)
{

    if (i >= heaps)
    {
        cout << "Index requested for update is out of bounds..." << endl;
        return;
    }

    int old_val = heap[i];

    heap[i] = new_val;
    
    if (old_val > new_val)
    {
        heapifysink(i);
    }
    else 
    {
        heapifysiftup(i);
    }
     
}

// why can we not just delete an element from the top?
// Because the top most element from our heap is not what we desire to delete;

void deleteelement(int element)
{

    cout << "STEP A: Update Index: " << element << " to: " << INT_MAX << endl;

    update_key(element, INT_MAX);

    cout << "STEP B: Since we previously sifted up our value to the root in the update_key function, so now we delete the root as it has the element that we initially desired to delete: " << endl;

    heap[0] = heap[heaps - 1];
    heaps--;

    // ensure that the heap property is maintained....
    heapifysink(0);

}

void printHeap()
{
    for (int m = 0; m < heaps; m++)
    {
        cout << heap[m] << " "; 
    }
    cout << endl;
}

int main(void)
{
    int ray[] = {8, 7, 6, 5, 4};
    heaps = 5;
    for (int m = 0; m < heaps; m++)
    {
        heap[m] = ray[m];
    }

    cout << "Original Heap: " << endl;
    printHeap();


    cout << "Updating index value 3 (value 5) to value 9////" << endl;
    update_key(3, 9);

    cout << "Updating index value 5 (value out of bounds) to value 30////" << endl;
    update_key(5, 30);

    cout << "Updating index value 4 (value 4) to value 30////" << endl;
    update_key(4, 30);

    cout << "Heap after updating: " << endl;
    printHeap();

    cout << "Now we will try and remove some key from their desired index position(s) not the top: " << endl;
    cout << "Deleting index 1 (value 9) from the heap...." << endl;
    deleteelement(1);

    cout << "Final Heap: " << endl;
    printHeap();


    return 0;
}
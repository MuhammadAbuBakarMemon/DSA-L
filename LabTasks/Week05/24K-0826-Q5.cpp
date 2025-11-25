#include <iostream>
using namespace std;

void findCombinations(int candidates[], int n, int target, int current[], int currentSize, int start) {
    if (target == 0) {
        for (int i = 0; i < currentSize; i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }
    
    if (target < 0) {
        return;
    }
    
    for (int i = start; i < n; i++) {
        current[currentSize] = candidates[i];
        findCombinations(candidates, n, target - candidates[i], current, currentSize + 1, i);
    }
}

void combinationSum(int candidates[], int n, int target) {
    int* current = new int[target];
    findCombinations(candidates, n, target, current, 0, 0);
    delete[] current;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int n = sizeof(candidates) / sizeof(candidates[0]);
    int target = 7;
    
    combinationSum(candidates, n, target);
    
    return 0;
}
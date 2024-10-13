#include <iostream>
using namespace std;

// Function to perform shell sort
void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

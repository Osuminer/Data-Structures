#include "sort.h"
#include <iostream>
#include <chrono>

typedef chrono::high_resolution_clock Clock;

using namespace std;

int main() {
    srand(1);   // Seed array to 1

    const int ARRAYSIZE = 5000;   // Size of array
    int arr[ARRAYSIZE];         // Array to sort

    // Fill array with random numbers from 0 to RANDMAX
    for (int i = 0; i < ARRAYSIZE; i++) {
        arr[i] = rand();
    }

    auto t1 = Clock::now();
    bubbleSort(arr, ARRAYSIZE);
    // insertionSort(arr, ARRAYSIZE);
    // mergeSort(arr, 0, ARRAYSIZE-1);
    // quickSort(arr, 0, ARRAYSIZE-1);
    // radixSort(arr, ARRAYSIZE);
    auto t2 = Clock::now();

    cout << "\nTime taken: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << "ns\n" << endl;

    return 0;
}
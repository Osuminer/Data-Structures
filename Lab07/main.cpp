#include "PriorityQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

typedef chrono::high_resolution_clock Clock;

using namespace std;

int main(){

    srand(1);   // Seed array to 1

    const int ARRAYSIZE = 500;
    //const int ARRAYSIZE = 1000; 
    //const int ARRAYSIZE = 2000; 
    //const int ARRAYSIZE = 5000; 
    
      // Size of array
    int arr[ARRAYSIZE];         // Array to sort

    // Fill array with random numbers from 0 to RANDMAX
    for (int i = 0; i < ARRAYSIZE; i++) {
        arr[i] = rand();
    }

    auto t1 = Clock::now();

    ArrayBasedPriorityQueue alpha;
    //HeapBasedPriorityQueue alpha;

    for (int i = 0; i < ARRAYSIZE; i++) {
        alpha.Insert(arr[i]);
        //alpha.Dequeue(arr[i]);
    }
    
    auto t2 = Clock::now();

    cout << "\nTime taken: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << "ns\n" << endl;

    return 0;

}
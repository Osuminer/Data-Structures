#include "PriorityQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main(){

    srand(1);   // Seed array to 1

    // const int ARRAYSIZE = 500;
    // const int ARRAYSIZE = 1000; 
    // const int ARRAYSIZE = 2000; 
    const int ARRAYSIZE = 5000; 
    
    // Size of array

    int arr[ARRAYSIZE];         // Array to sort

    // Fill array with random numbers from 0 to RANDMAX
    for (int i = 0; i < ARRAYSIZE; i++) {
        arr[i] = rand();
    }

    ArrayBasedPriorityQueue alpha;
    HeapBasedPriorityQueue beta;


    // array insert ------------------------------------------------------------

    auto arrayBeforeInsert = Clock::now(); 

    for (int i = 0; i < ARRAYSIZE; i++) {
        alpha.Insert(arr[i]);
    }
    
    auto arrayAfterInsert = Clock::now(); 

    // array dequeue ----------------------------------------------------------

    auto arrayBeforeDequeue = Clock::now();
    
    for (int i = 0; i < ARRAYSIZE; i++) {
        alpha.DeQueue();
    }

    auto arrayAfterDequeue = Clock::now(); 

    // heap insert ------------------------------------------------------------

    auto heapBeforeInsert = Clock::now(); 

    for (int i = 0; i < ARRAYSIZE; i++) {
        beta.Insert(arr[i]);
    }

    auto heapAfterInsert = Clock::now(); 

    // heap dequeue -----------------------------------------------------------

    auto heapBeforeDequeue = Clock::now(); 
    
    for (int i = 0; i < ARRAYSIZE; i++) {
        beta.DeQueue();
    }

    auto heapAfterDequeue = Clock::now(); 

    cout << "\nTime taken array insert: " << chrono::duration_cast<chrono::nanoseconds>(arrayAfterInsert - arrayBeforeInsert).count() << "ns\n" << endl;
    cout << "\nTime taken array dequeue: " << chrono::duration_cast<chrono::nanoseconds>(arrayAfterDequeue - arrayBeforeDequeue).count() << "ns\n" << endl;
    cout << "\nTime taken heap insert: " << chrono::duration_cast<chrono::nanoseconds>(heapAfterInsert - heapBeforeInsert).count() << "ns\n" << endl;
    cout << "\nTime taken heap dequeue: " << chrono::duration_cast<chrono::nanoseconds>(heapAfterDequeue - heapBeforeDequeue).count() << "ns\n" << endl;

    return 0;

}
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

    ArrayBasedPriorityQueue alpha;
    HeapBasedPriorityQueue beta;

    auto t1 = Clock::now(); //-------------------------------------------------

    for (int i = 0; i < ARRAYSIZE; i++) {
        alpha.Insert(arr[i]);
    }
    
    auto t2 = Clock::now(); //-------------------------------------------------

    // array dequeue

    auto t3 = Clock::now(); //-------------------------------------------------
    
    for (int i = 0; i < ARRAYSIZE; i++) {
        alpha.DeQueue();
    }

    auto t4 = Clock::now(); //-------------------------------------------------


    // heap insert

    auto t5 = Clock::now(); //-------------------------------------------------
    
    for (int i = 0; i < ARRAYSIZE; i++) {
        beta.Insert(arr[i]);
    }

    auto t6 = Clock::now(); //-------------------------------------------------

    // heap dequeue

    auto t7 = Clock::now(); //-------------------------------------------------
    
    for (int i = 0; i < ARRAYSIZE; i++) {
        beta.DeQueue();
    }

    auto t8 = Clock::now(); //-------------------------------------------------


    cout << "\nTime taken array insert: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << "ns\n" << endl;
    cout << "\nTime taken array dequeue: " << chrono::duration_cast<chrono::nanoseconds>(t4 - t3).count() << "ns\n" << endl;
    cout << "\nTime taken heap insert: " << chrono::duration_cast<chrono::nanoseconds>(t6 - t5).count() << "ns\n" << endl;
    cout << "\nTime taken heap dequeue: " << chrono::duration_cast<chrono::nanoseconds>(t8 - t7).count() << "ns\n" << endl;

    return 0;

}
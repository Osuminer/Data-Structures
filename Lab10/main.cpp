#include <iostream>
#include <vector>
#include <chrono>
#include "HashTable.h"
#include "Node.h"

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main(){

    srand(1);   // Seed array to 1

    HashTable<int, Node<int>> h1(500);
    HashTable<int, Node<int>> h2(1000);
    HashTable<int, Node<int>> h3(2000);
    HashTable<int, Node<int>> h4(5000);

    // Fill 500 item has table
    for (int i = 0; i < 500; i++) {
        Node<int> a(rand(), 2);

        h1.AddItem(a);
    }

    // Fill 1000 item has table
    for (int i = 0; i < 1000; i++) {
        Node<int> a(rand(), 2);

        h2.AddItem(a);
    }

    // Fill 2000 item has table
    for (int i = 0; i < 2000; i++) {
        Node<int> a(rand(), 2);

        h3.AddItem(a);
    }
       
    // Fill 5000 item has table
    for (int i = 0; i < 5000; i++) {
        Node<int> a(rand(), 2);

        h4.AddItem(a);
    }




    // array insert ------------------------------------------------------------

    auto arrayBeforeInsert = Clock::now(); 

    
    auto arrayAfterInsert = Clock::now(); 


    cout << "\nTime taken array insert: " << chrono::duration_cast<chrono::nanoseconds>(arrayAfterInsert - arrayBeforeInsert).count() << "ns\n" << endl;


    return 0;

}
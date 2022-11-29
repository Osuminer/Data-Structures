#include <iostream>
#include <vector>
#include <chrono>
#include "HashTable.h"
#include "Node.h"

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main(){

    srand(1);   // Seed array to 1

    HashTable<int, Node<int>> h(5);

    HashTable<int, Node<int>> h1(500);
    HashTable<int, Node<int>> h2(1000);
    HashTable<int, Node<int>> h3(2000);
    HashTable<int, Node<int>> h4(5000);

    for (int i = 0; i < 5; i++) {
        Node<int> a(rand(), 2);

        h.BadAddItem(a);
    }

    // Fill 500 item has table
    auto pre500 = Clock::now();
    for (int i = 0; i < 500; i++) {
        Node<int> a(rand(), 2);

        h1.BadAddItem(a);
    }
    auto post500 = Clock::now();


    // Fill 1000 item has table
    auto pre1000 = Clock::now();
    for (int i = 0; i < 1000; i++) {
        Node<int> a(rand(), 2);

        h2.BadAddItem(a);
    }
    auto post1000 = Clock::now();


    // Fill 2000 item has table
    auto pre2000 = Clock::now();
    for (int i = 0; i < 2000; i++) {
        Node<int> a(rand(), 2);

        h3.BadAddItem(a);
    }
    auto post2000 = Clock::now();
       
    // Fill 5000 item has table
    auto pre5000 = Clock::now();
    for (int i = 0; i < 5000; i++) {
        Node<int> a(rand(), 2);

        h4.BadAddItem(a);
    }
    auto post5000 = Clock::now();

    cout << "\nTime taken for 500 item insert: " << chrono::duration_cast<chrono::nanoseconds>(post500 - pre500).count() << "ns\n" << endl;
    cout << "\nTime taken for 1000 item insert: " << chrono::duration_cast<chrono::nanoseconds>(post1000 - pre1000).count() << "ns\n" << endl;
    cout << "\nTime taken for 2000 item insert: " << chrono::duration_cast<chrono::nanoseconds>(post2000 - pre2000).count() << "ns\n" << endl;
    cout << "\nTime taken for 5000 item insert: " << chrono::duration_cast<chrono::nanoseconds>(post5000 - pre5000).count() << "ns\n" << endl;


    return 0;

}
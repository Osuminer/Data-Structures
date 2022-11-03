#include <gtest/gtest.h>
#include "PriorityQueue.h"


// Array Based Priority Queue -----------------------------------------------
TEST(ArrayBased, Insert1) {
    ArrayBasedPriorityQueue a;

    a.Insert(1);
    a.Insert(2);

    ASSERT_EQ("2 1 ", a.PrintPriorityQueue());
}
TEST(ArrayBased, Insert2) {
    ArrayBasedPriorityQueue a;

    a.Insert(4);
    a.Insert(3);
    a.Insert(6);
    a.Insert(1);

    ASSERT_EQ("6 4 3 1 ", a.PrintPriorityQueue());
}

TEST(ArrayBased, DeQueue1) {
    ArrayBasedPriorityQueue a;

    a.Insert(1);
    a.Insert(2);
    a.DeQueue();

    ASSERT_EQ("1 ", a.PrintPriorityQueue());
}
TEST(ArrayBased, DeQueue2) {
    ArrayBasedPriorityQueue a;

    a.Insert(4);
    a.Insert(3);
    a.Insert(6);
    a.Insert(1);
    a.DeQueue();
    a.DeQueue();

    ASSERT_EQ("3 1 ", a.PrintPriorityQueue());
}

TEST(ArrayBased, Print1) {
    ArrayBasedPriorityQueue a;

    a.Insert(6);
    a.Insert(9);

    ASSERT_EQ("9 6 ", a.PrintPriorityQueue());
}
TEST(ArrayBased, Print2) {
    ArrayBasedPriorityQueue a;

    a.Insert(12);
    a.Insert(6);
    a.Insert(3);
    a.Insert(30);
    a.DeQueue();
    a.DeQueue();

    ASSERT_EQ("6 3 ", a.PrintPriorityQueue());
}

TEST(ArrayBased, Empty1) {
    ArrayBasedPriorityQueue a;

    ASSERT_TRUE(a.isEmpty());
}
TEST(ArrayBased, Empty2) {
    ArrayBasedPriorityQueue a;

    a.Insert(1);
    a.Insert(2);
    a.DeQueue();
    a.DeQueue();

    ASSERT_TRUE(a.isEmpty());
}

// Heap Based Priority Queue ----------------------------------------------
TEST(HeapBased, Insert1) {
    HeapBasedPriorityQueue a;

    a.Insert(1);
    a.Insert(2);

    ASSERT_EQ("2 1 ", a.PrintPriorityQueue());
}
TEST(HeapBased, Insert2) {
    HeapBasedPriorityQueue a;

    a.Insert(4);
    a.Insert(3);
    a.Insert(6);
    a.Insert(1);

    ASSERT_EQ("6 3 4 1 ", a.PrintPriorityQueue());
}

TEST(HeapBased, DeQueue1) {
    HeapBasedPriorityQueue a;

    a.Insert(1);
    a.Insert(2);
    a.DeQueue();

    ASSERT_EQ("1 ", a.PrintPriorityQueue());
}
TEST(HeapBased, DeQueue2) {
    HeapBasedPriorityQueue a;

    a.Insert(4);
    a.Insert(3);
    a.Insert(6);
    a.Insert(1);
    a.DeQueue();
    a.DeQueue();

    ASSERT_EQ("3 1 ", a.PrintPriorityQueue());
}

TEST(HeapBased, Print1) {
    HeapBasedPriorityQueue a;

    a.Insert(6);
    a.Insert(9);

    ASSERT_EQ("9 6 ", a.PrintPriorityQueue());
}
TEST(HeapBased, Print2) {
    HeapBasedPriorityQueue a;

    a.Insert(12);
    a.Insert(6);
    a.Insert(3);
    a.Insert(30);
    a.DeQueue();
    a.DeQueue();

    ASSERT_EQ("6 3 ", a.PrintPriorityQueue());
}

TEST(HeapBased, Empty1) {
    HeapBasedPriorityQueue a;

    ASSERT_TRUE(a.isEmpty());
}
TEST(HeapBased, Empty2) {
    HeapBasedPriorityQueue a;

    a.Insert(1);
    a.Insert(2);
    a.DeQueue();
    a.DeQueue();

    ASSERT_TRUE(a.isEmpty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
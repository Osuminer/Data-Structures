// tests.cpp

#include "sort.h"
#include <gtest/gtest.h>

TEST(sort, bubbleSort) {
    int arr[10] = {5, 3, 2, 6, 9, 8, 1, 4, 7, 10};
    int n = 10;

    bubbleSort(arr, n);

    ASSERT_EQ(arrayToString(arr, n), "1 2 3 4 5 6 7 8 9 10 ");
}

TEST(sort, insertionSort) {
    int arr[10] = {5, 3, 2, 6, 9, 8, 1, 4, 7, 10};
    int n = 10;

    insertionSort(arr, n);

    ASSERT_EQ(arrayToString(arr, n), "1 2 3 4 5 6 7 8 9 10 ");
}

TEST(sort, mergeSort) {
    int arr[10] = {5, 3, 2, 6, 9, 8, 1, 4, 7, 10};
    int n = 10;

    mergeSort(arr, 0, n-1);

    ASSERT_EQ(arrayToString(arr, n), "1 2 3 4 5 6 7 8 9 10 ");
}

TEST(sort, quickSort) {
    int arr[10] = {5, 3, 2, 6, 9, 8, 1, 4, 7, 10};
    int n = 10;

    quickSort(arr, 0, n-1);

    ASSERT_EQ(arrayToString(arr, n), "1 2 3 4 5 6 7 8 9 10 ");
}

TEST(sort, radixSort) {
    int arr[10] = {5, 3, 2, 6, 9, 8, 1, 4, 7, 10};
    int n = 10;

    radixSort(arr, n);

    ASSERT_EQ(arrayToString(arr, n), "1 2 3 4 5 6 7 8 9 10 ");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#pragma once


template <typename T>
class Node {
    public:
        Node() {
            key = -1;
            data = 0;
        }
        Node(int k, T d) {
            key = k;
            data = d;
        }

        int key;
        T data;
};
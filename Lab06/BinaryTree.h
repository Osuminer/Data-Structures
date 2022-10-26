#pragma once

#include <vector>

template<typename T> class Node {
    public:
        Node() {
            m_left = nullptr;
            m_right = nullptr;
        }

        Node(Node* node) {
            this->m_left = node->GetLeftNode();
            this->m_right = node->GetRightNode();
            this->m_val = node->ReturnValue();
        }

        Node(T val) {
            m_val = val;
        }

        ~Node() {

        }

        T ReturnValue() {
            return m_val;
        }

        void SetValue(T v) {
            m_val = v;
        }

        Node* GetRightNode() {
            return m_right;
        }

        void SetRightNode(Node* n) {
            m_right = n;
        }

        Node* GetLeftNode() {
            return m_left;
        }

        void SetLeftNode(Node* n) {
            m_left = n;
        }

    private:
        T m_val;
        Node* m_right;
        Node* m_left;
};

template<typename T> class BinaryTree {
    public:
        BinaryTree() {
            m_size = 0;
        }

        ~BinaryTree() {

        }

        bool Insert(Node<T>* newNode) {
            if (Insert(newNode, root)) {
                return true;
            }

            return false;
        }

        bool Insert(Node<T>* newNode, Node<T>* tempRootNode) {
            if (m_size == 0) {
                root->SetValue(newNode->ReturnValue());
            }

            if (newNode->ReturnValue() >= tempRootNode->ReturnValue()) {
                if (tempRootNode->GetRightNode() == nullptr) {
                    tempRootNode->SetRightNode(newNode);
                    m_size++;
                    return true;
                } else {
                    Insert(newNode, tempRootNode->GetRightNode());
                }

                return true;
            } else if (newNode->ReturnValue() < tempRootNode->ReturnValue()) {
                if (tempRootNode->GetLeftNode() == nullptr) {
                    tempRootNode->SetLeftNode(newNode);
                    m_size++;
                    return true;
                } else {
                    Insert(newNode, tempRootNode->GetLeftNode());
                }
            }

            return false;
        }

        Node<T> Find(T val) {

        }

        int Size() {
            return m_size;
        }

        std::vector<T> GetAllAscending() {

        }

        void Clear() {

        }

    private:
        Node<T>* root = new Node<T>();
        int m_size;
};
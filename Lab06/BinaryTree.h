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

        // std::shared_ptr<Node>m_right();
};

template<typename T> class BinaryTree {
    public:
        BinaryTree() {
            m_size = 0;
        }

        ~BinaryTree() {

        }

        // Insert -------------------------------------------------------------------------------

        /// @brief Insert with base tree root node
        /// @param newNode Node pointer to insert
        /// @return 
        bool Insert(Node<T>* newNode) {
            if (Insert(newNode, root)) {
                return true;
            }

            return false;
        }

        /// @brief Insert with specified root node, used for recursion
        /// @param newNode Node pointer to insert
        /// @param tempRootNode Root node pointer to start from
        /// @return 
        bool Insert(Node<T>* newNode, Node<T>* tempRootNode) {
            if (m_size == 0) {
                root->SetValue(newNode->ReturnValue());
                m_size++;
                return true;
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

        // Find -------------------------------------------------------------------------------

        /// @brief Find node with given value from base root node
        /// @param val Value to find
        /// @return 
        Node<T> Find(T val) {
            return Find(val, root);
        }

        /// @brief Find Node with given value from specified root node
        /// @param val Value to find
        /// @param tempRoot Root node to start search from
        /// @return 
        Node<T> Find(T val, Node<T>* tempRoot) {
            if (tempRoot->ReturnValue() == val) {
                return tempRoot;
            } else if (val > tempRoot->ReturnValue()) {
                return Find(val, tempRoot->GetRightNode());
            } else if (val < tempRoot->ReturnValue()) {
                return Find(val, tempRoot->GetLeftNode());
            }
        }

        // Size -------------------------------------------------------------------------------

        int Size() {
            return m_size;
        }

        // Get Ascending -------------------------------------------------------------------------------
        std::vector<T> GetAllAscending() {
            std::vector<T> v;
            InOrderSearch(v, root);
            return v;
        }

        void InOrderSearch(std::vector<T> &v, Node<T>* tempRoot) {
            if (tempRoot == nullptr) {
                return;
            }

            if (tempRoot->GetLeftNode() == nullptr) {
                v.push_back(tempRoot->ReturnValue());
                InOrderSearch(v, tempRoot->GetRightNode());
                return;
            } 

            InOrderSearch(v, tempRoot->GetLeftNode());
            v.push_back(tempRoot->ReturnValue());
            InOrderSearch(v, tempRoot->GetRightNode());
            return;

        }

        // Clear -------------------------------------------------------------------------------

        void Clear() {

        }

    private:
        Node<T>* root = new Node<T>();
        int m_size;
};
#pragma once

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
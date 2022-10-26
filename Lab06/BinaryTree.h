#include <vector>

template<typename T> class Node {
    public:
        Node() = delete;

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

        Node* GetRightNode() {
            return m_right;
        }

        void SetRightNode(Node* n) {
            m_right = *n;
        }

        Node* GetLeftNode() {
            return m_left;
        }

        void SetLeftNode(Node* n) {
            m_left = *n;
        }

    private:
        T m_val;
        Node* m_right = nullptr;
        Node* m_left = nullptr;
};

template<typename T> class BinaryTree {
    public:
        BinaryTree() {
            m_size = 0;
        }

        ~BinaryTree() {

        }

        bool Insert(Node<T>* newNode) {
            if (m_size == 0) {
                
                return true;
            }

            if (newNode->ReturnValue > root.ReturnValue()) {
                root.SetRightNode(newNode);
                return true;
            }

            if (newNode->ReturnValue() < root.ReturnValue()) {
            }


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
        Node<T> root = new Node<T>(node);
        int m_size;
};
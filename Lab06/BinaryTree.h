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

        bool Insert(Node<T>* newNode, Node<T>* rootNode) {
            if (newNode->ReturnValue() >= rootNode->ReturnValue()) {
                if (rootNode->GetRightNode() == nullptr) {
                    rootNode->SetRightNode(newNode);
                    return true;
                } else {
                    Insert(newNode, rootNode->GetRightNode());
                    m_size++;
                }

                return true;
            } else if (newNode->ReturnValue() < rootNode->ReturnValue()) {
                if (rootNode->GetLeftNode() == nullptr) {
                    rootNode->SetLeftNode(newNode);
                    return true;
                } else {
                    Insert(newNode, rootNode->GetLeftNode());
                    m_size++;
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
        // Node<T> root = new Node<T>();
        int m_size;
};
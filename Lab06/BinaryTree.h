template<typename T> class BinaryTree {
    public:
        BinaryTree() {
            m_size = 0;
        }

        ~BinaryTree() {

        }

        bool Insert(Node<T>* node) {
            if (m_size == 0) {
                
                return true;
            }

            if (root.)

        }

        Node<T>* Find(T val) {

        }

        int Size() {
            return m_size;
        }

        std::vector<Node<T>> GetAllAscending() {

        }

        void Clear() {

        }

    private:
        int m_size;
};

template<typename T> class Node {
    public:
        Node() {
            m_val = NULL;
            m_right = nullptr;
            m_left = nullptr;
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
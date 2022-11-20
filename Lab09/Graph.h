#include <vector>

template<typename T> class Node {
    public:
        Node() {
            m_pointer = nullptr;
        }

        Node(T val) {
            m_val = val;
        }

        ~Node() {}

        T ReturnValue() {
            return m_val;
        }

        void SetValue(T v) {
            m_val = v;
        }

    private:
        T m_val;
        Node* m_pointer;

        // std::shared_ptr<Node>m_right();
};

template<class T>
class Graph{
    public:
        
        Graph( vector<Node> a, vector<int> b1, vector<int> b2 ){
            v = a;
            e1 = b1;
            e2 = b2;
        }

        void addEdge( int i, int j ){
            e1.push_back(i);
            e2.push_back(j);
        }

        void removeEdge( int i, int j ){
            for( int k = 0, i < e1.size(), k++){
                if( e1.at(k) ==  i && e2.at(k) == j ){
                    e1[k].erase();
                    e2[k].erase();
                    return;
                }
            }
            return;
        }

        bool hasEdge( int i, int j ){
            for( int k = 0, k < e1.size(), k++){
                if( e1.at(k) ==  i && e2.at(k) == j ){
                    return true;
                }
            }
            return false;
        }

        vector<int> outEdges( int i ){
            vector<int> temp;
            for( int k = 0, k < e1.size(), k++){
                if( e1.at(k) ==  i ){
                    temp.push_back(e2.at(k));
                }
            }
            return temp;
        }

        vector<int> inEdges( int j ){
            vector<int> temp;
            for( int k = 0, k < e1.size(), k++){
                if( e2.at(k) ==  j ){
                    temp.push_back(e1.at(k));
                }
            }
            return temp;
        }

        void PrintOutAdjacencyMatrix(){
            
            cout << "  ";
            for( int k = 0, k < v.size(), i++ ){
                cout << v.at(k).ReturnValue() << " ";
            }
            cout << endl;

            for( int k = 0, k < v.size(), i++ ){
                cout << v.at(k).ReturnValue() << " ";
                for( int l = 0, l < v.size(), l++ ){
                    if( this->hasEdge( v.at(k).ReturnValue() , v.at(l).ReturnValue() ) = true ){
                        cout << "1 ";
                    } else {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }

        }
        ~Graph();

    private:
        vector<Node> v;
        vector<int> e1;
        vector<int> e2;

};
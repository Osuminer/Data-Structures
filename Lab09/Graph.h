#include <vector>

class Graph{
    public:
        Graph(){
            nodes = 5;
            vector< vector<int> > grph( nodes , vector<int>( nodes , 0 ) );
        }

        void addEdge( int i , int j ){
            grph[i][j] = 1;
        }

        void removeEdge( int i , int j ){
            grph[i][j] = 0;
        }

        bool hasEdge( int i , int j ){
            if( grph[i][j] == 1 ){
                return true;
            } 
            return false;
        }

        vector<int> outEdges( int i ){
            vector<int> temp;
            for( int k = 0 ; k < nodes ; k++ ){
                if( grph[i][k] == 1 ){
                    temp.push_back( k );
                }
            }
            return temp;
        }

        vector<int> inEdges( int i ){
            vector<int> temp;
            for( int k = 0 ; k < nodes ; k++ ){
                if( grph[k][i] == 1 ){
                    temp.push_back( k );
                }
            }
            return temp;
        }

        void PrintOutAdjacencyMatrix(){
            
            cout << "  ";
            for( int k = 0 ; k < nodes ; k++ ){
                cout << k << " ";
            }
            cout << endl;

            for( int k = 0 ; k < nodes ; k++ ){
                cout << k << " ";
                for( int l = 0 ; l < nodes ; l++ ){
                    if( this->hasEdge( k , l ) ){
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
        int nodes;
        vector< vector<int> > grph;
};
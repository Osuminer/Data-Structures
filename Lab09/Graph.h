#include <vector>
#include <iostream>

using namespace std;

class Graph{
    public:
        Graph(){
            nodes = 5;
            std::vector< std::vector<int> > grph( nodes , std::vector<int>( nodes , 0 ) );
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

        std::vector<int> outEdges( int i ){
            std::vector<int> temp;
            for( int k = 0 ; k < nodes ; k++ ){
                if( grph[i][k] == 1 ){
                    temp.push_back( k );
                }
            }
            return temp;
        }

        std::vector<int> inEdges( int i ){
            std::vector<int> temp;
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
        std::vector< std::vector<int> > grph;
};
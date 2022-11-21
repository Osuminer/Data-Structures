#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {

int x = 0;
Graph g;


while( x != 7 ){

    cout << "Press 1 to add an edge to graph. " << endl
         << "Press 2 remove an edge from graph. " << endl
         << "Press 3 Find an edge in the graph. " << endl
         << "Press 4 Find the out edges of a vertices " << endl
         << "Press 5 Find the in edges of a vertices " << endl
         << "Press 6 To Print out Adjacency Matrix " << endl
         << "Press 7 to quit. " << endl << endl;
    
    cin >> x;

    if( x == 1 ){
        int i;
        int j;

        cout << "enter first node " << endl;
        cin >> i;
        cout << "enter second node " << endl;
        cin >> j;

        g.addEdge( i , j );

    } else if( x == 2 ){
        int i;
        int j;

        cout << "enter first node " << endl;
        cin >> i;
        cout << "enter second node " << endl;
        cin >> j;

        g.removeEdge( i , j );

    } else if( x == 3 ){
        int i;
        int j;

        cout << "enter first node " << endl;
        cin >> i;
        cout << "enter second node " << endl;
        cin >> j;

        if( g.hasEdge( i , j ) ){
            cout << i << " and " << j << " does have an edge" << endl;
        } else {
            cout << i << " and " << j << " does not have an edge" << endl;
        }

    } else if( x == 4 ){
        int i;

        cout << "enter node " << endl;
        cin >> i;

        vector<int> temp = g.outEdges( i );

        if( !temp.empty() ){
            cout << "node " << i << " has out edges at:";

            for( int k = 0 ; k < temp.size() ; k++ ){
                cout << " " << temp[k];
            }


        } else {
            cout << "node " << i << " has no out edges";
        }
   
        cout << endl;

    } else if( x == 5 ){
        int i;

        cout << "enter node " << endl;
        cin >> i;

        vector<int> temp = g.inEdges( i );

        if( !temp.empty() ){
            cout << "node " << i << " has in edges at:";

            for( int k = 0 ; k < temp.size() ; k++ ){
                cout << " " << temp[k];
            }


        } else {
            cout << "node " << i << " has no in edges";
        }
   
        cout << endl;

    } else if( x == 6 ){
        g.PrintOutAdjacencyMatrix();
    }


} 


return 0;

}
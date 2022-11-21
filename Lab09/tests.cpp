#include <gtest/gtest.h>
#include "Graph.h"


// Add Edges ----------------------------------------------------------------------
TEST(AddEdges, AddEdge1) {
    Graph c;
    c.addEdge( 0 , 0 );
    ASSERT_TRUE( c.hasEdge( 0 , 0 ) );
}

TEST(AddEdges, AddEdge2) {
    Graph c;
    c.addEdge( 1 , 4 );
    ASSERT_TRUE( c.hasEdge( 1 , 4 ) );
}

// Remove Edges -------------------------------------------------------------------
TEST(RemoveEdges, RemoveEdge1) {
    Graph c;
    c.addEdge( 0 , 0 );
    c.removeEdge( 0 , 0 );
    ASSERT_FALSE( c.hasEdge( 0 , 0 ) );
}

TEST(RemoveEdges, RemoveEdge2) {
    Graph c;
    c.addEdge( 4 , 2 );
    c.removeEdge( 4 , 2 );
    ASSERT_FALSE( c.hasEdge( 4 , 2 ) );
}

// Has Edges ----------------------------------------------------------------------
TEST(HasEdges, HasEdge1) {
    Graph c;
    c.addEdge( 0 , 0 );
    ASSERT_TRUE( c.hasEdge( 0 , 0 ) );
}

TEST(HasEdges, HasEdge2) {
    Graph c;
    c.addEdge( 1 , 4 );
    ASSERT_TRUE( c.hasEdge( 1 , 4 ) );
}

// Out Edges ----------------------------------------------------------------------
TEST(OutEdges, OutEdge1) {
    Graph c;
    c.addEdge( 0 , 0 );
    vector<int> temp = c.outEdges( 0 );
    ASSERT_EQ( temp[0] , 0 );
}

TEST(OutEdges, OutEdge2) {
    Graph c;
    c.addEdge( 0 , 1 );
    c.addEdge( 0 , 4 );
    vector<int> temp = c.outEdges( 0 );
    ASSERT_EQ( temp.size() , 2 );
}

// In Edges -----------------------------------------------------------------------
TEST(InEdges, InEdge1) {
    Graph c;
    c.addEdge( 0 , 0 );
    vector<int> temp = c.inEdges( 0 );
    ASSERT_EQ( temp[0] , 0 );
}

TEST(InEdges, InEdge2) {
    Graph c;
    c.addEdge( 0 , 1 );
    c.addEdge( 4 , 1 );
    vector<int> temp = c.inEdges( 1 );
    ASSERT_EQ( temp.size() , 2 );
}

// Print --------------------------------------------------------------------------
TEST(PrintMatrix, Print1) {
    Graph c;
    ASSERT_TRUE( c.PrintOutAdjacencyMatrix() );
}

TEST(PrintMatrix, Print2) {
    Graph c;
    c.addEdge( 0 , 4 );
    ASSERT_TRUE( c.PrintOutAdjacencyMatrix() );
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

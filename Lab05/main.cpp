#include "Recursion.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ChessBoard chessBoard;

	bool status = chessBoard.SolveStack(chessBoard,0);
	if(status)
	{
		string output = chessBoard.ToString();
		cout << output << endl;
	}
	else
	{
		cout << "No solution found"  << endl;
		string output = chessBoard.ToString();
		cout << output << endl;
	}
	

	return 0;
}
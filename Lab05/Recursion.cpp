#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <exception>


using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1


int FactorialByRecursion::CalculateFactorial(int num) {
	int answer = num;
	if (num == 1) {
		return 1;
	}

	int temp = CalculateFactorial(num-1);
	
	return answer * temp;
}


int FactorialByStack::CalculateFactorial(int num) {

	int answer = 1;
	int temp = num;

	std::stack<int> s;
	
	s.push(num + 1);

	while( temp > 0 ){
		s.push(temp);
		temp--;
	}

	while( s.top() <= num ){
		answer *= s.top();
		s.pop();
	}

	return answer;
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	if (col >= 8) {
		return true;
	}

	for (int i = 0; i < 8; ++i) {
		if (CheckSafeQueens(chessBoard, i, col)) {
			m_board[i][col] = 1;

			if (Solve(chessBoard, col + 1) == true) {
				return true;
			}

			m_board[i][col] = 0;
		}
	}
	return false;
}

bool ChessBoard::SolveStack(ChessBoard chessBoard) {

	int filled = 0;	// Number of filled spots
	stack<pair<int, int>> queens;	// Stack of queen locations

	queens.push(make_pair(-1, -1));	// Default starter location

	int col = 0;
	int row = 0;

	// Loop until 8 spots are filled
	while (filled < 8) {

		// Increment the last queen's column by 1 for next queen
		col = queens.top().second + 1;

		if (CheckSafeQueens(chessBoard, row, col)) {	// If queen is safe in that position
			m_board[row][col] = 1;
			queens.push(make_pair(row, col));
			filled++;
			row = 0;
		} else if (!CheckSafeQueens(chessBoard, row, col) && row < 8) {	// If queen can't be placed, but still in bounds
			m_board[row][col] = 0;
			row++;
		} else if (!CheckSafeQueens(chessBoard, row, col) && row >= 8) {	// If queen can't be placed, but out of bounds
			queens.pop();	// Get rid of last queen to find new location
			filled--;
			row = queens.top().first + 1;	// Start moving last queen again from last row
		}
	}
	
	return true;
}


bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) {

	// Check all spots left of column
	for (int i = 0; i < col; i++) {
        if (m_board[row][i]) {
            return false;
		}
	}

	// Check all spots above
	for (int i = 0; i < row; i++) {
		if (m_board[i][col]) {
			return false;
		}
	}

	// Check all spots below
	for (int i = row; i < 8; i++) {
		if (m_board[i][col]) {
			return false;
		}
	}

	// Check all spots in upper left diagonal
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (m_board[i][j]) {
            return false;
		}
	}

	// Check all spots in lower left diagonal
	for (int i = row, j = col; j >= 0 && i < 8; i++, j--) {
        if (m_board[i][j]) {
            return false;
		}
	}

    return true;
}


string ChessBoard::ToString() {

	string answer = "";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i) {    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal = "I did not get an Exception";
	MyFakeClass* resourceThatNeedsToBeCleanedup = new MyFakeClass();

	//added this - Jason
	try{ 
		SimpleExceptionMethod(i); 
	} catch(MyException1 e){ 
		return e.what();
	} catch(MyException2 e){ 
		return e.what();
	} catch(MyException3 e){ 
		return e.what();
	}

	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i) {
	int retVal = 0;

	if (i == 1) {
		throw MyException1();
	}
	else if (i == 2) {
		throw MyException2();

	}
	else if (i == 3) {
		//I uncommented this - Jason
		throw MyException3();
	}
	else {
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "I got Exception 1";
}
char const* MyException2::what() const throw() {
	return "I got Exception 2";
}
//added this - Jason
char const* MyException3::what() const throw() {
	return "I got Exception 3";
}

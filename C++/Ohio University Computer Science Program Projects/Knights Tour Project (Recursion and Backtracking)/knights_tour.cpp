#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) 
{
  this->board_size = board_size;

  board.resize(board_size);
  for (int i = 0; i < board_size; ++i) 
  {
	board[i].resize(board_size);
  }
}

void KnightsTour::print() 
{
  for (int i = 0; i < board_size; i++) 
  {
	for (int j = 0; j < board_size; j++)
	  cout << setw(4) << board[i][j] << " ";
	cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

/**********START OF ANDREW'S IMPLEMENTATION**********/
void KnightsTour::get_moves(
  int row, int col, 
  int row_moves[], int col_moves[], int& num_moves) 
{
	// TA'S COMMENTS
	// Check all valid moves in a clockwise fashion starting
	// from the move in which the knight travels two squares
	// right and one square up. This will ensure that everyone's
	// output is consistent with mine.
	// END TA'S COMMENTS
  
	// I used the two helper functions to encapsulate the actions 
	// taken by them and make this more readable.
	// TODO Look for a better  way to loop through these if it exists
	if (valid(row + 2, col - 1))
		add(row + 2, col - 1, row_moves, col_moves, num_moves);

	if (valid(row + 2, col + 1))
		add(row + 2, col + 1, row_moves, col_moves, num_moves);

	if (valid(row + 1, col + 2))
		add(row + 1, col + 2, row_moves, col_moves, num_moves);

	if (valid(row - 1, col + 2))
		add(row - 1, col + 2, row_moves, col_moves, num_moves);

	if (valid(row - 2, col + 1))
		add(row - 2, col + 1, row_moves, col_moves, num_moves);

	if (valid(row - 2, col - 1))
		add(row - 2, col - 1, row_moves, col_moves, num_moves);

	if (valid(row - 1, col - 2))
		add(row - 1, col - 2, row_moves, col_moves, num_moves);

	if (valid(row + 1, col - 2))
		add(row + 1, col - 2, row_moves, col_moves, num_moves);

}

// Used to abstract the process of checking each of the 8 possible locations
bool KnightsTour::valid(int row, int col)
{
	// Make sure the data is within the board vector bounds
	if ((row >= 0 && row < board_size && col >= 0 && col < board_size))
	{
		// check the location isn't already full (all vector ints initialized to zero)
		if (board[col][row] == 0)
			return true;
		else
			return false;
	}
	else 
		return false;
}

// Marks the new location and stores the coordinate pair in the decayed array pointers
void KnightsTour::add(int row, int col, int row_moves[], int col_moves[], int & num_moves)
{
	row_moves[num_moves] = row;
	col_moves[num_moves] = col;
	num_moves++;
}

// TA'S COMMENTS
// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.
// END TA'S COMMENTS


void KnightsTour::move(int row, int col, int& m, int& num_tours) 
{
	// Given row and col, mark the current move id in board using m.
	// We will also increment m to make sure we are placing correct numbers
	board[col][row] = ++m;

	// TA'S COMMENTS
	// When m equals the total number of cells in board, it
	// means a tour has been completed. Every time a tour
	// is completed, you should print the board using ::print
	// END TA'S COMMENTS
	
	// I moved this up top, because if we found the board pieces, we can skip getting moves
	if (board_size * board_size == m)
	{
		num_tours++;
		cout << "Successful Board!" << endl;
		print();

	}
	else
	{
		// TA'S COMMENTS
		// Next find all valid knight moves from position row, col using
		// ::get_moves. For each new move found from ::get_moves,
		// recursively call ::move  to find all remaining
		// tours.
		// END TA'S COMMENTS

		//Declare vars for get_moves()
		int row_moves[8];
		int col_moves[8];
		int num_moves = 0;

		// Retrieve all possible moves
		get_moves(row, col, row_moves, col_moves, num_moves);

		// Loop through trying these new solutions and finding solutions that branch from them
		for (int i = 0; i < num_moves; ++i)
		{
			move(row_moves[i], col_moves[i], m, num_tours);
		}
		
	}

	// Regardless of whether we have found a successful board, a failed board,
	// or have exausted all possible move branches, we will need to step back
	// by removing the last piece we placed, and lowering the move id back down
	// to the previous placement
	board[col][row] = 0;
	m--;
}
/**********END OF ANDREW'S IMPLEMENTATION**********/

int KnightsTour::generate(int row, int col) 
{
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}



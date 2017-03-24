#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <vector>
using namespace std;

class KnightsTour {

public:
  KnightsTour(int board_size);

  void print();
  int generate(int row, int col);

  void move(int row, int col, int& m, int& num_tours);
  void get_moves(
	int row, int col, 
	int row_moves[], int col_moves[], int& num_moves
  );
  bool valid(int row, int col);
  void add(
	  int row, int col,
	  int row_moves[], int col_moves[], int& num_moves);

private:
  int board_size;
  vector<vector<int> > board;

};

#endif

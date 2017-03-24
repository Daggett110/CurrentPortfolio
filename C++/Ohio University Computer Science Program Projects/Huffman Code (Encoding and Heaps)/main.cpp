#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <cstring>
#include "huffman_tree.h"
using namespace std;

int main(int argc, char** argv) {
  // Read a string message into the HuffmanTree constructor
  // Next, pass the string message into HuffmanTree::print_message() 
  // to get its compressed binary encoding.
  int count;
  
  cin >> count;
  
  string message[count];
  for(int i = 0; i < count; ++i)
  {
	  while(cin.peek() == '\n' || cin.peek() == '\r')
		cin.ignore();
		getline(cin, message[i]);
  }
  
  for(int i = 1; i <= count; ++i)
  {
	  
	  HuffmanTree HT(message[i - 1]);
	  cout << "Test Case: " << i << endl;
	  HT.print_message(message[i - 1]);
  }
}

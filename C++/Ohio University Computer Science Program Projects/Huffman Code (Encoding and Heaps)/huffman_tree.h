#include <map>
#include <iostream>
#include "min_heap.h"
using namespace std;

struct HuffmanNode {
  HuffmanNode(char c, int f) : character(c), freq(f), left(NULL), right(NULL) {}
  HuffmanNode(int f) : character('*'), freq(f), left(NULL), right(NULL) {}

  ~HuffmanNode() {
    delete left;
    delete right;
    left = right = NULL;
  }
  
  char character;
  int freq;
  HuffmanNode* left;
  HuffmanNode* right;
};

class HuffmanTree {

public:
  HuffmanTree(string message) {
    // Count the frequency of each letter in message
    // e.g. 
    //    message == "aaabbccccdd"
    //    frequencies == {a:3, b:2, c:4, d:2} 
    map<char, int> frequencies;
    for (int i = 0; i < message.length(); ++i) {
      if (frequencies.count(message[i]) > 0)
        ++frequencies[message[i]];
      else        frequencies[message[i]] = 1;
    }
	// Create HuffmanNode for each unique letter in message
    // and organize nodes into a min heap
    // e.g.
    //  heap == 
    //            {b:2}  
    //           /     \
    //        {d:2}   {a:3}
    //        /   \   /    \
    //      {c:4} 
    MinHeap<HuffmanNode*> heap;
    map<char, int>::iterator it = frequencies.begin();
    for (; it != frequencies.end(); ++it) {
      HuffmanNode* huffman_node = new HuffmanNode(
        it->first, it->second
      );
      heap.insert(huffman_node, it->second);
    }

    // Combine nodes with smallest frequency and insert
    // back into heap until heap size == 1. Along the way,
    // create binary tree out of combined nodes.
    // e.g.
    //  (1)
    //     {b:2} == heap.extract_min(huffman_left)
    //     {d:2} == heap.extract_min(huffman_left)
    //     huffman_top ==
    //               {*:4}
    //              /     \
    //            {b:2}  {d:2}
    //
    //     heap == 
    //              {a:3}
    //             /     \
    //           {c:4}   {*:4}
    //
    //  (2)
    //     {a:3} == heap.extract_min(huffman_left)
    //     {c:4} == heap.extract_min(huffman_left)
    //     huffman_top ==
    //              {*:7}
    //             /     \
    //          {a:3}   {*:4}
    //    
    //     heap ==
    //            {c:4}
    //           /
    //         {*:7}
    //
    //  (3)
    //     {*:4} == heap.extract_min(huffman_left)
    //     {*:7} == heap.extract_min(huffman_right)
    //     huffman_top ==
    //            {*:11}
    //           /       \
    //      {c:4}        {*:7}
    //                  /     \
    //                {a:3}  {*:4}
    //                       /    \
    //                    {b:2}  {d:2}
    //
    //     heap == {*:11}
	while (heap.size() > 1) {
      HuffmanNode* huffman_left;
      HuffmanNode* huffman_right;

      heap.extract_min(huffman_left);
      heap.extract_min(huffman_right);

	  
      HuffmanNode* huffman_top = new HuffmanNode(
        huffman_left->freq + huffman_right->freq
      );

      huffman_top->left = huffman_left;
      huffman_top->right = huffman_right;

      heap.insert(huffman_top, huffman_top->freq);
    }
	
    // Get root of huffman tree. e.g. {*:11}
    heap.peek(root_);
  }

  ~HuffmanTree() {
    delete root_;
  }

  /**********START OF ANDREW'S IMPLEMENTATION**********/
  void print_message(const string message) 
  {
    // Print the Huffman encoding of message.
    // Append 0 to a character's encoding if moving left in Huffman tree
    // Append 1 to a character's encoding if moving right in Huffman tree
	
    // Remember, your Huffman tree is pointed at by root_, so start your
    // character searches from there.
	
	// I save the hieght here and use it for the initialization of the code
	// snippet in the loop because it's faster to grab the unchanging height
	// once outside the loop, and we don't have too empty codeSnippet at the
	// end of every loop.
	for (int i = 0; i < message.length(); ++i)
	{
		char codeSnippet[256];
		
		HuffTreeSearch(message[i], codeSnippet, root_, 0);
		
	}
	cout << endl;
  }
  
  void HuffTreeSearch(char target, char code[], HuffmanNode* root, int height)
  {
	  // if we have found our target ..
	if(root -> character == target)
	{
		// add it's code to the printed output
		for(int i = 0; i < height; ++i)
			cout << code[i];
		cout << " ";
	}
	else
	{
		// if the left node exists ..
		if(root -> left != NULL)
		{
			// Add the code of moving left in the tree and search it
			code[height] = '0';
			HuffTreeSearch(target, code, root -> left, height + 1);
		}
		if(root -> right != NULL)
		{
			code[height] = '1';
			HuffTreeSearch(target, code, root -> right, height + 1);
		}	cout << "search unsuccessful" << endl;*/
	}
	// if we have reached the end of a tree, we just ignore the code,
	// and move to the next option via recursive traversal
  }
  /**********END OF ANDREW'S IMPLEMENTATION**********/
  
private:
  HuffmanNode* root_;
};

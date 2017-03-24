#include <vector>
#include <iostream>
using namespace std;

template <typename Type>
struct HeapNode {
  HeapNode(const Type d, const int k) :
    data(d), key(k) {}

  Type data;
  int key;
};

template <typename Type>
class MinHeap {

public:
  MinHeap() 
  {
	  
  }
  ~MinHeap() 
  {
	  
  }

  
  //* Function: insert
  //* Input: 
  //*       data - User data
  //*       key  - Key value associated with user data.
  //*              Use key to organize user data into min
  //*              heap container
  /**********START OF ANDREW'S IMPLEMENTATION**********/
  void insert(const Type data, const int key) {
    // Since data could be of any type, we store it in a special
    // HeapNode that allows heap_ to keep track of user data and
    // their key values separately. 
	
	HeapNode<Type> heap_node(data, key);

	heap_.push_back(heap_node);
	
	// TA'S COMMENTS
    // Stop bubbling up if a child node has the same key value as
    // its parent node. This will ensure that your output remains
    // consistent with mine.
	// END TA'S COMMENTS
	int i = heap_.size() - 1;
	
	// While we are not at the root and heap_node is still
	// less than parent, keep moving up.
	while (i != 0 && heap_node.key < heap_[(i-1)/2].key)
	{
		HeapNode<Type> temp(heap_[i].data, heap_[i].key);
		heap_[i] = heap_[(i-1)/2];
		heap_[(i-1)/2] = temp;
		i /= 2;
	}
  }

  // TA'S COMMENTS
  //* Function: extract_min
  //* Input:
  //*       return_data - Reference variable to retrieve user data
  //*                     stored in heap.
  // END TA'S COMMENTS
  void extract_min(Type& return_data) {
	// TA'S COMMENTS
    // We will leave it up to the user to check if their heap is empty
    // before extracting the minimum element. With that in mind, just
    // return without setting return_data if heap_ is empty.
	// END TA'S COMMENTS
    if (heap_.size() == 0)
      return;
	
	// TA'S COMMENTS
    // Store minimum elements data in return data and then
    // remove the minimum element from the heap.
    // Make sure heap_ remains a min heap after this function exits.
	// END TA'S COMMENTS
	
	//store return data
	return_data = heap_[0].data;
	
	//move last element to the top
	heap_[0] = heap_.back();
	heap_.pop_back();
	
	// sift down
	int i = 0;
	// while we still have not created a min heap ..
	while (heap_[i].key > heap_[(2*i) + 1].key || heap_[i].key > heap_[(2*i) + 2].key)
	{
		// find the lesser node of the two (or the left one if they are equal)
		int swapIndex;
		if((2*i)+2 < size())
			swapIndex = heap_[(2*i) + 1].key <= heap_[(2*i)+2].key ? (2*i) + 1 : (2*i) + 2;
		else if((2*i)+1 < size())
		{
			swapIndex = (2*i)+1;
		}
		else
			break;
		HeapNode<Type> temp(heap_[swapIndex].data, heap_[swapIndex].key);
		heap_[swapIndex] = heap_[i];
		heap_[i] = temp;
		i = swapIndex;
	}
	
	// TA'S COMMENTS
	// IMPORTANT!!!
    // When two children nodes share the same key value, always swap
    // the parent node with the left child if the parent node is larger
    // than the left child. This will ensure that your output remains
    // consistent with mine.
	// END TA'S COMMENTS
  }

  // TA'S COMMENTS
  //* Function: peek
  //* Input:
  //*       return_data - Reference variable to retrieve user data
  //*                     stored in heap.
  // END TA'S COMMENTS
  void peek(Type& return_data) const {
    // As with extract_min, we leave it up to the user to check if
    // their heap is empty before calling peek. If the user doesn't
    // follow this suggestion and calls peek when
    // heap_ is empty, then return_data won't be set to anything.
    if (heap_.size() == 0)
      return;
  
    // If heap_ isn't empty, then get user data out of min element.
    // Don't remove min element from heap though.
	return_data = heap_[0].data;
	
  }

  // TA'S COMMENTS
  //* Function: size
  // END TA'S COMMENTS
  int size() const {
    // Return the size of your heap
	return heap_.size();
  }
  /**********END OF ANDREW'S IMPLEMENTATION**********/

private:
  vector<HeapNode<Type> > heap_;
};

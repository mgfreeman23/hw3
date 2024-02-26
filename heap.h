#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename Comparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, Comparator c = Comparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items;
  Comparator comp;
  int rank;
  void heapify(int i);
};

// Add implementation of member functions here

//constructor
template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c){
  rank = m;
  comp = c;
} 

//destructor
template <typename T, typename Comparator>
Heap<T,Comparator>::~Heap(){

} 

//push element
template <typename T, typename Comparator>
void Heap<T,Comparator>::push(const T& item){
  //add item to vector
  items.push_back(item);
  //get index of added item
  std::size_t index = items.size() - 1;
  //enter loop
  while (index != 0) {
    //get index of parent
    std::size_t parent_index = (index - 1) / rank;
    //value of data just added
    T& current = items[index];
    //value of its parent
    T& parent = items[parent_index];
    //exit loop if added data does not have priority over parent
    if (!comp(current, parent)) {
      break;
    }
    //if added does have priority, swap them and get ready to check against next parent
    std::swap(current, parent);
    index = parent_index;
  }
}

//check if heap is empty
template <typename T, typename Comparator>
bool Heap<T,Comparator>::empty() const{
  if(items.size() == 0){
    return true;
  }
  return false;
}

//returns number of items in heap
template <typename T, typename Comparator>
size_t Heap<T,Comparator>::size() const{
  return items.size();
}

//get top element
template <typename T, typename Comparator>
T const & Heap<T,Comparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items[0];

}

//remove top/best element
template <typename T, typename Comparator>
void Heap<T,Comparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");
  }
  //
  items[0] = items[items.size() - 1];
  items.pop_back();
  heapify(0);

}

//helper function for trickle down after pop
template <typename T, typename Comparator>
void Heap<T,Comparator>::heapify(int i){

    //index of curr parent
    int bestChild = i;
    
    //go through children and find "best" one if one better than parent
    for(int k = 0; k < rank; k++){
      int childIndex = rank*i + k + 1;
      if(childIndex < items.size() && comp(items[childIndex], items[bestChild])){
        bestChild = childIndex;
      }
    }
    //swap parent data with best child data, so the best is at the top
    if(bestChild != i){
        std::swap(items[i], items[bestChild]);
        // new index for best child as you trickle down the heap
        int i = bestChild;
        heapify(i);
    }
}


#endif


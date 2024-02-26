#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> {
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// do I need to write a constructor?
template <typename T>
Stack<T>::Stack(){

}

template <typename T>
Stack<T>::~Stack(){

}

template <typename T>
void Stack<T>::push(const T& item){
   std::vector<T>::push_back(item);
   return;
}
template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size(); 
}
template <typename T>
bool Stack<T>::empty() const {
    if (std::vector<T>::size() == 0){
        return true;
    }
    return false;
}

template <typename T>
const T& Stack<T>::top() const{
    if(this->empty()){
        throw std::underflow_error("empty stack");
    }
    return std::vector<T>::back(); 
    
}
template <typename T>
void Stack<T>::pop(){
    if(this->empty()){
        throw std::underflow_error("empty stack");
    }
    std::vector<T>::pop_back();
}


#endif
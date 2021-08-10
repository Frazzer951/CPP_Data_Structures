#include <iostream>
#include <stdexcept>

template<typename T>
struct dNode
{
  T          val;
  dNode<T> * next;
  dNode<T> * prev;

  dNode( T v ) : val( v ), next( nullptr ), prev( nullptr ) {}
};

template<typename T>
class DoublyLinkedList
{
  dNode<T> * head;
  dNode<T> * tail;

public:
  DoublyLinkedList();     // Default Constructor
  ~DoublyLinkedList();    // Default Destructor

  // Accessors
  dNode<T> * front();
  dNode<T> * back();

  // Capacity
  bool empty();

  // Modifiers
  void clear();
  void push_front( T value );
  void pop_front();
  void push_back( T value );
  void pop_back();
  void insert();
  void erase();
};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{}

template<typename T>
inline dNode<T> * DoublyLinkedList<T>::front()
{
  return nullptr;
}

template<typename T>
inline dNode<T> * DoublyLinkedList<T>::back()
{
  return nullptr;
}

template<typename T>
inline bool DoublyLinkedList<T>::empty()
{
  return false;
}

template<typename T>
inline void DoublyLinkedList<T>::clear()
{}

template<typename T>
inline void DoublyLinkedList<T>::push_front( T value )
{}

template<typename T>
inline void DoublyLinkedList<T>::pop_front()
{}

template<typename T>
inline void DoublyLinkedList<T>::push_back( T value )
{}

template<typename T>
inline void DoublyLinkedList<T>::pop_back()
{}

template<typename T>
inline void DoublyLinkedList<T>::insert()
{}

template<typename T>
inline void DoublyLinkedList<T>::erase()
{}

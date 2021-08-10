#include <iostream>
#include <stdexcept>
template<typename T>
struct node
{
  T         val;
  node<T> * next;

  node( T v ) : val( v ), next( nullptr ) {}
};

template<typename T>
class LinkedList
{
  node<T> * head;

public:
  LinkedList();     // Default Constructor
  ~LinkedList();    // Default Destructor

  // Accessors
  node<T> * front();

  // Capacity
  bool empty();

  // Modifiers
  void clear();
  void push_front( T value );
  void pop_front();
  void insert_after( node<T> * node, T value );
  void erase_after( node<T> * node );
};

template<typename T>
LinkedList<T>::LinkedList() : head( nullptr )
{}

template<typename T>
LinkedList<T>::~LinkedList()
{
  clear();
  delete head;
}

template<typename T>
node<T> * LinkedList<T>::front()
{
  return head;
}

template<typename T>
bool LinkedList<T>::empty()
{
  return head == nullptr;
}

template<typename T>
void LinkedList<T>::clear()
{
  node<T> * cur = head;
  head          = nullptr;

  while( cur != nullptr )
  {
    node<T> * tmp = cur;
    cur           = cur->next;
    delete tmp;
  }
}

template<typename T>
void LinkedList<T>::push_front( T value )
{
  auto * newNode = new node<T>( value );
  newNode->next  = head;
  head           = newNode;
}

template<typename T>
void LinkedList<T>::pop_front()
{
  if( empty() ) throw std::out_of_range( "LinkedList is empty" );
  node<T> * tmp = head;
  head          = head->next;
  delete tmp;
}

template<typename T>
void LinkedList<T>::insert_after( node<T> * n, T value )
{
  auto * newNode = new node<T>( value );
  newNode->next  = n->next;
  n->next        = newNode;
}

template<typename T>
void LinkedList<T>::erase_after( node<T> * n )
{
  if( empty() ) throw std::out_of_range( "LinkedList is empty" );
  node<T> * tmp = n->next;
  n->next       = tmp->next;
  delete tmp;
}

template<typename T>
bool operator==( const node<T> & lhs, const node<T> & rhs )
{
  return lhs.val == rhs.val && *lhs.next == *rhs.next;
}

template<typename T>
bool operator==( const LinkedList<T> & lhs, const LinkedList<T> & rhs )
{
  return *lhs.head() == *rhs.head();
}

template<typename T>
std::ostream & operator<<( std::ostream & s, LinkedList<T> const & data )
{
  node<T> cur = data.head();
  s << cur.val;
  while( cur != nullptr ) { s << "->" << cur.val; }
  return s;
}
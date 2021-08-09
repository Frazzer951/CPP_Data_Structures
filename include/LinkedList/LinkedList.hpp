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
inline node<T> * LinkedList<T>::front()
{
  return head;
}

template<typename T>
inline bool LinkedList<T>::empty()
{
  return head == nullptr;
}

template<typename T>
inline void LinkedList<T>::clear()
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
inline void LinkedList<T>::push_front( T value )
{
  node<T> * newNode = new node<T>( value );
  newNode->next     = head;
  head              = newNode;
}

template<typename T>
inline void LinkedList<T>::pop_front()
{
  node<T> * tmp = head;
  head          = head->next;
  delete tmp;
}

template<typename T>
inline void LinkedList<T>::insert_after( node<T> * node, T value )
{
  node<T> * newNode = new node<T>( value );
  newNode->next     = node->next;
  node->next        = newNode;
}

template<typename T>
inline void LinkedList<T>::erase_after( node<T> * node )
{
  node<T> * tmp = node->next;
  node          = tmp->next;
  delete tmp;
}
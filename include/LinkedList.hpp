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
  node<T> front();

  // Capacity
  bool empty();

  // Modifiers
  void clear();
  void push_front();
  void pop_front();
  void insert_after();
  void erase_after();
};

template<typename T>
LinkedList<T>::LinkedList() : head( nullptr )
{}

template<typename T>
LinkedList<T>::~LinkedList()
{
  delete head;
}
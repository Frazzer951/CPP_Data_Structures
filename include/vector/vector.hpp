#pragma once

template<typename T>
class vector
{
  T *          _arr;
  unsigned int _size;
  unsigned int _max_size;

  void _expand();

public:
  // Constructor
  vector() : _arr( new T[1] ), _size( 0 ), _max_size( 1 ) {}

  // Destructor
  ~vector() { delete _arr; }

  // Getter
  unsigned int size();
  unsigned int max_size();
  bool         empty();
  T            at( unsigned int index );
  T            front();
  T            back();

  // Setter
  void push_back( T value );
  void pop_back();
  void insert( unsigned int index, T value );
  void erase( unsigned int index );
  void clear();
};
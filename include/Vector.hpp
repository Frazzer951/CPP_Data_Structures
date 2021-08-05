#pragma once

#include <stdexcept>

template<typename T>
class vector
{
  T *          _arr;
  unsigned int _size;
  unsigned int _max_size;

  void _expand();

public:
  // Constructor
  vector();

  // Destructor
  ~vector();

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

template<typename T>
vector<T>::vector() : _arr( new T[1] ), _size( 0 ), _max_size( 1 )
{}

template<typename T>
vector<T>::~vector()
{
  delete _arr;
}


template<typename T>
void vector<T>::_expand()
{
  _max_size    = _max_size * 2;
  T * _new_arr = new T[_max_size];
  for( unsigned int i = 0; i < _size; i++ ) { _new_arr[i] = _arr[i]; }
  delete _arr;
  _arr = _new_arr;
}

template<typename T>
unsigned int vector<T>::size()
{
  return _size;
}

template<typename T>
unsigned int vector<T>::max_size()
{
  return _max_size;
}

template<typename T>
bool vector<T>::empty()
{
  return _size == 0;
}

template<typename T>
T vector<T>::at( unsigned int index )
{
  if( index < 0 ) throw std::out_of_range( "Index must be a positive value" );
  if( index >= _size ) throw std::out_of_range( "Index Out of Range" );
  return _arr[index];
}

template<typename T>
T vector<T>::front()
{
  if( _size == 0 ) throw std::out_of_range( "Vector is empty" );
  return _arr[0];
}

template<typename T>
T vector<T>::back()
{
  if( _size == 0 ) throw std::out_of_range( "Vector is empty" );
  return _arr[_size - 1];
}

template<typename T>
void vector<T>::push_back( T value )
{
  if( _size == _max_size ) _expand();
  _arr[_size] = value;
  _size++;
}

template<typename T>
void vector<T>::pop_back()
{
  _size--;
}

template<typename T>
void vector<T>::insert( unsigned int index, T value )
{}

template<typename T>
void vector<T>::erase( unsigned int index )
{}

template<typename T>
void vector<T>::clear()
{}
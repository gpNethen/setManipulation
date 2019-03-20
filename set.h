#ifndef SET_H
#define SET_H
#include <cstdlib>                       
#include <iostream>
  class Set
  {
    public:
      static const size_t CAPACITY = 100;   // Maximum capacity of a set
      typedef int Item;                     // Item type used when manipulating
      Set( ) { used = 0; }                     // Simple constructor
      void make_empty ( ) { used = 0; }        // Empties Set contents
      void insert ( const Item& entry );       // Put item into Set
      void remove ( const Item& target );      // Take item out of Set
      void operator += ( const Set& addend );  // Add Set contents
      size_t size( ) const { return used; }     // Gives size of a Set
      size_t occurs( const Item& target ) const; // Gives number of a certain
                                                 // item in a Set
      friend std::ostream& operator << ( std::ostream& out_s, const Set& b );
    private:
      Item data[CAPACITY];                  // Array for num. of elements in Set
      size_t used;                          // Var for number of elements in Set
  };
  Set operator + ( const Set& s1, const Set& s2 ); // Combining two Sets
#endif


#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "set.h"
using namespace std;
  void Set::insert ( const Item& entry )
  {
    assert ( size() < CAPACITY );
    data[used] = entry;
    ++used;
  }
  void Set::remove ( const Item& target )
  {
    size_t index; 
    for (index = 0; (index < used) && (data[index] != target); index++)
    
      ;
    if (index == used)
      return;
    used--;
    data[index] = data[used];
  }
  void Set::operator += ( const Set& addend )
  {
    size_t i, addend_size;
    assert ( size() + addend.size() <= CAPACITY );
    addend_size = addend.size();
    for (i=0; i<addend_size; ++i)
    {
      data[used] = addend.data[i];
      ++used;
    }
  }
  size_t Set::occurs( const Item& target ) const
  {
    size_t answer, i;
    answer = 0;
    for (i=0; i<used; ++i)
      if ( data[i] == target )
        ++answer;
    return answer;
  }
  ostream& operator << ( ostream& out_s, const Set& s )
  {
    out_s << "{ ";
    if ( s.used > 1 )
      for (int i=0; i<s.used-1; ++i)
        out_s << setw(1) << s.data[i] << ", "; 
    if ( s.used > 0 )
      out_s << setw(1) << s.data[s.used-1] << ' ';
    out_s << "}";
    return out_s;
  }
  Set operator + ( const Set& s1, const Set& s2 )
  {
    Set answer;
    assert ( s1.size() + s2.size() <= Set::CAPACITY );
    answer += s1;
    answer += s2;
    return answer;
  }

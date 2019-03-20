#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "set.h"
#include "set.cpp"
using namespace std;
const int SETS = 3;
void menu( );
int main()
{
  char command;
  int v;
  int n, n1, n2, n3;
  Set s[SETS];
  menu();
  do
  {
    cout << "--> ";
    cin >> command;
    switch ( command )         
    {
      case 'e': cin >> n;
                s[n].make_empty();
                break;
      case 'i': cin >> v >> n;
      			if(s[n].occurs(v)>0)
      			{
      			  cout << "     Value already exists in set." << endl;
      			  break;
      			}
      			else
      			{
                  s[n].insert(v);
                  break;
                }
      case 'r': cin >> v >> n;
                s[n].remove(v);
                break;
      case 's': cin >> n;
                cout << "Set " << setw(1) << n << " contains "
                     << setw(1) << s[n].size() << " items." << endl;
                break;
      case 'u': cin >> n1 >> n2 >> n3;
                s[n3] = s[n1] + s[n2];
                break;
      case 'w': cin >> n;
                cout << "Set " << setw(1) << n << ": " << s[n] << endl;
                break;
      case 'h': menu();
                break;
      default: ;             
    }
  } while ( command != 'q' );
  return EXIT_SUCCESS;
}
void menu( )
{
  cout << endl;
  cout << "This program responds to commands the user enters to" << endl;
  cout << "manipulate " << setw(1) << SETS << " sets,"
       << "  which are initially" << endl;
  cout << "empty. In the following commands, v is any integer, and" << endl;
  cout << "n , n1, n2, and n3 are numbers of sets; they may only be" << endl;
  cout << "integers from 0 to " << setw(1) << SETS-1 << '.' << endl << endl;
  cout << "  e n   -- Make set n empty." << endl;
  cout << "  i v n -- Insert the value v into set n." << endl;
  cout << "  r v n -- Remove the value v from set n." << endl;
  cout << "  s n   -- Report the size of set n." << endl;
  cout << "  u n1 n2 n3 -- Create the union of set n1 and set n2" << endl
       << "                put the union in set n3." << endl;
  cout << "  w n -- Write out the contents of set n." << endl;
  cout << "  h -- See this menu." << endl;
  cout << "  q -- Quit the program." << endl << endl;
}

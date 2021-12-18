#include "LL_T_E.h"
#include <iostream>
using namespace std;

int main()
{
  LL<int> l;
  try
    {
      l.addRear(3);
      l.addRear(4);
      l.addRear(6);
      l.addRear(7);
      cout << "Elements displayed:" << endl;
      l.displayAll();
      cout << "\n------ Elements that will be deleted ------" << endl;
      cout << l.deleteRear() << " has been deleted from the rear" << endl;
      l.displayAll();
      cout << "\n\n" << l.deleteRear() << " has been deleted from the rear" << endl;
      l.displayAll();
      cout << "\n\n" << l.deleteRear() << " has been deleted from the rear" << endl;
      l.displayAll();
      cout << "\n\n" << l.deleteRear() << " has been deleted from the rear" << endl;
      l.displayAll();
      cout << "\n\n" << l.deleteRear() << " has been deleted from the rear" << endl;
    }
  catch(LL<int>::Underflow)
    {
      cout << "\nUnderflow: there are no nodes inside the heap memory" << endl;
    }
  cout << "\nAFTERMATH" << endl << endl;
  l.displayAll();
  return 0;
}

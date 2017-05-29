#include "Flight.h"
#include <iostream>


using namespace std;


 int main() {
  Flight voo{};
  cout << "Done\n";

  Virtual *v = voo.getVirtual(0);
  cout << v->getPyshical(0)->getSensorName() <<endl;
  cout << v->getPyshical(1)->getSensorName() << endl;


  return 0;
}

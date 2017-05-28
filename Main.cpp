#include "Flight.h"
#include <iostream>


using namespace std;


 int main() {
  Flight voo{};
  cout << "Done\n";

  Virtual *v = voo.getVirtual(0);
  cout << v->getPyshical(0)->getSensorName();


  return 0;
}

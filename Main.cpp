#include "Flight.h"
#include <iostream>


using namespace std;


 int main() {
  Flight voo{};
    
  voo.connectSensors();
  usleep(20000);
  voo.sendInformation();

  return 0;
}

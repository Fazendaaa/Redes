#ifndef __FLIGHT__
#define __FLIGHT__

#include "Sensor.h"
#include "Virtual.h"
#include <vector>

using namespace std;

class Flight {
 private:
  vector<Virtual *> sensors{};

 public:
  Flight() {
    generateAllSensors();
  }

  void addSensor(Virtual *sensor) {
   this->sensors.push_back(sensor);
  }

  Virtual * getVirtual(int i){
    return this->sensors[i];
  }

  void generateAllSensors(){
    Sensor sensor1{"termometro","atm"};
    Sensor sensor2{"altimetro","atm"};
    Sensor sensor3{"barometro","atm"};
    Sensor sensor4{"acelerometro","atm"};
    Sensor sensor5{"umidade","atm"};
    Sensor sensor6{"distancia","atm"};
    Sensor sensor7{"visibilidade","atm"};
    Sensor sensor8{"tempo","atm"};
    Sensor sensor9{"turbulencia","atm"};
    Sensor sensor10{"banheiro","atm"};
    Sensor sensor11{"passaros","atm"};
    Sensor sensor12{"trem_de_pouso","atm"};


    Virtual vs1{};
    vs1.addSensor(&sensor1);
    vs1.addSensor(&sensor2);
    vs1.addSensor(&sensor3);
    addSensor(&vs1);

    Virtual vs2{};
    vs2.addSensor(&sensor4);
    vs2.addSensor(&sensor5);
    vs2.addSensor(&sensor6);
    addSensor(&vs2);

    Virtual vs3{};
    vs3.addSensor(&sensor7);
    vs3.addSensor(&sensor8);
    vs3.addSensor(&sensor9);
    addSensor(&vs3);

    Virtual vs4{};
    vs4.addSensor(&sensor10);
    vs4.addSensor(&sensor11);
    vs4.addSensor(&sensor12);
    addSensor(&vs4);
    }







  //Sensor getSensors()  {
  // return this->virtual;
  //}
};


#endif

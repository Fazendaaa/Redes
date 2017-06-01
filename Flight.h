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
    /*Sensor sensor1{"termometro","atm"};
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
    */
    for(int i=0;i<4;i++){
      Virtual *aux = new Virtual();
      this->sensors.push_back(aux);
    }


    this->sensors[0]->addSensor(new Sensor("termometro","atm"));
    this->sensors[0]->addSensor(new Sensor("altimetro","atm"));
    this->sensors[0]->addSensor(new Sensor("barometro","atm"));

    this->sensors[1]->addSensor(new Sensor("acelerometro","atm"));
    this->sensors[1]->addSensor(new Sensor("umidade","atm"));
    this->sensors[1]->addSensor(new Sensor("distancia","atm"));

    this->sensors[2]->addSensor(new Sensor("visibilidade","atm"));
    this->sensors[2]->addSensor(new Sensor("tempo","atm"));
    this->sensors[2]->addSensor(new Sensor("turbulencia","atm"));

    this->sensors[3]->addSensor(new Sensor("banheiro","atm"));
    this->sensors[3]->addSensor(new Sensor("passaros","atm"));
    this->sensors[3]->addSensor(new Sensor("trem_de_pouso","atm"));

    }

    void connectSensors(){
      bool x;
      for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
          Client *aux = this->sensors[i]->getPyshical(j)->getClient();
          string message = this->sensors[i]->getPyshical(j)->getSensorName();
          message = message + "|" + this->sensors[i]->getPyshical(j)->getDataType();
          aux->upload(message);
          //do {
          //  x = aux->upload(message);
          //} while(x);

        }
      }
    }

  //Sensor getSensors()  {
  // return this->virtual;
  //}
};


#endif

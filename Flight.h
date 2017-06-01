#ifndef __FLIGHT__
#define __FLIGHT__

#include "Sensor.h"
#include "Virtual.h"
#include "client.h"
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class Flight {
 private:
  //vector<Virtual *> sensors{};
  vector <Sensor *> sensors{};
  vector <Client *> connection{};

 public:
  Flight() {
    generateAllSensors();

  }

  //void addSensor(Virtual *sensor) {
   //this->sensors.push_back(sensor);
  //}
  void addSensor(Sensor *sensor){
    this->sensors.push_back(sensor);
  }

  void addClient(Client *client){
    this->connection.push_back(client);
  }

//  Virtual * getVirtual(int i){
//    return this->sensors[i];
//  }

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

    this->sensors[1]->addSensor(new Sensor("acelerometro","atm"));
    this->sensors[1]->addSensor(new Sensor("umidade","atm"));
    this->sensors[1]->addSensor(new Sensor("distancia","atm"));
    */
    //for(int i=0;i<4;i++){
    //  Virtual *aux = new Virtual();
    //  this->sensors.push_back(aux);
    //}



    addSensor(new Sensor("termometro","atm"));
    addSensor(new Sensor("altimetro","atm"));
    addSensor(new Sensor("barometro","atm"));

    addSensor(new Sensor("acelerometro","atm"));
    addSensor(new Sensor("umidade","atm"));
    addSensor(new Sensor("distancia","atm"));

    addSensor(new Sensor("visibilidade","atm"));
    addSensor(new Sensor("tempo","atm"));
    addSensor(new Sensor("turbulencia","atm"));

    addSensor(new Sensor("banheiro","atm"));
    addSensor(new Sensor("passaros","atm"));
    addSensor(new Sensor("trem_de_pouso","atm"));

    for(int i=0;i<12;i++){
      addClient(new Client());
    }

    }

    void connectSensors(){
      bool x;
      for(int i=0;i<12;i++){

          Client *aux = this->connection[i];
          string message = this->sensors[i]->getSensorName();
          message = message + "|" + this->sensors[i]->getDataType();
          aux->upload(message);
          //do {
          //  x = aux->upload(message);
          //} while(x);


      }
    }

    void sendInformation(){
      for(int k=0;k<20;k++){
        for(int i=0;i<4;i++){

            Client *aux = this->connection[i];
            string message = this->sensors[i]->getSensorName();
            message = message + "|" + to_string(this->sensors[i]->getSensorValue()) + "\n";
            aux->upload(message);

        }
        usleep(20000);
      }
    }

  /*  void sendInformation(){
      for(int k=0;k<2000;k++){
        for(int i=0;i<4;i++){
          for(int j=0;j<3;j++){
            Client *aux = this->sensors[i]->getPyshical(j)->getClient();
            string message = this->sensors[i]->getPyshical(j)->getSensorName();
            message = message + "|" + to_string(this->sensors[i]->getPyshical(j)->getSensorValue()) + "\n";
            aux->upload(message);
          }
        }
        usleep(20000);
      }
    }*/

  //Sensor getSensors()  {
  // return this->virtual;
  //}
};


#endif

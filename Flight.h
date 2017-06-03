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
  vector <Sensor *> sensors{};
  vector <Client *> connection{};

 public:
  Flight() {
    generateAllSensors();

  }

  void addSensor(Sensor *sensor){
    this->sensors.push_back(sensor);
  }

  void addClient(Client *client){
    this->connection.push_back(client);
  }



  void generateAllSensors(){

    addSensor(new Sensor("termometro","celsius"));
    addSensor(new Sensor("altimetro","pes"));
    addSensor(new Sensor("barometro","mmHg"));

    addSensor(new Sensor("acelerometro","m/s"));
    addSensor(new Sensor("umidade","%"));
    addSensor(new Sensor("distancia","km"));

    addSensor(new Sensor("visibilidade","%"));
    addSensor(new Sensor("tempo","ruim"));
    addSensor(new Sensor("turbulencia","nivel"));

    addSensor(new Sensor("banheiro","ocupado"));
    addSensor(new Sensor("passaros","perigo"));
    addSensor(new Sensor("trem_de_pouso","aberto"));

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

      }
    }

    void sendInformation(){
      for(int k=0;k<24;k++){
        for(int i=0;i<12;i++){
            usleep(200000);
            Client *aux = this->connection[i];
            string message = this->sensors[i]->getSensorName();
            message = message + "|" + to_string(this->sensors[i]->getSensorValue()) + "\n";
            aux->upload(message);
        }
      }
    }

};


#endif

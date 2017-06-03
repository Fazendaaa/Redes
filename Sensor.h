#ifndef __SENSOR__
#define __SENSOR__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
//#include "client.h"

using namespace std;

class Sensor{
	private:
		vector <float> dataValue;	//data
	 	string sensorName;	//sensor name
		string dataType;	//data type
		int value;
		//Client connection{};
	public:
		Sensor(string sensorName,string dataType);
		Sensor();
		int getSensorValue();
		string getSensorName();
		string getDataType();
		int getStoredValue();
		void setValue(int x);
		void setSensor(string,string);
		//Client* getClient();



};

Sensor::Sensor(){
	this->sensorName = "NULL";
	this->dataType = "NULL";
	srand (time(NULL));
}
Sensor::Sensor(string sensorName,string dataType){
	this->sensorName = sensorName;
	this->dataType = dataType;


}
void Sensor::setSensor(string sensorName,string dataType){
	this->sensorName = sensorName;
	this->dataType = dataType;
}

int Sensor::getSensorValue(){

	//termometor, altimetro, barometro, acelerometro, umidade, distancia, visibilidade, tempo, turbulencia.Sensor de banheiro,Sensor de birds

	int x = rand();

		if(this->sensorName == "termometro"){
			x = x % 1000 + 1;
		}
		if(this->sensorName == "altimetro"){
			x = x % 100000 + 1;
		}
		if(this->sensorName == "barometro"){
			x = x % 10 + 1;
		}
		if(this->sensorName == "acelerometro"){
			x = x % 100 + 1;
		}
		if(this->sensorName == "umidade"){
			x = x % 100 + 1;
		}
		if(this->sensorName == "distancia"){
			x = x % 100000 + 1;
		}
		if(this->sensorName == "visibilidade"){
			x = x % 100 + 1;
		}
		if(this->sensorName == "tempo"){
			x = x % 2;
		}
		if(this->sensorName == "turbulencia"){
			x = x % 10 + 1;
		}
		if(this->sensorName == "banheiro"){
			x = x % 2;
		}
		if(this->sensorName == "passaros"){
			x = x % 2;
		}
		if(this->sensorName == "trem_de_pouso"){
			x = x % 2 ;
		}
		setValue(x);

	return x;

}

int Sensor::getStoredValue(){
	return this->value;
}
void Sensor::setValue(int x){
	this->value = x;
}


string Sensor::getSensorName(){

	return this->sensorName;
}

string Sensor::getDataType(){

	return this->dataType;
}

#endif

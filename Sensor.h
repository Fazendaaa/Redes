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
}
Sensor::Sensor(string sensorName,string dataType){
	this->sensorName = sensorName;
	this->dataType = dataType;


}
void Sensor::setSensor(string sensorName,string dataType){
	this->sensorName = sensorName;
	this->dataType = dataType;
}


//Client* Sensor::getClient(){
//	return &this->connection;
//}

int Sensor::getSensorValue(){

	//termometor, altimetro, barometro, acelerometro, umidade, distancia, visibilidade, tempo, turbulencia.Sensor de banheiro,Sensor de birds

	srand (time(NULL));
	int x;

		if(this->sensorName == "termometro"){
			x = rand() % 100 + 1;
		}
		if(this->sensorName == "altimetro"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "barometro"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "acelerometro"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "umidade"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "distancia"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "visibilidade"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "tempo"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "turbulencia"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "banheiro"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "passaros"){
			x = rand() % 10 + 1;
		}
		if(this->sensorName == "trem_de_pouso"){
			x = rand() % 10 + 1;
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





/*int main( ) {

	Sensor teste{"barometro","atm"};
	vector <float> val = teste.getSensorValue();
	cout << teste.getSensorName()<< endl;
	cout << teste.getDataType()<< endl;
	for(int i=0;i<24;i++){

		cout << val[i] << " ";
   	}
	cout << endl;

}*/
#endif

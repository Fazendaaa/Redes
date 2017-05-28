#ifndef __SENSOR__
#define __SENSOR__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Sensor{
	private:
		vector <float> dataValue;	//data
	 	string sensorName;	//sensor name
		string dataType;	//data type
	public:
		Sensor(string sensorName,string dataType);
		vector <float> getSensorValue();
		string getSensorName();
		string getDataType();



};

Sensor::Sensor(string sensorName,string dataType){
	this->sensorName = sensorName;
	this->dataType = dataType;

}

vector <float> Sensor::getSensorValue(){

	//termometor, altimetro, barometro, acelerometro, umidade, distancia, visibilidade, tempo, turbulencia.Sensor de banheiro,Sensor de birds

	srand (time(NULL));

	for(int i=0;i<24;i++){

		if(this->sensorName == "termometro"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "altimetro"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "barometro"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "acelerometro"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "umidade"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "distancia"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "visibilidade"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "tempo"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "turbulencia"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "banheiro"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "passaros"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
		if(this->sensorName == "trem_de_pouso"){
			this->dataValue.push_back(rand() % 10 + 1);
		}
	}

	return this->dataValue;



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

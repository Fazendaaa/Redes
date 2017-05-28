#ifndef __VIRTUAL__
#define __VIRTUAL__


#include <iostream>
#include <vector>
#include "Sensor.h"
using namespace std;

class Virtual {
	private:
		vector<Sensor *> pyshical;

	public:
		Virtual() {

			//for(int i=0; i<3; i++)
				//this->pyshical.push_back(sensors[i]);
		}


		  void addSensor(Sensor *sensor) {
		   this->pyshical.push_back(sensor);
		  }

		Sensor* getPyshical(int i) {
			return this->pyshical[i];
		}
};

#endif

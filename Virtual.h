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
		}


		  void addSensor(Sensor *sensor) {
		   this->pyshical.push_back(sensor);
		  }

		Sensor* getPyshical(int i) {
			return this->pyshical[i];
		}
};

#endif

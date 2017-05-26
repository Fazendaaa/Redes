#include <iostream>
#include <queue>
using namespace std;

class Virtual {
	private:
		queue<Sensor*> pyshical{};

	public:
		Virtual(Sensor *sensors) {
			for(int i=0; i<3; i++)
				this->pyshical.push(sensors[i]);
		}

		Sensor getPyshical const {
			return pyshical;
		}
};

class Flight {
	private:
		queue<Sensor*> sensors{};

	public:
		Flight() {}

		void addSensor(Sensor sensor) const {
			this->sensors.push(sensor);
		}
	
		Sensor getSensors const {
			return this->virtual;		
		}
};



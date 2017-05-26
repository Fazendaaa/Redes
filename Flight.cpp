class Flight {
 private:
  queue<Sensor*> sensors{};

 public:
  Flight() {}

  void addSensor(Sensor sensor) const {
   this->sensors.push(sensor);
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

   addSensor(sensor1);
   addSensor(sensor2);
   addSensor(sensor3);
   addSensor(sensor4);
   addSensor(sensor5);
   addSensor(sensor6);
   addSensor(sensor7);
   addSensor(sensor8);
   addSensor(sensor9);
   addSensor(sensor10);
   addSensor(sensor11);
   addSensor(sensor12);
				
  }
 
  Sensor getSensors const {
   return this->virtual;  
  }
};

double voltageADCVal = 0.0; // read the Vout from voltage divider
double averageVoltageADCVal = 0.0;
double currentSensorADCVal = 0.0;   
double averageCurrentSensorADCVal = 0.0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  //get real time battery voltage value...
  voltageADCVal = analogRead(0);

//  if(voltageADCVal != null){
//    for (int i = 0; i < 150; i++) {
//        voltageADCVal += analogRead(0);
//      }
//    averageVoltageADCVal = voltageADCVal/150;
//    Serial.write("The Voltage ADC value: ");
//    Serial.println(averageVoltageADCVal);
//    Serial.println();
//    delay(1000);
//  }
  
  //getting current sensor value
//  currentSensorADCVal = analogRead(1) - 511;
  for(int i=0; i<150; i++){
    double val = analogRead(1);
    double offsetAdjustedVal = val - 511.5;
    currentSensorADCVal+= offsetAdjustedVal;
  }
  
  averageCurrentSensorADCVal = currentSensorADCVal/150.0;

  if(averageCurrentSensorADCVal<0.0){
    averageCurrentSensorADCVal = 0.0; 
  }
  
  Serial.write("The Current ADC value: ");
  Serial.println(averageCurrentSensorADCVal);
  
  currentSensorADCVal = 0.0;
  averageCurrentSensorADCVal = 0.0;
  
  //Current Sensor ADC value to current value...
  // 1 ADC value = 4.89 mV
  // 4.89 mv = 0.0489A
  // Every ADC step is 4.89mV and 0.0489A
  
  delay(1000);
}

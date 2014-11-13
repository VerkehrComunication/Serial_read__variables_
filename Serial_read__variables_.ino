String inputString = "";
String var1 = "";
String var2 = "";
String var3 = "";
boolean stringComplete = false;

void setup(){
  Serial.begin(9600);
  Serial.println("Ready...");

  inputString.reserve(10);
  var1.reserve(10);
  var2.reserve(10);
  var3.reserve(10);
}

void loop(){
  parseCommand();
}

/*
 En este proceso se realiza la lectura de forma serial 
 entre el Arduino y el Labview, lo que inicializa es cualquier 
 elemento asignado a una salida del Arduino la ejecuta, ejecuta una acción}
 
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

void parseCommand(){
  // print the string when a newline arrives:
  if (stringComplete) {
    inputString.trim();
    //Serial.println(inputString);
   // int separatorIndex = inputString.indexOf(',');
    var1=inputString.substring(0,4);
    var2=inputString.substring(5,6);
    var3=inputString.substring(7,11);
    
  //  Serial.println(separatorIndex);
    Serial.println("V1: "+var1);
    Serial.println("V2: "+var2);
    Serial.println("V3: "+var3);

    // clear the string:
    inputString = "";
    var1 = "";
    var2 = "";
    var3="";
    stringComplete = false;
  }

}






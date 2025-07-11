#include <string.h>

#include <map>


#define LED_PIN 2
#define TIME_UNIT 100
  
std::map<char, String> morse_map = {
  {' ', " "},
  {'a', ".-"},   {'b', "-..."}, {'c', "-.-."}, {'d', "-.."},  {'e', "."},
  {'f', "..-."}, {'g', "--."},  {'h', "...."}, {'i', ".."},   {'j', ".---"},
  {'k', "-.-"},  {'l', ".-.."}, {'m', "--"},   {'n', "-."},   {'o', "---"},
  {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},  {'s', "..."},  {'t', "-"},
  {'u', "..-"},  {'v', "...-"}, {'w', ".--"},  {'x', "-..-"}, {'y', "-.--"},
  {'z', "--.."},
  {'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"}, {'5', "....."},
  {'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."}, {'0', "-----"}
};


void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  }


void bad_bad(String blinker){

  if (blinker == " "){ 
    delay(TIME_UNIT*7);
    Serial.println();
    return;
  }

  for (int i=0; i<blinker.length();  i++){
    digitalWrite(LED_PIN, HIGH);
    
    if (blinker[i] == '.'){
      delay(TIME_UNIT);
    }
  
    if (blinker[i] == '-')
      delay(TIME_UNIT*3);

    digitalWrite(LED_PIN, LOW);
    delay(TIME_UNIT);
  
  }
  delay(TIME_UNIT*3);

}


void loop() {

  Serial.println("Type a message:");

  while (Serial.available() == 0){
   ; 
  }

  String input = Serial.readString();

  for (int i = 0; i < input.length(); i++) {
    input[i] = tolower(input[i]);

    bad_bad(morse_map[input[i]]);
    Serial.print(input[i]);
    
  }


  Serial.println();
}


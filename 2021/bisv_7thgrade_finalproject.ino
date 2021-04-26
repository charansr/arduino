#include <LiquidCrystal.h>
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
int X_pos = 0;
int Y_pos = 0;
int dead = 0;
int win = 0;
char win2 = "n";

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16,2);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

}

void loop() {
  if((X_pos == 5 and Y_pos == 1)or(X_pos == 8 and Y_pos == 0)){
    dead = 1;
  }
  if(dead == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Game Over");
  }else{
    int toggle = digitalRead(SW_pin);
    int X_value = analogRead(X_pin);
    int Y_value = analogRead(Y_pin);
    lcd.clear();
    lcd.setCursor(X_pos, Y_pos);
    lcd.print("@");
    lcd.setCursor(5, 1);
    lcd.print("#");
    lcd.setCursor(8,0);
    lcd.print("#");
    lcd.setCursor(15,0);
    lcd.print("$");
    lcd.setCursor(15,1);
    lcd.print("$");
    Serial.println(toggle);
    Serial.println(X_value);
    Serial.println(Y_value);
    if(X_value >= 550){
      X_pos = X_pos + 1;
    }
    if(X_value <= 400){
      X_pos = X_pos - 1;
    }
    if(Y_value <= 400){
      Y_pos = Y_pos + 1;
    }
    if(Y_value >= 550){
      Y_pos = Y_pos - 1;
    }
    if(X_pos == 15){
    win = 1;
    win2 = "w";
    }
    if((win == 1)or(win2 == "w")){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Victory");
    }
      delay(100);
  }
}
void loop2(){
  int toggle = digitalRead(SW_pin);
  int X_value = analogRead(X_pin);
  int Y_value = analogRead(Y_pin);
  if(X_value >= 550){
    X_pos = X_pos + 1;
  }
  if(X_value <= 400){
    X_pos = X_pos - 1;
  }
  if(Y_value <= 420){
    Y_pos += 1;
  }
  if(Y_value >= 550){
    Y_pos = Y_pos - 1;
  }
}
  

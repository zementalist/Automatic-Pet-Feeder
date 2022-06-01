#include <Servo.h>
Servo s;
int servoPin = 13;
int block_angle = 110;
int feed_angle = 40;
int ir_pin = 8;
bool prev_state_animal_detected = false;

void setup() {
  s.attach(servoPin);
  s.write(block_angle);
  pinMode(ir_pin, INPUT);
}

void loop() {
  int path_is_clear = digitalRead(ir_pin);
  bool animal_detected = ! path_is_clear;
  if(animal_detected && !prev_state_animal_detected) {
    s.write(feed_angle);
    delay(100);
    s.write(block_angle);
  }
  prev_state_animal_detected = animal_detected;
}

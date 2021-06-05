Servo myservo;

int boxHandler(String extra);
int doorHandler(String extra);
int lock = 0;
int unlock = 90;
int servoPin = D6;
int buttonPin = D2;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    myservo.attach(servoPin);
    myservo.write(lock);
    Particle.function("door", doorHandler);
    Particle.function("box", boxHandler);
}

    
void loop() {
    int buttonState = digitalRead(buttonPin);
    
    if(buttonState == LOW){
        Particle.publish("doorbell", "pressed");
        delay(5000);
    }
}

int boxHandler(String extra){
    if(strcmp(extra, "unlock") == 0){
        Particle.publish("box", "unlock");
        return 1;
    }
    if(strcmp(extra, "lock") == 0){
        Particle.publish("box", "lock");
        return 1;
    }
    return 1;
}

int doorHandler(String extra){
    if(strcmp(extra, "unlock") == 0){
        openLock();
        delay(1000);
    }
    else if(strcmp(extra, "lock") == 0){
        lockLock();
        delay(1000);
    }
    return 1;
}

void openLock(){
    Particle.publish("door", "unlock");
    myservo.write(unlock);
}

void lockLock(){
    Particle.publish("door", "lock");
    myservo.write(lock);
}
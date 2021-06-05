Servo myservo;

int servoPin = D4;
void boxHandler(const char *event, const char *data);
int lock = 0;
int unlock = 90;


void setup() {
    myservo.attach(servoPin);
    myservo.write(lock);
    Particle.subscribe("box", boxHandler);
}

void loop() {
}

void boxHandler(const char *event, const char *data){
    if(strcmp(data, "unlock") == 0){
        openLock();
    }
    else if(strcmp(data, "lock") == 0){
        lockLock();
    }
}

void openLock(){
    myservo.write(unlock);
}

void lockLock(){
    myservo.write(lock);
}
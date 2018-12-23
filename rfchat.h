void setup();

void loop();

bool motionDetected(int sensor);

void rfsend();

void rfreceive(); 

void rfstatus();

void printstatus();

void showRssi();

void setdestination();

void setID();

uint16_t retrieveAddress(uint8_t asciiArray[]); 

bool isInteger(uint8_t var); 

void command(uint8_t command); 

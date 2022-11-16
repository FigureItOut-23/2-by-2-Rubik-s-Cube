
#ifndef HEADER_FILE
#define HEADER_FILE

const int TURN_POW = 12;
const int CCW = 90;
const int CW = -90;
const int WACKER_OFFSET = 5;
const int CORNERS_ON_FACE = 4;
const int SENSOR_POWER = 25;

int cur_angle = 0;

//Movement Functions
void rotate(int angle);
void flip();
void hold();
void returnWhacker();
void R(int direction, int* cube);
void B(int direction, int* cube);
void U(int direction, int* cube);
void F(int direction, int* cube);

//Basic Algorithms
void alg1(int* cube);
void alg2(int* cube);
void alg3(int* cube);

//Scanning Functions
void CalibrateColourSensor(int* colour_boundaries_red, int* colour_boundaries_green, int* colour_boundaries_blue);
bool ScanCorner(int* curScan, int compRed, int compGreen, int compBlue);
char* intToColour(int col);

//Case Finding and Execution
int findCase(int* cube);
void orientFace(int* cube);

#endif HEADER_FILE

/// \mainpage Author Information
/// \section Information
///
///     Name:          header.c
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Date:          29-2-2017
///
/// \section doxygen How it works?
///
/// This file will be used by the entire team to define the global variables.

/******************bluetooth.c***********************/
long nLastXmitTimeStamp = nPgmTime;
long nDeltaTime = 0;
const int kMaxSizeOfMessage = 30;
const int INBOX = 5;
int btCmd = 0;

/******************collision.c**********************/
#define front 0
#define left 1
#define right 2
#define back 3

int sensorstate = 0;
int sound = 0;

/*****************linefollower.c********************/
#define RGBMIN 22	//Black
#define RGBMAX 52	//White

#define TOP_SPEED 40
#define LOW_SPEED 5

#define STOP 0

int speed_right = 0;
int speed_left = 0;

/*******************includes************************/
#include "bluetooth.c"
#include "sounds.c"
#include "linefollower.c"
#include "rem.c"
#include "collision.c"

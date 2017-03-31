int speed_right = 0;
int speed_left = 0;
int btCmd = 0;
int sound = 0;

//variables voor bluetooth.c
long nLastXmitTimeStamp = nPgmTime;
long nDeltaTime = 0;
const int kMaxSizeOfMessage = 30;
const int INBOX = 5;

#define front 0
#define left 1
#define right 2

int sensorstate = 0;

#include "bluetooth.c"
#include "rem.c"
#include "sounds.c"
#include "collision.c"
#include "linefollower.c"

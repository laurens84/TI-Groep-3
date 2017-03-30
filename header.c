int speed_right = 25;
int speed_left = 25;
int btCmd=0;

//variables voor bluetooth.c
long nLastXmitTimeStamp = nPgmTime;
long nDeltaTime         = 0;
const int kMaxSizeOfMessage = 30;
const int INBOX = 5;

#include "bluetooth.c"
#include "rem.c"
#include "collision.c"
#include "lijnvolger.c"
#include "OldSensor.c"

/*
	Author: Quentin Hoogwerf
	Starts loop which polls for new message every 100ms. Depending on what message is sent with Bluetooth Android app (available from HU Sharepoint),
	global variable 'btCmd' value is changed:

	Bt message	Variable
	LEFT: 			'L'
	Right:			'R'
	UP:					'U'
	DOWN:				'D'
	FIRE:				 0
	A:					 0
	B:					 0
	C:					 0

*/

#pragma platform(NXT)
	//long nLastXmitTimeStamp = nPgmTime;
	//long nDeltaTime         = 0;
	//const int kMaxSizeOfMessage = 30;
	//const int INBOX = 5;

task bluetooth()
{
  TFileIOResult nBTCmdRdErrorStatus;
  int nSizeOfMessage;
  ubyte nRcvBuffer[kMaxSizeOfMessage];

  while (true)
  {
    // Check to see if a message is available

    nSizeOfMessage = cCmdMessageGetSize(INBOX);

    if (nSizeOfMessage > kMaxSizeOfMessage)
      nSizeOfMessage = kMaxSizeOfMessage;
    if (nSizeOfMessage > 0){
    	nBTCmdRdErrorStatus = cCmdMessageRead(nRcvBuffer, nSizeOfMessage, INBOX);
    	nRcvBuffer[nSizeOfMessage] = '\0';
    	string s = "";
    	stringFromChars(s, (char *) nRcvBuffer);
    	displayCenteredBigTextLine(4, s);
    	if (s == "LEFT"){
    		btCmd = 'L';
    	}else if (s == "RIGHT"){
    		btCmd = 'R';
    	}else if (s == "UP"){
    		btCmd = 'U';
    	}else if (s == "DOWN"){
    		btCmd = 'D';
    	}else{
    		btCmd = 0;
			}
    }
  }
    wait1Msec(100);
  return;
}

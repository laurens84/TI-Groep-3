/*! @file
 \mainpage Author Information
	Author: Quentin Hoogwerf
*/

#pragma platform(NXT)
	//long nLastXmitTimeStamp = nPgmTime;
	//long nDeltaTime         = 0;
	//const int kMaxSizeOfMessage = 30;
	//const int INBOX = 5;

/*! \brief bluetooth
 *
 * Starts loop which polls for new message every 100ms. Depending on what message is sent with
 * Bluetooth Android app (available from HU Sharepoint), global variable 'btCmd' value is changed:
 *
 *	Bt message	Variable
 *	LEFT: 			'L'
 *	Right:			'R'
 *	UP:					'U'
 *	DOWN:				'D'
 *	FIRE:				 [plays a tome to simulate a honking horn]
 *	A:					 0
 *	B:					 0
 *	C:					'C'
 *
 */

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
    	}else if (s == "C"){
    		btCmd = -1;
      }else if (s == "FIRE"){
        playTone(1054, 25);
        s="";
      }else{
    		btCmd = 0;
			}
    }
  }
  eraseDisplay();
  wait1Msec(100);
  return;
}

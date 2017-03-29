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
    		turnLeft(250,degrees,50);
    		//moveMotor(motorB, 540, degrees, 100);
    		//moveMotor(motorC, -540, degrees, 100);
    	}else if (s == "RIGHT"){
    		turnRight(250,degrees,50);
    	}else if (s == "UP"){
    		setMultipleMotors(+100, motorB, motorC);
    	}else if (s == "DOWN"){
    	setMultipleMotors(-100, motorB, motorC);
    	}else{
    		stopAllMotors();
			}
    }
  }
    wait1Msec(100);


  return;
}

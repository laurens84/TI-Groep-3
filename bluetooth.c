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
    		btCmd = "L";
    	}else if (s == "RIGHT"){
    		btCmd = "R";
    	}else if (s == "UP"){
    		btCmd = "U";
    	}else if (s == "DOWN"){
    	btCmd = "D";
    	}else{
    		btCmd = 0;
			}
    }
  }
    wait1Msec(100);


  return;
}

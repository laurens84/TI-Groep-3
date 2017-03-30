// FreSixteenthuency (note)
// Example: A_3 is A in the third octave
// Ash_3 is A# in the third octave
#define C_3 261
#define Csh_3 275
#define D_3 293
#define Dsh_3 310
#define E_3 329
#define F_3 348
#define Fsh_3 370
#define G_3 392
#define Gsh_3 412
#define A_3 440
#define Ash_3 466
#define B_3 496
#define C_4 524
#define Csh_4 555
#define D_4 590
#define Dsh_4 621
#define E_4 656
#define F_4 695
#define Fsh_4 738
#define G_4 788
#define Gsh_4 830
#define A_4 877
#define Ash_4 929
#define B_4 987
#define C_5 1054
#define Csh_5 1104
#define D_5 1188
#define Dsh_5 1251
#define E_5 1322
#define F_5 1401
#define Fsh_5 1488
#define G_5 1590
#define Gsh_5 1646
#define A_5 1770
#define Ash_5 1841
#define B_5 1995
//Duration
#define Dwhole 200
#define Whole 100
#define H 50 //half
#define Q 25 //Quarter
#define E 13
#define Sixteenth 8

void playSecret(int plays){

	int secret[][]=
	{
		{G_5, Sixteenth},
		{Fsh_5, Sixteenth},
		{Dsh_5, Sixteenth},
		{A_4, Sixteenth},
		{Gsh_4, Sixteenth},
		{E_5, Sixteenth},
		{Gsh_5, Sixteenth},
		{C_5, Sixteenth},
	};
	for (int p=0; p<plays;p++){
		for (int i=0; i<8; i++){ //change the "i<n" to the new number of notes in the piece
			playTone(secret[i][0], secret[i][1]);
			while(bSoundActive);
			wait1Msec(20);
		}
	}
}

void playSirene(int plays){

	int sirene[][]=
	{
		{E_4, 100},
		{C_4, 100},
		{E_4, 100},
		{G_3, 100},

	};
	for (int p=0; p<plays;p++){
		for (int i=0; i<4; i++){ //change the "i<n" to the new number of notes in the piece
			playTone(sirene[i][0], sirene[i][1]);
			while(bSoundActive);
			wait1Msec(20);
		}
	}
}
void playTetris(int plays){
	int tetris[][]=
	{
		{E_5, Q},
		{B_4, E},
		{C_5, E},
		{D_5, Q},
		{C_5, E},
		{B_4, E},
		{A_4, Q},
		{A_4,	E},
		{C_5, E},
		{E_5, Q},
		{D_5, E},
		{C_5, E},
		{B_4, Q},
		{B_4, E},
		{C_5, E},
		{D_5, Q},
		{E_5, Q},
		{C_5, Q},
		{A_4, Q},
		{A_4, Q},
		{D_5, H},
		{F_5, E},
		{A_5, Q},
		{G_5, E},
		{F_5, E},
		{E_5, H},
		{C_5, E},
		{E_5, Q},
		{D_5, E},
		{C_5, E},
		{B_4, Q},
		{B_4, E},
		{C_5, E},
		{D_5, Q},
		{E_5, Q},
		{C_5, Q},
		{A_4, Q},
		{A_4, Q},

	};
	for (int p=0; p<plays;p++){
		for (int i=0; i<38; i++){ //change the "i<n" to the new number of notes in the piece
			playTone(tetris[i][0], tetris[i][1]);
			while(bSoundActive);
			wait1Msec(20);
		}
	}
}

  //2e deelD_5, F_5, A_5, G_5, F_5, E_5, C_5, E_5, D_5, C_5, B_4, B_4, C_5, D_5, E_5, C_5, A_4, A_4, _R,


task main()
{
playTetris(1);
}

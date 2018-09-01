//#define N 6
#define BUFSIZE 1024
#define ACTIONSIZE 10

#define MAX 99999
#define MIN -99999
#define DRAW 1000000

#define HASHM 32000000
#define CHILDMAX 288

#define TIMELIMIT 1000

extern int ChkLine[32][5];
extern int ChkLim;

extern int LevelLimit;
extern char id[BUFSIZE];

extern __int64 HashS1[HASHM], HashS2[HASHM];
extern int HashV[HASHM], HashT[HASHM], HashDepth[HASHM], HashCnt[HASHM];
extern int StoneCnt;

extern int StartTime, EndTime;
extern int GameEndChk;
extern int initChk;
extern int iSave, jSave, drSave;

// µ¹ÀÇ »ö
#define NONE -1
#define BLACK 0
#define WHITE 1

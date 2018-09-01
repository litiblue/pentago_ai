#include "const.h"
#include <stdio.h>

void InsertHash (__int64 s1, __int64 s2, int value, int TermChk, int Depth, int Cnt)
{
	int num;
	__int64 k = (s1 ^ (s2 << 27));
	__int64 m = HASHM;
	__int64 m2 = 10;
	int i;
	int tt=0;

	for (i=0; ; i++) {
		num = (k % m + i*(1 + k % m2)) % m;
//		if (++tt >= 5) printf("%d\n", tt);
		if ((HashCnt[num] <= StoneCnt) || (HashS1[num]==s1 && HashS2[num]==s2)) {
			HashS1[num] = s1;
			HashS2[num] = s2;
			HashV[num] = value;
			HashT[num] = TermChk;
			HashDepth[num] = Depth;
			HashCnt[num] = Cnt;
			return;
		}
	}
}

void SearchHash (__int64 s1, __int64 s2, int Depth, int &rType, int &value, int &TermChk)
{
	int num;
	__int64 k = (s1 ^ (s2 << 27));
	__int64 m = HASHM;
	__int64 m2 = 10;
	int i;

	for (i=0; ; i++) {
		num = (k % m + i*(1 + k % m2)) % m;
		if (HashCnt[num] <= StoneCnt) {
			rType = 0;
			return;
		}

		if (HashS1[num]==s1 && HashS2[num]==s2) {
			if (HashDepth[num] == Depth) {
				rType = 1;
				value = HashV[num];
				TermChk = HashT[num];
				return;
			}
			else {
				rType = 2;
				value = HashV[num];
				TermChk = HashT[num];
				return;
			}
		}

		num++;
		if (num >= HASHM) {
			num = 0;
		}
	}
}
/*
#include "const.h"

void ai (__int64 s1, __int64 s2)
{
	int i;

	for (i=0; i<36; i++) {
		if (s1 & ((__int64)1 << i)) continue;
		if (s2 & ((__int64)1 << i)) continue;

		iSave = i;
		jSave = 3;
		drSave = 1;

		break;
	}
}
*/
#include "const.h"
#include "ai.h"
#include "rotate.h"
#include "hash.h"
#include "evaluate.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void renewA (int &Alpha, int value)
{
	if (value > Alpha) {
		Alpha = value;
	}
}

void renewB (int &Beta, int value)
{
	if (value < Beta) {
		Beta = value;
	}
}

void renewS (int &Alpha, int value, int i, int j, int dr)
{
	if (value > Alpha) {
		Alpha = value;
		iSave = i;
		jSave = j;
		drSave = dr;
	}
}

struct Child
{
	__int64 s1;
	__int64 s2;
	int AB;
	int value;
};

struct aiChild
{
	__int64 s1;
	__int64 s2;
	int AB;
	int i;
	int j;
	int dr;
	int value;
};

void AddChild (struct Child Child[CHILDMAX], int &ChildLim, __int64 s1, __int64 s2, int AB, int value)
{
	Child[ChildLim].s1 = s1;
	Child[ChildLim].s2 = s2;
	Child[ChildLim].AB = AB;
	Child[ChildLim].value = value;
	ChildLim++;
}

void aiAddChild (struct aiChild Child[CHILDMAX], int &ChildLim, __int64 s1, __int64 s2, int AB,
				 int i, int j, int dr, int value)
{
	Child[ChildLim].s1 = s1;
	Child[ChildLim].s2 = s2;
	Child[ChildLim].AB = AB;
	Child[ChildLim].i = i;
	Child[ChildLim].j = j;
	Child[ChildLim].dr = dr;
	Child[ChildLim].value = value;
	ChildLim++;
}

int aiChildCompare (const void *a, const void *b)
{
	struct aiChild *aa = (struct aiChild *)a;
	struct aiChild *bb = (struct aiChild *)b;
	int num1, num2;

	num1 = aa->value;
	num2 = bb->value;
	
	if (num1 < num2) {
		return 1;
	}
	else if (num1 == num2) {
		return 0;
	}
	else {
		return -1;
	}
}

int ChildCompareMin (const void *a, const void *b)
{
	struct Child *aa = (struct Child *)a;
	struct Child *bb = (struct Child *)b;
	int num1, num2;

	num1 = aa->value;
	num2 = bb->value;
	
	if (num1 > num2) {
		return 1;
	}
	else if (num1 == num2) {
		return 0;
	}
	else {
		return -1;
	}
}

int ChildCompareMax (const void *a, const void *b)
{
	struct Child *aa = (struct Child *)a;
	struct Child *bb = (struct Child *)b;
	int num1, num2;

	num1 = aa->value;
	num2 = bb->value;

	if (num1 < num2) {
		return 1;
	}
	else if (num1 == num2) {
		return 0;
	}
	else {
		return -1;
	}
}

void Ending (__int64 s1, __int64 s2)
{
	int i, j;
	int cnt1=0, cnt2=0;
	int Alpha = MIN;
	int evalue;

	for (i=0; i<36; i++) {
		if (!(s1 & ((__int64)1 << i)) && !(s2 & ((__int64)1 << i))) {
			iSave = i;
			break;
		}
	}

	for (j=0; j<4; j++) {
		RotateLeft (s1, s2, j);
		evalue = EvaluateState (s1, s2);
		if (evalue == MAX) {
			renewS (Alpha, MAX, iSave, j, 0);
		}
		else if (evalue == MIN) {
			renewS (Alpha, MIN, iSave, j, 0);
		}
		else if (evalue == DRAW) {
			renewS (Alpha, 0, iSave, j, 0);
		}
		else {
			renewS (Alpha, evalue, iSave, j, 0);
		}
		RotateRight (s1, s2, j);

		RotateRight (s1, s2, j);
		evalue = EvaluateState (s1, s2);
		if (evalue == MAX) {
			renewS (Alpha, MAX, iSave, j, 1);
		}
		else if (evalue == MIN) {
			renewS (Alpha, MIN, iSave, j, 1);
		}
		else if (evalue == DRAW) {
			renewS (Alpha, 0, iSave, j, 1);
		}
		else {
			renewS (Alpha, evalue, iSave, j, 1);
		}
		RotateLeft (s1, s2, j);
	}
}

void ai (__int64 s1, __int64 s2)
{
	int i, j, rType, TermChk;
	int hvalue, evalue, fvalue;
	int ChildLim=0;
	
	int Alpha=MIN, Beta=MAX;

	struct aiChild Child[CHILDMAX];

	for (i=0; i<36; i++) {
		if (s1 & ((__int64)1 << i)) continue;
		if (s2 & ((__int64)1 << i)) continue;

		s1 ^= ((__int64)1 << i);

		for (j=0; j<4; j++) {
			if (!initChk) {
				iSave = i;
				jSave = j;
				drSave = 0;
				initChk = 1;
			}

			RotateLeft (s1, s2, j);
			SearchHash (s1, s2, LevelLimit, rType, hvalue, TermChk);
			if (rType == 0) {
				evalue = EvaluateState (s1, s2);

				if (evalue == MAX) {
					renewS (Alpha, MAX, i, j, 0);
					InsertHash (s1, s2, MIN, 1, LevelLimit, StoneCnt+1);
				}
				else if (evalue == MIN) {
					renewS (Alpha, MIN, i, j, 0);
					InsertHash (s1, s2, MIN, 1, LevelLimit, StoneCnt+1);
				}
				else if (evalue == DRAW) {
					renewS (Alpha, 0, i, j, 0);
					InsertHash (s1, s2, 0, 1, LevelLimit, StoneCnt+1);
				}
				else {
					aiAddChild (Child, ChildLim, s1, s2, Beta, i, j, 0, evalue);
				}
			}
			else if (rType == 1) {
				if (TermChk) {
					renewS (Alpha, hvalue, i, j, 0);
				}
				else {
					if (Alpha < hvalue) {
						aiAddChild (Child, ChildLim, s1, s2, hvalue, i, j, 0, hvalue);
					}
				}
			}
			else { // rType == 2
				if (TermChk) {
					renewS (Alpha, hvalue, i, j, 0);
				}
				else {
					aiAddChild (Child, ChildLim, s1, s2, Beta, i, j, 0, hvalue);
				}
			}
			RotateRight (s1, s2, j);
			if (Alpha >= Beta) {
				s1 ^= ((__int64)1 << i);
				goto quit;
			}

			RotateRight (s1, s2, j);
			SearchHash (s1, s2, LevelLimit, rType, hvalue, TermChk);
			if (rType == 0) {
				evalue = EvaluateState (s1, s2);

				if (evalue == MAX) {
					renewS (Alpha, MAX, i, j, 1);
					InsertHash (s1, s2, MAX, 1, LevelLimit, StoneCnt+1);
				}
				else if (evalue == MIN) {
					renewS (Alpha, MIN, i, j, 1);
					InsertHash (s1, s2, MIN, 1, LevelLimit, StoneCnt+1);
				}
				else if (evalue == DRAW) {
					renewS (Alpha, 0, i, j, 1);
					InsertHash (s1, s2, 0, 1, LevelLimit, StoneCnt+1);
				}
				else {
					aiAddChild (Child, ChildLim, s1, s2, Beta, i, j, 1, evalue);
				}
			}
			else if (rType == 1) {
				if (TermChk) {
					renewS (Alpha, hvalue, i, j, 1);
				}
				else {
					if (Alpha < hvalue) {
						aiAddChild (Child, ChildLim, s1, s2, hvalue, i, j, 1, hvalue);
					}
				}
			}
			else { // rType == 2
				if (TermChk) {
					renewS (Alpha, hvalue, i, j, 1);
				}
				else {
					aiAddChild (Child, ChildLim, s1, s2, Beta, i, j, 1, hvalue);
				}
			}
			RotateLeft (s1, s2, j);
			if (Alpha >= Beta) {
				s1 ^= ((__int64)1 << i);
				goto quit;
			}
		}
		s1 ^= ((__int64)1 << i);
	}

	qsort (Child, ChildLim, sizeof(struct aiChild), aiChildCompare);

	for (i=0; i<ChildLim; i++) {
		fvalue = MinFunction (Child[i].s1, Child[i].s2, 1, Alpha, (Child[i].AB<Beta ? Child[i].AB : Beta));
		if (GameEndChk) {
			return;
		}
		InsertHash (Child[i].s1, Child[i].s2, fvalue, 0, LevelLimit, StoneCnt+1);
		renewS (Alpha, fvalue, Child[i].i, Child[i].j, Child[i].dr);

		if (Alpha >= Beta) {
			goto quit;
		}
	}
quit:
	int ii = 1;
	//GetAction (Action);
//	printf("%d\n", Alpha);
}

int MinFunction (__int64 s1, __int64 s2, int level, int Alpha, int Beta)
{
	EndTime = GetTickCount();
	if (EndTime - StartTime > TIMELIMIT) {
		GameEndChk = 1;
		return 0;
	}

	int i, j, rType, TermChk;
	int hvalue, evalue, fvalue;
	int ChildLim=0;

	struct Child Child[CHILDMAX];

	for (i=0; i<36; i++) {
		if (s1 & ((__int64)1 << i)) continue;
		if (s2 & ((__int64)1 << i)) continue;

		s2 ^= ((__int64)1 << i);

		for (j=0; j<4; j++) {

			RotateLeft (s1, s2, j);
			SearchHash (s1, s2, LevelLimit-level, rType, hvalue, TermChk);
			if (rType == 0) {
				evalue = EvaluateState (s1, s2);

				if (evalue == MAX) {
					renewB (Beta, MAX);
					InsertHash (s1, s2, MAX, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == MIN) {
					renewB (Beta, MIN);
					InsertHash (s1, s2, MIN, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == DRAW) {
					renewB (Beta, 0);
					InsertHash (s1, s2, 0, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (level == LevelLimit) {
					renewB (Beta, evalue);
					InsertHash (s1, s2, evalue, 0, LevelLimit-level, StoneCnt+level+1);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Alpha, evalue);
				}
			}
			else if (rType == 1) {
				if (TermChk) {
					renewB (Beta, hvalue);
				}
				else if (level == LevelLimit) {
					renewB (Beta, hvalue);
				}
				else {
					if (hvalue < Beta) {
						AddChild (Child, ChildLim, s1, s2, hvalue, hvalue);
					}
				}
			}
			else { // rType == 2
				if (TermChk) {
					renewB (Beta, hvalue);
				}
				else if (level == LevelLimit) {
					renewB (Beta, hvalue);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Alpha, hvalue);
				}
			}
			RotateRight (s1, s2, j);
			if (Alpha >= Beta) {
				s2 ^= ((__int64)1 << i);
				return Beta;
			}

			RotateRight (s1, s2, j);
			SearchHash (s1, s2, LevelLimit-level, rType, hvalue, TermChk);
			if (rType == 0) {
				evalue = EvaluateState (s1, s2);

				if (evalue == MAX) {
					renewB (Beta, MAX);
					InsertHash (s1, s2, MAX, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == MIN) {
					renewB (Beta, MIN);
					InsertHash (s1, s2, MIN, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == DRAW) {
					renewB (Beta, 0);
					InsertHash (s1, s2, 0, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (level == LevelLimit) {
					renewB (Beta, evalue);
					InsertHash (s1, s2, evalue, 0, LevelLimit-level, StoneCnt+level+1);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Alpha, evalue);
				}
			}
			else if (rType == 1) {
				if (TermChk) {
					renewB (Beta, hvalue);
				}
				else if (level == LevelLimit) {
					renewB (Beta, hvalue);
				}
				else {
					if (hvalue < Beta) {
						AddChild (Child, ChildLim, s1, s2, hvalue, hvalue);
					}
				}
			}
			else { // rType == 2
				if (TermChk) {
					renewB (Beta, hvalue);
				}
				else if (level == LevelLimit) {
					renewB (Beta, hvalue);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Alpha, hvalue);
				}
			}
			RotateLeft (s1, s2, j);
			if (Alpha >= Beta) {
				s2 ^= ((__int64)1 << i);
				return Beta;
			}
		}
		s2 ^= ((__int64)1 << i);
	}

	qsort (Child, ChildLim, sizeof(struct Child), ChildCompareMin);

	for (i=0; i<ChildLim; i++) {
		fvalue = MaxFunction (Child[i].s1, Child[i].s2, level+1, (Child[i].AB>Alpha ? Child[i].AB : Alpha), Beta);
		if (GameEndChk) {
			return 0;
		}
		InsertHash (Child[i].s1, Child[i].s2, fvalue, 0, LevelLimit-level, StoneCnt+level+1);
		renewB (Beta, fvalue);

		if (Alpha >= Beta) {
			return Beta;
		}
	}

	return Beta;
}

int MaxFunction (__int64 s1, __int64 s2, int level, int Alpha, int Beta)
{
	EndTime = GetTickCount();
	if (EndTime - StartTime > TIMELIMIT) {
		GameEndChk = 1;
		return 0;
	}

	int i, j, rType, TermChk;
	int hvalue, evalue, fvalue;
	int ChildLim=0;

	struct Child Child[CHILDMAX];

	for (i=0; i<36; i++) {
		if (s1 & ((__int64)1 << i)) continue;
		if (s2 & ((__int64)1 << i)) continue;

		s1 ^= ((__int64)1 << i);

		for (j=0; j<4; j++) {

			RotateLeft (s1, s2, j);
			SearchHash (s1, s2, LevelLimit-level, rType, hvalue, TermChk);
			if (rType == 0) {
				evalue = EvaluateState (s1, s2);

				if (evalue == MAX) {
					renewA (Alpha, MAX);
					InsertHash (s1, s2, MAX, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == MIN) {
					renewA (Alpha, MIN);
					InsertHash (s1, s2, MIN, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == DRAW) {
					renewA (Alpha, 0);
					InsertHash (s1, s2, 0, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (level == LevelLimit) {
					renewA (Alpha, evalue);
					InsertHash (s1, s2, evalue, 0, LevelLimit-level, StoneCnt+level+1);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Beta, evalue);
				}
			}
			else if (rType == 1) {
				if (TermChk) {
					renewA (Alpha, hvalue);
				}
				else if (level == LevelLimit) {
					renewA (Alpha, hvalue);
				}
				else {
					if (Alpha < hvalue) {
						AddChild (Child, ChildLim, s1, s2, hvalue, hvalue);
					}
				}
			}
			else { // rType == 2
				if (TermChk) {
					renewA (Alpha, hvalue);
				}
				else if (level == LevelLimit) {
					renewA (Alpha, hvalue);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Beta, hvalue);
				}
			}
			RotateRight (s1, s2, j);
			if (Alpha >= Beta) {
				s1 ^= ((__int64)1 << i);
				return Alpha;
			}

			RotateRight (s1, s2, j);
			SearchHash (s1, s2, LevelLimit-level, rType, hvalue, TermChk);
			if (rType == 0) {
				evalue = EvaluateState (s1, s2);

				if (evalue == MAX) {
					renewA (Alpha, MAX);
					InsertHash (s1, s2, MAX, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == MIN) {
					renewA (Alpha, MIN);
					InsertHash (s1, s2, MIN, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (evalue == DRAW) {
					renewA (Alpha, 0);
					InsertHash (s1, s2, 0, 1, LevelLimit-level, StoneCnt+level+1);
				}
				else if (level == LevelLimit) {
					renewA (Alpha, evalue);
					InsertHash (s1, s2, evalue, 0, LevelLimit-level, StoneCnt+level+1);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Beta, evalue);
				}
			}
			else if (rType == 1) {
				if (TermChk) {
					renewA (Alpha, hvalue);
				}
				else if (level == LevelLimit) {
					renewA (Alpha, hvalue);
				}
				else {
					if (Alpha < hvalue) {
						AddChild (Child, ChildLim, s1, s2, hvalue, hvalue);
					}
				}
			}
			else { // rType == 2
				if (TermChk) {
					renewA (Alpha, hvalue);
				}
				else if (level == LevelLimit) {
					renewA (Alpha, hvalue);
				}
				else {
					AddChild (Child, ChildLim, s1, s2, Beta, hvalue);
				}
			}
			RotateLeft (s1, s2, j);
			if (Alpha >= Beta) {
				s1 ^= ((__int64)1 << i);
				return Alpha;
			}
		}
		s1 ^= ((__int64)1 << i);
	}

	qsort (Child, ChildLim, sizeof(struct Child), ChildCompareMax);

	for (i=0; i<ChildLim; i++) {
		fvalue = MinFunction (Child[i].s1, Child[i].s2, level+1, Alpha, (Child[i].AB<Beta ? Child[i].AB : Beta));
		if (GameEndChk) {
			return 0;
		}
		InsertHash (Child[i].s1, Child[i].s2, fvalue, 0, LevelLimit-level, StoneCnt+level+1);
		renewA (Alpha, fvalue);

		if (Alpha >= Beta) {
			return Alpha;
		}
	}

	return Alpha;
}
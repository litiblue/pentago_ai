#include "const.h"

void AddChkLine (int r, int c, int dr, int dc)
{
	int i, j;

	i = ChkLim;
	for (j=0; j<5; j++) {
		ChkLine[i][j] = r * 6 + c;
		r += dr;
		c += dc;
	}
	ChkLim++;
}

void MakeChkLine (void)
{
	int r, c;

	for (r=0; r<6; r++)
		for (c=0; c<=1; c++)
			AddChkLine (r, c, 0, 1);
	for (r=0; r<=1; r++)
		for (c=0; c<6; c++)
			AddChkLine (r, c, 1, 0);
	for (r=0; r<=1; r++)
		for (c=0; c<=1; c++)
			AddChkLine (r, c, 1, 1);
	for (r=4; r<=5; r++)
		for (c=0; c<=1; c++)
			AddChkLine (r, c, -1, 1);
}
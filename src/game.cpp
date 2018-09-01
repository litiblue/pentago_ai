#include <string.h>
#include <stdio.h>

#include "const.h"
#include "rotate.h"

void StateToS (int state[6][6], __int64 &s1, __int64 &s2)
{
	int r, c, num;

	for (r=0; r<6; r++) {
		for (c=0; c<6; c++) {
			num = r * 6 + c;
			if (state[r][c] == BLACK) {
				s2 ^= ((__int64)1 << num);
			}
			else if (state[r][c] == WHITE) {
				s1 ^= ((__int64)1 << num);
			}
		}
	}

}
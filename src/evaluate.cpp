#include "const.h"

int EvaluateState (__int64 s1, __int64 s2)
{
	int i, j, num;
	int cnt1, cnt2;
	int wchk=0, lchk=0, value=0;

	for (i=0; i<32; i++) {
		cnt1 = 0;
		cnt2 = 0;
		for (j=0; j<5; j++) {
			num = ChkLine[i][j];
			if (s1 & ((__int64)1 << num)) {
				cnt1++;
			}
			if (s2 & ((__int64)1 << num)) {
				cnt2++;
			}
		}
		
		if (cnt1 == 5) {
			wchk = 1;
		}
		else if (cnt2 == 5) {
			lchk = 1;
		}
		else {
			if (cnt2 == 0) {
				value++;
			}
			if (cnt1 == 0) {
				value--;
			}
		}
	}


	if ( !(s2 & ((__int64)1 << 0)) && !(s2 & ((__int64)1 << 5))
		&& (s1 & ((__int64)1 << 1)) && (s1 & ((__int64)1 << 2))
		&& (s1 & ((__int64)1 << 3)) && (s1 & ((__int64)1 << 4)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 6)) && !(s2 & ((__int64)1 << 11))
		&& (s1 & ((__int64)1 << 7)) && (s1 & ((__int64)1 << 8))
		&& (s1 & ((__int64)1 << 9)) && (s1 & ((__int64)1 << 10)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 12)) && !(s2 & ((__int64)1 << 17))
		&& (s1 & ((__int64)1 << 13)) && (s1 & ((__int64)1 << 14))
		&& (s1 & ((__int64)1 << 15)) && (s1 & ((__int64)1 << 16)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 18)) && !(s2 & ((__int64)1 << 23))
		&& (s1 & ((__int64)1 << 19)) && (s1 & ((__int64)1 << 20))
		&& (s1 & ((__int64)1 << 21)) && (s1 & ((__int64)1 << 22)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 24)) && !(s2 & ((__int64)1 << 29))
		&& (s1 & ((__int64)1 << 25)) && (s1 & ((__int64)1 << 26))
		&& (s1 & ((__int64)1 << 27)) && (s1 & ((__int64)1 << 28)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 30)) && !(s2 & ((__int64)1 << 35))
		&& (s1 & ((__int64)1 << 31)) && (s1 & ((__int64)1 << 32))
		&& (s1 & ((__int64)1 << 33)) && (s1 & ((__int64)1 << 34)) ) {
			wchk = 1;
	}

	if ( !(s2 & ((__int64)1 << 0)) && !(s2 & ((__int64)1 << 30))
		&& (s1 & ((__int64)1 << 6)) && (s1 & ((__int64)1 << 12))
		&& (s1 & ((__int64)1 << 18)) && (s1 & ((__int64)1 << 24)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 1)) && !(s2 & ((__int64)1 << 31))
		&& (s1 & ((__int64)1 << 7)) && (s1 & ((__int64)1 << 13))
		&& (s1 & ((__int64)1 << 19)) && (s1 & ((__int64)1 << 25)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 2)) && !(s2 & ((__int64)1 << 32))
		&& (s1 & ((__int64)1 << 8)) && (s1 & ((__int64)1 << 14))
		&& (s1 & ((__int64)1 << 20)) && (s1 & ((__int64)1 << 26)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 3)) && !(s2 & ((__int64)1 << 33))
		&& (s1 & ((__int64)1 << 9)) && (s1 & ((__int64)1 << 15))
		&& (s1 & ((__int64)1 << 21)) && (s1 & ((__int64)1 << 27)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 4)) && !(s2 & ((__int64)1 << 34))
		&& (s1 & ((__int64)1 << 10)) && (s1 & ((__int64)1 << 16))
		&& (s1 & ((__int64)1 << 22)) && (s1 & ((__int64)1 << 28)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 5)) && !(s2 & ((__int64)1 << 35))
		&& (s1 & ((__int64)1 << 11)) && (s1 & ((__int64)1 << 17))
		&& (s1 & ((__int64)1 << 23)) && (s1 & ((__int64)1 << 29)) ) {
			wchk = 1;
	}

	if ( !(s2 & ((__int64)1 << 0)) && !(s2 & ((__int64)1 << 35))
		&& (s1 & ((__int64)1 << 7)) && (s1 & ((__int64)1 << 14))
		&& (s1 & ((__int64)1 << 21)) && (s1 & ((__int64)1 << 28)) ) {
			wchk = 1;
	}
	if ( !(s2 & ((__int64)1 << 5)) && !(s2 & ((__int64)1 << 30))
		&& (s1 & ((__int64)1 << 10)) && (s1 & ((__int64)1 << 15))
		&& (s1 & ((__int64)1 << 20)) && (s1 & ((__int64)1 << 25)) ) {
			wchk = 1;
	}

//
	if ( !(s1 & ((__int64)1 << 0)) && !(s1 & ((__int64)1 << 5))
		&& (s2 & ((__int64)1 << 1)) && (s2 & ((__int64)1 << 2))
		&& (s2 & ((__int64)1 << 3)) && (s2 & ((__int64)1 << 4)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 6)) && !(s1 & ((__int64)1 << 11))
		&& (s2 & ((__int64)1 << 7)) && (s2 & ((__int64)1 << 8))
		&& (s2 & ((__int64)1 << 9)) && (s2 & ((__int64)1 << 10)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 12)) && !(s1 & ((__int64)1 << 17))
		&& (s2 & ((__int64)1 << 13)) && (s2 & ((__int64)1 << 14))
		&& (s2 & ((__int64)1 << 15)) && (s2 & ((__int64)1 << 16)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 18)) && !(s1 & ((__int64)1 << 23))
		&& (s2 & ((__int64)1 << 19)) && (s2 & ((__int64)1 << 20))
		&& (s2 & ((__int64)1 << 21)) && (s2 & ((__int64)1 << 22)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 24)) && !(s1 & ((__int64)1 << 29))
		&& (s2 & ((__int64)1 << 25)) && (s2 & ((__int64)1 << 26))
		&& (s2 & ((__int64)1 << 27)) && (s2 & ((__int64)1 << 28)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 30)) && !(s1 & ((__int64)1 << 35))
		&& (s2 & ((__int64)1 << 31)) && (s2 & ((__int64)1 << 32))
		&& (s2 & ((__int64)1 << 33)) && (s2 & ((__int64)1 << 34)) ) {
			lchk = 1;
	}

	if ( !(s1 & ((__int64)1 << 0)) && !(s1 & ((__int64)1 << 30))
		&& (s2 & ((__int64)1 << 6)) && (s2 & ((__int64)1 << 12))
		&& (s2 & ((__int64)1 << 18)) && (s2 & ((__int64)1 << 24)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 1)) && !(s1 & ((__int64)1 << 31))
		&& (s2 & ((__int64)1 << 7)) && (s2 & ((__int64)1 << 13))
		&& (s2 & ((__int64)1 << 19)) && (s2 & ((__int64)1 << 25)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 2)) && !(s1 & ((__int64)1 << 32))
		&& (s2 & ((__int64)1 << 8)) && (s2 & ((__int64)1 << 14))
		&& (s2 & ((__int64)1 << 20)) && (s2 & ((__int64)1 << 26)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 3)) && !(s1 & ((__int64)1 << 33))
		&& (s2 & ((__int64)1 << 9)) && (s2 & ((__int64)1 << 15))
		&& (s2 & ((__int64)1 << 21)) && (s2 & ((__int64)1 << 27)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 4)) && !(s1 & ((__int64)1 << 34))
		&& (s2 & ((__int64)1 << 10)) && (s2 & ((__int64)1 << 16))
		&& (s2 & ((__int64)1 << 22)) && (s2 & ((__int64)1 << 28)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 5)) && !(s1 & ((__int64)1 << 35))
		&& (s2 & ((__int64)1 << 11)) && (s2 & ((__int64)1 << 17))
		&& (s2 & ((__int64)1 << 23)) && (s2 & ((__int64)1 << 29)) ) {
			lchk = 1;
	}

	if ( !(s1 & ((__int64)1 << 0)) && !(s1 & ((__int64)1 << 35))
		&& (s2 & ((__int64)1 << 7)) && (s2 & ((__int64)1 << 14))
		&& (s2 & ((__int64)1 << 21)) && (s2 & ((__int64)1 << 28)) ) {
			lchk = 1;
	}
	if ( !(s1 & ((__int64)1 << 5)) && !(s1 & ((__int64)1 << 30))
		&& (s2 & ((__int64)1 << 10)) && (s2 & ((__int64)1 << 15))
		&& (s2 & ((__int64)1 << 20)) && (s2 & ((__int64)1 << 25)) ) {
			lchk = 1;
	}

	if (wchk) {
		if (lchk) {
			return DRAW;
		}
		else {
			return MAX;
		}
	}
	else {
		if (lchk) {
			return MIN;
		}
		else {
			return value;
		}
	}

}
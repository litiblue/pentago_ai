void RotateLeft (__int64 &s1, __int64 &s2, int j)
{
	__int64 t1=0, t2=0;

	if (j < 2) {
		if (j == 0) {
			t1 = s1;

			s1 ^= (((__int64)1 <<  0) & s1);
			s1 ^= (((__int64)1 <<  1) & s1);
			s1 ^= (((__int64)1 <<  2) & s1);
			s1 ^= (((__int64)1 <<  6) & s1);
			s1 ^= (((__int64)1 <<  7) & s1);
			s1 ^= (((__int64)1 <<  8) & s1);
			s1 ^= (((__int64)1 << 12) & s1);
			s1 ^= (((__int64)1 << 13) & s1);
			s1 ^= (((__int64)1 << 14) & s1);

			s1 |= ((t1 & ((__int64)1 <<  2)) >>  2);
			s1 |= ((t1 & ((__int64)1 <<  8)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 14)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 13)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 12)) <<  2);
			s1 |= ((t1 & ((__int64)1 <<  6)) <<  7);
			s1 |= ((t1 & ((__int64)1 <<  0)) << 12);
			s1 |= ((t1 & ((__int64)1 <<  1)) <<  5);
			s1 |=  (t1 & ((__int64)1 <<  7));


			t2 = s2;

			s2 ^= (((__int64)1 <<  0) & s2);
			s2 ^= (((__int64)1 <<  1) & s2);
			s2 ^= (((__int64)1 <<  2) & s2);
			s2 ^= (((__int64)1 <<  6) & s2);
			s2 ^= (((__int64)1 <<  7) & s2);
			s2 ^= (((__int64)1 <<  8) & s2);
			s2 ^= (((__int64)1 << 12) & s2);
			s2 ^= (((__int64)1 << 13) & s2);
			s2 ^= (((__int64)1 << 14) & s2);

			s2 |= ((t2 & ((__int64)1 <<  2)) >>  2);
			s2 |= ((t2 & ((__int64)1 <<  8)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 14)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 13)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 12)) <<  2);
			s2 |= ((t2 & ((__int64)1 <<  6)) <<  7);
			s2 |= ((t2 & ((__int64)1 <<  0)) << 12);
			s2 |= ((t2 & ((__int64)1 <<  1)) <<  5);
			s2 |=  (t2 & ((__int64)1 <<  7));
		}
		else/*if(j == 1)*/{
			t1 = s1;

			s1 ^= (((__int64)1 <<  3) & s1);
			s1 ^= (((__int64)1 <<  4) & s1);
			s1 ^= (((__int64)1 <<  5) & s1);
			s1 ^= (((__int64)1 <<  9) & s1);
			s1 ^= (((__int64)1 << 10) & s1);
			s1 ^= (((__int64)1 << 11) & s1);
			s1 ^= (((__int64)1 << 15) & s1);
			s1 ^= (((__int64)1 << 16) & s1);
			s1 ^= (((__int64)1 << 17) & s1);

			s1 |= ((t1 & ((__int64)1 <<  5)) >>  2);
			s1 |= ((t1 & ((__int64)1 << 11)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 17)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 16)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 15)) <<  2);
			s1 |= ((t1 & ((__int64)1 <<  9)) <<  7);
			s1 |= ((t1 & ((__int64)1 <<  3)) << 12);
			s1 |= ((t1 & ((__int64)1 <<  4)) <<  5);
			s1 |=  (t1 & ((__int64)1 << 10));


			t2 = s2;

			s2 ^= (((__int64)1 <<  3) & s2);
			s2 ^= (((__int64)1 <<  4) & s2);
			s2 ^= (((__int64)1 <<  5) & s2);
			s2 ^= (((__int64)1 <<  9) & s2);
			s2 ^= (((__int64)1 << 10) & s2);
			s2 ^= (((__int64)1 << 11) & s2);
			s2 ^= (((__int64)1 << 15) & s2);
			s2 ^= (((__int64)1 << 16) & s2);
			s2 ^= (((__int64)1 << 17) & s2);

			s2 |= ((t2 & ((__int64)1 <<  5)) >>  2);
			s2 |= ((t2 & ((__int64)1 << 11)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 17)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 16)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 15)) <<  2);
			s2 |= ((t2 & ((__int64)1 <<  9)) <<  7);
			s2 |= ((t2 & ((__int64)1 <<  3)) << 12);
			s2 |= ((t2 & ((__int64)1 <<  4)) <<  5);
			s2 |=  (t2 & ((__int64)1 << 10));
		}
	}
	else/*if(j >= 2)*/{
		if (j == 2) {
			t1 = s1;

			s1 ^= (((__int64)1 << 18) & s1);
			s1 ^= (((__int64)1 << 19) & s1);
			s1 ^= (((__int64)1 << 20) & s1);
			s1 ^= (((__int64)1 << 24) & s1);
			s1 ^= (((__int64)1 << 25) & s1);
			s1 ^= (((__int64)1 << 26) & s1);
			s1 ^= (((__int64)1 << 30) & s1);
			s1 ^= (((__int64)1 << 31) & s1);
			s1 ^= (((__int64)1 << 32) & s1);

			s1 |= ((t1 & ((__int64)1 << 20)) >>  2);
			s1 |= ((t1 & ((__int64)1 << 26)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 32)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 31)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 30)) <<  2);
			s1 |= ((t1 & ((__int64)1 << 24)) <<  7);
			s1 |= ((t1 & ((__int64)1 << 18)) << 12);
			s1 |= ((t1 & ((__int64)1 << 19)) <<  5);
			s1 |=  (t1 & ((__int64)1 << 25));


			t2 = s2;

			s2 ^= (((__int64)1 << 18) & s2);
			s2 ^= (((__int64)1 << 19) & s2);
			s2 ^= (((__int64)1 << 20) & s2);
			s2 ^= (((__int64)1 << 24) & s2);
			s2 ^= (((__int64)1 << 25) & s2);
			s2 ^= (((__int64)1 << 26) & s2);
			s2 ^= (((__int64)1 << 30) & s2);
			s2 ^= (((__int64)1 << 31) & s2);
			s2 ^= (((__int64)1 << 32) & s2);

			s2 |= ((t2 & ((__int64)1 << 20)) >>  2);
			s2 |= ((t2 & ((__int64)1 << 26)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 32)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 31)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 30)) <<  2);
			s2 |= ((t2 & ((__int64)1 << 24)) <<  7);
			s2 |= ((t2 & ((__int64)1 << 18)) << 12);
			s2 |= ((t2 & ((__int64)1 << 19)) <<  5);
			s2 |=  (t2 & ((__int64)1 << 25));
		}
		else/*if(j == 3)*/{
			t1 = s1;

			s1 ^= (((__int64)1 << 21) & s1);
			s1 ^= (((__int64)1 << 22) & s1);
			s1 ^= (((__int64)1 << 23) & s1);
			s1 ^= (((__int64)1 << 27) & s1);
			s1 ^= (((__int64)1 << 28) & s1);
			s1 ^= (((__int64)1 << 29) & s1);
			s1 ^= (((__int64)1 << 33) & s1);
			s1 ^= (((__int64)1 << 34) & s1);
			s1 ^= (((__int64)1 << 35) & s1);

			s1 |= ((t1 & ((__int64)1 << 23)) >>  2);
			s1 |= ((t1 & ((__int64)1 << 29)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 35)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 34)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 33)) <<  2);
			s1 |= ((t1 & ((__int64)1 << 27)) <<  7);
			s1 |= ((t1 & ((__int64)1 << 21)) << 12);
			s1 |= ((t1 & ((__int64)1 << 22)) <<  5);
			s1 |=  (t1 & ((__int64)1 << 28));


			t2 = s2;

			s2 ^= (((__int64)1 << 21) & s2);
			s2 ^= (((__int64)1 << 22) & s2);
			s2 ^= (((__int64)1 << 23) & s2);
			s2 ^= (((__int64)1 << 27) & s2);
			s2 ^= (((__int64)1 << 28) & s2);
			s2 ^= (((__int64)1 << 29) & s2);
			s2 ^= (((__int64)1 << 33) & s2);
			s2 ^= (((__int64)1 << 34) & s2);
			s2 ^= (((__int64)1 << 35) & s2);

			s2 |= ((t2 & ((__int64)1 << 23)) >>  2);
			s2 |= ((t2 & ((__int64)1 << 29)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 35)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 34)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 33)) <<  2);
			s2 |= ((t2 & ((__int64)1 << 27)) <<  7);
			s2 |= ((t2 & ((__int64)1 << 21)) << 12);
			s2 |= ((t2 & ((__int64)1 << 22)) <<  5);
			s2 |=  (t2 & ((__int64)1 << 28));
		}
	}
	
}

void RotateRight (__int64 &s1, __int64 &s2, int j)
{
	__int64 t1=0, t2=0;

	if (j < 2) {
		if (j == 0) {
			t1 = s1;

			s1 ^= (((__int64)1 <<  0) & s1);
			s1 ^= (((__int64)1 <<  1) & s1);
			s1 ^= (((__int64)1 <<  2) & s1);
			s1 ^= (((__int64)1 <<  6) & s1);
			s1 ^= (((__int64)1 <<  7) & s1);
			s1 ^= (((__int64)1 <<  8) & s1);
			s1 ^= (((__int64)1 << 12) & s1);
			s1 ^= (((__int64)1 << 13) & s1);
			s1 ^= (((__int64)1 << 14) & s1);

			s1 |= ((t1 & ((__int64)1 <<  0)) <<  2);
			s1 |= ((t1 & ((__int64)1 <<  6)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 12)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 13)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 14)) >>  2);
			s1 |= ((t1 & ((__int64)1 <<  8)) <<  5);
			s1 |= ((t1 & ((__int64)1 <<  2)) << 12);
			s1 |= ((t1 & ((__int64)1 <<  1)) <<  7);
			s1 |=  (t1 & ((__int64)1 <<  7));


			t2 = s2;

			s2 ^= (((__int64)1 <<  0) & s2);
			s2 ^= (((__int64)1 <<  1) & s2);
			s2 ^= (((__int64)1 <<  2) & s2);
			s2 ^= (((__int64)1 <<  6) & s2);
			s2 ^= (((__int64)1 <<  7) & s2);
			s2 ^= (((__int64)1 <<  8) & s2);
			s2 ^= (((__int64)1 << 12) & s2);
			s2 ^= (((__int64)1 << 13) & s2);
			s2 ^= (((__int64)1 << 14) & s2);

			s2 |= ((t2 & ((__int64)1 <<  0)) <<  2);
			s2 |= ((t2 & ((__int64)1 <<  6)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 12)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 13)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 14)) >>  2);
			s2 |= ((t2 & ((__int64)1 <<  8)) <<  5);
			s2 |= ((t2 & ((__int64)1 <<  2)) << 12);
			s2 |= ((t2 & ((__int64)1 <<  1)) <<  7);
			s2 |=  (t2 & ((__int64)1 <<  7));
		}
		else/*if(j == 1)*/{
			t1 = s1;

			s1 ^= (((__int64)1 <<  3) & s1);
			s1 ^= (((__int64)1 <<  4) & s1);
			s1 ^= (((__int64)1 <<  5) & s1);
			s1 ^= (((__int64)1 <<  9) & s1);
			s1 ^= (((__int64)1 << 10) & s1);
			s1 ^= (((__int64)1 << 11) & s1);
			s1 ^= (((__int64)1 << 15) & s1);
			s1 ^= (((__int64)1 << 16) & s1);
			s1 ^= (((__int64)1 << 17) & s1);

			s1 |= ((t1 & ((__int64)1 <<  3)) <<  2);
			s1 |= ((t1 & ((__int64)1 <<  9)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 15)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 16)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 17)) >>  2);
			s1 |= ((t1 & ((__int64)1 << 11)) <<  5);
			s1 |= ((t1 & ((__int64)1 <<  5)) << 12);
			s1 |= ((t1 & ((__int64)1 <<  4)) <<  7);
			s1 |=  (t1 & ((__int64)1 << 10));


			t2 = s2;

			s2 ^= (((__int64)1 <<  3) & s2);
			s2 ^= (((__int64)1 <<  4) & s2);
			s2 ^= (((__int64)1 <<  5) & s2);
			s2 ^= (((__int64)1 <<  9) & s2);
			s2 ^= (((__int64)1 << 10) & s2);
			s2 ^= (((__int64)1 << 11) & s2);
			s2 ^= (((__int64)1 << 15) & s2);
			s2 ^= (((__int64)1 << 16) & s2);
			s2 ^= (((__int64)1 << 17) & s2);

			s2 |= ((t2 & ((__int64)1 <<  3)) <<  2);
			s2 |= ((t2 & ((__int64)1 <<  9)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 15)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 16)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 17)) >>  2);
			s2 |= ((t2 & ((__int64)1 << 11)) <<  5);
			s2 |= ((t2 & ((__int64)1 <<  5)) << 12);
			s2 |= ((t2 & ((__int64)1 <<  4)) <<  7);
			s2 |=  (t2 & ((__int64)1 << 10));
		}
	}
	else/*if(j >= 2)*/{
		if (j == 2) {
			t1 = s1;

			s1 ^= (((__int64)1 << 18) & s1);
			s1 ^= (((__int64)1 << 19) & s1);
			s1 ^= (((__int64)1 << 20) & s1);
			s1 ^= (((__int64)1 << 24) & s1);
			s1 ^= (((__int64)1 << 25) & s1);
			s1 ^= (((__int64)1 << 26) & s1);
			s1 ^= (((__int64)1 << 30) & s1);
			s1 ^= (((__int64)1 << 31) & s1);
			s1 ^= (((__int64)1 << 32) & s1);

			s1 |= ((t1 & ((__int64)1 << 18)) <<  2);
			s1 |= ((t1 & ((__int64)1 << 24)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 30)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 31)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 32)) >>  2);
			s1 |= ((t1 & ((__int64)1 << 26)) <<  5);
			s1 |= ((t1 & ((__int64)1 << 20)) << 12);
			s1 |= ((t1 & ((__int64)1 << 19)) <<  7);
			s1 |=  (t1 & ((__int64)1 << 25));

			
			t2 = s2;

			s2 ^= (((__int64)1 << 18) & s2);
			s2 ^= (((__int64)1 << 19) & s2);
			s2 ^= (((__int64)1 << 20) & s2);
			s2 ^= (((__int64)1 << 24) & s2);
			s2 ^= (((__int64)1 << 25) & s2);
			s2 ^= (((__int64)1 << 26) & s2);
			s2 ^= (((__int64)1 << 30) & s2);
			s2 ^= (((__int64)1 << 31) & s2);
			s2 ^= (((__int64)1 << 32) & s2);

			s2 |= ((t2 & ((__int64)1 << 18)) <<  2);
			s2 |= ((t2 & ((__int64)1 << 24)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 30)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 31)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 32)) >>  2);
			s2 |= ((t2 & ((__int64)1 << 26)) <<  5);
			s2 |= ((t2 & ((__int64)1 << 20)) << 12);
			s2 |= ((t2 & ((__int64)1 << 19)) <<  7);
			s2 |=  (t2 & ((__int64)1 << 25));
		}
		else/*if(j == 3)*/{
			t1 = s1;

			s1 ^= (((__int64)1 << 21) & s1);
			s1 ^= (((__int64)1 << 22) & s1);
			s1 ^= (((__int64)1 << 23) & s1);
			s1 ^= (((__int64)1 << 27) & s1);
			s1 ^= (((__int64)1 << 28) & s1);
			s1 ^= (((__int64)1 << 29) & s1);
			s1 ^= (((__int64)1 << 33) & s1);
			s1 ^= (((__int64)1 << 34) & s1);
			s1 ^= (((__int64)1 << 35) & s1);

			s1 |= ((t1 & ((__int64)1 << 21)) <<  2);
			s1 |= ((t1 & ((__int64)1 << 27)) >>  5);
			s1 |= ((t1 & ((__int64)1 << 33)) >> 12);
			s1 |= ((t1 & ((__int64)1 << 34)) >>  7);
			s1 |= ((t1 & ((__int64)1 << 35)) >>  2);
			s1 |= ((t1 & ((__int64)1 << 29)) <<  5);
			s1 |= ((t1 & ((__int64)1 << 23)) << 12);
			s1 |= ((t1 & ((__int64)1 << 22)) <<  7);
			s1 |=  (t1 & ((__int64)1 << 28));


		t2 = s2;

			s2 ^= (((__int64)1 << 21) & s2);
			s2 ^= (((__int64)1 << 22) & s2);
			s2 ^= (((__int64)1 << 23) & s2);
			s2 ^= (((__int64)1 << 27) & s2);
			s2 ^= (((__int64)1 << 28) & s2);
			s2 ^= (((__int64)1 << 29) & s2);
			s2 ^= (((__int64)1 << 33) & s2);
			s2 ^= (((__int64)1 << 34) & s2);
			s2 ^= (((__int64)1 << 35) & s2);

			s2 |= ((t2 & ((__int64)1 << 21)) <<  2);
			s2 |= ((t2 & ((__int64)1 << 27)) >>  5);
			s2 |= ((t2 & ((__int64)1 << 33)) >> 12);
			s2 |= ((t2 & ((__int64)1 << 34)) >>  7);
			s2 |= ((t2 & ((__int64)1 << 35)) >>  2);
			s2 |= ((t2 & ((__int64)1 << 29)) <<  5);
			s2 |= ((t2 & ((__int64)1 << 23)) << 12);
			s2 |= ((t2 & ((__int64)1 << 22)) <<  7);
			s2 |=  (t2 & ((__int64)1 << 28));
		}
	}
}
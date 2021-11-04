#include<iostream>
#include "gmp.h"
#pragma comment(lib,"libgmp-10.lib")

void expmod(mpz_t a, mpz_t paraE, mpz_t paraN) {
	mpz_t e, n, eBack, aPow,temp;
	mpz_init_set(e, paraE);
	mpz_init_set(n, paraN);
	mpz_init_set(eBack, e);
	mpz_init_set(aPow, a);
	mpz_init(temp);
	mpz_set_ui(a, 1);
	mpz_mod_ui(temp, eBack, 2);	
	while (mpz_cmp_ui(eBack, 0) != 0) {	
		if (mpz_cmp_ui(temp, 1) == 0) {		
			mpz_mul(a, a, aPow);
			mpz_mod(a, a, n);
		}
#ifdef DEBUG
		gmp_printf("a = %Zd\n", a);
		gmp_printf("temp = %Zd\n", temp);
		gmp_printf("aPow = %Zd\n", aPow);
		gmp_printf("eBack = %Zd\n", eBack);
#endif // DEBUG

		mpz_mul(aPow, aPow, aPow);		
		mpz_mod(aPow, aPow, n);
		mpz_div_ui(eBack, eBack, 2);
		mpz_mod_ui(temp, eBack, 2);	
	}
}
void ChineseRemainderTheorem(mpz_t paraB1, mpz_t paraB2, mpz_t paraM1, mpz_t paraM2) {
	mpz_t b1, b2, m1, m2, m, m1Inverse, m2Inverse;
    mpz_t c;
    mpz_init(c);
    mpz_init_set_si(c,-1);
	mpz_init_set(b1, paraB1);
	mpz_init_set(b2, paraB2);
	mpz_init_set(m1, paraM1);
	mpz_init_set(m2, paraM2);
	mpz_init(m1Inverse);
	mpz_init(m2Inverse);
	mpz_init(m);
	mpz_mul(m, m1, m2);
	mpz_powm(m1Inverse,m1,c,m2);
	mpz_powm(m2Inverse,m2,c,m1);

    //calInverse(m1Inverse, m1, m2);
	//calInverse(m2Inverse, m2, m1);
	mpz_mul(b1, b1, m2);
	mpz_mul(b1, b1, m2Inverse);
	mpz_mul(b2, b2, m1);
	mpz_mul(b2, b2, m1Inverse);
	mpz_add(b1, b1, b2);
	mpz_mod(b1, b1, m);
	gmp_printf("%Zd\n", b1);
}
using namespace std;
int main() {
	int n;
	mpz_t e, m, p, q, b1, b2;
	mpz_init(e);
	mpz_init(m);
	mpz_init(p);
	mpz_init(q);
	mpz_init(b1);
	mpz_init(b2);
	cin >> n;
	for (int i = 0; i < n; i++) {
		gmp_scanf("%Zd%Zd%Zd%Zd", e, m, p, q);
		mpz_set(b1, m);
		mpz_set(b2, m);
		expmod(b1, e, p);
		expmod(b2, e, q);
		ChineseRemainderTheorem(b1, b2, p, q);
	}
	return 0;
}
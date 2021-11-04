#include<iostream>
#include<stack>
#include<string.h>
#include "gmp.h"
#pragma comment(lib,"libgmp-10.lib")
mpz_t st[800];
char str[1000];
inline void expmod(mpz_t a, mpz_t paraE, mpz_t n) {
	
	int i = 0;
	mpz_t aBack;
	mpz_init_set(aBack, a);
	mpz_get_str(str, 2, paraE);		
	mpz_set_ui(a, 1);
	while (str[i] != '\0') {		
		mpz_mul(a, a, a);
		mpz_mod(a, a, n);
		if (str[i] == '1') {
			mpz_mul(a, a, aBack);
			mpz_mod(a, a, n);
		}
		i++;
	}
}

int main() {
	int n;
	mpz_t e, m, p, q, b1, b2, B, d, phi, temp, pInverse, qInverse, _p, _q, d1, d2;
	for (int i = 0; i < 800; i++) {
		mpz_init(st[i]);
	}
	mpz_t c;mpz_init(c);
	mpz_init_set_si(c,-1);
	mpz_init(e);mpz_init(m);mpz_init(p);mpz_init(q);mpz_init(b1);mpz_init(b2);
	mpz_init(B);mpz_init(d);mpz_init(temp);mpz_init(phi);mpz_init(pInverse);
	mpz_init(qInverse);mpz_init(_p);mpz_init(_q);mpz_init(d1);mpz_init(d2);
	gmp_scanf("%d%Zd%Zd%Zd",&n , p, q, e);
	mpz_powm(pInverse,p,c,q);
	mpz_powm(qInverse,q,c,p);
	//calInverse(pInverse, p, q);		
	//calInverse(qInverse, q, p);
	mpz_mul(B, p, q);		
	mpz_sub_ui(_p, p, 1);	
	mpz_sub_ui(_q, q, 1);
	mpz_mul(phi, _p, _q);
	mpz_powm(d,e,c,phi);
	//calInverse(d, e, phi);	
	mpz_mod(d1, d, _p);		
	mpz_mod(d2, d, _q);
	while (n--) {
		gmp_scanf("%Zd", m);
		mpz_set(b1, m);
		mpz_set(b2, m);
		expmod(b1, d1, p);		
		expmod(b2, d2, q);


		mpz_mul(b1, b1, q);		
		mpz_mod(b1, b1, B);
		mpz_mul(b1, b1, qInverse);
		mpz_mod(b1, b1, B);

		mpz_mul(b2, b2, p);
		mpz_mod(b2, b2, B);
		mpz_mul(b2, b2, pInverse);
		mpz_mod(b2, b2, B);

		mpz_add(b1, b1, b2);
		mpz_mod(b1, b1, B);
		gmp_printf("%Zd\n", b1);
	}
	return 0;
}
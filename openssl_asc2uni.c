#include <stdio.h>
#include <openssl/crypto.h>
int main()
{
	unsigned char asc[50]={"B2E2CAD4"};
	unsigned char uni[50],*p,*q;
	int		ascLen,unlen;

	ascLen=strlen(asc);
	q=OPENSSL_asc2uni(asc,ascLen,NULL,&unlen);

	OPENSSL_free(q);
	return 0;
}

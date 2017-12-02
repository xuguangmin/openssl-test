#include <string.h>
#include <openssl/crypto.h>

int main()
{
	char *p;
	int i;
	p=OPENSSL_malloc(4);
	p=OPENSSL_realloc(p,40);
	p=OPENSSL_realloc(p,32);
	for(i=0;i<32;i++)
		memset(&p[i],i,1);
	/* realloc 时将以前的内存区清除(置乱) */
	p=OPENSSL_clear_realloc(p,32,77);
	OPENSSL_secure_malloc(3);
	OPENSSL_secure_free(p);
	return 0;
}

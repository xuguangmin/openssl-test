/* 大数 */

#include <openssl/bn.h>
int main()
{
	int
		ret;
	BIGNUM
		*a;
	BN_ULONG w;
	a=BN_new();
	BN_one(a);
	w=2685550010;
	ret=BN_add_word(a,w);
	if(ret!=1)
	{
		printf("a+=w err!\n");
		BN_free(a);
		return -1;
	}
	BN_free(a);
	return 0;
}

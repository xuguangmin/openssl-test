#include <openssl/bn.h>
int main()
{
	BIGNUM *ret1,*ret2;
	ret1=BN_new();
	ret1=BN_bin2bn("242424ab",8, ret1);
	ret2=BN_bin2bn("242424ab",8,NULL);
	BN_free(ret1);
	BN_free(ret2);
	return 0;
}

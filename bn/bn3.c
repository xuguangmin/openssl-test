#include <openssl/bn.h>
int main()
{
	BIGNUM *ret1=NULL;
	char bin[50],*buf=NULL;
	int len;

	ret1=BN_bin2bn("242424ab",8, NULL);
	len=BN_bn2bin(ret1,bin);
	len=BN_num_bytes(ret1);
	buf=malloc(len);
	len=BN_bn2bin(ret1,buf);

	free(buf);
	BN_free(ret1);
	return 0;
}

/* DSA 密钥生成 */

#include <string.h>
#include <openssl/dsa.h>
int main()
{
	DSA	*d;
	int	ret,i;
	unsigned char seed[20];
	int	 counter=2;
	unsigned long h;

	d=DSA_new();
	for(i=0;i<20;i++)
		memset(seed+i,i,1);

	//ret=DSA_generate_parameters_ex(d, 512,seed, 20, &counter,&h,NULL);
	/* 生成密钥参数 */
	ret=DSA_generate_parameters_ex(d, 512,NULL,0,NULL,NULL,NULL);
	if(ret!=1) {
		DSA_free(d);
		return -1;
	}

	/* 生成密钥 */
	ret=DSA_generate_key(d);
	if(ret!=1) {
		DSA_free(d);
		return -1;
	}
	DSA_print_fp(stdout,d,0);
	DSA_free(d);
	return 0;
}

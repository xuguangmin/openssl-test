/* md BIO, 本示例用 md BIO 对字符串"opessl"进行 md5 摘要 */

#include <openssl/bio.h>
#include <openssl/evp.h>
int main()
{
	BIO *bmd=NULL,*b=NULL;
	const EVP_MD *md=EVP_md5();
	int len;
	char tmp[1024];

	bmd=BIO_new(BIO_f_md());
	BIO_set_md(bmd,md);
	b= BIO_new(BIO_s_null());
	b=BIO_push(bmd,b);
	len=BIO_write(b,"openssl",7);
	len=BIO_gets(b,tmp,1024);
	printf("len: %d tmp:[", len);

	int i;
	for(i = 0; i < 16; i++) {
		printf("%02x", (unsigned char)tmp[i]);
	}
	printf("\n");
	fflush(NULL);

	BIO_free(b);
	return 0;
}

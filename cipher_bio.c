// 加/解密示例:

#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#define ENCRYPT 1
#define DECRYPY 0
int main()
{
	/* 加密 */
	BIO *bc=NULL,*b=NULL;
	const EVP_CIPHER *c=EVP_des_ecb();
	int len,i;
	char tmp[1024];
	unsigned char key[8],iv[8];
	for(i=0;i<8;i++)
	{
		memset(&key[i],i+1,1);
		memset(&iv[i],i+1,1);
	}

	bc=BIO_new(BIO_f_cipher());
	BIO_set_cipher(bc,c,key,iv,ENCRYPT);
	b= BIO_new(BIO_s_null());
	b=BIO_push(bc,b);
	len=BIO_write(b,"openssl",7);
	len=BIO_read(b,tmp,1024);
	printf("tmp:%s\n", tmp);

	BIO_free(b);

	/* 解密 */
	BIO const *bdec=NULL,*bd=NULL;
	EVP_CIPHER *cd=EVP_des_ecb();
	bdec=BIO_new(BIO_f_cipher());
	BIO_set_cipher(bdec,cd,key,iv,DECRYPY);
	bd= BIO_new(BIO_s_null());
	bd=BIO_push(bdec,bd);
	len=BIO_write(bdec,tmp,len);
	memset(tmp, '\0', 1024);
	len=BIO_read(bdec,tmp,1024);
	printf("tmp:%s\n", tmp);

	BIO_free(bdec);
	return 0;
}

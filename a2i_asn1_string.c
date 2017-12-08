/* 将 ASCII 码转换为 ASN1_STRING */

#include <openssl/asn1.h>
int main()
{
	BIO	*bp;
	ASN1_STRING	*str;
	unsigned char buf[50];
	int	size,len;

	bp=BIO_new(BIO_s_mem());
	len=BIO_write(bp,"B2E2CAD4",8);
	size=50;
	str=ASN1_STRING_new();
	a2i_ASN1_STRING(bp,str,buf,size);

	BIO_free(bp);
	ASN1_STRING_free(str);
	return 0;
}

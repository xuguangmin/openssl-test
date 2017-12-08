/* 将 bp 中的 ASC 码转换为 ASN1_INTEGER,buf 存放 BIO 中的 ASC 码 */
#include <openssl/asn1.h>
int main()
{
	BIO	*bp;
	ASN1_INTEGER *i;
	unsigned char buf[50];
	int	size,len;

	bp=BIO_new(BIO_s_mem());
	len=BIO_write(bp,"0FAB08BBDDEECC",14);
	size=50;
	i=ASN1_INTEGER_new();
	a2i_ASN1_INTEGER(bp,i,buf,size);

	BIO_free(bp);
	ASN1_INTEGER_free(i);
	return 0;
}

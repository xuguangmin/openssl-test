/* 计算 OID 的 DER 编码 */
#include <openssl/asn1.h>

int main()
{
	const	char oid[]={"2.99999.3"};
	int	i;
	unsigned char *buf;

	i=a2d_ASN1_OBJECT(NULL,0,oid,-1);
	if (i <= 0)
		return -1;

	buf=(unsigned char *)malloc(sizeof(unsigned char)*i);
	i=a2d_ASN1_OBJECT(buf,i,oid,-1);
	int k;
	for(k = 0; k < i; k++)
		printf("%02x ", buf[k]);
	printf("\n");


	free(buf);

	return 0;
}

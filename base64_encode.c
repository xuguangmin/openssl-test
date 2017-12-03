/* base64 编码 */

#include <string.h>
#include <openssl/evp.h>

int main()
{
	EVP_ENCODE_CTX ectx, dctx;
	unsigned char in[500],out[800],d[500];
	int inl,outl,i,total,ret,total2;
	EVP_EncodeInit(&ectx);

	for(i=0;i<500;i++)
		memset(&in[i],i,1);

	inl=500;
	total=0;
	EVP_EncodeUpdate(&ectx,out,&outl,in,inl);
	total+=outl;
	EVP_EncodeFinal(&ectx,out+total,&outl);
	total+=outl;
	printf("%s\n",out);
	EVP_DecodeInit(&dctx);
	outl=500;
	total2=0;
	ret=EVP_DecodeUpdate(&dctx,d,&outl,out,total);
	if(ret<0)
	{
		printf("EVP_DecodeUpdate err!\n");
		return -1;
	}
	total2+=outl;
	ret=EVP_DecodeFinal(&dctx,d,&outl);
	total2+=outl;

	return 0;
}

/* 压缩解压 */

#include <string.h>
#include <openssl/comp.h>
int main()
{
	COMP_CTX  *ctx;
	int	 len,olen=100,i,total=0;
	unsigned char in[50],out[100];
	unsigned char expend[200];
#ifdef	_WIN32
	ctx=COMP_CTX_new(COMP_rle());
#else
	/* for linux */
	ctx=COMP_CTX_new(COMP_zlib());
	printf("linux\n");
#endif
	for(i=0;i<50;i++)
		memset(&in[i],i,1);
	total=COMP_compress_block(ctx,out,olen,in,50);
	printf("out len:%d\n", total);
	len=COMP_expand_block(ctx,expend,200,out,total);

	for(i = 0; i < len; i++)
		printf("%02x ", expend[i]);

	COMP_CTX_free(ctx);
	return 0;
}

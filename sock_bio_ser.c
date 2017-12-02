/* socket BIO server*/

#include <stdio.h>
#include <openssl/bio.h>
#include <string.h>
int main()
{
	BIO *b=NULL,*c=NULL;
	int sock,ret,len;
	char *addr=NULL;
	char out[80];

	sock=BIO_get_accept_socket("2323",0);
	b=BIO_new_socket(sock, BIO_NOCLOSE);
	ret=BIO_accept(sock,&addr);
	BIO_set_fd(b,ret,BIO_NOCLOSE);
	while(1)
	{
		memset(out,0,80);
		len=BIO_read(b,out,80);
		if(out[0]=='q')
			break;
		printf("%s",out);
	}
	BIO_free(b);
	return 0;
}

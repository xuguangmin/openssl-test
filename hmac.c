# include <openssl/hmac.h>

int main()
{
	unsigned char *p = NULL;
	unsigned char *key = "1234";
	unsigned char *data = "xuguangmin";
	unsigned char hmac[1024];
	unsigned int  len;

	p = HMAC(EVP_md5(),
		key, strlen(key),
		data, strlen(data), 
		hmac, &len);
	int i;
	printf("hmac:");
	for(i = 0; i < len; i++)
		printf("%02x ", hmac[i]);
	printf("\n");

	printf("p:");
	for(i = 0; i < strlen(p); i++)
		printf("%02x ", p[i]);
	printf("\n");

	return 0;
}

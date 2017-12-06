/* 动态库加载卸载*/
#include <openssl/dso.h>
#include <openssl/bio.h>
int main()
{
	DSO *d;
	void (*f1)();
	void (*f2)();
	BIO *(*BIO_newx)(BIO_METHOD *a);
	BIO *(*BIO_freex)(BIO_METHOD *a);
	BIO *test;
	d=DSO_new();
	d=DSO_load(d,"libeay32",NULL,0);
	f1=DSO_bind_func(d,"BIO_new");
	//f2=DSO_bind_func(d,"BIO_free");
	BIO_newx=(BIO *(*)(BIO_METHOD *))f1;
	//BIO_freex=(BIO *(*)(BIO_METHOD *))f2;
	test=BIO_newx(BIO_s_file());
	return 0;
	BIO_set_fp(test,stdout,BIO_NOCLOSE);
	BIO_puts(test,"abd\n\n");
	//BIO_freex(test);
	DSO_free(d);
	return 0;
}

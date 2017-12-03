/* 给定session,从三列表获取所有对应值，这些值放在CONF_VALUE的堆栈中 */

#include <openssl/conf.h>

int main()
{
	CONF *conf;
	BIO *bp;
	STACK_OF(CONF_VALUE) *v;
	CONF_VALUE *one;
	int i,num;
	long eline;

	conf=NCONF_new(NULL);
	bp=BIO_new_file("conf_test.txt","r");
	if(bp==NULL)
	{
		printf("err!\n");
		return -1;
	}
	NCONF_load_bio(conf,bp,&eline);
	v=NCONF_get_section(conf,"CA_default");
	num=sk_CONF_VALUE_num(v);
	printf("section CA_default :\n");
	for(i=0;i<num;i++)
	{
		one=sk_CONF_VALUE_value(v,i);
		printf("%s = %s\n",one->name,one->value);
	}
	BIO_free(bp);
	printf("\n");
	return 0;
}

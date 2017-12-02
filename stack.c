#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/safestack.h>

//openssl 堆栈用法

typedef struct
Student_st
{
	char *name;
	int age;
	char *otherInfo;
}Student;

typedef STACK_OF(Student)   Students;
DEFINE_STACK_OF(Student)

Student *Student_Malloc()
{
	Student *a=malloc(sizeof(Student));
	a->name=malloc(20);
	strcpy(a->name,"zcp");
	a->otherInfo=malloc(20);
	strcpy(a->otherInfo,"no info");
	a->age = 45;
	return a;
}

void Student_Free(Student *a)
{
	free(a->name);
	free(a->otherInfo);
	free(a);
}
	static
int Student_cmp(Student *a,Student *b)
{
	int
		ret;
	ret=strcmp(a->name,b->name);
	return ret;
}

int main()
{
	Students *s,*snew;
	Student *s1,*one,*s2;
	int  i,num;

	s = sk_Student_new_null();
	snew=sk_Student_new(Student_cmp);
	s2=Student_Malloc();
	sk_Student_push(snew,s2);
	i=sk_Student_find(snew,s2);
	s1=Student_Malloc();
	sk_Student_push(s,s1);
	num=sk_Student_num(s);
	for(i=0;i<num;i++)
	{
		one=sk_Student_value(s,i);
		printf("student name : %s\n",one->name);
		printf("sutdent age : %d\n",one->age);
		printf("student otherinfo :%s\n\n\n",one->otherInfo);
	}

	sk_Student_pop_free(s,Student_Free);
	sk_Student_pop_free(snew,Student_Free);
	return 0;
}




#include"header.h"
char* get()
{
	int i=0;
	char *p=NULL;
	do
	{
		p=realloc(p,i+1);
		p[i]=getchar();
	}while(p[i++]!=10);
	p[i-1]=0;
	return p;
}

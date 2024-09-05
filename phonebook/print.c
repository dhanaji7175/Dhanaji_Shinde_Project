#include"header.h"
void print(D *p)
{
	int i;
	if(p==NULL)
	{
		printf("EMPTY\n"); return ;
	}
	while(p)
	{
		if(p->name[0])
			printf("%s  ",p->name[0]);
		if(p->name[1])
			printf("%s  ",p->name[1]);
		if(p->name[2])
			printf("%s\n",p->name[2]);
		//printf("%s ",p->num);
		for(i=0;i<13;i++)
			printf("%c",p->num[i]);
		printf("\n***************************************\n");
		p=p->next;
	}
}


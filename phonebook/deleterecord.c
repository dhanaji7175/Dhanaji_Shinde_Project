#include"header.h"
void delete(D **ptr)
{
	char str[20];
	int f=0;
	printf("ENTER NAME OR CONTACT TO BE DELETE:");
	__fpurge(stdin);
	scanf("%[^\n]s",str);
	D *p,*prev=NULL;
	prev=p=(*ptr);
	while(p)
	{
		if((strstr(p->name[0],str)) ||(strstr(p->name[2],str)) || strstr(p->num,str))
		{
			printf("%s   %s  %s\n",p->name[0],p->name[1],p->name[2]);
			printf("%s \n",p->num);
		}
		p=p->next;
	}
	printf("OUT OF ABOVE WHICH ONE YOU WANT TO DELETE:\n");
	__fpurge(stdin);
	scanf("%[^\n]s",str);
	prev=p=(*ptr);
	while(p)
	{
		if((strcmp(p->name[0],str)==0) ||(strcmp(p->name[2],str)==0) || (strcmp(p->num,str)==0))
		{
			f=1;
			if(p==(*ptr))
				(*ptr)=p->next;
			prev->next=p->next;
			free(p);
			p=NULL;
			p=prev;
		}
		prev=p;
		p=p->next;
	}
	if(f==0)
	printf("HEY !! YOU ENTERED CONTACT IS NOT PRESENT\n");
}


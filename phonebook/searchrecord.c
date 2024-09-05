#include"header.h"
void search(D **ptr)
{
	D *p=NULL,*prev=NULL;
	char str[20];
	int f=0;

	printf("ENTER THE NAME OR CONTACT WHICH YOU WANT SEARCH:\n");
	__fpurge(stdin);
	scanf("%[^\n]s",str);
	p=(*ptr);
	while(p)
	{
		if((strstr(p->name[0],str)) ||(strstr(p->name[2],str)) || strstr(p->num,str))
		{
			printf("%s   %s  %s\n",p->name[0],p->name[1],p->name[2]);
			printf("%s \n",p->num);f++;
		
		}
		p=p->next;
	}
	if(f==0)
	{
		printf("SORRY !! THIS CONTACT NOT IS IN LIST:\nPLEASE ENTER THE CORRECT\n");
		return ;
	
	}
	if(f>1)
	{
		f=0;
	printf("OUT OF ABOVE WHICH ONE YOU WANT TO search:\n");
	__fpurge(stdin);
	scanf("%[^\n]s",str);
	p=(*ptr);
	while(p)
	{
		if((strcmp(p->name[0],str)==0) ||(strcmp(p->name[2],str)==0) || (strcmp(p->num,str)==0)||(strcmp(p->name[1],str)==0))
		{
			f=1;
			printf("%s   %s  %s\n",p->name[0],p->name[1],p->name[2]);
			printf("%s \n",p->num);
			printf("%s \n",p->email);
			printf("%s \n",p->a.area);
			printf("%s \n",p->a.cityname);
		}
		prev=p;
		p=p->next;
	}
	}
	if(f==0)
		printf("YOU SEARCHED CONACT NOT PRESENT IN OUR PHONEBOOK:\n");

if(prev!=NULL)
		prev->next=NULL;
}



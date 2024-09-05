#include"header.h"
int test(char *p,int f)
{
	char *q=NULL;
	int cnt=0,cnt1=0;
	if(f==1)
	{
		for(q=p;*q;q++)
		{
			if(isalnum(*q))
				continue;
			else
				return 1;
		}

	}
	else if(f==2)
	{
		for(q=p;*q;q++)
		{
			if(isdigit(*q)||(*q=='+'))
				continue;
			else
				return 1;
		}
	}
	else
	{
		for(q=p;*q;q++)
		{

			if(*q=='@')
			{
				cnt++;continue;
			}
			if(*q=='.')
			{
				cnt1++;
			continue;
		}
			
			else
			{
				if(isalnum(*q) && cnt<=1 && cnt1<=1)
					continue;
				else
					return 1;
			}
		}
	}
	return 0;
}
int check(char *p,D *ptr)
{
	int cnt=0,i=0;

	if(ptr==NULL)
		return 0;
	while(ptr)
	{
		cnt=0;
		for(i=3;i<13;i++)
		{
			if(ptr->num[i]==p[i-3])
				cnt++;
		}
		if(cnt==10)
			return 1;

		ptr=ptr->next;
	}

	return 0;
}
int flag=0;
D *add(D *ptr)
{
	int i=0;
	char *str=NULL,*s=NULL;
	D *p=NULL,*nu=NULL,*prev=NULL;
	nu= calloc(1,sizeof(D));
	/************************** NAMES *********************************/
	printf("ENTER THE FIRST NAME:");
H1:nu->name[0]=calloc(1,20);
   __fpurge(stdin);
   nu->name[0]=get();
   if(test(nu->name[0],1))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   free(nu->name[0]);
	   nu->name[0]=NULL;
	   goto H1;
   }
   printf("ENTER THE MIDDLE NAME:");
H2:nu->name[1]=calloc(1,20);
   __fpurge(stdin);
   nu->name[1]=get();
   if(test(nu->name[1],1))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   free(nu->name[1]);
	   nu->name[1]=NULL;
	   goto H2;
   }
   printf("ENTER THE LAST NAME:");
   __fpurge(stdin);

   nu->name[2]=calloc(1,20);
   __fpurge(stdin);
H3:nu->name[2]=get();
   if(test(nu->name[2],1))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   free(nu->name[2]);
	   nu->name[2]=NULL;
	   goto H3;
   } 
   if((strlen(nu->name[0])==0))
   {
	   printf("DEAR YOU MISSING NAME !! PLEASE ENTER FIRST NAME:\n");
X:nu->name[0]=calloc(1,20);
  __fpurge(stdin);
  nu->name[0]=get();
  if(test(nu->name[0],1))
  {
	  printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	  free(nu->name[0]);
	  nu->name[0]=NULL;
	  goto X;
  }
   }

 
/********************************** MOBILE NUMBER ***************************************/
H4:printf("DEAR !!ENTER MOBILE NUMBER:\n");
printf("enter the country code:\n");
__fpurge(stdin);
s=get();
printf("ENTER THE NUMBER:");
__fpurge(stdin);
str=get();
strcat(s,str);
nu->num=s;
if((strlen(nu->num)<=3)||(strlen(nu->num)==0))
{
	printf("HEY MISSING!!YOU NOT ENTERED THE CONTACT:\n");
		goto H4;
}
if((strlen(nu->num)!=13) || test(nu->num,2))
{
	printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	goto H4;
}
if(check((nu->num)+3,ptr))
{
	printf("WRONG NUMBER !! PLEASE ENTER THE CORRECT NUMBER:\n");
	goto H4;
}
/*****************************  COMPANY ******************************************/
printf("DEAR !!ENTER COMPANY NAME:\n");
   nu->company=calloc(1,20);
__fpurge(stdin);
nu->company=get();
/*****************************  EMAIL ID ******************************************/

printf("DEAR !!ENTER EMAIL ID:\n");
   nu->email=calloc(1,20);
__fpurge(stdin);
H5:nu->email=get();
if(test(nu->email,3))
{
	printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	goto H5;
}
/*****************************  ADDRESS  ******************************************/
printf("DEAR !!ENTER THE ADDRESSS:\n");
nu->a.area=calloc(1,20);
__fpurge(stdin);
nu->a.area=get();
printf("DEAR !!ENTER THE CITY NAME:\n");
nu->a.cityname=calloc(1,20);
__fpurge(stdin);
nu->a.cityname=get();
flag=1;
/***************************** ADD BY SORT ******************************************/
if((ptr==NULL)||(strcmp(ptr->name[0],nu->name[0])>0))
{
	nu->next=ptr;
	ptr=nu;
	return ptr;
}
else
{
	p=ptr;
	while(p && (strcmp(nu->name[0],p->name[0])>0))
	{
		prev=p;
		p=p->next;
	}
	nu->next=prev->next;
	prev->next=nu;
	return ptr;
}
}


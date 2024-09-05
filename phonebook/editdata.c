#include"header.h"
/*int test(char *p,int f)
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
}*/
extern int flag;
D *edit(D *ptr)
{
	int i=0,ch=0,g=0;
	char *str=NULL,*s=NULL,*s1=NULL,*num1=NULL;
	D *p=NULL,*nu=NULL,*prev=NULL;
	printf("HELLO !! ENTER THE CONTACT TO BE EDIT:\n");
	__fpurge(stdin);
	s=get();
	p=ptr;
	while(p)
	{
		if((strstr(p->name[0],s)) ||(strstr(p->name[2],s)) || strstr(p->num,s))
		{
			g=1;
			printf("HELLO !! WHAT YOU WANT EDIT:\n");
			printf("\n1.FIRST NAME\n2.MIDDLE NAME\n3.LAST NAME\n4.MOBILE NUMBER\n5.EMAIL ID\n6.COMPANY\n7.ADDRESS\n");
			__fpurge(stdin);
			scanf("%d",&ch);
			if(ch==1)
			{
				printf("ENTER THE FIRST NEW NAME:");
H1:str=calloc(1,20);
   str=calloc(1,20);
   __fpurge(stdin);
   str=get();
   if((strlen(str)==0))
   {
	   printf("DEAR YOU MISSING NAME !! PLEASE ENTER FIRST NAME:\n");
	   free(str);
	   str=NULL;
	   goto H1;
   }
   if(test(str,1))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   free(str);
	   str=NULL;
	   goto H1;
   }
   p->name[0]=str;
			}
			else if(ch==2)
			{
				printf("ENTER THE NEW MIDDLE NAME:");
H2:str=calloc(1,20);
   str=calloc(1,20);
   __fpurge(stdin);
   str=get();
   if(test(str,1))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   free(str);
	   str=NULL;
	   goto H2;
   }
   p->name[1]=str;
			}
			else  if(ch==3)
			{

				printf("ENTER THE NEW LAST NAME:");
				__fpurge(stdin);

				str=calloc(1,20);
				__fpurge(stdin);
H3:str=get();
   str=get();
   if(test(str,1))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   free(str);
	   str=NULL;
	   goto H3;
   }
   p->name[2]=str;
			} 
			else if(ch==4)
			{
H4:printf("DEAR !!ENTER NEW MOBILE NUMBER:\n");
   printf("DEAR !!ENTER NEW MOBILE NUMBER:\n");
   printf("enter the country code:\n");
   __fpurge(stdin);
   s1=get();
   printf("ENTER THE NUMBER:");
   __fpurge(stdin);
   str=get();
   strcat(s1,str);
   num1=s;
   if(((strlen(num1)<=3)||(strlen(num1)==0)))
   {
	   printf("HEY MISSING!!YOU NOT ENTERED THE CONTACT:\n");
	   goto H4;
   }
   if((strlen(num1)!=13) || test(num1,2))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   goto H4;
   }
   if(check((num1)+3,ptr))
   {
	   printf("WRONG NUMBER !! PLEASE ENTER THE CORRECT NUMBER:\n");
	   goto H4;
   }
   p->num=num1;
			}
			else if(ch==5)
			{
				printf("DEAR !!ENTER NEW COMPANY NAME:\n");
				str=calloc(1,20);
				__fpurge(stdin);
				p->company=get();
			}
			/*****************************  EMAIL ID ******************************************/
			else if(ch==6)
			{
				printf("DEAR !!ENTER NEW EMAIL ID:\n");
				free(p->email);
				p->email=calloc(1,20);
				__fpurge(stdin);
H5:p->email=get();
   p->email=get();
   if(test(p->email,3))
   {
	   printf("HEY !! YOU ENTERED WRONG DATA !!\n PLEASE ENTER CORRECT:");
	   free(p->email);
	   p->email=NULL;
	   p->email=calloc(1,20);
	   goto H5;
   }
			}
			/*****************************  ADDRESS  ******************************************/
			else if(ch==7)
			{
				printf("DEAR !!ENTER THE NEW ADDRESSS:\n");
				free(p->a.area);
				p->a.area=NULL;
				p->a.area=calloc(1,20);
				__fpurge(stdin);
				p->a.area=get();
				printf("DEAR !!ENTER THE  NEW CITY NAME:\n");
				free(p->a.cityname);
				p->a.cityname=NULL;
				p->a.cityname=calloc(1,20);
				__fpurge(stdin);
				p->a.cityname=get();
			}
			else
			{
				printf("INVALID CHOICE:\n");
			}
			flag=1;
		}
		p=p->next;
	}

	if(g==0)
	{
		printf("YOU ENTERED DATA NOT FOUND HERE:\n");
	}
	return ptr;
}

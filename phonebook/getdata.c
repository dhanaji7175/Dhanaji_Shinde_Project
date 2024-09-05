#include"header.h"
D *gen()
{
	char ch;
	struct _IO_FILE *fp;
	D temp,*ptr=NULL,*nu=NULL,*lptr=NULL,var,*prev=NULL;

	fp=fopen("myphonebook","r");
	if(fp==NULL)
	{
		printf("SORRY YOUR FILE UNABLE TO OPEN:\n");
		return 0;
	}
	while(1)
	{
		ch=fgetc(fp);
		if(ch==-1)
			break;
		fseek(fp,-1,1);
		nu=calloc(1,sizeof(D));
		nu->name[0]=calloc(1,20);
		fscanf(fp,"%s",nu->name[0]);
		nu->name[1]=calloc(1,20);
		fscanf(fp,"%s",nu->name[1]);
		nu->name[2]=calloc(1,20);
		fscanf(fp,"%s",nu->name[2]);
		nu->num=calloc(1,20);
		fscanf(fp,"%s",nu->num);
		nu->company=calloc(1,20);
		fscanf(fp,"%s",nu->company);
		nu->email=calloc(1,20);
		fscanf(fp,"%s",nu->email);
		nu->a.area=calloc(1,20);
		fscanf(fp,"%s",nu->a.area);
		nu->a.cityname=calloc(1,20);
		fscanf(fp,"%s",nu->a.cityname);
		if(ptr==NULL)
		{
			ptr=nu;
			lptr=nu;
		}
		else
		{	prev=lptr;
			lptr->next=nu;
			lptr=nu;
		}
		nu=NULL;
	}
	if(prev!=NULL)
		prev->next=NULL;
	fclose(fp);
	return ptr;
}


#include"header.h"
void save(D *ptr)
{
	D *p=NULL;
	extern int flag;
	struct _IO_FILE  *fp;
	fp=fopen("myphonebook","w");
	p=ptr;
	while(ptr)
	{

		fprintf(fp,"%s %s %s\n",ptr->name[0],ptr->name[1],ptr->name[2]);
		fprintf(fp,"%s\n",ptr->num);
		fprintf(fp,"%s\n",ptr->company);
		fprintf(fp,"%s\n",ptr->email);
		fprintf(fp,"%s %s\n",ptr->a.area,ptr->a.cityname);
		ptr=ptr->next;
		flag=0;

	}
	fclose(fp);
}


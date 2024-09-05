#include"header.h"
int main()
{
	int f=0;
	extern int flag;
	D *start=NULL;
	start=gen();
	print(start);
	while(1)
	{
		char ch=0;
		printf("\n************************* MENU ****************************\n");
		printf("DEAR WHAT YOU WANT ???\na:->ADD A CONTACT\np:->PRINT CONTACT\ns:->SEARCH A CONTACT\ne:->EDIT CONTACT\nd:->DELETE CONTACT FROM LIST\nS:->SAVE RECORD\nq.STOP\nenter the choice:");
		__fpurge(stdin);
		scanf( "%c",&ch);
		switch(ch)
		{
			case 'a':start=add(start);break;
			case 'p':print(start);break;
			case 'S':if(flag==1)
					 save(start);
				 else
				 {
					 printf("DEAR PLEASE ENTER THE DATA THEN YOU CAN SAVE\n");
				 }
				 break;
			case 'd':delete(&start);break;
			case 's':search(&start);break;
			case 'q':exit(0);break;
			case 'e':start=edit(start);break;
			default:printf("INVALID CHOICE:\n");
		}
	}
}



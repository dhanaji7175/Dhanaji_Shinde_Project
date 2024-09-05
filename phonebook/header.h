#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct address
{
	char *area;
	char *cityname;
};
typedef struct CONTACT
{
	char *name[3];
	char *num;
	char *company;
	char *email;
	struct address a;
	struct CONTACT *next;
}D;
D *add(D *ptr);
void print(D *);
void delete(D **ptr);
D *gen();
void save(D *ptr);
void search(D **ptr);
char *get();
D* edit(D *);
int test(char *p,int f);
int check(char *p,D *ptr);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int m;

int hashvalue(int val, int i)
{
	return (val%m+i)%m;
}

int search(int *table, int val)
{
	int hval;
	int i=0;
	while(i<m)
	{
		hval = hashvalue(val, i);
		printf("%d(%d) ", hval, table[hval]);
		if(table[hval]==val)
			break;
		else if(table[hval] == -1)
			break;
		
		i++;
	}
	if(i!=m  && table[hval]!=-1)
		return hval;
	return -1;
}


void insert(int *table, int val)
{
	int hval;
	int i=0;
	while(i<m)
	{
		hval = hashvalue(val, i);
		printf("%d(%d) ",hval, table[hval]);
		if(table[hval] < 0)
		{
			table[hval] = val;
			break;
		}	
		else if(table[hval]==val)
			break;
		i++;
	}
	return ;
}

void delete(int *table, int x)
{
	int hval;
	hval = search(table, x);
	if(hval!=-1)
		table[hval] = -2;
	return;
}

int main()
{
	int val;
	char str[5];
	int *table;
	int src;
	scanf("%d", &m);
	table = (int*)malloc(m*sizeof(int));
	for(int i=0; i<m ; i++)
	table[i] = -1;
	while(scanf("%s%d", str, &val)!=EOF)
	{
		if(strcmp(str, "INS")==0)
		{
			insert(table, val);
			printf("\n");
		}
		else if(strcmp(str, "SRCH")==0)
		{
			 src = search(table, val);
			printf("\n");
		}
		else
		{
			delete(table, val);
			printf("\n");
		}
	}
	return 0; 
}

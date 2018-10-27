#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int m;

typedef struct node
{
	int no;
	struct node *next;
}node;

node *search(node **table, int no)
{
	int hval;
	node *head;
	
	hval = no%m;
	head=table[hval];
	if(head==NULL)
		return NULL;
	else if (head->no==no)
		return head;
	
	while(head->next!=NULL)
	{
		if(head->next->no==no)
			return head->next;
		head=head->next;
	}
	return NULL;
}


int insert(node **table, int no)
{
	int hval;
	node *head;
	node *sp;
	node *nd;
	
	hval = no%m;
	head = table[hval];

	sp = search(table, no);
	if(sp!=NULL)
		return -1;
	
	nd = (node*)malloc(sizeof(node));
	nd->no = no;	

	if(head==NULL)
	{
		nd->next = NULL;
		table[hval]=nd;
		return 1;
	}
	while(head->next!=NULL)
		head= head->next;
	
	head->next=nd;
	nd->next=NULL;
	return 1;
}

void print(node **table, int i)
{
	node *head;
	if(i>=m || i<0)
	{	
		printf("-1\n");
		return;
	}
	
	head = table[i];
	if(head==NULL)
	{
		printf("-1\n");
		return;
	}
	while(head!=NULL)
	{
		printf("%d ", head->no);
		head=head->next;
	}
	printf("\n");
	return;			
}

int delete(node **table, int no)
{
	int hval;
	node *head;
	node *hp;

	hval = no%m;
	head = table[hval];
	
	if(head==NULL)
		return -1;
	else if(head->no==no)
	{
		table[hval]=head->next;
		head->next = NULL;
		free(head);
		return 1;
	}	
	
	while(head->next!=NULL)
	{
		if(head->next->no==no)
		{
			hp = head->next;
			head->next = head->next->next;
			hp->next=NULL;
			free(hp);
			return 1;
		}
		head=head->next;
	}
	return -1;
}

int main()
{
	node **table;
	node *pt;
	char str[10];
	int no;

	scanf("%d", &m);
    
	table = (node**)malloc(m*sizeof(node*));
	for(int i=0; i<m; i++)
		table[i]=NULL;

	while(scanf("%s%d", str, &no)!=EOF)
	{
		if(strcmp(str, "INS")==0)
		{
			if(m<=0 || no<0)
				printf("-1\n");
			else
			{ 
				no = insert(table, no);
				if(no==-1)
					printf("-1\n");
			}
		}
		else if(strcmp(str, "PRT")==0)
		{
			print(table, no);
		}
		else if(strcmp(str, "DEL")==0)
		{
			if(m<=0 || no<0)
				printf("-1\n");
			else
			{
				no = delete(table, no);	
				if(no==-1)
					printf("-1\n");
			}		
		}
		else if(strcmp(str, "SRCH")==0)
		{
			if(m<=0 || no<0)
				printf("N\n");
			else
			{
				pt = search(table, no);
				if(pt==NULL)
					printf("N\n");
				else
					printf("Y\n");
			}
		}
		else
			continue;
	}
	return 0;
}

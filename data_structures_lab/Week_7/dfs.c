#include<stdio.h>
#include<stdlib.h>

int flag =0;

typedef struct Dval
{
	int u, v;
}Dval;
Dval edg[200];


typedef struct node
{
	int data;
	struct node *link;
}node;

typedef struct Graph
{
	node **head;
	int *visited;
}Graph;

int stoi(char *str)
{
	int x;
	sscanf(str, "%d", &x);
	return x;
}

int comparator(const void *p, const void *q)
{
	int p1, p2;
	p1 = ((Dval*)p)->u;
	p2 = ((Dval*)q)->u;
	return p1-p2;
}

void addNode(node **ad_head, int ver)
{
	
	node *nd;
	node *head;
	node *prev=NULL;
	head = *ad_head;
	nd = (node*)malloc(sizeof(node));
	nd->data = ver;
	if(head==NULL)
	{
		nd->link = NULL;
		*ad_head = nd;
		return;
	}
	else
	{
		while(head->link!=NULL && ver>((head->link)->data))
		{
			prev = head;
			head= head->link;
		}		
		
		if(head->link==NULL && ver<head->data)
		{
			nd->link = head;
			if(prev!=NULL)
				prev->link=nd;
			else
			{
				nd->link=*ad_head;
				*ad_head=nd;
			}
		}
		else
		{	
			nd->link = head->link;
			head->link=nd;
		}	
		return;
	}
}

Graph *CrGraph(int vtc)
{
	Graph *gr;
	gr = (Graph*)malloc(sizeof(Graph));
	

	gr->head = (node**)malloc(vtc*sizeof(node*));
	for(int i=0; i<vtc; i++)
		gr->head[i]=NULL;

	gr->visited = (int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
		gr->visited[i]=0;	

	return gr; 
}

void explore(Graph *gr, node *head, int i)
{
	int data;
	if(head==NULL)
	{
		return;
	}

	while(head!=NULL)
	{
		data = head->data;
		if(gr->visited[data]==0)
		{
			//printf("%d,%d\n", i,data);
			(edg[flag]).u = i;
			(edg[flag]).v = data;
			flag++;
			gr->visited[data]=1;
			explore(gr, gr->head[data], data);			
						
		}
		else
			head=head->link;
	}
	return;
}

void dfs(Graph *gr, int vtc)
{
	for(int i=0; i<vtc; i++)
	{
		if(gr->visited[i]==0)
		{
			gr->visited[i]=1;
			explore(gr, gr->head[i],i);
		}
	}
	return;
}

void displayList(Graph* gr, int vtc)
{
	node *head;
	for(int i=0; i<vtc; i++)
	{
		
		head=gr->head[i];
		if(head==NULL)
			printf("$\n");
		
		else if(head!=NULL)
		{ 
			while(head->link!=NULL)
			{
				printf("%d$", head->data);
				head=head->link;
			}
			if(head->link==NULL)
				printf("%d$\n", head->data);	
		}	
				
	}
	return;
}

void frf(node *head)
{
	if(head==NULL)
		return;
	if(head->link==NULL)
	{
		free(head);
		return;
	}
	else
	{
		frf(head->link);
		free(head);
	}
}

int main()
{
	char line[128];
	int lineNo=0;
	char v1[10], v2[10];
	int vtc, ver1, ver2;
	Graph *gr;
	while(fgets(line, sizeof line, stdin)!=NULL)
	{
		sscanf(line, "%s %s", v1, v2);
		lineNo++;
		if(lineNo==1)
		{
			vtc = stoi(v1);
			gr = CrGraph(vtc);
				
		}
		else
		{
			ver1 = stoi(v1);
			ver2 = stoi(v2);
			addNode(&(gr->head[ver1]), ver2);
		} 
	}
	//displayList(gr, vtc);
	dfs(gr, vtc);
	qsort((void*)edg, flag, sizeof(Dval), comparator);
	for(int i=0; i<flag; i++)
	{
		printf("(%d,%d)\n", (edg[i]).u, (edg[i]).v);
	}
	for(int i=0; i<vtc; i++)
		frf(gr->head[i]);
	
	free(gr->head);
	free(gr->visited);
	free(gr);
	return 0;
}

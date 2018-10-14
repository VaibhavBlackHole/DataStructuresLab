#include<stdio.h>
#include<stdlib.h>

int time1=0;


typedef struct node
{
	int ver;
	struct node* link;
}node;

typedef struct Graph
{
	node **head;
	int *stm;
	int *etm;
	int *visited;
}grh;

typedef struct Dval
{
	int v, t;
}Dval;

Dval tg1[200], tg2[200];

int comparator(const void *p1, const void *p2)
{
	int a, b;
	a = ((Dval*)p1)->t;
	b = ((Dval*)p2)->t;
	return b-a;
}

grh *CrGr(int vtc)
{
	grh *g;
	g = (grh*)malloc(sizeof(grh));
	
	g->head = (node**)malloc(vtc*sizeof(node*));
	for(int i=0; i<vtc; i++)
		g->head[i]=NULL;
	
	g->visited = (int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
		g->visited[i]=0;

	g->stm = (int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
		g->stm[i]=0;

	g->etm = (int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
		g->etm[i]=1000000;

	return g;	
}

void addNode(node **ad_head, int ver)
{
	node *head, *prev;
	head=*ad_head;

	prev = NULL;
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->ver = ver;
	if(head==NULL)
	{
		nd->link = NULL;
		*ad_head = nd;
		return;
	}
	else
	{
		while(head->link!=NULL && ver>(head->link)->ver)
		{
			prev = head;
			head=head->link;
		}
		if(head->link==NULL && ver<head->ver)
		{
			if(prev!=NULL)
			{
				prev->link = nd;
				nd->link = head;
			}
			else
			{
				nd->link = *ad_head;
				*ad_head=nd;
			}
		}
		else
		{
			nd->link = head->link;
			head->link = nd;			
		}
	}
	return;
}

void displayList(grh *g, int vtc)
{	
	node *head;
	for(int i=0; i<vtc; i++)
	{	
		head = g->head[i];
		if(head==NULL)
			printf("%d\n", i);
		
		else
		{
			printf("%d->", i);
			while(head->link!=NULL)
			{
				printf("%d->",head->ver);
				head = head->link;
			}
			printf("%d\n", head->ver);
		}
	}
	return;
}

void explore(grh *g, node *head)
{
	int ver;
	if(head==NULL)	
		return;
		
	while(head!=NULL)
	{
		//printf("Y\n");
		ver = head->ver;
		if(g->visited[ver]==0)
		{
			//printf("%p\n",head);
			g->visited[ver]=1;
			time1++;
			//printf("ver %d, time %d\n", ver, time1);
			g->stm[ver]=time1;
			explore(g, g->head[ver]);
			time1++;
			g->etm[ver]=time1;			
		}
		else
			head=head->link;
	}
	
	return;
}

void dfs(grh *g, int vtc, int min)
{
	for(int i=min; i<vtc; i++)
	{
		if(g->visited[i]==0)
		{
			g->visited[i]=1;
			time1++;
			//printf("ver %d, time %d\n", i, time1);
			g->stm[i] = time1;
			explore(g, g->head[i]);
			time1++;
			g->etm[i] = time1;
		}
	}
	return;
}

void pexplore(grh *g, node *head)
{
	int ver;
	if(head==NULL)	
	{
		//printf("\n");
		return;
	}
		
	while(head!=NULL)
	{
		ver = head->ver;
		if(g->visited[ver]==0)
		{
			printf("%d$",ver);
			g->visited[ver]=1;
			pexplore(g, g->head[ver]);		
		}
		else
			head=head->link;
	}
	return;
}

void frf(node *head)
{
	if(head!=NULL)
	{
		if(head->link==NULL)
		{
			free(head);
			return;
		}
		else
		{
			frf(head->link);
			free(head);
			return;
		}
	}
	return;
}

int main()
{
	int vtc;
	int u, v;
	grh *g1, *g2;
	
	scanf("%d", &vtc);
	
	g1 = CrGr(vtc);
	g2 = CrGr(vtc);
	while(scanf("%d %d", &u, &v)!=EOF)
	{
		addNode(&(g1->head[u]), v);
		addNode(&(g2->head[v]), u);
	}

	//dfs(g1, vtc, 0);
	dfs(g2, vtc, 0);

	//for(int i=0; i<vtc; i++)
		//printf("%d\n", g2->etm[i]);


	for(int i=0; i<vtc; i++)
	{	
		tg2[i].v = i;
		tg2[i].t = g2->etm[i];		
	}
	
	qsort((void*)tg2, vtc, sizeof(Dval), comparator);

	//for(int i=0; i<vtc; i++)
		//printf("%d %d\n", tg2[i].v, tg2[i].t);

	for(int i=0; i<vtc; i++)
	{
		if(g1->visited[tg2[i].v]==0)
		{
			printf("%d$",tg2[i].v);
			g1->visited[tg2[i].v]=1;
			pexplore(g1, g1->head[tg2[i].v]);
			printf("\n");
		}
		
	}	
	
	for(int i=0; i<vtc; i++)
	{
		frf(g1->head[i]);
		frf(g2->head[i]);
	}
	
		
	free(g1->head);
	free(g1->visited);
	free(g1->etm);
	free(g1->stm);
	free(g1);
	
	free(g2->head);
	free(g2->visited);
	free(g2->etm);
	free(g2->stm);
	free(g2);

	//displayList(g1, vtc);
	//displayList(g2, vtc);	
	return 0;	
}


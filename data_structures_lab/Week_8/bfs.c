#include<stdio.h>
#include<stdlib.h>

int flag =0;

typedef struct node
{
	int data;
	struct node *link;
}node;

typedef struct Queue
{
	int front, rear, capacity;
	int *arr;
}Queue;

typedef struct Graph
{
	node **head;
	int *visited;
	int *distance;
	Queue *qu;
}graph;

typedef struct sort
{
	int v1,v2;
}sort;

sort e[500];

int comparator(const void *p1, const void *p2)
{
	int a, b;
	a = ((sort*)p1)->v1;
	b = ((sort*)p2)->v1;
	if(a!=b)
		return a-b;
	else
	{
		a=((sort*)p1)->v2;
		b=((sort*)p2)->v2;
		return a-b;
	} 
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

graph* createGraph(int vtc)
{
	
	int edg, ver1, ver2;
	graph *gr;
	gr = (graph*)malloc(sizeof(graph));
	
	gr->head = (node**)malloc(vtc*sizeof(node*));
	for(int i=0; i<vtc; i++)
		(gr->head)[i]=NULL;                                    
	
	gr->visited = (int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
		(gr->visited)[i]=0;
	
	gr->distance=(int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
		(gr->distance)[i]=-1;
	
	gr->qu = (Queue*)malloc(sizeof(Queue));
	(gr->qu)->front = 0;
	(gr->qu)->rear = -1;			// stores the last filled element address (index) 
	(gr->qu)->arr = (int*)malloc(vtc*sizeof(int));
	(gr->qu)->capacity = vtc+1;
	
	return gr;
}

void queue(Queue *qu, int ver)
{
	qu->rear =qu->rear+1;
	(qu->arr)[qu->rear]=ver;
	return; 
}

int dequeue(Queue *qu)
{
	if(qu->front>=qu->rear+1)
		return -1;
	int ver;
	ver = (qu->arr)[qu->front];
	qu->front =qu->front+1;
	return ver; 
}

void displayList(graph* gr, int vtc)
{
	node *head;
	for(int i=0; i<vtc; i++)
	{
		head = (gr->head)[i];
		if(head!=NULL)
		{
			printf("%d->", i);
			while(head->link!=NULL)
			{
				printf("%d->",head->data);
				head= head->link;
			}
			printf("%d\n", head->data);
		}
		else
			printf("%d\n",i);
		
	}
	return;
}

void breadthFirstSearch(graph *gr, int v)
{
	node *head;
	int i, ver;
		
	(gr->qu)->front = 0;
	(gr->qu)->rear = -1;
	queue(gr->qu, v);
	//printf("%d is queued here\n", ver);
	(gr->visited)[v]=1;
	while(1)
	{
		ver = dequeue(gr->qu);		// we dequeue the vertex and see all the adjacent vertices of this vertex.
		if(ver==-1)
			break;
		i = ver;
		//printf("%d is dequed here\n", ver);
		head=(gr->head)[ver];
		while(head!=NULL)
		{
			ver = head->data;
			if((gr->visited)[ver]==0)
			{
				//printf("(%d,%d)\n", i, ver);
				e[flag].v1 = i;
				e[flag].v2 = ver;
				flag++;
				(gr->visited)[ver]=1;
				queue(gr->qu, ver);	
// as soon as we add any vertex to queue, we make it visited, so that we will not check it again, but at the time of dequeu of that element we find all the adjacent elements of that vertex.
				//printf("%d is queued here\n", ver);
				
				//printf("%p\n", head);
			}
			head = head->link;
		}
		
	}
	return;
}


void shortestDistance(graph *gr, int ver1, int vtc)
{
	int v;
	
	for(int i=0; i<vtc; i++)
	{
		gr->visited[i]=0;
		gr->distance[i]=-1;
		gr->qu->arr[i]=-1;
	}
		
	gr->qu->front = 0;
	(gr->qu)->rear = -1;
	
	int  u;
	gr->distance[ver1]=0;
	node *head ;
	queue(gr->qu, ver1);
	(gr->visited)[ver1]=1;
	while(1)
	{
		
		v=dequeue(gr->qu);
		//printf("ver1 %d\n", ver1);
		if(v==-1)
			break;
		head=(gr->head)[v];
		
		while(head!=NULL)
		{
			u = head->data;
			if((gr->visited)[u]==0)
			{
				(gr->distance)[u]=(gr->distance[v])+1;
				(gr->visited)[u]=1;
				queue(gr->qu, u);
			}
			head=head->link;
		}
		
	}
	
	for(int i=0; i<vtc; i++)
		printf("dist(%d,%d)=%d\n", ver1, i, gr->distance[i]);
	
	return ;
}

void display(graph *gr, int vtc)
{	
	for(int i=0; i<vtc; i++)
		printf("%d ", (gr->qu->arr)[i]);
	
	printf("\n");
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
	graph *gr;
	int vtc, ver1, ver2, dst;
	//printf("Enter the total number of vertices: ");
	scanf("%d", &vtc);
	gr = createGraph(vtc);
	while(scanf("%d %d", &ver1, &ver2)!=EOF)
	{
		addNode(&((gr->head)[ver1]), ver2);
	}
	//displayList(gr, vtc);
	breadthFirstSearch(gr, 0);
	qsort((void*)e, flag, sizeof(sort), comparator);
	for(int i=0; i<flag; i++)
		printf("(%d,%d)\n",e[i].v1, e[i].v2);
	//display(gr, vtc);	
	/*for(int i=0; i<vtc; i++)
	{	
		shortestDistance(gr, i, vtc);
	}*/
	
	for(int i=0; i<vtc; i++)
	{
		frf(gr->head[i]);
	}
	
	free(gr->head);
	free(gr->visited);
	free(gr->distance);
	free(gr->qu->arr);
	free(gr->qu);
	free(gr);
	
	return 0;
}

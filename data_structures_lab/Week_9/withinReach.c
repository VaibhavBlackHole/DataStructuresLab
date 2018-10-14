#include<stdio.h>
#include<stdlib.h>

int k=0;

typedef struct node
{
	int ver;
	struct node *link;
}node;

typedef struct queue
{
	int *arr;
	int front, rear;
}queue;

typedef struct graph
{
	node **head;
	int *vtd;
	int *dtc;
	queue *q;
}graph;

int comparator(const void *p1, const void *p2)
{
	int a = *((int*)p1);
	int b = *((int*)p2);
	return a-b;
}

graph *crGraph(int vtc)
{
	graph *gr = (graph*)malloc(sizeof(graph));
	gr->head = (node**)malloc(vtc*sizeof(node*));
	gr->vtd = (int*)malloc(vtc*sizeof(int));
	gr->dtc = (int*)malloc(vtc*sizeof(int));
	gr->q = (queue*)malloc(sizeof(queue));
	gr->q->arr = (int*)malloc(vtc*sizeof(int));
	gr->q->front = 0;
	gr->q->rear = -1;
	for(int i=0; i<vtc; i++)
	{
		gr->vtd[i]=0;
		gr->dtc[i]=100000;
		gr->head[i]=NULL;
	}
	return gr;
}

int dq(queue *q)
{
	int ver;
	if(q->front>q->rear)
		return -1;
	ver = q->arr[q->front];
	q->front = q->front+1;
	return ver;
}

void eq(queue* q, int ver)
{
	q->rear = q->rear+1;
	q->arr[q->rear]=ver;
	return;
}

void addNode(graph *gr, int ver1, int ver2)
{
	node *head;
	node *nd;
	head = gr->head[ver1];
	nd = (node*)malloc(sizeof(node));
	nd->ver = ver2;
	if(head==NULL)
	{	
		nd->link = NULL;
		gr->head[ver1]=nd;
		return;
	}
	nd->link = head;
	gr->head[ver1] = nd;
	return;
}

void bfs(graph *gr, int ver, int dtc)
{	
	node *head;
	int u,v;
	gr->dtc[ver]=0;
	gr->vtd[ver]=1;
	eq(gr->q, ver);
	while(1)
	{
		u = dq(gr->q);	
		if(u==-1)
			break;
		head = 	gr->head[u];
		while(head!=NULL)
		{
			v = head->ver;
			if(gr->vtd[v]==0)
			{
				gr->vtd[v]=1;
				eq(gr->q, v);
				gr->dtc[v]=gr->dtc[u]+1;
			}
			head=head->link;
		}
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
	graph *gr;
	int vtc, ver, dtc, ver1, ver2;
	scanf("%d%d%d", &vtc, &ver, &dtc);
	gr = crGraph(vtc);
	while(scanf("%d %d", &ver1, &ver2)!=EOF)
	{
		addNode(gr, ver1, ver2);
		addNode(gr, ver2, ver1);		
	}
	bfs(gr, ver, dtc);
	int *arr=(int*)malloc(100*sizeof(int));
	for(int i=0; i<vtc; i++)
	{
		//printf("%d\t",gr->dtc[i]);		// we calculate all the distances of the given input vertex from rest of the nodes. Then we compare it with the given input maximum distance, If it is less than or equal to it store it into the array and sort the array.
		if(gr->dtc[i]<=dtc)
		{	
			arr[k]=i;
			k++;
		}
	}
	qsort((void*)arr, k, sizeof(int), comparator);
	for(int i=0; i<k; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	for(int i=0; i<vtc; i++)
	{
		frf(gr->head[i]);
	}
	free(gr->head);
	free(gr->vtd);
	free(gr->dtc);
	free(gr->q->arr);
	free(gr->q);
	free(gr);
	free(arr);
	return 0;
}

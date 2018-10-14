#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}node;

typedef struct Graph
{
	node **head;
	int *visited;		// takes into account if any node is visited
}graph;

void insertNodeBegin(node** ad_head, int value)
{
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->data = value;
	if(*ad_head==NULL)
	{	
		nd->link = NULL;
		*ad_head = nd;
		return;  
	}
	nd->link = *ad_head;
	*ad_head = nd;
	return;
}

graph* createGraph(int vtc)
{
	graph* gr;
	int edg, ver1, ver2;
	
	gr = (graph*)malloc(sizeof(graph));
	gr->head = (node**)malloc(vtc*sizeof(node*));
	gr->visited = (int*)malloc(vtc*sizeof(int));
	
	for(int i=0; i<vtc; i++)
		(gr->head)[i]=NULL;
	
	for(int i=0; i<vtc; i++)
		(gr->visited)[i]=0;	// initializing all to be not visited
	
	printf("Enter total no of edges: ");
	scanf("%d", &edg);
	
	printf("Enter the values\n");
	for(int j=0; j<edg; j++)
	{
		scanf("%d,%d", &ver1, &ver2);
		ver1 = ver1-1;		
		ver2 = ver2-1;
		insertNodeBegin(&((gr->head)[ver1]), ver2);		// directed graph
		insertNodeBegin(&(gr->head)[ver2], ver1);		// non directed graph
	}
	return gr; 
}

void explore(graph *gr, node *head)		// head is the pointer to the ith linked list in the graph (adjacency list)
{
	int data;
	
	while(head!=NULL)
	{
		data = head->data;
		if((gr->visited)[data]==0)
		{ 
			printf("vertex %d is visited here\n", data);
			(gr->visited)[data]=1;
			explore(gr, (gr->head)[data]);
		}
		else
			head = head->link;
	}
	if(head==NULL)
	{
		//printf("No path to go, backtrack\n");
		return;	
	}
	
}

void depthFirstSearch(graph *gr, int vtc)
{
	for(int i=0; i<vtc; i++)
	{
		if((gr->visited)[i]==0)
		{
			printf("vertex %d is visited here in main\n", i);
			(gr->visited)[i]=1;
			explore(gr, (gr->head)[i]);
		}
		else 
			continue;
	}
	return;
}

void displayList(graph *gr, int vertices)
{
	node *ptr;
	for(int i=0; i<vertices; i++)
	{
		ptr = gr->head[i];
		if(ptr!=NULL)
		{
			while(ptr->link!=NULL)
			{
				printf("%d->%d ", i, ptr->data);
				ptr = ptr->link;
			}
			printf("%d->%d\n", i, ptr->data);
		}
		else
			continue;
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
	int vtc;
	printf("Enter the total number of vertices: ");
	scanf("%d", &vtc);
	gr = createGraph(vtc);	
	displayList(gr, vtc);
	
	depthFirstSearch(gr, vtc);
	
	for(int i=0; i<vtc; i++)
		frf(gr->head[i]);
		
	free(gr->head);
	free(gr->visited);
	free(gr);
	return 0;
}

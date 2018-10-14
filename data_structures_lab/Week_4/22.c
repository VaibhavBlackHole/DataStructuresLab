#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Code to parse integer from a string
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

typedef struct Queue
{
	int front, rear, capacity, current_size;
	int *q;
} queue; 

queue* make_queue(int capacity)
{
	queue* que;
	que = (queue*)malloc(sizeof(queue));
	que->front=0;					// front stores the index of first filled element 
	que->rear = -1;					// rear stores the index of last filled element
	que->capacity = capacity;
	que->current_size = 0;
	que->q = (int*)malloc(capacity*sizeof(int));
	return que;
}

int enque(queue *que, int key)		//is full if((*rear+2)%n==*front && *rear!=-1)
{
	if(que->current_size==que->capacity)
		return -1;
		
	(que->current_size)++;
	(que->rear)++;
	que->rear = (que->rear)%(que->capacity);	//(*rear)++;
	(que->q)[que->rear]=key;			//(*rear) = (*rear)%n;
							//A[*rear]=value;
	return 1;			
    /* Fill in */
}

int dequeue(queue *que)
{
	int output ;
	if(que->current_size==0)
		return -1;
		
	(que->current_size)--;
	output = (que->q)[que->front];
	(que->front)++;
	que->front = (que->front)%(que->capacity);
	return output;

    /* Insert the element key into the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
}

int peekFront(queue *que)
{
	if(que->current_size==0)
		return -1;
	return (que->q)[que->front];
    /* Delete the element A[i] from the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
}

void print(queue *que)
{
	int front=que->front;
	int rear=que->rear;
	int helper=0;
	int cap = que->capacity;
	int steps=0;
	if(que->current_size==0)
		return;
	if(front<rear)
	{
		steps=rear-front+1;
		while(steps--)
		{
			printf("%d\n", (que->q)[(que->front)+helper]);
			helper++;
		}
		return;
	}
	else if(front>rear)
	{
		steps = cap-(que->front-que->rear)+1;
		while(steps--)
		{
			printf("%d\n", (que->q)[((que->front)+helper)%cap]);
			helper++;
		}
		return;
	}
	else
		printf("%d\n", (que->q)[que->front]);
	return;
}

int size(queue *que)
{
	return que->current_size;
    /* Decrease the value of A[i] to newVal. Return 1 if the
    operation is successful and -1 otherwise. */
}

int isEmpty(queue *que)
{
	if(que->current_size==0)
		return 1;
	return 0;
    /* Ensure that the subtree rooted at A[i] is a min heap. */
}

int isFull(queue *que)
{
	if(que->current_size==que->capacity)
		return 1;
	return 0;
    /* Display the heap represented by A in the increasing order
    of their indices, one element per line.*/
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    queue* que;
    int ret;
    int lineNo = 0;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {
            que = make_queue(stoi(v1)-1);
            continue;
        }

        if(strcmp(v1,"ENQ") == 0)
        {
            ret = enque(que, stoi(v2));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"DEQ") == 0)
        {
            ret = dequeue(que);
                printf("%d\n", ret);
        }
        else if(strcmp(v1,"FRN") == 0)
        {
            ret = peekFront(que);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print(que);
        }
        else if(strcmp(v1,"SZE") == 0)
        {
            ret = size(que);
                printf("%d\n", ret);
        }
        else if(strcmp(v1,"EMP") == 0)
        {
            ret = isEmpty(que);
                printf("%d\n", ret);
        }
        else if(strcmp(v1, "FUL")==0)
        {
        	ret = isFull(que);
        		printf("%d\n", ret);
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(que)
        free(que);

    return 0;
}

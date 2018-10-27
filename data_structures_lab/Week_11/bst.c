#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int val;
	struct node *prt;
	struct node *lft;
	struct node *rgt;
}node;

int stoi(char *str)
{
	int x;
	sscanf(str, "%d", &x);	
	return x;
}

node *crNode(int val)
{
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->lft = NULL;
	nd->rgt = NULL;
	nd->val = val;
	return nd;
}

node *search(node *head, int val)
{
	if(head==NULL)
		return NULL;
	if(head->val==val)
		return head;
	else if (val>head->val)
		return search(head->rgt, val);
	else 
		return search(head->lft, val);
}

void insert(node **ad_root, node *prt, int val)
{
	node *head;
	node *sp;
	node *nd;

	head = *ad_root;
	sp = search(head, val);
	if(sp!=NULL)			
		return;
	
	if(head==NULL)
	{
		//printf("here for value %d\n", val);
		nd = crNode(val);
		nd->prt = prt;
		*ad_root=nd;
		return;
	}
	else if(val>head->val)
	{
		prt = head;
		insert(&((*ad_root)->rgt), prt, val);
	}
	else 
	{
		prt = head;
		insert((&(*ad_root)->lft), prt, val);
	}
	return;
}

node *findmax(node *head)
{
	if(head==NULL)
		return NULL;
	
	while(head->rgt!=NULL)
		head=head->rgt;
	return head;
}

node *findmin(node *head)
{
	if(head==NULL)
		return NULL;
	while(head->lft!=NULL)
		head = head->lft;
	return head;
}

void postOrder(node *head)
{
	if(head==NULL)
		return;
	//printf("here for %d ppst order\n", head->val);
	postOrder(head->lft);	
	postOrder(head->rgt);
	printf("%d ", head->val);
	return;
}

int delete(node **ad_root, int val)
{
	node *head;
	node *hp;
	
	head = *ad_root;
	head = search(head, val);
	if(head==NULL)
		return -1;
	
	if(head->lft==NULL && head->rgt==NULL)
	{
		if(head->prt==NULL)
		{
			//printf("\nHERE 1 \n");
			*ad_root=NULL;
			free(*ad_root);
			return 1;
		}
		else if(head->prt->lft==head)
		{
			//printf("\nHERE 2 \n");
			head->prt->lft=NULL;
			free(head);
			return 1;
		}
		else 
		{
			//printf("%d\n", head->prt->val);
			//printf("\nHERE 3 \n");
			head->prt->rgt=NULL;
			free(head);
			return 1;
		}
	}
	else if(head->rgt==NULL)
	{
		if(head->prt==NULL)
		{
			//printf("\nHERE 4 \n");
			*ad_root=head->lft;
			(*ad_root)->prt=NULL;
			free(head);
		}
		else if(head->prt->lft==head)
		{
			//printf("\nHERE 5\n");
			head->prt->lft=head->lft;
			head->lft->prt = head->prt;
			head->lft=NULL;
			free(head);
			return 1;
		}
		else
		{
			//printf("\nHERE 6\n");
			head->prt->rgt=head->lft;
			head->lft->prt=head->prt;
			head->lft=NULL;
			free(head);
			return 1;
		}
	}
	else if(head->lft==NULL)
	{
		if(head->prt==NULL)
		{
			//printf("\nHERE 7\n");
			*ad_root=head->rgt;
			(*ad_root)->prt=NULL;
			free(head);
		}
		else if(head->prt->lft==head)
		{
			//printf("\nHERE 8\n");
			head->prt->lft=head->rgt;
			head->rgt->prt = head->prt;
			head->rgt=NULL;
			free(head);
			return 1;
		}
		else
		{
			//printf("\nHERE 9\n");
			head->prt->rgt=head->rgt;
			head->rgt->prt = head->prt;
			head->rgt = NULL;
			free(head);
			return 1;
		}
	}
	else
	{
		//printf("\nHERE 10 \n");
		hp = findmax(head->lft);
		//printf("value of hp %d\n", hp->val);
		head->val=hp->val;
		delete(&hp, hp->val);
	}
	return 1;
}

int main()
{
	char line[127];
	char v1[15];
	char v2[15];
	node *root;
	root=NULL;
	node *pt; 
	int i;

	while(fgets(line, sizeof line, stdin)!=NULL)
	{
		sscanf(line, "%s %s", v1, v2);
		//printf("%s\n", v1);
		if(strcmp(v1, "MAX")==0)
		{
			pt = findmax(root);
			if(pt==NULL)
				printf("-1\n");
			else
				printf("%d\n", pt->val); 
		}
		else if(strcmp(v1, "MIN")==0)
		{
			pt = findmin(root);
			if(pt==NULL)
				printf("-1\n"); 
			else
				printf("%d\n", pt->val); 
		}
		else if(strcmp(v1, "DEL")==0)
		{
			if(stoi(v2)<0)
				i=-1;
			else
				i = delete(&root, stoi(v2));
			if(i==-1)
				printf("-1\n");
		}
		else if(strcmp(v1, "INS")==0)
		{
			if(stoi(v2)>=0)
				insert(&root, NULL, stoi(v2));
		}
		else if(strcmp(v1, "PST")==0)
		{
			if(root==NULL)
				printf("-1\n");
			else
			{ 
				postOrder(root);
				printf("\n");
			}		
		}
		else 
			continue;
	}
}

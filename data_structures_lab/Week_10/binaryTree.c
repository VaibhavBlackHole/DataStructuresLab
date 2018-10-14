#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int occ = 0;
int ind=1;

typedef struct node
{
	int val, idx;
	struct node *lft, *rgt;
}node;

int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

node *createNode(int val, int idx)
{
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->idx = idx;
	nd->val = val;
	nd->lft = NULL;
	nd->rgt = NULL;
	return nd;
}

node *search(node *root, int idx)
{
	if(root==NULL)
		return NULL;
	node *sp;
	if(root->idx==idx)
		return root;
	sp = search(root->lft, idx);
	if(sp!=NULL)
		return sp;
	return search(root->rgt, idx);
}

node *insNode(node *root, int val, int idx, char c)
{	
	node *sp;
	sp = search(root, idx);
	if(sp==NULL)
		return NULL;	
	if(c=='l')
	{
		if(sp->lft!=NULL)
			return NULL;
		sp->lft = createNode(val, ind+1);
		ind++;
		return sp->lft;
	}
	else
	{
		if(sp->rgt!=NULL)
			return NULL;
		sp->rgt = createNode(val, ind+1);
		ind++;
		return sp->rgt;
	}
}

void occurence(node *root, int k)
{
	if(root==NULL)
		return;
	if(root->val==k)
		occ++;
	occurence(root->lft, k);
	occurence(root->rgt, k);
	return;
}

void ppOrder(node *root)
{
	if(root==NULL)
		return;
	printf("%d ", root->val);
	ppOrder(root->lft);
	ppOrder(root->rgt);
	return;
}

void pinOrder(node *root)
{
	if(root==NULL)
		return;
	pinOrder(root->lft);
	printf("%d ", root->val);
	pinOrder(root->rgt);
	return;
}

void pstOrder(node *root)
{
	if(root==NULL)
		return;
	pstOrder(root->lft);
	pstOrder(root->rgt);
	printf("%d ", root->val);
	return;
}

void ffree(node *root)
{
	if(root==NULL)
		return;
	else if(root->lft==NULL && root->rgt==NULL)
	{
		free(root);
		return;
	}
	else if(root->lft==NULL)
	{
		ffree(root->rgt);
		free(root);
	}
	else if(root->rgt==NULL)
	{
		ffree(root->lft);
		free(root);
	}
	else 
	{
		ffree(root->lft);
		ffree(root->rgt);
		free(root);
		return;
	}
	return;
}

int main (int argc, char **argv)
{
	char line[128];
    char v1[15];
    char v2[15];
    char v3[15];
	char v4[15];
	int i=0;
	node *root;
	node *pt;
	int val;
	scanf("%d", &val);
	root = (node*)malloc(sizeof(node));
	root->lft = NULL;
	root->rgt = NULL;
	root->val = val;
	root->idx = 1;
	
	while(fgets(line, sizeof(line), stdin)!=NULL)
	{
		sscanf(line, "%s %s %s %s", v1, v2, v3, v4);
		if(strcmp(v1, "INS")==0)
		{
			pt = insNode(root, stoi(v2), stoi(v3), v4[0]);
			if(pt==NULL)
				printf("-1\n");
			
		}		
		else if(strcmp(v1, "PRE")==0)
		{
			ppOrder(root);
			printf("\n");
		}
		else if(strcmp(v1, "INO")==0)
		{
			pinOrder(root);
			printf("\n");		
		}		
		else if(strcmp(v1, "PST")==0)
		{
			pstOrder(root);
			printf("\n");
		}		
		else if(strcmp(v1, "OCC")==0)
		{
			occurence(root, stoi(v2));
			printf("%d\n", occ);
			occ=0;
		}
	}
	
	ffree(root);
	//free(root);
	return 0; 	
}


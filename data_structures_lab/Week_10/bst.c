#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int val;
	struct node *lft, *rgt, *prt;
}node;

int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

node *createNode(int val)
{
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->val = val;
	nd->lft = NULL;
	nd->rgt = NULL;
	return nd;
}

node *search(node *root, int val)
{
	node *pt;
	if(root==NULL)
		return NULL;
	if(root->val==val)
		return root;
	else if(root->val>val)
	{
		pt = search(root->lft, val);
		return pt;
	}
	else 
	{
		pt = search(root->rgt, val);
		return pt;
	}	
}

void insNode(node **ad_root, int val, node *prt)
{
	if(search(*ad_root, val) != NULL)
		return;
	node *nd; 
	if(*ad_root==NULL)
	{
		nd = createNode(val);
		nd->prt = prt;
		*ad_root = nd;
		//printf("%p\n", nd->prt);
		return;	 
	}
	else if((*ad_root)->val>val)
	{
		prt = *ad_root;
		insNode(&((*ad_root)->lft), val, prt);
		return;
	}
	else if((*ad_root)->val<val)
	{
		prt = *ad_root;
		insNode(&((*ad_root)->rgt), val, prt);
		return;	
	}
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
	//printf("%p\n", root);
	if(root==NULL)
		return;
	pstOrder(root->lft);
	pstOrder(root->rgt);
	printf("%d ", root->val);
	return;
}

node* fMin(node *root)
{
	if(root==NULL)
		return NULL;
	if(root->lft==NULL)
		return root;
	else 	
		return fMin(root->lft);
}

node* fMax(node *root)
{
	if(root==NULL)
		return NULL;
	if(root->rgt==NULL)
		return root;
	else
		return fMax(root->rgt);
}	

int deleteNode(node *root, int val)
{
	node *pt;
	pt = search(root, val);
	//printf("%p\n",pt);
	node *hpt;
	if(pt==NULL)
		return -1;

	if(pt->lft==NULL && pt->rgt==NULL)
	{
		//printf("removed: %d\n", pt->val);
		if(pt->prt==NULL)
		{
			free(pt->prt);
			free(pt);
			return 1;
		}
		else if(pt->prt->lft==pt)
			pt->prt->lft = NULL;
		else
			pt->prt->rgt = NULL;
		free(pt);
		return 1;
	}
	else if(pt->lft==NULL)
	{
		if(pt->prt->lft==pt)
		{
			//printf("removed: %d\n", pt->val);
			pt->prt->lft = pt->rgt;
			pt->rgt =NULL;
			free(pt);
			return 1;
		}
		else
		{
			//printf("removed: %d\n", pt->val);
			pt->prt->rgt = pt->rgt;
			pt->rgt =NULL;
			free(pt);
			return 1;
		}
	}
	else if(pt->rgt==NULL)
	{
		if(pt->prt->lft==pt)
		{
			//printf("removed: %d\n", pt->val);
			pt->prt->lft = pt->lft;
			pt->lft =NULL;
			free(pt);
			return 1;
		}
		else
		{
			//printf("removed: %d\n", pt->val);
			pt->prt->rgt = pt->lft;
			pt->lft =NULL;
			free(pt);
			return 1;		
		}
	}
	else
	{		
		//printf("removed: %d\n", pt->val);
		//printf("valur:%d\n", hpt->lft->val);
		hpt = fMin(pt->rgt);
		pt->val = hpt->val;
		return deleteNode(hpt, hpt->val);
		//printf("%d\n", hpt->val);
		/*if(hpt->prt->lft==hpt)
		{
			hpt->prt->lft = hpt->rgt;
			hpt->rgt=NULL;
			free(hpt);
			return 1;
		}
		else
		{
			hpt->prt->rgt = hpt->rgt;
			hpt->rgt =NULL;
			free(hpt);
			return 1;
		}*/			
	}
	
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

	int i=0;
	node *root;
	node *pt;
	root = NULL;
	while(fgets(line, sizeof(line), stdin)!=NULL)
	{
		sscanf(line, "%s %s %s", v1, v2, v3);
		if(strcmp(v1, "INS")==0)
		{
			insNode(&root, stoi(v2), NULL);
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
		else if(strcmp(v1, "DEL")==0)
		{
			i = deleteNode(root, stoi(v2));
			if(i==-1)
				printf("-1\n");
		}		
		else if(strcmp(v1, "SER")==0)
		{
			pt = search(root, stoi(v2));
			if(pt==NULL)
				printf("N\n");	
			else
				printf("Y\n");
		}
		else
			continue;
	}
		
	ffree(root);
	return 0; 	
}

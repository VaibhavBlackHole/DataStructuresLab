#include<stdio.h>
#include<stdlib.h>

struct st_details  // Stores student's details
{
	int roll_no;
	char name[20];
};

int main()
{
	int n;
	struct st_details *ptr, *p;
	
	printf("Give total no of students: ");
	scanf("%d", &n);
	ptr = (struct st_details *)malloc(n*sizeof(struct st_details));
	p = ptr;
	for(int i=0; i<n; i++)
	{
			printf("Give roll_no and name: ");
			scanf("%d%s", &(ptr->roll_no), (ptr->name));
			//ptr+=1;
			ptr+= sizeof(struct st_details);
	}

	ptr = p;
	for(int i=0; i<n; i++)
	{
			printf("roll_no:%d\tname:%s\n", ptr->roll_no, ptr->name);
			//scanf("%d%s", ptr.roll_no, ptr.name);
			ptr+= sizeof(struct st_details);
	}

	//free(ptr);

	return 0;
}

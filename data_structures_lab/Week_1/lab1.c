#include<stdio.h>
#include<stdlib.h>

char* slope(int x1,int y1, int x2, int y2, int x3, int y3)
	{
		float slope1 , slope2;
		char *win;
 		win = (char*)(malloc(3*sizeof(char)));
		slope1 = 1.0*(y2-y1)/(x2-x1);
 		slope2 = 1.0*(y3-y2)/(x3-x2);
		if(slope1==slope2){
			*(win) = 'Y';
			*(win+1)	= 'e';
			*(win+2)	= 's';	
			return win;
						}
		else {
			*(win)= 'N';
			*(win+1)= 'o';
			return win;
			}
    }

struct collinear
{
	int x, y;
};

int main()
{
	int ar[3] = {1, 2, 3};
	char array[3]={'1','0', '4'};
	char *win;
    int darray[2][3]= {{1, 2, 3},{5, 6, 7}};
    void *pointer = &ar;
    int *ptr, value;
    char *ap;
 	struct collinear coordinate1, coordinate2, coordinate3;

    ptr = &value;
    ap = array;
    value = 20;
	printf("Hello World\n");
    printf("Size of int is %ld\n", sizeof(int));
	printf("Size of char is %ld\n", sizeof(char));
	printf("Size of float is %ld\n", sizeof(float));
    printf("Size of double is %ld\n", sizeof(double));
    printf("Size of array is %ld\n", sizeof(array));
    printf("Address of value is %p\n", ptr);
    printf("Value is through pointer is %d\n", *ptr);
	printf("Value is %d\n", value);
	for(int i=0; i<3; i++)
    {
  		printf("Value at ap is %d\n", *ap);
        printf("Address is %p\n", ap);
		ap++;
    }
 
    printf("%p\n", *(darray+1));
	printf("%d\n", *(*(darray+1)+2));

	printf("%d\n", *(int*)pointer);
    pointer += sizeof(int);
    printf("%d\n", *(int*)pointer);

	printf("Give 3 points in 2d:");
    scanf("%d%d", &coordinate1.x, &coordinate1.y);
 	scanf("%d%d", &coordinate2.x, &coordinate2.y);
	scanf("%d%d", &coordinate3.x, &coordinate3.y);
	win = slope(coordinate1.x, coordinate1.y, coordinate2.x, coordinate2.y, coordinate3.x, coordinate3.y);
    printf("%s", win);
}

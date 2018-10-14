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

void shift(int A[])
{
    /* Fill in */

}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int *A = NULL;
    int n,i;

    fgets(line, sizeof line, stdin);
    sscanf(line, "%s", v1);
    n=stoi(v1);
    A = (int*) malloc(sizeof(int)* n);
    for(i=0;i<n;i++)
    {
	fgets(line, sizeof line, stdin);
	sscanf(line, "%s", v1);
	A[i]= stoi(v1);
    }
    shift(A);

    if(A)
        free(A);

    return 0;
}

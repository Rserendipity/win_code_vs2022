#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX 100

typedef struct AMG_Graph {
    int vexSize;
    int edgeSize;
    char vex[MAX_VEX];
    int edge[MAX_VEX][MAX_VEX];
} AMG_Graph;

AMG_Graph* AMGinit()
{
    AMG_Graph* graph = (AMG_Graph*)calloc(sizeof(AMG_Graph), 1);
    printf("Input Vex nums:>");
    scanf("%d", &graph->vexSize);
    printf("Input Edge nums:>");
    scanf("%d", &graph->edgeSize);

    return graph;
}

int main() 
{
    AMG_Graph* graph = AMGinit();




    return 0;
}
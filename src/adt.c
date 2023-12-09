#include "adt.h"
#include <stdlib.h>
#include <stdio.h>

void createGraph(Graph* graf, int x){
    graf->matrix = (int**)malloc(x*sizeof(int *));
    if (graf->matrix!=NULL){
        for (int i=0;i<x;i++){
            graf->matrix[i] = (int*)malloc(x*sizeof(int));
            graf->len = x;
            for (int j=0;j<x;j++){
                graf->matrix[i][j] = 0;
            }
        }
    }
}

void keyAppend(keyList* keyL, Key keyG){
    keyList p1 = (keyList)malloc(sizeof(KeyMsg));
    keyList p = *keyL;
    if (p1!=NULL){
        p1->info = keyG;
        p1->next = NULL;
        if (*keyL!=NULL){
            while (p->next !=NULL)
            {
                p = p->next;
            }
            p->next = p1;
        }else{
            *keyL = p1;
        }
       
    }else{
        printf("failed to malloc\n");
    }
}

void graphAppend(graphList* grafL, Graph grafVal){
    graphList g1 = (graphList)malloc(sizeof(Graph));
    graphList g = *grafL;
    if (g1!=NULL){
        g1->graf = grafVal;
        g1->next = NULL;
        if (*grafL!=NULL){
            while (g->next !=NULL)
            {
                g = g->next;
            }
            g->next = g1;
        }else{
            *grafL = g1;
        }
        
    }else{
        printf("failed to malloc\n");
    }
}
void displayGraph(Graph g){
    for (int i=0;i<g.len;i++){
        for (int j=0;j<g.len;j++){
            printf("%d ",g.matrix[i][j]);
        }
        printf("\n");
    }
}
#include "adt.h"
#include <stdlib.h>
#include <stdio.h>

void createGraph(Graph* graf, int x){
    graf->matrix = (int**)malloc(x*sizeof(int *));
    if (graf->matrix!=NULL){
        for (int i=0;i<x;i++){
            graf->matrix[i] = (int*)malloc(x*sizeof(int));
            for (int j=0;j<x;j++){
                graf->matrix[i][j] = 0;
            }
        }
    }
}

void keyAppend(keyList keyL, Key keyG){
    keyList p1 = (keyList)malloc(sizeof(KeyMsg));
    keyList p = keyL;
    if (p1!=NULL){
        p1->info = keyG;
        p1->next = NULL;
        while (p->next !=NULL){
        p = p->next;
         }
        p->next = p1;
    }
}

void graphAppend(graphList grafL, Graph grafVal){
    graphList g1 = (graphList)malloc(sizeof(Graph));
    graphList g = grafL;
    if (g1!=NULL){
        g1->graf = grafVal;
        g1->next = NULL;
        while (g->next !=NULL)
        {
            g = g->next;
        }
        
    }
}
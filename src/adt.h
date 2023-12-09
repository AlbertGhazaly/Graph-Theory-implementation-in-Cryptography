#ifndef ADT_H
#define ADT_H

typedef struct graph
{
    int **matrix;
} Graph;


typedef struct key
{
    int first;
    int last;    
} Key;


// package message

#define keyList struct keyMsg*
typedef struct keyMsg
{
    Key info;
    keyList next;
} KeyMsg;

#define graphList struct graphMsg*
typedef struct graphMsg
{
    Graph graf;
    graphList next;
} GraphMsg;

typedef struct message
{
    int len;
    graphList gList;
    keyList kList;
}Message;

#define Next(x) x->next
#define Graph(x) x->graf
#define key(x) x->key

void createGraph(Graph* graf, int x);
void keyAppend(keyList keyL, Key keyG);
void graphAppend(graphList grafL, Graph grafVal);

#endif

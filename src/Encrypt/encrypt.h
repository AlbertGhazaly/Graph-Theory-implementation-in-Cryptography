#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "../ADT/adt.h"

void charToBinary(char x, int res[7]);
int countOne(int bin[7]);
void shuffle(int arr[], int len);
int countZero(int arr[],int x);
void msgToGraf(Graph* graf, int len, int arr[7],keyList* kList);
Message encrypt(char text[], keyList* kList);

#endif
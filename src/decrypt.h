#ifndef DECRYPT_H
#define DECRYPT_H
#include "adt.h"
void grafToBin(Graph graf,Key koenci,int arr[]);
char binToChar(int arr[]);
char*decrypt(Message msg, keyList kList);
#endif
#include "encrypt.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void charToBinary(char x, int res[7]){
    int divd = 64;
    int i=0;
    for (;divd!=0;divd=divd/2){
        if (x>=divd){
            res[i] = 1;
            x -= divd;
        }else{
            res[i] = 0;
        }
        i++;
    }
}
int countOne(int bin[7]){
    int cnt =0;
    for (int i=0;i<7;i++){
        if (bin[i]==1){
            cnt++;
        }
    }
    return cnt;
}
void shuffle(int arr[], int len){
    for (int i=0;i<len;i++){
        arr[i] = i+1;
    }
    for (int i=len-1;i>0;i--){
        int ranNum = (rand() % (i+1));
        int temp = arr[i];
        arr[i] = arr[ranNum];
        arr[ranNum] = temp;

    }
}
int countZero(int arr[],int x){
    int sum = 0;
    int i =0;
    int cnt = 0;
    boolean found = false;
    while (i<7 && !found)
    {
        if (arr[i]==1){
            cnt++;
        }
        if (cnt==x){
            found = true;
        }
        i++;
    }
    for (;arr[i]!=1 && i<7;i++){
        sum ++;
    }
    return sum+1;
}
void msgToGraf(Graph* graf, int len, int arr[7],keyList* kList){
    int order[len];
    shuffle(order,len);
    int first = order[0];
    int last = order[len-1];
    for (int i=0;i<len-1;i++){
        graf->matrix[order[i]-1][order[i+1]-1] = countZero(arr,i+1);
        graf->matrix[order[i+1]-1][order[i]-1] = countZero(arr,i+1);
    }
    graf->matrix[first-1][last-1] = countZero(arr,len);
    graf->matrix[last-1][first-1] = countZero(arr,len);
    Key koenci = {first,last};
    keyAppend(kList,koenci);
}
Message encrypt(char text[], keyList* kList){
    Message msg;
    msg.gList = NULL;
    int len = 0;
    for (;text[len]!='\0';len++);
    msg.len = len;
    int xor = 85; //1010101
    srand((unsigned int)(time(NULL)) ^ getpid());
    for (int i=0;i<len;i++){
        char karakter = text[i] ^xor;
        int arr[7];
        charToBinary(karakter,arr);
        int one = countOne(arr);
        Graph graf;
        createGraph(&graf,one);
        msgToGraf(&graf,one,arr,kList);
        graphAppend(&msg.gList,graf);

    }
    return msg;
}

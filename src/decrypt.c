#include "decrypt.h"
#include <stdio.h>
#include <stdlib.h>

char binToChar(int arr[]){
    int sum =0;
    int x = 64;
    for (int i=0;i<7;i++){
        if (arr[i]==1){
            sum += x;
        }
        x = x/2;
    }
    return sum;
}

void grafToBin(Graph graf,Key koenci,int arr[]){
    int i;
    for (i=0;i<7;i++){
        arr[i] = 0;
    }
    int first = koenci.first;
    i = koenci.last-1;
    int prev = first-1;
    boolean stop = false;
    int id=6;
    if (koenci.first!=koenci.last){
        if (graf.len==2){
            int x = graf.matrix[i][prev];
            for (int k=1;k<x;k++){
                arr[id] = 0;
                id--;
            }
            arr[id]=1;
            id--;
            x = graf.matrix[prev][i];
            for (int k=1;k<x;k++){
                arr[id] = 0;
                id--;
            }
            arr[id]=1;
            id--;
        }else{
            while (!stop)
            {
                int j;
                if (i==koenci.last-1){
                    int x = graf.matrix[i][prev];
                    for (int k=1;k<x;k++){
                        arr[id] = 0;
                        id--;
                    }
                    arr[id]=1;
                    id--;
                }
                for (j=0;i<graf.len && (graf.matrix[i][j]==0 || j==prev);j++);
                int x = graf.matrix[i][j];
                for (int k=1;k<x;k++){
                    arr[id] = 0;
                    id--;
                }
                arr[id]=1;
                id--;
                prev = i;
                i = j;
                if (i==koenci.first-1){
                    stop = true;
                }
            }
        }
    }else{
        int x = graf.matrix[0][0];
        for (int k=1;k<x;k++){
            arr[id] = 0;
            id--;
        }
        arr[id] = 1;
        id--;
    }  
}
char* decrypt(Message msg, keyList kList){
    char* decryptedMsg = malloc((msg.len + 1) * sizeof(char));
    int xor = 127;
    graphList g = msg.gList;
    keyList k = kList;
    for (int i=0;i<msg.len;i++){
        char karakter;
        int arr[7];
        grafToBin(g->graf,k->info,arr);
        karakter = binToChar(arr);
        g = g->next;
        k = k->next;
        decryptedMsg[i] = karakter^xor;
    }
    return decryptedMsg;
}
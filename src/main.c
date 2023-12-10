#include "./Encrypt/encrypt.h"
#include "./Decrypt/decrypt.h"
#include <stdio.h>


int main(){
    char text[100];
    printf("Text a message: ");
    scanf("%s",text);
    Message msg;
    keyList kList;
    msg = encrypt(text,&kList);
    graphList g = msg.gList;
    keyList k = kList;
    char *decryptedText = decrypt(msg,kList);
    printf("Encryption result: \n");
    int i=0;
    while (g!=NULL)
    {
        printf("\nchar: %c\n",decryptedText[i]);
        printf("key: {%d %d}\n",k->info.first,k->info.last);
        displayGraph(g->graf);    
        printf("\n");
        i++;
        g = g->next;
        k = k->next;
    }
    
    printf("The decrypted Text: %s\n",decryptedText);
    return 0;
}
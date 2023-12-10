# Cryptography-Graph-Theory-Implementation-in-Text-Encryption-and-Decryption
### Author: Albert Ghazaly
<br>

## Program Description
This C program is made for encrypting message by using graph theory, especially hammilton graph. In addition, the encryption process also uses XOR Chipper. The decryption also uses the same theory as the encryption does. 

The source code is at src folder, the abstract data type used (Graph, Key, etc) is in ADT folder, encryption program is in Encryption folder, and decryption program is in Decryption folder. The main program is to implement both encryption and decryption process, so user can use both at the same time.

## How to Use
1. go to folder src

        cd src

2. compile the main program (copy this command to your CLI)

        gcc -o main main.c ./ADT/adt.c  ./Encrypt/encrypt.c ./Decrypt/decrypt.c

3. Start the program

        ./main
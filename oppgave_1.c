#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fillAr(char *, char *, int );


void main(){

    char ar[100]="please";
    char *A;
    A =(char*)malloc(100*sizeof(char));
    int n = strlen(ar);
    Palindrom(ar, A, n);
    
}

void Palindrom(char *b, char *a, int n){
    int i =0;

    while(i<n){
        a[i]=b[n-i-1];
        i++;
    }
    // printf("%s\n", a);
    
    
    if(strcmp(a,b)==0){

        printf("true\n");
        return 1;
    
    }else{
         printf("false\n");
        return 0;
        
    }

}

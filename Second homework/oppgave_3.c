#include <stdio.h>
#include <stdlib.h>


long double  F[1500]; 

long double fib(int n){
    F[0]=0; 
    F[1]=1;
    long double  j=0; //F[0]
    long double k=1; //F[1]
    int i=2;
    long double temp,s;


    while(i<n){

        s = j+k;
        F[i]=s;
        temp=k;
        j=temp;
        k=s;
        i++;
    }
}
void main(){

    int num=0;
    FILE * f;
    f= fopen("doc.txt", "w");

    int x;
    printf("please insert a number\n");
    scanf("%d", &x );
    printf("your N is %d\n", x);
    fib(x);

    while(num<x){
        
        fprintf(f, "%0.0Lf\n", F[num]);
        num++;
    }
    printf("doc.txt is ready :)\n");

    fclose(f);

    

}
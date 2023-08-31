#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mycmpFunction(char * string1, char * string2){
    //if string1 and string2 are equal then strcmp returns 0, otherwise 1 
    return strcmp(string1, string2);

}


char checkEquality(char A[], char B[]){
    if(mycmpFunction(A,B)==0){
        printf("equal\n");
    }
    else{
        printf("words are not equal\n");

    }

}
int palindrom( char * S1){
    int sizeS1 = strlen(S1);
    
}

int main(){


    char A[]= "Black Hawk";
    char B[]= "Black Hawk";
    checkEquality(A,B);

    


}
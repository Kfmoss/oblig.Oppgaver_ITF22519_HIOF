#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void fillArray(int *, int );
void writeArray(const int *, int);



int main(){


    int selected_n, *Array;
    printf("please insert number of elements : \n");
    scanf("%d", &selected_n);

    
    Array=(int*)malloc(selected_n*sizeof(int));
    if(Array==NULL){
        printf("Impossible to allocate memory!!!!!");
        return 1;
    }

    fillArray(Array,selected_n);
    writeArray(Array,selected_n);
  

    free(Array);
}

void fillArray(int *a, int b){
    int i;

    for(i=0;i< b;i++ ){
        printf("insert a number\n");
        scanf("%d", a);
        a++;


        // printf("the value of q is %d",q);

        printf("\n");

    }


}
void writeArray(const int *a, int b){
    int in = b;
    for(int e =0; e<b; e++){
        printf("%d",*a);
        a++;


    }
    printf("\n now in oposite order\n");
    while(in>0){
        a--;
        printf("%d", *a);
        in--;
        
    }

}


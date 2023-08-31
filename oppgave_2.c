#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RMAX 1000


int arr2 [RMAX];
int i=0;




int quickSort(int a[RMAX], int first, int last){
    //initialize 4 variables to sort elements
    int i, j, pivot, temp;
    //comparison between first and last element in the array. if this is true then...
    if(first<last){
        //pivot and i (0) get value of first element and j(999) the value of last one.
        pivot=first;
        i=first;
        j=last;
        printf("first j is %d\n", j);
        // while the value of i is less than j then..
        while(i<j){
            //while the value of elemnet in index i is less than value of element 
            // pivot index and the value of i is less than value of "last" then...
            while(a[i]<=a[pivot]&& i<last){
                //add 1 to value of i
                i++;
            }
            // while the value of element in index j (which was previously got value of last (index))
            // and the value of element in index pivot(got previously the value of first)
            while(a[j]>a[pivot]){
                //value of j reduces by 1
                j--;
                printf("value of j is %d\n", j);
            }
            //if still value of i is less thanvalue of j then...
            if(i<j){
                //swap value of elem in index i for  value of elem in index j
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        //if value of first and last are the same  then...
        //use temp to swap values...
        temp=a[pivot];
        //
        a[pivot] = a[j];
        a[j]= temp;
        printf("value of last j is %d\n", j);
        
        quickSort(a,first, j-1);
        quickSort(a, j+1, last);
    }
}

int main()
{
    // the loop fills up the array 

    while(i<RMAX){
        arr2[i] = rand()%100000;
        //this shows elements in array
        printf("the value in index %d is %d\n", i,arr2[i]);
        i++;
    }
    //call the function to sort elements 
    quickSort(arr2, 0,RMAX-1 );

    //printing values...
    printf(" ********  after array is sorted from the lowest to the largest value\n");
    printf(" ******** the smallest value is %d \n ****** and the largest is %d\n", arr2[0], arr2[RMAX-1]);

  
}
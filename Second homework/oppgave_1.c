/*
oppgave 1

        100
        __
   S=   \       n²
        /__
        n=0
*/

#include <stdio.h>
#include <stdlib.h>


// array with 101 elements
int arr[101];

// "counter" contains the value of "n"
// "s" will show result of sume of all values in arr

int counter,s  =0;

int main(){
    // array index starts from 0
    int i=0;

    while (counter<=100)
    {   
        // insert the value of srtq(n) == counter*counter
        arr[i] = counter*counter;
        // add value of elements in s
        s += arr[i];
        // value of counter and i plus 1
        i, counter++;
        //check value just in case something went wrong...
        // printf("value of counter %d\n", arr[i]);

    }
    printf("show result sum of all values in array: %d\n", s);
    
    /*
    //check lenght of array

    size_t lenghtArr = sizeof(arr)/sizeof(arr[100]);
    printf("%lu\n", lenghtArr);
   
    */


}


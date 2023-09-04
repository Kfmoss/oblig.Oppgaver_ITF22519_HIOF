#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct process
{
    int nummer; 
   char status;
   float start_tid;
   float CPU_tid;
}prosess_t;



prosess_t *kopier( prosess_t);

int main(){

// dette her er bare for å eksperimentere med med pekker og strukturer.
    prosess_t b, *b_p;
    b_p=&b;
    b.CPU_tid=2;
    b.nummer=6;
    b.start_tid=9;
    b.status='C';

    // her lager jeg en peker peker som tar imot pekeren returnert fra funksjonen kopier.

    prosess_t *check_kopi = kopier(b);

    printf("%d, %c, %f, %f ", b.nummer,b.status, b.start_tid, b.CPU_tid);
    printf("\n");
    printf("%d, %c, %f, %f ", b_p->nummer,b_p->status, b_p->start_tid, b_p->CPU_tid);

    // og her printer alle verdier i peker check_kopi.
    printf("\n");
    printf("%d, %c, %f, %f ", check_kopi->nummer,check_kopi->status, check_kopi->start_tid, check_kopi->CPU_tid);



}

prosess_t *kopier(prosess_t original){
    prosess_t *p_box, box;
    p_box=&box;
    p_box= (prosess_t *)malloc(100*sizeof(prosess_t));
    // det finnes sikkert andre metode til å kopiere verdier i original, men det fungerte også fint.
    p_box->CPU_tid=original.CPU_tid;
    p_box->nummer=original.nummer;
    p_box->status = original.status;
    p_box->start_tid = original.start_tid;

    return p_box; 
}

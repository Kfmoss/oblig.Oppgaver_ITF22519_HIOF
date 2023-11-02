#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur som lagrer data om en page frame
struct page_frame
{
   int id;   // Page-ID/-number
   int load; // Tidspunkt da pagen ble lagt inn i RAM
   int last; // Tidspunkt da pagen siste ble referert til
   int R;    // Referenced bit
   int M;    // Modified bit
};

// Globale variabler
int T = 300;           // Systemtid, settes til passende verdi
int N;                 // Antall prosesser
struct page_frame *PF; // Peker til array med page frames

// read_file(): Leser data for N page frames fra fil. Pages skal
// ligge sortert på ankomsttid. Alle data må være ikke-negative
// heltall. Alle tider oppgis i hele tidsenheter. Filformat:
//
//    N
//    id load last R M
//    id load last R M
//    id load last R M
//    ...
//
void read_file(char *filename)
{
   int i;
   FILE *p_file;
   
   // Åpner fil og sjekker for feil i åpning
   p_file = fopen(filename, "r");
   if (p_file == NULL)
   { 
      printf("Feil ved åpning av filen \"%s\"\n", filename); 
      exit(-1);
   }

   // Leser antall page frames
   fscanf(p_file, "%d", &N);

   // Oppretter array med plass til alle pages
   PF = (struct page_frame *) malloc(N * sizeof(struct page_frame));

   // Leser inn en og en page frame.
   for (i = 0; i < N; i++)
      fscanf(p_file, "%d %d %d %d %d", &PF[i].id, &PF[i].load,
	      &PF[i].last, &PF[i].R, &PF[i].M);
   fclose(p_file);
}

//first_in_first_out(): Simulering av page replacement med FIFO
//

int compareInt(const void *a, const void *b)
{
    const int *p1 = a;
    const int *p2 = b;
    return *p1 - *p2; 
    
}
void first_in_first_out()
{
   // Skal programmeres ferdig i oppgave 1

   /*
   variabler 
   */
  int i=0 , x=0, pivot1=0;
  int tmp[N];

  while(i<N){
    tmp[i]= PF[x].load;
    i++;
    x++;
  }
  qsort(tmp, N, sizeof(int), compareInt); // denne linjen returnerer en sortert list fra minste til største verdien.


  while(pivot1<N){
    if(tmp[0]== PF[pivot1].load){
        
        printf(" First in first out \n Page : %d    Loaded: %d   Last ref: %d  R:  %d  M:  %d \n \n", PF[pivot1].id,PF[pivot1].load, PF[pivot1].last, PF[pivot1].R, PF[pivot1].M );
    }
    pivot1++;
  }  


}

//least_recently_used(): Simulering av page replacement med LRU
//
void least_recently_used()
{
    int i =0, x=0, pivot1=0;
    int tmp[N];
    while(i<N){
        tmp[i]= PF[x].last;
        i++;
        x++;
    }
    qsort(tmp, N, sizeof(int), compareInt); // denne linjen returnerer en sortert list fra minste til største verdien.

    while (pivot1<N)
    {
        if(tmp[0]==PF[pivot1].last){
            printf("least recently used \n  Page : %d    Loaded: %d   Last ref: %d  R:  %d  M:  %d \n \n", PF[pivot1].id,PF[pivot1].load, PF[pivot1].last, PF[pivot1].R, PF[pivot1].M);
        }
        pivot1++;
    }
    

}

//second_chance(): Simulering av page replacement med Second Chance

void second_chance(){
    int i =0, x =0, z =0, c =0, c2=0, c3=0, c4=0, tr1=0, load, id,last, r, m;
    int tmp[N];


    while(i<N){
        tmp[i] = PF[x].load;
        i++;
        x++;
    }
    //sort the temp list with "last" values on it.
    qsort(tmp, N, sizeof(int), compareInt);

    for(int pl=0; pl<N; pl++){
        for(int px =0; px<N; px++){
            if(tmp[0]==PF[px].load){
                id = PF[px].id;
                load= PF[px].load;
                last = PF[px].last;
                r=PF[px].R;
                m=PF[px].M;
                PF[px].load =300;
                PF[px].R=0;
                tmp[0] = T;
                qsort(tmp, N, sizeof(int), compareInt);
                c++;
            }
            if(c==N-1){
                
                break;
            }
        }
    }
    printf( "Second Chance \n Page: %d Loaded: %d Last ref: %d  R: %d  M: %d\n",id,load,last,r, m );

  

    
}

int main()
{
   char filename[100];

   // Leser filnavn fra bruker
   printf("File? ");
   scanf("%s", filename);

   // Leser inn prosessdataene
   read_file(filename);

   // Simulerer page replacement
   first_in_first_out();
   least_recently_used();
   second_chance();

}
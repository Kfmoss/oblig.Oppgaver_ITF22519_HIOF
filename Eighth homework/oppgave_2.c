#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur som lagrer data om en prosess
struct process
{
   int id;      // Prosess-ID
   int arrive;  // Tidspunkt da prosessen ble satt inn i kø 
   int cpu;     // Total CPU-tid som prosessen krever
   int start;   // Tidspunkt da prosessen startet å kjøre
   int end;     // Tidspunkt da prosessen er ferdig
};


// Globale variabler
int T = 0;         // Systemtid, starter simulering ved tid lik 0
int N;             // Antall prosesser
struct process *P; // Peker til array med prosessene

// read_file(): Leser data for N prosesser fra fil. Prosessene skal
// ligge sortert på ankomsttid. Alle data må være ikke-negative
// heltall. Alle tider oppgis i hele tidsenheter. Filformat:
//
//    N
//    id arrive CPU
//    id arrive CPU
//    id arrive CPU
//    ...
//


void read_file(char *filename)
{
   int i, last_arrive = 0;
   FILE *p_file;
   
   // Åpner fil og sjekker for feil i åpning
   p_file = fopen(filename, "r");
   if (p_file == NULL)
   { 
      printf("Feil ved åpning av filen \"%s\"\n", filename); 
      exit(-1);
   }

   // Leser antall prosesser
   fscanf(p_file, "%d", &N);

   // Oppretter array med plass til alle prosessene
   P = (struct process *) malloc(N * sizeof(struct process));

   // Leser inn en og en prosess. Prosessene skal ligge sortert på
   // ankomsttid i filen, hvis ikke gis en feilmelding.
   for (i = 0; i < N; i++)
   {
      fscanf(p_file, "%d %d %d", &P[i].id, &P[i].arrive, &P[i].cpu);
      P[i].start = P[i].end = 0;
      
      if (P[i].arrive < last_arrive)
      { 
	 printf("Feil i ankomsttider, prosess %d\n", P[i].id); 
         exit(-1);
      }
      last_arrive = P[i].arrive;
   }
   fclose(p_file);
}

int compareInt(const void *a, const void *b)
{
    const int *p1 = a;
    const int *p2 = b;
    return *p1 - *p2; 
    
}


// simulate(): Simulering av batch scheduling. "Kjører" til alle
// prosessene er ferdige.
//
void simulate()
{

    
  int start=0, counter =0, end,merlot =0, pivot =0, pivot2 =0, arrcounter=0, i=0,toktok =0, counter2=0, nullcase =0;
  float total_tid_cpu =0, total_tid_arrival=0;
  int shortest_job_first[N], cpu[N];

  while(counter <N){
   shortest_job_first[arrcounter]=P[counter].arrive + P[counter].cpu;

 
   
   counter++;
   arrcounter++;
    
  }
 
  /* Here I just created a sorted list using the quicksort function in the library. This sorted list contains work-time of every process sorted from the lowest to the 
  largest value*/
  printf("\n");
  qsort(shortest_job_first, N, sizeof(int),compareInt );
 

  end =0;

  for(int x =0; x<N;x++){
   // get the element from sorted list in pivot to later compare its value.
   pivot = shortest_job_first[x];

   for(int z =0; z<N; z++){

      // pivots gets the value of arrive +cpu values when arrive is not equal zero
      if(P[z].arrive!=0){
         pivot2 = P[z].arrive+P[z].cpu;
      }
         
      //Print the values from P when arrive is zero and the flag 'i' is zero
      // printf("%d i!\n", i);
      if(P[z].arrive==0 && i ==0){
         printf("%d  %d   %d  0 \n",P[z].id, P[z].arrive, P[z].cpu);
         //i gets the number of times 
         start =P[z].cpu;
         end = P[z].cpu;
         
         i+=1; //flag to catch how many process have zero as value for arrive.
         
      }
      else{
         if(pivot == pivot2 && P[z].arrive !=0  ){
            
            printf("%d  %d   %d  %d  %d \n",P[z].id, P[z].arrive, P[z].cpu, start, end);
            end += P[z].cpu;
            start+=P[z].cpu;

         }
      }

   }
   
  }
  
}

// main(): Leser filnavn med prosessdata, leser fil og kjører scheduling
//
int main()
{
   char filename[100];

   // Leser filnavn fra bruker
   printf("File? ");
   scanf("%s", filename);

   // Leser inn prosessdataene
   read_file(filename);

   // Simulerer batch-scheduling
   simulate();
}
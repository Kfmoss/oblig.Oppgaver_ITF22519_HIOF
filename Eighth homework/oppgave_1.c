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
int option;

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

// simulate(): Simulering av batch scheduling. "Kjører" til alle
// prosessene er ferdige.
//
void simulate()
{


    int start=0, end, pivot, counter=0;
    float tot_cpu=0, tot_arr=0, sum_av =0, tot_end=0, average_Taround=0,aveWaitTid=0 ;

    printf(" Process ID  Arrive CPU  Start End\n");


  while(counter<N){

   /* med ifen nedenfor kan jeg la 0 registreres som tid den første  prosessen starter*/
    if(counter!=0){
        pivot = start;
        start = P[counter-1].cpu+pivot;
      }
    end = P[counter].cpu +start; 
    tot_end+=end;
    sum_av += end - P[counter].arrive;
    tot_cpu+=P[counter].cpu;
    tot_arr+=P[counter].arrive;
    

    printf("  %d            %d     %d   %d  %d   \n", P[counter].id,P[counter].arrive, P[counter].cpu, start, end);
    

    counter++;
  }

    /* average wait-time  = [totalEnd - totalArrivaltime - totalCputime]/antallprosesser   */
  
   aveWaitTid = (tot_end - tot_arr-tot_cpu)/counter;
    /* average time-around = [totalEnd -totalArrive]/antallprosesser */
  average_Taround = sum_av/counter;
  printf("the average turn-around time is : %f\n", average_Taround);
  printf("the average wait-time is : %f\n", aveWaitTid);

}


// main(): Leser filnavn med prosessdata, leser fil og kjører scheduling
//
int main()
{
   char filename[100];

//    // Leser filnavn fra bruker
   printf("File? ");
   scanf("%s", filename);

   // Leser inn prosessdataene
   read_file(filename);

  

   // Simulerer batch-scheduling
   simulate();
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMBER_OF_THREADS 4 // number of threads

// Matrisemultiplikasjon: Beregner produktet C = AB

#define MAX 64 // Maksimalt antall rader/kolonner

int A[MAX][MAX], // De tre matrisene som skal brukes
    B[MAX][MAX], // deklareres globalt, slik at de er
    C[MAX][MAX]; // tilgjengelige for alle funksjoner

int N; // Antall rader og kolonner

char *filnavn_A = "a.txt", // Navn på de tre filene
     *filnavn_B = "b.txt", // som brukes til å
     *filnavn_C = "resultMatrix.txt"; // lagre matrisene


/* 
  It is possible to find better alternatives to perform a multiplication between 2 matrices.
  A possible solution could be to restrict the access to matrix A and B  from the 4 threads 
  in the function les_AB(). 
  However this solution starts from advices from a student assistant which is devide a matrix in 4, so
  every thread should have access to only a 1/4 of matrices in order to
  perform a multiplication between matrix A and B  to get the right result for matrix C (resultMatrix.txt). 

  This means that every thread can only perform a multiplication of 16 rows and 64 columns. Please check function multipliser_AB()! 


*/

pthread_mutex_t Mutex; // create a variable of type "pthread_mutex"

int row =0;
void les_AB()
{
  FILE *fil_A, *fil_B;
  int tmp, i, j;

  fil_A = fopen(filnavn_A, "r");
  fil_B = fopen(filnavn_B, "r");

  fscanf(fil_A, "%d", &N);
  if (N > MAX)
  {
    printf("Feil: N > %d\n", MAX);
    exit(-1);
  }
  fscanf(fil_B, "%d", &tmp);
  if (N != tmp)
  {
    printf("Feil: Matrisene har ulike dimensjoner\n");
    exit(-1);
  }
  

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
    {
      fscanf(fil_A, "%d", &A[i][j]);
      fscanf(fil_B, "%d", &B[i][j]);
    }
  
  fclose(fil_A);
  fclose(fil_B);
}

// Skriver resultatet C = AB ut til fil
void skriv_C()
{
  FILE *fil_C;
  int i, j;

  fil_C = fopen(filnavn_C, "w");
  fprintf(fil_C, "%d\n", N);
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
      fprintf(fil_C, "%d ", C[i][j]);
    fprintf(fil_C, "\n");
  }
  
  fclose(fil_C);
}

// Utfører hele matrisemultiplikasjonen
void *multipliser_AB()
{
  int i, j, k;
  pthread_mutex_lock(&Mutex);
  for (i = 0; i < 16; i++)
    for (j = 0; j < N; j++)
    {
      C[i][j] = 0;
      for (k = 0; k < N; k++)
	C[i][j] += A[i][k] * B[k][j];

    }
  pthread_mutex_unlock(&Mutex);
}

// Hovedprogram
int main()
{
  /*the way to perform this program is about the same like oppgave 1b*/
  pthread_mutex_init(&Mutex,NULL); //mutex getting ready 
  pthread_t th[NUMBER_OF_THREADS];
  int check_the_thread,i;
  
  les_AB();

  for(i=0;i<NUMBER_OF_THREADS;i++){
    pthread_create(&th[i], NULL, multipliser_AB, NULL);//creating 4 threads
  }
  for(i=0;i<NUMBER_OF_THREADS;i++){
    pthread_join(th[i], NULL);// execute threads
  }

  skriv_C();
  pthread_mutex_destroy(&Mutex);//destroy mutex
}

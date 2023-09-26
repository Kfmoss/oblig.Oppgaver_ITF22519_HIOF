#include <pthread.h>
#include <stdio.h>
#define N_THREADS 5

int value = 0; // Global variabel som deles av alle tråder

/*new code line*/
pthread_mutex_t Mymutex; //this is for å synkro int value.

/*new code line*/

void *count()
{
  int i;
  
  pthread_mutex_lock(&Mymutex); ///lock the mutex for access. 
  for (i = 0; i < 1000000; i++){
    
    value++;

  }
  printf("%d  \n", value);
  pthread_mutex_unlock(&Mymutex);

}

int main ()
{
   // initialize 2 variables: i of type integer and an array of (data)type pthread_t which has size =5 
   int i;
   pthread_t thread[N_THREADS];

   pthread_mutex_init(&Mymutex, NULL); //mutex's getting ready
//    pthread_cond_init(&cond, NULL); // condition ready
   
   // the loop creates a new thread. since the process to create a new thread takes time then
   for(i = 0; i < N_THREADS; i++)
      pthread_create(&thread[i], NULL, count, NULL);
   for(i = 0; i < N_THREADS; i++)
     pthread_join(thread[i], NULL);


    pthread_mutex_destroy(&Mymutex); //delete mutex
    
   
  
}
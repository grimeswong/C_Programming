//
//
// print out counter to see the main thread and the child thread
// result: two threads print out at the same time

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *printCounter(void *m);

int main()
{

  pthread_t tid[2];   //create two threads array
  char *print[2] = {"printCounter1", "printCounter2"};

  int thread[2] = {1,2};


  for (int i=0 ; i<2; i++) {
    pthread_create(&tid[i], NULL, (void *) printCounter, &thread[i]);   // last one is type casting (pointer)
  }

  for (int i=0; i<2; i++) {
    pthread_join(tid[i], NULL);
  }
  // result:
  // Thread 1 Counter: 1
  // Thread 2 Counter: 1
  // Thread 2 Counter: 2
  // Thread 1 Counter: 2
  // Thread 2 Counter: 3
  // Thread 1 Counter: 3
  // Thread 2 Counter: 4
  // Thread 1 Counter: 4
  // Thread 2 Counter: 5
  // Thread 1 Counter: 5
}

void *printCounter(void *m)
{
    int j = *(int *) m;
    for(int i=1; i<=5; i++) {
      printf("Thread %d Counter: %d\n",j, i);
      sleep(1);
    }
    return NULL;
}

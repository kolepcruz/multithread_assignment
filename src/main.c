#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define N_THREADS 5

/**
 * @brief 
 * This is a test implementation 
 * @param v 
 * @return void* 
 */
void* thread_test(void *v);

int main(){
    pthread_t threads[N_THREADS];

    for (int i = 0; i < N_THREADS; ++i)
        if(pthread_create(&threads[i],NULL,thread_test,(void*) (i+1)) != 0)
            fprintf(stderr,"Problem creating thread no%d",i);

    for (int j = 0; j < N_THREADS; ++j)
        pthread_join(threads[j],NULL);
    
    return EXIT_SUCCESS;
}


void* thread_test(void *v){
    int tid = (int) v;
    printf("This is my test thread no%d\n",tid);
    return NULL;
}
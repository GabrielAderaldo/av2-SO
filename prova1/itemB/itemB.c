#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int saldo = 0;

//Inicializando a variavel do multex...
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void* depositar(void* v)
{
    int i;
    //Colocando o Mutex-lock
    pthread_mutex_lock(&mutex);
    
    printf("O endereço de memoria: %d\n",v);
    for(i=0;i<1000;i++)
    {    
        saldo = saldo+1;
    }
    //Colocando o Retirando o mutex-lock
    pthread_mutex_unlock(&mutex);
}

int main()
{
    //inicializando os ids das threads...
    int tid1 = 1;
    int tid2 = 2;
    int tid3 = 3;
    int tid4 = 4;

    //inicializando as threads...
    pthread_t thread_1;
    pthread_t thread_2;
    pthread_t thread_3;
    pthread_t thread_4;

    //colocando as funções que criando cadsa thread...
    pthread_create(&thread_1,NULL,&depositar,&tid1);
    pthread_create(&thread_2,NULL,&depositar,&tid2);
    pthread_create(&thread_3,NULL,&depositar,&tid3);
    pthread_create(&thread_4,NULL,&depositar,&tid4);
    
    //colocando as funções que inicializam cada thread...
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    pthread_join(thread_3,NULL);
    pthread_join(thread_4,NULL);


    //resultado final...
    printf("Saldo Final: %d.",saldo);

    return 0;
}
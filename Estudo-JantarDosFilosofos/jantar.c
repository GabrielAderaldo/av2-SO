#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

void pensar(int n){
    srand(time(NULL));
    printf("O %d estah pensando na solucao da vida...\n",n);
    sleep(rand()%5);
}


void* filosofo(void* ptr){
    int n = *((int*)ptr);
    

    //MESA DOS FILOSOFOS...
    while (1){

        pensar(n);
        //pegar o primeiro talher 
        //pegar o segundo talher
        //comer
        //liberar o primeiro talher 
        //liberar o segundo talher

    }
    

    
    
    return NULL;
}

pthread_mutex_t semaforo[5];


int main(){

    pthread_t f1,f2,f3,f4,f5;

    
    int n1=0,n2=1,n3=2,n4=3,n5=0,i;

    
    pthread_create(&f1,NULL,filosofo,&n1);
    pthread_create(&f1,NULL,filosofo,&n2);
    pthread_create(&f1,NULL,filosofo,&n3);
    pthread_create(&f1,NULL,filosofo,&n4);
    pthread_create(&f1,NULL,filosofo,&n5);

    pthread_join(f1,NULL);
    pthread_join(f2,NULL);
    pthread_join(f3,NULL);
    pthread_join(f4,NULL);
    pthread_join(f5,NULL);

    return 0;
}
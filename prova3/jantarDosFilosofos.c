#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


pthread_t F0, F1, F2, F3, F4;
pthread_mutex_t H[5];

void* filosofo(void* x){

int n;
int* p;
p = (int *) x;
n = *p;
while(1){
printf("Filosofo %d pensando...\n",n);
if(n == 4){
    printf("EXECULTANDO O IF\n");
pthread_mutex_lock(&H[(n+1)%5]);//Pegando os hashis
pthread_mutex_lock(&H[n]);//Pegando os hashis
printf("Filosofo %d comendo...\n",n);//SESSÃO CRITICA
sleep(1);//SESSÃO CRITICA
pthread_mutex_unlock(&H[n]);//deixando os hashis
pthread_mutex_unlock(&H[(n+1)%5]);//deixando os hashis
}else{
pthread_mutex_lock(&H[n]);//Pegando os hashis
pthread_mutex_lock(&H[(n+1)%5]);//Pegando os hashis
printf("Filosofo %d comendo...\n",n);//SESSÃO CRITICA
sleep(1);//SESSÃO CRITICA
pthread_mutex_unlock(&H[n]);//deixando os hashis
pthread_mutex_unlock(&H[(n+1)%5]);//deixando os hashis
}

}
return NULL;
}




int main()
{
int n0 = 0, n1 = 1, n2 = 2, n3 = 3, n4 = 4;
pthread_create(&F0,NULL,filosofo,&n0);
pthread_create(&F1,NULL,filosofo,&n1);
pthread_create(&F2,NULL,filosofo,&n2);
pthread_create(&F3,NULL,filosofo,&n3);
pthread_create(&F4,NULL,filosofo,&n4);
pthread_join(F0,NULL);
pthread_join(F1,NULL);
pthread_join(F2,NULL);
pthread_join(F3,NULL);
pthread_join(F4,NULL);
return 0;
}
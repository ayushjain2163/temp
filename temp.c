
// Reader Writer problem 
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

#define R 5
#define W 5
int s=10;
int readcount=0;
int writecount=0;
void *reader(void *a);
void *writer(void *a);

pthread_mutex_t x;
sem_t wsem;

int main(){    
    pthread_mutex_init(&x,NULL);
    sem_init(&wsem,0,1);
    
    pthread_t read[R];
    pthread_t write[W];
    
    for(int i=0;i<R;i++){
        pthread_create(&read[i],NULL,*reader,(void*)i);
    }
    for(int i=0;i<W;i++){
        pthread_create(&write[i],NULL,*writer,(void*)i);
    }
    for(int i=0;i<R;i++){
        pthread_join(read[i],NULL);
    }
    for(int i=0;i<W;i++){
        pthread_join(write[i],NULL);
    }
    return 0;
}

void *reader(void* a){
    int r=(int*)a;
    int i=0;
    while(i<R){
        pthread_mutex_lock(&x);
        readcount++;
        if(readcount==1)
            sem_wait(&wsem);
        pthread_mutex_unlock(&x);
        printf("Reader %d is Reading %d \n",r,s);
        pthread_mutex_lock(&x);
        readcount--;
        if(readcount==0)
            sem_post(&wsem);
        pthread_mutex_unlock(&x);
        sleep(rand()%10);
        i++;
    }
}

void *writer(void* a){
    int w=(int*)a;
    int i=0;
    while(i<W){
        pthread_mutex_lock(&x);
        s=s+5;
        printf("\t \t \t Writer %d is writing %d \n",w,s);
        pthread_mutex_unlock(&x);
        sleep(rand()%10);
        i++;
    }
    
    
}

#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int buf[5],  f,   r;  //Circular queue
sem_t  mutex,  full,  empty;
void *produce(void *arg)
{
    int i;
    for(i=0;i<10;i++)
    {
        sem_wait(&empty);//Wait of empty slot and decrement the empty  
        sem_wait(&mutex); //Wait if consumer is consuming a item

        printf("produced item is %d\n",i);
        buf[(++r)%5]=i;
        sleep(1);

        sem_post(&mutex); // signal the consumer to consume the item mutex=0
        sem_post(&full); // full will be increamented

    }
}
void *consume(void *arg)
{
        int item,i;
        for(i=0;i<10;i++)
        {
                sem_wait(&full); //Wait for item  and decrement the full
                sem_wait(&mutex); // Wait if producer s producing a item

                item=buf[(++f)%5];
                printf("consumed item is %d\n",item);
                sleep(1);

                sem_post(&mutex); // signal the producer  to produce the item mutex=0
                sem_post(&empty); // incrementing the empty variable
        }
}
int main()
{
    pthread_t tid1,tid2;
    sem_init(&mutex,  0,  1);
    sem_init(&full,  0,  0);
    sem_init(&empty, 0,  5);
    pthread_create(&tid1, NULL, produce, NULL);
    pthread_create(&tid2,NULL, consume, NULL);
     pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}

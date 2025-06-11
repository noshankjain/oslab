#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    void *smemory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    printf("Key of shared memory is %d\n", shmid);
    smemory = shmat(shmid, NULL, 0);
    if (smemory == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }
    printf("Process attached at %p\n", smemory);
    printf("Enter some data to write to shared memory: ");
    ssize_t bytesRead = read(0, buff, sizeof(buff) - 1);
    strcpy(smemory, buff);
    printf("You wrote: %s\n", (char*)smemory);
    return 0;
}

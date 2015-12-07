#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "common.h"


struct sembuf readOP = {
    SEM_READER_IDX, -1, 0 
};


int main() {
    // obtain semaphores
    int sem_id = semget(SEM_KEY, SEM_NUM, IPC_CREAT | 0666);
    union semun arg;

    // share memory
    int shm_id = shmget(SHM_KEY, MSG_LEN_MAX, IPC_CREAT | 0666);
    char *message = shmat(shm_id, 0, 0);

    // start the loop
    int exit_command_received = 0;
    while(!exit_command_received) {
        puts("Waiting for your turn, please be patient...");
        semop(sem_id, &readOP, 1);

        puts("Here's the message:");
        puts(message);

        if(is_exit_command(message)) {
            exit_command_received = 1;
        }

        arg.val = READY;
        semctl(sem_id, SEM_WRITER_IDX, SETVAL, arg);
    }

    // unmap shared memory
    if(shmdt(message) == -1) {
        puts("Failed to shmdt");
        exit(1);
    }

    return 0;
}

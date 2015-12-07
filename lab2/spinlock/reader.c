/*
    I decided to leave only 1 reader,
    because 2 (or any other number) of them would be exactly identical.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include "common.h"


int main() {
    int shm_id = shmget(SHM_KEY, sizeof(struct SharedData), IPC_CREAT | 0666);
    if(shm_id == -1) {
        puts("Failed to shmget.");
        exit(1);
    }

    struct SharedData *shared_data = (struct SharedData*)shmat(shm_id, 0, 0);

    int exit_command_received = 0;
    while(!exit_command_received) {
        puts("Waiting for your turn. Please be patient.");

        // GCC builtin function is used here.
        // It atomically does the following: "If the flag is set to READY_TO_READ, then sets it to READING"
        while(__sync_val_compare_and_swap(&shared_data->flag, READY_TO_READ, READING) != READY_TO_READ) {
            sleep(WAIT_SLEEP_TIME);
        }

        puts("The message is:");
        puts(shared_data->message);

        if(is_exit_command(shared_data->message))
        {
            exit_command_received = 1;
        }

        puts("Releasing resources...");
        shared_data->flag = READY_TO_WRITE;
    }

    puts("Bye.");

    if(shmdt(shared_data) == -1) {
        puts("Failed to shmdt.");
        exit(1);
    }

    return 0;
}

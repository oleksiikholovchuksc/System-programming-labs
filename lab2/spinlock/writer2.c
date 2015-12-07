/*
    The only difference between writer1.c and writer2.c is in resources initialization.
    Writer1 initializes them and writer2 does not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
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
        // It atomically does the following: "If the flag is set to READY_TO_WRITE, then sets it to WRITING"
        while(__sync_val_compare_and_swap(&shared_data->flag, READY_TO_WRITE, WRITING) != READY_TO_WRITE) {
            sleep(WAIT_SLEEP_TIME);
        }

        puts("Now it's your turn. Please write something great: ");
        fgets(shared_data->message, MSG_LEN_MAX, stdin);

        if(is_exit_command(shared_data->message))
        {
            exit_command_received = 1;
        }

        puts("Releasing resources...");
        shared_data->flag = READY_TO_READ;
    }

    puts("Bye.");

    if(shmdt(shared_data) == -1) {
        puts("Failed to shmdt.");
        exit(1);
    }

    return 0;
}

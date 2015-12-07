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
        while(shared_data->flag != READER1_OWNS) {
            sleep(WAIT_SLEEP_TIME);
        }

        puts("The message received from Writer1 is: ");
        puts(shared_data->message);

        if(is_exit_command(shared_data->message))
        {
            exit_command_received = 1;
        }

        puts("The workflow is proceeding to Writer2.");
        shared_data->flag = WRITER2_OWNS;
    }

    puts("Bye.");

    if(shmdt(shared_data) == -1) {
        puts("Failed to shmdt.");
        exit(1);
    }

    return 0;
}
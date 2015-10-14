/*
 * Lab 1. Reader. No duplicates allowed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>


const key_t SHM_KEY = 0x0BEC;
const size_t SHM_SIZE = 0xDEAD;
const char* EXIT_CMD = "exit";
const size_t EXIT_CMD_LEN = 4;
const int ALLOW_EVERYTHING_MASK = 0666;

char last_msg[SHM_SIZE] = {0};

int main() {
  int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | ALLOW_EVERYTHING_MASK);
  if(shm_id == -1) {
    puts("Failed to shmget\n");
    exit(1);
  }

  char *mapped_memory = (char*)shmat(shm_id, 0, 0);
  if((char*)-1 == mapped_memory) {
    puts("Failed to shmat\n");
    exit(1);
  }

  while(strncmp(mapped_memory, EXIT_CMD, EXIT_CMD_LEN) != 0) {
    if(strncmp(mapped_memory, last_msg, SHM_SIZE) != 0) {
      strncpy(last_msg, mapped_memory, SHM_SIZE);
      puts(last_msg);
    }
  }

  if(shmdt(mapped_memory) == -1) {
    puts("Failed to shmdt");
    exit(1);
  }
  
  return 0;
}

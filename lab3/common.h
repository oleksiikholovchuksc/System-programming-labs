#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

// shared memory key
extern const key_t SHM_KEY = 0xFACE;

// semaphores constants
extern const int MSG_LEN_MAX = 228;
extern const key_t SEM_KEY = 0xDEAD;
extern const int SEM_NUM = 2;
extern const int SEM_WRITER_IDX = 0;
extern const int SEM_READER_IDX = 1;

// workers states constants
extern const int WORKING = 0;
extern const int READY = 1;

int is_exit_command(const char *buf) {
    return strncmp(buf, "EXIT", 4) == 0;
}
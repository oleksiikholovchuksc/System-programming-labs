#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


extern const key_t SHM_KEY = 0xBEC;
extern const size_t MSG_LEN_MAX = 228;

struct SharedData {
    short flag;
    char message[MSG_LEN_MAX];
};
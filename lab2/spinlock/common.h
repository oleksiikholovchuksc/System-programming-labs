#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>


extern const float WAIT_SLEEP_TIME = 0.5;

extern const short READY_TO_WRITE = 0;
extern const short WRITING        = 1;
extern const short READY_TO_READ  = 2;
extern const short READING        = 3;

extern const key_t SHM_KEY = 0xBEC;
extern const size_t MSG_LEN_MAX = 228;

struct SharedData {
    short flag;
    char message[MSG_LEN_MAX];
};

int is_exit_command(const char *buffer)
{
    return strncmp(buffer, "EXIT", 4) == 0;
}

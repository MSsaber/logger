#include <stdio.h>
#include <log.h>
#include <trace.h>

#define FILE_NAME "log"
#define PATH "C:\\Users\\86189\\Desktop\\"

int main(void)
{
    long log_fd = 0;

    OPEN(&log_fd ,PATH, FILE_NAME);

    printf("log_fd : %lu\n", log_fd);

    ILOG(log_fd, "Hallo World[%d]\n", 1);
    DLOG(log_fd, "Hallo World[%d]\n", 2);
    ELOG(log_fd, "Hallo World[%d]\n", 3);
    WLOG(log_fd, "Hallo World[%d]\n", 4);

    CLOSE(log_fd);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <log.h>

typedef struct __Log{

    char log_time[20];
    char *file_name;
    char *path;
    FILE *log_file;
} Log;

static void destory_logger_handle(Log* handle)
{
    if (!handle) return;

    free(handle->file_name);
    free(handle->path);

    close(handle->log_file);

    free(handle);
}

int initialize_logger(long *logger_fd,
                      char *path, uint32_t path_len,
                      char *file_name, uint32_t file_name_len)
{
    (void) logger_fd;
    (void) path;
    (void) path_len;
    (void) file_name;
    (void) file_name_len;

    return 0;
}

void destory_logger(long logger_fd)
{
    Log *log_handle = (Log *)logger_fd;

    destory_logger_handle(log_handle);
}

void log(char *format, ...)
{
    va_list args;
}
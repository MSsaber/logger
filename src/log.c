#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <log.h>
#include <trace.h>

#define LOG_SUCCESS    0x00000000
#define LOG_FOE        0x0000fffd
#define LOG_GENERAIC   0x0000fffe
#define LOG_OUT_OF_MEM 0x0000ffff

#define START_YEAR 1900

#define ALLOC(size, c, type) ((type) alloc(size, c))

#ifdef STATIC_CONFIG
long logger = 0;
#endif

typedef char * pchar;

typedef struct __Log{

    char log_time[20];
    char *file_name;
    char *path;
    FILE *log_file;
} Log;

static void *alloc(uint32_t size, char c)
{
    void *buf = malloc(size);
    if (!buf) return NULL;

    memset(buf, c, size);
    return buf;
}

static uint32_t move_buffer(char *in, uint32_t in_len,
                            pchar *out, uint32_t *out_len)
{
    char *buf = NULL;

    *out_len = 0;
    buf  = ALLOC(in_len + 1, 0x00, pchar);
    if (!buf) return LOG_OUT_OF_MEM;

    *out_len = in_len;
    memcpy(buf, in, in_len);
    *out = buf;

    return LOG_SUCCESS;
}

static void destory_logger_handle(Log* handle)
{
    if (!handle) return;

    if (handle->file_name)
        free(handle->file_name);

    if (handle->path)
        free(handle->path);

    if (handle->log_file)
        fclose(handle->log_file);

    free(handle);
}

static void time_log(FILE *f)
{
    time_t t;
    struct tm * a;
    time(&t);
    a=localtime(&t);

    printf("%4d-%02d-%02d %02d:%02d:%02d  ",
        START_YEAR + a->tm_year,1+a->tm_mon,a->tm_mday,
        a->tm_hour,a->tm_min,a->tm_sec); 

    fprintf(f, "%4d-%02d-%02d %02d:%02d:%02d  ",
        START_YEAR + a->tm_year,1+a->tm_mon,a->tm_mday,
        a->tm_hour,a->tm_min,a->tm_sec);
}

int initialize_logger(long *logger_fd,
                      char *path, uint32_t path_len,
                      char *file_name, uint32_t file_name_len)
{
    uint32_t res = LOG_SUCCESS;
    Log *logger = NULL;
    char *file_path = NULL;

    logger = ALLOC(sizeof(Log), 0x00, Log *);
    if (!logger) return LOG_OUT_OF_MEM;
    logger->file_name = NULL;
    logger->path = NULL;
    logger->log_file = NULL;
    res = move_buffer(path, path_len, &logger->path, &path_len);
    if (res) goto error;

    res = move_buffer(path, path_len, &logger->file_name, &file_name_len);
    if (res) goto error;

    file_path = ALLOC(path_len + file_name_len, 0x00, char *);
    if (!file_path) goto error;
    memcpy(file_path, path, path_len);
    memcpy(file_path + path_len, file_name, file_name_len);

    logger->log_file = fopen(file_path, "a");
    if (!logger->log_file) {
        res = LOG_FOE;
        goto error;
    }

    *logger_fd = (long) logger;

    free(file_path);

    return (int) LOG_SUCCESS;
error:
    if (file_path)
        free(file_path);
    destory_logger_handle(logger);
    return (int) res;
}

void destory_logger(long logger_fd)
{
    Log *log_handle = (Log *)logger_fd;

    destory_logger_handle(log_handle);
}

void log_info(long logger_fd, bool dt, char *format, ...)
{
    (void) dt;
    char buf[512];
    Log *logger = (Log *) logger_fd;
    if (!logger_fd) return;

    if (dt)
        time_log(logger->log_file);

    va_list args;

    va_start(args, format);
    vsprintf(buf,format,args);
    fprintf(logger->log_file, "%s", buf);
    printf("%s", buf);
    va_end(args);
}
#include <stdio.h>
#include <log.h>
#include <trace.h>
#include <stdarg.h>

#define FILE_NAME "testlog"
#if PLATFORM_GE
#define PATH "./"
#else
#define PATH "C:\\Users\\86189\\Desktop\\"
#endif

void logger_print(const char *fmt, ...)
{
    char buf[256];
    int n;
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);
    printf("%s", (const char*)buf);
}


int main(void)
{
    long log_fd = 0;

    OPEN(&log_fd ,PATH, FILE_NAME);

    printf("log_fd : %lu\n", log_fd);

    ILOG(log_fd, "Hello World[%d]\n", 1);
    DLOG(log_fd, "Hello World[%d]\n", 2);
	//sleep(10);
    ELOG(log_fd, "Hello World[%d]\n", 3);
    WLOG(log_fd, "Hello World[%d]\n", 4);

    HEXDUMP(log_fd, "HelloHelloHelloHello", 20);

    CLOSE(log_fd);
    return 0;
}

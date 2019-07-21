#ifndef TRACE_H_
#define TRACE_H_

#include <log.h>
#include <string.h>

#ifdef STATIC_CONFIG

extern long logger;

#define OPEN(path, file) initialize_logger(&logger, path, strlen(path), file, strlen(file))

#define CLOSE() destory_logger(logger);

#define ILOG(fmt, ...) log_info(logger, true, "[INFO] %s : %d" fmt, __func__, __LINE__)

#define DLOG(fmt, ...) log_info(logger, true, "[DEBUG] %s : %d" fmt, __func__, __LINE__)

#define ELOG(fmt, ...) log_info(logger, true, "[ERROR] %s : %d" fmt, __func__, __LINE__)

#define WLOG(fmt, ...) log_info(logger, true, "[WRANING] %s : %d" fmt, __func__, __LINE__)

#else

#define OPEN(fd, path, file) initialize_logger(&fd, path, strlen(path), file, strlen(file))

#define CLOSE(fd) destory_logger(fd)

#define ILOG(fd, fmt, ...) log_info(fd, true, "[INFO] %s : %d" fmt, __func__, __LINE__)

#define DLOG(fd, fmt, ...) log_info(fd, true, "[DEBUG] %s : %d" fmt, __func__, __LINE__)

#define ELOG(fd, fmt, ...) log_info(fd, true, "[ERROR] %s : %d" fmt, __func__, __LINE__)

#define WLOG(fd, fmt, ...) log_info(fd, true, "[WRANING] %s : %d" fmt, __func__, __LINE__)


#endif

#endif /*TRACE_H_*/
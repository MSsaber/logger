#ifndef LOG_H_
#define LOG_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * func : initialize a logger
 * param :
 * [in] path : file path
 * [in] path_len : file path string length
 * [in] file_name : file name
 * [in] file_name_len : file name string length
 * [out] logger_fd : if init seccessed, return a valid logger fd
 */
extern int initialize_logger(void **logger_fd,
                             const char *path, uint32_t path_len,
                             const char *file_name, uint32_t file_name_len);

/**
 * func : destory logger by fd
 * param :
 * [in] logger_fd : fd of logger
 */
extern void destory_logger(void *logger_fd);

extern void log_info(void * logger_fd, bool dt, const char *format, ...);

extern void hexdump(void * logger_fd, const uint8_t *buf, uint32_t buf_size);

#ifdef __cplusplus
}
#endif

#endif /*LOG_H_*/
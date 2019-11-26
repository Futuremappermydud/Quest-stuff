#ifndef LOGGING_H
#define LOGGING_H

#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include <unistd.h>

enum LOG_VERBOSE_TYPE {
    CRITICAL = 1,
    ERROR = 2,
    WARNING = 4,
    INFO = 8,
    DEBUG = 16
};

#ifndef LOG_LEVEL
#define LOG_LEVEL CRITICAL | ERROR | WARNING | INFO | DEBUG
#endif

#ifndef MOD_ID
#define MOD_ID "PLACEHOLDER_MOD_ID"
#endif
#ifndef VERSION

#define VERSION "0.0.0"
#endif

#ifdef log
#undef log
#endif
#define log_base(...) __android_log_print(ANDROID_LOG_INFO, "QuestHook [" MOD_ID " v" VERSION "] ", __VA_ARGS__)

#define log(level, ...) if (((LOG_LEVEL) & level) != 0) {\
if (level == CRITICAL) log_base("[CRITICAL] " __VA_ARGS__); \
if (level == ERROR) log_base("[ERROR] " __VA_ARGS__); \
if (level == WARNING) log_base("[WARNING] " __VA_ARGS__); \
if (level == INFO) log_base("[INFO] " __VA_ARGS__); \
if (level == DEBUG) log_base("[DEBUG] " __VA_ARGS__); }

#ifndef STD_BUFFER_SIZE
#define STD_BUFFER_SIZE 256
#endif
static int pfd[2];
static pthread_t thr;
static void *thread_func(void*)
{
    ssize_t rdsz;
    char buf[STD_BUFFER_SIZE];
    while((rdsz = read(pfd[0], buf, sizeof buf - 1)) > 0) {
        if(buf[rdsz - 1] == '\n') --rdsz;
        buf[rdsz] = 0;  /* add null-terminator */
        __android_log_write(ANDROID_LOG_INFO, MOD_ID, buf);
    }
    return 0;
}

static int start_logger()
{

    setvbuf(stdout, 0, _IOLBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);

    /* create the pipe and redirect stdout and stderr */
    pipe(pfd);
    dup2(pfd[1], 1);
    dup2(pfd[1], 2);

    /* spawn the logging thread */
    if(pthread_create(&thr, 0, thread_func, 0) == -1)
        return -1;
    pthread_detach(thr);
    return 0;
}

#endif /* LOGGING_H */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>


typedef struct _сис_інф {
    char *назва_системи;
    char *назва_вузла;
    char *збірка_ядра;
    char *версія;
    char *архітектура;
} СистемнаІнформація;


extern "C" int отримати_системну_інформацію(СистемнаІнформація *сис_інф, int розмір_буферу) {
    struct utsname buffer;

    errno = 0;
    if (uname(&buffer) < 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    if (сис_інф == nullptr) {
        perror("сис_інф");
        exit(EXIT_FAILURE);
    }

    strncpy(сис_інф->назва_системи, buffer.sysname, розмір_буферу);
    strncpy(сис_інф->назва_вузла, buffer.nodename, розмір_буферу);
    strncpy(сис_інф->збірка_ядра, buffer.release, розмір_буферу);
    strncpy(сис_інф->версія, buffer.version, розмір_буферу);
    strncpy(сис_інф->архітектура, buffer.machine, розмір_буферу);

    // printf("system name = %s\n", buffer.sysname);
    // printf("node name   = %s\n", buffer.nodename);
    // printf("release     = %s\n", buffer.release);
    // printf("version     = %s\n", buffer.version);
    // printf("machine     = %s\n", buffer.machine);

    return EXIT_SUCCESS;
}

extern "C" void друк_сі(const char* формат, char* значення = nullptr) {
    printf(формат, значення);
}
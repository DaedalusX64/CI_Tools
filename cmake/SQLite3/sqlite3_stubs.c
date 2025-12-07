// sqlite_stubs.c – 3DS stub implementations for POSIX ownership calls

#include <stddef.h>

int fchown(int fd, unsigned int owner, unsigned int group)
{
    (void)fd;
    (void)owner;
    (void)group;
    // 3DS has no real ownership model – just pretend success
    return 0;
}

unsigned int geteuid(void)
{
    // Single-user system, so just say "root"
    return 0;
}
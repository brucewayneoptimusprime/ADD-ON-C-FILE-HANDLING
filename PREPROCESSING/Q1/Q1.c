#include <stdio.h>

#ifdef _WIN32
int main() {
    printf("This code is for Windows.\n");
    return 0;
}
#endif

#ifndef _WIN32
int main() {
    printf("This code is for Linux.\n");
    return 0;
}
#endif

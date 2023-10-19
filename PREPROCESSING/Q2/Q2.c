#include <stdio.h>

#define SPEED_OF_LIGHT 299792458 // meters per second

int main() {
    double distance = 150000000; // 150 million meters
    double time = distance / SPEED_OF_LIGHT;

    printf("Time for light to travel %f meters: %f seconds\n", distance, time);
    return 0;
}

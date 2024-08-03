#include <stdio.h>

int main()
{
    float latitude;
    float longitude;
    char info[80];

    // Continuously read input until end-of-file or an invalid input
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        
        // Check if latitude and longitude are within the specified ranges
        if ((latitude > 26.0) && (latitude < 34.0)) {
            if ((longitude > -76.0) && (longitude < -64.0)) {
                // Print the valid latitude, longitude, and info
                printf("%f,%f,%s\n", latitude, longitude, info);
            }
        }
    }

    return 0;
}


// pixelColor.c
// Mandelbrot Colors
// Emily Chen and Taimur Azhar
#include <stdlib.h>
#include <stdio.h>

#define BLACK 0
#define WHITE 255
#define MAX_STEPS 256.0

unsigned char stepsToBlue (int steps) {
    double t = steps / MAX_STEPS;
    unsigned char color = (int) 4 * (1 - t) * t * t * (1 - t) * WHITE;
    return color;
}

unsigned char stepsToRed (int steps) {
    double t = steps / MAX_STEPS;
    unsigned char color = (int) 110 * (1 - t) * (1 - t) * (1 - t) * (1 - t) * (1 -t) * WHITE;
    return color;
}

unsigned char stepsToGreen (int steps) {
    double t = steps / MAX_STEPS;
    unsigned char color = (int) 4 * (1 - t) * (1 - t) * t * (1- t) * WHITE;
    return color;
}

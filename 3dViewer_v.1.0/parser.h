#ifndef EXAMPLE_H
#define EXAMPLE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct facets {
    unsigned int count_v; // the amount of vertexes in one facet
    unsigned int *pInds;
}polygon_t;

typedef struct facets_test {
    unsigned int count_v;
    unsigned int pInds[3];
}polygon_test;

typedef struct Data {
    unsigned int vertex_count;
    unsigned int facets_count;
    double *pVerts;
    polygon_t *polygons;
    double scale;
    double factor;
    double angle;
    double rotX;
    double rotY;
    double rotZ;
    double step_ud;
    double step_lr;
}data;

void parser(data *drawing_data,char *filename);

//AUXILIARY

int check_symbol(char c,char check);
int is_vertex(char *buffer);
int is_facet(char *buffer);
void print_data(const data *drawing_data);
void free_data(data *drawing_data);

#ifdef __cplusplus
}
#endif

#endif

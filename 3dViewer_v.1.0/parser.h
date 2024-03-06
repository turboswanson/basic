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

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef struct Data {
    unsigned int vertex_count;
    unsigned int facets_count;
    polygon_t *polygons;
    matrix_t vertexes;
    double scale;
}data;

void parser(data *drawing_data,char *filename);

//AUXILIARY
void create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);
int check_symbol(char c,char check);
int is_vertex(char *buffer);
int is_facet(char *buffer);
void print_data(const data *drawing_data);
void free_data(data *drawing_data);

#ifdef __cplusplus
}
#endif

#endif

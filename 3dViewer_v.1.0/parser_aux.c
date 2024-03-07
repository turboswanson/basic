#include "parser.h"

void create_matrix(int rows, int columns, matrix_t *result) {
    
    result->rows = rows;
    result->columns = 3;

    result->matrix = (double **)calloc(rows, sizeof(double*));  // allocate memory for rows pointers

    for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));  // allocate memory for values
    }
    
    
}

void remove_matrix(matrix_t *A) {

  for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
  }

  free(A->matrix);
  
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
  
}

/// @brief two symbols comparing fucntion
/// @param symbol1
/// @param symbol2
/// @return 1 - symbols equal, 0 - they're not
int check_symbol(char c,char check){
    int res = 0;

    if (c == check){
        res = 1;
    }

    return res;
}

/// @brief if current string contains vertex information
/// @param buffer 
/// @return 1 -yes, 2 - no
int is_vertex(char *buffer){
    int res = 0;

    if(check_symbol(buffer[0],'v') && check_symbol(buffer[1],' ')) {
        res = 1;
    }

    return res;
}

/// @brief if current string contains facet information
/// @param buffer 
/// @return 1 -yes, 2 - no
int is_facet(char *buffer){
    int res = 0;

    if(check_symbol(buffer[0],'f') && check_symbol(buffer[1],' ')) {
        res = 1;
    }

    return res;
}

/// @brief print drawing_data content
/// @param drawing_data 
void print_data(const data *drawing_data){

    int num = drawing_data->vertex_count;

    printf("VERTEXES\n");

    for( int i = 0; i < num; i++) {
        for(int j = 0 ; j < 3; j++){
            printf("%lf ",drawing_data->vertexes.matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("INDEXES\n");

   for(unsigned int i = 0 ; i < drawing_data->facets_count; i++) {
    for(unsigned int j = 0; j < drawing_data->polygons[i].count_v;j++) {
        printf("%u ",drawing_data->polygons[i].pInds[j]);
    }
    printf("\n");
   }

 }

 void free_data(data *drawing_data) {
    // free(drawing_data->pVerts);

    for(unsigned int i = 0; i < drawing_data->facets_count; i++) {
        free(drawing_data->polygons[i].pInds);
    }

    free(drawing_data->polygons);

    remove_matrix(&drawing_data->vertexes);

    drawing_data->vertex_count = 0.0;
    drawing_data->facets_count = 0.0;

    drawing_data->scale[0] = __DBL_MAX__;
    drawing_data->scale[1] = __DBL_MIN__;
    drawing_data->scale[2] = __DBL_MAX__;
    drawing_data->scale[3] = __DBL_MIN__;
    drawing_data->scale[4] = __DBL_MAX__;
    drawing_data->scale[5] = __DBL_MIN__;

 }

#include "parser.h"

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

    int num1 = drawing_data->vertex_count;

    printf("VERTEXES\n");

    for(int i = 0; i < num1*3; i++){
        printf("%lf\n", drawing_data->pVerts[i]);    
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
    free(drawing_data->pVerts);

    for(unsigned int i = 0; i < drawing_data->facets_count; i++) {
        free(drawing_data->polygons[i].pInds);
    }

    free(drawing_data->polygons);

    drawing_data->vertex_count = 0.0;
    drawing_data->facets_count = 0.0;
    drawing_data->scale = 0.0;
    drawing_data->factor = 1.0;
    drawing_data->angle = 0.0;
    drawing_data->step_ud = 0.0;
    drawing_data->step_lr = 0.0;
    drawing_data->rotX = 0.0;
    drawing_data->rotY = 0.0;
    drawing_data->rotZ = 0.0;
 }

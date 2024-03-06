#include "parser.h"

static void memory_handling(data *drawing_data) {
    // drawing_data->pVerts = (double *)calloc(drawing_data->vertex_count*3,sizeof(double));
    drawing_data->polygons = (polygon_t *)calloc(drawing_data->facets_count,sizeof(polygon_t));
    unsigned int rows = drawing_data->vertex_count;
    create_matrix(rows,3,&drawing_data->vertexes);

}

static void counting_vf(char *buffer,int index,data *drawing_data){
    size_t len = strlen(buffer);
    unsigned int count = 0;

    for(size_t i = 0; i < len ; i++) {
        if(check_symbol(buffer[i], ' ')) {
            count++;
        }
    }

    drawing_data->polygons[index].count_v = count ;
}

static void counting_function(char *filename,data *drawing_data){
    char buffer[256];
    memset(buffer,0, sizeof(buffer));

    FILE *file = fopen(filename,"r");
    
    while(fgets(buffer,sizeof(buffer),file)) {
        if(is_vertex(buffer)){
            drawing_data->vertex_count++;
        }

        if(is_facet(buffer)){
            drawing_data->facets_count++;
        }
    }

    fclose(file);    

}

static void set_vertex_coord(char *buffer,int index,data *drawing_data) {
    double x = 0;
    double y = 0;
    double z = 0;

    sscanf(buffer+2,"%lf %lf %lf",&x,&y,&z);

    // drawing_data->pVerts[index] = x;

    // drawing_data->pVerts[index+1] = y;

    // drawing_data->pVerts[index+2] = z;
    drawing_data->vertexes.matrix[index][0] = x;
    drawing_data->vertexes.matrix[index][1] = y;
    drawing_data->vertexes.matrix[index][2] = z;

    if(x > drawing_data->scale) drawing_data->scale = x;
    if(y > drawing_data->scale) drawing_data->scale = y;
    if(z > drawing_data->scale) drawing_data->scale = z;
}


static void set_vertex_for_facet(char *buffer,int facet_index,data *drawing_data){
    
    unsigned int num = drawing_data->polygons[facet_index].count_v;
    drawing_data->polygons[facet_index].pInds= (unsigned int *)calloc(num,sizeof(unsigned int));
 
    char *ptr = buffer;
    int flag = 0;
    int tmp = 0;
    int index = 0;

    while(*ptr) {
       
        if(check_symbol(*ptr,' ')){
            flag = 0;
        }

        if(isdigit(*ptr) && check_symbol(*(ptr-1),' ')){
            flag = 1;
        }

        if(flag){
            sscanf(ptr,"%u",&tmp);
            drawing_data->polygons[facet_index].pInds[index] = tmp-1;
            tmp = 0;
            flag = 0;
            index++;
        }

        ptr++;
    }
 
}


static void string_parsing(char *filename,data *drawing_data){
    char buffer[256];
    memset(buffer,0, sizeof(buffer));
    int vertex_index = 0;
    int facet_index = 0;

    FILE *file = fopen(filename, "r");

    while(fgets(buffer,sizeof(buffer),file)) {
        if(is_vertex(buffer)){
            set_vertex_coord(buffer,vertex_index,drawing_data);
            vertex_index++;
        }

        if(is_facet(buffer)) {
            counting_vf(buffer,facet_index,drawing_data);
            set_vertex_for_facet(buffer,facet_index,drawing_data);
            facet_index++;
        }

    }

    fclose(file);
    
}


void parser(data *drawing_data, char *filename){

    drawing_data->vertex_count = 0;
    drawing_data->facets_count = 0;
    drawing_data->scale = 0.0;
    drawing_data->polygons = NULL;

    if(access(filename, F_OK) == 0){
        counting_function(filename,drawing_data);
        memory_handling(drawing_data);
        string_parsing(filename,drawing_data);        
        // print_data(&drawing_data);
        // free_data(&drawing_data);
    }
//    else {
//        fprintf(stderr, "%s : No such file or a directory", filename);
//    }


    // return 0;

}

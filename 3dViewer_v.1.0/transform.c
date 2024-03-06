#include "transform.h"

void translation(data *drawing_data, double a, double b,double c) {

    int count = (int)drawing_data->vertex_count;
        for(int i = 0; i < count; i++){


        drawing_data->vertexes.matrix[i][0] = drawing_data->vertexes.matrix[i][0] + a;
        drawing_data->vertexes.matrix[i][1] = drawing_data->vertexes.matrix[i][1] + b;
        drawing_data->vertexes.matrix[i][2] = drawing_data->vertexes.matrix[i][2] + c;


    }

}

void scaling(data *drawing_data, double a) {

    int count = (int)drawing_data->vertex_count;

    for(int i = 0; i < count; i++){

            drawing_data->vertexes.matrix[i][0] = drawing_data->vertexes.matrix[i][0] * a;
            drawing_data->vertexes.matrix[i][1] = drawing_data->vertexes.matrix[i][1] * a;
            drawing_data->vertexes.matrix[i][2] = drawing_data->vertexes.matrix[i][2] * a;

    }

}

void rotation_by_ox(data *drawing_data, double angle){

    int count = (int)drawing_data->vertex_count;

    for(int i = 0; i < count; i++) {
        double tmp_y = drawing_data->vertexes.matrix[i][1];
        double tmp_z = drawing_data->vertexes.matrix[i][2];

        drawing_data->vertexes.matrix[i][1] = cos(angle)*tmp_y - sin(angle)*tmp_z;
        drawing_data->vertexes.matrix[i][2] = sin(angle)*tmp_y + cos(angle)*tmp_z;

    }
}

void rotation_by_oy(data *drawing_data, double angle) {
    int count = (int)drawing_data->vertex_count;

    for(int i = 0; i < count; i++) {
        double tmp_x = drawing_data->vertexes.matrix[i][0];
        double tmp_z = drawing_data->vertexes.matrix[i][2];

        drawing_data->vertexes.matrix[i][0] = cos(angle) * tmp_x + sin(angle) * tmp_z;
        drawing_data->vertexes.matrix[i][2] = -sin(angle) * tmp_x + cos(angle) * tmp_z;
    }
}

void rotation_by_oz(data *drawing_data, double angle) {
    int count = (int)drawing_data->vertex_count;

    for(int i = 0; i < count; i++) {
        double tmp_x = drawing_data->vertexes.matrix[i][0];
        double tmp_y = drawing_data->vertexes.matrix[i][1];

        drawing_data->vertexes.matrix[i][0] = cos(angle) * tmp_x - sin(angle) * tmp_y;
        drawing_data->vertexes.matrix[i][1] = sin(angle) * tmp_x + cos(angle) * tmp_y;
    }
}

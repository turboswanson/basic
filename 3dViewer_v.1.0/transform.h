#ifndef TRANSFORM_H
#define TRANSFORM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "parser.h"
#include <math.h>

void translation(data *drawing_data,double a, double b,double c);
void scaling(data *drawing_data, double a);
void rotation_by_ox(data *drawing_data, double angle);
void rotation_by_oy(data *drawing_data, double angle);
void rotation_by_oz(data *drawing_data, double angle);

#ifdef __cplusplus
}
#endif


#endif

#ifndef FUNCIONES_H
#define FUNCIONES_H

float calcularDistancia(float x1, float y1, float x2, float y2);
void calcularPerimetro(float puntos[3][2], float *per, float *l1, float *l2, float *l3);
float calcularArea(float per, float l1, float l2, float l3);
float calcularVolumen(float areaBase, float altura);

#endif

#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float x2, float y2);
void calcularPerimetro(float puntos[3][2], float *per, float *l1, float *l2, float *l3);
float calcularArea(float per, float l1, float l2, float l3);
float calcularVolumen(float areaBase, float altura);

int main(int argc, char *argv[]) {

    float puntos[3][2] = {{0, 0}, {2, 4}, {7, 1}};
    float perimetro, lado1, lado2, lado3;
    
    calcularPerimetro(puntos, &perimetro, &lado1, &lado2, &lado3);
    float areaBase = calcularArea(perimetro, lado1, lado2, lado3);
    
    float altura;
    printf("Ingrese la altura de la pirámide: ");
    scanf("%f", &altura);
    
    float volumen = calcularVolumen(areaBase, altura);
    float areaSuperficial = areaBase + (perimetro * altura / 2.0);
    
    printf("El volumen de la pirámide es: %.2f\n", volumen);
    printf("El área superficial de la pirámide es: %.2f\n", areaSuperficial);

    return 0;
}

float calcularDistancia(float x1, float y1, float x2, float y2) {
    float distancia = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return distancia;
}

void calcularPerimetro(float puntos[3][2], float *per, float *l1, float *l2, float *l3) {
    *l1 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[1][0], puntos[1][1]);
    *l2 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[2][0], puntos[2][1]);
    *l3 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[1][0], puntos[1][1]);
    *per = *l1 + *l2 + *l3;
}

float calcularArea(float per, float l1, float l2, float l3) {
    float semiperimetro = per / 2;
    float area = sqrt(semiperimetro * (semiperimetro - l1) * (semiperimetro - l2) * (semiperimetro - l3));
    return area;
}

float calcularVolumen(float areaBase, float altura) {
    float volumen = (areaBase * altura) / 3.0;
    return volumen;
}

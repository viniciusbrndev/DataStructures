#include <stdio.h>

#include "ponto.h"
#include "circ.h"

int main() {
    Ponto* pt1;
    float x, y;
    printf("Digite x e y: ");
    scanf("%f %f", &x, &y);
    pt1 = PontoAloca(x, y);
    PontoGet(pt1, &x, &y);
    printf("(%.1f, %.1f)\n", x, y);

    Ponto *pt2 = PontoAloca(1.0, 1.0);

    printf("A distancia entre P1 e P2 eh %.2f\n", 
        PontoDistacia(pt1, pt2));

    Circulo *c = CirculoAloca(pt1, 3);

    printf("A area do circulo eh %.1f\n", CirculoArea(c));
    printf("O ponto pt2 %s dentro do circulo\n", CirculoInterior(c, pt2) ? "esta" : "nao esta");

    pt1 = PontoDesaloca(pt1);
    pt2 = PontoDesaloca(pt2);
    c = CirculoDesaloca(c);

    return 0;
}
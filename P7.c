/*P7.c*/
/*Marcos Paulo Arruda Freitas*/
/*11811EEL011*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *x, *y;
} Pont;

int main() {
    FILE *file;
    char str[50] = {0};
    int a = 0, i;
    Pont p;
    scanf("%d", &i);
    if (i == 1) {
        scanf("%d", &a);
        fflush(stdin);
        p.x = calloc(a, sizeof(double));
        p.y = calloc(a, sizeof(double));
        for (i = 0; i < a; i++) {
            p.x[i] = cos(i * 2.0 * M_PI / (a - 1));
            p.y[i] = sin(i * 2.0 * M_PI / (a - 1));
        }
        file = fopen("pontos.dat", "w");
        for (i = 0; i < a; i++) {
            fprintf(file, "%.3lf,%.3lf\n", p.x[i], p.y[i]);
        }

        fclose(file);
        free(p.x);
        free(p.y);
    } else if (i == 2) {
        file = fopen("pontos.dat", "r");
        while (!feof(file)) {
            fgets(str, 49, file);
            printf("%s", str);
        }
        fclose(file);
    }
    return 0;
}

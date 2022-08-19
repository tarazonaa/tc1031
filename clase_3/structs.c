#include <stdio.h>

struct informacionEstudiante {
    char* nombre;
    int id;
    int edad;
};

int main() {
    struct informacionEstudiante estudiante;
    estudiante.nombre = "Juan";
    estudiante.id = 1;
    estudiante.edad = 20;
    printf("%s\n", estudiante.nombre);
    printf("%d\n", estudiante.id);
    printf("%d\n", estudiante.edad);
    return 0;
}

#include <stdio.h>
#include <string.h>

/* ========= ESTRUCTURAS ========= */
struct Estudiante {
    char nombre[50];
};

struct Asistencia {
    char curso[50];
    char fecha[20];
    char horario[25];
    char estudiante[50];
    char estado[15];
};

struct Curso {
    char nombre[50];
    struct Estudiante estudiantes[50];
    int numEstudiantes;
    char fechas[10][20];
    int numFechas;
    char horarios[5][25];
    int numHorarios;
};

/* ========= VARIABLES GLOBALES ========= */
struct Curso cursos[5];
int numCursos = 0;

struct Asistencia registrosAsistencia[500];
int numRegistros = 0;

/* ========= FUNCION MENU GENERICO ========= */
int seleccionarOpcion(const char titulo[], char opciones[][50], int total) {
    int opcion;
    int i;

    do {
        printf("\n%s\n", titulo);
        for (i = 0; i < total; i++) {
            printf("%d. %s\n", i + 1, opciones[i]);
        }

        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;
        }

        if (opcion < 1 || opcion > total) {
            printf("Opcion no valida.\n");
        }

    } while (opcion < 1 || opcion > total);

    return opcion - 1;
}

/* ========= INICIALIZAR CURSOS ========= */
void inicializarCursos() {
    strcpy(cursos[0].nombre, "Matematicas");
    strcpy(cursos[0].estudiantes[0].nombre, "Juan");
    strcpy(cursos[0].estudiantes[1].nombre, "Maria");
    strcpy(cursos[0].estudiantes[2].nombre, "Pedro");
    cursos[0].numEstudiantes = 3;

    strcpy(cursos[0].fechas[0], "2023-10-01");
    strcpy(cursos[0].fechas[1], "2023-10-08");
    strcpy(cursos[0].fechas[2], "2023-10-15");
    cursos[0].numFechas = 3;

    strcpy(cursos[0].horarios[0], "07:30 - 09:00");
    strcpy(cursos[0].horarios[1], "09:00 - 10:30");
    cursos[0].numHorarios = 2;

    strcpy(cursos[1].nombre, "Fisica");
    strcpy(cursos[1].estudiantes[0].nombre, "Ana");
    strcpy(cursos[1].estudiantes[1].nombre, "Luis");
    cursos[1].numEstudiantes = 2;

    strcpy(cursos[1].fechas[0], "2023-10-02");
    strcpy(cursos[1].fechas[1], "2023-10-09");
    cursos[1].numFechas = 2;

    strcpy(cursos[1].horarios[0], "10:30 - 12:00");
    strcpy(cursos[1].horarios[1], "12:00 - 13:00");
    cursos[1].numHorarios = 2;

    numCursos = 2;
}

/* ========= SELECCIONAR CURSO ========= */
int seleccionarCurso() {
    char opciones[5][50];
    int i;

    for (i = 0; i < numCursos; i++) {
        strcpy(opciones[i], cursos[i].nombre);
    }

    return seleccionarOpcion("Seleccione un curso:", opciones, numCursos);
}

/* ========= SELECCIONAR FECHA Y HORARIO ========= */
void seleccionarFechaYHorario(int cursoIndex, int *fechaIndex, int *horarioIndex) {
    char opcionesFechas[10][50];
    char opcionesHorarios[5][50];
    int i;

    for (i = 0; i < cursos[cursoIndex].numFechas; i++) {
        strcpy(opcionesFechas[i], cursos[cursoIndex].fechas[i]);
    }
    *fechaIndex = seleccionarOpcion("Seleccione una fecha:", opcionesFechas, cursos[cursoIndex].numFechas);

    for (i = 0; i < cursos[cursoIndex].numHorarios; i++) {
        strcpy(opcionesHorarios[i], cursos[cursoIndex].horarios[i]);
    }
    *horarioIndex = seleccionarOpcion("Seleccione un horario:", opcionesHorarios, cursos[cursoIndex].numHorarios);
}

/* ========= REGISTRAR ASISTENCIA ========= */
void registrarAsistencia() {
    int cursoIndex;
    int fechaIndex, horarioIndex;
    int i;
    char estado;

    cursoIndex = seleccionarCurso();
    seleccionarFechaYHorario(cursoIndex, &fechaIndex, &horarioIndex);

    printf("\nLista de estudiantes:\n");
    for (i = 0; i < cursos[cursoIndex].numEstudiantes; i++) {
        printf("%d. %s\n", i + 1, cursos[cursoIndex].estudiantes[i].nombre);
    }

    for (i = 0; i < cursos[cursoIndex].numEstudiantes; i++) {
        if (numRegistros >= 500) {
            printf("Limite de registros alcanzado.\n");
            return;
        }

        printf("%s (P/A): ", cursos[cursoIndex].estudiantes[i].nombre);
        scanf(" %c", &estado);

        strcpy(registrosAsistencia[numRegistros].curso, cursos[cursoIndex].nombre);
        strcpy(registrosAsistencia[numRegistros].fecha, cursos[cursoIndex].fechas[fechaIndex]);
        strcpy(registrosAsistencia[numRegistros].horario, cursos[cursoIndex].horarios[horarioIndex]);
        strcpy(registrosAsistencia[numRegistros].estudiante, cursos[cursoIndex].estudiantes[i].nombre);

        if (estado == 'P' || estado == 'p') {
            strcpy(registrosAsistencia[numRegistros].estado, "Presente");
        } else {
            strcpy(registrosAsistencia[numRegistros].estado, "Ausente");
        }

        numRegistros++;
    }

    printf("Asistencia registrada correctamente.\n");
}

/* ========= REPORTE SEMANAL ========= */
void generarReporteSemanal() {
    int cursoIndex;
    int f, r;

    cursoIndex = seleccionarCurso();

    printf("\nReporte semanal - %s\n", cursos[cursoIndex].nombre);

    for (f = 0; f < cursos[cursoIndex].numFechas; f++) {
        printf("\nFecha: %s\n", cursos[cursoIndex].fechas[f]);

        for (r = 0; r < numRegistros; r++) {
            if (strcmp(registrosAsistencia[r].curso, cursos[cursoIndex].nombre) == 0 &&
                strcmp(registrosAsistencia[r].fecha, cursos[cursoIndex].fechas[f]) == 0) {

                printf("  %s - %s (%s)\n",
                       registrosAsistencia[r].estudiante,
                       registrosAsistencia[r].estado,
                       registrosAsistencia[r].horario);
            }
        }
    }
}

/* ========= MAIN ========= */
int main() {
    int opcion;
    char opcionesMenu[3][50] = {
        "Registrar Asistencia",
        "Generar Reporte Semanal",
        "Salir"
    };

    inicializarCursos();

    do {
        opcion = seleccionarOpcion("Menu Principal:", opcionesMenu, 3);

        if (opcion == 0) {
            registrarAsistencia();
        } else if (opcion == 1) {
            generarReporteSemanal();
        }

    } while (opcion != 2);

    return 0;
}

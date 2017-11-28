#include <stdio.h>
#include <stdlib.h>
#define ARCHIVO_DATOS "dengue.csv"

// Definimos la estructura donde almacenar cada registro
// del arhivo.
typedef struct {
    short etapaVida;
} RegistroArchivo;

// Definimos la estructura que contiene los campos de control
// y de calculo para el enunciado.
typedef struct {
    short grupoEtapaVida;
    short cantidadXEtapa;
    short totalPacientes;
} RegistroControl;
    
// Prototipo de las funciones.
FILE *abrirArchivo(char[], char[]);
void primerRegistro(RegistroArchivo, RegistroControl *);
void procesarRegistro(RegistroArchivo, RegistroControl *);
void procesarCorte(RegistroArchivo, RegistroControl *);
void imprimirCabecera(void);
void imprimirResultadosFinales(RegistroControl);
RegistroArchivo leerRegistroArchivo(FILE *);

int main(void)
{
    // Declaramos las variables estructuradas para datos y control.
    RegistroArchivo regArchivo;
    RegistroControl regControl;

    // Abrimos el archivo y leemos el primer registro.
    FILE *fd = abrirArchivo(ARCHIVO_DATOS, "r");

    // Leemos el registro actual del archivo.
    regArchivo = leerRegistroArchivo(fd);

    // Establecemos los valores iniciales para los calculos.
    primerRegistro(regArchivo, &regControl);
    // Iteramos sobre cada registro del archivo de datos.
    while (!feof(fd)) {
        // Verificamos si el registro actual ya pertenece al
        // siguiente grupo de procesamiento.
        if (regArchivo.etapaVida != regControl.grupoEtapaVida) {
            procesarCorte(regArchivo, &regControl);
        }
        // Procesamos el registro actual.
        procesarRegistro(regArchivo, &regControl);
        // Leemos el siguiente registro del archivo.
        regArchivo = leerRegistroArchivo(fd);
    }
    // Al llegar al final del arhivo estamos ante el ultimo bloque
    // de datos que debe procesarse.
    procesarCorte(regArchivo, &regControl);

    // Imprimimos los totales generales
    imprimirResultadosFinales(regControl);

    // Cerramos el archivo de datos.
    fclose(fd);

    return 0;
}

// Inicializa los valores ante el primer registro leido e
// imprime los titulos de la cabecera.
void primerRegistro(RegistroArchivo regArch, RegistroControl *regControl) {
    regControl->cantidadXEtapa = 0;
    regControl->totalPacientes = 0;
    regControl->grupoEtapaVida = regArch.etapaVida;
    imprimirCabecera();
}

// Procesa el registro actual.
void procesarRegistro(RegistroArchivo regArch, RegistroControl *regControl) {
   regControl->cantidadXEtapa++;
}

// Procesa el corte del bloque anterior.
void procesarCorte(RegistroArchivo regArch, RegistroControl *regControl){
    printf("%5hd%18hd\n", regControl->grupoEtapaVida, regControl->cantidadXEtapa);
    regControl->totalPacientes += regControl->cantidadXEtapa;
    regControl->cantidadXEtapa = 0;
    regControl->grupoEtapaVida = regArch.etapaVida;
}

// Imprime los titulos de la cabecera.
void imprimirCabecera(void) {
    printf("%s\t%15s\n", "Etapa", "Cantidad");
}

// Imprime los resultados finales.
void imprimirResultadosFinales(RegistroControl regControl) {
    printf("Total Pacientes: %hd\n", regControl.totalPacientes);
}

// Funcion encargada de la apertura del archivo a procesar en
// caso de falla, terminamos el programa.
FILE *abrirArchivo(char nombreArchivo[], char modoApertura[]) {
    FILE *fd = fopen(nombreArchivo, modoApertura);
    if (fd == NULL) {
        printf("ERROR: No se pudo abrir el archivo %s.\n", nombreArchivo);
        exit(1);
    }
    return fd;
}

// Lee el registro actual del archivo cuyo puntero se recibe
// como parametro.
RegistroArchivo leerRegistroArchivo(FILE *fd){
    RegistroArchivo r;
    fscanf(fd, "%hd,%*d", &r.etapaVida);
    return r;
}

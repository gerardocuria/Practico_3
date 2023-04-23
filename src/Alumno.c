/************************************************************************************************
Copyright (c) <year>, <copyright holders>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/


 /** \brief 
 **
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "Alumno.h"
#include <stdio.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

struct alumno_s{
    char apellido[50];//!< 50 bytes para apellido
    char nombre[50];//!< 50 bytes para nombre
    uint32_t documento;//!<  32bits para documento
    //***// bool ocupado;
};

/* === Private function declarations =========================================================== */

static int SerializarCadena();
static int SerializarNumero();

/*con estatic hago que sean internas del c porque si alguien modifica el h y pone extern puede modificar la funcion*/

/* === Public function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/** @brief 
muestra en formato json y devuelve la cantidad de espacio usado
*/

static int SerializarCadena(const char * campo,const char * valor, char * cadena, int espacio){
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}
/** @brief 
muestra en formato json y devuelve la cantidad de espacio usado
*/
static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio){
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

//***//static struct alumno_s intancias[50] = {0}; lleno toda el area del vector con ceros

/* === Public function implementation ========================================================== */

alumno_t CrearAlumno(char * apellido, char * nombre, int documento){
    alumno_t resultado = malloc(sizeof(struct alumno_s)); 
    //con malloc le pedimos al compilador un bloque del tamaño alumno_s y nos devuelve la direccion de inicio
    //Creo que resultado es un puntero del tipo alumno_t osea un puntero tipo estructura alumno_s
    strcpy(resultado->apellido, apellido);
    strcpy(resultado->nombre, nombre);
    resultado->documento = documento;

    return resultado;
}

int GetCompleto(alumno_t alumno, char cadena[], uint32_t espacio){
    return NULL;

}

int GetDocumento(alumno_t alumno){
    return NULL;

}

int Serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio){
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    cadena++;
    disponibles--;
    resultado = SerializarCadena("apellido",&alumno->apellido,cadena,disponibles);

    if (resultado > 0){
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarCadena("nombre",&alumno->nombre,cadena,disponibles);
    }
    if (resultado > 0){
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento",alumno->documento,cadena,disponibles);
    }
    if (resultado > 0){
        cadena += resultado;
        disponibles -= resultado;
        *(cadena-1)= '}';
        resultado = espacio - disponibles;
    }

    return resultado;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
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

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "Alumno.h"
#include <stdio.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

int main(void){
/*
    static const struct alumno_s yo = {
        .apellido = "Curia",
        .nombre = "Gerardo",
        .documento = 41495098,
     };*/
     /*defino yo como estructura alumno_s*/

    /*strncpy(yo.apellido, "Curia", sizeof(yo.apellido)); esto ya no sirve*/
    /*Esta funcion hace yo.apellido = "Curia";*/

    /*Las variables locales se asignan en la pila, la variable existe mientras se llama a la subrrutina*/
    /*Si pongo const la variable sigue estando en la pila, lo unico que va a hacer es que no se pueda escribir*/
    /*Si pongo datos en la pila hasta pisar las variables globales, estas cambina de valor*/
    /*La pila se divide en global, head, pila*//*head es un area de memoria dinamica que cambia durante la ejecucion del programa*/
    /*Las variables en HEAD se crean y se destruyen en tiempo de ejecucion, no de compilacion como las variables globales*/
    /*malloc para pedir un bloque de memoria en head y free para devolverlo*/
    /*En sistemas embebidos no es recomendable usar HEAD, porque nos podemos quedar sin memoria, en general solo usamos variables globales y la pila*/
    /*Si a las variables la defino dentro de una funcion son locales y se guaran en la pila, si las defino fuera de cualquier funcion es global*/
    /*Para crear una variable global el compilador genera en flah un bloque con todos los valores iniciales de la variable y antes de ejecutar el main copia ese sector de flah en la ram(global)*/
    /*Si defino una variable local y no le pongo valor, este valor es descocnocido*/
    /*Si defino una variable local sin valor, este valor es 0*/
    /*En ejecucion querer guardar una variable en flahs es una locura*/
    /*Finalmente si quiero poner la variable yo (que esta dentro de una funcion por lo que es local) con la flash, debo poner satic (para definirla como global) y const (se le asigna lugar en la flash, pero no en la ram ya que se la puede trabajar de la flash directamente ya que es constante)*/


    char cadena[128];
    alumno_t yo = CrearAlumno("Curia","Gerardo",41495098);

    if (Serializar(yo, cadena, sizeof(cadena)) >= 0){
    /*Serializar(direccion de memoria de yo, direccion de memoria de cadena (donde guardo la cadena en formato json), tamaño de la cadena (si o si sizeof porque el tamaño solo se da en tiempo de ejecucion));*/
        printf ("%s\n", cadena);
    }else{
        printf("Error al serializar\n");
    };


    return 0;
}

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
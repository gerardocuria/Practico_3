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

#ifndef Alumno_H
#define Alumno_H

/** @brief 
 **
 ** @{ */
/**
*/
/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

#include <stdint.h> 
#include <string.h> 
/*se supne que la cavezera del complador van entre llaves y las cavezeras propias entre comillas*/
/*el compilador gcc sabe donde esta stdint.h*/

/* === Public data type declarations =========================================================== */
/** @brief 
Estructura que contiene el espacio para guardar apellido, nombre y documento del alumno
*/
typedef struct alumno_s * alumno_t;
/*alumno_t es un puntero a alumno_s pero no sabemos que campos tiene alumno_s*/


/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/** @brief 
(direccion de inicio de la estructura alumno_t, cadena con los datos del alumno en formato json, el espacio ocupado por la cadena)
esta funcion toma los datos del alumno, luego completa una cadena con los datos del alumno en formato json.
*/

int Serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio);
/*alumno es un puntero a el tipo de dato alumno_t*/
/*de esta manera paso la direccion de inicio de la estructura y no la estructura entera porque la estructura es grande para andar copiandola*/
/*la marco como const para indicar que no cambio el contenido de la estructura solo la leo*/
/*el const va a la izquierda para que sea constante la estructura, si estuviera a la derecha seria constante el puntero*/
/*un array es un puntero al primer elemeno por lo que char cadena[] es lo mismo que char cadena*/
alumno_t CrearAlumno(char * apellido, char * nombre, int documento);

int GetCompleto(alumno_t alumno, char cadena[], uint32_t espacio);

int GetDocumento(alumno_t alumno);


/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */

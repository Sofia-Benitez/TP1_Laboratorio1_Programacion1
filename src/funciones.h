/*
 * funciones.h
 *
 *  Created on: Apr 15, 2021
 *      Author: sofia
 */

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief menu principal de la calculadora. Imprime las opciones y muestra los numeros ingresados
 *
 * \param flagUno int    marca si se ingreso el primer operando. Si la funcion que ingresa numeros retorna 1 es porque el numero fue ingresado correctamente
 * \param flagDos int    marca si se ingreso el segundo operando. Si la funcion que ingresa numeros retorna 1 es porque el numero fue ingresado correctamente
 * \param primerOperando int    primer numero ingresado, reemplaza la x
 * \param segundoOperando int   segundo numero ingresado, reemplaza la y
 * \return void  no devuelve nada
 */
 void menuPrincipal(int flagUno, int flagDos, int primerOperando, int segundoOperando);



/** \brief suma de dos operandos
 *
 * \param numero1 int  primer operando
 * \param numero2 int  segundo operando
 * \return int        resultado de la operacion
 *
 */
int suma(int numero1, int numero2);


/** \brief resta de dos operandos. Al primer operando se le sustrae el segundo
 *
 * \param numero1 int   primer operando
 * \param numero2 int   segundo operando
 * \return int          resultado de la operacion
 *
 */
int resta(int numero1,int numero2);


/** \brief realiza la division de dos operandos y Devuelve 0 si no es posible realizar la division y 1 si es posible.
 *
 * \param numero1 int    primer operando
 * \param numero2 int    segundo operando
 * \param resultado float*   puntero del resultado de la operacion
 * \return int        retorna 0 si la division no se puede realizar porque el puntero es null o el segundo operando es 0 y retorna 1 si la division se puede realizar
 *
 */
int division(int numero1, int numero2, float* resultado);


/** \brief multiplicacion de dos operandos
 *
 * \param numero1 int    primer operando
 * \param numero2 int    segundo operando
 * \return int            resultado de la operacion
 *
 */
int multiplicacion(int numero1, int numero2);


/** \brief obtiene el factorial de un numero y devuelve si es posible realizar la operacion
 *
 * \param numero int   numero ingresado
 * \param resultadoFactorial int*    puntero del resultado de la operacion
 * \return int     devuelve 1 si se puede realizar la operacion, 0 si no se puede porque el numero ingresado es negativo y -1 si el numero ingresado es mayor a 10
 *
 */
int factorial(int numero1, int* resultadoFactorial);

#endif // FUNCIONES_H_INCLUDED

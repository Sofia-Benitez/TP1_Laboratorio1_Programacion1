/*
 * utn.h
 *
 *  Created on: Apr 15, 2021
 *      Author: sofia
 */

#ifndef UTN_H_
#define UTN_H_


/** \brief funcion para pedir un numero por consola y validar si es un numero
 *
 * \param pResultado int*   puntero a variable donde se escribe el valor ingresado si es correcto
 * \param mensaje char*    puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param mensajeError char*    puntero a cadena de caracteres con mensaje de error en el caso del que el numero ingresado no sea valido
 * \param minimo int    valor minimo admitido
 * \param maximo int    valor maximo admitido
 * \param reintentos int   cantidad de reintentos para ingresar el numero
 * \return int   devuelve 1 si la funcion es realizada correctamente y 0 si no se realiza
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);




#endif // UTN_H_INCLUDED




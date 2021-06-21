#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Parsea los datos los datos de los empleados desde un archivo.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde un archivo.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED

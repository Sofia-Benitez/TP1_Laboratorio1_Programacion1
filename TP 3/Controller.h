void menu(void);
/** \brief funcion que abre y lee un archivo de texto para llamar al parser. Si existen empleados cargados al abrir un archivo le pregunta al usuario si quiere sobrescribirlos
 *
 * \param path char*   ruta donde esta ubicado el archivo
 * \param pArrayListEmployee LinkedList*      linkedlist donde se cargaran los datos
 * \return int   devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief funcion que abre y lee un archivo binario para llamar al parser. Si existen empleados cargados al abrir un archivo le pregunta al usuario si quiere sobrescribirlos
 *
 * \param path char*  ruta donde esta ubicado el archivo
 * \param pArrayListEmployee LinkedList*  linkedlist donde se cargaran los datos
 * \return int   devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief funcion que permite agregar un empleado al linkedlist llamando a una funcion que pide los datos
 *
 * \param pArrayListEmployee LinkedList*   linkedlist donde se cargaran los datos
 * \param id int    id actualizado desde el main
 * \return int      devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id);
/** \brief funcion que muestra a los empleados existentes y pide id para que el usuario elija cual modificar y que campo de el mismo
 *
 * \param pArrayListEmployee LinkedList*   linkedlist donde se cargaran los datos
 * \return int   devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief funcion que muestra la lista de empleados existentes y pide un id para que el usuario elija cual eliminar del linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \return int     devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief funcion que imprime la lista de empleados llamando a la funcion mostrarEmpleado();
 *
 * \param pArrayListEmployee LinkedList*
 * \return int   devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief funcion que ordena los empleados segun dos criterios
 *
 * \param pArrayListEmployee LinkedList*
 * \return int  devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief funcion que almacena los datos de un linkedlist en un archivo .csv
 *
 * \param path char*   ruta donde esta ubicado el archivo
 * \param pArrayListEmployee LinkedList*   linkedlist de datos que se almacenaran
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief funcion que carga los datos de un linkedlist en un archivo binario
 *
 * \param path char*   ruta donde esta ubicado el archivo
 * \param pArrayListEmployee LinkedList*   linkedlist de datos que se almacenaran
 * \return int     int  devuelve 1 si los datos se cargaron correctamente y 0 sino
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



void menuPrincipal(int flagUno, int flagDos, int primerOperando, int segundoOperando);
/** \brief menu principal de la calculadora. Imprime las opciones y muestra los numeros ingresados
 *
 * \param flagUno int    marca si se ingreso el primer operando. Si la funcion que ingresa numeros retorna 1 es porque el numero fue ingresado correctamente
 * \param flagDos int    marca si se ingreso el segundo operando. Si la funcion que ingresa numeros retorna 1 es porque el numero fue ingresado correctamente
 * \param primerOperando int    primer numero ingresado, reemplaza la x
 * \param segundoOperando int   segundo numero ingresado, reemplaza la y
 * \return void  no devuelve nada
 */


int suma(int numero1, int numero2);

int resta(int numero1,int numero2);

int division(int numero1, int numero2, float* resultado);

int multiplicacion(int numero1, int numero2);


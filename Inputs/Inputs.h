

/** * \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
* */

int getInt(int* valor,char message[],char eMessage[],int lowLimit, int hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
* */ int getFloat(float* valor,char message[],char eMessage[], float lowLimit, float hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
* */
 int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida si es una letra y muestra el numero ascii que le corresponde
 *
 * \param letra char letra a validar
 * \return int numero ascii de la letra
 *
 */
int validarLetra(char letra);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error al pasar los limites
* \param eMessage Es el mensaje a ser mostrado en caso de error al poner un numero
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
* */

int getString(char* input,char message[],char eMessage[],char eNumMessage[], int lowLimit, int hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** \brief recorre un Array y determina si hay todos los caracteres son
            letras
 *
 * \param palabra Array a analiizar
 * \param tam tamanio del Array
 * \return int Si no encontro un numero [0] si encontro un numero [-1]
 *
 */
int validarLetrasEnString(char palabra[],int tam);

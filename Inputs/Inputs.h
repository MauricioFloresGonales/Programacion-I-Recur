

/** * \brief Solicita un n�mero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
* */

int getInt(int* valor,char message[],char eMessage[],int lowLimit, int hiLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita un n�mero al usuario y lo valida
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

/** \brief solicita una de las dos letras que se pide
 *
 * \param input Se carga el caracter ingresado
 * \param message[] Es el mensaje a ser mostrado
 * \param eMessage[] Es el mensaje a ser mostrado en caso de error
 * \param oneLimit letra que se puede ingrear
 * \param twoLimit otra letra que se puede ingrear
 * \return int Si obtuvo el caracter [0] si no [-1]
 *
 */
int getOneChar(char* input,char message[],char eMessage[],char oneLimit, char twoLimit);

//------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida que solo sea una letra y que no sea un numero
 *
 * \param input Letra a validar
 * \return int si solo se ingreseo una letra [0] si no [-1]
 *
 */
int validarUnaLetra(char input);

//------------------------------------------------------------------------------------------------------------------------------------------

/** * \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error al pasar los limites
* \param eMessage Es el mensaje a ser mostrado en caso de error al poner un numero
* \param lowLimit Longitud m�nima de la cadena
* \param hiLimit Longitud m�xima de la cadena
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

//------------------------------------------------------------------------------------------------------------------------------------------



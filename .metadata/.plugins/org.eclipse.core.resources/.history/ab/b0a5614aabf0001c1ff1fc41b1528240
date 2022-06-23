/*
 * utn.h
 *
 *  Created on: 20 jun. 2022
 *      Author: ayala
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
//Se usa para conseguir un numero
int getInt(int* pResultado);

//Se usa para conseguir un numero flotante
int getFloat(int* pResultado);

//Se usa para conseguir una cadena de caracteres
int getCadena(char pResultado[]);

//Se usa para conseguir un codigo alfanumerico
int getCodigo(char pResultado[]);

//Se encarga de recibir los datos ingresados por teclado cuidando de que
//no se pase del limite
int myGets(char* cadena,int largo);

//Recibe una cadena de caracteres y comprueba que sea numerica
int esNumerica(char*cadena);

//Recibe una cadena de caracteres y comprueba que sea alfabetica
int esAlfabetica(char cadena[]);

//Recibe una cadena de caracteres alfanumerica
//y comprueba que no se pase del limite
int esCodigo(char*cadena);

//Devuelve 0 y copia el numero ingresado en pResultado
//si todo sale bien o devuelve -1 Si falla
int utn_getNumero(int* pResultado, char* mensaje,
char* mensajeError,int minimo,int maximo, int reintentos);

//Devuelve 0 y copia el numero ingresado en pResultado
//si todo sale bien o devuelve -1 Si falla
int utn_getNumeroFlotante(float* pResultado, char* mensaje,
char* mensajeError,float minimo,float maximo, int reintentos);

//Devuelve 0 y copia el caracter ingresado en pResultado
//si todo sale bien o devuelve -1 Si falla
int utn_getCaracter(char* pResultado, char* mensaje,
char* mensajeError,char minimo,char maximo, int reintentos);

//Devuelve 0 y copia la cadena ingresada en pResultado
//si todo sale bien o devuelve -1 Si falla
int utn_getCadena(char* pResultado[],char* mensaje,char* mensajeError
,int largo,int reintentos);

//Devuelve 0 y copia la cadena ingresada en pResultado
//si todo sale bien o devuelve -1 Si falla
int utn_getCodigo(char* pResultado[],char* mensaje,
char* mensajeError,int largo,int reintentos);

/*int tomarDatos(char name[],char lastName[],
float* price,int* typePassenger, char flycode[],int* status,int* id);*/

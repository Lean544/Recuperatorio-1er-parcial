/*
 * vivienda.h
 *
 *  Created on: 20 jun. 2022
 *      Author: ayala
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_
struct
{

int idVivienda;
char calle[25];
int cantPersonas;
int cantHabitaciones;
int tipoVivienda;
int legajoCencista;
int idCatastro;
int isEmpty;

}typedef eVivienda;

struct
{
int tipoVivienda;
char descripcion [25];

}typedef tipoVivienda;


#endif /* VIVIENDA_H_ */

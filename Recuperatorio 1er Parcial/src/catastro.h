/*
 * catastro.h
 *
 *  Created on: 20 jun. 2022
 *      Author: ayala
 */

#ifndef CATASTRO_H_
#define CATASTRO_H_
struct
{
int idCatastro;
char localidad[25];
int manzana;
int parcela;
}typedef eCatastro;

struct
{
int tipoCatastro;
char descripcion [25];

}typedef tipoCatastro;
#endif /* CATASTRO_H_ */

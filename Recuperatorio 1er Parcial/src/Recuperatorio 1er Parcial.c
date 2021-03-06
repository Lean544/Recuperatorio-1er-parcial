/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "vivienda.h"
#include "cencista.h"
#include "catastro.h"
#include "utn.h"
#include "tomarDatos.h"

#define TAM 2000
int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int retorno;
	int retornoMenu;
	int retornoUno;
	int contIngresos=0;
	eCencista cencistas[3];
	eCatastro catastros[5];
	eVivienda viviendas[TAM];
	eVivienda* pViviendas=NULL;
	pViviendas=viviendas;

	if(/*inicializarArray(pViviendas, TAM)==0 && cargaForzadaCencistas(cencistas,3)==0 &&
	cargaForzadaCatastros(catastros,5)==0 && cargarCatastrosYCencistas(viviendas,cencistas,catastros,TAM)==0*/
	cargaForzada(viviendas,cencistas,catastros,TAM,3,5)==0 && inicializarArray(pViviendas,TAM)==0){
		retorno=0;
	}

	if(retorno==0){
			do
			{
				retornoMenu = utn_getNumero(&menu,"1.Altas Vivienda\n"
				"2.Modificar Vivienda\n3.Baja Vivienda\n4.Listar Viviendas\n"
				"5.Listar Cencistas\n6.Salir","Error",1,6,2);
				if(retornoMenu == 0){
						switch(menu){
								case 1:
									if(ingresar(pViviendas,TAM)==0)
									{
										retornoUno=0;
										contIngresos++;
										printf("Datos Tomados!\n");
									}
								break;


								case 2:
									if(retornoUno==0){
										modificarVivienda(pViviendas,TAM);
									}else{
										printf("Error no se completo la funcion Uno\n");
									}

										break;

								case 3:
									if(retornoUno==0){
									 eliminar(viviendas, TAM);
									}else{
										printf("Error no se completo la funcion Uno\n");
										}
										break;


								case 4:
									if(retornoUno==0 && contIngresos == 1){
										imprimirUnaVivienda(viviendas);
									}else if(retornoUno==0 && contIngresos > 1){
										listarViviendas(viviendas,TAM,cencistas,catastros);

									}else{
										printf("Error no se completo la funcion Uno\n");
									}
										break;

								case 5:

									listarCencistas(cencistas,3);
										break;

								case 6:
										printf("Finalizando programa");
										break;
									}
				}else{
					printf("Error en el Menu\n");
				}

			}while(menu!=6);
	}else{
		printf("Error al inicializar\n");
	}
	return EXIT_SUCCESS;
}

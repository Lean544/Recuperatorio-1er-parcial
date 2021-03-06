/*
 * tomarDatos.c
 *
 *  Created on: 20 jun. 2022
 *      Author: ayala
 */
#include <stdio.h>
#include <stdlib.h>
#include "vivienda.h"
#include "cencista.h"
#include "catastro.h"
#include "utn.h"
#include "string.h"

int inicializarArray(eVivienda* list, int len)
{
	int retorno=-1;
	if(list !=NULL && len>0){
		for(int i=0;i<len;i++){
					(list+i)->isEmpty=1;
					(list+i)->idVivienda=20000;
					retorno=0;
		}
	}else{
		return retorno;
	}


return retorno;
}

/*int cargaForzadaCencistas(eCencista array[],int len){
	int retorno=-1;
	int i;
	eCencista cencistas[3]={
		{100,"Ana",34,12032345},
		{101,"Juan",24,430154678},
		{102,"Sol",47,590237487}
	};

	if(array !=NULL && len>0){
		for(i=0;i<len;i++){
			(*(array+i))=(*(cencistas+i));
			retorno=0;
		}

	}

	return retorno;
}

int cargaForzadaCatastros(eCatastro catastros[],eCencista cencistas[],int len,int lenUno){
	int retorno=-1;
	int i;
	int j;
	eCatastro auxCatastros[5]=
	{
			{1000,"Avellaneda",28,1540},
			{1001,"Lanus",43,1789},
			{1002,"Quilmes",32,1624},
			{1003,"La Plata",67,1677},
			{1004,"Lomas de Zamora",32,1923}
	};
	eCencista auxCencistas[3]={
		{100,"Ana",34,12032345},
		{101,"Juan",24,430154678},
		{102,"Sol",47,590237487}
	};

	if(catastros !=NULL && cencistas !=NULL && len>0){
		for(i=0;i<len;i++){
			(*(catastros+i))=(*(auxCatastros+i));
			retorno=0;
		}
		for(j=0;j<4;j++){

		}

	}

	return retorno;
}*/

int cargaForzada(eVivienda list[],eCencista cencistas[],eCatastro catastros[],int len,int lenCencistas,int lenCatastros){
	int retorno=-1;
	int i;
	int j;
	int x;
	int contCencistas=0;
	int contCatastros=0;

	eCatastro auxCatastros[5]=
	{
			{1000,"Avellaneda",28,1540},
			{1001,"Lanus",43,1789},
			{1002,"Quilmes",32,1624},
			{1003,"La Plata",67,1677},
			{1004,"Lomas de Zamora",32,1923}
	};
	eCencista auxCencistas[3]={
		{100,"Ana",34,12032345},
		{101,"Juan",24,430154678},
		{102,"Sol",47,590237487}
	};

	if(list!=NULL && cencistas !=NULL && catastros!=NULL && len>0){
		for(j=0;j<lenCatastros;j++){
			(*(catastros+j))=(*(auxCatastros+j));
		}
		for(x=0;x<lenCencistas;x++){
			(*(cencistas+x))=(*(auxCencistas+x));
		}

		for(i=0;i<len;i++){
			(*(list+i)).idCatastro=(*(catastros+contCatastros)).idCatastro;
			contCatastros++;
			if(contCatastros==5){
				contCatastros=0;
			}

			(*(list+i)).legajoCencista=(*(cencistas+contCencistas)).legajoCencista;
			contCencistas++;
			if(contCencistas==3){
				contCencistas=0;
			}
			retorno=0;

		}
	}

	return retorno;
}


int ingresar(eVivienda* list, int len)
{
	int retorno=-1;
	int i;
	for(i=0;i<len;i++){
		if((list+i)->isEmpty==1 && (list+i)->legajoCencista !=0 && (list+i)->idCatastro!=0){
			if(utn_getCadena((list+i)->calle,"Ingrese la Calle","Error",51,5)==0 &&
				utn_getNumero(&(list+i)->cantPersonas,"Ingrese La cantidad de personas","Error",1,100,5)==0 &&
				utn_getNumero(&(list+i)->cantHabitaciones,"Ingrese la cantidad de Habitaciones","Error",1,100,5)==0 &&
				utn_getNumero(&(list+i)->tipoVivienda,"Ingrese el tipo de Vivienda:\n1)Casa\n"
				"2)Departamento\n3)Casilla\n4)Rancho","Error",1,4,5)==0){
					(list+i)->isEmpty=0;
					(list+i)->idVivienda=(list+i)->idVivienda+i;
					retorno=0;
				printf("\n----------------------------------------------------\n\n");
				printf(" La calle ingresado es:%s\n",(list+i)->calle);
				printf(" La cantidad de personas en la vivienda son:%d\n",(list+i)->cantPersonas);
				printf(" La cantidad de habitaciones son:%d\n",(list+i)->cantHabitaciones);
				printf(" El tipo de vivienda es %d\n",(list+i)->tipoVivienda);
				printf(" El id de la vivienda es %d\n",(list+i)->idVivienda);
				printf(" Legajo de su cencista %d\n",(list+i)->legajoCencista);
				printf(" Id de su catastro %d",(list+i)->idCatastro);
				printf("\n----------------------------------------------------\n\n");
			}
			break;
		}else{
			printf("Error");
		}

	}


	return retorno;
}

int findById(eVivienda* list, int len,int id)
{
	int retorno=-1;
	int i;

	for(i=0;i<len;i++){
		if(id==(list+i)->idVivienda){
			printf("Vivienda encontrada!\n");
			retorno= i;
			break;
		}
	}
 return retorno;
}


int modificarVivienda(eVivienda* list,int len)
{
	int menu;
	int idModificar;
	int busqueda;
	int retorno=-1;

	utn_getNumero(&idModificar,"Ingrese la Id del pasajero a modificar","Error",20000,30000,5);

	busqueda=findById(list,len,idModificar);


	if(busqueda!=-1){
		do{
			utn_getNumero(&menu,"Que desea modificar?\n1)Calle\n2)Cantidad de personas\n"
					"3)Cantidad de habitaciones\n4)Tipo de vivienda\n5)Salir","Error",1,5,5);

			switch(menu){
				case 1:
						printf("La calle actual es: %s\n",(list+busqueda)->calle);

						if(utn_getCadena((list+busqueda)->calle,"Ingrese la calle nueva",
						"Error",25,5)==0){
							retorno=0;
							printf("La calle nueva es %s\n",(list+busqueda)->calle);
						}else{
							printf("Error al actualizar el nombre\n");
						}



					break;

				case 2:
					printf("La cantidad de personas"
					"actual es: %d\n",(list+busqueda)->cantPersonas);

					if(utn_getNumero(&(list+busqueda)->cantPersonas,
					"Ingrese la nueva cantidad de personas","Error",1,100,5)==0){
						retorno=0;
						printf("La cantidad de personas nueva es %d\n",(list+busqueda)->cantPersonas);
					}else{
						printf("Error al actualizar la cantidad\n");
					}

					break;

				case 3:
					printf("La cantidad de habitaciones"
					"actual es: %d\n",(list+busqueda)->cantHabitaciones);

					if(utn_getNumero(&(list+busqueda)->cantHabitaciones,
					"Ingrese la nueva cantidad de habitaciones","Error",1,100,5)==0){
						retorno=0;
						printf("La cantidad de habitaciones nueva es %d\n",(list+busqueda)->cantHabitaciones);
					}else{
						printf("Error al actualizar la cantidad\n");
					}


					break;

				case 4:
					printf("El tipo de vivienda actual es: %d\n",(list+busqueda)->tipoVivienda);

					if(utn_getNumero(&(list+busqueda)->tipoVivienda,
					"Ingrese El tipo de Vivienda nuevo\n1)Casa\n2)Departamento\n3)Casilla\n4)Rancho","Error",1,4,5)==0){
						retorno=0;
						printf("El tipo de vivienda nuevo es:%d\n",(list+busqueda)->tipoVivienda);
					}else{
						printf("Error al actualizar la cantidad\n");
					}

					break;


				case 5:
					printf("Finalizando Submenu\n");
					break;

					}
			}while(menu!=5);
	}else{
		printf("Error pasajero no encontrado\n");
	}
	return retorno;
}

//int eliminar(eVivienda* list, int len)
int eliminar(eVivienda list[], int len)
{
	int idAux;
	int retorno=-1;
	int retornoBusqueda;
		utn_getNumero(&idAux,"Ingrese la id de la vivienda a eliminar","Error",20000,30000,5);
		retornoBusqueda=findById(list,len,idAux);
		if(retornoBusqueda!=-1){
			printf("Posicion %d\n",retornoBusqueda);
			//(list+idAux)->isEmpty=1;
			(*(list+retornoBusqueda)).isEmpty=1;
			retorno=0;

		}else{
		printf("Error vivienda no encontrada\n");
		}
	return retorno;
}


void listarCencistas(eCencista cencistas[],int len)
{
	int i;

	printf("Cencistas:\n");

	for(i=0;i<len;i++){
		printf("---------------------------------\n");
		printf("Legajo:%d\n",(*(cencistas+i)).legajoCencista);
		printf("Nombre:%s\n",(*(cencistas+i)).nombre);
		printf("Edad:%d\n",(*(cencistas+i)).edad);
		printf("Telefono:%d\n",(*(cencistas+i)).telefono);
	}
	printf("---------------------------------\n");
}

int sortPassengersByCode(eVivienda list[], int len)
{
	int retorno=-1;
	int flagCambio;
	int i;
	eVivienda auxVivienda;

	if(list!=NULL && len>0){
			do{
				flagCambio = 0;
				for(i = 0; i < len-1; i++){

					if(strcmp((*(list+i)).calle,(*(list+i+1)).calle)>0 && (*(list+i)).isEmpty==0){

						flagCambio = 1;
						auxVivienda=(*(list+i));
						(*(list+i))=(*(list+i+1));
						(*(list+i+1))=auxVivienda;
						retorno=0;
					}else if(strcmp((*(list+i)).calle,(*(list+i+1)).calle)==0 &&
							(*(list+i)).cantPersonas>(*(list+i+1)).cantPersonas){
						auxVivienda=(*(list+i));
						(*(list+i))=(*(list+i+1));
						(*(list+i+1))=auxVivienda;
						retorno=0;
					}
				}
				}while(flagCambio == 1);
	}else{
		retorno=-1;
	}

  return retorno;
}

void imprimirPorTipo(eVivienda list[],int len)
{
	int i;
	int j;
	int tipo;
	int retornoTipo;
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	tipoVivienda auxTipo[]={
			{1,"Casa"},
			{2,"Departamento"},
			{3,"Casilla"},
			{4,"Rancho"}
	};

	retornoTipo=utn_getNumero(&tipo,"Ingrese El tipo de vivienda que desea mostrar\n"
			"1)Casa\n2)Departamento\n3)Casilla\n4)Rancho","Error",1,4,5);
	if(retornoTipo==0)
	{
		for(j=0;j<5;j++){
			if(tipo==(*(auxTipo+j)).tipoVivienda){
				break;
			}
		}
		printf("Viviendas del tipo Seleccionado:");
		printf("\n*******************************************************************************************************\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Calle",anchoColumnasNumero,
				"Cant de Personas",anchoColumnasTexto,"Cant de Habitaciones",anchoColumnasTexto,"Tipo de Vivienda",
				anchoColumnasTexto,"Legajo del cencista",anchoColumnasNumero,"Id del catastro");

		for(i=0;i<len;i++){
			if((*(list+i)).isEmpty==0 && (*(list+i)).tipoVivienda == tipo){
				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*d|%*d|%*s|%*d|%*d|\n",anchoColumnasTexto,(*(list+i)).idVivienda,anchoColumnasNumero,(*(list+i)).calle
				,anchoColumnasNumero,(*(list+i)).cantPersonas,anchoColumnasTexto,(*(list+i)).cantHabitaciones
				,anchoColumnasTexto,(*(auxTipo+j)).descripcion,
				anchoColumnasTexto,(*(list+i)).legajoCencista,anchoColumnasNumero,(*(list+i)).idCatastro);
			}
		}

	}else{
		printf("Error al ingresar el tipo\n");
	}
}

void imprimirPorLocalidad(eVivienda list[],int len)
{
	int i;
	int j;
	int x;
	int tipo;
	int retornoTipo;
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	tipoCatastro auxCatastro[]={
			{1000,"Avellaneda"},
			{1001,"Lan?s"},
			{1002,"Quilmes"},
			{1003,"La Plata"},
			{1004,"Lomas de Zamora"}
	};
	tipoVivienda auxTipo[]={
			{1,"Casa"},
			{2,"Departamento"},
			{3,"Casilla"},
			{4,"Rancho"}
	};


	retornoTipo=utn_getNumero(&tipo,"Ingrese La localidad que desea mostrar\n"
			"1000.Avellaneda\n1001.Lanus\n1002.Quilmes\n1003.La Plata\n1004.Lomas de Zamora"
			,"Error",1000,1004,5);
	if(retornoTipo==0)
	{
		for(x=0;x<6;x++){
			if(tipo==(*(auxCatastro+x)).tipoCatastro){
				break;
			}
		}

		printf("Viviendas del tipo Seleccionado:");
		printf("\n*******************************************************************************************************\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Calle",anchoColumnasNumero,
				"Cant de Personas",anchoColumnasTexto,"Cant de Habitaciones",anchoColumnasTexto,"Tipo de Vivienda",
				anchoColumnasTexto,"Legajo del cencista",anchoColumnasNumero,"Localidad");

		for(i=0;i<len;i++){
			if((*(list+i)).isEmpty==0 && (*(list+i)).idCatastro == tipo){
				for(j=0;j<5;j++){
					if((*(list+i)).tipoVivienda==(*(auxTipo+j)).tipoVivienda){
						break;
					}
				}
				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*d|%*d|%*s|%*d|%*s|\n",anchoColumnasTexto,(*(list+i)).idVivienda,anchoColumnasNumero,(*(list+i)).calle
				,anchoColumnasNumero,(*(list+i)).cantPersonas,anchoColumnasTexto,(*(list+i)).cantHabitaciones
				,anchoColumnasTexto,(*(auxTipo+j)).descripcion,
				anchoColumnasTexto,(*(list+i)).legajoCencista,anchoColumnasNumero,(*(auxCatastro+x)).descripcion);
			}
		}

	}else{
		printf("Error al ingresar el tipo\n");
	}
}

void imprimirAvellaneda(eVivienda list[],int len){
	int i;
	int j;
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	tipoVivienda auxTipo[]={
			{1,"Casa"},
			{2,"Departamento"},
			{3,"Casilla"},
			{4,"Rancho"}
	};

	printf("Viviendas de Avellaneda:\n");
	printf("\n*******************************************************************************************************\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Calle",anchoColumnasNumero,
	"Cant de Personas",anchoColumnasTexto,"Cant de Habitaciones",anchoColumnasTexto,"Tipo de Vivienda",
	anchoColumnasTexto,"Legajo del cencista",anchoColumnasNumero,"Localidad");

	for(i=0;i<len;i++){
		if((*(list+i)).isEmpty==0 && (*(list+i)).idCatastro == 1000){
			for(j=0;j<5;j++){
				if((*(list+i)).tipoVivienda==(*(auxTipo+j)).tipoVivienda){
					break;
				}
			}
			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*d|%*s|%*d|%*d|%*s|%*d|%*s|\n",anchoColumnasTexto,(*(list+i)).idVivienda,anchoColumnasNumero,(*(list+i)).calle
			,anchoColumnasNumero,(*(list+i)).cantPersonas,anchoColumnasTexto,(*(list+i)).cantHabitaciones
			,anchoColumnasTexto,(*(auxTipo+j)).descripcion,
			anchoColumnasTexto,(*(list+i)).legajoCencista,anchoColumnasNumero,"Avellaneda");
		}
	}


}

void imprimirPorCencista(eVivienda list[],int len){
		int i;
		int j;
		int x;
		int h;
		int tipo;
		int retornoTipo;
		int anchoColumnasTexto=-20;
		int anchoColumnasNumero=-20;
		tipoCatastro auxCatastro[]={
				{1000,"Avellaneda"},
				{1001,"Lan?s"},
				{1002,"Quilmes"},
				{1003,"La Plata"},
				{1004,"Lomas de Zamora"}
		};
		tipoVivienda auxTipo[]={
				{1,"Casa"},
				{2,"Departamento"},
				{3,"Casilla"},
				{4,"Rancho"}
		};
		eCencista auxCencistas[]={
				{100,"Ana"},
				{101,"Juan"},
				{102,"Sol"}
		};


		retornoTipo=utn_getNumero(&tipo,"Ingrese el cencista que desea mostrar\n"
				"100.Ana\n101.Juan\n102.Sol\n","Error",100,102,5);
		if(retornoTipo==0)
		{
			for(h=0;h<4;h++){
				if(tipo==(*(auxCencistas+h)).legajoCencista){
					break;
				}
			}

			printf("Viviendas del tipo Seleccionado:");
			printf("\n*******************************************************************************************************\n");
			printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Calle",anchoColumnasNumero,
					"Cant de Personas",anchoColumnasTexto,"Cant de Habitaciones",anchoColumnasTexto,"Tipo de Vivienda",
					anchoColumnasTexto,"Cencista",anchoColumnasNumero,"Localidad");

			for(i=0;i<len;i++){
				if((*(list+i)).isEmpty==0 && (*(list+i)).legajoCencista == tipo){
					for(j=0;j<5;j++){
						if((*(list+i)).tipoVivienda==(*(auxTipo+j)).tipoVivienda){
							break;
						}
					}
					for(x=0;x<6;x++){
						if((*(list+i)).idCatastro==(*(auxCatastro+x)).tipoCatastro){
							break;
						}
					}
					printf("\n----------------------------------------------------------------------------------------------------\n");
					printf("|%*d|%*s|%*d|%*d|%*s|%*s|%*s|\n",anchoColumnasTexto,(*(list+i)).idVivienda,anchoColumnasNumero,(*(list+i)).calle
					,anchoColumnasNumero,(*(list+i)).cantPersonas,anchoColumnasTexto,(*(list+i)).cantHabitaciones
					,anchoColumnasTexto,(*(auxTipo+j)).descripcion,
					anchoColumnasTexto,(*(auxCencistas+h)).nombre,anchoColumnasNumero,(*(auxCatastro+x)).descripcion);
				}
			}

		}else{
			printf("Error al ingresar el tipo\n");
		}

}

void listarCasas(eVivienda list[],int len){
	int i;
	int j;
	int x;
	int h;
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	tipoCatastro auxCatastro[]={
			{1000,"Avellaneda"},
			{1001,"Lan?s"},
			{1002,"Quilmes"},
			{1003,"La Plata"},
			{1004,"Lomas de Zamora"}
	};
	tipoVivienda auxTipo[]={
			{1,"Casa"},
			{2,"Departamento"},
			{3,"Casilla"},
			{4,"Rancho"}
	};
	eCencista auxCencistas[]={
			{100,"Ana"},
			{101,"Juan"},
			{102,"Sol"}
	};

		printf("Viviendas de tipo Casa:");
		printf("\n*******************************************************************************************************\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Calle",anchoColumnasNumero,
				"Cant de Personas",anchoColumnasTexto,"Cant de Habitaciones",anchoColumnasTexto,"Tipo de Vivienda",
				anchoColumnasTexto,"Cencista",anchoColumnasNumero,"Localidad");

		for(i=0;i<len;i++){
			if((*(list+i)).isEmpty==0 && (*(list+i)).tipoVivienda == 1){
				for(j=0;j<5;j++){
					if((*(list+i)).tipoVivienda==(*(auxTipo+j)).tipoVivienda){
						break;
					}
				}
				for(x=0;x<6;x++){
					if((*(list+i)).idCatastro==(*(auxCatastro+x)).tipoCatastro){
						break;
					}
				}
				for(h=0;h<4;h++){
					if((*(list+i)).legajoCencista==(*(auxCencistas+h)).legajoCencista){
						break;
					}
				}

				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*d|%*d|%*s|%*s|%*s|\n",anchoColumnasTexto,(*(list+i)).idVivienda,anchoColumnasNumero,(*(list+i)).calle
				,anchoColumnasNumero,(*(list+i)).cantPersonas,anchoColumnasTexto,(*(list+i)).cantHabitaciones
				,anchoColumnasTexto,(*(auxTipo+j)).descripcion,
				anchoColumnasTexto,(*(auxCencistas+h)).nombre,anchoColumnasNumero,(*(auxCatastro+x)).descripcion);
				}
			}
}

void listarDepartamentosLanus(eVivienda list[],int len){
	int i;
	int j;
	int x;
	int h;
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	tipoCatastro auxCatastro[]={
			{1000,"Avellaneda"},
			{1001,"Lan?s"},
			{1002,"Quilmes"},
			{1003,"La Plata"},
			{1004,"Lomas de Zamora"}
	};
	tipoVivienda auxTipo[]={
			{1,"Casa"},
			{2,"Departamento"},
			{3,"Casilla"},
			{4,"Rancho"}
	};
	eCencista auxCencistas[]={
			{100,"Ana"},
			{101,"Juan"},
			{102,"Sol"}
	};

		printf("Viviendas de tipo Casa:");
		printf("\n*******************************************************************************************************\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Calle",anchoColumnasNumero,
				"Cant de Personas",anchoColumnasTexto,"Cant de Habitaciones",anchoColumnasTexto,"Tipo de Vivienda",
				anchoColumnasTexto,"Cencista",anchoColumnasNumero,"Localidad");

		for(i=0;i<len;i++){
			if((*(list+i)).isEmpty==0 && (*(list+i)).tipoVivienda == 2 && (*(list+i)).idCatastro==1001){
				for(j=0;j<5;j++){
					if((*(list+i)).tipoVivienda==(*(auxTipo+j)).tipoVivienda){
						break;
					}
				}
				for(x=0;x<6;x++){
					if((*(list+i)).idCatastro==(*(auxCatastro+x)).tipoCatastro){
						break;
					}
				}
				for(h=0;h<4;h++){
					if((*(list+i)).legajoCencista==(*(auxCencistas+h)).legajoCencista){
						break;
					}
				}

				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*d|%*d|%*s|%*s|%*s|\n",anchoColumnasTexto,(*(list+i)).idVivienda,anchoColumnasNumero,(*(list+i)).calle
				,anchoColumnasNumero,(*(list+i)).cantPersonas,anchoColumnasTexto,(*(list+i)).cantHabitaciones
				,anchoColumnasTexto,(*(auxTipo+j)).descripcion,
				anchoColumnasTexto,(*(auxCencistas+h)).nombre,anchoColumnasNumero,(*(auxCatastro+x)).descripcion);
				}
			}
}

void listarViviendas(eVivienda list[],int len,eCencista listCencistas[],eCatastro listCatastros[]){

	int menu;
	int retornoMenu;
	int retorno;

	retorno=sortPassengersByCode(list,len);

	if(retorno==0)
	{
		do{
			retornoMenu=utn_getNumero(&menu,"Ingrese la forma en la que desea la lista:\n"
			"1)Elegir un tipo de vivienda y mostrar solo las de ese tipo\n"
			"2)Elegir una localidad y mostrar todas las viviendas de ella\n"
			"3)Viviendas de Avellaneda\n"
			"4)Elegi un cencista y mostrar las viviendas que censo\n"
			"5)Mostrar solo las casas\n"
			"6)Mostrar solo departamentos en la localidad de lanus\n"
			"7)Volver al menu anterior\n","Error",1,7,5);
			if(retornoMenu==0){
				switch(menu){
				case 1:
					imprimirPorTipo(list,len);
					break;

				case 2:
					imprimirPorLocalidad(list,len);
					break;

				case 3:
					imprimirAvellaneda(list,len);
					break;

				case 4:
					imprimirPorCencista(list,len);
					break;

				case 5:
					listarCasas(list,len);
					break;

				case 6:
					listarDepartamentosLanus(list,len);
					break;

				case 7:

					printf("Finalizando SubMenu\n");

				}

			}else{
				printf("Error en el menu");
			}
		}while(menu!=7);
	}
}

void imprimirUnaVivienda(eVivienda list[]){
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	int i;
	tipoVivienda auxTipo[]={
			{1,"Casa"},
			{2,"Departamento"},
			{3,"Casilla"},
			{4,"Rancho"}
	};

	for(i=0;i<5;i++){
		if((*(list+0)).tipoVivienda==(*(auxTipo)).tipoVivienda){
			break;
		}
	}
	printf("Viviendas del tipo Seleccionado:");
	printf("\n*******************************************************************************************************\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|",anchoColumnasTexto,"Id",anchoColumnasTexto,"Calle",anchoColumnasNumero,
			"Cant de Personas",anchoColumnasTexto,"Cant de Habitaciones",anchoColumnasTexto,"Tipo de Vivienda",
			anchoColumnasTexto,"Legajo del cencista",anchoColumnasNumero,"Id del catastro");
			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*d|%*s|%*d|%*d|%*s|%*d|%*d|\n",anchoColumnasTexto,(*(list+0)).idVivienda,anchoColumnasNumero,(*(list+0)).calle
			,anchoColumnasNumero,(*(list+0)).cantPersonas,anchoColumnasTexto,(*(list+0)).cantHabitaciones
			,anchoColumnasTexto,(*(auxTipo+i)).descripcion,
			anchoColumnasTexto,(*(list+0)).legajoCencista,anchoColumnasNumero,(*(list+i)).idCatastro);
			printf("\n----------------------------------------------------------------------------------------------------\n");

}

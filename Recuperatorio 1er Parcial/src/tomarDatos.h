/*
 * tomarDatos.h
 *
 *  Created on: 20 jun. 2022
 *      Author: ayala
 */
//Inicializa todos los campos isEmpty del array en 1 y inicializa todos los id en 20000
int inicializarArray(eVivienda* list, int len);

//Carga los cencistas y catastros en sus arrays y luego los carga en las viviendas
int cargaForzada(eVivienda list[],eCencista cencistas[],eCatastro catastros[],int len,int lenCencistas,int lenCatastros);

//Toma por teclado los datos de una vivienda y los pone en la primer posicion vacia
int ingresar(eVivienda* list,int len);

//Recibe un id y busca en el array si lo encuentra retorna la posicion
int findById(eVivienda* list, int len,int id);

//Modifica cualquiera de los campos de alguna de las posiciones del array
int modificarVivienda(eVivienda* list,int len);

//Pide un id por teclado y usa findById para buscarlo,si lo encuentra
//Cambia el campo isEmpty a 1
int eliminar(eVivienda list[], int len);

//Lista a todos lo cencistas del array
void listarCencistas(eCencista cencistas[],int len);

//Pide el tipo de vivienda que desea y muestra solo las de ese tipo
void imprimirPorTipo(eVivienda list[],int len);

//Pide la localidad y muestra solo las viviendas que estan
//ingresadas en ella
void imprimirPorLocalidad(eVivienda list[],int len);

//Muestra solo las viviendas registradas en Avellaneda
void imprimirAvellaneda(eVivienda list[],int len);

//Pide el legajo del cencista y muestra solo las viviendas
//censadas por este
void imprimirPorCencista(eVivienda list[],int len);

//Lista solo las viviendas del tipo casa
void listarCasas(eVivienda list[],int len);

//Lista solo las viviendas de tipo departamento
//registradas en Lanus
void listarDepartamentosLanus(eVivienda list[],int len);

//Despliega un submenu con opciones para listar
//Las viviendas ingresadas
void listarViviendas(eVivienda list[],int len,eCencista listCencistas[],eCatastro listCatastros[]);

//Se utiliza solo cuando hay una vivienda ingresada
//Imprime una sola vivienda
void imprimirUnaVivienda(eVivienda list[]);

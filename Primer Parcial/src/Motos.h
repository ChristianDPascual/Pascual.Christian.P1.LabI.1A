#ifndef MOTOS_H_
#define MOTOS_H_
#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#define V 20
#define T 30
#define TAM 1000
#define TRUE 0
#define FALSE -1

typedef struct
{
	char dia[V];
	char mes[V];
	char anio[V];
}eFecha;

typedef struct
{
	int id;//comienza en 1000
	char descripcion[21];//Enduro, Chopera, Scooter, Vintage
}eTipo;

typedef struct
{
	int id;//comienza en 10000
	char nombreColor[V];//Gris, Negro, Azul, Blanco, Rojo
}eColor;

typedef struct
{
	int id;
	char marca[V];
	int idTipo;
	int idColor;
	int cilindrada[5];//50, 125, 500, 600, 750
	int puntaje;
}eMoto;

typedef struct
{
	int id[V];//comienza en 2000
	char descripcion[21];//(Limpieza: $450, Ajuste: $300, Balanceo: $150, Cadena: $390)
	float precio[V];

}eServicio;

typedef struct
{
	int id;
	int idMoto;
	int idServicio;
	int fecha;
}eTrabajo;

int inicializarMotos(eMoto[],int);
int inicializarTipos(eTipo[],int);
int inicializarColores(eColor[],int);
int inicializarServicios(eServicio[],int);
int ingresarMoto(eMoto[],eColor[],eTipo[],int,int);
int agregarColor(eColor[],char[],int);
int agregarTipo(eTipo[],char[],int);
int generarID(eMoto[],int);
int modificarMoto(eMoto[],eColor[],int,int);
void mostrarUnaMoto(eMoto[],eColor[],int,int,int);
int buscarPorID(eMoto[],int,int);
#endif /* MOTOS_H_ */

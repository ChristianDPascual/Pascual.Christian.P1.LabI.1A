#include <stdio.h>
#include <stdlib.h>
#include "Motos.h"
#include "UTN.h"
#define T 30
#define V 20
#define TAM 1000
#define TRUE 0
#define FALSE -1


int main(void)
{
	setbuf(stdout,NULL);
	eFecha Fecha[TAM];
	eTipo Tipos[T];
	eColor Colores[T];
	eMoto Motos[TAM];
	eServicio Servicios[T];
	eTrabajo Trabajos[TAM];
	int opciones;
	char cOpciones[2];
	int inicioM;
	int inicioC;
	int inicioS;
	int inicioT;
	int verificar;
	int opcionOrden;
	char tipoOrden[2];

	if(((inicioM=inicializarMotos(Motos,TAM))==TRUE) && ((inicioT=inicializarTipos(Tipos,T))==TRUE) && ((inicioC=inicializarColor(Colores,T))==TRUE) && ((inicioS=inicializarServicios(Servicios,T))==TRUE))
	{
	do
	{
	printf("Elija la opcion\n");
	printf("1 Alta Moto\n");
	printf("2 Modificar Moto\n");
	printf("3 Baja Motos\n");
	printf("4 Listar Motos\n");
	printf("5 Listar Tipos\n");
	printf("6 Listar Colores\n");
	printf("7 Listar Servicios\n");
	printf("8 Alta trabajo\n");
	printf("9 Salir\n");
	fflush(stdin);
	scanf("%[^\n]",cOpciones);
	opciones=atoi(cOpciones);

	while((verificar=validarNumeroEntero(cOpciones))==FALSE || (opciones>9 || opciones<1))
	{
		printf("Error, Elija una opcion valida (1-9)\n");
		fflush(stdin);
		scanf("%[^\n]",cOpciones);
		opciones=atoi(cOpciones);
	}
	  switch(opciones)
	  {
	  case 1:
		  if(ingresarMoto(Motos,Colores,Tipos,TAM,T)==TRUE)
		  {
			  printf("Se agregado la moto exitosamente\n");
		  }
		  else
		  {
			  printf("No agrego la moto\n");
		  }
		  break;
	  case 2:
		  break;
	  case 3:
	      break;
	  case 4:
		  break;
	  case 5:
	   break;
	  case 6:
		  break;
	  case 7:
		  break;
	  case 8:
		  break;
	  case 9:
		  printf("Programa Finalizado\n");
		  break;
	  }
	}while(opciones!=9);
	}
	else
	{
		printf("ERROR, no se inicializo el programa\n");
	}

	return EXIT_SUCCESS;
}

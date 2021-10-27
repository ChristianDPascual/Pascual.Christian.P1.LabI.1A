#include <stdio.h>
#include <stdlib.h>
#include "Estructuras.h"
#include "Motos.h"
#include "UTN.h"
#include "Fecha.h"
#define V 20
#define LONG 31
#define TAM 1000
#define TRUE 0
#define FALSE -1


int main(void)
{
	setbuf(stdout,NULL);
	eFecha Fecha[TAM];
	eTipo Tipos[LONG];
	eColor Colores[LONG];
	eMoto Motos[TAM];
	eServicio Servicios[LONG];
	eTrabajo Trabajos[TAM];
	int opciones;
	int valor;
	int verificar;
	char cOpciones[2];

	if(((inicializarMotos(Motos,TAM))==TRUE) && ((inicializarTipos(Tipos,LONG))==TRUE) &&((inicializarTrabajos(Trabajos,TAM))==TRUE) &&((inicializarColores(Colores,LONG))==TRUE) && ((inicializarServicios(Servicios,LONG))==TRUE))
	{

	do
	{
	printf("\nElija la opcion\n");
	printf("1\tAlta Moto\n");
	printf("2\tModificar Moto\n");
	printf("3\tBaja Motos\n");
	printf("4\tListar Motos\n");
	printf("5\tListar Tipos\n");
	printf("6\tListar Colores\n");
	printf("7\tListar Servicios\n");
	printf("8\tAlta trabajo\n");
	printf("9\tListar Trabajo\n");
	printf("10\tSalir\n");
	fflush(stdin);
	scanf("%[^\n]",cOpciones);
	opciones=atoi(cOpciones);

	while((verificar=validarNumeroEntero(cOpciones))==FALSE || (opciones>10 || opciones<1))
	{
		printf("Error, Elija una opcion valida (1-10)\n");
		fflush(stdin);
		scanf("%[^\n]",cOpciones);
		opciones=atoi(cOpciones);
	}
	  switch(opciones)
	  {
	  case 1:
		  if(ingresarMoto(Motos,Colores,Tipos,TAM,LONG)==TRUE)
		  {
			  printf("Se agregado la moto exitosamente\n");
		  }

		  break;
	  case 2:
		  if(validarMenu(Motos,TAM)==TRUE)
		  {
		  if(modificarMoto(Motos,Colores,Tipos,TAM,LONG)==FALSE)
		  {
			  printf("El ID ingresado no existe\n");
			  printf("Necesita ver el listado, ");
			  if((valor=DarRespuesta())==TRUE)
			  {
				  mostrarMotoID(Motos,TAM);
			  }
		  }
		  }
		  else
		  {
			  printf("No hay motos cargadas\n");
		  }
		  break;
	  case 3:
		  if(validarMenu(Motos,TAM)==TRUE)
		  {
		  if(BajaMoto(Motos,Colores,Tipos,TAM,LONG)==FALSE)
		  {
			  printf("El ID ingresado no existe\n");
		 	  printf("Necesita ver el listado, ");
			  if((valor=DarRespuesta())==TRUE)
			  {
				  mostrarMotoID(Motos,TAM);
 			  }
		  }
		  }
		  else
		  {
			  printf("No hay motos cargadas\n");
		  }
	      break;
	  case 4:
		  if(validarMenu(Motos,TAM)==TRUE)
		  {
		  if(ListarMotoTipoID(Motos,Tipos,TAM,LONG)==FALSE)
		  {
			  printf("ERROR\n");
		  }
		  }
		  else
		  {
			  printf("No hay motos cargadas\n");
		  }
		  break;
	  case 5:
		  if(listarTipos(Tipos,LONG)==FALSE)
		  {
			  printf("Ocurrio un error inesperado\n");
		  }
	   break;
	  case 6:
		  if(listarColor(Colores,LONG)==FALSE)
		  {
			  printf("Ocurrio un error inesperado\n");
     	  }
		  break;
	  case 7:
		  if(listarServicios(Servicios,LONG)==FALSE)
		  {
			  printf("Ocurrio un error inesperado\n");

		  }
		  break;
	  case 8:
		  if(validarMenu(Motos,TAM)==TRUE)
		  {
		  if((cargarTrabajo(Motos,Trabajos,Servicios,Colores,Tipos,Fecha,TAM,LONG))==FALSE)
		  {
			  printf("El ID ingresado no existe\n");
			  printf("Necesita ver el listado, ");
			  if((valor=DarRespuesta())==TRUE)
			  {
				  mostrarMotoID(Motos,TAM);
			  }
		  }
		  }
		  else
		  {
			  printf("No hay motos cargadas\n");
		  }
		  break;
	  case 9:
		  if(validarMenu(Motos,TAM)==TRUE)
		  {
		  if(validarListarTrabajos(Trabajos,TAM)==TRUE)
		  {

		  if(listarTrabajos(Motos,Trabajos,Servicios,TAM,LONG)==FALSE)
		  {
			  printf("Ocurrio un error inesperado\n");
		  }
		  }
		  else
		  {
			  printf("No hay trabajos cargados\n");
		  }
		  }
		  else
		  {
			  printf("No hay motos cargadas\n");
		  }
		  break;
	  case 10:
		  printf("Programa Finalizado\n");
		  break;
	  }
	}while(opciones!=10);
	}
	else
	{
		printf("ERROR, no se inicializo el programa\n");
	}

	return EXIT_SUCCESS;
}

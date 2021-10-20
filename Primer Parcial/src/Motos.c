#include "Motos.h"
#include "UTN.h"

int inicializarMotos(eMoto listadoMotos[], int tam)
{
	int validacion=FALSE;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			listadoMotos[i].id=FALSE;
		}
		validacion=TRUE;
	}

	return validacion;
}

int inicializarColores(eColor listaColores[], int t)
{
	int validacion=FALSE;
	char auxColores[5][V]={"Gris","Negro","Azul","Blanco","Rojo"};
	int auxID[5]={10000,10001,10002,10003,10004};
	int i;

	if(t>0)
	{
		for(i=0;i<t;i++)
		{
			if(i<5)
			{
			strcpy(listaColores[i].nombreColor,auxColores[i]);
			listaColores[i].id=auxID[i];
			}
			else
			{
				listaColores[i].id=FALSE;
			}
		}
		validacion=TRUE;
	}

	return validacion;
}

int inicializarServicios(eServicio listaServicios[], int t)
{
	int validacion=FALSE;
	int i;
	int auxID[4]={2001,2002,2003,2004};
	char auxServicio[4][V]={"Limpieza","Ajuste","Balanceo","Cadena"};
	float auxPrecio[4]={450,300,150,390};

	if(t>0)
	{
		for(i=0;i<t;i++)
		{
			if(i<4)
			{
			    listaServicios[i].id=auxID[i];
			    strcpy(listaServicios[i].descripcion,auxServicio[i]);
			    listaServicios[i].precio=auxPrecio[i];
			}
			else
			{
				listaServicios[i].id=FALSE;
			}
		}
		validacion=TRUE;
    }

	return validacion;
}
int inicializarTipos(eTipo listaTipos[], int t)
{
	int validacion=FALSE;
	int i;
	int auxID[4]={1001,1002,1003,1004};
	char auxDescripcion[4][V]={"Enduro","Chopera","Scooter","Vintage"};

	if(t>0)
	{
		for(i=0;i<t;i++)
		{
			if(i<4)
			{
			    listaTipos[i].id=auxID[i];
			    strcpy(listaTipos[i].descripcion,auxDescripcion[i]);
			}
			else
			{
				listaTipos[i].id=FALSE;
			}
		}
		validacion=TRUE;
	}

	return validacion;
}

int ingresarMoto(eMoto moto[],eColor color[],eTipo tipos[],int tamanio,int t)
{
	int validacion=FALSE;
	int id;
	int puntaje;
	int cilindros;
	int idC;
	int idT;
	int i;
	char cCilindros[8];
	char colores[V];
	char tipo[V];
	char marca[V];
	char cPuntaje[3];


	id=generarID(moto,tamanio);

	printf("Ingrese la marca\n");
	fflush(stdin);
	scanf("%[^\n]",marca);

	while(validarPalabra(marca)==FALSE)
	{
		printf("Error, Ingrese la marca\n");
		fflush(stdin);
		scanf("%[^\n]",marca);
	}

	printf("Ingrese el tipo\n");
	fflush(stdin);
	scanf("%[^\n]",tipo);

	while(validarPalabra(tipo)==FALSE)
	{
		printf("Error, Ingrese el tipo\n");
		fflush(stdin);
		scanf("%[^\n]",tipo);
	}
	idT=validarTipo(tipos,tipo,t);
	if(idT==FALSE)
	{
		if(agregarTipo(tipos,tipo,t)==FALSE)
		{
			return validacion;
		}
	}

	printf("Ingrese el color\n");
	fflush(stdin);
	scanf("%[^\n]",colores);

	while(validarPalabra(colores)==FALSE)
	{
		printf("Error, Ingrese el color\n");
		fflush(stdin);
		scanf("%[^\n]",colores);
	}

	idC=validarColor(color,colores,t);
	if(idC==FALSE)
	{
		if(agregarColor(color,colores,t)==FALSE)
		{
			return validacion;
		}
	}

	printf("Ingrese la cilindrada de la moto(50 - 125 - 500 - 600 - 750)\n");
	fflush(stdin);
	scanf("%[^\n]",cCilindros);
	cilindros=atoi(cCilindros);
	while(validarNumeroEntero(cCilindros)==FALSE && validarCilindrada(cilindros)==FALSE)
	{
		printf("Error,Ingrese la cilindrada de la moto(50 - 125 - 500 - 600 - 750)\n");
		fflush(stdin);
		scanf("%[^\n]",cCilindros);
		cilindros=atoi(cCilindros);
	}

	printf("Ingrese el puntaje (1-10)\n");
	fflush(stdin);
	scanf("%[^\n]",cPuntaje);
	puntaje=atoi(cPuntaje);

	while(validarNumeroEntero(cPuntaje)==FALSE && (puntaje<1 || puntaje>10))
	{
		printf("Error, Ingrese el puntaje (1-10)\n");
		fflush(stdin);
		scanf("%[^\n]",cPuntaje);
		puntaje=atoi(cPuntaje);
	}

	for(i=0;i<tamanio;i++)
	{
		if(moto[i].id==FALSE)
		{
			moto[i].id=id;
			strcpy(moto[i].marca,marca);
			moto[i].idTipo=idT;
			moto[i].idColor=idC;
			moto[i].cilindrada=cilindros;
			moto[i].puntaje=puntaje;
			validacion=TRUE;
			break;
		}
	}

	return validacion;
}
int agregarColor(eColor listadoColores[],char nuevoColor[],int t)
{
	int validacion=FALSE;
	char respuesta[3];
	char letra;
	int largo;
	int i;


	printf("Desea agregar el color %s  al listado permanente(si/no)\n",nuevoColor);
	fflush(stdin);
	scanf("%[^\n]",respuesta);
	while(validarPalabra(respuesta)==FALSE)
	{
		printf("Error, desea agregar %s a la lista de colores (si/no)\n",nuevoColor);
		fflush(stdin);
		scanf("%[^\n]",respuesta);
	}
	for(i=0;i<3;i++)
	{
		letra=tolower(respuesta[i]);
		respuesta[i]=letra;
	}

	if(strcmp(respuesta,"si")==0)
	{
		largo=strlen(nuevoColor);
		for(i=0;i<largo;i++)
		{
			if(i==0)
			{
				letra=toupper(nuevoColor[i]);
				nuevoColor[i]=letra;
			}
			else
			{
				letra=tolower(nuevoColor[i]);
				nuevoColor[i]=letra;
			}
		}
		for(i=0;i<t;i++)
		{
			if(listadoColores[i].id==FALSE)
			{
				strcpy(listadoColores[i].nombreColor,nuevoColor);
				listadoColores[i].id=10000+i;
				break;
			}
		}
		validacion=TRUE;
	}

	return validacion;
}

int agregarTipo(eTipo listadoTipo[], char nuevoTipo[],int t)
{
	int validacion=FALSE;
	char respuesta[3];
	char letra;
	int largo;
	int i;

	printf("Desea agregar el tipo %s  al listado permanente(si/no)\n",nuevoTipo);
	fflush(stdin);
	scanf("%[^\n]",respuesta);
	while(validarPalabra(respuesta)==FALSE)
	{
		printf("Error, desea agregar %s a la lista de tipo(si/no)\n",nuevoTipo);
		fflush(stdin);
		scanf("%[^\n]",respuesta);
	}
	for(i=0;i<3;i++)
	{
		letra=tolower(respuesta[i]);
		respuesta[i]=letra;
	}

	if(strcmp(respuesta,"si")==0)
	{
		largo=strlen(nuevoTipo);
		for(i=0;i<largo;i++)
		{
			if(i==0)
			{
				letra=toupper(nuevoTipo[i]);
				nuevoTipo[i]=letra;
			}
			else
			{
				letra=tolower(nuevoTipo[i]);
				nuevoTipo[i]=letra;
			}
		}
		for(i=0;i<t;i++)
		{
			if(listadoTipo[i].id==FALSE)
			{
				strcpy(listadoTipo[i].descripcion,nuevoTipo);
				listadoTipo[i].id=1000+i;
				break;
			}
		}
		validacion=TRUE;
	}

	return validacion;
	}

int generarID(eMoto listado[],int tam)
{
	int i;
	int validacion=FALSE;


	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(listado[i].id==FALSE)
			{
				validacion=i+1000;
				break;
			}
		}
	}
	return validacion;
}

int modificarMoto(eMoto listadoMotos[], eColor listadoColores[],int tamanio, int t)
{
	int validacion=FALSE;
	char cDireccionID;
	int direccionID;
	char respuesta[3];
	char letra;
	int i;

	printf("Ingrese el ID de la moto\n");
	fflush(stdin);
	scanf("%[^\n]",cDireccionID);
	direccionID=atoi(cDireccionID);
	while(validarNumeroEntero(cDireccionID)==FALSE);
	{
		printf("Error, Ingrese el ID\n");
		fflush(stdin);
		scanf("%[^\n]",cDireccionID);
		direccionID=atoi(cDireccionID);
	}
	if(buscarPorID(listadoMotos,tamanio,direccionID)==TRUE)
	{
		mostrarUnaMoto(listadoMotos,listadoColores,tamanio,t,direccionID);
		printf("Esta es la moto que desea modificar?(si/no): \n");
		fflush(stdin);
		scanf("%[^\n]",respuesta);
		for(i=0;i<3;i++)
		{
			 	letra=tolower(respuesta[i]);
			 	respuesta[i]=letra;
		}
		while(validarPalabra(respuesta)==FALSE)
		{
		 	printf("Esta es la moto que desea modificar?(si/no)");
		 	fflush(stdin);
		 	scanf("%[^\n]",respuesta);
		 }

		 if(strcmp(respuesta,"si")==0)
		 {

	      }
		 else
		 {
			 }
		 }


	return validacion;
}

int buscarPorID(eMoto listado[],int tamanio,int direccion)
{
	int validacion=FALSE;
	int i;

	if(tamanio>0 && direccion>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(listado[i].id==direccion)
			{
				validacion=TRUE;
				break;
			}
		}
	}

	return validacion;
}
void mostrarUnaMoto(eMoto listado[],eColor listaColor[],int tamanio,int t,int direccion)
{
	int i;
	int j;

	if(tamanio>0 && direccion>0)
	{

		for(i=0;i<tamanio;i++)
		{
			if(direccion==listado[i].id)
			{
				for(j=0;j<t;j++)
				{
					if(listado[i].idColor==listaColor[j].id)
					{
						printf("Color: %s\t",listaColor[j].nombreColor);
						break;
					}
				}
				printf("ID: %d \t Marca: %s \t ID tipo: %d \t ID color %d \t Cilindrada %d \t Puntaje %d\n",listado[i].id,
						                                                                                    listado[i].marca,
						                                                                                    listado[i].idTipo,
																											listado[i].idColor,
																											listado[i].cilindrada,
																											listado[i].puntaje);

				break;
			}
		}
	}

}

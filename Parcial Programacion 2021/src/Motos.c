#include "Motos.h"
#include "UTN.h"
#include "Fecha.h"

int inicializarTrabajos(eTrabajo listadoTrabajos[],int tam)
{
	int validacion=FALSE;
	int i;

	if(tam>0)
	{
		for(i=0;i<tam;i++)
		{
		listadoTrabajos[i].id=FALSE;
		}
		validacion=TRUE;
	}

	return validacion;
}
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
	int auxID[4]={2000,2001,2002,2003};
	float auxPrecio[4]={450,300,150,390};
	char auxServicio[4][V]={"Limpieza","Ajuste","Balanceo","Cadena"};

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
	int valor;
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


	if((valor=listarTipos(tipos,t))==TRUE)
	{
	printf("Elija un tipo o ingrese uno nuevo\n");
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
		else
		{
			idT=validarTipo(tipos,tipo,t);
		}
	}

	}

	if((valor=listarColor(color,t))==TRUE)
	{
	printf("Elija un color o ingrese uno nuevo\n");
	fflush(stdin);
	scanf("%[^\n]",colores);

	while(validarPalabra(colores)==FALSE)
	{
		printf("Error, Ingrese el color\n");
		fflush(stdin);
		scanf("%[^\n]",colores);
	}

	idC=validarColores(color,colores,t);
	if(idC==FALSE)
	{
		if(agregarColor(color,colores,t)==FALSE)
		{
			return validacion;
		}
		else
		{
			idC=validarColores(color,colores,t);
		}
	}
	}

	printf("Ingrese la cilindrada de la moto(50 - 125 - 500 - 600 - 750)\n");
	fflush(stdin);
	scanf("%[^\n]",cCilindros);
	cilindros=atoi(cCilindros);
	while((validarNumeroEntero(cCilindros)==FALSE) || (validarCilindrada(cilindros)==FALSE))
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

	while(validarNumeroEntero(cPuntaje)==FALSE || (puntaje<1 || puntaje>10))
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
			mostrarUnaMoto(moto,color,tipos,tamanio,t,id);
			break;
		}
	}

	return validacion;
}
int agregarColor(eColor listadoColores[],char nuevoColor[],int t)
{
	int validacion;
	int id;
	int i;
	int largo;
	char letra;

	printf("Se puede agregar el color %s al listado, ",nuevoColor);

	if(DarRespuesta()==TRUE)
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
				id=1+listadoColores[i-1].id;
				strcpy(listadoColores[i].nombreColor,nuevoColor);
				listadoColores[i].id=id;
				break;
			}
		}
		validacion=TRUE;
	}
	else
	{
		printf("No se agrego el color\nVolviendo al menu principal\n");
		validacion=FALSE;
	}


	return validacion;
}
int agregarServicio(eServicio listadoServicio[],char nuevoServicio[],int t)
{
	int validacion;
	int id;
	int i;
	int largo;
	float precio;
	char letra;
	char cPrecio[V];

	printf("Se puede agregar el servicio %s al listado, ",nuevoServicio);

	if(DarRespuesta()==TRUE)
	{
		printf("Ingrese el costo del servicio:\n");
		fflush(stdin);
		scanf("%[^\n]",cPrecio);
		precio=atof(cPrecio);
		while((validarNumeroFlotante(cPrecio)==FALSE) || precio<1)
		{
			printf("Error, ingrese el costo del servicio:\n");
			fflush(stdin);
			scanf("%[^\n]",cPrecio);
			precio=atof(cPrecio);
		}

		largo=strlen(nuevoServicio);
		for(i=0;i<largo;i++)
		{
			if(i==0)
			{
				letra=toupper(nuevoServicio[i]);
				nuevoServicio[i]=letra;
			}
			else
			{
					letra=tolower(nuevoServicio[i]);
					nuevoServicio[i]=letra;
			}
		}
		for(i=0;i<t;i++)
		{
			if(listadoServicio[i].id==FALSE)
			{
				id=1+listadoServicio[i-1].id;
				strcpy(listadoServicio[i].descripcion,nuevoServicio);
				listadoServicio[i].id=id;
				listadoServicio[i].precio=precio;
				break;
			}
		}
		validacion=TRUE;
	}
	else
	{
		printf("No se agrego el servicio\nVolviendo al menu principal\n");
		validacion=FALSE;
	}


	return validacion;
}

int agregarTipo(eTipo listadoTipo[], char nuevoTipo[],int t)
{
	int validacion;
	int id;
	int i;
	int largo;
	char letra;

	printf("Se puede agregar el tipo %s  al listado, ",nuevoTipo);

	if(DarRespuesta()==TRUE)
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
				id=1+listadoTipo[i-1].id;
				strcpy(listadoTipo[i].descripcion,nuevoTipo);
				listadoTipo[i].id=id;
				break;
			}
		}
		validacion=TRUE;
	}
	else
	{
		printf("No se agrego el tipo\nVolviendo al menu principal\n");
		validacion=FALSE;
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
				validacion=1000+i;
				break;
			}
		}
	}
	return validacion;
}

int modificarMoto(eMoto listadoMotos[], eColor listadoColores[],eTipo listadoTipos[],int tamanio, int t)
{
	int validacion=FALSE;
	int direccionID;
	int valor;
	int i;
	int contador=-1;
	int verificar;
	int opciones;
	int puntaje;
	int idC;
	char cOpciones[2];
	char cDireccionID[6];
	char colores[V];
	char cPuntaje[3];


	printf("Ingrese el ID de la moto\n");
	fflush(stdin);
	scanf("%[^\n]",cDireccionID);
	direccionID=atoi(cDireccionID);
	while(validarNumeroEntero(cDireccionID)==FALSE)
	{
		printf("Error, Ingrese el ID\n");
		fflush(stdin);
		scanf("%[^\n]",cDireccionID);
		direccionID=atoi(cDireccionID);
	}
	if(buscarPorID(listadoMotos,tamanio,direccionID)==TRUE)
	{
		printf("LA moto es encontrada es:\n");
		mostrarUnaMoto(listadoMotos,listadoColores,listadoTipos,tamanio,t,direccionID);
		if((valor=DarRespuesta())==TRUE)
		{

		    do{
			printf("Elija la categoria que desea modificar\n");
			printf("1- Color\n");
			printf("2- Puntaje\n");
			printf("3- Finalizar y volver al menu principial\n");
			fflush(stdin);
			scanf("%[^\n]",cOpciones);
			opciones=atoi(cOpciones);

			while((verificar=validarNumeroEntero(cOpciones))==FALSE || (opciones>3 || opciones<1))
			{
				printf("Error, Elija una opcion valida (1-3)\n");
				fflush(stdin);
				scanf("%[^\n]",cOpciones);
				opciones=atoi(cOpciones);
			}

			switch(opciones)
			{
			case 1:
				if((valor=listarColor(listadoColores,t))==TRUE)
				{
				printf("Elija un color o ingrese uno nuevo\n");
				fflush(stdin);
				scanf("%[^\n]",colores);

				while(validarPalabra(colores)==FALSE)
				{
					printf("Error, Ingrese el color\n");
					fflush(stdin);
					scanf("%[^\n]",colores);
				}

				idC=validarColores(listadoColores,colores,t);
				if(idC==FALSE)
				{
					if(agregarColor(listadoColores,colores,t)==FALSE)
					{
						return validacion;
					}
					else
					{
						idC=validarColores(listadoColores,colores,t);
					}
				}
				}
				contador++;
				break;
			case 2:
				    printf("Ingrese el puntaje (1-10)\n");
					fflush(stdin);
					scanf("%[^\n]",cPuntaje);
					puntaje=atoi(cPuntaje);

					while(validarNumeroEntero(cPuntaje)==FALSE || (puntaje<1 || puntaje>10))
					{
						printf("Error, Ingrese el puntaje (1-10)\n");
						fflush(stdin);
						scanf("%[^\n]",cPuntaje);
						puntaje=atoi(cPuntaje);
					}
					contador++;
				break;
			case 3:
				contador++;
				break;
			}
		    }while(opciones!=3);
		}
		else
		{
			contador++;
		}

	}

	if(contador>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(listadoMotos[i].id==direccionID)
			{
				listadoMotos[i].idColor=idC;
				listadoMotos[i].puntaje=puntaje;
				break;
			}
		}
		mostrarUnaMoto(listadoMotos,listadoColores,listadoTipos,tamanio,t,direccionID);
		validacion=TRUE;
		printf("Se modificaron los datos exitosamente\n");
	}
	else
	{
		if(contador==0)
		{
			printf("No se ha modificado ningun dato\n");
			validacion=TRUE;
		}
	}

	return validacion;
}
int BajaMoto(eMoto listadoMotos[], eColor listadoColores[],eTipo listadoTipos[],int tamanio, int t)
{
	int validacion=FALSE;;
	int direccionID;
	int valor;
	char cDireccionID[6];
	int i;

	printf("Ingrese el ID de la moto\n");
	fflush(stdin);
	scanf("%[^\n]",cDireccionID);
	direccionID=atoi(cDireccionID);
	while(validarNumeroEntero(cDireccionID)==FALSE)
	{
		printf("Error, Ingrese el ID\n");
		fflush(stdin);
		scanf("%[^\n]",cDireccionID);
		direccionID=atoi(cDireccionID);
	}
	if(buscarPorID(listadoMotos,tamanio,direccionID)==TRUE)
	{
		validacion=TRUE;
		printf("La siguiente moto se dara de baja:\n");
		mostrarUnaMoto(listadoMotos,listadoColores,listadoTipos,tamanio,t,direccionID);
		if((valor=DarRespuesta())==TRUE)
		{
			for(i=0;i<tamanio;i++)
			{
			   if(listadoMotos[i].id==direccionID)
			   {
				   listadoMotos[i].id=FALSE;
				   break;
			   }
			}

			printf("Se dio de baja correctamente\n");
		}
		else
		{
			printf("No se dio de baja\n");
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
void mostrarUnaMoto(eMoto listado[],eColor listaColor[],eTipo listadoTipo[],int tamanio,int t,int direccion)
{
	int i;
	int j;
	char colorMoto[V];
	char tipoMoto[V];

	if(tamanio>0 && direccion>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(direccion==listado[i].id)
			{
				for(j=0;j<t;j++)
				{
					if(listado[i].idTipo==listadoTipo[j].id)
					{
						strcpy(tipoMoto,listadoTipo[j].descripcion);
						break;
					}
				}

				for(j=0;i<t;j++)
				{
					if(listado[i].idColor==listaColor[j].id)
					{
						strcpy(colorMoto,listaColor[j].nombreColor);
						break;
					}
				}
				printf("ID: %d \t Marca: %s \t Tipo: %s \t ID tipo: %d \t Color: %s\t ID color: %d \t Cilindrada %d \t Puntaje %d\n", listado[i].id,
										                                                                                              listado[i].marca,
																																	  tipoMoto,
										                                                                                              listado[i].idTipo,
																																	  colorMoto,
																										                              listado[i].idColor,
																										                              listado[i].cilindrada,
																										                              listado[i].puntaje);
				break;
			}
		}
	}

}


int listarTipos(eTipo tipos[], int t)
{
	int validacion=FALSE;
	int i;

	if(t>0)
	{
		validacion=TRUE;
		for(i=0;i<t;i++)
		{
			if(tipos[i].id!=FALSE)
			{
				printf("Tipo: %s \t ID: %d\n",tipos[i].descripcion,tipos[i].id);
			}
		}
	}

	return validacion;
}

int listarColor(eColor colores[], int t)
{
	int validacion=FALSE;
	int i;

	if(t>0)
	{
		validacion=TRUE;

		for(i=0;i<t;i++)
		{
			if(colores[i].id!=FALSE)
			{
				printf("Color: %s \t ID: %d\n",colores[i].nombreColor,colores[i].id);
			}
		}

	}

	return validacion;
}

int listarServicios(eServicio servicios[], int t)
{
	int validacion=TRUE;
	int i;

	if(t>0)
	{
		validacion=TRUE;
		for(i=0;i<t;i++)
		{
			if(servicios[i].id!=FALSE)
			{
				printf("Servicio: %s\tPrecio %.2f\tID: %d\n",servicios[i].descripcion,servicios[i].precio,servicios[i].id);
			}
		}
	}

	return validacion;
}
int iniciarTrabajo(eServicio Servicios[],int t)
{
	int idS;
	int validacion=FALSE;
	char nuevoServicios[V];

	if(listarServicios(Servicios,t)==TRUE)
	{
		printf("Seleccione o ingrese un nuevo servicio\n");
		fflush(stdin);
		scanf("%[^\n]",nuevoServicios);

		while(validarPalabra(nuevoServicios)==FALSE)
		{
			printf("Error, Ingrese el servicio\n");
			fflush(stdin);
			scanf("%[^\n]",nuevoServicios);
		}

		idS=validarServicios(Servicios,nuevoServicios,t);
		if(idS==FALSE)
		{
			if(agregarServicio(Servicios,nuevoServicios,t)==FALSE)
			{
				return validacion;
			}
			else
			{
				idS=validarServicios(Servicios,nuevoServicios,t);
				validacion=idS;
			}

		}
		else
		{
			validacion=idS;
		}

	}

	return validacion;
}
int cargarTrabajo(eMoto listadoMotos[],eTrabajo ListadoTrabajos[],eServicio listaServicios[],eColor listadoColores[],eTipo listadoTipos[],eFecha fecha[],int tamanio,int t)
{
	eFecha unaFecha;
	int validacion=FALSE;
	int direccionID;
	int valor;
	int IDservicio;
	int i;
	int carga=10000;
	char cDireccionID[6];

	printf("Ingrese el ID de la moto que desea a�adir un trabajo\n");
	fflush(stdin);
	scanf("%[^\n]",cDireccionID);
	direccionID=atoi(cDireccionID);
	while(validarNumeroEntero(cDireccionID)==FALSE)
	{
		printf("Error, Ingrese el ID\n");
		fflush(stdin);
		scanf("%[^\n]",cDireccionID);
		direccionID=atoi(cDireccionID);
	}
	if(buscarPorID(listadoMotos,tamanio,direccionID)==TRUE)
	{
				mostrarUnaMoto(listadoMotos,listadoColores,listadoTipos,tamanio,t,direccionID);
				if((valor=DarRespuesta())==TRUE)
				{
					unaFecha=cargarFechas();
					IDservicio=iniciarTrabajo(listaServicios,t);
					if(IDservicio!=FALSE)
					{
						for(i=0;i<tamanio;i++)
						{
							if(ListadoTrabajos[i].id==FALSE)
							{
								ListadoTrabajos[i].id=carga+i;
							    ListadoTrabajos[i].idMoto=direccionID;
							    ListadoTrabajos[i].idServicio=IDservicio;
							    ListadoTrabajos[i].fecha=unaFecha;
							    validacion=TRUE;
							    break;
							}
						}
						printf("Se a�adio con exito el trabajo\n");
						validacion=TRUE;

					}
					else
					{
						validacion=TRUE;
						return validacion;
					}

				}
				else
				{
					validacion=TRUE;
					printf("No se a�adio ningun trabajo\n");
					return validacion;
				}
	}


	return validacion;
}
int mostrarMotoTipoID(eMoto listaMotos[],eTipo listaTipos[],int tamanio,int t)
{
	int validacion=FALSE;
	int i;
	int j;

	if(tamanio>0 && t>0)
	{
		validacion=TRUE;
		for(i=0;i<tamanio;i++)
		{
			for(j=0;j<t;j++)
			{
				if(listaMotos[i].id!=FALSE && listaTipos[j].id==listaMotos[i].idTipo)
				{
					printf("ID: %d\tMarca: %s\tTipo: %s\tID tipo: %d\tID color: %d\tCilindrada: %d\tPuntaje: %d\n",listaMotos[i].id,
						                                                                                           listaMotos[i].marca,
							                                                                                       listaTipos[j].descripcion,
																												   listaTipos[j].id,
																												   listaMotos[i].idColor,
																												   listaMotos[i].cilindrada,
																												   listaMotos[i].puntaje);
				}
			}
		}
	}

	return validacion;
}
int ListarMotoTipoID(eMoto listadoMotos[],eTipo listadoTipos[],int tamanio,int t)
{
	eMoto auxiliar;
	int validacion=FALSE;
	int i;
	int j;
	int opcion;
	char cOpcion[5];

	if(tamanio>0 && t>0)
	{
		validacion=TRUE;
		do{
		printf("Elija la opcion:\n");
		printf("1 Listar por Tipo\n");
		printf("2 Listar por ID\n");
		printf("3 Volver al menu anterior\n");
		fflush(stdin);
		scanf("%[^\n]",cOpcion);
		opcion=atoi(cOpcion);
		while(validarNumeroEntero(cOpcion)==FALSE || (opcion<1 || opcion>3))
		{
			printf("Error, Ingrese una opcion (1-2)\n");
			fflush(stdin);
			scanf("%[^\n]",cOpcion);
			opcion=atoi(cOpcion);
		}

		switch(opcion)
		{
		case 1:
			for(i=0;i<tamanio-1;i++)
			{
				for(j=i+1;j<tamanio;j++)
				{
					if(listadoMotos[i].idTipo>listadoMotos[j].idTipo)
					{
					  auxiliar=listadoMotos[i];
					  listadoMotos[i]=listadoMotos[j];
					  listadoMotos[j]=auxiliar;
					}
				}
			}
			if(mostrarMotoTipoID(listadoMotos,listadoTipos,tamanio,t)==FALSE)
			{
				printf("Ocurrio un error\n");
				return validacion;
			}
			break;
		case 2:
			for(i=0;i<tamanio-1;i++)
		    {
				for(j=i+1;j<tamanio;j++)
				{
					if(listadoMotos[i].id>listadoMotos[j].id)
					{
						auxiliar=listadoMotos[i];
			 		    listadoMotos[i]=listadoMotos[j];
					    listadoMotos[j]=auxiliar;
					}
				}
		    }
			if(mostrarMotoTipoID(listadoMotos,listadoTipos,tamanio,t)==FALSE)
			{
				printf("Ocurrio un error\n");
				return validacion;
			}
			break;
		case 3:
			for(i=0;i<tamanio-1;i++)
			{
				for(j=i+1;j<tamanio;j++)
				{
					if(listadoMotos[i].id<listadoMotos[j].id)
					{
						auxiliar=listadoMotos[i];
						listadoMotos[i]=listadoMotos[j];
						listadoMotos[j]=auxiliar;
					}
				}
			}
		break;
		}

		}while(opcion!=3);

	}

	return validacion;
}

void mostrarMotoID(eMoto lista[],int tamanio)
{
	int i;
	if(tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(lista[i].id!=FALSE)
			{
			    printf("ID: %d\tMarca: %s\tID tipo: %d\tID color: %d\tCilindrada: %d\tPuntaje: %d\n",lista[i].id,
			    		                                                                             lista[i].marca,
																									 lista[i].idTipo,
																									 lista[i].idColor,
																									 lista[i].cilindrada,
																									 lista[i].puntaje);
			}
		}
	}
	}
int listarTrabajos(eMoto listaMoto[],eTrabajo listaTrabajos[],eServicio listaServicios[],int tamanio,int t)
{
	int validacion=FALSE;
	int i;
	int j;
	int k;
	int contador=0;
	float precio;
	char descripcion[V];


	if(tamanio>0 && t>0)
	{
		validacion=TRUE;
		for(i=0;i<tamanio;i++)
		{
			for(j=0;j<tamanio;j++)
			{
				if(listaMoto[i].id!=FALSE && listaMoto[i].id==listaTrabajos[j].idMoto && listaTrabajos[j].id!=FALSE)
				{
					for(k=0;k<t;k++)
					{
						if(listaTrabajos[j].idServicio==listaServicios[k].id && listaServicios[k].id!=FALSE)
						{
							strcpy(descripcion,listaServicios[k].descripcion);
							precio=listaServicios[k].precio;
							break;
						}
					}
					printf("ID Moto: %d \t Marca: %s \t ID Trabajo: %d \t Servicio: %s \t Precio: %.2f \t Fecha: %d/%d/%d\n",listaMoto[i].id,
							                                                                                    listaMoto[i].marca,
																												listaTrabajos[j].id,
																												descripcion,
																												precio,
																												listaTrabajos[j].fecha.dia,
																												listaTrabajos[j].fecha.mes,
																												listaTrabajos[j].fecha.anio);
					contador++;
				}
			}
		}
	}

	if(contador==0)
	{
		printf("No hay trabajos cargados\n");
	}

	return validacion;
}

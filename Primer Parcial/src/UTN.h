#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Motos.h"
#define TAM 1000
#define V 20
#define T 30
#define TRUE 0
#define FALSE -1

int validarNumeroEntero(char[]);
int validarNumeroFlotante(char[]);
int validarPalabra(char[]);
int validarCilindrada(int);
int validarColores(eColor[],char[],int);
int validarTipo(eTipo[],char[],int);
#endif /* UTN_H_ */

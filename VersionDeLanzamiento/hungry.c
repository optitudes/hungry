/* 
 * Programa   : hungry.c
 * Descripción: implementacion de las funciones para la libreria de hungry.h
 * Autor      : Ivan Cardona, Juan Rojas, Laura Maldonado
 * Fecha      : Noviembre 2020
 * Licencia   : GNU GPL v3
 */
 
#include <stdio.h>
#include <string.h>
//ctype solo se necesita en funciones por ende no se llama en el main ni hungry.h
#include <ctype.h>
#include <stdlib.h>
#include "hungry.h"
#include "uniquindio.h"
#include "historia.h"



//procedimiento que funciona como el main de la historia, ya que la historia está anidada en el
//Parametros: las estadisticas del jugador y las tildes 
void desarrollarJuego()
{
	Datos jugador;
	int eleccion;
	int terminarJ=0;
	//lectura de los datos del jugador
	leerEstadisticas(&jugador);
	//para manejar las decisiones en el codigo utilizamos:
	//1=good, siendo estas las decisiones buenas o que tiendan a buenas
	//2=bad, siendo 1 lo contrario de 0
	//se muestra el prologo de la historia
	prologo(jugador);
	n2(jugador);
	//narra la historia de la mujer
	if (jugador.sexo=='m')
	{
		eleccion=n5(&jugador);
		if(eleccion==1) {n9(jugador);} else {n10(jugador);}
		n18(jugador);
		historiaMixta(jugador);
	}
	//narra la historia del hombre
	else
	{
		//funcion que muestra como el jugador sale de la casa
		eleccion=n4(&jugador);
		//decicion que separa la historia si el hombre eligio salvar o no al perro
		//elecion 1= salvar al perro
		if(eleccion==1) {n6(jugador);} else{n7(jugador);}
		eleccion=n8(&jugador);
 		if (eleccion==1) {n11(jugador);} else{n12(jugador);}
		terminarJ=imprimirMuerte(jugador);
		if(terminarJ==1){goto final1;}

		eleccion=n13(jugador);
		if (eleccion==1) {n14(jugador);} else{n15(jugador);}
		n19(jugador);
		historiaMixta(jugador);	
    }
    final1: printf("\n");
}
void historiaMixta(Datos jugador)
{
	int eleccion,terminarJ;

	eleccion=n17(jugador);
		if (eleccion==1)
		{
			eleccion=n20(&jugador);
			if(eleccion==1)
			{
				n21(jugador);

				terminarJ=imprimirMuerte(jugador);
				if(terminarJ==1){goto final2;}

				eleccion=n23(&jugador);
				if (eleccion==1){n27(jugador);}else{n28(jugador);}

				terminarJ=imprimirMuerte(jugador);
				if(terminarJ==1){goto final2;}
				
				historiaFinal(jugador);

			}
			else
			{
				n22(jugador);
				eleccion=n24(&jugador);
				if (eleccion==1){n25(jugador);}else{n26(jugador);}

				terminarJ=imprimirMuerte(jugador);
				if(terminarJ==1){goto final2;}

				n29(jugador);
				historiaFinal(jugador);
			}
		}
		else
		{
			eleccion=n23(&jugador);
			if (eleccion==1){n27(jugador);}else{n28(jugador);}

			terminarJ=imprimirMuerte(jugador);
			if(terminarJ==1){goto final2;}

			historiaFinal(jugador);
		}
	final2: printf("\n");	
}
void historiaFinal(Datos jugador)
{
	int eleccion;
	eleccion=n30(jugador);
	if(eleccion==1)
	{
		n31(jugador);
		eleccion=n33(jugador);
		if (eleccion=1)
		{
			n34(jugador);
			if (jugador.accionesB>jugador.accionesM) {n36(jugador);} else {n37(jugador);}
		}
		else
		{
			n35(jugador);
			if (jugador.accionesB>jugador.accionesM) {n38(jugador);} else {n39(jugador);}
		}

	}
	else
	{
		n32(jugador);
		n35(jugador);
		if (jugador.accionesB>jugador.accionesM) {n38(jugador);} else {n39(jugador);}
	}
}
//----------------------------sistema------------------------------------------

//procedimiento que asigna los valores iniciales a las estadisticas del jugador
//tambien solicita el sexo y el nombre al jugador
//Parametros: el paso por referencia de la variable jugador, variable de tipo
//		      Datos
void leerEstadisticas(Datos *jugador)
{
	//solicitud del nombre y sexo
	leerCadena("Ingrese el nombre del jugador  :",jugador->nombre,MAX_CADENA);
	//ciclo que verifica que la cadena no sea nula
	while(strcmp(jugador->nombre,"")==0)
	{
		printf("error, nombre invalido, intente de nuevo\n");
		leerCadena("Ingrese el nombre del jugador: ",jugador->nombre,MAX_CADENA);
	}	
	jugador->sexo=leerCaracter("Ingrese su sexo  (H/M): ");
	jugador->sexo=tolower(jugador->sexo);
	while(jugador->sexo!='m'&& jugador->sexo!='h')
	{
		printf("error, caracter no valido, intente nuevamente\n");
		jugador->sexo=leerCaracter("Ingrese su sexo (H/M)\n:");
		jugador->sexo=tolower(jugador->sexo);	
	}
	//asignamos las estadisticas generales del jugador
	jugador->estadoA  =3;
	jugador->accionesB=0;
	jugador->accionesM=0;
	jugador->salud    =100;
}
//funcion que imprime las estadisticas del jugador
void imprimirEstadisticas(Datos jugador)
{
	printf("--------------------------\n");
	if (jugador.estadoA>3)
	{
		printf("((^w^ ))");		
	}
	else
	{
		if (jugador.estadoA==3) {printf("(O_O )");} else {printf("(T_T )");}			
	}
	printf("  salud=%.1f\n",jugador.salud);
	printf("--------------------------\n");
}
//funcion que valida la eleccioin entre 1 y 2
int validarEleccion()
{
	char caracterEleccion[1];
	int  eleccion;

	caracterEleccion[0]=leerCaracter("\n:");
	while(caracterEleccion[0] != '1' && caracterEleccion[0] != '2')
	{
		printf("error, elija entre 1 y 2.");
		
		caracterEleccion[0]=leerCaracter("\n:");
	}
	

        eleccion=atoi(caracterEleccion);
	return eleccion;
}
//procedimiento que imprime la muerte del jugador durante el desarrollo del juego
int imprimirMuerte(Datos jugador)
{

	if(jugador.salud<=0)
	{
		printf("%s se pone palido por las heridas que tiene, se sienta y al cabo de dos minutos\n",jugador.nombre);
		printf("su corazón deja de latir");
		return 1; 
	}
	else
	{
		if (jugador.estadoA<=0)
		{
			printf("%s no puede más mentalmente, se siente insuficiente y que no merece la vida\n",jugador.nombre);
			printf("sí que toma la desición de dejar de luchar, se sienta y espera a que algún infectado lo \n  ");
			printf("encuentre y lo libere de su miserable vida...");
			return 1;
		}else
                {
                    return 0;
                }
	}

}
//procedimientos  que afectan las estadisticas del jugador dependiendo de su eleccion
void afectarAnimo (Datos *jugador,int eleccion) {if (eleccion==1) {jugador->estadoA++;  } else{jugador->estadoA--;}}
void accionesBM   (Datos *jugador,int eleccion) {if (eleccion==1) {jugador->accionesB++;} else{jugador->accionesM++;}}
void accionesSalud(Datos *jugador,int eleccion) {if (eleccion==1) {jugador->salud-=34;  }}

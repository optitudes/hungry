/*
	Programa: main(mientras le ponemos un nombre al juego).c
	Descripción: es un video juego que permite al jugador ponerse en los zapatos
		         de un sobreviviente a un contagio masivo de una espora dañina
	Autores:Ivan Cardona, Juan Rojas, Laura Maldonado
	Fecha: noviembre 2020

*/
/*                    Analisis
	Resultado esperado: un juego de roll en modo texto, el cual esté construido con todo lo que aprendimos
					    durante el curso, incluyendo punteros
	Datos disponibles: -nombre del jugador y su sexo.
	Proceso: Usando typedef creamos el tipo de dato "jugador" e inicializamos una variable llamada jugador de ese tipo,
			 luego usando una función le solicitaremos el nombre al usuario y su sexo, validamos los dos
			 datos  y con una decision compuesta asignaremos a la variable  jugador los atributos faltantes.
			 Una vez terminada esta función comenzará el juego con una introducción.

 	Variables: Datos jugador 	c*/
//llamado a las bibliotecas necesarias
#include<stdio.h>
//locate.h para usar tildes y ñ
#include"hungry.h"
#include"uniquindio.h"
#include"historia.h"
//librerías necesarias para el juego con caracteres
//wchar  incluye un soporte para un amplio tipo de caracteres
#include <wchar.h>
//locale incluye un soporte para un amplio tipo de formatos
#include <locale.h>
//funcion principal
int main()
{
	int continuar=0;
	setlocale(LC_ALL, "");
	//ciclo para que el jugador se pueda echar varias partidas sin
	//tener que reiniciar el programa
	do
	{
		//inicia la historia
		desarrollarJuego();
		continuar=leerEntero("Desea jugar de nuevo?\n1: si\n2: no \n: ");
	}while(continuar==1);
	return 0;
}

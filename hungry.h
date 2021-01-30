/* 
 * Programa   : Libreria "juego"
 * Descripción: Prototipos de la biblioteca juego.h
 * Autor      : Ivan Cardona, Juan Rojas, Laura Maldonado
 * Fecha      : noviembre 2020
 */

 // Prototipos de las funciones / procedimientos

#ifndef HUNGRY
  #define HUNGRY
//define el tamaño maximo del nombre
#define MAX_CADENA 30
//estructura necesaria para almacenar los datos del jugador
typedef struct 
{
	char sexo,nombre [MAX_CADENA];
	//estadoA es el estado de animo,accionesB/M son dos contadores de
	//las acciones buenas y malas que toma el jugador
	int estadoA,accionesB,accionesM;
	//arma: 0=palo, 1=bate,2=llave inglesa,3=cuchillo
	float salud;
}Datos;
//funcion que valida la eleccion del usuario entre 1 y 2
int validarEleccion      ();
//proceso que define las  estadisticas del jugador
void leerEstadisticas    (Datos *jugador);
//función que imprime las estadisticas del jugador
void imprimirEstadisticas(Datos jugador);
//procesos que contiene la estructura de la historia
void desarrollarJuego    ();
//contiene la parte de la historia en la que se unen las tramas
void historiaMixta       (Datos jugador);
//contiene la parte final de la historia
void historiaFinal       (Datos jugador);
//procedimiento que imprime la muerte del jugador en cualquier parte del juego
int imprimirMuerte      (Datos jugador);
//procedimientos que afectan las estadisticas del usuario según su eleccion
void afectarAnimo        (Datos *jugador,int eleccion);
void accionesBM          (Datos *jugador,int eleccion);
void accionesSalud       (Datos *jugador,int eleccion);
#endif


/* 
 * Programa   : hungry.c
 * Descripci�n: implementacion de las funciones para la libreria de hungry.h
 * Autor      : Ivan Cardona, Juan Rojas
 * Fecha      : Noviembre 2021
 */
//llamado a las bibliotecas necesarias

#include <stdio.h>
#include <string.h>
//ctype solo se necesita en funciones por ende no se llama en el main ni hungry.h
#include <ctype.h>
#include <stdlib.h>
#include "hungry.h"
#include "uniquindio.h"
//procedimiento que cuenta el inicio de la historia
//Parametros:Las estadisticas del jugador y las tildes
void prologo(Datos jugador)
{
	//char que servir� para regular la cantidad de texto en pantalla
	char continuar;
	printf("A�o 1930...\n");
	//secci�n que le pide al usuario que presione enter para continuar, luego limpia pantalla e imprime las estadisticas
	//en el prologo se omite la parte de imprimir estadisticas ya que no son necesarias

	continuar=leerCaracter("presione enter para continuar...");
	clrscr();
	//inicio  de narrativa
	printf("%s escucha en la radio una noticia acerca de un accidente que ocurri� cerca al yacimiento de agua\n",jugador.nombre);
	printf("que alimenta una peque�a presa la cual  provee de energia y agua potable el pueblo donde %s vive,\n",jugador.nombre);
	printf("el locutor narra que un avi�n se accident� cerca al yacimiento y que por dificultades geol�gicas y climatol�gicas ");
	printf("\nno se pudo hallar el avi�n %s no presta mucha atenci�n y se distrae poco desp�es con la m�sica \n",jugador.nombre);
	printf("de turno...\n");
	continuar=leerCaracter("presione enter para continuar...");
	clrscr();
}
//procedimiento que adentra al jugador en la trama
void n2(Datos jugador)
{

	char continuar;
	int  eleccion;

	printf("A�o 1931..\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s duerme placidamente en la sala de su hogar, hasta que unos gritos repentinos abruman los \n",     jugador.nombre);
	printf("alrededores de su morada se despierta y con los ojos pesados se asoma a la ventana para ver qu�\nes lo que tiene a");
	printf(" la gente gritando de manera tan escandalosa...\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s se queda en shock..\nnunca en su vida se habr�a imaginado algo as�..\ngente corriendo \n",        jugador.nombre);
	printf("ensangrientada, personas con las caras rojas de sangre y expresiones de locura...\nel suelo te�ido de rojo, y rest");
	printf("os de organos adornando la escena como si de un macabro fest�n se tratara.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s ten�a su cuerpo paralizado, su mente no pod�a procesar tal situaci�n, parec�a congelado en el   ",jugador.nombre);
	printf("tiempo.\nesto cambi� cuando un fuerte golpe azot� su puerta.\n%s desv�a su mirada hacia la puerta  ",jugador.nombre);
	printf("desde la ventana y ve que un grupo de almenos tres personas est�n tratando de entrar\nde esas personas se alcanza ");
	printf("a notar que tienen sangre en sus manos y sus ojos est�n brotados como nueces\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s observa a sus alrededores apresuradamente una forma de escapar motivado por el miedo\nnota un   ",jugador.nombre);
	printf("conducto de ventilaci�n que lleva al garaje\ntambi�n una ventana que lleva al patio.\n mientras %s ",jugador.nombre);
	printf("elige, el sonido de la madera de su puerta rompiendose desmorona la poca cordura que le queda.\n");
	printf("1: Ir por el conducto de ventilaci�n\n2: Romper la ventana e ir por el patio \n");
	eleccion=validarEleccion();

	//condici�n que l�mita la elecci�n dependiendo del sexo del jugador
	if (eleccion==1 && jugador.sexo=='h')
	{
		printf("su complexi�n no le permite entrar por el conducto de ventilac�n\nla puerta se rompe ferozmente como un trueno  ");
		printf("y %s no tiene m�s remedio que huir por la ventana\n",jugador.nombre);
	}
	else
	{
		if(eleccion==2&&jugador.sexo=='m')
		{
			printf("%s no tiene la fuerza suficiente para romper esa ventana\nla puerta se rompe ferozmente y ",jugador.nombre );
			printf("%s no tiene m�s remedio que huir por el conducto\n",jugador.nombre);
		}
	}
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}

//---------------------------------------------------------------MUJER--------------------------------------------------------//
//---------Funciones mujer----------------------------------//

int  n5 (Datos *jugador)
{
	char continuar;
	int  eleccion;

	printf("al salir a la calle logra ver a un extremo de la misma a un perro que se encuentra atrapado\nel cual va  ser    ");
	printf("atacado por un salvaje que se acerca corriendo agresivamente.\n\n%s observa bien y se da cuenta ",jugador->nombre);
	printf("que aquel salvaje que se acerca al perro es su hermano\n%s piensa si lo mejor es defender al  pe",jugador->nombre);
	printf("rro, arriesgandoze a dejar malherido a su hermano\no dejar que su hermano mate al perro con el fin de no lastima");
	printf("rlo y buscar una cura\n1: salvar al perrito\n2: ignorar la situaci�n\n");
	//se realiza la lectura y validaci�n de la decici�n
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(*jugador);
	//afectamos las estadisticas dependiendo de la eleccion
	accionesBM   (&*jugador,eleccion);
	accionesSalud(&*jugador,eleccion);
	afectarAnimo (&*jugador,eleccion);
	return eleccion;
}

//procedimiento que narra la entrada de la mujer al panel de ventilaci�n
//parametros=los datos del jugador
void n3 (Datos jugador)
{
	int eleccion;
	char continuar;

	printf("gracias a su complexi�n delgada logra colarse por el panel de ventilaci�n el cual la conduce al garaje, al entra");
	printf("r se topa\n con un bate de beisbol, lo toma y se sienta para descansar un poco\nmientras recupera el aliento un ");
	printf("grupo de salvajes comienza a golpear la debil puerta que conecta el garaje con el interior de la casa\n haciendo");
	printf(" que %s no tenga m�s remedio que salir corriendo a la calle por la puerta principal del garaje.",  jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}

//---------------Procedimientos mujer-------------------------------------------

//procedimiento que narrala la historia si la mujer decide ayudar al perro
void n9 (Datos jugador)
{
	char continuar;

	printf("%s corre hacia su hermano y lo embiste con su bate, el golpe lo manda volando hasta un anden cerc",jugador.nombre);
	printf("ano,\nal caer, el hermano de %s se golpea la cabeza y se queda quieto mientras de su cabeza se ge",jugador.nombre);
	printf("nera un lago\nde sangre.\n%s libera al perro y este sale coriendo despavorido, %s ",jugador.nombre,jugador.nombre);
	printf("observa todo a su alrededor y ve a las personas descontroladas\ny decide que lo mejor es ir a la comisar�a en bu");
	printf("sca de refugio y armas.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();

	printf("%s se conoce muy bien el pueblo as� que se mete por un pasadizo entre las malesas para llegar m�s",jugador.nombre);
	printf(" rapido a la comisar�a.");
}
//procedimiento que narra la historia si la mujer decide no ayudar al perro
void n10 (Datos jugador)
{
	char continuar;

	printf("%s recuerda los momentos de infancia con su hermano por lo que sin pensarlo evade la situaci�n y ",jugador.nombre);
	printf("decide ir a la comisar�a en busca de un resguardo temporal\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}

//procedimiento que detalla como el jugador llega a la comisaria mediante el atajo
void n16(Datos jugador)
{
	char continuar;

    printf("%s recuerda que de ni�a junto a sus amigas, iban la mayor parte del tiempo a un parque que qued", jugador.nombre );
    printf("a a tres cuadras\nde la comisar�a del pueblo, pero ellas no se iban por la carretera, ya que conoc�an un atajo e");
    printf("ntre el bosque que\nhab�a detr�s de su casa, sin pensarlo dos veces y m�s a�n viendo la cantidad de infectados q");
    printf("ue se encuentran en la\ncarretera, se dirige al bosque por donde consigue atravesar el atajo sin problemas y sal");
    printf("ir muy serca de la comisar�a\n");
    continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el encuentro de la mujer con el doctor en la comisar�a
void n18(Datos jugador)
{
	char continuar;

	printf("despues de llegar a la comisar�a logra ver a una persona que parece un doctor\ndesp�es de compartir ciertas  pal");
	printf("abras, %s se da cuenta que el doctor se llama johan\ny que es un doctor del hospital del pueblo\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("johan le comenta a %s que desde por la ma�ana la gente ha estado acudiendo al hospital por un bro",jugador.nombre);
	printf("te\nen la piel y mucha fiebre, narra tambi�n que desp�es de un tiempo todo se descontrol� y que los pacientes \n");
	printf("empezaron a atacarse unos a otros con armas de contundencia e incluso con los dientes. Cuenta adem�s\nque tuvo q");
	printf("ue salir del hospital a buscar ayuda en la comisar�a ya que no era seguro estar en el hospital");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
		
	printf("johan muestra a %s un documento secreto de polic�a, y le dice que hace masomenos un a�o un avi�n ",jugador.nombre);
	printf("\ntuvo un accidente en las monta�as, cerca al yacimiento de agua, que no se encontr� el avi�n pero se supo que p");
	printf("ertenec�a a \nuna farmaceutica muy poderosa. Luego saca otro docmento y le informa a %s que esa f",jugador.nombre);
	printf("armaceutica envi� un equipo de \ncientificos a inspeccionar las monta�as, curiosamente la fecha de esa expedici�");
	printf("n era la misma fecha actual.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("johan convence a %s de ir a las monta�as en busca de m�s informaci�n\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}


//-------------------------------------------------------HOMBRE----------------------------------------------
//funciones

//funcion que imprime la seccion 4 de la historia
//parametro= Datos del jugador 
int n4(Datos *jugador)
{
	int eleccion;
	char continuar;
	
	printf("gracias a su fuerza %s logra romper una  ventana que conduce al patio trasero de la casa\nse met",jugador->nombre);
	printf("e por la ventana rota y mientras corre a trav�s del patio se tropieza con un palo de madera\n%s ",jugador->nombre);
	printf("se levanta y ve que el palo tiene buena resistencia as� que lo toma.");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(*jugador);

	printf("%s corre y salta la cerca  que separa su patio de la calle...\n",jugador->nombre);
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(*jugador);
	
	printf("al salir a la calle logra ver a un extremo de la misma a un perro que se encuentra atrapado\nel cual va  ser ata");
	printf("cado por un salvaje que se acerca corriendo agresivamente.\n\n%s observa bien y se da cuenta que",jugador->nombre);
	printf(" aquel salvaje que se acerca al perro es su hermano\n%s piensa si lo mejor es defender al perro,",jugador->nombre);
	printf(" arriesgandoze a dejar malherido a su hermano\no dejar que su hermano mate al perro con el fin de no lastimarlo ");
	printf("y buscar una cura\n");
	printf("1: salvar al perrito\n2: ignorar la situaci�n\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(*jugador);

	//afectamos las estadisticas del jugador
	accionesBM   (&*jugador,eleccion);
	accionesSalud(&*jugador,eleccion);
	afectarAnimo (&*jugador,eleccion);
	return eleccion;
}
//funcion que narrra la la historia cuanddo el jugador debe elegir si ayudar o no a los supervivientes
int n8  (Datos *jugador)
{
	int eleccion;
	char continuar;
	
	printf("%s se detiene un momento para analizar el mejor camino, recuerda que cuando era ni�o sab�a de un",jugador->nombre);
	printf(" camino conduc�a\na un parque cerca a la comisar�a, luego mira hacia la carretera y ve a un grupo de personas si");
	printf("endo atacadas por un\ngrupo de salvajes, %s debe decidir si ayudarlos o huir:\n",jugador->nombre);
	printf("1: ayudar a las personas\n2: huir");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(*jugador);

	accionesBM   (&*jugador,eleccion);
	afectarAnimo (&*jugador,eleccion+1);
	return eleccion;
}
//funcion que informa lo que sucede cuando el jugador entra en la comisaria, aqui decide como sera la primera impresion con el doctor
int n13(Datos jugador)
{
	char continuar;
	int eleccion;
	
    printf("Despues de ver que la comisaria no esta como %s lo imaginaba, guarda algo de silencio, \nya que ",jugador.nombre );
    printf("le parece escuchar un ruido, dicho ruido no es producto de su imaginaci�n porque suena de nuevo.\n Una y otra v�");
    printf("z, cada vez m�s, %s se inquieta ya que en su mente tiene una serie\nde sentimientos que le quier",jugador.nombre );
    printf("en hacer explotar su cabeza, pues dicho ruido puede ser como su salvaci�n\nsu perdici�n. En este preciso momento");
    printf(" %s puede identificar de donde proviene el ruido, y es de la parte trasera de\nla puerta, que t", jugador.nombre );
    printf("iene justo en frente, solo le queda decidir si entrar atacando, o entrar sigilosamente\n");
    printf("1: Entrar atacando.\n2: Entrar sigilosamente.\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);

	return eleccion;
}

//---------------------------procedimientos

//procedimiento que muestra lo que ocurre si elige salvar al perro
void n6 (Datos jugador)
{
	char continuar;
	
	printf("%s corre hacia su hermano y lo embiste con una brutalidad que lo manda volando hasta un anden cer",jugador.nombre);
	printf("cano,\nal caer, el hermano de %s se golpea la cabeza y se queda quieto mientras de su cabeza se g",jugador.nombre);
	printf("enera un lago\nde sangre.\n%s libera al perro y este sale coriendo despavoridoy un rostro de terr",jugador.nombre);
	printf("or, %s observa todo a su alrededor y ve a las personas descontroladas\n",jugador.nombre);
	printf("y decide que lo mejor es ir a la comisar�a en busca de refugio y armas.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//narra la desici�n de no ayudar al perro
void n7 (Datos jugador)
{
	char continuar;
	
	printf("%s recuerda los momentos de infancia con su hermano por lo que sin pensarlo evade la situaci�n y ",jugador.nombre);
	printf("decide ir a la comisar�a en busca de un resguardo temporal\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);


}
//procedimiento que imprime la historia si el hombre decide ayudar a las personas en la calle
void n11(Datos jugador)
{
	char continuar;
	
	printf("%s  corre valeroso a ayudar pero cuando llega es sorprendido por una macabra escena, ninguna de l",jugador.nombre);
	printf("as personas se encuentran con vida\nel suelo se encuentra lleno de sangre y trozos de carne mutilada con pellejo");
	printf("s,el m�s depravado fest�n de carne  %s queda pasmado y ve como esos salvajes sueltan los trozos\n",jugador.nombre);
	printf("deshumanizados de esas personas para atraparlo a el. %s corre hacia la comisar�a, durante la carr",jugador.nombre);
	printf("era se resbala con la sangre\ngolpeandose la cabeza. Pero esto no lo detiene y consigue llegar a la comisar�a \n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//Narra la parte donde el jugador no ayuda ha las personas y se va para la comisar�a
void n12(Datos jugador)
{
	char continuar;
	
	printf("%s huye por el atajo que recordaba, durante el camino escucha los gritos desesperados  de las per",jugador.nombre);
	printf("sonas\nesos gritos empiezan a resonar en la cabeza de %s en son de culpa, hasta que llega a la co",jugador.nombre);
	printf("misar�a\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//narra lo que pasa si se decide entrar violentamente a la puerta de la comisar�a donde escucha el ruido
void n14(Datos jugador)
{
	char continuar;
	
	printf("%s entra de manera violenta, golpeando la puerta con una patada y arremetiendo con una persona\nq",jugador.nombre);
	printf("ue estaba de espaldas, esta se voltea por reflejo ezquiva a %s y lo lanza sobre una mesa cercana ",jugador.nombre);
	printf("\ntras el asalto se entabla una conversaci�n\nsujeto -veo que no eres como ellos,no hay sangre en tu boca, est�s");
	printf(" bien?\n%s- si, quien eres tu??\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//narra lo que pasa si se decide entrar sigilosamente a la puerta de la comisar�a donde escucha el ruido
void n15(Datos jugador)
{
	char continuar;
	
	printf("%s entra sigilosamente, abriendo la puerta de manera casi imperceptible y logra ver a un hombre d",jugador.nombre);
	printf("e espaldas\n%s lo observa  y nota que sus movimientos no son similares a los de los salvajes, as�",jugador.nombre);
	printf(" que decide entablar una conversaci�n\n-hola?, estas bien? - pregunta %s con inseguridad\nsujeto:",jugador.nombre);
	printf("- si, y por lo que veo tu tambi�n\n%s quien eres tu??\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//procedimiento que narra como johan le entrega la informaci�n a el jugador y deciden ir a las monta�as
void n19(Datos jugador)
{
	char continuar;
	
	printf("\n");
	printf("johan- me llamo johan y soy m�dico del hospital de la zona, quien eres tu?\nsoy %s, un ciudadano ",jugador.nombre);
	printf("ordinario quiz�\n johan le comenta a %s que desde por la ma�ana la gente ha estado acudiendo al h",jugador.nombre);
	printf("ospital por un brote\nen la piel y mucha fiebre, narra tambi�n que desp�es de un tiempo todo se descontrol� y qu");
	printf("e los pacientes\nempezaron a atacarse unos a otros con armas de contundencia e incluso con los dientes. Cuenta a");
	printf("dem�s\nque tuvo que salir del hospital a buscar ayuda en la comisar�a ya que no era seguro estar en el hospital ");
	continuar=leerCaracter("\npresione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
	
	printf("johan muestra a %s un documento secreto de polic�a, y le dice que hace masomenos un a�o un avi�n ",jugador.nombre);
	printf(" tuvo un \naccidente en las monta�as, cerca al yacimiento de agua, que no se encontr� el avi�n pero se supo que ");
	printf("pertenec�a a \nuna farmaceutica muy poderosa. Luego saca otro docmento y le informa a %s  que esa",jugador.nombre);
	printf(" farmaceutica envi� un equipo de \ncientificos a inspeccionar las monta�as, curiosamente la fecha de esa expedic");
	printf("i�n era la misma fecha actual.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("johan convence a %s de ir a las monta�as en busca de m�s informaci�n\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();	
	imprimirEstadisticas(jugador);


}

//------------------------------------mixto----------------------------------
//-----------------------------funciones mixtas-----------------
//narra la escena donde johan y el jugador eligen si ir por armas o ir a la monta�a
int n17 (Datos jugador)
{
	char continuar;
	int eleccion;
	
	printf("%s nota que johan est� un poco pensativo, se acerca y le pregunta qu� pasa\njohan le responde que",jugador.nombre);
	printf(" tiene una duda que %s le puede ayudar a solucionar, johan no sabe si es mejor\nir por armas aunq",jugador.nombre);
	printf("ue se escuchen gritos y quejidos por toda la comisar�a o ir directamente a la monta�a\n1: buscar armas\n2: ir a ");
	printf("la monta�a\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);

	return eleccion;
}
//narra la  escena donde johan y el jugador salen de la comisar�a
int n20 (Datos *jugador)
{	
	char continuar;
	int eleccion;
	
	printf("salen de la habitaci�n de documentos y se dirigen a lo que ellos consideran podr�a ser la zona de armas\nven una");
	printf(" escopeta pero antes de tomarla escuchan varias personas corriendo hacia donde ellos est�n\nambos salen corriend");
	printf("o. Mientras corr�an un infectado sale sorpresivamente de otro sal�n y asalta a johan\n1: ayudar a johan\n2: segu");
	printf("ir corriendo\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(*jugador);

	//la salud se ver�  afectada solo si elige la opci�n 1
	if (eleccion==1) {accionesSalud(&*jugador,eleccion);}
	accionesBM   (&*jugador,eleccion);
	afectarAnimo (&*jugador,eleccion);
	return eleccion;
}
//Narra la desicion de ayudar al medico cuando son interceptados mientras buscaban armas en la comisar�a
void n21 (Datos jugador)
{
	char continuar;
	
	printf("%s decide devolverse a ayudar al m�dico, se acerca y con una fuerte patada golpea al infectado\nl",jugador.nombre);
	printf("iberando a johan, en eso un caminante rompe una ventana que estaba cerca a ellos y los vidrios lastiman\ntanto a");
	printf(" johan como a %s, ambos siguen corriendo y salen de la comisar�a",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//Narra la desicion de no ayudar al medico cunado son interceptados mientras buscaban armas en la comisar�a
void n22 (Datos jugador)
{
	char continuar;
	
	printf("%s decide seguir corriendo, a medida que avanza escucha los forcejeos y los gritos de johan\ndesp",jugador.nombre);
	printf("desp�es de correr por un breve lapso de tiempo, %s consige salir de la comisar�a e integrarse\nen",jugador.nombre);
	printf(" el camino de la monta�a");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//procedimiento que muestra la parte de la historia donde el jugador es acorralado por infectados en la monta�a
//y debe elegir si saltar o no por un barranco adyacente
int n24 (Datos *jugador)
{
	int eleccion;
	char continuar;
	
	printf("%s comienza a subir la monta�a, un poco cansado por la situaci�n, los plieges de piel que cubren",jugador->nombre);
	printf("\nsu rostro est�n humedos de sudor, y su rostro refleja una semilla de locura, %s trata de refle",jugador->nombre);
	printf("xionar\nsobre lo que ha sucedido cuando velozmente es alcanzado por un grupo de almenos 6 salvajes con sus rostr");
	printf("os que emiten demencia,%s se ve acorralado en un barranco\nen un breve  preludio que avisaba la ",jugador->nombre);
	printf("fuga de violencia superpuesta %s observa el barranco y el arma de contundencia que carga en su m",jugador->nombre);
	printf("ano... \n1: luchar \n2:saltar\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(*jugador);
	accionesBM   (&*jugador,eleccion);
	accionesSalud(&*jugador,eleccion);
	afectarAnimo (&*jugador,eleccion);
    
	return eleccion;

}
//narra el momento en el que salen de la comisaria y son perseguidos por un grupo de salvajes, aqui se decide si dejar morir a 
//jhoan o luchar a su lado
int n23(Datos *jugador)
{
	char continuar;
	int eleccion;
	
    printf("Una vez afuera de la comisar�a, %s y Jhoan se encuentran un poco m�s tranquilos pese a todo lo", jugador->nombre );
	printf(" que ha ocurr�do\nsin embargo esta sensaci�n de calma no dura mucho, pues min�tos desp�es de empezar a sumergirs");
	printf("e en la intr�pida, pero hermosa\nmonta�a se escucha como salvajes se dirigen hacia ellos. Pronto se ve subiendo ");
	printf("por la monta�a un gran n�mero de salvajes \n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(*jugador);
	
	printf("Rapidamente %s y Jhoan empiezan a correr, no obstante Jhoan cae debido a una roca e el suelo qu", jugador->nombre);
    printf("e no pude ver por la tension\ndel momento, %s se detiene y piensa si ayudarlo, �, utilizar el a", jugador->nombre);
	printf("contesimiento como ventaja para huir sin riesgo\nde que los salvajes lo sigan.\n1: Ayudar a Jhoan\n2: Seguir cor");
	printf("riendo\n");
	eleccion=validarEleccion();

	clrscr();
	imprimirEstadisticas(*jugador);

    accionesBM   (&*jugador,eleccion);
	accionesSalud(&*jugador,eleccion);
	afectarAnimo (&*jugador,eleccion);

	return eleccion;
}
//narracion de como el jugador ve una mancha blanca con rojo y decide si ir a investigar o no
int n30(Datos jugador)
{
	char continuar;
	int eleccion;

	printf("en medio de dolor, soledad al borde de un colapso mental logra ver una mancha de ");
	printf("color blanco con rojo\ndespues de todo lo que ha vivido %s desconfia, sin embargo",jugador.nombre);
	printf(" se plantea la cuesti�n\n1: investigar\n2: seguir caminando\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
        
        return eleccion;
}
//procedimiento que relata como el jugador despues de decidir lucha termina cayendo por el barranco, y quedando inconsciente
void n25(Datos jugador)
{
	char continuar;
	
	printf("%s decidido ha luchar, agarra firmemente su arma, sin embargo se da cuanta que atr�s vienen much", jugador.nombre);
    printf("os m�s salvajes, aun encontrandose\nen una situaci�n tan cr�tica %s da cara a la batalla, pero t", jugador.nombre);
    printf("ermina siendo acorralado de espalda al barranco, por lo que su pie derecho\nse desliza en el barranco, ocasionan");
    printf("do que todo su cuerpo caiga r�pidamente en este, en ese momento %s s�lo rodaba por el\nbarranco,", jugador.nombre);
    printf(" mientras golpeaba sus extremidades, casi llegando al final %s golpea su cabeza con una roca...\n",jugador.nombre);
    continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}   
//narra como el jugadro salta hacia el barranco, y queda inconsciente
void n26(Datos jugador)
{
	char continuar;
	
    printf("%s con un prudente salto, se adentra al barranco de la monta�a, inteligentemente baja teniendose", jugador.nombre);
    printf(" de la maleza que en dicho barranco abunda\nsin embargo, es dif�cil cuando se esta tan cansado, y la inclinaci�n");
    printf(" del barranco no te favorece, por lo que de este modo %s\ntermina perdiendo el control de su vel", jugador.nombre);
    printf("ocidad de bajada y sale rodando sin impedimento alguno, por desgracia casi llegando al final del barranco     \n");
    printf("%s golpea muy fuertemente su cabeza con una roca...\n", jugador.nombre);
    continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//narracion de como el jugador intenta salvar al doctor pero este lo empuja hacia un barranco para salvarlo a el
void n27(Datos jugador)
{
	char continuar;
	
    printf("Rapidamente casi sin dudarlo, %s corre a socorrer a Jhoan, lastimosamente los salvajes ya est�n d",jugador.nombre);
    printf("emaciado serca por lo que Jhoan se levanta\ny empuja a %s mientras los salvajes rasgan su piel y ",jugador.nombre);
    printf("deboran sus muslos.\n");
    continuar=leerCaracter("presione enter para continuar...");

    clrscr();
	imprimirEstadisticas(jugador);
	
    printf("%s cae rapidamente por el barranco, intenta agarrarse de la maleza pero la velocidad con la que c",jugador.nombre);
    printf("ae no lo deja, %s sigue cayendo y golpea su cabeza\ncon una roca...\n",jugador.nombre);
    continuar=leerCaracter("presione enter para continuar...");
    
    clrscr();
	imprimirEstadisticas(jugador);
}
//naraccion de como el jugador deja a Jhoan tirado en el suelo, mientras corre
void n28(Datos jugador)
{
	char continuar;
	
	printf("Con frialdad %s deja tirado a Jhoan, sigue corriendo y a su vez escucha los gritos desesperados ", jugador.nombre);
	printf("de dolor de Jhoan\n%s corre y corre hasta que no logra escuchar ya los sonidos de que emiten los", jugador.nombre);
	printf(" salvajes, despues de esto %s comienza\na reflexionar sobre lo que hizo, sintiendo una punzada  ", jugador.nombre);
	printf("en su pecho, empieza de nuevo a escuchar los gritos de Jhoan\npero esta vez en su cabeza, por lo que sale corrie");
	printf("ndo de nuevo para evitar el sentimiento  de culpa.\n");
	continuar=leerCaracter("presione enter para continuar...");
    
    clrscr();
	imprimirEstadisticas(jugador);
}
//El jugador despierta de su desmayo
void n29(Datos jugador)
{
	char continuar;

	printf("---------------\n");
	printf("1 HORA DESP�ES\n");
	printf("---------------\n");
	printf("%s despierta muy desorientado, y empieza de su pesadilla, de nuevo se escucha se suben salvajes ", jugador.nombre);
	printf("se levanta del suelo y\n%s se asoma por los arbustos y nota que hacia el se dirige un grupo de ", jugador.nombre );
	printf("salvajes, lo que no deja m�s opci�n que seguir subiendo.\n");
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que explica la historia del hongo
void n31(Datos jugador)
{
	char continuar;

	printf("su curiosidad predomina en la toma de desicion por lo que al llegar al lugar se encuentra con un hombre que por\n");
	printf("su apariencia, podr�a ser un cientifico, el hombre est� muy malherido y a duras penas logra contar una horrible\n");
	printf("historia sobre el acontecimiento:\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("hombre:-un hongo modificado se dirig�a hacia el laboratorio del norte para ser analizado, ya que seg�n archivos\n");
	printf("de investigaci�n este hongo presenta un componente que en determinada epoca del a�o ocasiona graves efectos en \n");
	printf("el cerebro humano, este hongo viajaba con el proposito de ocasionar una guerra biol�gica entre paises cercanos.\n");
	printf("\nen su traslado algo sali� mal con el avi�n encargado de transportarlo, pasamos mucho tiempo buscando el avi�n\n");
	printf("sin exito alguno hasta hace pocos dias, en cuanto tuvimos la ubicaci�n vinimos pero mirame, ya es demaciado tarde");
	printf("\nalmenos para mi...");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("cientifico:- el avi�n est� en alguna parte del rio que conecta a la peque�a presa de agua, suponemos que desde \n");
	printf("all� solt� sus esporas y contagi� al pueblo. no me queda mucho tiempo, puedo sentir el frio de la muerte y mis \n");
	printf("organos deterse, sube rio arriba y encuentra el avi�n, en este habr� un antidoto mnuy potente, viertelo en el  \n");
	printf("rio y espera a que las bestias se acerquem a beber.. solo as� podr�s salvarlos..");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("el hombre muere...");

	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
// narra la historia si el jugador ignora la mancha
void n32(Datos jugador)
{
	char continuar;

	printf("%s ignora la mancha y sigue subiendo la monta�a...",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar..."  );
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//Narra cuando el jugador escucha la alarma de un carro y puede decidir si seguir con su mision o largarse para salvarse de todo
int n33(Datos jugador)
{
	int eleccion;
	char continuar;

	printf("desp�es de unos cuantos minutos %s escucha un sonido que parece ser la alarma de un automovil   \n",jugador.nombre);
	printf("%s\nrapidamente identifica que el sonido proviene de un lugar no muy lejano, esto le hace pensar q",jugador.nombre);
	printf("ue podr�a dejarlo\ntodo atr�s y huir en el coche hacia una vida mejor\n1: seguir hacia el rio\n2:buscar el coche ");

	eleccion=validarEleccion();
	continuar=leerCaracter("\npresione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	return eleccion;
}
// procedimiento que narra  cuando el jugador encuentra el antidoto
void n34(Datos jugador)
{
	char continuar;

	printf("tras caminar por almenos dos horas %s empieza a encontrar partes del avi�n, por lo que acelera su \n",jugador.nombre);
	printf("paso hasta encontrarlo...");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s entra en el avi�n y logra ver lo que posiblemente es el antidoto, se acerca al recipiente y ve \n",jugador.nombre);
	printf("en su descripci�n que efectivamente lo es\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra como el jugador encuentra el coche y escapa
void n35(Datos jugador)
{
	char continuar;

	printf("%s logra ver el coche y se acerca r�pidamente a el, en su interior descubre un infierno de sangre \n",jugador.nombre);
	printf("y viceras, a�n as� %s decide entrar y para su suerte las llaves del auto est�n puestas y lo que   \n",jugador.nombre);
	printf("parece ser un brazo a�n las sostiene, sin escrupulo alguno las toma con el �nico objetivo de salir de all� vivo  \n");
	printf("sin embargo un grupo de infectados se acercan velozente al auto,%s prende el auto de inmediato e  \n",jugador.nombre);
	printf("intenta acelerar, pero por desgracia el acelerador est� atascado con los restos deshumanizados de alquel hombre\n  ");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s como puede logra retirar los restos y acelerar el vehiculo escapando de la situaci�n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el final bueno del rio
void n36(Datos jugador)
{
	char continuar;

	printf("%s vierte el antidoto en rio, inmediatamente ve como el hongo se desintegra, tambi�n observa que  \n",jugador.nombre);
	printf("a lo lejos varios infectados est�n bebiendo agua del rio y entrando en combulsi�n para luego quedar inmoviles en \n");
	printf("suelo\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s se duerme y al cabo de un rato despierta y observa como los que parecian infectados hace unas  \n",jugador.nombre);
	printf("horas ahora est�n despertando sin indicios de salvajismo");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s es conciente de que no ser� recordado como el salvador sin embargo lo �nico que a %s\n",jugador.nombre,jugador.nombre);
	printf("le importa es saber que la muerte de johan no fue en vano...\n");
}
//procedimiento que narra el final malo del rio
void n37(Datos jugador)
{
	char continuar;

	printf("debido a su mentalidad mezquina, %s ve el antidoto como una fuente de dinero, as� que decide      \n",jugador.nombre);
	printf("colocarlo en una maleta que tambi�n encontr� en el avi�n y parte de all� con la intenci�n de venderlo con precio \n");
	printf("alto en el mercado negro\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el final bueno del coche
void n38(Datos jugador)
{
	char continuar;
		
	printf("con el paso del tiempo %s logr� superar los horrendos recuerdos y profundas heridas que le dejaron\n",jugador.nombre);
	printf("los acontecimientos que vivi�, logrando conseguir una vida normal en un pais menos amenazado por guerras de tipo \n");
	printf("biol�gicas.");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el final malo del coche
void n39(Datos jugador)
{
	char continuar;

	printf("desp�es de todas sus malas acciones %s empieza a sentirse culpable y termina odiandose a si mismo\n",jugador.nombre);
	printf("con tal intensidad que termina suicidandose\n");
}


/* 
 * Programa   : hungry.c
 * Descripción: implementacion de las funciones para la libreria de hungry.h
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
	//char que servirá para regular la cantidad de texto en pantalla
	char continuar;
	printf("Año 1930...\n");
	//sección que le pide al usuario que presione enter para continuar, luego limpia pantalla e imprime las estadisticas
	//en el prologo se omite la parte de imprimir estadisticas ya que no son necesarias

	continuar=leerCaracter("presione enter para continuar...");
	clrscr();
	//inicio  de narrativa
	printf("%s escucha en la radio una noticia acerca de un accidente que ocurrió cerca al yacimiento de agua\n",jugador.nombre);
	printf("que alimenta una pequeña presa la cual  provee de energia y agua potable el pueblo donde %s vive,\n",jugador.nombre);
	printf("el locutor narra que un avión se accidentó cerca al yacimiento y que por dificultades geológicas y climatológicas ");
	printf("\nno se pudo hallar el avión %s no presta mucha atención y se distrae poco despúes con la música \n",jugador.nombre);
	printf("de turno...\n");
	continuar=leerCaracter("presione enter para continuar...");
	clrscr();
}
//procedimiento que adentra al jugador en la trama
void n2(Datos jugador)
{

	char continuar;
	int  eleccion;

	printf("Año 1931..\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s duerme placidamente en la sala de su hogar, hasta que unos gritos repentinos abruman los \n",     jugador.nombre);
	printf("alrededores de su morada se despierta y con los ojos pesados se asoma a la ventana para ver qué\nes lo que tiene a");
	printf(" la gente gritando de manera tan escandalosa...\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s se queda en shock..\nnunca en su vida se habría imaginado algo así..\ngente corriendo \n",        jugador.nombre);
	printf("ensangrientada, personas con las caras rojas de sangre y expresiones de locura...\nel suelo teñido de rojo, y rest");
	printf("os de organos adornando la escena como si de un macabro festín se tratara.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s tenía su cuerpo paralizado, su mente no podía procesar tal situación, parecía congelado en el   ",jugador.nombre);
	printf("tiempo.\nesto cambió cuando un fuerte golpe azotó su puerta.\n%s desvía su mirada hacia la puerta  ",jugador.nombre);
	printf("desde la ventana y ve que un grupo de almenos tres personas están tratando de entrar\nde esas personas se alcanza ");
	printf("a notar que tienen sangre en sus manos y sus ojos están brotados como nueces\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s observa a sus alrededores apresuradamente una forma de escapar motivado por el miedo\nnota un   ",jugador.nombre);
	printf("conducto de ventilación que lleva al garaje\ntambién una ventana que lleva al patio.\n mientras %s ",jugador.nombre);
	printf("elige, el sonido de la madera de su puerta rompiendose desmorona la poca cordura que le queda.\n");
	printf("1: Ir por el conducto de ventilación\n2: Romper la ventana e ir por el patio \n");
	eleccion=validarEleccion();

	//condición que límita la elección dependiendo del sexo del jugador
	if (eleccion==1 && jugador.sexo=='h')
	{
		printf("su complexión no le permite entrar por el conducto de ventilacón\nla puerta se rompe ferozmente como un trueno  ");
		printf("y %s no tiene más remedio que huir por la ventana\n",jugador.nombre);
	}
	else
	{
		if(eleccion==2&&jugador.sexo=='m')
		{
			printf("%s no tiene la fuerza suficiente para romper esa ventana\nla puerta se rompe ferozmente y ",jugador.nombre );
			printf("%s no tiene más remedio que huir por el conducto\n",jugador.nombre);
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
	printf("rlo y buscar una cura\n1: salvar al perrito\n2: ignorar la situación\n");
	//se realiza la lectura y validación de la decición
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

//procedimiento que narra la entrada de la mujer al panel de ventilación
//parametros=los datos del jugador
void n3 (Datos jugador)
{
	int eleccion;
	char continuar;

	printf("gracias a su complexión delgada logra colarse por el panel de ventilación el cual la conduce al garaje, al entra");
	printf("r se topa\n con un bate de beisbol, lo toma y se sienta para descansar un poco\nmientras recupera el aliento un ");
	printf("grupo de salvajes comienza a golpear la debil puerta que conecta el garaje con el interior de la casa\n haciendo");
	printf(" que %s no tenga más remedio que salir corriendo a la calle por la puerta principal del garaje.",  jugador.nombre);
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
	printf("observa todo a su alrededor y ve a las personas descontroladas\ny decide que lo mejor es ir a la comisaría en bu");
	printf("sca de refugio y armas.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();

	printf("%s se conoce muy bien el pueblo así que se mete por un pasadizo entre las malesas para llegar más",jugador.nombre);
	printf(" rapido a la comisaría.");
}
//procedimiento que narra la historia si la mujer decide no ayudar al perro
void n10 (Datos jugador)
{
	char continuar;

	printf("%s recuerda los momentos de infancia con su hermano por lo que sin pensarlo evade la situación y ",jugador.nombre);
	printf("decide ir a la comisaría en busca de un resguardo temporal\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}

//procedimiento que detalla como el jugador llega a la comisaria mediante el atajo
void n16(Datos jugador)
{
	char continuar;

    printf("%s recuerda que de niña junto a sus amigas, iban la mayor parte del tiempo a un parque que qued", jugador.nombre );
    printf("a a tres cuadras\nde la comisaría del pueblo, pero ellas no se iban por la carretera, ya que conocían un atajo e");
    printf("ntre el bosque que\nhabía detrás de su casa, sin pensarlo dos veces y más aún viendo la cantidad de infectados q");
    printf("ue se encuentran en la\ncarretera, se dirige al bosque por donde consigue atravesar el atajo sin problemas y sal");
    printf("ir muy serca de la comisaría\n");
    continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el encuentro de la mujer con el doctor en la comisaría
void n18(Datos jugador)
{
	char continuar;

	printf("despues de llegar a la comisaría logra ver a una persona que parece un doctor\ndespúes de compartir ciertas  pal");
	printf("abras, %s se da cuenta que el doctor se llama johan\ny que es un doctor del hospital del pueblo\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("johan le comenta a %s que desde por la mañana la gente ha estado acudiendo al hospital por un bro",jugador.nombre);
	printf("te\nen la piel y mucha fiebre, narra también que despúes de un tiempo todo se descontroló y que los pacientes \n");
	printf("empezaron a atacarse unos a otros con armas de contundencia e incluso con los dientes. Cuenta además\nque tuvo q");
	printf("ue salir del hospital a buscar ayuda en la comisaría ya que no era seguro estar en el hospital");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
		
	printf("johan muestra a %s un documento secreto de policía, y le dice que hace masomenos un año un avión ",jugador.nombre);
	printf("\ntuvo un accidente en las montañas, cerca al yacimiento de agua, que no se encontró el avión pero se supo que p");
	printf("ertenecía a \nuna farmaceutica muy poderosa. Luego saca otro docmento y le informa a %s que esa f",jugador.nombre);
	printf("armaceutica envió un equipo de \ncientificos a inspeccionar las montañas, curiosamente la fecha de esa expedició");
	printf("n era la misma fecha actual.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("johan convence a %s de ir a las montañas en busca de más información\n",jugador.nombre);
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
	printf("e por la ventana rota y mientras corre a través del patio se tropieza con un palo de madera\n%s ",jugador->nombre);
	printf("se levanta y ve que el palo tiene buena resistencia así que lo toma.");
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
	printf("1: salvar al perrito\n2: ignorar la situación\n");
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
	
	printf("%s se detiene un momento para analizar el mejor camino, recuerda que cuando era niño sabía de un",jugador->nombre);
	printf(" camino conducía\na un parque cerca a la comisaría, luego mira hacia la carretera y ve a un grupo de personas si");
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
    printf("le parece escuchar un ruido, dicho ruido no es producto de su imaginación porque suena de nuevo.\n Una y otra vé");
    printf("z, cada vez más, %s se inquieta ya que en su mente tiene una serie\nde sentimientos que le quier",jugador.nombre );
    printf("en hacer explotar su cabeza, pues dicho ruido puede ser como su salvación\nsu perdición. En este preciso momento");
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
	printf("y decide que lo mejor es ir a la comisaría en busca de refugio y armas.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//narra la desición de no ayudar al perro
void n7 (Datos jugador)
{
	char continuar;
	
	printf("%s recuerda los momentos de infancia con su hermano por lo que sin pensarlo evade la situación y ",jugador.nombre);
	printf("decide ir a la comisaría en busca de un resguardo temporal\n");
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
	printf("s,el más depravado festín de carne  %s queda pasmado y ve como esos salvajes sueltan los trozos\n",jugador.nombre);
	printf("deshumanizados de esas personas para atraparlo a el. %s corre hacia la comisaría, durante la carr",jugador.nombre);
	printf("era se resbala con la sangre\ngolpeandose la cabeza. Pero esto no lo detiene y consigue llegar a la comisaría \n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//Narra la parte donde el jugador no ayuda ha las personas y se va para la comisaría
void n12(Datos jugador)
{
	char continuar;
	
	printf("%s huye por el atajo que recordaba, durante el camino escucha los gritos desesperados  de las per",jugador.nombre);
	printf("sonas\nesos gritos empiezan a resonar en la cabeza de %s en son de culpa, hasta que llega a la co",jugador.nombre);
	printf("misaría\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//narra lo que pasa si se decide entrar violentamente a la puerta de la comisaría donde escucha el ruido
void n14(Datos jugador)
{
	char continuar;
	
	printf("%s entra de manera violenta, golpeando la puerta con una patada y arremetiendo con una persona\nq",jugador.nombre);
	printf("ue estaba de espaldas, esta se voltea por reflejo ezquiva a %s y lo lanza sobre una mesa cercana ",jugador.nombre);
	printf("\ntras el asalto se entabla una conversación\nsujeto -veo que no eres como ellos,no hay sangre en tu boca, estás");
	printf(" bien?\n%s- si, quien eres tu??\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//narra lo que pasa si se decide entrar sigilosamente a la puerta de la comisaría donde escucha el ruido
void n15(Datos jugador)
{
	char continuar;
	
	printf("%s entra sigilosamente, abriendo la puerta de manera casi imperceptible y logra ver a un hombre d",jugador.nombre);
	printf("e espaldas\n%s lo observa  y nota que sus movimientos no son similares a los de los salvajes, así",jugador.nombre);
	printf(" que decide entablar una conversación\n-hola?, estas bien? - pregunta %s con inseguridad\nsujeto:",jugador.nombre);
	printf("- si, y por lo que veo tu también\n%s quien eres tu??\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//procedimiento que narra como johan le entrega la información a el jugador y deciden ir a las montañas
void n19(Datos jugador)
{
	char continuar;
	
	printf("\n");
	printf("johan- me llamo johan y soy médico del hospital de la zona, quien eres tu?\nsoy %s, un ciudadano ",jugador.nombre);
	printf("ordinario quizá\n johan le comenta a %s que desde por la mañana la gente ha estado acudiendo al h",jugador.nombre);
	printf("ospital por un brote\nen la piel y mucha fiebre, narra también que despúes de un tiempo todo se descontroló y qu");
	printf("e los pacientes\nempezaron a atacarse unos a otros con armas de contundencia e incluso con los dientes. Cuenta a");
	printf("demás\nque tuvo que salir del hospital a buscar ayuda en la comisaría ya que no era seguro estar en el hospital ");
	continuar=leerCaracter("\npresione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
	
	printf("johan muestra a %s un documento secreto de policía, y le dice que hace masomenos un año un avión ",jugador.nombre);
	printf(" tuvo un \naccidente en las montañas, cerca al yacimiento de agua, que no se encontró el avión pero se supo que ");
	printf("pertenecía a \nuna farmaceutica muy poderosa. Luego saca otro docmento y le informa a %s  que esa",jugador.nombre);
	printf(" farmaceutica envió un equipo de \ncientificos a inspeccionar las montañas, curiosamente la fecha de esa expedic");
	printf("ión era la misma fecha actual.\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("johan convence a %s de ir a las montañas en busca de más información\n",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();	
	imprimirEstadisticas(jugador);


}

//------------------------------------mixto----------------------------------
//-----------------------------funciones mixtas-----------------
//narra la escena donde johan y el jugador eligen si ir por armas o ir a la montaña
int n17 (Datos jugador)
{
	char continuar;
	int eleccion;
	
	printf("%s nota que johan está un poco pensativo, se acerca y le pregunta qué pasa\njohan le responde que",jugador.nombre);
	printf(" tiene una duda que %s le puede ayudar a solucionar, johan no sabe si es mejor\nir por armas aunq",jugador.nombre);
	printf("ue se escuchen gritos y quejidos por toda la comisaría o ir directamente a la montaña\n1: buscar armas\n2: ir a ");
	printf("la montaña\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);

	return eleccion;
}
//narra la  escena donde johan y el jugador salen de la comisaría
int n20 (Datos *jugador)
{	
	char continuar;
	int eleccion;
	
	printf("salen de la habitación de documentos y se dirigen a lo que ellos consideran podría ser la zona de armas\nven una");
	printf(" escopeta pero antes de tomarla escuchan varias personas corriendo hacia donde ellos están\nambos salen corriend");
	printf("o. Mientras corrían un infectado sale sorpresivamente de otro salón y asalta a johan\n1: ayudar a johan\n2: segu");
	printf("ir corriendo\n");
	eleccion=validarEleccion();
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(*jugador);

	//la salud se verá  afectada solo si elige la opción 1
	if (eleccion==1) {accionesSalud(&*jugador,eleccion);}
	accionesBM   (&*jugador,eleccion);
	afectarAnimo (&*jugador,eleccion);
	return eleccion;
}
//Narra la desicion de ayudar al medico cuando son interceptados mientras buscaban armas en la comisaría
void n21 (Datos jugador)
{
	char continuar;
	
	printf("%s decide devolverse a ayudar al médico, se acerca y con una fuerte patada golpea al infectado\nl",jugador.nombre);
	printf("iberando a johan, en eso un caminante rompe una ventana que estaba cerca a ellos y los vidrios lastiman\ntanto a");
	printf(" johan como a %s, ambos siguen corriendo y salen de la comisaría",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//Narra la desicion de no ayudar al medico cunado son interceptados mientras buscaban armas en la comisaría
void n22 (Datos jugador)
{
	char continuar;
	
	printf("%s decide seguir corriendo, a medida que avanza escucha los forcejeos y los gritos de johan\ndesp",jugador.nombre);
	printf("despúes de correr por un breve lapso de tiempo, %s consige salir de la comisaría e integrarse\nen",jugador.nombre);
	printf(" el camino de la montaña");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

}
//procedimiento que muestra la parte de la historia donde el jugador es acorralado por infectados en la montaña
//y debe elegir si saltar o no por un barranco adyacente
int n24 (Datos *jugador)
{
	int eleccion;
	char continuar;
	
	printf("%s comienza a subir la montaña, un poco cansado por la situación, los plieges de piel que cubren",jugador->nombre);
	printf("\nsu rostro están humedos de sudor, y su rostro refleja una semilla de locura, %s trata de refle",jugador->nombre);
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
	
    printf("Una vez afuera de la comisaría, %s y Jhoan se encuentran un poco más tranquilos pese a todo lo", jugador->nombre );
	printf(" que ha ocurrído\nsin embargo esta sensación de calma no dura mucho, pues minútos despúes de empezar a sumergirs");
	printf("e en la intrépida, pero hermosa\nmontaña se escucha como salvajes se dirigen hacia ellos. Pronto se ve subiendo ");
	printf("por la montaña un gran número de salvajes \n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(*jugador);
	
	printf("Rapidamente %s y Jhoan empiezan a correr, no obstante Jhoan cae debido a una roca e el suelo qu", jugador->nombre);
    printf("e no pude ver por la tension\ndel momento, %s se detiene y piensa si ayudarlo, ó, utilizar el a", jugador->nombre);
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
	printf(" se plantea la cuestión\n1: investigar\n2: seguir caminando\n");
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
	
	printf("%s decidido ha luchar, agarra firmemente su arma, sin embargo se da cuanta que atrás vienen much", jugador.nombre);
    printf("os más salvajes, aun encontrandose\nen una situación tan crítica %s da cara a la batalla, pero t", jugador.nombre);
    printf("ermina siendo acorralado de espalda al barranco, por lo que su pie derecho\nse desliza en el barranco, ocasionan");
    printf("do que todo su cuerpo caiga rápidamente en este, en ese momento %s sólo rodaba por el\nbarranco,", jugador.nombre);
    printf(" mientras golpeaba sus extremidades, casi llegando al final %s golpea su cabeza con una roca...\n",jugador.nombre);
    continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}   
//narra como el jugadro salta hacia el barranco, y queda inconsciente
void n26(Datos jugador)
{
	char continuar;
	
    printf("%s con un prudente salto, se adentra al barranco de la montaña, inteligentemente baja teniendose", jugador.nombre);
    printf(" de la maleza que en dicho barranco abunda\nsin embargo, es difícil cuando se esta tan cansado, y la inclinación");
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
	
    printf("Rapidamente casi sin dudarlo, %s corre a socorrer a Jhoan, lastimosamente los salvajes ya están d",jugador.nombre);
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
	printf("1 HORA DESPÚES\n");
	printf("---------------\n");
	printf("%s despierta muy desorientado, y empieza de su pesadilla, de nuevo se escucha se suben salvajes ", jugador.nombre);
	printf("se levanta del suelo y\n%s se asoma por los arbustos y nota que hacia el se dirige un grupo de ", jugador.nombre );
	printf("salvajes, lo que no deja más opción que seguir subiendo.\n");
	continuar=leerCaracter("presione enter para continuar...\n");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que explica la historia del hongo
void n31(Datos jugador)
{
	char continuar;

	printf("su curiosidad predomina en la toma de desicion por lo que al llegar al lugar se encuentra con un hombre que por\n");
	printf("su apariencia, podría ser un cientifico, el hombre está muy malherido y a duras penas logra contar una horrible\n");
	printf("historia sobre el acontecimiento:\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("hombre:-un hongo modificado se dirigía hacia el laboratorio del norte para ser analizado, ya que según archivos\n");
	printf("de investigación este hongo presenta un componente que en determinada epoca del año ocasiona graves efectos en \n");
	printf("el cerebro humano, este hongo viajaba con el proposito de ocasionar una guerra biológica entre paises cercanos.\n");
	printf("\nen su traslado algo salió mal con el avión encargado de transportarlo, pasamos mucho tiempo buscando el avión\n");
	printf("sin exito alguno hasta hace pocos dias, en cuanto tuvimos la ubicación vinimos pero mirame, ya es demaciado tarde");
	printf("\nalmenos para mi...");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("cientifico:- el avión está en alguna parte del rio que conecta a la pequeña presa de agua, suponemos que desde \n");
	printf("allí soltó sus esporas y contagió al pueblo. no me queda mucho tiempo, puedo sentir el frio de la muerte y mis \n");
	printf("organos deterse, sube rio arriba y encuentra el avión, en este habrá un antidoto mnuy potente, viertelo en el  \n");
	printf("rio y espera a que las bestias se acerquem a beber.. solo así podrás salvarlos..");
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

	printf("%s ignora la mancha y sigue subiendo la montaña...",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar..."  );
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//Narra cuando el jugador escucha la alarma de un carro y puede decidir si seguir con su mision o largarse para salvarse de todo
int n33(Datos jugador)
{
	int eleccion;
	char continuar;

	printf("despúes de unos cuantos minutos %s escucha un sonido que parece ser la alarma de un automovil   \n",jugador.nombre);
	printf("%s\nrapidamente identifica que el sonido proviene de un lugar no muy lejano, esto le hace pensar q",jugador.nombre);
	printf("ue podría dejarlo\ntodo atrás y huir en el coche hacia una vida mejor\n1: seguir hacia el rio\n2:buscar el coche ");

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

	printf("tras caminar por almenos dos horas %s empieza a encontrar partes del avión, por lo que acelera su \n",jugador.nombre);
	printf("paso hasta encontrarlo...");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s entra en el avión y logra ver lo que posiblemente es el antidoto, se acerca al recipiente y ve \n",jugador.nombre);
	printf("en su descripción que efectivamente lo es\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra como el jugador encuentra el coche y escapa
void n35(Datos jugador)
{
	char continuar;

	printf("%s logra ver el coche y se acerca rápidamente a el, en su interior descubre un infierno de sangre \n",jugador.nombre);
	printf("y viceras, aún así %s decide entrar y para su suerte las llaves del auto están puestas y lo que   \n",jugador.nombre);
	printf("parece ser un brazo aún las sostiene, sin escrupulo alguno las toma con el único objetivo de salir de allí vivo  \n");
	printf("sin embargo un grupo de infectados se acercan velozente al auto,%s prende el auto de inmediato e  \n",jugador.nombre);
	printf("intenta acelerar, pero por desgracia el acelerador está atascado con los restos deshumanizados de alquel hombre\n  ");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s como puede logra retirar los restos y acelerar el vehiculo escapando de la situación",jugador.nombre);
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el final bueno del rio
void n36(Datos jugador)
{
	char continuar;

	printf("%s vierte el antidoto en rio, inmediatamente ve como el hongo se desintegra, también observa que  \n",jugador.nombre);
	printf("a lo lejos varios infectados están bebiendo agua del rio y entrando en combulsión para luego quedar inmoviles en \n");
	printf("suelo\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s se duerme y al cabo de un rato despierta y observa como los que parecian infectados hace unas  \n",jugador.nombre);
	printf("horas ahora están despertando sin indicios de salvajismo");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);

	printf("%s es conciente de que no será recordado como el salvador sin embargo lo único que a %s\n",jugador.nombre,jugador.nombre);
	printf("le importa es saber que la muerte de johan no fue en vano...\n");
}
//procedimiento que narra el final malo del rio
void n37(Datos jugador)
{
	char continuar;

	printf("debido a su mentalidad mezquina, %s ve el antidoto como una fuente de dinero, así que decide      \n",jugador.nombre);
	printf("colocarlo en una maleta que también encontró en el avión y parte de allí con la intención de venderlo con precio \n");
	printf("alto en el mercado negro\n");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el final bueno del coche
void n38(Datos jugador)
{
	char continuar;
		
	printf("con el paso del tiempo %s logró superar los horrendos recuerdos y profundas heridas que le dejaron\n",jugador.nombre);
	printf("los acontecimientos que vivió, logrando conseguir una vida normal en un pais menos amenazado por guerras de tipo \n");
	printf("biológicas.");
	continuar=leerCaracter("presione enter para continuar...");
	
	clrscr();
	imprimirEstadisticas(jugador);
}
//procedimiento que narra el final malo del coche
void n39(Datos jugador)
{
	char continuar;

	printf("despúes de todas sus malas acciones %s empieza a sentirse culpable y termina odiandose a si mismo\n",jugador.nombre);
	printf("con tal intensidad que termina suicidandose\n");
}

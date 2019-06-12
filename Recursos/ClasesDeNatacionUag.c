#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <windows.h>
#include "prototipos.h"

/*
	Preguntar si desea realizar una inscripcion o consulto
	Inscripcion: grupo, nivel, instructor en particular. (manda error si el instructor no se encuentra en el nivel deseado)
	preguntar horario, si no hay dar  una sugerencia, si si hay lo anoto y se inscribe y avisa si ya esta lleno.
	Al hacer una consulta se pregunta que grupo, se imprime el grupo seleccionado junto con su instructor nivel y horario
*/

int main(void){
	char decision[20];	//Guardara la decisiones el que usuario ingrese
	int i,salir=1;	//Se utilizara la variable salir para del bucle
	char nivel_d[20],instructor_d[20]; //Guarda el nivel e instructor que desee el usuario
	int horario_d;	//Guarda la hora deseada de la clase 
	
	//Creacion y asignacion de datos a las clases
	eClases ClaseBasica;	
	eClases ClaseAvanzada;
	eClases ClaseBasica1;
	eClases ClaseAvanzada1;

	strcpy(ClaseBasica.instructor,"Juan");
	strcpy(ClaseAvanzada.instructor,"Karla");
	strcpy(ClaseBasica1.instructor,"Juan");
	strcpy(ClaseAvanzada1.instructor,"Karla");

	strcpy(ClaseBasica.nivel,"Basico");
	strcpy(ClaseAvanzada.nivel,"Avanzado");
	strcpy(ClaseBasica1.nivel,"Basico");
	strcpy(ClaseAvanzada1.nivel,"Avanzado");

	ClaseBasica.horarios = 12;
	ClaseBasica1.horarios = 15;
	ClaseAvanzada.horarios = 17;
	ClaseAvanzada1.horarios = 19;
	
	ClaseBasica.cupo = 5;
	ClaseAvanzada.cupo = 5;
	ClaseBasica1.cupo = 5;
	ClaseAvanzada1.cupo = 5;

	system("cls");	//Limpiamos la ventana
	do{
		//Inicia UI principal
		printf("Desea realizar una inscripcion, consulta o salir?\n");
		scanf("%s", &decision);
		if(!(strcmp(decision,"inscripcion"))){
			printf("\nDesea seleccionar su clase por nivel o instructor?\n");
			scanf("%s", &decision);
			if(!(strcmp(decision,"nivel"))){	//Si escoge inscribirse por nivel
				printf("\nQue nivel desea: Basico o Avanzado?\n");
				scanf("%s", &nivel_d);
				if(!strcmp(nivel_d,"Basico")){	//Si selecciono nivel basico
					printf("\nEstos son los horarios del nivel Basico:");
					printf("\n 1. %d pm\n 2. %d pm",ClaseBasica.horarios,ClaseBasica1.horarios);
					printf("\nQue horario desea tomar: %d pm  o  %d pm?\n",ClaseBasica.horarios,ClaseBasica1.horarios);
					scanf("%d", &horario_d);
				}else if(!strcmp(nivel_d,"Avanzado")){	//Si selecciono nivel avanzado
					printf("\nEstos son los horarios del nivel Avanzado:");
					printf("\n 1. %d pm\n 2. %d pm",ClaseAvanzada.horarios,ClaseAvanzada1.horarios);
					printf("\nQue horario desea tomar: %d pm  o  %d pm?\n",ClaseAvanzada.horarios,ClaseAvanzada1.horarios);
					scanf("%d", &horario_d);
				}else{	//Si no selecciono una de las dos opciones
					printf("\nError IF() Seleccion de NIVEL 1\n");
				}
			}else if(!(strcmp(decision,"instructor"))){	//Si escoge inscribirse por instructor
				//GUSTAVO
				printf("Estos son los profesores disponibles:\n1.Juan\n2.Karla" );
				printf("\nQue instructor desea?\n");
				scanf("%s", &instructor_d);
				if(!strcmp(instructor_d, "Juan")){	//Se selecciona 
					printf("\nEstos son los horarios de Juan:\n1. 12:00pm\n2. 15:00pm\n");
					printf("que horario desea? ");
					scanf("%i",&horario_d);
				}else if(!strcmp(instructor_d, "Karla")){
					printf("\nEstos son los horarios de Karla:\n1. 17:00pm\n2. 19:00pm\n");
					printf("que horario desea? ");
					scanf("%i",&horario_d);
				}

			}else{	//Si no escoge ninguna de las dos opciones
				printf("\nError IF() Seleccion de organizacion 1\n");
			}
		}else if(!(strcmp(decision,"consulta"))){		//Si decide hacer una consulta
			printf("\nNivel: %s",ClaseBasica.nivel);	//Se imprime la clase Basica
			printf("\nInstructor: %s",ClaseBasica.instructor);
			printf("\nHorarios: \n1. %d pm | Cupo: %d\n2. %d pm | Cupo: %d",ClaseBasica.horarios,ClaseBasica.cupo,ClaseBasica1.horarios,ClaseBasica1.cupo);

			printf("\n\n");

			printf("\nNivel: %s",ClaseAvanzada.nivel);		//Se imprime la clase Avanzada
			printf("\nInstructor: %s",ClaseAvanzada.instructor);
			printf("\nHorarios: \n1. %d pm | Cupo: %d\n2. %d pm | Cupo: %d",ClaseAvanzada.horarios,ClaseAvanzada.cupo,ClaseAvanzada1.horarios,ClaseAvanzada1.cupo);

		}else if(!(strcmp(decision,"salir"))){//Si selecciona otra salir
			salir = 0;
		}

		//Revisar dispocicion de clases
		switch(horario_d){
			case 12:
						if(	ClaseBasica.cupo>0){	//Si aun hay cupo en esta clase 
							ClaseBasica.cupo--;	//Se le resta un cupo a la clas	
							printf("\nFelicidades tu inscripcion ya fue aprobada.");
							break;
						}else{
							printf("\nLo sentimos ese horario esta ocupado. Por favor pruebe otro.");
						}
			break;
			case 15:
						if(	ClaseBasica1.cupo>0){
							ClaseBasica1.cupo--;
							printf("\nFelicidades tu inscripcion ya fue aprobada.");
							break;
						}else{
							printf("\nLo sentimos ese horario esta ocupado. Por favor pruebe otro.");
						}
			break;
				case 17:
						if(	ClaseAvanzada.cupo>0){
							ClaseAvanzada.cupo--;
							printf("\nFelicidades tu inscripcion ya fue aprobada.");
							break;
						}else{
							printf("\nLo sentimos ese horario esta ocupado. Por favor pruebe otro.");
						}
			break;
				case 19:
						if(	ClaseAvanzada1.cupo>0){
							ClaseAvanzada1.cupo--;
							printf("\nFelicidades tu inscripcion ya fue aprobada.");
							break;
						}else{
							printf("\nLo sentimos ese horario esta ocupado. Por favor pruebe otro.");
						}
			break;
		}
		
	}while(salir);
	return 0;
}

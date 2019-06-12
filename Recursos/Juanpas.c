/*
	Este programa tiene como objetivo simular una aplicación que almacena las
	cuentas de cada mesa que un bar posee. El programa debe ser capaz de alojar
	cada pedido que se ha hecho en cada mesa, de mostrar la cuenta actual, de
	agregar productos ordenados por los clientes a la cuenta y de crear una nueva
	cuenta para la misma mesa (en caso de que dicha mesa alla sido desocupada y 
	ocupada nuevamente).
	
	Equipo: Jorge Nava de la Peña y Alejandro Juvencio	
*/

#pragma warning (disable : W8075 )

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <conio.h>
#include <windows.h>

/***********FUNCIONES*************/
void pintarMarcoInterfaz(void);
void encabezadoInterfaz(void);
void pintarNavegador(void);
void Menu(void);
int despliegueDeAccion(int);
void pintarRayaDivisora(int,int,int,int);
void pintarMesas(void);
void limpiarNavegador(void);
void pintarMarcoCuenta(void);
void encabezadoCuenta(int,int);
void mostrarCuenta(void);
void imprimirNumeroCuenta(int,int);
int largoCadena(char*);
void conversionDeNombre(char *);
void imprimirCuenta(char**,int*);
void inicializarArreglos(char**,int*);
void agregarProductosCuenta(char**,int*);
void fuenteAgregarACuenta(void);
void seleccionarListasDeLaMesaAgregarCuenta(int,int);
void seleccionarListasDeLaMesaVerMenu(int);
void inicializarTodosArreglos(void);
void barraHor(int,int,int,int);
void barraVer(int,int,int,int);
/*********************************/

/***********CONSTANTES************/
#define largoNombres 10
#define maxProductos 20
/*********************************/

/***********VARIABLES*************/
int opc,bucle;
/*********************************/

/***********ARREGLOS*************/
char mesa1Productos[largoNombres][maxProductos], mesa1Cantidad[maxProductos];
char mesa2Productos[largoNombres][maxProductos], mesa2Cantidad[maxProductos];
char mesa4Productos[largoNombres][maxProductos], mesa4Cantidad[maxProductos];
char mesa5Productos[largoNombres][maxProductos], mesa5Cantidad[maxProductos];
char mesa6Productos[largoNombres][maxProductos], mesa6Cantidad[maxProductos];
char mesa7Productos[largoNombres][maxProductos], mesa7Cantidad[maxProductos];
char mesa8Productos[largoNombres][maxProductos], mesa8Cantidad[maxProductos];
char mesa9Productos[largoNombres][maxProductos], mesa9Cantidad[maxProductos];
char mesa10Productos[largoNombres][maxProductos], mesa10Cantidad[maxProductos];
/*********************************/


	int main(void){
		int i = 0;
		
		inicializarTodosArreglos();
		
		clrscr();
		
		do{
		pintarMarcoInterfaz();		
		pintarNavegador();
		Menu();
		cprintf("Seleccion: "); //Poner acento
		cscanf("%d",&opc);
		limpiarNavegador();
		
		despliegueDeAccion(opc);
		
		system("pause");
		i++;
		}while(i < 4);
		
		return 0;
	}
	
	void pintarMarcoInterfaz(){ //Se encarga de dibujar un marco que sera donde se desplegara toda la información.

		window(1,1,168,41);
		textbackground(WHITE);
		clrscr();
		window(3,2,166,40);
		textbackground(CYAN);
		clrscr();
		
		encabezadoInterfaz();		
		pintarMesas();
		
	}
	
	void encabezadoInterfaz(){
		
		int x=44,y=2;	
		textcolor(WHITE);
		
		gotoxy(x,y);  cprintf("  888888 888     888        d8888 888b    888 8888888b.     d8888  .d8888b.  \n\r");
		gotoxy(x,y+1);cprintf("    P88b 888     888       d88888 8888b   888 888   Y88b   d88888 d88P  Y88b \n\r");
		gotoxy(x,y+2);cprintf("     888 888     888      d88P888 88888b  888 888    888  d88P888 Y88b.      \n\r");
		gotoxy(x,y+3);cprintf("     888 888     888     d88P 888 888Y88b 888 888   d88P d88P 888  PY888b.   \n\r");
		gotoxy(x,y+4);cprintf("     888 888     888    d88P  888 888 Y88b888 8888888PP d88P  888     PY88b. \n\r");
		gotoxy(x,y+5);cprintf("     888 888     888   d88P   888 888  Y88888 888      d88P   888       P888 \n\r");
		gotoxy(x,y+6);cprintf("     88P Y88b. .d88P  d8888888888 888   Y8888 888     d8888888888 Y88b  d88P \n\r");
		gotoxy(x,y+7);cprintf("     888  PY88888PP  d88P     888 888    Y888 888    d88P     888  PY8888PP  \n\r");
		gotoxy(x,y+8);cprintf("   .d88P                                                                         \n\r");
		gotoxy(x,y+9);cprintf(" .d88PP                                                                          \n\r");
		gotoxy(x,y+10);cprintf("888PP                                                         \n\r");
		
	}
	
	void pintarNavegador(){
		window(129,17,166,38);
		textbackground(WHITE);
		clrscr();
		window(131,18,166,37);
		textbackground(CYAN);
		clrscr(); 
	}
	
	void Menu(){
		textcolor(WHITE);
		cprintf("%cQu%c desea hacer%c",168,130,63);
		cprintf("\n\n\r1) Mostrar cuenta\n\r2) Agregar a la cuenta\n\r3) Crear nueva cuenta\n\n\r");
				
		return;
	}
	
	int despliegueDeAccion(int opc){
		switch (opc){
			case 1: mostrarCuenta();
			break;
			case 2: fuenteAgregarACuenta();
			break;
			case 3:
			break;
		}		
		return 0;
	}
	
	void pintarRayaDivisora(int xI,int yI,int xF,int yF){
		window(xI,yI,xF,yF);
		textbackground(LIGHTGRAY);
		clrscr();
	}

	void pintarMesas(void){
		int i,x1=10,y1=17,x2=30,y2=21;
		int color = LIGHTGRAY;
		window(3,2,166,40); //Se posiciona en el cuadro azul grande
		
		for(i = 0; i < 4; i++,y1+=6,y2+=6){
			window(x1,y1,x2,y2); //Crea rectangulos que aparentan mesas
			textbackground(color);
			clrscr();
			gotoxy(11,3);
			textcolor(BLACK);
			cprintf("%d",i+1);
		}
		x1 = 38; x2 = 58; y1=17; y2 = 21;
		for(i = 0; i <= 3; i++,y1 += 6, y2+=6){
			window(x1,y1,x2,y2); //Crea rectangulos que aparentan mesas
			textbackground(color);
			clrscr(); 
			gotoxy(11,3);
			textcolor(BLACK);
			cprintf("%d",i+5);
		}
		
		x1 = 63; x2 = 83; y1=22; y2 = 26;
		for(i = 0; i < 2; i++,y1 += 8, y2+=8){
			window(x1,y1,x2,y2); //Crea rectangulos que aparentan mesas
			textbackground(color);
			clrscr(); 
			gotoxy(11,3);
			textcolor(BLACK);
			cprintf("%d",i+9);			
		}
	}
	
	void limpiarNavegador(){
		window(131,18,166,37);
		textbackground(CYAN);
		clrscr(); 
	}
	
	void pintarMarcoCuenta(){
		
		window(1,1,168,41);
		textbackground(BLUE); 
		clrscr();
		window(3,2,166,40);
		textbackground(BLACK);
		clrscr();
	}
	
	void encabezadoCuenta(int numCuenta,int version){
		int x,y;	
		
		textcolor(BLUE);
		textbackground(BLACK);
		if(version == 1){
			x=32;y=2;
			gotoxy(x,y+0);cprintf(" .d8888b.  888     888 8888888888 888b    888 88888888888     d8888     888  888   ");
			gotoxy(x,y+1);cprintf("d88P  Y88b 888     888 888        8888b   888     888        d88888     888  888   ");
			gotoxy(x,y+2);cprintf("888    888 888     888 888        88888b  888     888       d88P888   888888888888 ");
			gotoxy(x,y+3);cprintf("888        888     888 8888888    888Y88b 888     888      d88P 888     888  888   ");
			gotoxy(x,y+4);cprintf("888        888     888 888        888 Y88b888     888     d88P  888     888  888   ");
			gotoxy(x,y+5);cprintf("888    888 888     888 888        888  Y88888     888    d88P   888   888888888888 ");
			gotoxy(x,y+6);cprintf("Y88b  d88P Y88b. .d88P 888        888   Y8888     888   d8888888888     888  888   ");
			gotoxy(x,y+7);cprintf(" 8Y8888P8   8Y88888P8  8888888888 888    Y888     888  d88P     888     888  888   ");
		}else{
			x=45;y=3;
			gotoxy(x,y+0);cprintf("                                                       888  888   ");                                                                                        
			gotoxy(x,y+1);cprintf("                                     d8P               888  888   ");
			gotoxy(x,y+2);cprintf("                                   d888888P          888888888888 ");   
			gotoxy(x,y+3);cprintf(" d8888bd 88   d8P d8888b   88bd88   ?88'   d888b8b     888  888   ");
			gotoxy(x,y+4);cprintf("d8P      88   88 d8b_,dP  88P' ?8b  88P   d8P' ?88     888  888   ");    
			gotoxy(x,y+5);cprintf("88b      8(  d88 88b     d88   88P  88b   88b  ,88b  888888888888 ");	    
			gotoxy(x,y+6);cprintf("`?888P'd  88Pd?8b`?888P'd88'   88b  `?8b  `?88P'`88b   888  888   ");
			gotoxy(x,y+7);cprintf("                                                       888  888   ");
			
		}					
		imprimirNumeroCuenta(numCuenta,version);
	}
	
	void mostrarCuenta(){
		int numCuenta,version = 1,i,j;
		cprintf("%cDe que mesa es de la que gustaria\n\rver su cuenta?\n",168);
		cscanf("%d",&numCuenta);
		pintarMarcoCuenta();
		encabezadoCuenta(numCuenta,version);
		
		window(5,17,60,30);
		
		seleccionarListasDeLaMesaVerMenu(numCuenta);
		
	}
	
	void imprimirNumeroCuenta(int num,int version){
		if(version == 1){
			int x=118,y=2;
			switch (num){
				case 1:
					gotoxy(x,y+0);cprintf(" d888      ");
					gotoxy(x,y+1);cprintf("d8888      ");
					gotoxy(x,y+2);cprintf("  888      ");
					gotoxy(x,y+3);cprintf("  888      ");
					gotoxy(x,y+4);cprintf("  888      ");
					gotoxy(x,y+5);cprintf("  888      ");
					gotoxy(x,y+6);cprintf("  888      ");
					gotoxy(x,y+7);cprintf("8888888   ");
				break;
				case 2:
					gotoxy(x,y+0);cprintf(" .d8888b.  ");
					gotoxy(x,y+1);cprintf("d88P  Y88b ");
					gotoxy(x,y+2);cprintf("       888 ");
					gotoxy(x,y+3);cprintf("     .d88P ");
					gotoxy(x,y+4);cprintf(" .od888P  ");
					gotoxy(x,y+5);cprintf("d88P       ");
					gotoxy(x,y+6);cprintf("888       ");
					gotoxy(x,y+7);cprintf("888888888 ");
				break;
				case 3:
					gotoxy(x,y+0);cprintf(" .d8888b.  ");
					gotoxy(x,y+1);cprintf("d88P  Y88b ");
					gotoxy(x,y+2);cprintf("     .d88P ");
					gotoxy(x,y+3);cprintf("    8888b  ");
					gotoxy(x,y+4);cprintf("     8Y8b. ");
					gotoxy(x,y+5);cprintf("888    888 ");
					gotoxy(x,y+6);cprintf("Y88b  d88P ");
					gotoxy(x,y+7);cprintf(" 8Y8888P8  ");
				break;
				case 4:
					gotoxy(x,y+0);cprintf("    d8888  ");
					gotoxy(x,y+1);cprintf("   d8P888  ");
					gotoxy(x,y+2);cprintf("  d8P 888  ");
					gotoxy(x,y+3);cprintf(" d8P  888  ");
					gotoxy(x,y+4);cprintf("d88   888  ");
					gotoxy(x,y+5);cprintf("8888888888 ");
					gotoxy(x,y+6);cprintf("      888  ");
					gotoxy(x,y+7);cprintf("      888 ");
				break;
				case 5:
					gotoxy(x,y+0);cprintf("888888888  ");
					gotoxy(x,y+1);cprintf("888        ");
					gotoxy(x,y+2);cprintf("888        ");
					gotoxy(x,y+3);cprintf("8888888b.  ");
					gotoxy(x,y+4);cprintf("     8Y88b ");
					gotoxy(x,y+5);cprintf("       888 ");
					gotoxy(x,y+6);cprintf("Y88b  d88P ");
					gotoxy(x,y+7);cprintf(" Y888888P  ");
				break;
				case 6:
					gotoxy(x,y+0);cprintf(" .d8888b.         ");
					gotoxy(x,y+1);cprintf("d88P  Y88b        ");
					gotoxy(x,y+2);cprintf("888               ");
					gotoxy(x,y+3);cprintf("888d888b.         ");
					gotoxy(x,y+4);cprintf("888P 8Y88b        ");
					gotoxy(x,y+5);cprintf("888    888        ");
					gotoxy(x,y+6);cprintf("Y88b  d88P        ");
					gotoxy(x,y+7);cprintf(" Y888888P  ");
				break;
				case 7:
					gotoxy(x,y+0);cprintf(" 8888888888  ");
					gotoxy(x,y+1);cprintf("      d88P   ");     
					gotoxy(x,y+2);cprintf("     d88P    ");     
					gotoxy(x,y+3);cprintf("    d88P     ");     
					gotoxy(x,y+4);cprintf(" 88888888    ");     
					gotoxy(x,y+5);cprintf("  d88P       ");     
					gotoxy(x,y+6);cprintf(" d88P        ");     
					gotoxy(x,y+7);cprintf("d88P     ");
				break;
				case 8:
					gotoxy(x,y+0);cprintf(" .d8888b.         ");
					gotoxy(x,y+1);cprintf("d88P  Y88b        ");
					gotoxy(x,y+2);cprintf("Y88b. d88P        ");
					gotoxy(x,y+3);cprintf(" dY88888b         ");
					gotoxy(x,y+4);cprintf(".d8P88Y8b.        ");
					gotoxy(x,y+5);cprintf("888    888        ");
					gotoxy(x,y+6);cprintf("Y88b  d88P        ");
					gotoxy(x,y+7);cprintf(" Y888888P");
				break;
				case 9:
					gotoxy(x,y+0);cprintf(" .d8888b.         ");
					gotoxy(x,y+1);cprintf("d88P  Y88b        ");
					gotoxy(x,y+2);cprintf("888    888        ");
					gotoxy(x,y+3);cprintf("Y88b. d888        ");
					gotoxy(x,y+4);cprintf(" dY888P888        ");
					gotoxy(x,y+5);cprintf("       888        ");
					gotoxy(x,y+6);cprintf("Y88b  d88P        ");
					gotoxy(x,y+7);cprintf(" Y888888P  ");
				break;
				case 10:
					gotoxy(x,y+0);cprintf(" d888   .d8888b.  ");
					gotoxy(x,y+1);cprintf("d8888  d88P  Y88b ");
					gotoxy(x,y+2);cprintf("  888  888    888 ");
					gotoxy(x,y+3);cprintf("  888  888    888 ");
					gotoxy(x,y+4);cprintf("  888  888    888 ");
					gotoxy(x,y+5);cprintf("  888  888    888 ");
					gotoxy(x,y+6);cprintf("  888  Y88b  d88P ");
					gotoxy(x,y+7);cprintf("8888888 Y888888P  ");
				break;
			}  
		}else{
			int x=112,y=3;
			switch (num){
				case 1:
					gotoxy(x,y+0);cprintf(" d888      ");
					gotoxy(x,y+1);cprintf("d8888      ");
					gotoxy(x,y+2);cprintf("  888      ");
					gotoxy(x,y+3);cprintf("  888      ");
					gotoxy(x,y+4);cprintf("  888      ");
					gotoxy(x,y+5);cprintf("  888      ");
					gotoxy(x,y+6);cprintf("  888      ");
					gotoxy(x,y+7);cprintf("8888888   ");
				break;
				case 2:
					gotoxy(x,y+0);cprintf(" .d8888b.  ");
					gotoxy(x,y+1);cprintf("d88P  Y88b ");
					gotoxy(x,y+2);cprintf("       888 ");
					gotoxy(x,y+3);cprintf("     .d88P ");
					gotoxy(x,y+4);cprintf(" .od888P  ");
					gotoxy(x,y+5);cprintf("d88P       ");
					gotoxy(x,y+6);cprintf("888       ");
					gotoxy(x,y+7);cprintf("888888888 ");
				break;
				case 3:
					gotoxy(x,y+0);cprintf(" .d8888b.  ");
					gotoxy(x,y+1);cprintf("d88P  Y88b ");
					gotoxy(x,y+2);cprintf("     .d88P ");
					gotoxy(x,y+3);cprintf("    8888b  ");
					gotoxy(x,y+4);cprintf("     8Y8b. ");
					gotoxy(x,y+5);cprintf("888    888 ");
					gotoxy(x,y+6);cprintf("Y88b  d88P ");
					gotoxy(x,y+7);cprintf(" 8Y8888P8  ");
				break;
				case 4:
					gotoxy(x,y+0);cprintf("    d8888  ");
					gotoxy(x,y+1);cprintf("   d8P888  ");
					gotoxy(x,y+2);cprintf("  d8P 888  ");
					gotoxy(x,y+3);cprintf(" d8P  888  ");
					gotoxy(x,y+4);cprintf("d88   888  ");
					gotoxy(x,y+5);cprintf("8888888888 ");
					gotoxy(x,y+6);cprintf("      888  ");
					gotoxy(x,y+7);cprintf("      888 ");
				break;
				case 5:
					gotoxy(x,y+0);cprintf("888888888  ");
					gotoxy(x,y+1);cprintf("888        ");
					gotoxy(x,y+2);cprintf("888        ");
					gotoxy(x,y+3);cprintf("8888888b.  ");
					gotoxy(x,y+4);cprintf("     8Y88b ");
					gotoxy(x,y+5);cprintf("       888 ");
					gotoxy(x,y+6);cprintf("Y88b  d88P ");
					gotoxy(x,y+7);cprintf(" Y888888P  ");
				break;
				case 6:
					gotoxy(x,y+0);cprintf(" .d8888b.         ");
					gotoxy(x,y+1);cprintf("d88P  Y88b        ");
					gotoxy(x,y+2);cprintf("888               ");
					gotoxy(x,y+3);cprintf("888d888b.         ");
					gotoxy(x,y+4);cprintf("888P 8Y88b        ");
					gotoxy(x,y+5);cprintf("888    888        ");
					gotoxy(x,y+6);cprintf("Y88b  d88P        ");
					gotoxy(x,y+7);cprintf(" Y888888P  ");
				break;
				case 7:
					gotoxy(x,y+0);cprintf(" 8888888888  ");
					gotoxy(x,y+1);cprintf("      d88P   ");     
					gotoxy(x,y+2);cprintf("     d88P    ");     
					gotoxy(x,y+3);cprintf("    d88P     ");     
					gotoxy(x,y+4);cprintf(" 88888888    ");     
					gotoxy(x,y+5);cprintf("  d88P       ");     
					gotoxy(x,y+6);cprintf(" d88P        ");     
					gotoxy(x,y+7);cprintf("d88P     ");
				break;
				case 8:
					gotoxy(x,y+0);cprintf(" .d8888b.         ");
					gotoxy(x,y+1);cprintf("d88P  Y88b        ");
					gotoxy(x,y+2);cprintf("Y88b. d88P        ");
					gotoxy(x,y+3);cprintf(" dY88888b         ");
					gotoxy(x,y+4);cprintf(".d8P88Y8b.        ");
					gotoxy(x,y+5);cprintf("888    888        ");
					gotoxy(x,y+6);cprintf("Y88b  d88P        ");
					gotoxy(x,y+7);cprintf(" Y888888P");
				break;
				case 9:
					gotoxy(x,y+0);cprintf(" .d8888b.         ");
					gotoxy(x,y+1);cprintf("d88P  Y88b        ");
					gotoxy(x,y+2);cprintf("888    888        ");
					gotoxy(x,y+3);cprintf("Y88b. d888        ");
					gotoxy(x,y+4);cprintf(" dY888P888        ");
					gotoxy(x,y+5);cprintf("       888        ");
					gotoxy(x,y+6);cprintf("Y88b  d88P        ");
					gotoxy(x,y+7);cprintf(" Y888888P  ");
				break;
				case 10:
					gotoxy(x,y+0);cprintf(" d888   .d8888b.  ");
					gotoxy(x,y+1);cprintf("d8888  d88P  Y88b ");
					gotoxy(x,y+2);cprintf("  888  888    888 ");
					gotoxy(x,y+3);cprintf("  888  888    888 ");
					gotoxy(x,y+4);cprintf("  888  888    888 ");
					gotoxy(x,y+5);cprintf("  888  888    888 ");
					gotoxy(x,y+6);cprintf("  888  Y88b  d88P ");
					gotoxy(x,y+7);cprintf("8888888 Y888888P  ");
				break;
			}  
		}
	}
	
	void agregarProductosCuenta(char **mesaProductos, int *mesaCantidad){
		int i,j;
		char producto[10];
		
		cprintf("\nProducto: ");
		cscanf("%s",producto);
		conversionDeNombre(producto);

		for(i = 0; i < 10; i++){
			if(strcmp(mesaProductos[i],"X") == 0){
				break;
			}
		}
		j = i;
		for(i = 0; i < j; i++){
			if(strcmp(producto,mesaProductos[i]) == 0){
				mesaCantidad[i] += 1; //Se agrega 1 a la cantidad que ya tenia
				break; //Deja de buscar coincidencias ya que encontro una
			}
			if(i == j-1 && strcmp(producto,mesaProductos[i]) != 0){
				stpcpy(mesaProductos[j],producto); //Se añade a la lista
			}
		}		
	}

	void imprimirCuenta(char **mesaProductos, int *mesaCantidad){
		int i,j;
		
		window(5,17,60,30);
		
		for(i = 0; i < 10; i++){
			if(strcmp(mesaProductos[i],"X") == 0){
				break;
			}
		}
		
		cprintf("Se ordeno:\n\n\n");

		j = i;
		for(i = 0; i < j; i++){ 
			cprintf("\r%d | %s\n",mesaCantidad[i],mesaProductos[i]);
		}
	} 

	void inicializarArreglos(char **mesaProductos, int *mesaCantidad){

		/*
			*SE LE ASIGNARAN CARACTERES X A TODAS LAS CASILLAS DE MESAPRODUCTO
			*SE LE ASIGNARAN CEROS A TODAS LAS CASILLAS DE LA LISTA DE CANTIDADES
		*/
		
		int i,j;

		for(i = 0; i < 10; i++){
			strcpy(mesaProductos[i],"X");
		}
		
		for(i = 0; i < 10; i++){
			mesaCantidad[i] = 1;
		}
	}

	void conversionDeNombre(char string[]){
			int i; 
		 
			string[0] = toupper(string[0]);
			
			for(i = 1; i < 	largoCadena(string); i++){
				string[i] = tolower(string[i]);
			}
	}

	int largoCadena(char cadena[]){
			int largo=0;
			while (cadena[largo]!='\0') largo++;
			return largo;
	}
			
	void fuenteAgregarACuenta(){
		
		int i,j,x,y,numAgregar,numCuenta,version = 1;

		cprintf("%cDe que mesa es de la que gustaria\n\ragregar a su cuenta?\n",168);
		cscanf("%d",&numCuenta);
		pintarMarcoCuenta();
		encabezadoCuenta(numCuenta,version);
		
		x = 115;y = 15;
		barraVer(x,y,20,BLUE); x+=2;
		cprintf("                      MENU");
		gotoxy(x,y+3);cprintf("1) Pizza");
		gotoxy(x,y+4);cprintf("2) Cerveza");
		gotoxy(x,y+5);cprintf("3) Papas");
		gotoxy(x,y+6);cprintf("4) Alitas");
		gotoxy(x,y+7);cprintf("5) Soda");
		
		//FUNCION PARA MOSTRAR CUENTA
		
		textbackground(BLUE);
		window(60,17,110,22);
		clrscr();
		textbackground(BLACK);
		window(62,18,108,21);
		clrscr();
		
		cprintf(" %cCuantos productos desea agregar a la cuenta    de la mesa #%d?   ",168,numCuenta); 
		cscanf("%d",&numAgregar);
		
		textbackground(BLACK);
		window(60,17,110,22);
		clrscr();
		
		textbackground(BLACK);
		window(80,17,110,30);
		clrscr();
		
		seleccionarListasDeLaMesaAgregarCuenta(numCuenta,numAgregar); //CAMBIAR A ALGO MAS DESCRIPTIVO
	
	}	

	void seleccionarListasDeLaMesaAgregarCuenta(int numCuenta,int numAgregar){
		
		char producto[10];
		int i;
				
		switch(numCuenta){
			case 1:
				if(numAgregar == 1){
					if(strcmp(mesa1Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa1Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa1Productos,mesa1Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa1Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa1Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa1Productos,mesa1Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa1Productos,mesa1Cantidad);
			break;
			case 2:
				if(numAgregar == 1){
					if(strcmp(mesa2Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa2Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa2Productos,mesa2Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa2Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa2Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa2Productos,mesa2Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa2Productos,mesa2Cantidad);
			break;
			case 3:
				if(numAgregar == 1){
					if(strcmp(mesa3Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa3Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa3Productos,mesa3Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa3Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa3Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa3Productos,mesa3Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa3Productos,mesa3Cantidad);
			break;
			case 4:
				if(numAgregar == 1){
					if(strcmp(mesa4Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa4Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa4Productos,mesa4Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa4Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa4Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa4Productos,mesa4Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa4Productos,mesa4Cantidad);
			break;
			case 5:
				if(numAgregar == 1){
					if(strcmp(mesa5Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa5Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa5Productos,mesa5Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa5Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa5Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa5Productos,mesa5Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa5Productos,mesa5Cantidad);
			break;
			case 6:
				if(numAgregar == 1){
					if(strcmp(mesa6Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa6Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa6Productos,mesa6Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa6Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa6Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa6Productos,mesa6Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa6Productos,mesa6Cantidad);
			break;
			case 7:
				if(numAgregar == 1){
					if(strcmp(mesa7Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa7Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa7Productos,mesa7Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa7Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa7Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa7Productos,mesa7Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa7Productos,mesa7Cantidad);
			break;
			case 8:
				if(numAgregar == 1){
					if(strcmp(mesa8Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa8Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa8Productos,mesa8Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa8Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa8Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa8Productos,mesa8Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa8Productos,mesa8Cantidad);
			break;
			case 9:
				if(numAgregar == 1){
					if(strcmp(mesa9Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa9Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa9Productos,mesa9Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa9Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa9Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa9Productos,mesa9Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa9Productos,mesa9Cantidad);
			break;
			case 10:
				if(numAgregar == 1){
					if(strcmp(mesa10Productos[0],"X") == 0){
						cprintf("\nProducto: ");
						cscanf("%s",producto);
						conversionDeNombre(producto);
						stpcpy(mesa10Productos[0],producto);
					}else{
						agregarProductosCuenta(mesa10Productos,mesa10Cantidad);
					}
				}else if(numAgregar > 1){
					for(i = 0; i < numAgregar; i++){
						if(strcmp(mesa10Productos[0],"X") == 0){
							cprintf("\nProducto: ");
							cscanf("%s",producto);
							conversionDeNombre(producto);
							stpcpy(mesa10Productos[i],producto);
						}else{
							agregarProductosCuenta(mesa10Productos,mesa10Cantidad);
						}
					}
				}	
				imprimirCuenta(mesa10Productos,mesa10Cantidad);
			break;			
		}
	}
	
	void inicializarTodosArreglos(){
		inicializarArreglos(mesa1Productos,mesa1Cantidad);
		inicializarArreglos(mesa2Productos,mesa2Cantidad);
		inicializarArreglos(mesa3Productos,mesa3Cantidad);
		inicializarArreglos(mesa4Productos,mesa4Cantidad);
		inicializarArreglos(mesa5Productos,mesa5Cantidad);
		inicializarArreglos(mesa6Productos,mesa6Cantidad);
		inicializarArreglos(mesa7Productos,mesa7Cantidad);
		inicializarArreglos(mesa8Productos,mesa8Cantidad);
		inicializarArreglos(mesa9Productos,mesa9Cantidad);
		inicializarArreglos(mesa10Productos,mesa10Cantidad);
	}

	void barraHor(int x, int y, int longitud, int color){
		int i;
		textcolor(color);
		for(i = 0; i < longitud; i++){
			gotoxy(x+i,y);
			cprintf("%c",196);
		}
	}

	void barraVer(int x, int y, int longitud, int color){
		int i;
		textcolor(color);
		for(i = longitud; i > 0; i--){
			gotoxy(x,y+i);
			cprintf("%c",219);
		}
	}

	void seleccionarListasDeLaMesaVerMenu(int numCuenta){
		switch(numCuenta){
			case 1: imprimirCuenta(mesa1Productos,mesa1Cantidad);
			break;
			case 2: imprimirCuenta(mesa2Productos,mesa2Cantidad);
			break;
			case 3: imprimirCuenta(mesa3Productos,mesa3Cantidad);
			break;
			case 4: imprimirCuenta(mesa4Productos,mesa4Cantidad);
			break;
			case 5: imprimirCuenta(mesa5Productos,mesa5Cantidad);
			break;
			case 6: imprimirCuenta(mesa6Productos,mesa6Cantidad);
			break;
			case 7: imprimirCuenta(mesa7Productos,mesa7Cantidad);
			break;
			case 8: imprimirCuenta(mesa8Productos,mesa8Cantidad);
			break;
			case 9: imprimirCuenta(mesa9Productos,mesa9Cantidad);
			break;
			case 10: imprimirCuenta(mesa10Productos,mesa10Cantidad);
			break;
		}

	}


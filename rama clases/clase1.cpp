#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

using namespace std;

//PROTOTIPO DE LAS FUNCIONES
void cambio(char a[]);
void CursorOn(bool visible, DWORD size);
void CursorOff();
void gotoxy(int x,int y);
void dibujarCuadro(int x1,int y1,int x2,int y2);
void limpia();
void menu();
void comprar();
void login();
void leerPasw(char frase[]);


//CLASE CLIENTE: SE CREA LA CLASE CLIENTE, Y DEFINIMOS LOS ATRIBUTOS Y MÉTODOS
class Persona{
	public:
		char nombre[35];
		char dni[15];
		char telefono[15];
		char ciudad[50];
	public:
		void ingreso();
		void actualizar();
		void eliminar();
		void consultar();
};


//CLASE DERIVADA CLIENTE, HEREDA TODOS LOS ATRIBUTOS DE LA CLASE PERSONA
class Cliente : public Persona{
		int edad;
	public:
		void ingreso();
		void actualizar();
		void eliminar();
		void consultar();
};


//CLASE TITULO, AQUI SE CREA UN ATRIBUTO TIPO CHAR DONDE LE ASIGNAREMOS UN NOMBRE CON EL CONSTRUCTOR, Y CREAMOS LA FUNCION AMIGA MOSTRARTIRULO
class Titulo{
		char nombre[40];
	public:
		Titulo(){
			strcpy(nombre,"              R E S T A U R A N T E");
		}
	    friend void mostrarTitulo(Titulo);  //prototipo function amiga
	    
};
//FUNCION MOSTRARTITULO, PERMITE LLAMAR A LA FUNCION AMIGA Y MOSTRAR EL TEMA E IMPRIMIRLO
void mostrarTitulo(Titulo T){
	gotoxy(16,3); printf(T.nombre);
}


//FUNCION MENU: IMPRIME LAS OPCIONES DEL MENU PRINCIPAL POR PANTALLA, Y PERMITE QUE EL USUARIO INGRESE UNA OPCIÓN
void menu(){
	Cliente Cl; //AQUÍ SE INSTANCIA LA CLASE CLIENTE, ES DECIR, SE CREA EL OBJETO LLAMADO CL , CON ESTO SE PODRÁ LLAMAR A LOS MÉTODOS QUE TIENE LA CLASE CLIENTE 
	char op,op2;
	limpia();
	CursorOn(1,10);
	do{
		gotoxy(4,6); printf("CLIENTES                         PEDIDOS                          CERRAR");
		gotoxy(4,9); printf("MENU PRINCIPAL");
		gotoxy(4,11); printf("(1) Clientes");
		gotoxy(4,13); printf("(2) Pedidos");
		gotoxy(4,15); printf("(3) Cerrar");
		gotoxy(4,18); printf("Ingrese opcion: ");
		scanf("%s",&op);
		
		if(op!='1' && op!='2' && op!='3'){
			gotoxy(4,22); printf("Error al ingresar valores. Presione una tecla para volver a ingresar..");
			CursorOff();
			getch();
			gotoxy(4,22); printf("                                                                       ");
			gotoxy(4,18); printf("                                                                       ");
			CursorOn(1,10);	
		}
			
	}while(op!='1' && op!='2' && op!='3');
	
	
	if (op=='1'){
			limpia();
			do{
				gotoxy(4,6); printf("CLIENTES                         PEDIDOS                          CERRAR");
				gotoxy(4,8); printf("1. Registrar");
				gotoxy(4,10); printf("2. Actualizar");
				gotoxy(4,12); printf("3. Eliminar");
				gotoxy(4,14); printf("4. Consultar");
				gotoxy(4,16); printf("5. Volver");
				gotoxy(4,20); printf("Ingrese opcion: ");
				scanf("%s",&op2);
				
				if(op2!='1' && op2!='2' && op2!='3' && op2!='4' && op2!='5'){
					gotoxy(4,22); printf("Error al ingresar valores. Presione una tecla para volver a ingresar..");
					CursorOff();
					getch();
					gotoxy(4,22); printf("                                                                       ");
					gotoxy(4,20); printf("                                      ");
					CursorOn(1,10);	
				}
			
			}while(op2!='1' && op2!='2' && op2!='3' && op2!='4' && op2!='5');
		
		if (op2=='1') Cl.ingreso();   //AQUÍ SE LLAMA AL MÉTODO INGRESO
		if (op2=='2') Cl.actualizar();   //AQUÍ SE LLAMA AL MÉTODO ACTUALIZAR
		if (op2=='3') Cl.eliminar();     //AQUÍ SE LLAMA AL MÉTODO ELIMINAR
		if (op2=='4') Cl.consultar();    //AQUÍ SE LLAMA AL MÉTODO CONSULTAR
		if (op2=='5') menu();
	}	
	
	
	if (op=='2'){
			limpia();
			do{
			gotoxy(4,6); printf("CLIENTES                         PEDIDOS                          CERRAR");
			gotoxy(37,8); printf("1. Comprar");
			gotoxy(37,10); printf("2. Volver");

			gotoxy(37,13); printf("Ingrese opcion: ");
			scanf("%s",&op2);
			
			if(op2!='1' && op2!='2'){
				gotoxy(4,22); printf("Error al ingresar valores. Presione una tecla para volver a ingresar..");
				CursorOff();
				getch();
				gotoxy(4,22); printf("                                                                       ");
				gotoxy(34,13); printf("                             ");
				CursorOn(1,10);	
			}
			
	}while(op2!='1' && op2!='2');
	
		if (op2=='1') comprar();         //AQUÍ SE LLAMA AL MÉTODO CONSULTAR
		if (op2=='2') menu();
	}
	
	
	if (op=='3')
		exit(0);
	
}


// FUNCION INGRESO DE DATOS: ESTA FUNCIÓN PERMITE INGRESAR LOS DATOS DEL CLIENTE, Y LA CREACIÓN DEL ARCHIVO QUE LO LLAMAREMOS E2, QUE ALMACENARÁ ESTOS DATOS PARA QUE UNA VEZ SE CIERRE EL PROGRAMA, ESTOS QUEDEN GUARDADOS.
//FUNCION PARA QUE APAREZCA EL CURSOR
void CursorOn(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}


//FUNCION GOTOXY, SIRVE PARA POSICIONAR LOS MENSAJES EN UNA DETERMINADA ZONA DE LA PANTALLA, SE INGRESA COLUMNA Y FILA DE LA PANTALLA, EJEMPLO: gotoxy(4,10); printf("HOla"); ESTE MENSAJE SE IMPRIMIRÁ EN LA POSICIÓN COLUMNA 4, FILA 10
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }


//FUNCION QUE LIMPIA EL AREA DE LA PANTALLA
void limpia(){
	int i,j;
	for(i=8;i<=23;i++){
		for(j=4;j<=75;j++){
			gotoxy(j,i); printf(" ");}}
}


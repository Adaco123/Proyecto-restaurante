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
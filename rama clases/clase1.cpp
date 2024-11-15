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
void Cliente::ingreso(){
	FILE *pa, *pa2;                                //AQUI SE CREAN 2 VARIABLEs DE TIPO APUNTADOR CON EL NOMBRE PA Y PA2. ES DECIR, UNA VARIABLE PARA CADA ARCHIVO..
	char r;                                        //..LA CUEAL VA A CONTENER LA DIRECCION FISICA DE LOS ARCHIVOS UTILIZADOS 
	Cliente nuevo, lista[50];                      //AQUÍ SE CREAN DOS OBJETOS DE LA CLASES CLIENTE, UNO ES NUEVO Y EL OTRO ES UN ARRAY O VECTOR LLAMADO LISTA..
	limpia();                                      //..EL OBJETO NUEVO NOS PERMITERÁ ALMACENAR LOS DATOS EN LAS VARIABLES, PARA LUEGO GUARDARLOS EN EL ARCHIVO, MÁS ABAJO SE INDICE LA LINEA DONDE SE GUARDAN.
	
	if (((pa = fopen("Archivo Binario","a+b"))==NULL) || ((pa2 = fopen("Archivo Datos","a+b"))==NULL))            //FUNCION FOPEN: PERMITE CREAR Y/O ABRIR UN ARCHIVO, SE CREAN 2 ARCHIVOS, UNO BINARIO Y EL OTRO DE TEXTO , EL DE TEXTO PERMITE LEER LOS CARACTERES DEL TECLADO NORMAL
	{ 
		printf("No se puede abrir el archivo.\n");
		exit (0);
	}

	int encontro=1,i,ultimo,res;

	rewind(pa); 
	i=0;
	while(!feof(pa)){                                   //CON ESTE WHILE, SE VA A RECORRER TODO EL ARCHIVO, USAMOS LA FUNCION FEOF PARA RECORRER, LA CUAL RETORNA UN VALOR DISTINTO A CERO SI Y SOLO SI EL INDICADOR A LLEGADO AL FINAL DEL ARCHIVO
		if(fread(&nuevo, sizeof(Cliente), 1, pa)){      //LA FUNCION FREAD, DEVUELVE EL NUMERO DE ELEMENTOS LEIDOS EN EL ARCHIVO, POR LO TANTO ESTE NUMERO NOS SIRVE PARA INDICARLE AL ARRAY CUANTAS POSICIONES TENDRÁ
			lista[i]=nuevo;                             //TODA LA INFORMACION ALMACENADA EN NUEVO SE LA GUARDARA EN EL ARRAY LISTA..
			i++;                                        //.. ESTO SE LO HACE PARA LUEGO COMPARAR
		}                                               
	}

	
	
	fflush(stdin);
	gotoxy(4,8);printf("REGISTRO DE CLIENTES");
	gotoxy(4,10);printf("Nombres y apellidos:  "); gets(nuevo.nombre);

	gotoxy(4,12);printf("DNI:                  ");
	res=i;
	
	do{
		gotoxy(26,12); gets(nuevo.dni);
			
		//PROCESO DE BÚSQUEDA DE LA INFORMACIÓN
		ultimo=res-1;
		i=0;
		encontro=1;
		while (i<=ultimo && encontro){
			if (strcmp(lista[i].dni,nuevo.dni)==0) encontro=0; //COMPARA EL DNI INGRESADO POR TECLADO , CON LOS DNI DEL ARRAY LISTA
			else i++;
		}
		
		if (i<=ultimo){
			gotoxy(26,12);printf("                              ");
			gotoxy(4,22);printf("DNI ya registrado. Ingrese nuevamente.");}
		else {gotoxy(4,22); printf("                                               ");}
	}while(i<=ultimo);

	fflush(stdin);
	gotoxy(4,14);printf("Telefono:             "); gets(nuevo.telefono);
	gotoxy(4,16);printf("Ciudad:               "); gets(nuevo.ciudad);
	
	do{
		CursorOff();
		gotoxy(4,22);printf("¨Registrar Nuevo Cliente? Si[s] / No [n]: "); 
		r=getch();
	}while(r!='S' && r!='s' && r!='N' && r!='n');
	
		
	if (r=='s' || r=='S') {
		fwrite(&nuevo, sizeof(Cliente),1,pa);                                                            //AQUI SE GUARDAN LOS DATOS EN EL ARCHIVO LLAMADO ARCHIVO BINARIO , LA FUNCIÓN FWRITE PERMITE GUARDAR INFORMACIÓN CONTENIDA EN LAS VARIABLES A UN ARCHIVO DESTINO
		fprintf(pa2, "%s %s %s %s\n", nuevo.nombre, nuevo.dni, nuevo.telefono, nuevo.ciudad);           //AQUI SE GUARDAN LOS DATOS EN EL ARCHIVO DE TEXTO LLAMADO ARCHIVO DATOS, LA FUNCION FPRINTF AL IGUAL QUE LA FWRITE GUARDA INFORMACION EN LAS VARIABLES
		gotoxy(4,22);printf("                                             "); 
		gotoxy(4,22);printf("Cliente Registrado. Presione una tecla para volver..");
	}
	
	else {
	gotoxy(4,22);printf("Cliente NO Registrado. Presione una tecla para volver..");
	}
	
	fclose(pa); 
	fclose(pa2);
	CursorOff();
	getch();
	limpia();
	menu();
}


	
// FUNCION ACTUALIZAR: PERMITE MODIFICAR DATOS DEL CLIENTE
void Cliente::actualizar(){ 
	Cliente nuevo, lista[50];
  	char dni[15];
  	int encontro=1,linea,i,ultimo;
  	char r;
  	FILE *pa, *pa2;
  	limpia();
  	
	if (((pa = fopen("Archivo Binario","a+b"))==NULL))        
	{ 
		printf("No se puede abrir el archivo.\n");
		exit (0);
	}
  	rewind(pa); i=0;
  	
	while(!feof(pa)){ 
		if(fread(&nuevo, sizeof(Cliente), 1, pa)){
			lista[i]=nuevo;
			i++;
		}
  	}
  	
  	fclose(pa);
 
  	//proceso de busqueda de la informaci¢n
  	gotoxy(4,8);printf("ACTUALIZAR DATOS");
  	gotoxy(4,10);
  	fflush(stdin);
  	printf("Ingrese Numero De DNI: ");gets(dni);
  	ultimo=i-1;
  	i=0;
  	
  	while (i<=ultimo && encontro){ 
		if (strcmp(lista[i].dni,dni)==0) 
			encontro=0;
    	else 
			i++;
  	}
  	
  	if (i<=ultimo){ 
		do {
			CursorOn(1,10);
		    limpia();
		    gotoxy(4,8);printf("ACTUALIZAR DATOS");
		    gotoxy(4,10);printf("1. Nombre:                 %s\n",lista[i].nombre);
		    gotoxy(4,12);printf("2. DNI:                    %s\n",lista[i].dni);
		    gotoxy(4,14);printf("3. Telefono:               %s\n",lista[i].telefono);
		    gotoxy(4,16);printf("4. Ciudad:                 %s\n",lista[i].ciudad);
		    
		    gotoxy(4,20);printf("Escriba la linea a modificar: ");
		    
			do{
		       gotoxy(34,20);scanf("%d",&linea);
		       if(linea<1 || linea>4) {
		       	gotoxy(34,20);printf("          ");
		       	gotoxy(4,22);printf("Opcion no valida. Ingrese nuevamente..");
			   }
		    }while(linea<1 || linea>4);
		    gotoxy(4,22);printf("                                            ");
		    
		    fflush(stdin);
		    
			switch(linea){
			    case 1: gotoxy(4,10 );printf("                                                       ");
				    gotoxy(4,22);printf("                                           ");
					gotoxy(4,10 );
				    printf("1. Nombre:                 ");
				    gets(lista[i].nombre);
				    break;
			    case 2: gotoxy(4,12 );printf("                                            ");
				    gotoxy(4,22);printf("                                           ");
					gotoxy(4,12 );
				    printf("2. DNI:                    ");
				    gets(lista[i].dni);
				    break;
				case 3: gotoxy(4,14);printf("                                                  ");
				    gotoxy(4,22);printf("                                           ");
					gotoxy(4,14);
				    printf("3. Telefono:               ");
				    gets(lista[i].telefono);
				    break;
				case 4: gotoxy(4,16);printf("                                                       ");
				    gotoxy(4,22);printf("                                           ");
					gotoxy(4,16);
				    printf("4. Ciudad:                 ");
				    gets(lista[i].ciudad);
			}
			
			gotoxy(4,20);printf("Actualizacion Correcta.                  ");
			
			do{
				CursorOff();
				gotoxy(4,22);printf("¨Desea Seguir Actualizando? Si[s] / No[n]: ");
				r=getch();
			}while(r!='S' && r!='s' && r!='N' && r!='n');

    	}while (r!='n' && r!='N');
    
	    // Abre el archivo para Sobrescribir
	    if (((pa = fopen("Archivo Binario", "wb"))== NULL) || ((pa2 = fopen("Archivo Datos", "wb"))== NULL)) 
	      { printf("No se puede abrir el archivo.\n");
		return;
	      }
	    i=0;
	    
	    while(i<=ultimo)
	    { 
			fwrite(&lista[i], sizeof(Cliente), 1, pa);
			fprintf(pa2, "%s %s %s %s\n", lista[i].nombre, lista[i].dni, lista[i].telefono, lista[i].ciudad);
	      	i++;
	    }
	    
		fclose(pa);
		fclose(pa2);
		gotoxy(4,20);printf("                                         ");
		gotoxy(4,22);printf("Presione una tecla para volver...                   ");
	    CursorOff();
	    getch();
		limpia();
		menu();
  	}
  	
  	else{
  		fclose(pa);
    	gotoxy(4,22);printf("Cliente NO registrado. Presione una tecla para volver... ");
    	CursorOff();
		getch();
		limpia();
		menu();
	}
	
	

}
void Cliente::eliminar(){ 
	Cliente nuevo, lista[50];
  	char dni[15];
  	char r;
  	int encontro=1,linea,i,ultimo;
  	FILE *pa, *pa2;
  	limpia();
  	
	if ((pa = fopen("Archivo Binario", "a+b"))== NULL){ 
		printf("No se puede abrir el archivo.\n");
		return;
    }
    
  	rewind(pa); i=0;
  	while(!feof(pa)){ 
		if(fread(&nuevo, sizeof(Cliente), 1, pa)){
	 		lista[i]=nuevo;
	 		i++;
		}
  	}
  	
  	fclose(pa);
 
  	//proceso de busqueda de la informaci¢n
  	gotoxy(4,8);printf("ELIMINAR DATOS");
  	gotoxy(4,10);
  	fflush(stdin);
  	printf("Ingrese Numero De DNI: "); gets(dni);
  	ultimo=i-1;
  	i=0;
  	
	while (i<=ultimo && encontro){ 
		if (strcmp(lista[i].dni,dni)==0) 
			encontro=0;
    	else 
			i++;
  	}
  	
  	if (i<=ultimo){
    	limpia();
	    gotoxy(4,8);printf("ELIMINAR DATOS");
	    gotoxy(4,10);printf("1. Nombre:                 %s\n",lista[i].nombre);
	    gotoxy(4,12);printf("2. DNI:                    %s\n",lista[i].dni);
	    gotoxy(4,14);printf("3. Telefono:               %s\n",lista[i].telefono);
	    gotoxy(4,16);printf("4. Ciudad:                 %s\n",lista[i].ciudad);
		
		do{	
			CursorOff();
			gotoxy(4,22); printf("¨Desea Eliminarlo? Si[s] / No[n]: ");
			r=getch();
		}while(r!='S' && r!='s' && r!='N' && r!='n');
	    
	    
		if (r=='s' || r=='S'){ 
			while (i<ultimo) {
			    lista[i]=lista[i+1];
			    i++;
			}
		
			ultimo=i-1;
			
			if (((pa = fopen("Archivo Binario", "wb"))== NULL) || ((pa2 = fopen("Archivo Datos", "wb"))== NULL)) 
	     	{ 
				printf("No se puede abrir el archivo.\n");
				return;
	      	}
			
			i=0;
			
			while(i<=ultimo){
				fwrite(&lista[i], sizeof(Cliente), 1, pa);
				fprintf(pa2, "%s %s %s %s\n", lista[i].nombre, lista[i].dni, lista[i].telefono, lista[i].ciudad);
			  	i++;
			}
			
			fclose(pa);
			fclose(pa2);
			gotoxy(4,22); printf("                                        ");
			gotoxy(4,22);printf("Cliente Eliminado. Presione una tecla para volver..");
			CursorOff();
			getch();
			limpia();
			menu();
	    }
	    
	    else{
	    	gotoxy(4,22); printf("                                    ");
			gotoxy(4,22);printf("Cliente NO Eliminado. Presione una tecla para volver..");
			CursorOff();
			getch();
			limpia();
			menu();
		}
  	}
  	
  	else{ 
		gotoxy(4,22);printf("Cliente NO Registrado. Presione una tecla para volver..");
    	CursorOff();
    	getch();
		limpia();
		menu();
  	}
  	
}



// FUNCION CONSULTAR: REALIZA LA CONSULTA DEL CLIENTE, SE INGRESA EL DNI , Y ESTE NOS MUESTRA TODA LA INFORMACION DEL CLIENTE
void Cliente::consultar(){ 
	Cliente nuevo, lista[50];
  	char dni[15];
  	int encontro=1,linea,i,ultimo;
  	FILE *pa;
  	limpia();
  	if ((pa = fopen("Archivo Binario", "a+b"))== NULL)
      { printf("No se puede abrir el archivo.\n");
	return;
      }
  	rewind(pa); i=0;
  	while(!feof(pa))
  	{ if(fread(&nuevo, sizeof(Cliente), 1, pa)){
	 lista[i]=nuevo;
	 i++;
	 }
  	}
  	fclose(pa);
 

  	//proceso de busqueda de la informaci¢n
  	gotoxy(4,8);printf("CONSULTA DE CLIENTES");
  	gotoxy(4,10);
  	fflush(stdin);
  	printf("Ingrese Numero De DNI: ");gets(dni);
  	ultimo=i-1;
  	i=0;
  	while (i<=ultimo && encontro)
  	{	 if (strcmp(lista[i].dni,dni)==0) encontro=0;
    	else i++;
  	}
  	if (i<=ultimo)
  	{
    	limpia();
	    gotoxy(4,8);printf("CONSULTA DE CLIENTES");
	    gotoxy(4,10);printf("1. Nombre:                 %s\n",lista[i].nombre);
	    gotoxy(4,12);printf("2. DNI:                    %s\n",lista[i].dni);
	    gotoxy(4,14);printf("3. Telefono:               %s\n",lista[i].telefono);
	    gotoxy(4,16);printf("4. Ciudad:                 %s\n",lista[i].ciudad);
	
	    gotoxy(4,22);printf("Presione una tecla para volver...                   ");
	    CursorOff();
	    getch();
		limpia();
		menu();
  	}
  	else
  	{ 
    	gotoxy(4,22);printf("Usuario NO registrado. Presione una tecla para volver... ");
    	CursorOff();
    	getch();
		limpia();
		menu();
  	}
  	
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


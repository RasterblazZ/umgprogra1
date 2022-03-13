#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

fstream archivo;

string nombre;
string carne;
string correo;
string seccion;
int ciclo;
char estado;
float promedio;


void leerArchivo()
{
     archivo.open("datos.txt",ios::in);
     if(archivo.is_open()){

          while (!archivo.eof())
          {
               archivo>>nombre>>carne>>correo>>seccion>>ciclo>>estado>>promedio; //orden en el cual seran leidos los datos.
               if (!archivo.eof()) //Si no se a llegado al final del archivo que muestre el registro
               {
               cout<<"........Registro........\n";
               cout<<"Nombre: "<<nombre<<endl;
               cout<<"Carne: "<<carne<<endl;
               cout<<"Correo: "<<correo<<endl;
               cout<<"Seccion: "<<seccion<<endl;
               cout<<"Ciclo Escolar: "<<ciclo<<endl;
               cout<<"Estado: "<<estado<<endl;
               cout<<"Promedio: "<<promedio<<endl;
               }
          }
          archivo.close();
     }
     else{
          cout<<"El archivo no existe.Se creara uno nuevo...";
          archivo.open("datos.txt",ios::out);
     }
}

void escribirArchivo(){
     archivo.open("datos.txt",ios::out|ios::app);
     if(archivo.is_open()){
          cout<<"Ingrese los dato que se le solicitan a continuacion:\n";
          cout<<"Nombre:\n";
          cin>>nombre;
          archivo<<nombre<<" ";
          cout<<"Carne:\n";
          cin>>carne;
          archivo<<carne<<" ";
          cout<<"Correo:\n";
          cin>>correo;
          archivo<<correo<<" ";
          cout<<"Seccion:\n";
          cin>>seccion;
          archivo<<seccion<<" ";
          cout<<"Ciclo Escolar:\n";
          cin>>ciclo;
          archivo<<ciclo<<" ";
          cout<<"Estado:\n";
          cin>>estado;
          archivo<<estado<<" ";
          cout<<"Promedio:\n";
          cin>>promedio;
          archivo<<promedio<<"\n";
          archivo.close();
     }
     else{
          cout<<"El archivo no existe!";
     }
}

void modificarAlumno(){
     string carneUser;
     char estadoUser;
     float promedioUser;
     cout<<"Ingrese un carne\n";
     cin>>carneUser;

     archivo.open("datos.txt",ios::out|ios::in);
     if(archivo.is_open()){

          while (!archivo.eof())
          {
               archivo>>nombre>>carne>>correo>>seccion>>ciclo>>estado>>promedio; //orden en el cual seran leidos los datos.
               if (!archivo.eof()) //Si no se a llegado al final del archivo que muestre el registro
               {
                    if (carne == carneUser)
                    {
                         cout<<"........Registro........\n";
                         cout<<"Nombre: "<<nombre<<endl;
                         cout<<"Carne: "<<carne<<endl;
                         cout<<"Correo: "<<correo<<endl;
                         cout<<"Seccion: "<<seccion<<endl;
                         cout<<"Ciclo Escolar: "<<ciclo<<endl;
                         cout<<"Estado: "<<estado<<endl;
                         cout<<"Promedio: "<<promedio<<endl;

                         cout<<"Ingrese el estado (R/A) :\n"; 
                         cin>>estadoUser;
                         estado=estadoUser;
                         
                         cout<<"Ingrese el promedio (0.00f) :\n"; 
                         cin>>promedioUser;
                         promedio=promedioUser;
                         
                         archivo>>nombre>>carne>>correo>>seccion>>ciclo>>estadoUser>>promedioUser;
                         break;
                    }else{
                         continue;
                    }
               }
          }
          archivo.close();
     }
     else{
          cout<<"El archivo no existe.Se creara uno nuevo...";
          archivo.open("datos.txt",ios::out);
     }
}

void buscarPersona(){
     string carneUser;
     cout<<"Ingrese un carne";
     cin>>carneUser;

     archivo.open("datos.txt",ios::in);
     if(archivo.is_open()){

          while (!archivo.eof())
          {
               archivo>>nombre>>carne>>correo>>seccion>>ciclo>>estado>>promedio; //orden en el cual seran leidos los datos.
               if (!archivo.eof()) //Si no se a llegado al final del archivo que muestre el registro
               {
                    if (carne == carneUser)
                    {
                         cout<<"........Registro........\n";
                         cout<<"Nombre: "<<nombre<<endl;
                         cout<<"Carne: "<<carne<<endl;
                         cout<<"Correo: "<<correo<<endl;
                         cout<<"Seccion: "<<seccion<<endl;
                         cout<<"Ciclo Escolar: "<<ciclo<<endl;
                         cout<<"Estado: "<<estado<<endl;
                         cout<<"Promedio: "<<promedio<<endl;
                    }else{
                         continue;
                    }
               }
          }
          archivo.close();
     }
     else{
          cout<<"El archivo no existe.Se creara uno nuevo...";
          archivo.open("datos.txt",ios::out);
     }
}




int main(){
     int continuar = 0;
     while (true)
     {
     
     int opcion = 0;
     Regresar:
     cout<<"\nQue desea hacer a continuacion!!\n";
     cout<<"1 - Agregar alumno\n";
     cout<<"2 - Buscar a un alumno\n";
     cout<<"3 - Modificar los datos de un Alumno\n";
     cout<<"4 - Ver todos los registros\n"; //Listo
     cout<<"5 - Salir\n"; //Listo
     cout<<"Ingrese una opcion del 1 al 5: ";
     cin>>opcion;
     
     switch (opcion)
     {
     case 1:
        cout<<"Selecciono Agregar alumno\n";
        escribirArchivo();
        break;

     case 2:
        cout<<"Selecciono Buscar alumno\n";
        buscarPersona();
        break;

     case 3:
        cout<<"Selecciono Modificar los datos de un Alumno\n";
        modificarAlumno();
        break;

     case 4:
        cout<<"Selecciono ver todos los registros\n";
        leerArchivo();
        goto Regresar;
        break;

     case 5:
        cout<<"Selecciono Salir del programa!!\n";
        cout<<"Saliendo del programa.....\n";
        system ("pause");
        return 0;
        break; 
     
     default:
          break;
     }
     cout<<"Para continuar ingrese el numero 1: \n";
     cin>>continuar;
     if(continuar!=1){
          break;
     }
     }
     system("pause");
     return 0;
}


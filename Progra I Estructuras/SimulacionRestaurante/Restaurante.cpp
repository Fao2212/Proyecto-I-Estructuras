#include "Restaurante.h"
#include "QtDebug"
#include "Mesa.h"
#include "ListaSimple.cpp"
#include "EntradaRestaurante.h"
#include "TablaPlatos.h"
#include "CocinaEnsaladas.h"
#include "CocinaPostres.h"
#include "CocinaPrincipal.h"
#include "Caja.h"
#include "Lavadero.h"
#include "Menu.h"
#include "Mesero.h"
#include "QDebug"
#include "Cajero.h"
#include "Cocinero.h"
#include "Plato.h"
#include "Lavaplatos.h"



void Restaurante :: crearMatriz(){

   int mesas = this->cantidadDeMesas;
   for(int i =0;i < mesas;i++){
       int * coordenadas = getDisponible();
       if(coordenadas != nullptr)
           this->consecutivoDeMesa += 1;
           matriz[coordenadas[0]][coordenadas[1]] = new Mesa(this->consecutivoDeMesa);
   }
}

 int * Restaurante :: getDisponible(){//devuelve un par disponible para asignar a la matriz
     static int coordenadas[2] = {0};
     for(int i = 0;i <5;i++){
         for(int j = 0;j<4;j++){
             if(matriz[i][j]==nullptr){
                 coordenadas[0] = i;
                 coordenadas[1] = j;
                 return coordenadas;
             }
         }
     }
     return nullptr;
 }

Restaurante:: Restaurante(int cantidadDeMesas,int cantidadDeMeseros,QString nombre,int tiempoDeGeneracionMinimo
                                    ,int tiempoDeGeneracionMaximo,int tiempoMinimoEntrada, int tiempoMaximoEntrada,int probabildadEntrada
                                    ,int tiempoMinimoPrincipal,int tiempoMaximoPrincipal, int probabilidadPrincipal
                                    ,int tiempoMinimoPostre,int tiempoMaximoPostre,int probabilidadPostre){
     this->consecutivoDeMesa = 0;
     this->cantidadDeMesas = cantidadDeMesas;
     this->cantidadDeMeseros = cantidadDeMeseros;
     this->tiempoDeGeneracionMinimo = tiempoDeGeneracionMinimo;
     this->tiempoDeGeneracionMaximo = tiempoDeGeneracionMaximo;
     this->tiempoMinimoPostre = tiempoMinimoPostre;
     this->tiempoMaximoPostre = tiempoMaximoPostre;
     this-> tiempoMaximoEntrada = tiempoMaximoEntrada;
     this-> tiempoMinimoEntrada = tiempoMinimoEntrada;
     this->tiempoMaximoPrincipal =tiempoMaximoPrincipal;
     this->tiempoMinimoPrincipal = tiempoMinimoPrincipal;
     this->probabilidadPrincipal = probabilidadPrincipal;
     this->probabildadEntrada = probabildadEntrada;
     this->probabilidadPostre = probabilidadPostre;
     this->nombre = nombre;
     qDebug()<<"Creando matriz";
     crearMatriz();
     qDebug()<<"Matriz creada";
     copiarMatriz(matriz);
     this->entrada = new EntradaDelRestaurante(6,this->tiempoDeGeneracionMinimo,this->tiempoDeGeneracionMaximo,
                                               this->matriz,this->cantidadDeMesas);
     this->meseros = new ListaSimple<Mesero>();
     //Falta crear el menu puedo cambiar la lista simple por una circular
     this->tabla = new TablaPlatos(this->tiempoMinimoEntrada,this->tiempoMaximoEntrada,this->probabildadEntrada
                                   ,this->tiempoMinimoPrincipal,this->tiempoMaximoPrincipal,this->probabilidadPrincipal
                                   ,this->tiempoMinimoPostre,this->tiempoMaximoPostre,this->probabilidadPostre);
     this->cocinaEntradas = new CocinaEnsaladas();
     this->cocinaPostres = new CocinaPostres();
     this->cocinaPrincipal = new CocinaPrincipal();
     this->lavadero = new Lavadero();
     this->caja = new Caja();
     this->menu = new Menu();
     qDebug()<<"Creando meseros";
     setMeseros();
     qDebug()<<"Meseros creados";
     qDebug()<<"Asignando mesas";
     setMesasMeseros();
     qDebug()<<"Mesas asignadas";
 }//Si se quiere hacer un init default llamar la funcion con valores default

 void Restaurante :: setMeseros(){
     for(int i = 0; i<cantidadDeMeseros;i++){
         meseros->insertar(new Mesero(cocinaPrincipal,cocinaEntradas,cocinaPostres,tiempoServicioMesero));
     }
 }

 void Restaurante :: setMesasMeseros(){
    int repartir = cantidadDeMesas/cantidadDeMeseros;
    Nodo<Mesero> * temp = meseros->primerNodo;
    int i = 0;
    int j = 0 ;
    while(temp != nullptr){
        while(i<repartir && j<cantidadDeMesas){
            temp->dato.mesasAsignadas[i] = mesas[j];//CAMBIAR
            i++;
            j++;
        }
        temp->dato.numeroMesasAsignadas = i;
        i = 0;
        temp = temp->siguiente;
    }
 }

 void Restaurante :: copiarMatriz(Mesa * matriz[5][4]){
     for(int i = 0;i<5;i++){
         for(int j = 0;j<4;j++){
             if(matriz[i][j]!=nullptr)
                 this->mesas[i] = matriz[i][j];
         }
     }
 }
//REVISAR TODOS LOS CONSTRUCTORES ESTRUCTURAS Y HACER MENU

 void Restaurante :: cambiarTiempoMesero(Mesero * mesero,int tiempo){
     mesero->tiempoDeServido = tiempo;
 }

 void Restaurante :: cambiarTiempoCajero(Cajero * cajero,int tiempo){
     cajero->tiempo = tiempo;
 }

 void Restaurante :: cambiarTiempoCocinero(Cocinero * cocinero,int tiempo){
     cocinero->tiempo = tiempo;
 }

 void Restaurante :: cambiarTiempoLavaplatos(Lavaplatos * lavaplatos,int tiempo){
     lavaplatos->tiempo = tiempo;
 }

 void Restaurante :: cambiarTiempoPreparacionPlato(Plato * plato, int tiempo){
     plato->tiempoDePreparacion = tiempo;
 }

#include "Restaurante.h"
#include "QtDebug"
#include "Mesa.h"
#include "ListaSimple.h"
#include "EntradaRestaurante.h"
#include "TablaPlatos.h"
#include "Cocina.h"
#include "Caja.h"
#include "Lavadero.h"
#include "Menu.h"
#include "Mesero.h"
#include "QDebug"
#include "Cajero.h"
#include "Cocinero.h"
#include "Plato.h"
#include "Lavaplatos.h"
#include "qlistwidget.h"
#include "Globals.h"







void Restaurante :: crearMatriz(){

   int mesas = this->cantidadDeMesas;
   for(int i =0;i < mesas;i++){
       int * coordenadas = getDisponible();
       if(coordenadas != nullptr){
           this->consecutivoDeMesa += 1;
           matriz[coordenadas[0]][coordenadas[1]] = new Mesa(this->consecutivoDeMesa);
       }
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
                                 ,int tiempoMinimoPostre,int tiempoMaximoPostre,int probabilidadPostre,int tiempoServicioMesero,
                          ColaMensajes * mensajes){

    this->mensajes = mensajes;
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
    this->tiempoServicioMesero = tiempoServicioMesero;
     this->probabilidadPostre = probabilidadPostre;
     this->nombre = nombre;
     qDebug()<<"Creando matriz";
     crearMatriz();
     qDebug()<<"Matriz creada";
     copiarMatriz(matriz);
     this->entrada = new EntradaDelRestaurante(6,this->tiempoDeGeneracionMinimo,this->tiempoDeGeneracionMaximo,
                                               this->matriz,this->cantidadDeMesas);
     this->meseros = new ListaSimple<Mesero>();
     this->threadsMeseros = new ListaSimple<ThreadMesero>();
     this->tabla = new TablaPlatos(this->tiempoMinimoEntrada,this->tiempoMaximoEntrada,this->probabildadEntrada
                                   ,this->tiempoMinimoPrincipal,this->tiempoMaximoPrincipal,this->probabilidadPrincipal
                                   ,this->tiempoMinimoPostre,this->tiempoMaximoPostre,this->probabilidadPostre);
     tablaglobal = this->tabla;
     this->cocinaEntradas = new Cocina(ENSALADAS);
     this->cocinaPostres = new Cocina(POSTRES);
     this->cocinaPrincipal = new Cocina(PRINCIPAL);
     this->cocineros[0] = cocinaEntradas->cocineros[0];
     this->cocineros[1] = cocinaPrincipal->cocineros[0];
     this->cocineros[2] = cocinaPrincipal->cocineros[1];
     this->cocineros[3] = cocinaPrincipal->cocineros[2];
     this->cocineros[4] = cocinaPostres->cocineros[0];
     this->lavadero = new Lavadero();
     this->caja = new Caja();
     this->menu = new Menu();
     cargarMenu();
     menuglobal = this->menu;
     qDebug()<<"Creando meseros";
     setMeseros();
     qDebug()<<"Meseros creados";
     qDebug()<<"Asignando mesas";
     setMesasMeseros();
     qDebug()<<"Mesas asignadas";
 }//Si se quiere hacer un init default llamar la funcion con valores default

 void Restaurante :: setMeseros(){
     for(int i = 0; i<cantidadDeMeseros;i++){
         Mesero * mesero = new Mesero(cocinaPrincipal,cocinaEntradas,cocinaPostres,tiempoServicioMesero);
         mesero->id = i+1;
         meseros->insertar(mesero);
         ThreadMesero * threadMesero = new ThreadMesero();
         threadMesero->__init__(mesero,&mutexEntrada,this->mensajes);
         this->threadsMeseros->insertar(threadMesero);
     }
 }

 void Restaurante :: setMesasMeseros(){
    int repartir = cantidadDeMesas/cantidadDeMeseros;
    Nodo<Mesero> * temp = meseros->primerNodo;
    Nodo<Mesero> * aux = temp;
    int i = 0;
    int j = 0 ;
    while(temp != nullptr){
        while(i<repartir && j<cantidadDeMesas){
            temp->dato->mesasAsignadas[i] = mesas[j];//CAMBIAR
            i++;
            j++;
        }
        temp->dato->numeroMesasAsignadas = i;
        i = 0;
        aux = temp;
        temp = temp->siguiente;
    }
    if(cantidadDeMesas%cantidadDeMeseros != 0){
        aux->dato->mesasAsignadas[repartir] = mesas[cantidadDeMesas-1];
        aux->dato->numeroMesasAsignadas += 1;
    }
 }

 void Restaurante :: copiarMatriz(Mesa * matriz[5][4]){
     int k = 0;
     for(int i = 0;i<5;i++){
         for(int j = 0;j<4;j++){
             if(matriz[i][j]!=nullptr){
                 this->mesas[k] = matriz[i][j];
                 k ++;
                }
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

 void Restaurante :: cambiarTiempoPreparacionPlato(Plato * plato, int tiempo){
     plato->tiempoDePreparacion = tiempo;
 }

 void Restaurante :: iniciarThreadMeseros(QListWidget * log){
     qDebug()<<"Inicializando meseros";
     Nodo<ThreadMesero> * temp = threadsMeseros->primerNodo;
     for (int i =0;i < cantidadDeMeseros;i++) {
         temp->dato->log = log;
         temp->dato->start();
         qDebug()<<"Mesero # "+QString::number(i+1)+" inicializado.";
         temp = temp->siguiente;
     }
 }

 void Restaurante ::iniciarThreadCocineros(QListWidget *log){
     qDebug()<<"Inicializando cocineros";
     for (int i =0;i < 5;i++) {
         threadCocineros[i] = new ThreadCocinero();
         threadCocineros[i]->__init__(cocineros[i],log,&mutexEntrada);
         threadCocineros[i]->log = log;
         threadCocineros[i]->start();
         qDebug()<<"Cocinero # "+QString::number(i+1)+" inicializado.";
     }
}

 void Restaurante :: cargarMenu(){

 }

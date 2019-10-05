#include "Menu.h"
#include "ListaDoble.h"
#include "Random.h"
#include "Nodo.h"
#include "Plato.h"
#include "ListaSimple.h"

//Se crea una lista simple con el nombre Menu y se cargar aca todos los platos
Menu :: Menu(){
    menu = new ListaDoble<Plato>();
    menuDefault();
    imprimirPlatos();
}

    Plato * Menu :: platoAlAzar(Tipo tipo){

        NodoD<Plato> * temp3 = nullptr;
        int repeticiones = Random::RandomRange(10,20);
        int i = 0;
        while(i < repeticiones){
            NodoD<Plato> * temp1 = menu->primerNodo;
            NodoD<Plato> * temp2 = menu->ultimoNodo;

            while(temp1 != nullptr){
                if(temp1->dato->tipo == tipo)
                    temp3 = temp1;
                temp1 = temp1->siguiente;
                i++;
            }
            while(temp2 != nullptr){
                if(temp2->dato->tipo == tipo)
                    temp3 = temp2;
                temp2 = temp2->anterior;
                i++;
            }
        }
        return temp3->dato;
    }

    void Menu :: menuDefault(){
        ListaSimple<QString> * listapollo = new ListaSimple<QString>();
        ListaSimple<QString> * listahelado = new ListaSimple<QString>();
        ListaSimple<QString> * listalangosta = new ListaSimple<QString>();
        ListaSimple<QString> * listapasta = new ListaSimple<QString>();
        ListaSimple<QString> * listatiramisu = new ListaSimple<QString>();
        ListaSimple<QString> * listapapa = new ListaSimple<QString>();
        ListaSimple<QString> * listaaro = new ListaSimple<QString>();
        ListaSimple<QString> * listapescado = new ListaSimple<QString>();
        ListaSimple<QString> * listapavo = new ListaSimple<QString>();
        ListaSimple<QString> * listacheese = new ListaSimple<QString>();
        ListaSimple<QString> * listacafe = new ListaSimple<QString>();
        ListaSimple<QString> * listaensalada = new ListaSimple<QString>();
        ListaSimple<QString> * listalasagna = new ListaSimple<QString>();
        ListaSimple<QString> * listamango = new ListaSimple<QString>();
        ListaSimple<QString> * listaqueso = new ListaSimple<QString>();
        ListaSimple<QString> * listatacos = new ListaSimple<QString>();
        ListaSimple<QString> * listaham = new ListaSimple<QString>();
        ListaSimple<QString> * listaasado = new ListaSimple<QString>();
        Plato * p1 = new Plato("Pollo Frito",PLATO,13,4,3500,listapollo);
        Plato * p2= new Plato("Helado De Chocolate",POSTRE,3,6,1800,listahelado);
        Plato * p3= new Plato("Langosta",PLATO,20,5,7600,listalangosta);
        Plato * p4= new Plato("Pasta",PLATO,10,7,3000,listapasta);
        Plato * p5= new Plato("Tiramisu",POSTRE,9,7,2000,listatiramisu);
        Plato * p6= new Plato("Papas Fritas",ENTRADA,6,2,1750,listapapa);
        Plato * p7= new Plato("Aros de Cebolla",ENTRADA,6,2,1850,listaaro);
        Plato * p9= new Plato("Pescado al Horno",PLATO,16,5,3300,listapescado);
        Plato * p8= new Plato("Pavo",PLATO,19,7,4500,listapavo);
        Plato * p10= new Plato("Cheesecake",POSTRE,10,4,2500,listacheese);
        Plato * p11= new Plato("Cafe",ENTRADA,2,2,800,listacafe);
        Plato * p12= new Plato("Ensalada Cesar",ENTRADA,7,5,2750,listaensalada);
        Plato * p13= new Plato("Lasagna",PLATO,15,8,3800,listalasagna);
        Plato * p14= new Plato("Postre de mango",POSTRE,11,8,1200,listamango);
        Plato * p15= new Plato("Queso frito",ENTRADA,5,2,1600,listaqueso);
        Plato * p16= new Plato("Tacos",PLATO,10,6,2800,listatacos);
        Plato * p17= new Plato("Hamburguesa",ENTRADA,14,4,3000,listaham);
        Plato * p18= new Plato("Asado",PLATO,21,4,10000,listaasado);
        menu->insertar(p1);menu->insertar(p2);menu->insertar(p3);menu->insertar(p4);menu->insertar(p5);
        menu->insertar(p6);menu->insertar(p7);menu->insertar(p8);menu->insertar(p9);menu->insertar(p10);
        menu->insertar(p11);menu->insertar(p12);menu->insertar(p13);menu->insertar(p14);menu->insertar(p15);
        menu->insertar(p16);menu->insertar(p17);menu->insertar(p18);
    }
    void Menu :: imprimirPlatos(){
        NodoD<Plato> * temp = menu->ultimoNodo;
        while (temp != nullptr) {
            qDebug()<<temp->dato->nombre;
            temp = temp->anterior;
        }
    }

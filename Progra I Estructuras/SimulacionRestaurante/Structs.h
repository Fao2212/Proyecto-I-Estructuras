#ifndef STRUCTS_H
#define STRUCTS_H

struct Bitacora;
struct Caja;
struct Cajero;
struct Cliente;
struct CocinaEnsaladas;
struct CocinaPostres;
struct CocinaPrincipal;
struct Cocinero;
template<typename T>
struct Cola;
struct Cuenta;
struct EntradaDelRestaurante;
struct Estado;
struct GrupoDeClientes;
struct Ingrediente;
struct Lavadero;
struct Lavaplatos;
template<typename T>
struct ListaSimple;
struct mainwindow;
struct Menu;
struct Mesa;
struct Mesero;
template<typename T>
struct Nodo;
struct Peticion;
template<typename T>
struct Pila;
struct Plato;
struct Random;
struct Restaurante;
struct TablaPlatos;
enum Tipo{
    ENTRADA,PLATO,POSTRE
};
enum Fase : int{

     CREADA,PEDIRENTRADA,COCINAENTRADA,COCINANDOENTRADA
    ,ENTRADATERMINADA,ENTREGAENTRADA,COMIENDOENTRADA
    ,LAVADAENTRADA,PEDIDAPRINCIPAL,COCINAPRINCIPAL,COCINANDOPRINCIPAL
    ,PRINCIPALTERMINADA,ENTREGAPRINCIPAL,COMIENDOPRINCIPAL
    ,LAVARPRINCIPAL,PEDIRPOSTRE,COCINAPOSTRE,COCINANDOPOSTRE
    ,POSTRETERMINADO,ENTREGAPOSTRE,COMIENDOPOSTRE,COBROCUENTA
    ,LAVARPOSTRE,CUENTAACAJA
};


#endif // STRUCTS_H

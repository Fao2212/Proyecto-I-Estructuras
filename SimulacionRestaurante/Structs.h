#ifndef STRUCTS_H
#define STRUCTS_H

struct Bitacora;
struct Caja;
struct Cajero;
struct Cliente;
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
struct Mensaje;
struct ColaMensajes;
struct Restaurante;
struct TablaPlatos;
template<typename T>
struct ListaDoble;
struct Cocina;
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
enum TipoDeCocina{
    ENSALADAS,PRINCIPAL,POSTRES
};
enum ColorTexto{
    COLORMESERO,COLORENTRADA,COLORCOCINERO,COLORCAJERO,COLORLAVAPLATOS,COLORCLIENTE,COLORDEFAULT
};


#endif // STRUCTS_H

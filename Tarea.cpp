//Programa para determinar la relación entre dos rectas y/o el punto de interseccion entre ellas
//Andrés Gómez CODIGO 2154714 David Felipe Sandoval Granados cod 2142786
//Versión 1.0

//incluir librerias
#include <iostream>
#include <stdlib.h>
using namespace std;
float pidex();//funcion para pedir un valor x
float pidey();//funcion para pedir un valor y
void paralelas(float m1,float m2);//funcion para determinar si son paralelas
void perpendiculares(float m1,float m2);//funcion para determinar si son perpendiculares
void interseccion(float m1,float m2,float b1,float b2);//funcion para hallar el punto de interseccion
//clases
class Punto{//clase punto
  protected: //atributos

    float x1;
    float y1;
    float x2;
    float y2;
  public: //métodos
    Punto(float,float,float,float);//constructor del punto

};
class Recta : public Punto{//clase Recta
  protected: //atributos
    float m;
    float b;
  public:
    Recta(float,float,float,float);//constructor
    float getm();//getter de la pendiente
    float getb();//getter del corte en y
    void show();//mostrar la ecuacion de larecta
};

Punto::Punto(float _x,float _y,float _w, float _z){
    x1=_x;
    y1=_y;
    x2=_w;
    y2=_z;
}
Recta::Recta(float _x,float _y,float _w, float _z):Punto(_x,_y,_w,_z){//constructor de la recta
  if (x2-x1!=0){
  m=((y2) - (y1))/((x2) - (x1));//halla el valor de la pendiente
  b=(-(m)*(x1))+ (y1);//halla el valor del corte en y
  }
  else{
    cout<<"No se puede dividir entre cero, cambie sus valores e inténtelo nuevamente"<<endl;
    exit(0);
  }
}

float Recta::getm(){//retorna la pendiente
  return m;
}

float Recta::getb(){// retorna el corte en y
  return b;
}
void Recta::show(){ //muestra la recta ingresada
  cout<<"La recta ingresada es: y = "<< m <<" x + "<< b << endl;
}
//principal
int main(){
  float x1,y1,x2,y2;//variables para guardar los datos que se piden
  cout<<"Ingrese los datos del primer punto"<<endl;//se piden los datos del primer punto
  x1=pidex();
  y1=pidey();
  cout<<"Ingrese los datos del segundo punto"<<endl;//se piden los datos del segundo punto
  x2=pidex();
  y2=pidey();
  Recta R(x1,y1,x2,y2);
  cout<<"Ingrese los datos del primer punto"<<endl;//se piden los datos del primer punto
  x1=pidex();
  y1=pidey();
  cout<<"Ingrese los datos del segundo punto"<<endl;//se piden los datos del segundo punto
  x2=pidex();
  y2=pidey();
  Recta R2(x1,y1,x2,y2);
  R.show();//ecuacion de la primera recta
  R2.show();//ecuacion de la segunda recta
  //se imprime en pantalla lo solicitado por el usuario:
  paralelas(R.getm(),R2.getm());
  perpendiculares(R.getm(),R2.getm());
  interseccion(R.getm(),R2.getm(),R.getb(),R2.getb());
  return 0;
}

float pidex(){//pide el valor de x
    float x;
    cout<< "Ingrese el punto X: "<<endl;
    cin >> x;
    if(cin.fail()){
    cout<<"El valor ingresado no es tipo float, intentelo nuevemanete"<<endl;
    exit(0);
    }
    return x;//retorna el valor pedido
}
float pidey(){//pide el valor de y
    float y;
    cout<< "Ingrese el punto Y: "<<endl;
    cin >> y;
    if(cin.fail()){
    cout<<"El valor ingresado no es tipo float, intentelo nuevamente"<<endl;
    exit(0);
    }
    return y;//retorna el valor pedido
}
void paralelas(float m1,float m2){
    if (m1 == m2){//si las pendientes son iguales, son paralelas
    cout<< "Las rectas son paralelas"<<endl;
    }
}
void perpendiculares(float m1,float m2){
  if (m1 * m2==-1){//si el producto de cada pendiente es igual a -1 son perpendiculares
    cout<< "Las rectas son perpendiculares"<<endl;
  }
}
void interseccion(float m1,float m2,float b1,float b2){
  float x,y;
  if(m1==m2){ //si son paralelas no tienen interseccion
    cout<< "Las rectas no tienen intersección"<<endl;
  }
  else{//se obtiene el valor de la interseccion de las dos rectas dado que no son paralelas
  x=((b2-b1)/(m1-m2));// obtiene el valor de X para el punto de corte
  y=((m1*((b2-b1)/(m1-m2)))+b1);// obtiene el valor de Y para el punto de corte
  cout<<"El punto de corte en el eje X es: "<<"X= "<<x<<endl;//imprime en valor del punto en el eje x
  cout<<"El punto de corte en el eje Y es: "<<"Y= "<<y<<endl;//imprime en valor del punto en el eje y
  }
}

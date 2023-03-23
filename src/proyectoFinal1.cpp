//============================================================================
// Name        : proyectoFinal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Proyecto parqueadero
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


class Parqueadero{
protected:
   vector<Parqueadero>parqueaderos;
public:

	double calcular_valorPagar(double vhoraEntrada,double vhoraSalida,double vcategoria);
    double calcular_tiempo(double vhoraEntrada,double vhoraSalida);
    double calcular_tiempomin(double mEntrada,double mSalida);
    double calcular_categoria(double vcategoria);

};

double Parqueadero::calcular_categoria(double vcategoria){
	if(vcategoria==1){
		cout<<"A seleccionado automovil";
		return vcategoria;
	}
	if(vcategoria==2){
		cout<<"A seleccionado motocicleta ";
		return vcategoria;
	}
	else{
		cout<<"Su eleccion no es correcta";
		return vcategoria;
	}
}

double Parqueadero::calcular_tiempo(double vhoraEntrada,double vhoraSalida){
	double tiempo;
	tiempo=vhoraSalida-vhoraEntrada;
	return tiempo;
}
double Parqueadero::calcular_tiempomin(double mEntrada,double mSalida){
	double Tiempomin;
	if(mEntrada>mSalida){
		Tiempomin=(mEntrada-mSalida);
	return Tiempomin;
	}else{
		Tiempomin=(mSalida-mEntrada);
	return Tiempomin;
}
}

double Parqueadero::calcular_valorPagar(double vhoraEntrada, double vhoraSalida,double vcategoria){
	double ValorTiempoh=0;

	if(vcategoria==1){
	ValorTiempoh=2500 *calcular_tiempo(vhoraEntrada,vhoraSalida);
	   return ValorTiempoh;
	}

	if(vcategoria==2){
		ValorTiempoh=1500* calcular_tiempo(vhoraEntrada,vhoraSalida);
		return ValorTiempoh;

	}else{
		cout<<"Su eleccion no es correcta";
		return ValorTiempoh;
	}
}




class ValidarDatos {
public:
	bool validarhoraEntrada(int vhoraEntrada);
	bool validarhoraSalida(int vhoraSalida);
	bool validarminEntrada(int mEntrada);
	bool validarminSalida(int mSalida);
};
bool ValidarDatos::validarhoraEntrada(int vhoraEntrada ){
	if(vhoraEntrada >= 0 && vhoraEntrada < 24){
		return true;
	}else{
		cout<<"Falso";
		return false;

	}
}
bool ValidarDatos::validarminEntrada(int mEntrada ){
	if(mEntrada >= 0 && mEntrada < 60){
		return true;
	}else{
		cout<<"Falso";
		return false;

	}
}

bool ValidarDatos::validarhoraSalida(int vhoraSalida){
     if(vhoraSalida>=0 && vhoraSalida<24){
		return true;
	}else{
		cout<<"Falso";
		return false;

}
}
bool ValidarDatos::validarminSalida(int mSalida){
     if(mSalida>=0 && mSalida<60){
		return true;
	}else{
		cout<<"Falso";
		return false;

}
}
class Vehiculo:public Parqueadero{
protected:
	double categoria;
	string placa;
	double horaEntrada;
	double horaSalida;
	double TotalValor;
	double TotalFinal;

	vector<Vehiculo>vehiculos;
public:
    void setcategoria(double _categoria);
    void setplaca(string _placa);
	void sethoraEntrada(double _horaEntrada);
	void sethoraSalida(double _horaSalida);
	void settotalvalor(double _TotalValor);
	void settotalfinal(double _TotalFinal);
	double getcategoria();
	string getplaca();
	double gethoraEntrada();
	double gethoraSalida();
	double gettotalvalor();
	double gettotalfinal();

	void leerDatos();
};
void Vehiculo::setcategoria(double _categoria){
	categoria = _categoria;
}

double Vehiculo::getcategoria(void){
	return categoria;
}

void Vehiculo::setplaca(string _placa) {
	placa = _placa;
}

string  Vehiculo::getplaca(void) {
	return placa;
}

void Vehiculo::sethoraEntrada(double _horaEntrada) {
	horaEntrada = _horaEntrada;
}

double Vehiculo::gethoraEntrada(void) {
	return horaEntrada;
}
void Vehiculo::sethoraSalida(double _horaSalida) {
	horaSalida = _horaSalida;
}

double Vehiculo::gethoraSalida(void) {
	return horaSalida;

}
void Vehiculo::settotalvalor(double _TotalValor){
	TotalValor = _TotalValor;
}

double Vehiculo::gettotalvalor(void) {
	return TotalValor;
}
void Vehiculo::settotalfinal(double _TotalFinal) {
	TotalFinal = _TotalFinal;
}

double Vehiculo::gettotalfinal(void) {
	return TotalFinal;

}


void Vehiculo::leerDatos(){

   Vehiculo obj_vehiculo;
   double vcategoria;
   string vplaca;
   double vhoraEntrada;
   double vhoraSalida;
   double mEntrada;
   double mSalida;
   char c;
   int seguir=0;
   while(seguir==0){
   cout<< "Digite la categoria del vehiculo\n1.Automovil\n2.Motocicleta"<<endl;
   cin>>vcategoria;
   cout <<"Digite la placa del Vehiculo"<<endl;
   cin>>vplaca;
   cout<<"Digite la hora de entrada"<<endl;
   cin>>vhoraEntrada>>c>>mEntrada;
   cout<<"Digite la hora de salida"<<endl;
   cin>>vhoraSalida>>c>>mSalida;

   obj_vehiculo.setcategoria(vcategoria);
   obj_vehiculo.sethoraEntrada(vhoraEntrada);
   obj_vehiculo.sethoraSalida(vhoraSalida);
   obj_vehiculo.setplaca(vplaca);

   ValidarDatos obj_ValidarDatos;
   bool respuestahoraEntrada=obj_ValidarDatos.validarhoraEntrada(obj_vehiculo.gethoraEntrada());
   bool respuestahoraSalida=obj_ValidarDatos.validarhoraSalida(obj_vehiculo.gethoraSalida());
   if((respuestahoraEntrada) && (respuestahoraSalida)){
   vehiculos.push_back(obj_vehiculo);

   Parqueadero obj_parqueadero;
   string categorias;

   categorias=obj_parqueadero.calcular_categoria(obj_vehiculo.getcategoria());
   double tiempo;
   tiempo=obj_parqueadero.calcular_tiempo(obj_vehiculo.gethoraEntrada(),obj_vehiculo.gethoraSalida());

   double Total1;
   Total1=obj_parqueadero.calcular_valorPagar(obj_vehiculo.gethoraEntrada(),obj_vehiculo.gethoraSalida(),obj_vehiculo.getcategoria());
   obj_vehiculo.settotalvalor(obj_parqueadero.calcular_valorPagar(vhoraEntrada, vhoraSalida, vcategoria));


   cout<<categorias<<endl;
   cout<<"Su tiempo de estancia es de: "<<endl;
   cout<<tiempo<<"  horas "<<endl;
   cout<<"El valor a pagar es de: "<<endl;
   cout<<Total1<<endl;


   }else{
	   cout << "Comuniquese con el proveedor del software .....";
   }
   cout<<"Desea seguir ingresando vehiculos: 0.Si 1.No"<<endl;
   cin>>seguir;

   }
   int tam=vehiculos.size();
   int TotalPar=0;

   for(int i=0;i<tam;i++){
	   	 cout<<"Vehiculo: " << i <<endl;
 		 cout<<"Placa:"<<vehiculos[i].getplaca()<<endl;
 		 cout<<"Valor pagado:"<<vehiculos[i].calcular_valorPagar(vhoraEntrada, vhoraSalida, vcategoria)<<endl;
 		 TotalPar=+vehiculos[i].calcular_valorPagar(vhoraEntrada, vhoraSalida, vcategoria);
 		 cout<<TotalPar<<endl;

 	}


}





int main() {
        Vehiculo obj_vehiculo;
        obj_vehiculo.leerDatos();
		cout << "\nFin del programa ... ";
		return 0;











}

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	ifstream archivo("datos_pinza.txt");

	if (!archivo) {
		cout << "Error al abrir el archivo" << endl;
		return 1;
	}
	/* Arrays */

	float datos [100][3];
	int ids[100];
	float galga[100];
	float fuerza_izq[100];
	float fuerza_der[100];

	int i = 0;

	/*Lectura del archivo*/

	while (i < 100 && archivo >> ids[i] >> datos[i][0] >> datos[i][1] >> datos[i][2]) {
		galga[i] = datos[i][0];
		fuerza_izq[i] = datos[i][1];
		fuerza_der[i] = datos[i][2];

		i++;
	}

	int n=i;

	/*Muestra datos*/
	for(int j = 0; j < n; j++) {
		cout << "ID: " << ids[j]
			<< "Galga: " << galga[j]
			<< "Izq: " << fuerza_izq[j]
			<< "Der: " << fuerza_der[j] << endl;
	}
	/*Calcula medias*/
	float suma_galga = 0, suma_izq = 0, suma_der = 0;
	for (int j = 0; j < n; j++) {
		suma_galga +=galga[j];
		suma_izq += fuerza_izq[j];
		suma_der += fuerza_der[j];
	}

	float media_galga =suma_galga /n;
	float media_izq =suma_izq /n;
	float media_der = suma_der /n;

	cout << "\nMedia galga: " << media_galga << endl;
	cout << "Media fuerza izquierda: " << media_izq << endl;
	cout << "Media fuerza derecha: " << media_der << endl;

	/*Archivo de salida*/
	ofstream salida ("resultado_pinza.txt");

	salida << "RESULTADOS DEL SISTEMA DE PINZA ROBOTICA \n";

	salida << "Medias:";
	salida << "Galga = " << media_galga << endl;
	salida << "Fuerza izquierda = " << media_izq << endl;
	salida << "Fuerza derecha = " << media_der << endl;
	salida << "\n Clasificacion:\n";

	/*Evaluar estabilidad*/
	for (int j = 0; j < n; j++) {
		float diferencia = abs(fuerza_izq[j] - fuerza_der[j]);
		if (diferencia > 0.15) { 
			cout << "Estado muestra " << ids[j] << ": INESTABLE" << endl;
			salida << ids[j] << " INESTABLE\n";
		} else {
			cout << "Estado muestra " << ids[j] << ": ESTABLE" << endl;
			salida << ids[j] << " ESTABLE\n";
		}
	}
	archivo.close();
	salida.close();
	return 0;

}










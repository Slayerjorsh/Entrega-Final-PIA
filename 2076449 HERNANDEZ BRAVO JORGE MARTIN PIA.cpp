#include <iostream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int Guardar(int size);

struct Citas {
	string nombre, apellido, horatra, descrip, precio;
	string nombre_completo;
	int ID;
}total[20];

int opc;

int Menu();

void AgendarCita(int i, int opc);

int main() {
	int i = 1;
	int size = 1;

	do {
		opc = Menu();
		switch (opc) {
		case 1:
			AgendarCita(i, opc);
			i++;
			size = size + 1;
			break;
		case 2:
			cout << "Modificar Cita" << endl;
			exit(0);
			break;
		case 3: {

			cout << "Eliminar cita" << endl;
			int arr[20], tot = 20, elem, iElim, j, found = 0;

			for (int j = 1; j < i; j++) {
				cout << "Cita numero: " << total[j].ID << endl;
				cout << "Datos referentes:" << endl;
				cout << total[j].nombre_completo << endl;
				cout << total[j].descrip << endl;
				cout << total[j].horatra << endl;
				cout << total[j].precio << endl;
				cout << endl;
			}

			cout << "Ingrese el numero de cita a eliminar: \n";
			cin >> elem;

			for (iElim = 0; iElim < tot; iElim++)
			{
				if (total[iElim].ID == elem)
				{
					for (j = iElim; j < (tot - 1); j++)
						total[j] = total[j + 1];
					found = 1;


					i--;
					size = size - 1;
					tot--;
				}
			}
			if (found == 0) {
				//No lo encontro
				cout << "\nLa cita no ha sido encontrada";
			}
			else {
				//Lo encontro y lo elimino
				cout << "\nLa cita ha sido eliminada";

				//Reacomoda ID
				int IDReacomodo = 1;
				for (int j = 1; j < i; j++) {
					total[j].ID = IDReacomodo;
					++IDReacomodo;
				}
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			break;
		case 4:
			cout << "Lista de citas vigentes" << endl;
			for (int j = 1; j < i; j++) {
				cout << "Cita numero: " << total[j].ID << endl;
				cout << "Datos referentes:" << endl;
				cout << total[j].nombre_completo << endl;
				cout << total[j].descrip << endl;
				cout << total[j].horatra << endl;
				cout << total[j].precio << endl;
				cout << endl;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			exit(0);
		case 6:
			system("cls");
			cout << "Gracias por utilizar este simulador de consultorio de citas dentales, que tenga un buen dia.";
			Guardar(size);
			exit(0);
			break;
		}
	} while (opc != 5 || opc != 6);
	return 0;
}

int Menu() {
	int opc;

	cout << "\t Bienvenido(a) a este simulador de consultorio de citas dentales" << endl;
	cout << "¿Que desea hacer?\n";
	cout << "1.- Agendar cita.\n";
	cout << "2.- Modificar cita.\n";
	cout << "3.- Eliminar cita.\n";
	cout << "4.- Lista de citas vigentes.\n";
	cout << "5.- Limpiar pantalla.\n";
	cout << "6.- Salir.\n";

	cin >> opc;

	return opc;
}


void AgendarCita(int i, int opc) {
	int aux = 0;
	cout << "Numero de cita: " << i << endl;
	total[i].ID = i;
	cout << "Ingrese el nombre del paciente: " << endl;
	cin >> total[i].nombre;
	cout << "Ingrese el apellido del paciente: " << endl;
	cin >> total[i].apellido;
	cout << "Ingrese la hora de tratamiento(en formato 24h): " << endl;
	cin >> total[i].horatra;
	cout << "Ingrese la descripcion del tratamiento(en una sola palabra): " << endl;
	cin >> total[i].descrip;
	cout << "Ingrese el precio" << endl;
	cin >> total[i].precio;
	total[i].nombre_completo = total[i].nombre + " " + total[i].apellido;
	cout << "Los datos del paciente son: " << total[i].nombre_completo << "." << "\nSu hora de tratamiento es: " << total[i].horatra << "." << "\nSu descripcion de tratamiento es: " << total[i].descrip << "\nSu precio es de: " << total[i].precio << endl;
	system("pause");
	system("cls");
}


	int Guardar(int size) {

		ofstream myfile("Citas.txt");
		if (myfile.is_open())
		{
			for (int count = 1; count < size; count++) {
				myfile << "-------------------------------------- \n";
				myfile << "Cita numero: " << total[count].ID << "\n";
				myfile << "Datos referentes:" << "\n";
				myfile << "Nombre: " << total[count].nombre_completo << "\n";
				myfile << "Descripcion: " << total[count].descrip << "\n";
				myfile << "Hora: " << total[count].horatra << "\n";
				myfile << "Precio: " << total[count].precio << "\n";
				myfile << "\n";
			}
			myfile.close();
		}
		else cout << "No se pudo abrir el archivo TXT";
		return 0;

	}

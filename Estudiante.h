#pragma once
#include <main.h>
#include <iostream>
#include "Conect.h"
using namespace  std;
class Estudiante {
	// atributos
private: string estudiante;
	   // constructor
public:
	Estudiante() {}
	Estudiante(string e) {
		estudiante = e;
	}
	void setEstudiante(string e) { estudiante = e; }
	string getEstudiante() { return estudiante; }

	void crear() {
		int q_estado;
		Conexion cn = Conexion();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "INSERT INTO estudiante(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) VALUES ('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		Conexion cn = Conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de los Estudiantes ------------" << endl;
			string consulta = "select * from idEstudiante";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();


	}

	void actualizar() {
		int q_estado;
		Conexion cn = Conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Actualizar Estudiantes------------" << endl;
			string consulta = "update idEstudiante from estudiante where idEstudiante=0";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();


	}


	void eliminar() {
		int q_estado;
		Conexion cn = Conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Eliminar datos de los Estudiantes ------------" << endl;
			string consulta = "delete * from estudiante where idEstudiante=0;
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << endl;
				}

			}
			else {
				cout << " xxx Datos eliminados  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error al eliminar xxxx" << endl;
		}
		cn.cerrar_conexion();


	}
};


// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;


void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(0.2f, 0.3f, 0.0f);

	glEnd();
}

void dibujarPolygono() {
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.9f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.2f, 0.3f, 0.0f);
	glVertex3f(0.6f, -0.4f, 0.0f);
	glVertex3f(0.4f, - 0.6f, 0.0f);


	glEnd();
}
void dibujarTriangulos() {
	/*
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	*/
	//Establecemos el tipo de primitiva
	glBegin(GL_TRIANGLES);
	//Establecemos Color
	glColor3f(1.0f, 0.0f, 0.0f);
	//Enviar vertices
	glVertex3f(-0.8f, 0.8f, 0.0f);
	glVertex3f(-0.8f, -0.8f, 0.0f);
	glVertex3f(0.8f, -0.8f, 0.0f);

	glVertex3f(0.8f, 0.8f, 0.0f);
	glVertex3f(0.8f, -0.8f, 0.0f);
	glVertex3f(-0.8f, 0.8f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.01f, 0.0f);
	glVertex3f(-0.01f, -0.01f, 0.0f);
	glVertex3f(0.01f, -0.01f, 0.0f);

	//Especficar que dejaremos de dibujar.
	glEnd();
}

void dibujarLineaContinua()
{
	glBegin(GL_LINE_STRIP);
	glColor3f(0.2f, 0.3f, 1.0f);
	glVertex3f(0.1f, 0.3f, 0.0f);
	glColor3f(0.5f, 0.8f, 0.3f);
	glVertex3f(0.1f, -0.3f, 0.0f);
	glVertex3f(0.4f, -0.3f, 0.0f);

	glEnd();
}
void dibujarLineas()
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.4f, 0.6f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.4f, 0.0f);

	glVertex3f(-0.3f, 0.1f, 0.0f);
	glVertex3f(-3.0f,-0.1f,0.0f);
	glEnd();

}
void dibujar() {
	dibujarPolygono();
}

int main()
{
	//Declarar una ventana
	GLFWwindow*window;

	//Si no se pudo iniciar GLFW 
	//Terminamos ejecucion.

	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//Si se puedo iniciar GLFW
	//Inicializmos la ventana
	//Todas las funciones especificas de GLFW tienen el sufijo glfw
	window = glfwCreateWindow(600,600,"Ventana",NULL,NULL);

	//Si no pudo crear la ventana
	//Terminamos ejecucion
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vex establecido el contexto
	//Se activan las funciones "Modernas" (gpu) 

	
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version Opengl: " << versionGL;

	//Ciclo de dibujo (Draw Loop)
	while (!glfwWindowShouldClose(window))
	{
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado.
		glClearColor(1,0.8,0,1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();

		glfwSwapBuffers(window);

	}
	//Despues del ciclo de dibujo
	//Eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}


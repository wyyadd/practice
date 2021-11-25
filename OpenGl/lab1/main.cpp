#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "..\..\Common\Utils.h"
using namespace std;

#define numVAOs 12
#define numVBOs 24
#define pi 3.1415926
#define n 200

//ȫ�ֱ���
GLuint renderingProgram;
GLuint vao[numVAOs];
GLuint vbo[numVBOs];

void bindVAO(int num, float vertex[], int sizeV,  float colour[], int sizeC, GLuint& vPositionLoc, GLuint& vColorLoc) {
	//�󶨵�ǰVAO
	glBindVertexArray(vao[num]);
	// Load the data into the GPU  
	glBindBuffer(GL_ARRAY_BUFFER, vbo[2 * num]);
	glBufferData(GL_ARRAY_BUFFER, sizeV * sizeof(float), vertex, GL_STATIC_DRAW);
	//��VBO������������ɫ������Ӧ�Ķ�������
	glVertexAttribPointer(vPositionLoc, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vPositionLoc);
	// Load the data into the GPU  
	glBindBuffer(GL_ARRAY_BUFFER, vbo[2 * num + 1]);
	glBufferData(GL_ARRAY_BUFFER, sizeC * sizeof(float), colour, GL_STATIC_DRAW);
	//��VBO������������ɫ������Ӧ�Ķ�������
	glVertexAttribPointer(vColorLoc, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vColorLoc);
}

//������ɫ������ʼ������
void init(GLFWwindow* window)
{
	renderingProgram = Utils::createShaderProgram("vertShader.glsl", "fragShader.glsl");

	glGenVertexArrays(numVAOs, vao);
	glGenBuffers(numVBOs, vbo);
	GLuint vPositionLoc = glGetAttribLocation(renderingProgram, "vPosition");
	GLuint vColorLoc = glGetAttribLocation(renderingProgram, "vColor");
	///////////���౦������������//////////////
	float vertices_square[8] = {
		-0.4f, -0.6f,
		0.4f, -0.6f,
		0.4f, 0.6f,
		-0.4f, 0.6f
	};
	float color_square[16] = {
		1.0f, 1.0f, 0.0f, 1.0f,  // red
		1.0f, 1.0f, 0.0f, 1.0f,   // blue
		1.0f, 1.0f, 0.0f, 1.0f,   // blue
		1.0f, 1.0f, 0.0f, 1.0f   // green
	};
	bindVAO(0, vertices_square, 8, color_square, 16, vPositionLoc, vColorLoc);
	///////////���౦���ֱ�//////////////
	float leftHand[6] = {
		-0.4f, -0.1f,
		-0.35f, -0.15f,
		-1.0f, -0.5f
	};
	float rightHand[6] = {
		0.4f, -0.1f,
		0.35f, -0.15f,
		1.0f, -0.5f
	};
	float handColour[12] = {
		1.0f, 1.0f, 0.0f, 1.0f,  
		1.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f 
	};
	bindVAO(1, leftHand, 6, handColour, 12,  vPositionLoc, vColorLoc);
	bindVAO(2, rightHand, 6, handColour, 12, vPositionLoc, vColorLoc);
	///////////���౦����//////////////
	float leftLeg[8] = {
		-0.15f, -0.6f,
		-0.15f, -1.0f,
		-0.1f, -1.0f,
		-0.1f, -0.6f
	};
	float rightLeg[8] = {
		 0.1f, -0.6f,
		 0.1f, -1.0f,
		 0.15f, -1.0f,
		 0.15f, -0.6f
	};
	bindVAO(3, leftLeg, 8, color_square, 16, vPositionLoc, vColorLoc);
	bindVAO(4, rightLeg, 8, color_square, 16, vPositionLoc, vColorLoc);
	///////////���౦���۾�//////////////
	float deltaE = 2.0 * (float)pi / n;
	float re = 0.09;
	float rIe = 0.03;
	float leftEye[2*n];
	float leftIEye[2 * n];
	float rightEye[2*n];
	float rightIEye[2 * n];
	float eyeColour[4 * n];
	float eyeIColour[4 * n];
	for (int i = 0; i < n; ++i) {
		leftEye[2*i] = re * cos(deltaE * i) - 0.1f;
		leftEye[2*i + 1] = rightEye[2*i + 1] = re * sin(deltaE * i) + 0.3f;
		rightEye[2*i] = re * cos(deltaE * i) + 0.1f;
		leftIEye[2 * i] = rIe * cos(deltaE * i) - 0.1f;
		leftIEye[2 * i + 1] = rightIEye[2 * i + 1] = rIe * sin(deltaE * i) + 0.3f;
		rightIEye[2 * i] = rIe * cos(deltaE * i) + 0.1f;
		eyeColour[4 * i] = eyeColour[4 * i + 1] = eyeColour[4 * i + 2] = 0.0f;
		eyeColour[4 * i + 3] = 1.0f;
		eyeIColour[4 * i] = eyeIColour[4 * i + 1] = eyeIColour[4 * i + 2] = eyeIColour[4 * i + 3] = 1.0f;
	}
	bindVAO(5, leftEye, 2*n,  eyeColour, 4*n,  vPositionLoc, vColorLoc);
	bindVAO(6, rightEye, 2*n,  eyeColour, 4*n, vPositionLoc, vColorLoc);
	bindVAO(10, leftIEye, 2 * n, eyeIColour, 4 * n, vPositionLoc, vColorLoc);
	bindVAO(11, rightIEye, 2 * n, eyeIColour, 4 * n, vPositionLoc, vColorLoc);
	///////////���౦�����//////////////
	float deltaM = 2.0 * (float)pi / n;
	float rm = 0.1;
	float mouth[n];
	float mouthColour[2 * n] = { 1.0f };
	for (int i = n/2; i < n; i += 1) {
		mouth[2*i-n] = rm * cos(deltaM * i);
		mouth[2*i + 1-n] = rm * sin(deltaM * i);
	}
	bindVAO(7, mouth, n, mouthColour, 2 * n, vPositionLoc, vColorLoc);
	///////////���౦������//////////////
	float leftTooth[8] = {
		-0.05f, -0.09f,
		-0.05f, -0.15f,
		-0.01f, -0.15f,
		-0.01f, -0.10f
	};
	float rightTooth[8] = {
		0.01f, -0.10f,
		0.01f, -0.15f,
		0.05f, -0.15f,
		0.05f, -0.09f
	};
	float colorTooth[16] = {
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f 
	};
	bindVAO(8, leftTooth, 8, colorTooth, 16, vPositionLoc, vColorLoc);
	bindVAO(9, rightTooth, 8, colorTooth, 16, vPositionLoc, vColorLoc);
}

//���ƺ���
void display(GLFWwindow* window, double currentTime)
{
	glUseProgram(renderingProgram);

	glClearColor(0.23f, 0.72f, 0.47f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//���ƺ��౦������������
	glBindVertexArray(vao[0]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	//���ƺ��౦���ֱ�
	glBindVertexArray(vao[1]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(vao[2]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//���ƺ��౦����
	glBindVertexArray(vao[3]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindVertexArray(vao[4]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	//���ƺ��౦���۾�
	glBindVertexArray(vao[5]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, n);
	glBindVertexArray(vao[6]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, n);
	glBindVertexArray(vao[10]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, n);
	glBindVertexArray(vao[11]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, n);
	//���ƺ��౦�����
	glBindVertexArray(vao[7]);
	glDrawArrays(GL_LINE_STRIP, 0, n/2);
	//���ƺ��౦������
	glBindVertexArray(vao[8]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindVertexArray(vao[9]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

int main(void)
{
	//glfw��ʼ��
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//���ڰ汾
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//��������
	GLFWwindow* window = glfwCreateWindow(800, 800, "triangle and square", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)//glew��ʼ��
	{
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);

	//������ɫ���������Ͱ�VAO��VBO
	init(window);

	//�¼�ѭ��
	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
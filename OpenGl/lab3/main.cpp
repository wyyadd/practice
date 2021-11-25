#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp> // glm::value_ptr
#include <glm\gtc\matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include "Utils.h"
#include "Sphere.h"
#include "Torus.h"
using namespace std;

#define numVAOs 4
#define numVBOs 12

float cameraX, cameraY, cameraZ;
GLuint renderingProgram;
GLuint vao[numVAOs];
GLuint vbo[numVBOs];

// interact
int m_sun = 1; int m_earth = 2; int m_moon = 3;
glm::vec3 lightLoc = glm::vec3(2.0f, 2.0f, 2.0f);

// variable allocation for display
GLuint mvLoc, projLoc, nLoc;
GLuint globalAmbLoc, ambLoc, diffLoc, specLoc, posLoc, mambLoc, mdiffLoc, mspecLoc, mshiLoc;
int width, height;
float aspect;
glm::mat4 pMat, vMat, mMat, mvMat, invTrMat, rMat;
glm::vec3 currentLightPos = lightLoc, transformed;
float lightPos[3];

// white light
float globalAmbient[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
float lightAmbient[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
float lightDiffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
float lightSpecular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

// gold material
float* matAmb_gd = Utils::goldAmbient();
float* matDif_gd = Utils::goldDiffuse();
float* matSpe_gd = Utils::goldSpecular();
float matShi_gd = Utils::goldShininess();

// silver material
float* matAmb_sl = Utils::silverAmbient();
float* matDif_sl = Utils::silverDiffuse();
float* matSpe_sl = Utils::silverSpecular();
float matShi_sl = Utils::silverShininess();

// bronze material
float* matAmb_bn = Utils::bronzeAmbient();
float* matDif_bn = Utils::bronzeDiffuse();
float* matSpe_bn = Utils::bronzeSpecular();
float matShi_bn = Utils::bronzeShininess();

stack<glm::mat4> mvStack;

Sphere sun = Sphere(48);
Sphere moon = Sphere(48);
Torus earth(0.5f, 0.2f, 48);
Sphere light_source = Sphere(16);

void setupVertices(void) {
	// sun
	std::vector<int> sun_ind = sun.getIndices();
	std::vector<glm::vec3> sun_vert = sun.getVertices();
	std::vector<glm::vec3> sun_norm = sun.getNormals();
	std::vector<float> sun_pvalues;
	std::vector<float> sun_nvalues;
	int sun_numIndices = sun.getNumIndices();
	for (int i = 0; i < sun_numIndices; i++) {
		sun_pvalues.push_back((sun_vert[sun_ind[i]]).x);
		sun_pvalues.push_back((sun_vert[sun_ind[i]]).y);
		sun_pvalues.push_back((sun_vert[sun_ind[i]]).z);
		sun_nvalues.push_back((sun_norm[sun_ind[i]]).x);
		sun_nvalues.push_back((sun_norm[sun_ind[i]]).y);
		sun_nvalues.push_back((sun_norm[sun_ind[i]]).z);
	}
	// earth
	std::vector<int> earth_ind = earth.getIndices();
	std::vector<glm::vec3> vert = earth.getVertices();
	std::vector<glm::vec3> norm = earth.getNormals();
	std::vector<float> earth_pvalues;
	std::vector<float> earth_nvalues;
	for (int i = 0; i < earth.getNumVertices(); i++) {
		earth_pvalues.push_back(vert[i].x);
		earth_pvalues.push_back(vert[i].y);
		earth_pvalues.push_back(vert[i].z);
		earth_nvalues.push_back(norm[i].x);
		earth_nvalues.push_back(norm[i].y);
		earth_nvalues.push_back(norm[i].z);
	}
	// moon
	std::vector<int> moon_ind = moon.getIndices();
	std::vector<glm::vec3> moon_vert = moon.getVertices();
	std::vector<glm::vec3> moon_norm = moon.getNormals();
	std::vector<float> moon_pvalues;
	std::vector<float> moon_nvalues;
	int moon_numIndices = moon.getNumIndices();
	for (int i = 0; i < moon_numIndices; i++) {
		moon_pvalues.push_back((moon_vert[moon_ind[i]]).x);
		moon_pvalues.push_back((moon_vert[moon_ind[i]]).y);
		moon_pvalues.push_back((moon_vert[moon_ind[i]]).z);
		moon_nvalues.push_back((moon_norm[moon_ind[i]]).x);
		moon_nvalues.push_back((moon_norm[moon_ind[i]]).y);
		moon_nvalues.push_back((moon_norm[moon_ind[i]]).z);
	}
	// 光源
	std::vector<int> light_source_ind = light_source.getIndices();
	std::vector<glm::vec3> light_source_vert = light_source.getVertices();
	std::vector<glm::vec3> light_source_norm = light_source.getNormals();
	std::vector<float> light_source_pvalues;
	std::vector<float> light_source_nvalues;
	int light_source_numIndices = light_source.getNumIndices();
	for (int i = 0; i < light_source_numIndices; i++) {
	light_source_pvalues.push_back((light_source_vert[light_source_ind[i]]).x);
	light_source_pvalues.push_back((light_source_vert[light_source_ind[i]]).y);
	light_source_pvalues.push_back((light_source_vert[light_source_ind[i]]).z);
	// 因为光在球里面, 法向量相反
	light_source_nvalues.push_back(-(light_source_norm[light_source_ind[i]]).x);
	light_source_nvalues.push_back(-(light_source_norm[light_source_ind[i]]).y);
	light_source_nvalues.push_back(-(light_source_norm[light_source_ind[i]]).z);
	}
	

	glGenVertexArrays(numVAOs, vao);
	glGenBuffers(numVBOs, vbo);

	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sun_pvalues.size()*4, &sun_pvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sun_nvalues.size()*4, &sun_nvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sun_ind.size()*4, &sun_ind[0], GL_STATIC_DRAW);

	glBindVertexArray(vao[1]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
	glBufferData(GL_ARRAY_BUFFER, earth_pvalues.size()*4, &earth_pvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[4]);
	glBufferData(GL_ARRAY_BUFFER, earth_nvalues.size()*4, &earth_nvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[5]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, earth_ind.size()*4, &earth_ind[0], GL_STATIC_DRAW);

	glBindVertexArray(vao[2]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[6]);
	glBufferData(GL_ARRAY_BUFFER, moon_pvalues.size()*4, &moon_pvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[7]);
	glBufferData(GL_ARRAY_BUFFER, moon_nvalues.size()*4, &moon_nvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[8]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, moon_ind.size()*4, &moon_ind[0], GL_STATIC_DRAW);

	glBindVertexArray(vao[3]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[9]);
	glBufferData(GL_ARRAY_BUFFER, light_source_pvalues.size()*4, &light_source_pvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[10]);
	glBufferData(GL_ARRAY_BUFFER, light_source_nvalues.size()*4, &light_source_nvalues[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[11]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, light_source_ind.size()*4, &light_source_ind[0], GL_STATIC_DRAW);
}

void installLights(glm::mat4 vMatrix, int material) {
	transformed = glm::vec3(vMatrix * glm::vec4(currentLightPos, 1.0));
	lightPos[0] = transformed.x;
	lightPos[1] = transformed.y;
	lightPos[2] = transformed.z;

	// get the locations of the light and material fields in the shader
	globalAmbLoc = glGetUniformLocation(renderingProgram, "globalAmbient");
	ambLoc = glGetUniformLocation(renderingProgram, "light.ambient");
	diffLoc = glGetUniformLocation(renderingProgram, "light.diffuse");
	specLoc = glGetUniformLocation(renderingProgram, "light.specular");
	posLoc = glGetUniformLocation(renderingProgram, "light.position");
	mambLoc = glGetUniformLocation(renderingProgram, "material.ambient");
	mdiffLoc = glGetUniformLocation(renderingProgram, "material.diffuse");
	mspecLoc = glGetUniformLocation(renderingProgram, "material.specular");
	mshiLoc = glGetUniformLocation(renderingProgram, "material.shininess");

	// material
	float* matAmb; float* matDif; float* matSpe; float matShi;
	switch (material)
	{
	case 1: {
		matAmb = matAmb_bn;
		matDif = matDif_bn;
		matSpe = matSpe_bn;
		matShi = matShi_bn;
	} break;
	case 2: {
		matAmb = matAmb_sl;
		matDif = matDif_sl;
		matSpe = matSpe_sl;
		matShi = matShi_sl;
	} break;
	case 3: {
		matAmb = matAmb_gd;
		matDif = matDif_gd;
		matSpe = matSpe_gd;
		matShi = matShi_gd;
	} break;
	default: {
		matAmb = matAmb_bn;
		matDif = matDif_bn;
		matSpe = matSpe_bn;
		matShi = matShi_bn;
	}
		break;
	}
	//  set the uniform light and material values in the shader
	glProgramUniform4fv(renderingProgram, globalAmbLoc, 1, globalAmbient);
	glProgramUniform4fv(renderingProgram, ambLoc, 1, lightAmbient);
	glProgramUniform4fv(renderingProgram, diffLoc, 1, lightDiffuse);
	glProgramUniform4fv(renderingProgram, specLoc, 1, lightSpecular);
	glProgramUniform3fv(renderingProgram, posLoc, 1, lightPos);
	glProgramUniform4fv(renderingProgram, mambLoc, 1, matAmb);
	glProgramUniform4fv(renderingProgram, mdiffLoc, 1, matDif);
	glProgramUniform4fv(renderingProgram, mspecLoc, 1, matSpe);
	glProgramUniform1f(renderingProgram, mshiLoc, matShi);
}

void init(GLFWwindow* window) {
	renderingProgram = Utils::createShaderProgram("./BlinnPhongShaders/vertShader.glsl", "./BlinnPhongShaders/fragShader.glsl");

	glfwGetFramebufferSize(window, &width, &height);
	aspect = (float)width / (float)height;
	pMat = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f);

	cameraX = 0.0f; cameraY = 0.0f; cameraZ = 8.0f;
	setupVertices();
}

void display(GLFWwindow* window, double currentTime) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glUseProgram(renderingProgram);

	mvLoc = glGetUniformLocation(renderingProgram, "mv_matrix");
	projLoc = glGetUniformLocation(renderingProgram, "proj_matrix");
	nLoc = glGetUniformLocation(renderingProgram, "norm_matrix");

	vMat = glm::translate(glm::mat4(1.0f), glm::vec3(-cameraX, -cameraY, -cameraZ));
	mvStack.push(vMat);

	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(pMat));

	// rotate update light
	currentLightPos = glm::vec3(lightLoc.x, lightLoc.y, lightLoc.z);
	//rMat = rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(0.0f, 0.0f, 1.0f));
	//currentLightPos = glm::vec3(rMat * glm::vec4(currentLightPos, 1.0f));

	// --------------
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	mvStack.push(mvStack.top());
	mvStack.top() *= rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(0.0, 1.0, 0.0));
	invTrMat = glm::transpose(glm::inverse(mvStack.top()));
	glUniformMatrix4fv(nLoc, 1, GL_FALSE, glm::value_ptr(invTrMat));
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
	installLights(vMat,m_sun);
	glDrawArrays(GL_TRIANGLES, 0, sun.getNumIndices()); //绘制
	mvStack.pop(); //去除太阳自转

	//-----------------------  cube == planet  
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(sin((float)currentTime)*4.0, 0.0f, cos((float)currentTime)*4.0));
	mvStack.push(mvStack.top());
	mvStack.top() *= rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(1.0, 0.0, 0.0));
	invTrMat = glm::transpose(glm::inverse(mvStack.top()));
	glUniformMatrix4fv(nLoc, 1, GL_FALSE, glm::value_ptr(invTrMat));
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[4]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[5]);
	installLights(vMat,m_earth);
	glDrawElements(GL_TRIANGLES, earth.getNumIndices(), GL_UNSIGNED_INT, 0); //绘制
	//glDrawArrays(GL_TRIANGLES, 0, earth.getNumIndices()); //绘制
	mvStack.pop(); //去除地球自转

	//-----------------------  smaller cube == moon
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, sin((float)currentTime)*2.0, cos((float)currentTime)*2.0));
	mvStack.top() *= rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(0.0, 0.0, 1.0));
	mvStack.top() *= scale(glm::mat4(1.0f), glm::vec3(0.25f, 0.25f, 0.25f));
	invTrMat = glm::transpose(glm::inverse(mvStack.top()));
	glUniformMatrix4fv(nLoc, 1, GL_FALSE, glm::value_ptr(invTrMat));
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[6]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[7]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[8]);
	installLights(vMat,m_moon);
	glDrawArrays(GL_TRIANGLES, 0, moon.getNumIndices()); //绘制
	mvStack.pop();

	mvStack.pop(); //地球位置
	mvStack.pop(); //太阳位置

	//light source
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(lightLoc.x, lightLoc.y, lightLoc.z));
	mvStack.top() *= scale(glm::mat4(1.0f), glm::vec3(0.1f, 0.1f, 0.1f));
	invTrMat = glm::transpose(glm::inverse(mvStack.top()));
	glUniformMatrix4fv(nLoc, 1, GL_FALSE, glm::value_ptr(invTrMat));
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[9]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[10]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[11]);
	installLights(vMat,m_sun);
	glDrawArrays(GL_TRIANGLES, 0, light_source.getNumIndices()); //绘制
	mvStack.pop();

	mvStack.pop();  // the final(float)currentTime pop is for the view matrix

}

void window_size_callback(GLFWwindow* win, int newWidth, int newHeight) {
	aspect = (float)newWidth / (float)newHeight;
	glViewport(0, 0, newWidth, newHeight);
	pMat = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		cameraZ -= yoffset/3;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		switch (button)
		{
		case GLFW_MOUSE_BUTTON_LEFT: //左键按下
		{
			m_sun++;
			m_earth++;
			m_moon++;
			if (m_sun > 3)
				m_sun = 1;
			if (m_earth > 3)
				m_earth = 1;
			if (m_moon > 3)
				m_moon = 1;
		}
			break;
		case GLFW_MOUSE_BUTTON_MIDDLE: //中健按下
			break;
		case GLFW_MOUSE_BUTTON_RIGHT: //右键按下
			break;
		default:
			break;
		}
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action != GLFW_PRESS)
		return;
	switch (key)
	{
	case GLFW_KEY_W:
		lightLoc.y += 1;
		break;
	case GLFW_KEY_S:
		lightLoc.y -= 1;
		break;
	case GLFW_KEY_A:
		lightLoc.x -= 1;
		break;
	case GLFW_KEY_D:
		lightLoc.x += 1;
		break;
	case GLFW_KEY_Z:
		lightLoc.z += 1;
		break;
	case GLFW_KEY_C:
		lightLoc.z -= 1;
		break;
	default:
		break;
	}
}

int main(void) {
	if (!glfwInit()) 
	{ 
		exit(EXIT_FAILURE); 
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Stack", NULL, NULL);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) 
	{ 
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);

	glfwSetWindowSizeCallback(window, window_size_callback);
	// 滚轮z轴调整
	glfwSetScrollCallback(window, scroll_callback);
	//鼠标回调函数
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	//按键调整函数
	glfwSetKeyCallback(window, key_callback);

	init(window);

	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
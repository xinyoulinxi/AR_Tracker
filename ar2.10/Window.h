#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_
#include <glad/glad.h>
#include<glfw3.h>
#include<iostream>
class Window {
private:
	size_t width;
	size_t height;
	GLFWwindow* m_window;
	char* name;
public:
	Window(char* name="AR Window",size_t w= 800, size_t h=600);
	void SetWindowSize(size_t w,size_t h){
		width = w;
		height = h;
	}
	
	GLFWwindow* GetWindow() { return m_window; }
};

#endif
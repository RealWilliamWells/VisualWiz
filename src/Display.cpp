//
// Created by william on 19/05/23.
//

#include <iostream>
#include "Display.h"

using namespace wiz;

void Display::init() {
#ifndef __EMSCRIPTEN__
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
#endif
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Display::open(unsigned int width, unsigned int height, void (*framebufferSizeCallback)(GLFWwindow* window, int width, int height)) {
    window = glfwCreateWindow(width, height, "VisualWizTest", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        // TODO: throw window creation exception
    }
    glfwMakeContextCurrent(window);

//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetCursorPosCallback(window, osv::LookInput::mouseInputCallback);

    std::string openGLExtName = "";
#ifdef OS_SWITCH
    openGLExtName = "glad";
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
#else
    openGLExtName = "GLEW";
    if (glewInit() != GLEW_OK) {
#endif
        std::cerr << "Failed to create " << openGLExtName << std::endl;
        glfwTerminate();
        // TODO: throw glew or glad init exception
    }

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

void Display::close() {
    glfwSetWindowShouldClose(window, true);
}

void Display::update() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
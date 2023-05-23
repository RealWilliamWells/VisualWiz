//
// Created by william on 19/05/23.
//

#ifndef VISUALWIZ_DISPLAY_H
#define VISUALWIZ_DISPLAY_H

#include <memory>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace wiz {
    class Display;
}

class wiz::Display {
private:
    GLFWwindow* window;

public:
    void init();

    void open(unsigned int width, unsigned int height, void (*framebufferSizeCallback)(GLFWwindow* window, int width, int height));

    void close();

    void update();

    static void defaultFramebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
};

#endif //VISUALWIZ_DISPLAY_H

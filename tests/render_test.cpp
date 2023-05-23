//
// Created by william on 19/05/23.
//

#include <gtest/gtest.h>
#include "Display.h"

// Should be able to open window with OpenGL context
TEST(display, open_window)
{
    wiz::Display* display = new wiz::Display();

    display->init();
    display->open(1280, 720, wiz::Display::defaultFramebufferSizeCallback);

    display->close();
}


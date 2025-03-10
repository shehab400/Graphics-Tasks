// cr. code: Sumanta Guha.
/////////////////////////////////////////////////////////////////////

// a macro to include the mathematical constants
#define _USE_MATH_DEFINES

// cstdlib: a header that defines several general purpose functions (eg.  random number generation, integer arithmetics, sorting , .... )
// cmath: A Header that declares a set of functions to compute common mathematical operations and transformations (eg. trigonometric functions, exponential functions, ... )
// iostream: header file contains definitions of objects like cin, cout, ... .
#include <cstdlib>
#include <cmath>
#include <iostream>

#include <glew.h>
#include <freeglut.h>

// Globals.
static float R = 40.0; // Radius of circle.
static float X = 50.0; // X-coordinate of center of circle.
static float Y = 50.0; // Y-coordinate of center of circle.
static int numVertices = 5; // Number of vertices on circle.

// Drawing routine.
void drawScene(void)
{
    float t = 0; // Angle parameter.
    int i;

    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a line loop with vertices at equal angles apart on a circle
    // with center at (X, Y) and radius R, The vertices are colored randomly.
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVertices; ++i)
    {
        glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
        glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
        t += 2 * M_PI / numVertices;
    }
    glEnd();

    glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case '+':
        numVertices++;
        glutPostRedisplay();
        break;
    case '-':
        if (numVertices > 3) numVertices--;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    std::cout << "Interaction:" << std::endl;
    std::cout << "Press +/- to increase/decrease the number of vertices on the circle." << std::endl;
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("circle.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}

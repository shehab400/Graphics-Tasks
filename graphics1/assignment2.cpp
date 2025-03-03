//#include <glew.h>
//#include <freeglut.h>
//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//int w = 500;
//int h = 500;  // Adjusted window height
//
//// Function prototypes
//void drawleaf(int centerX, int centerY, float r = 0, int no_point = 360);
//void drawScene(void);
//void setup(void);
//void resize(int w, int h);
//void keyInput(unsigned char key, int x, int y);
//
//// Drawing routine.
//void drawScene(void)
//{
//    // Clear the buffer and set the drawing color.
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0, 1.0, 0.0);
//
//    // Draw a slightly bigger leaf-like shape.
//    drawleaf(w / 2, h / 2, 80);  // Increased radius
//
//    // Execute the drawing.
//    glFlush();
//}
//
//// Function to draw a leaf-like shape.
//// Function to draw a leaf-like shape.
//// Function to draw a leaf-like shape.
//void drawleaf(int centerX, int centerY, float r, int no_point)
//{
//    double angle;
//    glBegin(GL_LINE_STRIP);
//    float startX, endX, startY, endY;
//    int count = 0;
//    int shift = 0;
//    const int len = 70 + 70 + 50; // Increased length for the curve
//    double* arrX = new double[len];
//    double* arrY = new double[len];
//
//    for (int i = 70; i > -70; i--)
//    {
//        angle = 2 * 3.1415 * i / 360;
//        double x = centerX + r * cos(angle);
//        double y = centerY + r * sin(angle);
//        if (angle > 0)
//        {
//            double new_angle = 3.1415 - angle;
//            arrX[count] = centerX + r * cos(new_angle);
//            arrY[count] = centerY + r * sin(new_angle);
//        }
//        else
//        {
//            double new_angle = -3.1415 - angle;
//            arrX[count] = centerX + r * cos(new_angle);
//            arrY[count] = centerY + r * sin(new_angle);
//        }
//
//        if (i == 70)
//        {
//            startX = x;
//            startY = y;
//            shift = startX - arrX[0];
//            arrX[0] = x;
//            arrY[0] = y;
//        }
//        else
//            arrX[count] = arrX[count] + shift;
//        if (i == -69)
//        {
//            endX = x;
//            endY = y;
//            arrX[count] = x;
//            arrY[count] = y;
//        }
//
//        glVertex2f(x, y);
//        count++;
//    }
//
//    // Add a curve at the end
//    float controlX = endX + 50.0;
//    float controlY = endY - 20.0;
//    float curveEndX = endX + 30.0;
//    float curveEndY = endY - 40.0;
//
//    for (int i = 1; i <= 20; i++)
//    {
//        float t = i / 20.0;
//        float curveX = (1 - t) * (1 - t) * endX + 2 * (1 - t) * t * controlX + t * t * curveEndX;
//        float curveY = (1 - t) * (1 - t) * endY + 2 * (1 - t) * t * controlY + t * t * curveEndY;
//
//        arrX[count] = curveX;
//        arrY[count] = curveY;
//
//        glVertex2f(curveX, curveY);
//        count++;
//    }
//
//    glEnd();
//
//    // Draw the leaf shape
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i < len; i++)
//    {
//        glVertex2f(arrX[i], arrY[i]);
//    }
//    glEnd();
//
//    // Add lines inside the leaf
//    glBegin(GL_LINES);
//    for (int i = 0; i < len; i++)
//    {
//        if (i % 5 == 0) // Adjust the spacing between the lines
//        {
//            // Left side
//            glVertex2f(arrX[i], arrY[i]);
//            glVertex2f(centerX + 65 + i / 10, centerY + r - 2.5 * i);
//
//            // Right side (symmetric)
//            /*glVertex2f(arrX[i], arrY[i]);
//            glVertex2f(centerX + 27 + 105, centerY + r - 2.5 * i);*/
//        }
//
//        if (centerY + r - 2 * i <= centerY - r + 2.8)
//        {
//            break;
//        }
//    }
//    glEnd();
//
//    delete[] arrX;
//    delete[] arrY;
//    glBegin(GL_LINES);
//    glVertex2f(centerX + 27, centerY + r - 2.8);
//    glVertex2f(centerX + 27, centerY - r + 2.8);
//    glEnd();
//}
//
//
//
//
//
//// Initialization routine.
//void setup(void)
//{
//    // Set the clearing color of the OpenGL window (background) toblack.
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//}
//
//// OpenGL window reshape routine.
//void resize(int w, int h)
//{
//    // Drawing the entire window.
//    glViewport(0, 0, w, h);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    // Set up a viewing box span along the x-axis from left to right,
//    // along the y-axis from bottom to top,
//    // and along the z-axis from -1.0 to 1.0.
//    glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//// Keyboard input processing routine. x & y are the location of the mouse.
//void keyInput(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//        // ASCII of escape key.
//    case 27:
//        exit(0);
//        break;
//    default:
//        break;
//    }
//}
//
//// Main routine.
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv); // Initializes the FreeGLUT library.
//
//    // Create context, set its version, and set backward compatibility.
//    glutInitContextVersion(3, 3);
//    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
//
//    // Wanting an OpenGL context to support a single-buffered frame,
//    // each pixel having red, green, blue, and alpha values.
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//
//    // Set the initial size of the OpenGL window and the location of its top-left corner on the computer screen.
//    glutInitWindowSize(w, h);
//    glutInitWindowPosition(0, 0);
//
//    // Creates the OpenGL context and its associated window with the specified string parameter as title.
//    glutCreateWindow("Leaf Drawing");
//
//    // Callback routines when the OpenGL window is to be drawn, when it is resized,
//    // and when keyboard input is received, respectively.
//    glutDisplayFunc(drawScene);
//    glutReshapeFunc(resize);
//    glutKeyboardFunc(keyInput);
//
//    // Initializes GLEW (the OpenGL Extension Wrangler Library),
//    // which handles the loading of OpenGL extensions,
//    // with the switch set so that extensions implemented even in pre-release drivers are exposed.
//    glewExperimental = GL_TRUE;
//    glewInit();
//
//    setup();
//
//    // Begins the event-processing loop, calling registered callback routines as needed.
//    glutMainLoop();
//
//    return 0;
//}

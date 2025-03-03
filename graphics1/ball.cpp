//
//
//#include <cmath>
//#include <cstdlib>
//#include <iostream>
//#include <fstream>
//
//#include <glew.h>
//#include <freeglut.h>
//
//// Globals.
//static int isAnimate = 0; // Animated?
//static int animationPeriod = 100; // Time interval between frames.
//static float t = 0.0; // Time parameter.
//static double h = 8; // Horizontal component of initial velocity.
//static double v = 4.0; // Vertical component of initial velocity.
//static float g = 0.2;  // Gravitational accelaration.
//static char theStringBuffer[10]; // String buffer.
//static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.
//
//
//// Drawing routine.
//void ballmotion(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//
//    // Place scene in frustum.
//    glTranslatef(-15.0, -15.0, -25.0);
//
//    // Apply equations of motion to transform sphere.
//
//    /*glTranslatef(h * t, v * t - (g / 2.0) * t * t, 0.0);*/
//    // Adjust the translation equation based on projectile motion.
//    float x = h * t;
//    float y = v * t - 0.5 * g * t * t; // Calculate y position using the projectile motion equation.
//    float z = 0.0; // Assuming motion in the xy-plane.
//
//    glTranslatef(-15.0 + x, -15.0 + y, -25.0 + z); // Translate the ball to its calculated position.
//
//    // Sphere.
//    glColor3f(1.0, 0.0, 0.0);
//    glutSolidSphere(2.0, 10, 10);
//
//    glutSwapBuffers();
//}
//void drawWall(float width=30 , float height=30, float depth=-50) {
//    // Draw a simple wall using GL_QUADS.
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_POLYGON);
//    // Front face
//    glVertex3f(-15, -15, depth / 2);
//    glVertex3f(-15, -10, depth / 2);
//    glVertex3f(-8, -10, depth / 2);
//    glVertex3f(-8, 10, depth / 2);
//    glEnd();
//}
//void drawScene()
//{ 
//    ballmotion();
//    drawWall();
//}
//
//// Timer function.
//void animate(int value)
//{
//    if (isAnimate)
//    {
//        t += 1.0;
//        if (h > 3.2) //3.2
//        { h -= 0.2; } // decrease speed over time to make it look more realistic
//        else
//        {
//            h -= 0.12;
//        }
//       
//       
//        glutPostRedisplay();
//        glutTimerFunc(animationPeriod, animate, 1);
//    }
//}
//
//// Initialization routine.
//void setup(void)
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//}
//
//// OpenGL window reshape routine.
//void resize(int w, int h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-4.0, 5.0, -5.0, 5.0, 5.0, 100.0);
//    /*glFrustum(-50, 50.0, -50.0, 50.0, 0.0, 100);*/
//
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// Keyboard input processing routine.
//void keyInput(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//    case 27:
//        exit(0);
//        break;
//    case ' ':
//        if (isAnimate) isAnimate = 0;
//        else
//        {
//            isAnimate = 1;
//            animate(1);
//        }
//        break;
//    case 'r':
//        isAnimate = 0;
//        t = 0.0;
//        h = 10;
//        v = 4;
//        glutPostRedisplay();
//        break;
//    default:
//        break;
//    }
//}
//
//
//
//
//// Main routine.
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//
//    glutInitContextVersion(4, 3);
//    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
//
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("throwBall.cpp");
//    glutDisplayFunc(drawScene);
//    glutReshapeFunc(resize);
//    glutKeyboardFunc(keyInput);
//
//    glewExperimental = GL_TRUE;
//    glewInit();
//
//    setup();
//
//    glutMainLoop();
//}
//

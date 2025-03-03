///*
// Notes on glm:
//
//glm is a set of C++ classes and functions to fill in the programming gaps in writing the basic vector and matrix mathematics for OpenGL applications.
//1- download it from this link https://glm.g-truc.net/0.9.9/index.html
// or using Homebrew (on macos)
//2- Look for the directory that contains the .hpp files: glm.hpp, vec3.hpp, .... . Add the path of this directory to the headers path of your project, similar to the steps you followed with the other libraries.
//*/
//
//// This code creates simple camera movements (forward, backward, right, left) using gluLookAt
//
//#include <iostream>
//
//#include <glew.h>
//#include <freeglut.h>
//#include <glm.hpp>
//
//
//
//static float speed = 1.0;   // a float to determine the speed of camera motion
//
//// defining the eye, center and up vectors
//glm::vec3 eye = glm::vec3(0.0, 0.0, 15);
//glm::vec3 center = glm::vec3(0.0, 0.0, 0.0);
//glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);
//
//glm::vec3 forwardDir = glm::vec3(0.0, 0.0, -1.0);   // direction of forward movement of the camera
//
//// Drawing routine.
//void drawScene(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0, 0.0, 0.0);
//    glLoadIdentity();
//
//    gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
//
//    glutWireTeapot(5.0);
//
//    glutSwapBuffers();
//}
//
//// to move the camera in the forward direction, we simply increment the eye and center vectors in that direction. Here we chose that to be to the front, down the z axis.
//void moveForward(void)
//{
//    eye += speed * forwardDir;
//    center += speed * forwardDir;
//}
//
//// a change in sign moves you to the opposite direction .
//void moveBackward(void)
//{
//    eye -= speed * forwardDir;
//    center -= speed * forwardDir;
//}
//
//// cross product of the line of sight vector with the up vector gives us the direction pointing to the right of the camera.
//// the eye and center are incremented in that direction
//void moveRight(void)
//{
//    glm::vec3 rightDir = glm::cross(glm::normalize(center - eye), up);
//    eye += speed * rightDir;
//    center += speed * rightDir;
//}
//
//void moveLeft(void)
//{
//    glm::vec3 rightDir = glm::cross(glm::normalize(center - eye), up);
//    eye -= speed * rightDir;
//    center -= speed * rightDir;
//}
//
//// Initialization routine.
//void setup(void)
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//
//}
//
//// OpenGL window reshape routine.
//void resize(int w, int h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
//
//    glMatrixMode(GL_MODELVIEW);
//
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
//    case 'w':
//        moveForward();
//        glutPostRedisplay();
//        break;
//    case 'x':
//        moveBackward();
//        glutPostRedisplay();
//        break;
//    case 'd':
//        moveRight();
//        glutPostRedisplay();
//        break;
//    case 'a':
//        moveLeft();
//        glutPostRedisplay();
//        break;
//    default:
//        break;
//    }
//}
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
//    glutCreateWindow("boxWithLookAt.cpp");
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

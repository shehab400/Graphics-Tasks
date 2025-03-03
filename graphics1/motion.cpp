//// simple example showing automatic animation, using glutIdleFunc. Pressing space bar plays/resumes animation of a rotating ball.
///////////////////////////////////
//
//#include <iostream>
//
//#include <glew.h>
//#include <freeglut.h>
//
//static float Zangle = 0.0; // Angle to rotate the sphere around z axis.
//static int animate = 0;
//
//// Drawing routine.
//void drawScene(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0, 0.0, 0.0);
//    glLoadIdentity();
//
//    // Modeling transformations.
//    glTranslatef(0.0, 0.0, -20.0);
//
//
//    glRotatef(Zangle, 0.0, 0.0, 1.0);
//    glTranslatef(5.0, 0.0, 0.0);
//    glutWireSphere(3.0, 8, 8);
//
//    glutSwapBuffers();
//
//}
//
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
    /*glFrustum(0, 10.0, 0.0, 10.0, 0.0, 1);*/
//    glMatrixMode(GL_MODELVIEW);
//}
//
//
//void animation(void)
//{
//    Zangle += 5.0;
//    if (Zangle > 360.0) Zangle -= 360.0;
//    glutPostRedisplay();
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
//
//    case ' ':
//        if (animate)
//        {
//            animate = 0;
//            glutIdleFunc(NULL);
//        }
//        else
//        {
//            animate = 1;
//            glutIdleFunc(animation);
//        }
//        break;
//
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
//    glutCreateWindow("box.cpp");
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

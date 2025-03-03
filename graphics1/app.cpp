////cr. code: sumanta guha.
//////////////////////////
//
////importing the header files
//#include <glew.h>
//#include <freeglut.h> 
//
//// drawing routine.
//void drawscene(void)
//{
//	// clearing the buffer and setting the drawing color
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 0.0, 0.0);
//	glutWireCube(5.0);
//	//glColor3f(1.0, 0.0, 0.0);
//
//	//// draw a polygon with specified vertices counterclockwise.
//	//glBegin(GL_POLYGON);
//	//glVertex3f(20.0, 20.0, 0.0);	// x, y, z
//	//glVertex3f(80.0, 20.0, 0.0);
//	//glVertex3f(80.0, 80.0, 0.0);
//	//glVertex3f(20.0, 80.0, 0.0);
//
//	//glEnd();
//
//	//// execute the drawing
//	//glFlush();
//}
//
//// initialization routine.
//void setup(void)
//{
//	//the clearing color of the opengl window (background)
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//}
//
//// opengl window reshape routine.
//void resize(int w, int h)
//{
//	// drawing the entire window
//	glViewport(0, 0, w, h);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	//glortho(left, right, bottom, top, near, far)
//	//sets up a viewing box span along the x-axis is from left to right, along the y-axis from bottom to top, 
//	// and along the z-axis from ?far to ?near.
//	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//// keyboard input processing routine. x & y are location of the mouse
//void keyinput(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//		// ascii of escape key
//	case 27:
//		exit(0);
//		break;
//	default:
//		break;
//	}
//}
//
//// main routine.
//int main(int argc, char** argv)
//{
//
//	glutInit(&argc, argv);	// initializes the freeglut library.
//
//	// create context, set its version and set backward compatibility. 
//	// context is the interface between an instance of opengl and the rest of the system
//	glutInitContextVersion(3, 3);
//	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
//
//	// wanting an opengl context to support a single-buffered frame, each pixel having red, green, blue and alpha values.
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//
//	// set the initial size of the opengl window and the location of its top left corner on the computer screen
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(200, 200);
//
//	// creates the opengl context and its associated window with the specified string parameter as title.
//	glutCreateWindow("square.cpp");
//
//	// callback routines – when the opengl window is to be drawn, when it is resized, 
//	// and when keyboard input is received, respectively
//	glutDisplayFunc(drawscene);
//
//	glutReshapeFunc(resize);
//
//	// initializes glew (the opengl extension wrangler library) which handles the loading of opengl extensions, 
//	// with the switch set so that extensions implemented even in pre-release drivers are exposed.
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	setup();
//
//	// begins the event-processing loop, calling registered callback routines as needed
//	glutMainLoop();
//
//}
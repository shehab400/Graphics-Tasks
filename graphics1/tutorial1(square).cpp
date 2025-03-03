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
//	glclear(gl_color_buffer_bit);
//	glcolor3f(1.0, 0.0, 0.0);
//
//	// draw a polygon with specified vertices counterclockwise.
//	glbegin(gl_polygon);
//	glvertex3f(20.0, 20.0, 0.0);	// x, y, z
//	glvertex3f(80.0, 20.0, 0.0);
//	glvertex3f(80.0, 80.0, 0.0);
//	glvertex3f(20.0, 80.0, 0.0);
//
//	glend();
//
//	// execute the drawing
//	glflush();
//}
//
//// initialization routine.
//void setup(void)
//{
//	//the clearing color of the opengl window (background)
//	glclearcolor(0.0, 0.0, 0.0, 0.0);
//}
//
//// opengl window reshape routine.
//void resize(int w, int h)
//{
//	// drawing the entire window
//	glviewport(0, 0, w, h);
//
//	glmatrixmode(gl_projection);
//	glloadidentity();
//
//	//glortho(left, right, bottom, top, near, far)
//	//sets up a viewing box span along the x-axis is from left to right, along the y-axis from bottom to top, 
//	// and along the z-axis from ?far to ?near.
//	glortho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
//
//	glmatrixmode(gl_modelview);
//	glloadidentity();
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
//	glutinit(&argc, argv);	// initializes the freeglut library.
//
//	// create context, set its version and set backward compatibility. 
//	// context is the interface between an instance of opengl and the rest of the system
//	glutinitcontextversion(3, 3);
//	glutinitcontextprofile(glut_compatibility_profile);
//
//	// wanting an opengl context to support a single-buffered frame, each pixel having red, green, blue and alpha values.
//	glutinitdisplaymode(glut_single | glut_rgba);
//
//	// set the initial size of the opengl window and the location of its top left corner on the computer screen
//	glutinitwindowsize(300, 300);
//	glutinitwindowposition(200, 200);
//
//	// creates the opengl context and its associated window with the specified string parameter as title.
//	glutcreatewindow("square.cpp");
//
//	// callback routines – when the opengl window is to be drawn, when it is resized, 
//	// and when keyboard input is received, respectively
//	glutdisplayfunc(drawscene);
//	glutreshapefunc(resize);
//	glutkeyboardfunc(keyinput);
//
//	// initializes glew (the opengl extension wrangler library) which handles the loading of opengl extensions, 
//	// with the switch set so that extensions implemented even in pre-release drivers are exposed.
//	glewexperimental = gl_true;
//	glewinit();
//
//	setup();
//
//	// begins the event-processing loop, calling registered callback routines as needed
//	glutmainloop();
//
//} 
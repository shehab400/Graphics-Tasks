//#include <iostream>
//#include <glew.h>
//#include <freeglut.h>
//#include <glm.hpp>
//#include <chrono>
//#include <thread>
//
//float angle = 0.0;
//static float speed = 1.0;
//float angle_speed = 5.0 * 3.14 / 180.0;
//float car_width = 20; //width of Car 
//float obstacle_width = 5; //width of Obstacle 
//const int NumberOfObstacles = 4;
//bool  message_is_displayed = FALSE;
//bool car_is_stopped = FALSE; //A boolen variable to stop car , while the message [you lose / you win] is displayed
//float target_width = 50.0; //Target Width
//
//
//int Timer = 0; //Counts the seconds while the message [you lose / you win] is displayed
//
//bool loser = FALSE; //A boolen variable that is changed if the car collides with obstacles.
//bool winer = FALSE; //A boolen variable that is changed if the car reach the target.
//
////array for Obstacle centers
//glm::vec3 arr_of_obstacles_centers[NumberOfObstacles] = { glm::vec3(40.0, 0.0, -30) ,glm::vec3(-40.0, 0.0, -70),glm::vec3(-30.0, 0.0, -130),glm::vec3(25.0, 0.0, -110) };
////I have always set the y of the centers to zero to facilitate collision detection calculations
////Target center
//glm::vec3 target_center = glm::vec3(0.0, 0.0, -200);
//
//
//
//glm::vec3 eye = glm::vec3(0.0, 0.0, 70); //eye [for gluLookAt function]
//glm::vec3 center = glm::vec3(0.0, 0.0, 15.0);//center [for gluLookAt function] , car center
//glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);////up [for gluLookAt function]
//
//void Restart_the_game() {
//    //Restart_the_game =>> A function to return variables that change during the game to their initial state
//    loser = FALSE;
//    winer = FALSE;
//    eye = glm::vec3(0.0, 0.0, 70);
//    center = glm::vec3(0.0, 0.0, 15.0);
//    up = glm::vec3(0.0, 1.0, 0.0);
//    angle = 0.0;
//    Timer = 0;
//    car_is_stopped = FALSE;
//    message_is_displayed = FALSE;
//}
//
//void writeBitmapString(void* font, char* string)
//{
//    char* c;
//    for (c = string; *c != '\0'; c++)  glutBitmapCharacter(font, *c);
//}
////function to display the message => [you lose / you win] 
////Similar to the Animate function
//void display_message(int value)
//{
//    glWindowPos2i(400, 500);
//    //loser:true if The car collided with an obstacle
//    if (loser) {
//        writeBitmapString(GLUT_BITMAP_8_BY_13, (char*)"You Lose !");
//    }
//    //winer:true if The car reached the target
//    else if (winer)
//    {
//        writeBitmapString(GLUT_BITMAP_8_BY_13, (char*)"You Win !");
//    }
//    //The message display ends and the game restarts when the timer reaches ten
//    if (Timer >= 10) {
//        Restart_the_game();
//        message_is_displayed = FALSE;
//    }
//    Timer = Timer + 1; //The timer increases by one each time the function is called
//    glutPostRedisplay();
//    if (message_is_displayed) glutTimerFunc(1000, display_message, 1);
//}
//
//void drawTarget() {
//    glPushMatrix();
//    glTranslatef(0.0, target_width * 0.5, 0.0);//We assumed that the floor at y equals zero, 
//    //so we raised the body up to make its base touch the floor at y equals zero.
//    glColor3f(0.0, 0.0, 1.0); //Make the target blue
//    glTranslatef(target_center.x, target_center.y, target_center.z);//translate center from origin to target_center
//    glutSolidCube(target_width);
//    glPopMatrix();
//}
//
//void drawCar() {
//
//    glPushMatrix();
//    glTranslatef(0.0, car_width * 0.3 * 0.5, 0.0);//We assumed that the floor at y equals zero, 
//    //so we raised the body up to make its base touch the floor at y equals zero.
//
////Draw the lower half of the car body (By Cube with width=20)
//    glPushMatrix();
//    glColor3f(0.85, 0.85, 0.0); //car : yellow 
//    glTranslatef(center.x, center.y, center.z);//translate center from origin to car_center
//    glScalef(1.0, 0.3, 1.0);//Scaling  y will not affect the collision calculations because the motion is in the xy plane
//    glutSolidCube(car_width);
//    glPopMatrix();
//
//    //Draw the upper half of the car body
//    glPushMatrix();
//    glColor3f(0.85, 0.85, 0.0);//car : yellow 
//    glTranslatef(center.x, center.y + (car_width + 12) * 0.3 * 0.5, center.z);
//    //I did not do the scaling in the x or z component, 
//    //so that the distance between the center and all the side faces is fixed
//    //Because we consider the body of the car as a ball,
//    //so a fixed distance between the faces and the center must be maintained as much as possible
//    glScalef(1.0, 0.3, 1.0);
//    glutSolidCube(12);
//    glPopMatrix();
//    // Set car material properties
//    GLfloat car_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//    GLfloat car_diffuse[] = { 0.8f, 0.8f, 0.0f, 1.0f };
//    GLfloat car_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//    GLfloat car_shininess = 100.0f;
//
//    glMaterialfv(GL_FRONT, GL_AMBIENT, car_ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, car_diffuse);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, car_specular);
//    glMaterialf(GL_FRONT, GL_SHININESS, car_shininess);
//
//    //draw car wheel (Right-Behind)
//    glPushMatrix();
//    glColor3f(0.0, 0.0, 0.0);
//    glTranslatef(center.x + (0.5 * car_width), center.y - ((0.5 * car_width) * 0.3), center.z + (0.5 * car_width));
//    glRotatef(90, 0.0, 1.0, 0.0); //rotete the Tours by angle:90 [around:y]
//    glutSolidTorus(0.5, 1.0, 50, 50);
//    glPopMatrix();
//
//    //draw car wheel (Left-Behind)
//    glPushMatrix();
//    glColor3f(0.0, 0.0, 0.0);
//    glTranslatef(center.x - (0.5 * car_width), center.y - ((0.5 * car_width) * 0.3), center.z + (0.5 * car_width));
//    glRotatef(90, 0.0, 1.0, 0.0); //rotete the Tours by angle:90 [around:y]
//    glutSolidTorus(0.5, 1.0, 50, 50);
//    glPopMatrix();
//
//    //draw car wheel (Left-Front)
//    glPushMatrix();
//    glColor3f(0.0, 0.0, 0.0);
//    glTranslatef(center.x - (0.5 * car_width), center.y - ((0.5 * car_width) * 0.3), center.z - (0.5 * car_width));
//    glRotatef(90, 0.0, 1.0, 0.0);//rotete the Tours by angle:90 [around:y]
//    glutSolidTorus(0.5, 1.0, 50, 50);
//    glPopMatrix();
//
//    //draw car wheel (Right-Front)
//    glPushMatrix();
//    glColor3f(0.0, 0.0, 0.0);
//    glTranslatef(center.x + (0.5 * car_width), center.y - ((0.5 * car_width) * 0.3), center.z - (0.5 * car_width));
//    glRotatef(90, 0.0, 1.0, 0.0);//rotete the Tours by angle:90 [around:y]
//    glutSolidTorus(0.5, 1.0, 50, 50);
//    glPopMatrix();
//
//    //draw tail light (Right)
//    glPushMatrix();
//    glColor3f(0.9, 0.3, 0.1);
//    glTranslatef(center.x + 6, center.y - ((0.5 * car_width) * 0.3) + 1, center.z + (0.5 * car_width));
//    glScalef(1.5, 1.0, 0.1);
//    glutSolidCube(2);
//    glPopMatrix();
//
//    //draw tail light (Left)
//    glPushMatrix();
//    glColor3f(0.9, 0.3, 0.1);
//    glTranslatef(center.x - 6, center.y - ((0.5 * car_width) * 0.3) + 1, center.z + (0.5 * car_width));
//    glScalef(1.5, 1.0, 0.1);
//    glutSolidCube(2);
//    glPopMatrix();
//
//    glPopMatrix();
//    //// Draw headlights (Front)
//    //glColor3f(1.0, 1.0, 1.0); // Set color to white for headlights
//    //glPushMatrix();
//    //// Right headlight
//    //glTranslatef(center.x + (0.5 * car_width) - 2, center.y + (car_width * 0.15), center.z - (0.5 * car_width) + 2);
//    //glutSolidSphere(1.0, 20, 20);
//    //glPopMatrix();
//
//    //glPushMatrix();
//    //// Left headlight
//    //glTranslatef(center.x - (0.5 * car_width) + 2, center.y + (car_width * 0.15), center.z - (0.5 * car_width) + 2);
//    //glutSolidSphere(1.0, 20, 20);
//    //glPopMatrix();
//     // Draw headlights (Front)
//    glColor3f(1.0, 1.0, 1.0); // Set color to white for headlights
//    glPushMatrix();
//    // Right headlight
//    glTranslatef(center.x + (0.5 * car_width) - 2, center.y + (car_width * 0.15), center.z - (0.5 * car_width) + 2);
//    glutSolidSphere(1.0, 20, 20);
//    glPopMatrix();
//
//    glPushMatrix();
//    // Left headlight
//    glTranslatef(center.x - (0.5 * car_width) + 2, center.y + (car_width * 0.15), center.z - (0.5 * car_width) + 2);
//    glutSolidSphere(1.0, 20, 20);
//    glPopMatrix();
//   
//
//
//
//}
//
////Function for drawing obstacles We set the y[We made it zero to facilitate collision calculations 
////because the movement is in the xz plane] and width by dafult to make it easier to call the function
//void draw_obstacle(float center_x, float center_z, float center_y = 0, float width = obstacle_width) {
//    glPushMatrix();
//    glColor3f(1.0, 0.0, 0.0);
//    glTranslatef(center_x, center_y + (width * 0.5 * 5), center_z);//We assumed that the floor at y equals zero, 
//    //so we raised the body up to make its base touch the floor at y equals zero.
//
//    glScalef(2.0, 5.0, 1.0);//Scaling  y will not affect the collision calculations because the motion is in the xy plane
//
//    glutSolidCube(width);
//    glPopMatrix();
//}
//
//void detectCollision()
//{
//    float distance = 0;
//    for (int i = 0; i < NumberOfObstacles; i++)//Loop to calculate the distance with all obstacles
//    {
//        distance = glm::length(center - arr_of_obstacles_centers[i]);//The distance between the obstacle and the car
//        if (distance <= ((car_width + obstacle_width) / 2))
//        {
//            Timer = 0;//Set the timer that counts the message remaining on the screen to zero
//            loser = TRUE;
//            message_is_displayed = TRUE;
//            car_is_stopped = TRUE; //stop car , while the message [you lose / you win] is displayed
//            display_message(1);//Start displaying the message
//            break;
//        }
//    }
//    distance = glm::length(center - target_center);//The distance between the target and the car
//    if (distance <= ((car_width + target_width) / 2))
//    {
//        Timer = 0;//Set the timer that counts the message remaining on the screen to zero
//        winer = TRUE;
//        message_is_displayed = TRUE;
//        car_is_stopped = TRUE;//stop car , while the message [you lose / you win] is displayed
//        display_message(1);
//    }
//}
//
//void drawScene(void)
//{
//    glEnable(GL_DEPTH_TEST);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glColor3f(0.0, 0.0, 0.0);
//    glLoadIdentity();
//
//    gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
//
//    // Set up lighting
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    GLfloat light_position[] = { center.x, center.y + 20.0, center.z, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//    drawCar(); // Draw car with headlights
//    for (int i = 0; i < NumberOfObstacles; i++)
//    {
//        draw_obstacle(arr_of_obstacles_centers[i].x, arr_of_obstacles_centers[i].z);
//    }
//    drawTarget();
//
//    if (winer)
//        glColor3f(0.0, 1.0, 0.0);
//    else
//        glColor3f(1.0, 0.0, 0.0);
//
//    detectCollision();
//
//    glutSwapBuffers();
//}
//
//void moveForward(void)
//{
//    glm::vec3 forwardDir = glm::normalize(center - eye);
//    eye += speed * forwardDir;
//    center += speed * forwardDir;
//}
//
//void moveBackward(void)
//{
//    //Returns a vector in the same direction as x but with length of 1. 
//    glm::vec3 forwardDir = glm::normalize(center - eye);
//    eye -= speed * forwardDir;
//    center -= speed * forwardDir;
//}
//
//void moveRight(void)
//{
//    //Returns the cross product of x and y. 
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
//void rotateLeft()
//{
//    angle += angle_speed;
//    float l = glm::length(center - eye);
//    center.x = eye.x - l * sin(angle);
//    center.z = eye.z - l * cos(angle);
//}
//
//void rotateRight()
//{
//    angle -= angle_speed;
//    float l = glm::length(center - eye);
//    center.x = eye.x - l * sin(angle);
//    center.z = eye.z - l * cos(angle);
//}
//
//void setup(void)
//{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//}
//
//void resize(int w, int h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 300.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void specialKeyInput(int key, int x, int y) {
//    if (car_is_stopped)
//        //IF condition to make the car stopped while displaying a win/loss message to a user
//        return;
//    switch (key) {
//    case GLUT_KEY_LEFT:
//        rotateLeft();
//        glutPostRedisplay();
//        break;
//    case GLUT_KEY_RIGHT:
//        rotateRight();
//        glutPostRedisplay();
//        break;
//    case GLUT_KEY_UP:
//        moveForward();
//        glutPostRedisplay();
//        break;
//    case GLUT_KEY_DOWN:
//        moveBackward();
//        glutPostRedisplay();
//        break;
//
//    default:
//        break;
//    }
//}
//
//
//void keyInput(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//    case 27:
//        exit(0);
//        break;
//    case 'd':
//        moveRight();
//        glutPostRedisplay();
//        break;
//    case 'a':
//        moveLeft();
//        glutPostRedisplay();
//        break;
//
//    default:
//        break;
//    }
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//
//    glutInitContextVersion(4, 3);
//    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
//    glutInitWindowSize(550, 600);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("CAR GAME :)");
//    glutDisplayFunc(drawScene);
//    glutReshapeFunc(resize);
//    glutKeyboardFunc(keyInput); // Removed reference to specialKeyInput
//    glutSpecialFunc(specialKeyInput); // Removed reference to specialKeyInput
//
//    glewExperimental = GL_TRUE;
//    glewInit();
//
//    setup();
//
//    glutMainLoop();
//}

#include <GL/glut.h>
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0); //Set the range of display is x: -5.0 ~ 5.0, Y: -5.0 ~ 5.0
    glMatrixMode(GL_MODELVIEW);
}

void drawSquare(void) //Drawing center in the origin, square length 2 square
{
    glBegin(GL_POLYGON); //The vertex specifies the need to press counterclockwise
    {
        glVertex2f(-1.0f,-1.0f);//Lower left
        glVertex2f(1.0f,-1.0f);//Upper right point
        glVertex2f(1.0f, 1.0f);//Upper right
        glVertex2f(-1.0f,1.0f);//Upper left point
    }
    glEnd();
}

void myDraw1(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //Empty

    glLoadIdentity(); //Set the current matrix into unit matrix
    glColor3f(1.0, 0.0, 0.0);
    drawSquare(); //Draw a side length of 2 red square at the origin

    glTranslatef(2.0,3.0,0.0); //Move 2 units to the right, move 3 units up
    glScalef(1.0,1.5,1.0); //The X and Z directions remain unchanged, and the Y direction is magnified to 1.5 times.
    glColor3f(0.0, 1.0, 0.0);
    drawSquare(); //Draw a side length of 2 green square

    glLoadIdentity(); //Set the current matrix into unit matrix
    glTranslatef(-2.0,-3.0,0.0); //3 units to the left, move 3 units down
    glScalef(0.5,1.5,1.0); //The Z direction remains unchanged, the X direction is reduced to 0.5 times the original, and the Y direction is magnified to 1.5 times.
    glColor3f(0.0, 0.0, 1.0);
    drawSquare(); //Draw a side length 2 blue square

    glFlush();
}

void myDraw2(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //Empty

    glLoadIdentity(); //Set the current matrix into unit matrix
    glColor3f(1.0, 0.0, 0.0);
    drawSquare(); //Draw a side length of 2 red square at the origin
    glPushMatrix(); //Press the current matrix into the stack
    {
        glTranslatef(2.0,3.0,0.0); //Move 2 units to the right, move 3 units up
        glScalef(1.0,1.5,1.0); //The X and Z directions remain unchanged, and the Y direction is magnified to 1.5 times.
        glColor3f(0.0, 1.0, 0.0);
        drawSquare(); //Draw a side length of 2 green square
    }
    glPopMatrix(); //Playing a matrix from the top of the stack for the current matrix

    glTranslatef(-2.0,-3.0,0.0); //3 units to the left, move 3 units down
    glScalef(0.5,1.5,1.0); //The Z direction remains unchanged, the X direction is reduced to 0.5 times the original, and the Y direction is magnified to 1.5 times.
    glColor3f(0.0, 0.0, 1.0);
    drawSquare(); //Draw a side length 2 blue square

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Scale function example");

    init();
    glutDisplayFunc(myDraw1);
    glutMainLoop();
}

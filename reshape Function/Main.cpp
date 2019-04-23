#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;

GLsizei winWidth = 400, winHight = 400;

GLuint regHex;

class screenpt
{
private:
	GLint x, y;
public:
	screenpt()
	{
		x = y = 0;
	}

	void setCoords(GLint xCoord,GLint yCoord)
	{
		x = xCoord;
		y = yCoord;
	}

	GLint getx() const
	{
		return x;
	}

	GLint gety() const
	{
		return y;
	}


};

void Init()
{
	screenpt hexVertex, circCtr;
	double theta;
	GLint k;

	circCtr.setCoords(winWidth / 2, winHight / 2);
	glClearColor(1.0, 1.0, 1.0, 1.0);

	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (k=0;k<6;k++)
	{
		theta = TWO_PI * k / 6.0;
		hexVertex.setCoords(circCtr.getx() + 150 * cos(theta), circCtr.gety() + 150 * sin(theta));
		glVertex2i(hexVertex.getx(), hexVertex.gety());
	}
	glEnd();
	glEndList();
}

void regHexgon()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(regHex);
	glFlush();
}

void winReshapeFcn(int newWidth, int newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	glutInitWindowPosition(winWidth, winHight);
	glutCreateWindow("Resharp-Function & Display-List Example");
	Init();
	glutDisplayFunc(regHexgon);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}


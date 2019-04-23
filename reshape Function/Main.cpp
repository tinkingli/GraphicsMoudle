#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;

GLsizei winWidth = 400, winHight = 400;

//����һ��ȫ�ֱ�����GLuint�������ͣ�
GLuint regHex;

class screenpt
{
	//����˽�е�GLint�������ͣ�x,y
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
	int a =0;

	circCtr.setCoords(winWidth / 2, winHight / 2);
	glClearColor(1.0, 1.0, 1.0, 1.0);

	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	//��ʾһ�����Ķ����
	glBegin(GL_POLYGON);
	for (k=0;k<6;k++)
	{
		theta = TWO_PI * k / 6.0;
		hexVertex.setCoords(circCtr.getx() + 150 * cos(theta), circCtr.gety() + 150 * sin(theta));
		a = cos(theta);
		glVertex2i(hexVertex.getx(), hexVertex.gety());
		a = 0;

	}
	/*glVertex2i(350, 200);
	glVertex2i(275, 329);
	glVertex2i(125, 329);
	glVertex2i(50, 200);
	glVertex2i(125, 70);
	glVertex2i(275, 70);
*/
	//����һ�����Ķ����
	glEnd();
	//����һ����ʾ�б�
	glEndList();
}

void regHexgon()
{
	//����ɫ������ʾ����
	glClear(GL_COLOR_BUFFER_BIT);
	//ִ��һ����ʾ�б�
	glCallList(regHex);
	//ǿ��������л�����ִ�д���OPENGL����
	glFlush();
}

void winReshapeFcn(int newWidth, int newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

//������
void main(int argc, char* argv[])
{
	//GLUT��ʼ�������
	glutInit(&argc, argv);
	//�趨��ʾ���ڵĻ������ɫģ�͵�ѡ��
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	//���ڴ���ʱ��ʾ��������
	glutInitWindowPosition(winWidth, winHight);
	//�����ڴ���ʱ�ı���
	glutCreateWindow("Resharp-Function & Display-List Example");
	//ִ��Init����
	Init();
	//����һ��ͼ�β���ͼ�Ķ��崫�ݸ�GULT����
	glutDisplayFunc(regHexgon);
	//ָ����ʾ���ڳߴ�ı�ʱ�Ĺ���
	glutReshapeFunc(winReshapeFcn);
	//���д�������ʾ������ͬͼ��һ��������
	glutMainLoop();
}


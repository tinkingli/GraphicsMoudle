#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;

GLsizei winWidth = 400, winHight = 400;

//定义一个全局变量的GLuint数据类型，
GLuint regHex;

class screenpt
{
	//定义私有的GLint数据类型，x,y
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
	//显示一个填充的多边形
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
	//结束一个填充的多边形
	glEnd();
	//结束一个显示列表
	glEndList();
}

void regHexgon()
{
	//令颜色赋给显示窗口
	glClear(GL_COLOR_BUFFER_BIT);
	//执行一个显示列表
	glCallList(regHex);
	//强制清空所有缓存来执行处理OPENGL函数
	glFlush();
}

void winReshapeFcn(int newWidth, int newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

//主方法
void main(int argc, char* argv[])
{
	//GLUT初始化的语句
	glutInit(&argc, argv);
	//设定显示窗口的缓存和颜色模型等选项
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	//窗口创建时显示器的坐标
	glutInitWindowPosition(winWidth, winHight);
	//窗口在创建时的标题
	glutCreateWindow("Resharp-Function & Display-List Example");
	//执行Init方法
	Init();
	//创建一个图形并将图的定义传递给GULT函数
	glutDisplayFunc(regHexgon);
	//指定显示窗口尺寸改变时的工作
	glutReshapeFunc(winReshapeFcn);
	//所有创建的显示窗口连同图形一并被激活
	glutMainLoop();
}


#include <GL/glut.h>
GLsizei winWidth = 500, winHight = 700;

GLint xRaster = 25, yRaster = 150;

GLubyte label[36] = { 'J','a','n','F','e','b','M','a','r','A','p','t','M','a','y','J','u','n' ,'J','u','l','A','u','g','S','e','p','O','c','t','N','o','v','D','e','c' };

GLint dataValue[12] = { 420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438 };


void Init()
{
	//设定窗口的背景颜色为白色
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//将当前矩阵指定为投影矩阵
	glMatrixMode(GL_PROJECTION);
	//用于截取世界坐标系相应区域
	gluOrtho2D(0.0, 500.0, 0.0, 600.0);
}

void BarChart(void)
{
	GLint month, k;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	for (k = 0; k < 12; k++)
	{
		glRecti(20 + k * 50, 165, 40 + k * 50, dataValue[k]);
	}

	glColor3f(0.0, 0.0, 0.0);
	xRaster = 20;
	for (month = 0; month < 12; month++)
	{
		glRasterPos2i(xRaster, yRaster);
		for (k = 3 * month; k < 3 * month + 3; k++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
		}
		xRaster += 50;
	}
	glFlush();
}

void winReshapeFcn(GLint newWith, GLint newHight)
{
	//将当前矩阵指定为投影矩阵
	glMatrixMode(GL_PROJECTION);
	//对当前的矩阵进行初始化
	glLoadIdentity();
	//用于截取世界坐标系相应区域
	gluOrtho2D(0.0, GLdouble(newWith), 0.0, GLdouble(newHight));
	//指定刷新颜色缓冲区时所用的颜色
	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char** argv)
{
	//GLUT初始化
	glutInit(&argc, argv);
	//设定窗口的缓存和颜色
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//设定窗口在显示器上的坐标
	glutInitWindowPosition(200, 200);
	//设定窗口的大小
	glutInitWindowSize(winWidth, winHight);
	//设定窗口的名字
	glutCreateWindow("Bar Chart Data Por");
	//执行Init方法
	Init();
	glutDisplayFunc(BarChart);
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();

}

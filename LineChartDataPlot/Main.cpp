#include <GL/glut.h>

//定义屏幕的大小
GLsizei  winWidth = 600, winHight = 600;

GLint xRaster = 25, yRaster = 150;

//我能说这是我见过最弱智的月份拼写吗？
GLubyte label[36] = { 'J','a','n','F','e','b','M','a','r','A','p','t','M','a','y','J','u','n' ,'J','u','l','A','u','g','S','e','p','O','c','t','N','o','v','D','e','c' };

//12个月份的数据
GLint dataValue[12] = { 420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438 };

void init(void)
{
	//设定窗口的颜色为白色
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//将当前的投影设置成举
	glMatrixMode(GL_PROJECTION);
	//用于截取世界坐标系响应区域
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}

void lineGraph(void)
{
	//
	GLint month, k;
	//定义一个int数据结构的 x变量
	GLint x = 30;
	//指定刷新颜色缓冲区时所用的颜色
	glClear(GL_COLOR_BUFFER_BIT);
	//在场景中绘制的对象颜色
	glColor3f(0.0, 0.0, 1.0);
	//开始绘制一条连续的线
	glBegin(GL_LINE_STRIP);
	for (k = 0; k < 12; k++)
	{
		//绘制一条线
		glVertex2i(x + k * 50, dataValue[k]);
	}
	//结束绘制线
	glEnd();

	//在场景中绘制的对象颜色
	glColor3f(1.0, 0.0, 0.0);
	for (k = 0; k < 12; k++)
	{
		//用于字体的起始位置
		glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);
		//选择一种字体和一个位图字符来显示
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
	}

	//在场景中绘制的对象颜色
	glColor3f(0.0, 0.0, 0.0);
	xRaster = 20;
	for (month = 0; month < 12; month++)
	{
		//用于字体的起始位置
		glRasterPos2i(xRaster, yRaster);
		for (k = 3 * month; k < 3 * month + 3; k++)
		{
			//选择一种字体和一个位图字符来显示
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
		}
		xRaster += 50;
	}
	//强制清空所有缓存来执行处理OPENGL函数
	glFlush();
}

void winReshapeFcn(GLint newWith, GLint newHight)
{
    //当前投影为矩阵投影
	glMatrixMode(GL_PROJECTION);
	//对当前的矩阵初始化
	glLoadIdentity();
	//用于截取世界坐标系相应区域
	gluOrtho2D(0.0, GLdouble(newWith), 0.0, GLdouble(newHight));
	//指定刷新颜色缓冲区
	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char** argv)
{
	//初始化glut
	glutInit(&argc, argv);
	//设定窗口的缓存和颜色
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//设置窗口在显示器的坐标
	glutInitWindowPosition(100, 100);
	//设置窗口的大小
	glutInitWindowSize(winWidth, winHight);
	//设置窗口的名字
	glutCreateWindow("Line Chart Data Plot");
	//执行init方法
	init();
	//创建一个图形并将图的定义传递给GULT函数
	glutDisplayFunc(lineGraph);
	//创建一个图形并将图的定义传递给GULT函数
	glutReshapeFunc(winReshapeFcn);
	//所有创建的显示窗口连同图形一并被激活
	glutMainLoop();

}

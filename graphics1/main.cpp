#include <GL/glut.h>

void init(void)
{
	//设置窗口的背景颜色设定为白色
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//设置为投影模式
	glMatrixMode(GL_PROJECTION);
	//投影成2d
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	//令颜色赋给显示窗口
	glClear(GL_COLOR_BUFFER_BIT);
	//在场景中选择的对象颜色
	glColor3f(0.0, 0.4, 0.2);
	//绘制一条180,15到10,145的一条线
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();
	//强制清空所有缓存来执行处理OPENGL函数
	glFlush();
}

void  main(int argc, char* argv[])
{
	//GLUT初始化的语句
	glutInit(&argc,argv);
	//设定显示窗口的缓存和颜色模型等选项
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//窗口创建时显示器的坐标
	glutInitWindowPosition(50, 100);
	//创建一个指定像素的窗口
	glutInitWindowSize(400, 300);
	//窗口在创建时的标题
	glutCreateWindow("New OpenGL");

	init();
	//创建一个图形并将图的定义传递给GULT函数
	glutDisplayFunc(lineSegment);
	//所有创建的显示窗口连同图形一并被激活
	glutMainLoop();
}

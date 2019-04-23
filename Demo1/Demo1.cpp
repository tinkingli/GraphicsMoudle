
#include <GL/glut.h>

void showaaa();
void renderScene();
void changeSize(GLsizei w, GLsizei h);
void setUpPc();

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	// 明确何种类型显示模式
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowPosition(400, 400);
	// 实际创建窗口
	glutCreateWindow("OpenGL");
	// 调用回调函数
	glutDisplayFunc(renderScene);

	glutReshapeFunc(changeSize);
	setUpPc();
	glutMainLoop();



	return 0;
}

void showaaa() {
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.1f, -0.1f, 0.5f, 0.5f);
	glFlush();
}

void renderScene() {
	// 从窗口中清除最后一次绘制的图形
	glClear(GL_COLOR_BUFFER_BIT);

	// 设置颜色
	glColor3f(0.5f, 0.625f, 0.12f);

	//绘制矩形
	glRectf(-30.0f, 15.0f, 30.0f, -15.0f);
	//刷新队列
	glFlush();
}

void setUpPc() {
	// 设置颜色刷屏
	glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
}


void changeSize(GLsizei w, GLsizei h) {
	GLfloat a; // 记录宽高比
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);

	// 重置坐标系统
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 建立裁剪区域
	a = (GLfloat)w / (GLfloat)h;
	if (w < h) {
		glOrtho(-100.0, 100.0, -100.0 / a, 100.0 / a, 1.0, -1.0);
	}
	else
	{
		glOrtho(-100.0 * a, 100.0 * a, -100.0, 100.0, 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
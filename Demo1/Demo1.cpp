
#include <GL/glut.h>

void showaaa();
void renderScene();
void changeSize(GLsizei w, GLsizei h);
void setUpPc();

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	// ��ȷ����������ʾģʽ
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowPosition(400, 400);
	// ʵ�ʴ�������
	glutCreateWindow("OpenGL");
	// ���ûص�����
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
	// �Ӵ�����������һ�λ��Ƶ�ͼ��
	glClear(GL_COLOR_BUFFER_BIT);

	// ������ɫ
	glColor3f(0.5f, 0.625f, 0.12f);

	//���ƾ���
	glRectf(-30.0f, 15.0f, 30.0f, -15.0f);
	//ˢ�¶���
	glFlush();
}

void setUpPc() {
	// ������ɫˢ��
	glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
}


void changeSize(GLsizei w, GLsizei h) {
	GLfloat a; // ��¼��߱�
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);

	// ��������ϵͳ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// �����ü�����
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
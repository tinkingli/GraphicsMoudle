#include <GL/glut.h>

void init(void)
{
	//���ô��ڵı�����ɫ�趨Ϊ��ɫ
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//����ΪͶӰģʽ
	glMatrixMode(GL_PROJECTION);
	//ͶӰ��2d
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	//����ɫ������ʾ����
	glClear(GL_COLOR_BUFFER_BIT);
	//�ڳ�����ѡ��Ķ�����ɫ
	glColor3f(0.0, 0.4, 0.2);
	//����һ��180,15��10,145��һ����
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();
	//ǿ��������л�����ִ�д���OPENGL����
	glFlush();
}

void  main(int argc, char* argv[])
{
	//GLUT��ʼ�������
	glutInit(&argc,argv);
	//�趨��ʾ���ڵĻ������ɫģ�͵�ѡ��
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//���ڴ���ʱ��ʾ��������
	glutInitWindowPosition(50, 100);
	//����һ��ָ�����صĴ���
	glutInitWindowSize(400, 300);
	//�����ڴ���ʱ�ı���
	glutCreateWindow("New OpenGL");

	init();
	//����һ��ͼ�β���ͼ�Ķ��崫�ݸ�GULT����
	glutDisplayFunc(lineSegment);
	//���д�������ʾ������ͬͼ��һ��������
	glutMainLoop();
}

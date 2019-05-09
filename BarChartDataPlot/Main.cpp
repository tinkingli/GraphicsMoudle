#include <GL/glut.h>
GLsizei winWidth = 500, winHight = 700;

GLint xRaster = 25, yRaster = 150;

GLubyte label[36] = { 'J','a','n','F','e','b','M','a','r','A','p','t','M','a','y','J','u','n' ,'J','u','l','A','u','g','S','e','p','O','c','t','N','o','v','D','e','c' };

GLint dataValue[12] = { 420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438 };


void Init()
{
	//�趨���ڵı�����ɫΪ��ɫ
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//����ǰ����ָ��ΪͶӰ����
	glMatrixMode(GL_PROJECTION);
	//���ڽ�ȡ��������ϵ��Ӧ����
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
	//����ǰ����ָ��ΪͶӰ����
	glMatrixMode(GL_PROJECTION);
	//�Ե�ǰ�ľ�����г�ʼ��
	glLoadIdentity();
	//���ڽ�ȡ��������ϵ��Ӧ����
	gluOrtho2D(0.0, GLdouble(newWith), 0.0, GLdouble(newHight));
	//ָ��ˢ����ɫ������ʱ���õ���ɫ
	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char** argv)
{
	//GLUT��ʼ��
	glutInit(&argc, argv);
	//�趨���ڵĻ������ɫ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//�趨��������ʾ���ϵ�����
	glutInitWindowPosition(200, 200);
	//�趨���ڵĴ�С
	glutInitWindowSize(winWidth, winHight);
	//�趨���ڵ�����
	glutCreateWindow("Bar Chart Data Por");
	//ִ��Init����
	Init();
	glutDisplayFunc(BarChart);
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();

}

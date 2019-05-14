#include <GL/glut.h>

//������Ļ�Ĵ�С
GLsizei  winWidth = 600, winHight = 600;

GLint xRaster = 25, yRaster = 150;

//����˵�����Ҽ��������ǵ��·�ƴд��
GLubyte label[36] = { 'J','a','n','F','e','b','M','a','r','A','p','t','M','a','y','J','u','n' ,'J','u','l','A','u','g','S','e','p','O','c','t','N','o','v','D','e','c' };

//12���·ݵ�����
GLint dataValue[12] = { 420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438 };

void init(void)
{
	//�趨���ڵ���ɫΪ��ɫ
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//����ǰ��ͶӰ���óɾ�
	glMatrixMode(GL_PROJECTION);
	//���ڽ�ȡ��������ϵ��Ӧ����
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}

void lineGraph(void)
{
	//
	GLint month, k;
	//����һ��int���ݽṹ�� x����
	GLint x = 30;
	//ָ��ˢ����ɫ������ʱ���õ���ɫ
	glClear(GL_COLOR_BUFFER_BIT);
	//�ڳ����л��ƵĶ�����ɫ
	glColor3f(0.0, 0.0, 1.0);
	//��ʼ����һ����������
	glBegin(GL_LINE_STRIP);
	for (k = 0; k < 12; k++)
	{
		//����һ����
		glVertex2i(x + k * 50, dataValue[k]);
	}
	//����������
	glEnd();

	//�ڳ����л��ƵĶ�����ɫ
	glColor3f(1.0, 0.0, 0.0);
	for (k = 0; k < 12; k++)
	{
		//�����������ʼλ��
		glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);
		//ѡ��һ�������һ��λͼ�ַ�����ʾ
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
	}

	//�ڳ����л��ƵĶ�����ɫ
	glColor3f(0.0, 0.0, 0.0);
	xRaster = 20;
	for (month = 0; month < 12; month++)
	{
		//�����������ʼλ��
		glRasterPos2i(xRaster, yRaster);
		for (k = 3 * month; k < 3 * month + 3; k++)
		{
			//ѡ��һ�������һ��λͼ�ַ�����ʾ
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
		}
		xRaster += 50;
	}
	//ǿ��������л�����ִ�д���OPENGL����
	glFlush();
}

void winReshapeFcn(GLint newWith, GLint newHight)
{
    //��ǰͶӰΪ����ͶӰ
	glMatrixMode(GL_PROJECTION);
	//�Ե�ǰ�ľ����ʼ��
	glLoadIdentity();
	//���ڽ�ȡ��������ϵ��Ӧ����
	gluOrtho2D(0.0, GLdouble(newWith), 0.0, GLdouble(newHight));
	//ָ��ˢ����ɫ������
	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char** argv)
{
	//��ʼ��glut
	glutInit(&argc, argv);
	//�趨���ڵĻ������ɫ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//���ô�������ʾ��������
	glutInitWindowPosition(100, 100);
	//���ô��ڵĴ�С
	glutInitWindowSize(winWidth, winHight);
	//���ô��ڵ�����
	glutCreateWindow("Line Chart Data Plot");
	//ִ��init����
	init();
	//����һ��ͼ�β���ͼ�Ķ��崫�ݸ�GULT����
	glutDisplayFunc(lineGraph);
	//����һ��ͼ�β���ͼ�Ķ��崫�ݸ�GULT����
	glutReshapeFunc(winReshapeFcn);
	//���д�������ʾ������ͬͼ��һ��������
	glutMainLoop();

}

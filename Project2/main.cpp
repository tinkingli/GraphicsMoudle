#include<GL/glut.h>
void Initial(void)//��ʼ������ 
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//��ɫ������ǰ3����RGB�������Alphaֵ����������͸����1.0��ʾ��ȫ��͸��
	glMatrixMode(GL_PROJECTION);//OpenGL������ά��ʽ������ͼ��������Ҫһ��ͶӰ�任����άͼ��ͶӰ����ʾ���Ķ�ά�ռ���
	gluOrtho2D(0.0, 200, 0.0, 150.0);//ָ��ʹ����ͶӰ��һ��x������0~200��y����0~150��Χ�ڵľ�����������ͶӰ����ʾ������

}
void myDisplay(void)//��ʾ�ص�����
{
	glClear(GL_COLOR_BUFFER_BIT);//ʹ��glClearColorz��ָ����ֵ�趨��ɫ��������ֵ�����������е�ÿһ����������Ϊ����ɫ
	glColor3f(0.0f, 0.0f, 0.0f);//��ͼ��ɫΪ��ɫ
	glRectf(50.0f, 100.0f, 150.0f, 50.0f);//ͼ�ε����꣬����һ�����Ͻ��ڣ�50��100�������½��ڣ�150��50���ľ���
	glFlush();//���OpenGL���������ǿ��ִ���������������OpenGL����
}
int main(int argc, char * argv[])//����ʹ��glut�⺯�����д��ڹ���
{
	glutInit(&argc, argv);//ʹ��glut����Ҫ���г�ʼ��
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//�趨������ʾģʽ����ɫģ�ͺͻ��棬������RGB��ɫģ�ͺ͵�����
	glutInitWindowPosition(100, 100);//�趨���ڵĳ�ʼλ�ã���Ļ���Ͻ�Ϊԭ�㣬��λΪ����
	glutInitWindowSize(400, 400);//�趨���ڵĴ�С
	glutCreateWindow("��һ��OpenGL���򡪡���ΰ");//����һ�����ڣ������Ǵ��ڱ�����
	glutDisplayFunc(&myDisplay);//��myDisplayָ��Ϊ��ǰ���ڵ���ʾ���ݺ���
	Initial();
	glutMainLoop();//ʹ���ڿ������������ʹ��ʾ�ص�������ʼ����
	return 0;
}

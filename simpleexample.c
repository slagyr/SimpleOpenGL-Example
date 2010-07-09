#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>
#include <stdio.h>

#define kWindowWidth 400
#define kWindowHeight 300

typedef GLfloat point[3]; 

GLvoid DrawGLScene(void);
GLvoid ChangeSize(GLsizei w, GLsizei h);
GLvoid RotateSome(void);
GLvoid HandleKeyPress(int key, int x, int y);

int lastFrameTime = 0;
float xVelocity = 0;
float yVelocity = 0;
float xRotation = 45;
float yRotation = 45;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(kWindowWidth, kWindowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow ("simple opengl example");

	glutDisplayFunc(DrawGLScene);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(RotateSome);
	glutSpecialFunc(HandleKeyPress);

	printf("entering glutMainLoop()\n");
	glutMainLoop();
	return 0;
}

GLvoid DrawGLScene(void)
{
	// printf("DrawGLScene\n");
	glClear(GL_COLOR_BUFFER_BIT);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glNormal3d(0, 0, 1);
	GLfloat specular[] = {0, 0, 0, 1};
	glLightfv(GL_LIGHT0, GL_POSITION,  specular);
	GLfloat blue[] = {.1f, .1f, .8f, 1.f};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);

	glTranslatef(0.0, 0.0, -2.0);
	glRotatef(xRotation, 0.0, 1.0, 0.0);
	glRotatef(yRotation, 1.0, 0.0, 0.0);
	
	glutSolidCube(1);
	
	glutSwapBuffers();
}


void ChangeSize(GLsizei w, GLsizei h)
{
	printf("ChangeSize(%d, %d)\n", w, h);
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(60.0f, w/h, 1, 10);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RotateSome(void)
{
	int time;
	time = glutGet(GLUT_ELAPSED_TIME);
	if(time - lastFrameTime < 20)
		return;
	else
		lastFrameTime = time;
		
	xRotation += xVelocity;
	if(xRotation >= 360)
		xRotation -= 360;
	else if(xRotation <= 0)
		xRotation += 360;
		
	yRotation += yVelocity;
	if(yRotation >= 360)
		yRotation -= 360;
	else if(yRotation <= 0)
		yRotation += 360;
		
	glLoadIdentity();
	glutPostRedisplay();
}

void HandleKeyPress(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP : 
			yVelocity += 0.1;
			break;
		case GLUT_KEY_DOWN : 
			yVelocity -= 0.1;
			break;
		case GLUT_KEY_LEFT :
			xVelocity -= 0.1;
			break;
		case GLUT_KEY_RIGHT :
			xVelocity += 0.1;
			break;
	}
	
	if(xVelocity < -5)
		xVelocity = -5;
	else if(xVelocity > 5)
		xVelocity = 5;
		

	if(yVelocity < -5)
		yVelocity = -5;
	else if(yVelocity > 5)
		yVelocity = 5;
		
	printf("x: %f y: %f\n", xVelocity, yVelocity);
}

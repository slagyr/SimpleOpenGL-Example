#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define kWindowWidth 400
#define kWindowHeight 300

typedef GLfloat point[3]; 

// point v[4] ={{0.0, 0.0, 1.0}, 
//              {0.0, 0.942809, -0.333333}, 
//              {-0.816497, -0.471405, -0.333333}, 
//              {0.816497, -0.471405, -0.333333}};


GLvoid DrawGLScene(void);
// void tetrahedron(void);
// void triangle(point a, point b, point c);
void cube();
void square(point a, point b, point c, point d);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(kWindowWidth, kWindowHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow ("simple opengl example");

  glutDisplayFunc(DrawGLScene);

  glutMainLoop();
  return 0;
}

GLvoid DrawGLScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(1.0,1.0,1.0); 
  glLoadIdentity(); 

  glRotatef(45, 0.5, 0.5, 0.5);

  // tetrahedron(); 
  cube();
  glutSwapBuffers();
}

void cube()
{
	point ftl = {-0.5, 0.5, 0.5};
	point ftr = {0.5, 0.5, 0.5};
	point fbl = {-0.5, -0.5, 0.5};
	point fbr = {0.5, -0.5, 0.5};
	point btl = {-0.5, 0.5, -0.5};
	point btr = {0.5, 0.5, -0.5};
	point bbl = {-0.5, -0.5, -0.5};
	point bbr = {0.5, -0.5, -0.5};

	square(ftl, ftr, fbr, fbl); //front
	square(fbl, fbr, bbr, bbl); //bottom
	square(btl, btr, bbr, bbl); // back
	square(btl, btr, ftr, ftl); //top
	square(ftr, btr, bbr, fbr); //right
	square(ftl, fbl, bbl, btl); //left
}

void square(point a, point b, point c, point d)
{
  glBegin(GL_LINE_LOOP);
  glVertex3fv(a); 
  glVertex3fv(b); 
  glVertex3fv(c); 
  glVertex3fv(d);
  glEnd();	
}

// void triangle( point a, point b, point c) 
// { 
//   glBegin(GL_LINE_LOOP);
//   glVertex3fv(a); 
//   glVertex3fv(b); 
//   glVertex3fv(c); 
//   glEnd(); 
// }
// 
// void tetrahedron(void) 
// { 
//   triangle(v[0], v[1], v[2]); 
//   triangle(v[3], v[2], v[1]); 
//   triangle(v[0], v[2], v[3]); 
// } 

//*****************************************************
//
// pratica4.cpp
// Visualização 3D
//
//*****************************************************
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
GLfloat angle, fAspect, width, height, xcamera, ycamera, zcamera, xlookat, ylookat, zlookat, camera_rotation_angle, camera_rotation_radius = 200;

GLfloat hilt_width = 2.0;
GLfloat hilt_height = 20.0;

GLfloat needle_rotation = 0.0;
GLfloat needle_max_height = 10.0;
GLfloat needle_min_height = -10.0;
GLfloat needle_height_change = 0.0;
GLfloat needle_height_change_direction = 1.0;

GLfloat base_height = 10.0;
GLfloat base_width = 200.0;
GLfloat base_depth = 200.0;
GLfloat base_position_y = -50.0;

GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
GLint specular_exponent = 100;
GLfloat ambient_light[] = {0.2, 0.2, 0.2, 1.0};
GLfloat diffuse_light[] = {0.8, 0.8, 0.8, 1.0};
GLfloat specular_light[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position[] = {10.0, 40.0, 0.0, 1.0};


void DrawSword(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.8f, 0.8f, 0.8f);

	glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 20.0, -5);
		glVertex3f(-10.0, 20.0, 0.0);
		glVertex3f(0.0, 20.0, 5);
		glVertex3f(10.0, 20.0, 0.0);
	glEnd();

	// glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(hilt_width / 2.0, 20.0, hilt_width / 2.0);
		glVertex3f(hilt_width / 2.0, 20.0 + hilt_height, hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0 + hilt_height, hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0, hilt_width / 2.0);

		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(-hilt_width / 2.0, 20.0, hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0 + hilt_height, hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0 + hilt_height, -hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0, -hilt_width / 2.0);

		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(-hilt_width / 2.0, 20.0, -hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0 + hilt_height, -hilt_width / 2.0);
		glVertex3f(hilt_width / 2.0, 20.0 + hilt_height, -hilt_width / 2.0);
		glVertex3f(hilt_width / 2.0, 20.0, -hilt_width / 2.0);

		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(hilt_width / 2.0, 20.0, -hilt_width / 2.0);
		glVertex3f(hilt_width / 2.0, 20.0 + hilt_height, -hilt_width / 2.0);
		glVertex3f(hilt_width / 2.0, 20.0 + hilt_height, hilt_width / 2.0);
		glVertex3f(hilt_width / 2.0, 20.0, hilt_width / 2.0);

		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(hilt_width / 2.0, 20.0 + hilt_height, hilt_width / 2.0);
		glVertex3f(hilt_width / 2.0, 20.0 + hilt_height, -hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0 + hilt_height, -hilt_width / 2.0);
		glVertex3f(-hilt_width / 2.0, 20.0 + hilt_height, hilt_width / 2.0);
	glEnd();


	glBegin(GL_POLYGON);
		glNormal3f(-0.445976f, -0.074329f,  0.891953f);
		glVertex3f(0.0, 20.0, 5);
		glVertex3f(-10.0, 20.0, 0.0);
		glVertex3f(0.0, -40.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3f(0.445976f, -0.074329f,  0.891953f);
		glVertex3f(10.0, 20.0, 0.0);
		glVertex3f(0.0, 20.0, 5);
		glVertex3f(0.0, -40.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3f(0.445976f, -0.074329f, -0.891953f);
		glVertex3f(0.0, 20.0, -5);
		glVertex3f(10.0, 20.0, 0.0);
		glVertex3f(0.0, -40.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3f(-0.445976f, -0.074329f, -0.891953f);
		glVertex3f(-10.0, 20.0, 0.0);
		glVertex3f(0.0, 20.0, -5);
		glVertex3f(0.0, -40.0, 0.0);
	glEnd();

	// glutSwapBuffers();
}

void DrawBase(void)
{
	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(base_width / 2, base_position_y, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y, -base_depth / 2);
		glVertex3f(base_width / 2, base_position_y, -base_depth / 2);

		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(base_width / 2, base_position_y - base_height, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y - base_height, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y - base_height, -base_depth / 2);
		glVertex3f(base_width / 2, base_position_y - base_height, -base_depth / 2);

		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(base_width / 2, base_position_y, base_depth / 2);
		glVertex3f(base_width / 2, base_position_y, -base_depth / 2);
		glVertex3f(base_width / 2, base_position_y - base_height, -base_depth / 2);
		glVertex3f(base_width / 2, base_position_y - base_height, base_depth / 2);

		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(base_width / 2, base_position_y, base_depth / 2);
		glVertex3f(base_width / 2, base_position_y - base_height, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y - base_height, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y, base_depth / 2);

		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(-base_width / 2, base_position_y, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y - base_height, base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y - base_height, -base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y, -base_depth / 2);

		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(-base_width / 2, base_position_y, -base_depth / 2);
		glVertex3f(base_width / 2, base_position_y, -base_depth / 2);
		glVertex3f(base_width / 2, base_position_y - base_height, -base_depth / 2);
		glVertex3f(-base_width / 2, base_position_y - base_height, -base_depth / 2);
	glEnd();

	// glutSwapBuffers();
}

void Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawBase();

	glPushMatrix();
		glTranslated(0.0, needle_height_change, 0.0);
		glRotated(needle_rotation, 0.0, 1.0, 0.0);
		DrawSword();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void Initialize(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// glEnable(GL_CULL_FACE);
	// glCullFace(GL_BACK);

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMateriali(GL_FRONT, GL_SHININESS, specular_exponent);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);

	angle = 45;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void SetGLParameters(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, fAspect, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(xcamera, ycamera, zcamera,  // camera position
			  xlookat, ylookat, zlookat,		  // target position
			  0, 1, 0);		 // UP vector
}

void SetWindowSize(GLint width, GLint height)
{
	if (height == 0) height = 1;

	glViewport(0, 0, width, height);

	fAspect = (GLfloat)width / (GLfloat)height;

	SetGLParameters();
}


// Função callback chamada para gerenciar teclas especiais
void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		ycamera += 10;
	}
	if (key == GLUT_KEY_DOWN) {
		ycamera -= 10;
	}

	if (key == GLUT_KEY_RIGHT) {
		camera_rotation_angle += 0.1;
		xcamera = camera_rotation_radius * cos(camera_rotation_angle);
		zcamera = camera_rotation_radius * sin(camera_rotation_angle);
	}
	if (key == GLUT_KEY_LEFT) {
		camera_rotation_angle -= 0.1;
		xcamera = camera_rotation_radius * cos(camera_rotation_angle);
		zcamera = camera_rotation_radius * sin(camera_rotation_angle);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer
	SetGLParameters();
	glutPostRedisplay();
}

// Função callback chamada para gerenciar teclado
void KeyboardManagement(unsigned char key, int x, int y) {
	switch (key) {
		case ' ': // restaura posição inicial da camera
			camera_rotation_angle = 0;
			// camera_rotation_radius = 100;
			xcamera = camera_rotation_radius * cos(camera_rotation_angle);
			zcamera = camera_rotation_radius * sin(camera_rotation_angle);

			ycamera = 0;
			xlookat = 0;
			zlookat = 0;
			ylookat = 0;
			break;

		case 'w':
			// xlookat += 10;
			xcamera -= 10;
			camera_rotation_radius -= 10;
			break;

		case 'a':
			// zlookat += 10;

			break;

		case 's':
			// xlookat -= 10;
			xcamera += 10;
			camera_rotation_radius += 10;
			break;

		case 'd':
			// zlookat -= 10;

			break;

		case 'q':
			ylookat += 10;
			break;

		case 'e':
			ylookat -= 10;
			break;


	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer
	SetGLParameters();
	glutPostRedisplay();
}

//função callback que será chamada após o tempo especificado
void TimeControl(int value) {
	needle_rotation += 5;
	needle_height_change += needle_height_change_direction * 0.5;
	if (needle_height_change > needle_max_height)
	{
		needle_height_change_direction = -1.0;
	} else if (needle_height_change < needle_min_height)
	{
		needle_height_change_direction = 1.0;
	}
	// Redesenha a cena e executa o timer novamente para ter uma animacao continua
	glutPostRedisplay();
	glutTimerFunc(100, TimeControl, 1);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(700,100);
	width = 800;
	height = 700;
	glutInitWindowSize(width,height);
	fAspect = (GLfloat)width / (GLfloat)height;
	camera_rotation_angle = 0;
	// camera_rotation_radius = 600;
	xcamera = camera_rotation_radius * cos(camera_rotation_angle);
	zcamera = camera_rotation_radius * sin(camera_rotation_angle);
	ycamera = 0;
	angle = 45;
	glutCreateWindow("Knight's Needle");
	xlookat = 0;
	ylookat = 0;
	zlookat = 0;
	glutTimerFunc(100, TimeControl, 1);
	glutDisplayFunc(Draw);
	glutReshapeFunc(SetWindowSize);
	glutKeyboardFunc(KeyboardManagement); // Define qual funcao gerencia o comportamento do teclado
	glutSpecialFunc(SpecialKeys);
	Initialize();
	glutMainLoop();

}

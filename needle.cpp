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

GLfloat base_height = 2.5;
GLfloat base_size_reference = 150.0;
GLfloat base_size;
GLfloat base_position_y = -50.0;
GLfloat step_variance;
GLfloat step_number = 0.0;
GLfloat step_scale_factor = 1.1;
int number_of_steps = 4;

GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
GLint specular_exponent = 100;
GLfloat ambient_light[] = {0.2, 0.2, 0.2, 1.0};
GLfloat specular_light[] = {1.0, 1.0, 1.0, 1.0};

GLfloat diffuse_light0[] = {0.8, 0.8, 0.8, 1.0};
GLfloat light_position0[] = {0.0, 200.0, 0.0, 1.0};

GLfloat diffuse_light1[] = {0.2, 0.8, 0.2, 1.0};
GLfloat light_position1[] = {base_size_reference / 2.0f, -30.0, base_size_reference / 2.0f, 1.0};

GLfloat diffuse_light2[] = {0.8, 0.2, 0.2, 1.0};
GLfloat light_position2[] = {-base_size_reference / 2.0f, -30.0, base_size_reference / 2.0f, 1.0};

GLfloat diffuse_light3[] = {0.2, 0.2, 0.8, 1.0};
GLfloat light_position3[] = {base_size_reference / 2.0f, -30.0, -base_size_reference / 2.0f, 1.0};

GLfloat diffuse_light4[] = {0.5, 0.4, 0.6, 1.0};
GLfloat light_position4[] = {-base_size_reference / 2.0f, -30.0, -base_size_reference / 2.0f, 1.0};


void DrawSword(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.95f, 0.95f, 0.95f);

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
	base_size = base_size_reference;
	step_variance = base_height;
	step_number = 0.0;

	glColor3f(0.65f, 0.65f, 0.65f);
	glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(base_size / 2, base_position_y, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y, -base_size / 2);
		glVertex3f(base_size / 2, base_position_y, -base_size / 2);

		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(base_size / 2, base_position_y - base_height, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - base_height, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - base_height, -base_size / 2);
		glVertex3f(base_size / 2, base_position_y - base_height, -base_size / 2);

		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(base_size / 2, base_position_y, base_size / 2);
		glVertex3f(base_size / 2, base_position_y, -base_size / 2);
		glVertex3f(base_size / 2, base_position_y - base_height, -base_size / 2);
		glVertex3f(base_size / 2, base_position_y - base_height, base_size / 2);

		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(base_size / 2, base_position_y, base_size / 2);
		glVertex3f(base_size / 2, base_position_y - base_height, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - base_height, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y, base_size / 2);

		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(-base_size / 2, base_position_y, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - base_height, base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - base_height, -base_size / 2);
		glVertex3f(-base_size / 2, base_position_y, -base_size / 2);

		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(-base_size / 2, base_position_y, -base_size / 2);
		glVertex3f(base_size / 2, base_position_y, -base_size / 2);
		glVertex3f(base_size / 2, base_position_y - base_height, -base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - base_height, -base_size / 2);
	glEnd();

	for (int i = 0; i < number_of_steps; i++) {
		base_size *= step_scale_factor;
		step_number += 1.0;

		glBegin(GL_QUADS);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);
			glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);

			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(base_size / 2, base_position_y - base_height - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - base_height - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - base_height - (step_variance * step_number), -base_size / 2);
			glVertex3f(base_size / 2, base_position_y - base_height - (step_variance * step_number), -base_size / 2);

			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);
			glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);
			glVertex3f(base_size / 2, base_position_y - base_height - (step_variance * step_number), -base_size / 2);
			glVertex3f(base_size / 2, base_position_y - base_height - (step_variance * step_number), base_size / 2);

			glNormal3f(0.0, 0.0, 1.0);
			glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);
			glVertex3f(base_size / 2, base_position_y - base_height - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - base_height - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);

			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - base_height - (step_variance * step_number), base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - base_height - (step_variance * step_number), -base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);

			glNormal3f(0.0, 0.0, -1.0);
			glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);
			glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);
			glVertex3f(base_size / 2, base_position_y - base_height - (step_variance * step_number), -base_size / 2);
			glVertex3f(-base_size / 2, base_position_y - base_height - (step_variance * step_number), -base_size / 2);
		glEnd();
	}

	base_size *= 5;
	step_number += 1.0;

	glColor3f(0.3f, 0.8f, 0.4f);
	glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), base_size / 2);
		glVertex3f(-base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);
		glVertex3f(base_size / 2, base_position_y - (step_variance * step_number), -base_size / 2);
	glEnd();

	// glutSwapBuffers();
}

void DrawSpike(void)
{
	glutWireCone(5.0, 20.0, 16, 16);
}

void Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawBase();
	DrawSpike();
	glPushMatrix();
		glTranslated(base_size / 2.0, base_position_y, base_size / 2.0);
		DrawSpike();
	glPopMatrix();
	// glPushMatrix();
	// 	glTranslated(-base_size / 2.0, base_position_y, base_size / 2.0);
	// 	DrawSpike();
	// glPopMatrix();
	// glPushMatrix();
	// 	glTranslated(base_size / 2.0, base_position_y, -base_size / 2.0);
	// 	DrawSpike();
	// glPopMatrix();
	// glPushMatrix();
	// 	glTranslated(-base_size / 2.0, base_position_y, -base_size / 2.0);
	// 	DrawSpike();
	// glPopMatrix();

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
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light2);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position2);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light3);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position3);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light4);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position4);

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
	gluPerspective(angle, fAspect, 0.1, 10000);

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
			camera_rotation_radius = 200;
			xcamera = camera_rotation_radius * cos(camera_rotation_angle);
			zcamera = camera_rotation_radius * sin(camera_rotation_angle);

			ycamera = 0;
			xlookat = 0;
			zlookat = 0;
			ylookat = 0;
			break;

		case 'w':
			xcamera -= 10 * cos(camera_rotation_angle);
    		zcamera -= 10 * sin(camera_rotation_angle);

    		camera_rotation_radius = sqrt(xcamera*xcamera + zcamera*zcamera);
			break;

		case 'a':
			zcamera -= 10;
			zlookat += 10;
			break;

		case 's':
			xcamera += 10 * cos(camera_rotation_angle);
    		zcamera += 10 * sin(camera_rotation_angle);
			
    		camera_rotation_radius = sqrt(xcamera*xcamera + zcamera*zcamera);
    		break;

		case 'd':
			zlookat -= 10;
			zcamera += 10;
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

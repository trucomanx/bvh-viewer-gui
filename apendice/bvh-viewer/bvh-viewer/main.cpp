////////////////////////////////////////////////////////////
//  Created by Yuki Koyama.                               //
//  Copyright (c) 2012 Yuki Koyama. All rights reserved.  //
//  http://www-ui.is.s.u-tokyo.ac.jp/~koyama/             //
//                                                        //
//  This is released for NON-COMMERCIAL use only.         //
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#if(APPLE)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "BVHObject.h"

using namespace std;

namespace {
    clock_t   timeRecorder;
    BVHObject bvhObject;
    int       frameNumber = 0;
    int       width       = 1024;
    int       height      = 768;
    
    const Vector3d eyePoint(- 3.0, 3, 8.0);
    const Vector3d focusPoint(0.0, 1.5, 0.0);
    const Vector3d upDirection(0.0, 1.0, 0.0);
    const GLfloat  lightPosition[4] = { - 5.0f, 10.0f, 10.0f, 1.0f };
    const float    wallSize         = 20.0f;
    const float    modelScale       = 0.060f;
    const string   fileName         = string("sample.bvh");
}

extern void glut_display(void);
extern void glut_reshape(int w, int h);
extern void glut_idle(void);
extern void glut_mouse(int button, int state, int x, int y);
extern void glut_motion(int x, int y);
extern void glut_keyboard (unsigned char key, int x, int y);

void init() {
    
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDisable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glCullFace(GL_BACK);
	glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);

	const GLfloat lightColor[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat lightAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
	
    const GLfloat ambient[]   = { 0.2f, 0.2f, 0.2f, 1.0f };
	const GLfloat specular[]  = { 0.4f, 1.0f, 0.4f, 1.0f };
    const GLfloat shininess[] = { 40.0f };
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void scene(void) {
    // wall
    const float size = wallSize;
    const float d    = size / 10.0f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    for (double dx0 = - size; dx0 < size; dx0 += d) {
        for (double dy0 = - size; dy0 < size; dy0 += d) {
            double dx1 = dx0 + d, dy1 = dy0 + d;
            glVertex3f(dx0, 0.0, dy0);
            glVertex3f(dx0, 0.0, dy1);
            glVertex3f(dx1, 0.0, dy1);
            glVertex3f(dx1, 0.0, dy0);
        }
    }
    glEnd();
    
    // character
    if (bvhObject.ready) {
        const float scale = modelScale;
        glColor3f(1.0f, 0.0f, 0.0f);
        glScalef(scale, scale, scale);
        bvhObject.render(frameNumber);
        
        frameNumber ++;
        frameNumber %= bvhObject.nFrames;
    }
}

void glut_display(void) {
    // draw scene
    const Vector3d& e = eyePoint;
    const Vector3d& f = focusPoint;
    const Vector3d& u = upDirection;
    
    // Set OpenGL viewport and camera
    int w = width;
    int h = height;
    glViewport(0, 0, w, h);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // camera setting
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (double)w/h, 0.3, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(e.x_, e.y_, e.z_, f.x_, f.y_, f.z_, u.x_, u.y_, u.z_);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    scene();
    
	glutSwapBuffers();
}

void glut_reshape(int w, int h) {
    width  = w;
    height = h;
}

void glut_idle(void) {
    clock_t targetInterval = static_cast<clock_t>(1000.0 * 1000.0 * bvhObject.interval);
    if (clock() - timeRecorder > targetInterval) {
        glutPostRedisplay();
        timeRecorder = clock();
    }
}

void glut_mouse(int button, int state, int x, int y) {  }
void glut_motion(int x, int y) {  }
void glut_keyboard (unsigned char key, int x, int y) {  }
void glut_special (int key, int x, int y) {  }

int main(int argc, const char **argv) {
    glutInit(&argc, const_cast<char **>(argv));
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("BVH Player");
    
    glutDisplayFunc(glut_display);
    glutReshapeFunc(glut_reshape);
    glutIdleFunc(glut_idle);
    glutMouseFunc(glut_mouse);
    glutMotionFunc(glut_motion);
    glutPassiveMotionFunc(glut_motion);
    glutKeyboardFunc(glut_keyboard);
    glutSpecialFunc(glut_special);
    
    init();
    
    bvhObject.init(fileName);
    
    timeRecorder = clock();
    
    glutMainLoop();
    
    return 0;
}


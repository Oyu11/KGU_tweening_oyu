#include <GL/glut.h>
#include <iostream>
#include <cmath>
float t = 0.0;
int state = 1;
void drawPolygon(float radius, int sides) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; i++) {
        float angle = 2.0 * M_PI * i / sides;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float radius1 = 0.1 + 0.4 * t;
    float radius2 = 0.5 + 0.4 * t;
    int sides = 5 + 15 * t;
    glColor3f(1.0 - t, 0.0, t);
    drawPolygon(radius1, sides);
    glColor3f(t, 0.0, 1.0 - t);
    drawPolygon(radius2, sides);
    switch (state) {
        case 1:
            if (t < 1) t += 0.01;
            else state = -1;
            break;
        case -1:
            if (t > 0) t -= 0.01;
            else state = 1;
            break;
    }
    glutSwapBuffers();
}
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(120, timer, 0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Animation");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutTimerFunc(60, timer, 0);
    glutMainLoop();
    return 0;
}
//tweening hiij bui heseg ali n ve
//zurj bui heseg ali n ve

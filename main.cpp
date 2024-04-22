#include <GL/glut.h>
#include <iostream>
#include <cmath>

float t = 0.0;
int state = 1;

void drawPentagon(float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 5; i++) {
        float angle = 2.0 * M_PI * i / 5;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawTwentySidedPolygon(float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 20; i++) {
        float angle = 2.0 * M_PI * i / 20;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void tween_pol(float t, float radiusA, float radiusB) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 20; i++) {
        float angleA = 2.0 * M_PI * i / 5;
        float xA = radiusA * cos(angleA);
        float yA = radiusA * sin(angleA);

        float angleB = 2.0 * M_PI * i / 20;
        float xB = radiusB * cos(angleB);
        float yB = radiusB * sin(angleB);

        float x = (1 - t) * xA + t * xB;
        float y = (1 - t) * yA + t * yB;

        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    drawPentagon(0.5);

    glColor3f(0.0, 1.0, 0.0);
    drawTwentySidedPolygon(0.5);

    // Tweening animation
    glColor3f(0.0, 0.0, 1.0);
    tween_pol(t, 0.5, 0.5);

    switch (state) {
        case 1:
            if (t < 1) t += 0.01;
            else state = -1;
            break;
        case -1:
            if (t > 0) t -= 0.01;
            break;
    }

    glutSwapBuffers();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Tweening Oyu");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutTimerFunc(20, timer, 0);
    glutMainLoop();
    return 0;
}

#define NUM_BUBBLES 15
#define NUM_PEBBLES 100
float bubbleY[NUM_BUBBLES];
float bubbleX[NUM_BUBBLES];
float bubbleSpeed[NUM_BUBBLES];
float pebbleX[NUM_PEBBLES];
float pebbleY[NUM_PEBBLES];
float pebbleRadius[NUM_PEBBLES];
float pebbleColor[NUM_PEBBLES][3];
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

float s = 400, ss = 140, a = 0, b = 0, aa = -70, bb = 0, flag = 0, flag3 = 0, flag4 = 0;
float x = 100, y = 0, r = 0.5, y11 = 0, y21 = 0, y31 = 0, y41 = 0, y51 = 0, y61 = 0, y71 = 0, y81 = 0, y91 = 0, y10 = 0, y12 = 0, y13 = 0, y14 = 0, x0 = 0, xo = 0, angle = 0.0, pi = 3.142;
float fish_x = 0.0;
float fish_y = 0.0;
float fish4_x = 500.0;
float fish4_y = 0.0;
float fish_speed = 0.5;
float time = 0.0;
float offset_x=0.0;
float offset_y=0.0;
int animationSpeed = 1;


void init(void) {
    glClearColor(0.0, 0.6, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}


void fish1(void) {
    glColor3f(0.0, 0.0, 0.545);
    glBegin(GL_POLYGON);
    glVertex2f(270 + a, 350 + aa);
    glVertex2f(300 + a, 325 + aa);
    glVertex2f(370 + a, 350 + aa);
    glVertex2f(300 + a, 375 + aa);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(360 + a, 350 + aa);
    glColor3ub(rand() % 256, rand() % 256, rand() % 256);
    glVertex2f(405 + a, 370 + aa);
    glVertex2f(395 + a, 350 + aa);
    glVertex2f(405 + a, 327 + aa);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 256, rand() % 256, rand() % 256);
    glVertex2f(302 + a, 373 + aa);
    glColor3f(0.0, 0.0, 0.545);
    glVertex2f(340 + a, 409 + aa);
    glVertex2f(320 + a, 360 + aa);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 256, rand() % 256, 0);
    glVertex2f(302 + a, 328 + aa);
    glColor3f(0.0, 0.0, 0.545);
    glVertex2f(340 + a, 300 + aa);
    glVertex2f(320 + a, 340 + aa);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(280 + a, 355 + aa);
    glEnd();
}

void fish2(float offset_y,float time) {
    float amplitude = 35.0;
    float frequency = 0.4;  
    float wave_offset_y = amplitude * sin(frequency * time);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(70 + offset_y, 145 + wave_offset_y);
    glColor3ub(rand() % 256, rand() % 256, 0);
    glVertex2f(20 + offset_y, 120 + wave_offset_y);
    glVertex2f(30 + offset_y, 145 + wave_offset_y); 
    glVertex2f(20 + offset_y, 170 + wave_offset_y); 
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(65 + offset_y, 145 + wave_offset_y); 
    glVertex2f(125 + offset_y, 170 + wave_offset_y); 
    glVertex2f(165 + offset_y, 145 + wave_offset_y); 
    glVertex2f(125 + offset_y, 120 + wave_offset_y); 
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 256, rand() % 256, 0);
    glVertex2f(126 + offset_y, 168 + wave_offset_y); 
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(105 + offset_y, 206 + wave_offset_y); 
    glVertex2f(95 + offset_y, 155 + wave_offset_y); 
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 256, rand() % 256, 0);
    glVertex2f(126 + offset_y, 122 + wave_offset_y); 
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(105 + offset_y, 90 + wave_offset_y); 
    glVertex2f(95 + offset_y, 140 + wave_offset_y); 
    glEnd();

    glColor3f(0.0, 0.0, 0.0); 
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(142 + offset_y, 151 + wave_offset_y);
    glEnd();

    glColor3f(1.0, 1.0, 1.0); 
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2f(143 + offset_y, 152 + wave_offset_y); 
    glEnd();
}

void fish3(void) {
    // Same as fish1
}

void fish4(float offset_x, float time) {
    // Same as fish2
}

void fish5(float offset_x, float time) {
    // Same as fish1
}

void fish6(float offset_x, float offset_y) { 
    // Same as fish2
}

void fish7(float offset_x, float offset_y) {
    // Same as fish1
}

void plant1L(int x1, int x2, int m) {
    float y1 = 0, y2 = 0, p1 = 0, p2 = 0;
    float length = 15;
    float scale_factor = 3.0; 

    glColor3f(0.0, 0.392, 0.0);

    for (p1 = x1, p2 = x2; p1 <= p2; p1 += 2, p2 -= 2) {
        y1 = sin(p1 * 3.14 / 180);
        y2 = sin(p2 * 3.14 / 180);
        y1 *= 5 * scale_factor;
        y2 *= 5 * scale_factor;

        glBegin(GL_LINES);
        glVertex2f(p1, y1 + m);
        glVertex2f(p2, y2 + m);
        glEnd();

        // Draw leaves
        glBegin(GL_LINES);
        glVertex2f(p1, y1 + m);
        glVertex2f(p1 - 2, y1 + m + length * scale_factor);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(p2, y2 + m);
        glVertex2f(p2 + 2, y2 + m + length * scale_factor);
        glEnd();
    }
}

void plant2L(int x1, int x2, int m) {
   // Same as Plant1L
}

void plant3L(int x1, int x2, int m) {
    // Same as Plant1L
}

void plant4L(int x1, int x2, int m) {
    // Same as Plant1L
}

void plant5L(int x1, int x2, int m) {
    // Same as Plant1L
}

void plant6L(int x1, int x2, int m) {
    // Same as Plant1L
}

void plant7L(int x1, int x2, int m) {
    // Same as Plant1L
}

void plant8L(int x1, int x2, int m) {
    // Same as Plant1L
}

void plant9L(int x1, int x2, int m) {
    // Same as Plant1L
}

void plant10L(int x1, int x2, int m) {
    // Same as Plant1L
}

void initBubbles() {
    for (int i = 0; i < NUM_BUBBLES; i++) {
        bubbleX[i] = rand() % 500; 
        bubbleY[i] = rand() % 500; 
        bubbleSpeed[i] = 1 + (rand() % 3) * 0.1; 
    }
}

void drawBubbles(float x, float y, float radius) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0.8, 0.8, 0.8, 0.5); 
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14159 * i / 300;
        double dx = radius * cos(angle);
        double dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();

    glDisable(GL_BLEND);
}

void updateBubbles(float *y, float speed) {
    *y += speed;
    if (*y > 500) { 
        *y = 0;
    }
}

void setupViewport() {
    glViewport(0, 0, 600, 800); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 800); 
    glMatrixMode(GL_MODELVIEW);
}

void initPebbles() {
    for (int i = 0; i < NUM_PEBBLES; ++i) {
        pebbleX[i] = rand() % 500; 
        pebbleY[i] = rand() % 50;  
        pebbleRadius[i] = 5 + rand() % 10; 
        pebbleColor[i][0] = (float)rand() / RAND_MAX; 
        pebbleColor[i][1] = (float)rand() / RAND_MAX; 
        pebbleColor[i][2] = (float)rand() / RAND_MAX; 
    }
}

void drawPebble(float x, float y, float radius, float color[3]) {
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); 
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * M_PI / 180.0;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawPebbles() {
    for (int i = 0; i < NUM_PEBBLES; ++i) {
        drawPebble(pebbleX[i], pebbleY[i], pebbleRadius[i], pebbleColor[i]);
    }
}

void speed(void) {
    animationSpeed++;
}

void slow(void) {
    if (animationSpeed > 1) {
        animationSpeed--;
    }
}

void drawSineWave(void) {
    int i;
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < 720; i++) {
        float x = i;
        float y = 100 + 30 * sin(x * 3.14159 / 180);
        glVertex2f(x, y+10);
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSineWave();
    plant1L(50,70,50); 
    plant2L(150,170,50);
    plant3L(250,270,50); 
    plant4L(350,370,50); 
    plant5L(450,470,50);
    plant6L(0,20,50);
    plant7L(100,120,50);
    plant8L(200,220,50);
    plant9L(300,320,50);
    plant10L(400,420,50);
    // Draw fish
    time += 0.1;
     offset_x -= 1.0;
    if (offset_x < -400) { 
        offset_x = 800;
    }
     offset_y += 1.0;
    if (offset_y > 800) { 
        offset_y = -400;
    }
    fish1();
    fish2(offset_y,time);
    fish3();
    fish4(offset_x,time);
    fish5(offset_x,time);
    fish6(fish_x, fish_y);
    fish7(fish4_x, fish4_y);
 
    for (int i = 0; i < NUM_BUBBLES; i++) {
        drawBubbles(bubbleX[i], bubbleY[i], 10); 
    }

    drawPebbles();
    glFlush();
    glutSwapBuffers();
}

void mov(void) {
    a -= 0.5 * animationSpeed; 
    b += 0.5 * animationSpeed; 
    if (a < -500) a = 500; 
    if (b > 500) b = -500; 
}

void idle(void) {
    mov();
    for (int i = 0; i < NUM_BUBBLES; i++) {
        updateBubbles(&bubbleY[i], bubbleSpeed[i]);
    }
    fish_x += fish_speed;
    fish_y += fish_speed;
    if (fish_x > 500) fish_x = 0;
    if (fish_y > 500) fish_y = 0;
    fish4_x -= fish_speed;
    fish4_y += fish_speed;
    if (fish4_x < 0) fish4_x = 500; 
    if (fish4_y > 500) fish4_y = 0;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Virtaul Aquarium");

    init();
    initBubbles();
    initPebbles();
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}

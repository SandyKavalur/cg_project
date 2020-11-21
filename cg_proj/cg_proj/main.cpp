#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

float x = .70, y = .40, z = .09;
int i = 0, j = 0;
float x_pos = 0;
float c1 = 0, f1 = 0;
int height = 500;
int width = 600;
float sx = 227, sy = 106, sz = 14;
int state = 1, state1 = 0, c11 = 0;
float fx = 0, fy = 0;
int speed = 4;
int stars[][2] = { {10,-15},{80,10},{150,-5},{220,15},{290,30},{360,-25},{410,50},{480,15} };
int bi = 0;
int stateb = 0;
int bird1[][2] = { {10,300},{40,330},{70,270},{100,300} };
int mountposition[][2] = { {0,150},{200,160},{350,140} };
int xb = 650;
int beeposition[][2] = { {0,0},{60,60},{90,90},{0,90} };
float x2 = 142, y2 = 237, z2 = 9;
int day = 0, night = 0;
float yt = 0;
int days = 0;
int angle1 = 0;
int pd = 1;
int petaldropposition[][4] = { {90,180,250,0},{45,160,150,0} };

GLdouble mountainpoints[][2] = { {1,0},{0,0},{0.125,0.1},{0.225,0.12},{0.35,0.14},{0.45,0.19},{0.556,0.28},{.610,.35},{.750,.59},
{.81,.75},{.89,.85},{.93,.90},{.95,.91},{.97,.91},{1.125,0.90},{1.225,.85},{1.35,.75},{1.45,.59},{1.556,.35},{1.610,.28},
{1.750,.19},{1.81,.14},{1.89,.12},{1.93,.01},{2,0} };
int cloudposition[][3] = { {0,0,0},{-400,0,0},{-800,0,0} };
void drawCircleFilled(double centerX, double centerY, double radiusX, double radiusY)
{
    const float DEG2RAD = 3.14159 / 180;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = -1; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(centerX + cos(degInRad) * radiusX, centerY + sin(degInRad) * radiusY);
    }
    glEnd();
}
void wing()
{
    glBegin(GL_POLYGON);

    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.167, 0.083, 0.0);
    glVertex3f(1.225, 0.208, 0.0);
    glVertex3f(1.25, 0.42, 0.0);
    glVertex3f(1.23, 0.583, 0.0);
    glVertex3f(1.167, 0.75, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3d(.75, .75, 0);
    glVertex3d(.583, .5, 0);
    glVertex3d(.56, .2, 0);
    glVertex3d(.8, 0, 0);
    glEnd();
}
void leg()
{
    glBegin(GL_LINE_STRIP);
    glVertex3d(255, 225, -2);
    glVertex3d(245, 195, -2);
    glVertex3d(245, 160, -2);
    glEnd();

}
void bee()
{

    glScaled(.3, .3, .3);
    glTranslated(xb, 0, 0);
    glRotated(180, 0, 1, 0);
    //lower body
    glPushMatrix();
    glColor3f(224 / 255.0, 232 / 255.0, 65 / 255.0);
    glTranslated(200, 200, 0);
    glRotated(30, 0, 0, 1);
    drawCircleFilled(0, 0, 50, 20);
    glColor3f(0 / 255.0, 0 / 255.0, 0 / 255.0);
    drawCircleFilled(8, 0, 40, 18);
    glColor3f(224 / 255.0, 232 / 255.0, 65 / 255.0);
    drawCircleFilled(20, 0, 30, 15);
    glColor3f(0 / 255.0, 0 / 255.0, 0 / 255.0);
    drawCircleFilled(30, 0, 20, 12);
    glColor3f(224 / 255.0, 232 / 255.0, 65 / 255.0);
    drawCircleFilled(40, 0, 10, 10);
    glPopMatrix();
    //upper body
    glPushMatrix();
    glColor3f(217 / 255.0, 196 / 255.0, 63 / 255.0);
    glTranslated(265, 230, 0);
    glRotated(15, 0, 0, 1);
    drawCircleFilled(0, 0, 25, 15);
    glPopMatrix();
    glColor3d(0, 0, 0);
    //nose
    glBegin(GL_TRIANGLES);
    glVertex2d(275, 230);
    glVertex2d(280, 235);
    glVertex2d(300, 220);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2d(280, 235);
    glVertex2d(290, 255);
    glVertex2d(310, 265);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2d(285, 235);
    glVertex2d(300, 245);
    glVertex2d(310, 245);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(160, 185);
    glVertex2d(170, 185);
    glVertex2d(158, 155);
    glEnd();
    glPushMatrix();
    leg();
    glPopMatrix();
    glPushMatrix();
    glScaled(.6, .6, 1);
    glTranslated(180, 140, 0);
    leg();
    glPopMatrix();
    glPushMatrix();
    glScaled(.3, .3, 1);
    glTranslated(650, 520, 0);
    leg();
    glPopMatrix();
    if (stateb == 0)
    {
        glPushMatrix();
        glColor3f(239 / 255.0, 245 / 255.0, 157 / 255.0);
        glTranslated(300, 300, 0);
        glScaled(50, 70, 0);
        glRotated(180, 0, 0, 1);
        wing();
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glColor3f(239 / 255.0, 245 / 255.0, 157 / 255.0);
        glTranslated(205, 160, 0);
        glScaled(50, 70, 0);
        glRotated(0, 0, 0, 1);
        wing();
        glPopMatrix();
    }
}
void drawCloud(int g1, int h1)
{
    glTranslated(c1 + c11 / 2, 0, 0);
    glColor3f(1, 1, 1);
    drawCircleFilled(g1, h1, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(g1 + 35, h1, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(g1 + 8, h1 - 5, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(g1 - 2, h1 - 5, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(g1 - 35, h1, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(g1 - 15, h1 + 28, 35, 35);

    float m = g1 + 150;

    glColor3f(1, 1, 1);
    drawCircleFilled(m, h1, 20, 20);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(m + 20, h1, 20, 20);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(m + 8, h1 - 5, 20, 20);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(m - 2, h1 - 5, 20, 20);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(m - 20, h1, 20, 20);
    glColor3f(255.0, 255.0, 255.0);
    drawCircleFilled(m - 10, h1 + 13, 20, 20);
}
void background()
{
    glColor3f(x, y, z);
    glBegin(GL_QUADS);
    glVertex2d(0, height * 35 / 100);
    glVertex2d(width, height * 35 / 100);
    glVertex2d(width, height);
    glVertex2d(0, height);
    glEnd();
    glColor3f(x2 / 255.0, y2 / 255.0, z2 / 255.0);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(width, 0);
    glVertex2d(width, height * 35 / 100);
    glVertex2d(0, height * 35 / 100);
    glEnd();
}
void flower()
{
    glScaled(fx, fy, 0);
    glColor3f(14 / 255.0, 84 / 255.0, 5 / 255.0);
    //stem
    glBegin(GL_POLYGON);
    glVertex3d(60, 0, 0);
    glVertex3d(60, 200, 0);
    glVertex3d(65, 200, 0);
    glVertex3d(65, 0, 0);
    glEnd();
    //leaf
    glPushMatrix();
    glTranslated(95, 95, 0);
    glRotated(45, 0, 0, 1);
    glTranslated(-95, -95, 0);
    drawCircleFilled(100, 100, 40, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(35, 85, 0);
    glRotated(-45, 0, 0, 1);
    glTranslated(-35, -85, 0);
    drawCircleFilled(20, 100, 40, 10);
    glPopMatrix();
    //petals
    glColor3f(1, 1, 0);

    for (int angle = 0; angle < 360; angle = angle + 3 + angle1)
    {
        glTranslated(60, 200, 0);
        glRotated(angle, 0, 0, 1);
        glTranslated(-60, -200, 0);
        drawCircleFilled(60, 200, 50, 5);
    }
    //center
    glColor3f(0, 0, 0);
    drawCircleFilled(60, 200, 30, 30);
}
void moon() {
    glColor3f(1, 1, 1);
    glTranslated(c1 - f1, 0, 0);
    drawCircleFilled(c1 - f1 - 35, 400, 15, 15);
    glColor3f(x, y, z);
    drawCircleFilled(c1 - f1 - 30, 405, 15, 15);
    //clouds
    glPushMatrix();
    drawCloud(-200, 380);
    glPopMatrix();
}
void star() {
    glBegin(GL_TRIANGLES);
    glVertex2d(50, 400);
    glVertex2d(60, 400);
    glVertex2d(55, 415);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(50, 410);
    glVertex2d(60, 410);
    glVertex2d(55, 395);
    glEnd();
}
//bird
void bird()
{
    glScaled(.3, .3, 0);
    glTranslated(bi, 0, 0);
    glPushMatrix();
    //body color
    glColor3f(0, 0, 0);
    //body
    drawCircleFilled(100, 100, 60, 20);
    //face
    drawCircleFilled(175, 100, 20, 20);
    //mouth
    glBegin(GL_TRIANGLES);
    glVertex2d(196, 105);
    glVertex2d(196, 95);
    glVertex2d(215, 100);
    glEnd();
    //tail
    int a[][2] = { {10,110},{10,100},{10,90} };
    for (int i = 0; i < 3; i++)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex2d(40, 100);
        glVertex2d(a[i][0], a[i][1]);
        glEnd();
    }
    //up wing
    if (stateb == 0) {
        glBegin(GL_TRIANGLES);
        glVertex2d(100, 100);
        glVertex2d(150, 150);
        glVertex2d(50, 150);
        glEnd();
    }
    //down wing
    else {
        glBegin(GL_TRIANGLES);
        glVertex2d(100, 100);
        glVertex2d(150, 50);
        glVertex2d(50, 50);
        glEnd();
    }
    //eye
    //eye color
    glColor3b(1, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2d(180, 105);
    glEnd();
    glPopMatrix();
}
//mountain
void mountain()
{
    glScaled(150, 150, 0);
    glColor3d(156 / 255.0, 16 / 255.0, 23 / 255.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 24; i++)
    {
        glVertex2dv(mountainpoints[i]);
    }
    glEnd();
}
//tree
void Strees()
{   //body

    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_POLYGON);
    glVertex2f(140, 45);
    glColor3f(0.502, 0.0, 0.0);
    glVertex2f(150, 170);
    glColor3f(0.545, 0.271, 0.075);
    glVertex2f(160, 45);
    glEnd();
    //branches 1
    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_POLYGON);
    glVertex2f(145, 100);
    glVertex2f(146, 115);
    glVertex2f(120, 145);
    glVertex2f(145, 100);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(151, 155);
    glVertex2f(151, 150);
    glVertex2f(170, 175);
    glVertex2f(153, 155);
    glEnd();
}
void leaf()
{
    glPushMatrix();
    glScaled(20, 20, 0);
    glColor3d(0, 1, 0);

    glBegin(GL_POLYGON);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.167, 0.083, 0.0);
    glVertex3f(1.225, 0.208, 0.0);
    glVertex3f(1.25, 0.42, 0.0);
    glVertex3f(1.23, 0.583, 0.0);
    glVertex3f(1.167, 0.75, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex2d(.75, .75);
    glVertex2d(.583, .5);
    glVertex2d(.56, .2);
    glVertex2d(.8, 0);
    glEnd();
    glPopMatrix();
}
void leaves()
{
    glPushMatrix();
    glTranslated(160, 182, 0);
    glRotated(-40, 0, 0, 1);
    leaf();
    glPopMatrix();
    glPushMatrix();
    glTranslated(150, 163, 0);
    glRotated(40, 0, 0, 1);
    leaf();
    glPopMatrix();
    glPushMatrix();
    glTranslated(170, 180, 0);
    glRotated(-100, 0, 0, 1);
    leaf();
    glPopMatrix();
}
void tree()
{
    glColor3d(1, 0, 0);
    glScaled(.7, .7 + yt, 0);
    Strees();

    glPushMatrix();
    leaves();
    glPopMatrix();

    glPushMatrix();
    glRotated(80, 0, 0, 1);
    glTranslated(-5, -260, 0);
    leaves();
    glPopMatrix();

    glPushMatrix();
    glRotated(65, 0, 0, 1);
    glTranslated(45, -225, 0);
    leaves();
    glPopMatrix();
}
void PrintText(float x, float y, void* font, int col, char* string)
{
    int len;
    glColor3d(0, 1, 0);
    glPointSize(5.0);
    glRasterPos2f(x, y);
    len = (int)strlen(string);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}
void home()
{

    glClearColor(0.0, 0.0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    PrintText(120, 410, GLUT_BITMAP_TIMES_ROMAN_24, 38, (char*)"DSATM");
    PrintText(120, 390, GLUT_BITMAP_TIMES_ROMAN_24, 18, (char*)"DEPARTMENT : CSE");
    PrintText(120, 340, GLUT_BITMAP_TIMES_ROMAN_24, 18, (char*)"\"SUNFLOWER :: INTERACTION WITH SUN\"");
    PrintText(235, 270, GLUT_BITMAP_TIMES_ROMAN_24, 18, (char*)"SUBMITTED BY :");
    PrintText(120, 250, GLUT_BITMAP_TIMES_ROMAN_24, 18, (char*)"SANDEEP KAVALUR");
    PrintText(120, 230, GLUT_BITMAP_TIMES_ROMAN_24, 18, (char*)"1DT17CS081");
    PrintText(320, 250, GLUT_BITMAP_TIMES_ROMAN_24, 18, (char*)"SANGAMESH V");
    PrintText(320, 230, GLUT_BITMAP_TIMES_ROMAN_24, 18, (char*)"1DT17CS082");

    glutPostRedisplay();
}

int h = 0;
int zz = 0;
int ip = 0;
void petaldrop(int degree, int xp, int yp, int zp)
{
    glColor3f(1, 1, 0);
    glPushMatrix();
    glScaled(.3, .3, 0);
    glTranslated(xp, yp, zp);
    glRotated(degree, 0, 0, 1);
    glTranslated(-xp, -yp, zp);
    drawCircleFilled(xp, yp, 50, 5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if (h == 0) {
        home();
    }
    else {
        background();
        //mountain
        for (int i = 0; i < 3; i++)
        {
            glPushMatrix();
            glTranslated(mountposition[i][0], mountposition[i][1], 0);
            mountain();
            glPopMatrix();
        }
        //tree
        glPushMatrix();
        glTranslated(10, 110, 0);
        tree();
        glPopMatrix();

        glPushMatrix();
        glTranslated(200, 120, 0);
        tree();
        glPopMatrix();

        glPushMatrix();
        glTranslated(400, 110, 0);
        tree();
        glPopMatrix();
        //flower position
        for (int i = 0; i < 18; i++) {
            int i1 = i % 6;
            if (i < 6) {
                j = 8;
            }
            else if (i >= 6 && i < 12) {
                j = 5;
            }
            else {
                j = 2;
            }
            glPushMatrix();
            glTranslated(100 * i1, 10 * j, 0);
            glRotated(-f1 / 10, 0, 0, 1);
            flower();
            j = 0;
            glPopMatrix();
        }
        //moon
        glPushMatrix();
        moon();
        glPopMatrix();
        //sun
        glPushMatrix();
        glColor3f(sx / 255.0, sy / 255.0, sz / 255.0);
        glTranslated(c1, 0, 0);
        drawCircleFilled(c1, 400, 35, 35);
        glPopMatrix();
        //bird
        for (int i = 0; i < 4; i++)
        {
            glPushMatrix();
            glTranslated(bird1[i][0], bird1[i][1], 0);
            bird();
            glPopMatrix();
        }
        //stars position
        if (state1 == 1) {
            for (int i = 0; i < 8; i++) {
                glPushMatrix();
                glColor3f(1, 1, 1);
                glTranslated(stars[i][0], stars[i][1], 0);
                star();
                glPopMatrix();
            }
        }
        if (zz == 1)
        {
            //bee position
            for (int i = 0; i < 4; i++)
            {
                glPushMatrix();
                glTranslated(beeposition[i][0] + 500, beeposition[i][1], 0);
                bee();
                glPopMatrix();
            }
        }

        //cloud movement and sun movement
        if (c1 < 330 && state1 == 0) {
            c1 += speed;
            f1 = c1;
            c11 += (30 + speed);
            //flower size
            if (fx <= .6)
            {
                fx += .01;
                fy += .01;
            }
            if (pd == 1 && days % 1 == 0 && zz == 1)
            {
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1], petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 300, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 600, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 900, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 1200, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 1500, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 1800, petaldropposition[ip][2], petaldropposition[ip][3]);

                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 500, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 700, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 800, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 1000, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 1100, petaldropposition[ip][2], petaldropposition[ip][3]);
                petaldrop(petaldropposition[ip][0], petaldropposition[ip][1] + 1300, petaldropposition[ip][2], petaldropposition[ip][3]);

                ip += 1;
            }
        }
        else {
            state1 = 1;
            f1 -= speed;
            if (f1 <= 0) {
                state1 = 0;
                c1 = 0;
                c11 = 0;
                zz = 1;
                yt += .01;
                //reducing the petals
                days += 1;
                if (days % 1 == 0)
                {
                    angle1 += 2;
                    pd = 1;
                }
            }
        }
        //sky color
        if (c1 < 120) {
            x -= .01 * speed / 5;
            y += 2 * .01 * speed / 5;
            z += 3 * .01 * speed / 5;
        }
        else {
            x -= .01 * speed / 7;
            y -= 2 * .01 * speed / 7;
            z -= 3 * .01 * speed / 7;
        }
        if (c1 <= 0) {
            x = .70;
            y = .40;
            z = .09;
            bi = 0;
        }
        //ground
        if (c1 < 120) {
            x2 -= 1;
        }
        else {
            x2 -= .3;
            y2 -= 0.3;
            z2 += .6;
        }
        if (c1 == 0) {
            x2 = 142;
            y2 = 237;
            z2 = 9;
        }
        //sun color
        if (sy < 224 && state == 1)
            sy += 2 + speed;
        else {
            state = 0;
            sy -= 1 - speed / 10;
            if (sy < 106) {
                sy = 106;
                state = 1;
            }
        }
        //bird speed
        bi += speed + 30;
        if (stateb == 0) {
            stateb = 1;
        }
        else {
            stateb = 0;
        }
        //bee speed
        xb -= 10 * speed;
        if (xb <= -1800 && state1 == 0) {
            xb = 650;
        }
    }
    glFlush();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    Sleep(100);
}
void menu(int val)
{
    switch (val)
    {
    case 1:
        day = 1;
        h = 1;
        state1 = 0;
        c1 = 0;
        f1 = 0;
        c11 = 0;
        x = .70, y = .40, z = .09;
        xb = 650;
        break;
    case 2:
        night = 1;
        h = 1;
        state1 = 1;
        c1 = 330;
        f1 = c1;
        x = 0, y = 0, z = 0;
        xb = -1800;
        break;
    case 3:
        exit(0);
        break;
    }
}
void special(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        speed -= 1;
        c11 -= 3;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        speed += 1;
        c11 += 3;
        glutPostRedisplay();
        break;
    case GLUT_KEY_END:
        exit(0);
        break;
    }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(width, height);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("SUNFLOWER");

    int val = glutCreateMenu(menu);
    glutAddMenuEntry("DAY", 1);
    glutAddMenuEntry("NIGHT", 2);
    glutAddMenuEntry("EXIT", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(0, timer, 0);

    glutSpecialFunc(special);
    glutFullScreen();

    glutMainLoop();
}

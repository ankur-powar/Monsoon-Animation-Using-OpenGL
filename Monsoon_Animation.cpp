/*

                         ANKUR POWAR

                ANIMATION OF MONSOON IN PUNE

                        INSTRUCTIONS:

                1]   Left Click to START.

                2]   RIGHT Click to STOP.

*/

#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

class scene
{
    float sunx=0, suny=0, sunr=1.0, sung=0.2, sunb=0.0, sunrad = 0.1;
    float cloudx=0, cloudy=410, cloudr=0.95, cloudg=0.95, cloudb=0.95;
    float cloud2x = 0;
    float bgr=0.0, bgg=0.0, bgb=0.0;
    int i=0;
    int yc = 10;

public:
    void drawCircle(float r, float x, float y, int type);
    void rain(int x, int y, int yc);
    void mountain1(float inx);
    void mountain2(float inx);
    void grass();
    void river(int x);
    void lightening(float x, float y);
    void delay();
    void animation();
} obj;

void scene::drawCircle(float r, float x, float y, int type)
{
        float i = 0.0f;
        int limit = 360;

        if(type == 2)
            limit = 180;

        glBegin(GL_TRIANGLE_FAN);

        glVertex2f(x, y);
        for(i = 0.0f; i <= limit; i++)
                glVertex2f(r*cos(3.141592 * i / 180.0) + x, r*sin(3.141592 * i / 180.0) + y);

        glEnd();
}

void scene::rain(int x, int y, int yc)
{
    int xinc = 30;
    for(int i=450; i>0; i-=7)
    {
        for(int j=170; j>0; j-=7)
        {
            glBegin(GL_POINTS);

            glColor3f(0.0,0.05,1.0);
            glPointSize(4);

            glVertex2f(x-j+xinc, y-i+yc);

            glEnd();
        }
        xinc++;
    }
    glFlush();
}

void scene::mountain1(float inx)
{
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.2,0.2);
    glVertex2f(inx+80, 0);
    glVertex2f(inx+160,160);
    glVertex2f(inx+240,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(inx+140, 120);
    glVertex2f(inx+160,160);
    glVertex2f(inx+180,120);
    glVertex2f(inx+170,110);
    glVertex2f(inx+160,120);
    glVertex2f(inx+150,110);
    glEnd();
    glFlush();
}

void scene::mountain2(float inx)
{
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.2,0.2);
    glVertex2f(inx+100, 0);
    glVertex2f(inx+200,200);
    glVertex2f(inx+300,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(inx+175, 150);
    glVertex2f(inx+200,200);
    glVertex2f(inx+225,150);
    glVertex2f(inx+215,140);
    glVertex2f(inx+210,150);
    glVertex2f(inx+185,140);
    glEnd();
    glFlush();
}

void scene::grass()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.1);
    glVertex2f(0, 0);
    glVertex2f(0,10);
    glVertex2f(1400,10);
    glVertex2f(1400,0);
    glEnd();
    glFlush();
}

void scene::river(int x)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.1,1.0);
    glVertex2f(0, 1);
    glVertex2f(0,22);
    glVertex2f(x,22);
    glVertex2f(x,1);
    glEnd();
    glFlush();
}

void scene::lightening(float x, float y)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.9,0.1);
    glVertex2f(x+0, y);
    glVertex2f(x+40,y-70);
    glVertex2f(x+70,y-45);
    glVertex2f(x+90,y-120);
    glVertex2f(x+50,y);
    glEnd();
    glFlush();
}

void scene::delay()
{
    for(int i=0; i<40000000; i++);
}

void scene::animation()
{
    for(i; i<2300; i++)
    {
        mountain1(500);
        mountain1(800);
        mountain2(260);
        mountain2(600);
        mountain2(950);
        grass();
        delay();

        if(i< 670)
        {
            sunx+=1;
            suny+=0.8;
            sunrad += 0.1;
            sunr-=0.00005;
            sunb+=0.0001;
            sung+=0.0005;

            bgr += 0.0001;
            bgg += 0.0006;
            bgb += 0.0009;


            glColor3f(sunr, sung, sunb);
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(bgr,bgg,bgb,0.0);
            drawCircle(115-sunrad, sunx , suny, 1);

            cloud2x+=2;
            if(350<i && (i%10==0 || i%10==1))
            {
                lightening(cloud2x-75,500);
                lightening(cloud2x-30,500);
                lightening(cloud2x+15,500);
            }
            glColor3f(0.8, 0.8, 0.8);
            drawCircle(50, cloud2x, 500, 2);
            drawCircle(50, cloud2x-35.0, 500-30.0, 2);
            drawCircle(50, cloud2x+35.0, 500-30.0, 2);

            drawCircle(50, cloud2x+60, 600, 2);
            drawCircle(50, cloud2x+25.0, 600-30.0, 2);
            drawCircle(50, cloud2x+95.0, 600-30.0, 2);

        }
        else if(i < 1400)
        {
            sunx+=0.2;
            cloudr -= 0.0004;
            cloudg -= 0.0004;
            cloudb -= 0.0004;
            glColor3f(sunr, sung, sunb);
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(bgr,bgg,bgb,0.0);
            drawCircle(115-sunrad, sunx , suny, 1);

            rain(cloudx-10, cloudy-40, yc);
            yc*=-1;
            cloudx+=1;
            if(i%10==0 || i%10==1)
            {
                lightening(cloudx-70,cloudy-20);
                lightening(cloudx-25,cloudy-20);
                lightening(cloudx+20,cloudy-20);
            }
            glColor3f(cloudr, cloudg, cloudb);
            drawCircle(50, cloudx , cloudy, 2);
            drawCircle(50, cloudx-35.0, cloudy-30.0, 2);
            drawCircle(50, cloudx+35.0, cloudy-30.0, 2);
            river(cloudx);
        }
        else
        {
            sunx+=1;
            suny-=0.6;
            sunrad -= 0.1;
            sunr+=0.0001;
            sunb-=0.0008;
            sung-=0.0005;
            bgr -= 0.0001;
            bgg -= 0.0006;
            bgb -= 0.0009;
            cloudr -= 0.0004;
            cloudg -= 0.0004;
            cloudb -= 0.0004;

            glColor3f(sunr, sung, sunb);
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(bgr,bgg,bgb,0.0);
            drawCircle(115-sunrad, sunx , suny, 1);

            rain(cloudx-10, cloudy-40, yc);
            yc*=-1;
            cloudx+=1;
            glColor3f(cloudr, cloudg, cloudb);
            drawCircle(50, cloudx , cloudy, 2);
            drawCircle(50, cloudx-35.0, cloudy-30.0, 2);
            drawCircle(50, cloudx+35.0, cloudy-30.0, 2);
            river(cloudx);
        }
        glFlush();
    }
}


void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1400,0,700);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glFlush();
}

void mymouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        obj.animation();
    }
}

void keyboard(unsigned char key,int x,int y)
{
    if(key == 27)           // ESC key for EXIT
        exit(0);
    else
        cout<<"\n You have pressed: "<<key<<endl;

    glutPostRedisplay();
}

void board()
{
    cout<<"\n\t\tANIMATION OF MONSOON IN PUNE\n\n";
    cout<<"\t\t\tINSTRUCTIONS:\n\n";
    cout<<"\t\t1]   Left Click to START.\n\n";
    cout<<"\t\t2]   RIGHT Click to STOP.\n\n";

    cout<<"\t   OBSERVE MOVEMENT AND SIZE OF SUN\n";
    cout<<"\t     OBSERVE RAIN AND LIGHTENING\n";
}

int main(int argc,char **argv)
{
    board();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1400,700);
    glutInitWindowPosition(55,80);
    glutCreateWindow("MONSOON IN PUNE");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mymouse);
	myInit();
	glutMainLoop();
}




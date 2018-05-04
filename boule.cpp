#include "boule.h"




//#include "GL/glu.h"

boule::boule(float r, float v, float b)
{
    couleur[0] = r;
    couleur[1] = v;
    couleur[2] = b;
    couleur[3] = 1.0;
    glEnable(GL_DEPTH_TEST);

}

void boule::display(){
    glLoadIdentity();
    glPushMatrix();

        gluQuadricDrawStyle(quadrique, GLU_FILL);
        glTranslatef(posx,posz,0);
        //glTranslatef(posx,-10,posz);
        glColor3f(couleur[0],couleur[1],couleur[2]);
        gluSphere(quadrique, 2.5,50,50);

    glPopMatrix();


}

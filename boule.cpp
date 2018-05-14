#include "boule.h"




//#include "GL/glu.h"

boule::boule(float r, float v, float b)
{
    couleur[0] = r;
    couleur[1] = v;
    couleur[2] = b;
    couleur[3] = 1.0;
    glEnable(GL_DEPTH_TEST);

    tex = QGLWidget::convertToGLFormat(QImage(QString(":/pourboule.jpg")));
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA , GL_UNSIGNED_BYTE, tex.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluQuadricTexture(quadrique, GL_TRUE);


}

void boule::display(){
    glLoadIdentity();
    glPushMatrix();

        glColor3f(1,1,1);
        gluQuadricDrawStyle(quadrique, GLU_FILL);

        glEnable(GL_TEXTURE_2D);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA , GL_UNSIGNED_BYTE, tex.bits());
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gluQuadricTexture(quadrique, GL_TRUE);

        glBindTexture(GL_TEXTURE_2D, m_TextureID);

        glTranslatef(posx,posz,0);

        gluSphere(quadrique, 2.5,50,50);

        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

#include "cube.h"

cube::cube()
{
    // Nous allons prendre le centre et la distance souhaitée pour un carré)
}


#include "cube.h"

//static const float vertices[] = {
//    // Face avant
//    -0.5f, 0.5f, 0.5f,    // Coin supérieur gauche
//    -0.5f, -0.5f, 0.5f,   // Coin inférieur gauche
//    0.5f, -0.5f, 0.5f,    // Coin inférieur droit
//    0.5f, 0.5f, 0.5f,     // Coin supérieur droit

//    // Face arrière
//    -0.5f, 0.5f, -0.5f,   // Coin supérieur gauche
//    -0.5f, -0.5f, -0.5f,  // Coin inférieur gauche
//    0.5f, -0.5f, -0.5f,   // Coin inférieur droit
//    0.5f, 0.5f, -0.5f     // Coin supérieur droit
//};

//static const unsigned int indices[] = {
//    // Face avant
//    0, 1, 2,
//    0, 2, 3,

//    // Face arrière
//    4, 5, 6,
//    4, 6, 7,

//    // Arêtes latérales
//    0, 4, 7,
//    0, 7, 3,
//    1, 2, 6,
//    1, 6, 5
//};


cube::~cube()
{
    vertexBuffer.destroy();
    indexBuffer.destroy();
}


void cube::render()
{

    glBegin(GL_QUADS);

    glColor3ub(0,0,255); // set la couleur

            float center_x = x_;  // Coordonnée x du centre du cube
            float center_y = y_ ;  // Coordonnée y du centre du cube
            float center_z = z_ ;  // Coordonnée z du centre du cube
            float edge_length = size_ ;  // Longueur d'une arête du cube


            float half_length = edge_length / 2.0f;
            float x_min = center_x - half_length;
            float x_max = center_x + half_length;
            float y_min = center_y - half_length;
            float y_max = center_y + half_length;
            float z_min = center_z - half_length;
            float z_max = center_z + half_length;

            // Dessiner le cube
            glBegin(GL_QUADS);
            {
                // Face avant
                glVertex3f(x_min, y_min, z_max);
                glVertex3f(x_max, y_min, z_max);
                glVertex3f(x_max, y_max, z_max);
                glVertex3f(x_min, y_max, z_max);

                // Face arrière
                glVertex3f(x_min, y_min, z_min);
                glVertex3f(x_min, y_max, z_min);
                glVertex3f(x_max, y_max, z_min);
                glVertex3f(x_max, y_min, z_min);

                // Face gauche
                glVertex3f(x_min, y_min, z_min);
                glVertex3f(x_min, y_min, z_max);
                glVertex3f(x_min, y_max, z_max);
                glVertex3f(x_min, y_max, z_min);

                // Face droite
                glVertex3f(x_max, y_min, z_min);
                glVertex3f(x_max, y_max, z_min);
                glVertex3f(x_max, y_max, z_max);
                glVertex3f(x_max, y_min, z_max);

                // Face inférieure
                glVertex3f(x_min, y_min, z_min);
                glVertex3f(x_max, y_min, z_min);
                glVertex3f(x_max, y_min, z_max);
                glVertex3f(x_min, y_min, z_max);

                // Face supérieure
                glVertex3f(x_min, y_max, z_min);
                glVertex3f(x_min, y_max, z_max);
                glVertex3f(x_max, y_max, z_max);
                glVertex3f(x_max, y_max, z_min);
            }
            glEnd();

}

void cube::draw(float x,float y,float z, float size)
{

    glBegin(GL_QUADS);

    glColor3ub(0,0,255); // set la couleur
    //glColor3ub(rand()*255,rand()*255,rand()*255);

            float center_x = x;  // Coordonnée x du centre du cube
            float center_y = y ;  // Coordonnée y du centre du cube
            float center_z = z ;  // Coordonnée z du centre du cube
            float edge_length = size ;  // Longueur d'une arête du cube


            float half_length = edge_length / 2.0f;
            float x_min = center_x - half_length;
            float x_max = center_x + half_length;
            float y_min = center_y - half_length;
            float y_max = center_y + half_length;
            float z_min = center_z - half_length;
            float z_max = center_z + half_length;

            // Dessiner le cube
            glBegin(GL_QUADS);
            {
                // Face avant
                glVertex3f(x_min, y_min, z_max);
                glVertex3f(x_max, y_min, z_max);
                glVertex3f(x_max, y_max, z_max);
                glVertex3f(x_min, y_max, z_max);

                // Face arrière
                glVertex3f(x_min, y_min, z_min);
                glVertex3f(x_min, y_max, z_min);
                glVertex3f(x_max, y_max, z_min);
                glVertex3f(x_max, y_min, z_min);

                // Face gauche
                glVertex3f(x_min, y_min, z_min);
                glVertex3f(x_min, y_min, z_max);
                glVertex3f(x_min, y_max, z_max);
                glVertex3f(x_min, y_max, z_min);

                // Face droite
                glVertex3f(x_max, y_min, z_min);
                glVertex3f(x_max, y_max, z_min);
                glVertex3f(x_max, y_max, z_max);
                glVertex3f(x_max, y_min, z_max);

                // Face inférieure
                glVertex3f(x_min, y_min, z_min);
                glVertex3f(x_max, y_min, z_min);
                glVertex3f(x_max, y_min, z_max);
                glVertex3f(x_min, y_min, z_max);

                // Face supérieure
                glVertex3f(x_min, y_max, z_min);
                glVertex3f(x_min, y_max, z_max);
                glVertex3f(x_max, y_max, z_max);
                glVertex3f(x_max, y_max, z_min);
            }
            glEnd();

}


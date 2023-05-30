#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include "planet.h"
#include <QApplication>


#include "cube.h"


// Pour Windows / Linux,
#include <GL/glu.h>

// Declarations des constantes
const unsigned int WIN_WIDTH_HEIGHT = 900;
const float MAX_DIMENSION     = 50.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
   setFixedSize(WIN_WIDTH_HEIGHT, WIN_WIDTH_HEIGHT);

   // Connexion du timer
   connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
       m_TimeElapsed += 1.0f / 12.0f;


       update();
   });

   //m_AnimationTimer.setInterval(10);
   m_AnimationTimer.setInterval(100);
   m_AnimationTimer.start();
}

// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    // Distance par rapport au soleil, rayon, periode de rotation, periode de révolution
    // 0.0f, 5.0f, 0.0f, 0.0f               // Soleil
    // 7.5f, 0.50f,  58.646f,   87.969f     // Mercure
    // 10.0f, 0.90f, -243.018f, 224.701f    // Venus
    // 13.0f, 0.90f, 0.997f,    365.256f    // Terre
    // 17.5f, 1.50f, 1.025f,    686.960f    // Mars
    // 27.0f, 3.00f, 0.413f,    935.354f    // Jupiter
    // 35.0f, 2.50f, 0.448f,    1757.736f   // Saturne
    // 40.5f, 1.50f, -0.718f,   3687.150f   // Uranus
    // 45.0f, 1.50f, 0.671f,    6224.903f  // Neptune

    // Creation des planètes et ajout des planetes dans le vecteur m_Planetes
}

// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation des tampons

    // Definition de la position de la camera

    // Affichage des m_Planetes

    // On va tester l'affichage d'un cube

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Modèle Ortho
    //glOrtho(0.0,4.0,0.0,4.0,0.0,10.0);


    // Vue perspective

    gluPerspective(70.f,width()/height(), 0.1f, 12.f);

//    gluLookAt(0.0, 1.0, 5.0,  // Position de la caméra (x, y, z)
//                      0.0, 0.0, 0.0,  // Point cible (x, y, z)
//                      0.0, 1.0, 0.0); // Vecteur d'orientation de la caméra (x, y, z)


    gluLookAt(0.0, 2.0, 5.0,  // Position de la caméra (x, y, z)
                      0.0, 0.0, 0.0,  // Point cible (x, y, z)
                      0.0, 1.0, 0.0); // Vecteur d'orientation de la caméra (x, y, z)


    //Etat choisi par le jeu
    int game_state = 2 ;

    // Etat de la main  donnée à récupérer via opencv
    int real_state = 5;

    // on rapproche le mur plutôt ce sera plus simple, avancement du mur
    if (camera_value_z < 5) {


        camera_value_z = camera_value_z + 1 ;
    }

    else{ // c'est a cet endroit qu'on doit réinitialiser la matrice du mur
        camera_value_z = -30 ;


        // On modifie additionne le score
        if(real_state == game_state) {
            score+=1;
            qDebug() << "on incrémente le score" << score ;
        }
    }

    //Déclaration de la matrice du mur

    int n = floor(5/0.1) ; // nombre de ligne on divise bien par le pas
    int p = floor(5/0.1) ; // nombre de colonne



    //std::vector<std::vector<bool>> wall(n, std::vector<bool>(p, false));

    std::vector<std::vector<int>> wall(n, std::vector<int>(p, 0)); // On crée une matrice de zéros

    // Reste à créer une matrice composée de 1 aux bons endroits et sommer les matrices



    // Tracé du mur
    cube C(0,0,0,0.1);

    // Attention j'ai moins de cube que ce que je pense

    for (float i= -0.5 ; i<0.5 ; i+=0.01){
        for(float j = -0.5; j<0.5 ; j+=0.01 ){

            //int position_i = ((i - (-5)) / (5 - (-5))) * (100 - 1) + 1 ;
            //int position_j = ((j - (-5)) / (5 - (-5))) * (100 - 1) + 1 ;

            int position_i = (i - (-0.5)) / (0.5 - (-0.5)) * (100 - 1) + 1 ;
            int position_j = (j - (-0.5)) / (0.5 - (-0.5)) * (100 - 1) + 1 ;

            //qDebug() << "la nouvelle position de i  dans la matrice est :" << position_i << " "  ;
            //qDebug() << "la nouvelle position de j dans la matrice est :" << position_j << " "  ;


//            if(i<-0.25 || i>0.25 ){
//                C.draw(i,j, camera_value_z, 0.1);
//            }
//            if(j<-0.25 || j>0.25 ){
//                C.draw(i,j, camera_value_z, 0.1);
//            }

            if(position_j>50){
                C.draw(i,j, camera_value_z, 0.01);
            }


            if(position_j<=50){
                if(position_i < 30 || position_i > 65) {
                    C.draw(i,j, camera_value_z, 0.01);
                }
            }

            // On fait un switch case pour tracer les doigts

            switch (game_state) {
                    case 1: // doigts
                        //std::cout << "État 1" << std::endl;
                        break;
                    case 2: // doigts
                        if(position_j>40 && position_j<=50){
                            if (position_i >=30 && position_i < 60) {

                                C.draw(i,j, camera_value_z, 0.01);
                            }

                        }
                        break;
                    case 3: // 3 doigts
                        if(position_j>40 && position_j<=50){
                            if (position_i >= 30 && position_i < 50) {

                                C.draw(i,j, camera_value_z, 0.01);
                            }

                            if (position_i > 55 && position_i < 60) {

                                C.draw(i,j, camera_value_z, 0.01);
                            }

                        }
                        break;
                    case 4: // 4 doigts
                        if(position_j>40 && position_j<=50){
                            if (position_i >= 30 && position_i < 40) {
                                //qDebug() << "on trace un doigts" ;
                                C.draw(i,j, camera_value_z, 0.01);
                            }
                            if (position_i > 45 && position_i < 50) {

                                C.draw(i,j, camera_value_z, 0.01);
                            }

                            if (position_i > 55 && position_i < 60) {

                                C.draw(i,j, camera_value_z, 0.01);
                            }

                        }
                        break;

                    case 5: // 5 doigts
                        if(position_j>40 && position_j<=50){
                            //qDebug() << "Voici les valeurs de i :" << position_i ;
                            // auriculaire
                            //if( (position_i > 35 && position_i < 40) || (position_i > 45 && position_i < 50) || (position_i > 55 && position_i < 60)) {
                            if (position_i > 35 && position_i < 40) {
                                //qDebug() << "on trace un doigts" ;
                                C.draw(i,j, camera_value_z, 0.01);
                            }
                            if (position_i > 45 && position_i < 50) {

                                C.draw(i,j, camera_value_z, 0.01);
                            }

                            if (position_i > 55 && position_i < 60) {

                                C.draw(i,j, camera_value_z, 0.01);
                            }

                        }
                        break;
                    default:
                        //std::cout << "État inconnu" << std::endl;
                        break;
                }





            // Configuration tous les doigts initiale sauf pouce
//            if(position_j>40 && position_j<=50){
//                //qDebug() << "Voici les valeurs de i :" << position_i ;
//                // auriculaire
//                //if( (position_i > 35 && position_i < 40) || (position_i > 45 && position_i < 50) || (position_i > 55 && position_i < 60)) {
//                if (position_i > 35 && position_i < 40) {
//                    //qDebug() << "on trace un doigts" ;
//                    C.draw(i,j, camera_value_z, 0.01);
//                }
//                if (position_i > 45 && position_i < 50) {

//                    C.draw(i,j, camera_value_z, 0.01);
//                }

//                if (position_i > 55 && position_i < 60) {

//                    C.draw(i,j, camera_value_z, 0.01);
//                }

//            }




            // On ramène nos indice sur une matrice (100,100) et on vérifie s'il y a un 1 dessus. C
            // C'est le tracé de la main



            //if(i<-1){

                    //C.draw(i,j, camera_value_z, 0.1);
                //}
            //}
            //C.draw(i,j, camera_value_z, 0.1);
            //C.draw(i,j, camera_value_z, 0.1);


            }

        }




}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Activation/Arret de l'animation
        case Qt::Key_Enter:
        {
            if(m_AnimationTimer.isActive())
                m_AnimationTimer.stop();
            else
                m_AnimationTimer.start();

            break;
        }
        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    update();
}

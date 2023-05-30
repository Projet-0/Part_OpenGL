#ifndef PLANET_H
#define PLANET_H

#include <qopengl.h>
#include <QColor>
// Pour Windows / Linux,
#include <GL/glu.h>
// Pour mac OS,
// #include <OpenGL/glu.h>

// Classe dediee pour la gestion d'une planete
class Planet
{
public:
    // Constructeur avec parametres
    Planet();

    // Destructeur
    virtual ~Planet();

    // Methode d'affichage
    void Display(const float timeInDays) const;
};


#endif // PLANET_H

#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "windows.h"
#include <iostream>
#include <cstdlib>
#include <clocale>
#include "Collision.hpp"

using namespace std;
using namespace sf;
using namespace Collision;
/*
setlocale(LC_ALL,"spanish");
*/

class Sprites
{
private:
    Texture camino_textura_propiedad;
    bool textura_cargada;
    Sprite  camino_sprite_propiedad;
public:
    Sprites (const string& nombre_imagen)
    {
        if(!CreateTextureAndBitmask(camino_textura_propiedad,nombre_imagen))
            textura_cargada=false;
        else
            textura_cargada=true;
        if (textura_cargada)
        {
            camino_sprite_propiedad.setTexture(camino_textura_propiedad);
            camino_sprite_propiedad.setColor(Color(255,255,255,0));
        }
    }
    Sprites (const string& nombre_imagen,float *opacidad_bicho,float x,float y)
    {

        if(!CreateTextureAndBitmask(camino_textura_propiedad,nombre_imagen))
            textura_cargada=false;
        else
            textura_cargada=true;
        if (textura_cargada)
        {
            camino_textura_propiedad.setSmooth(true);
            camino_sprite_propiedad.setTexture(camino_textura_propiedad);
            camino_sprite_propiedad.setColor(Color(255,255,255,opacidad_bicho[0]));
            camino_sprite_propiedad.setPosition(x,y);
        }
    }
    Sprite getSprite()
    {
        return camino_sprite_propiedad;
    }
    void setSprite(Sprite s)
    {
        camino_sprite_propiedad=s;
    }
    bool getConfirmacion()
    {
        return textura_cargada;
    }
};

class Monstruo
{
private:
    Sprite bicho;
    int vida,danio;
    float velocidad;
public:
    Sprite getBicho()
    {
        return bicho;
    }
    int getVida()
    {
        return vida;
    }
    int getDanio()
    {
        return danio;
    }
    float getVelocidad()
    {
        return velocidad;
    }
    void setVida (int v)
    {
        vida=v;
    }
    void setDanio (int d)
    {
        danio=d;
    }
    void setVelocidad (float ve)
    {
        velocidad=ve;
    }
    void setSprite (Sprite b)
    {
        bicho=b;
    }
};

class Boton
{
private:
    float esi[2],esd[2],eii[2],eid[2];
    RectangleShape boton;
    int tamaniox,tamanioy;
public:
    Boton(float x,float y,float posx,float posy,int transparencia=0)
    {
        boton.setSize(Vector2f(x,y));
        esi[0]=posx;
        esi[1]=posy;
        esd[0]=posx+(x-1);
        esd[1]=posy;
        eii[0]=posx;
        eii[1]=posy+(y-1);
        eid[0]=posx+(x-1);
        eid[1]=posy+(y-1);
        boton.setPosition(posx,posy);
        boton.setFillColor(Color(255,255,255,transparencia));
        tamaniox=x;
        tamanioy=y;
    }
    int getEsix()
    {
        return esi[0];
    }
    int getEsdx()
    {
        return esd[0];
    }
    int getEiix()
    {
        return eii[0];
    }
    int getEidx()
    {
        return eid[0];
    }
    int getEsiy()
    {
        return esi[1];
    }
    int getEsdy()
    {
        return esd[1];
    }
    int getEiiy()
    {
        return eii[1];
    }
    int getEidy()
    {
        return eid[1];
    }
    RectangleShape getBoton()
    {
        return boton;
    }
    void setTransparencia(int t)
    {
        boton.setFillColor(Color(255,255,255,t));
    }
    int getMousex(int *mouse) {
    int mx=mouse[0];
    if (mouse[2]!=1000||mouse[3]!=600) {
    mx=mouse[0]-(tamaniox-1);
    }
    return mx;
    }
    int getMousey(int *mouse) {
    int my=mouse[1];
    if (mouse[2]!=1000||mouse[3]!=600) {
    my=mouse[1]-(tamanioy-1);
    }
    return my;
    }
};

#endif // CLASES_H_INCLUDED
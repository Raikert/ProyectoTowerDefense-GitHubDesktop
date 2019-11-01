#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

int juego()
{
    ///variables de los for, dados los multiples conflictos por declaraciones seguidas en los ciclos.
    int i,x,te,d;

    ///definicion de la ventana del juego
    RenderWindow window(VideoMode(1000, 600), "Tower Defense - La defensa del fuerte nicomando");

    ///Setea el framerate a 60 fps, comentar para mas velocidad,seteado para ver la velocidad real del juego
    ///bugeo de los sprites solucionado seteando el Smooth de los Sprites en True.
    window.setFramerateLimit(60);

    ///Sector de Incializacion y generacion de Sprites y vectores de Sprites
    const int cantidad_bichos=10;
    const float velocidad=0.8;
    float opacidad_bichos[cantidad_bichos];
    for (i=0; i<cantidad_bichos; i++)
    {
        opacidad_bichos[i]=0;
    }
    Sprites bicho("img/bicho_reside_circulo.png",opacidad_bichos,285,0);

    if (!bicho.getConfirmacion())
        return -10;

    Sprite v[cantidad_bichos];
    cargar_vector_sprites(v,bicho.getSprite(),cantidad_bichos);

    ///Camino lvl1 para modificaciones de colision por error de colisiones con los bichos - comentado

    /*
    Sprites camino1("img/caminolvl1.png")
    if (!camino1.getConfirmacion())
        return -10;
    */

    Texture textura_mapa,textura_bicho,textura_menu,textura_rango;

    if (!textura_mapa.loadFromFile("img/008.png"))
        return -1;
    if (!textura_menu.loadFromFile("img/006.jpg"))
        return -1;
    if (!textura_rango.loadFromFile("img/rango.png"))
        return -1;

    textura_bicho.setSmooth(true);
    textura_rango.setSmooth(true);
    textura_menu.setSmooth(true);
    textura_mapa.setSmooth(true);

    ///Zona de texto
    Font tipo_de_texto;

    /// ------------------------------------------------------------------
    /** if (!tipo_de_texto.loadFromFile("tipos_de_texto/OpenSans-Bold.ttf"))
        return -1;
    Text texto_prueba;
    texto_prueba.setFont(tipo_de_texto);
    texto_prueba.setString("GENTESSS EDITION");
    texto_prueba.setCharacterSize(24);   */
    ///-------------------------------------------------------------------
    Sprite mapa,menu;
    mapa.setTexture(textura_mapa);
    menu.setTexture(textura_menu);

    int mousexy[2];
    for (i=0; i<2; i++)
    {
        mousexy[i]=0;
    }
    Texto mousex("tipos_de_texto/OpenSans-BoldItalic.ttf",mousexy[0],18,627,545,Color::White);
    if (!mousex.getConfirmacion())
        return -1;
    Texto mousey("tipos_de_texto/OpenSans-BoldItalic.ttf",mousexy[1],18,693,549,Color::White);
    if (!mousey.getConfirmacion())
        return -1;

    ///Si gente, le puse MUSICA WEEEEE
    Music musica_menu,musica_juego;
    if (!musica_menu.openFromFile("musica/song_sneaky_driver.ogg"))
        return -1;
    if (!musica_juego.openFromFile("musica/glorious morning.ogg"))
        return -1;

    ///volumen de la musica del menu
    musica_menu.setVolume(50.f);
    // musica_menu.setPlayingOffset(seconds(62.5f));
    musica_menu.play();
    musica_menu.setLoop(true);
    musica_juego.setVolume(50.f);
    musica_juego.setLoop(true);
    bool boolmusica=false,boolmusicajuego=true,habilitacionmouse=true;

    ///con esta variable se cambia la cantidad de monstruos en el mundo

    ///Para un futuro en donde pongamos a los 3 sprites de los 8 tipos de monstruos q consegui-veanlo en la carpeta de img

    /*
    Sprite v[cantidad_objetos][3];
    */

    ///objeto boton de la nueva clase de botones_rectangulo, 5 Parametros:
    ///Tama�o en Float X, Tama�o en Float Y, Posicion de la pantalla en Float X, Posicion de la pantalla en Float Y
    ///el Quinto parametro es transparencia q se pone en 0,osea invisible, por parametro por omision.
    ///Util para ver en q posicion de la pantalla se ubica el boton.

    Boton nueva_partida(237,38,351,316),cargar_partida(237,38,351,377),salir(237,38,351,437),sonido(55,50,872,487);

    ///*/////////////////////////////////////////////-------------ZONA DE TORRES -------------////////////////////////////////////////////////////////////////////////////////////////////////
    /// Variables para la verificacion de clicks y demas
    int posicion_clickeada;
    int contador_de_clicks=0;
    int contador_de_clicks_fuera=0;
    /// Definicion de los espacios para las torres ----------------------------------------------------------------------------
    const int tam_torres = 9;
    int coordenadas_X_Y_torres[2]; /// X=0 Y=1
    int coordenadas_X_Y_torres_t1[2]; /// X=0 Y=1
    int coordenadas_X_Y_torres_t2[2]; /// X=0 Y=1
    int coordenadas_X_Y_torres_t3[2]; /// X=0 Y=1
    int coordenadas_X_Y_equis[2]; /// X=0 Y=1
    int coordenadas_X_Y_vender[2]; /// X=0 Y=1
    int coordenadas_X_Y_subirlvl[2]; /// X=0 Y=1
    int coordenadas_X_Y_mejorar[2]; /// X=0 Y=1
    Boton torres[tam_torres];
    Boton torres_t1[tam_torres];
    Boton torres_t2[tam_torres];
    Boton torres_t3[tam_torres];
    Boton torres_equis[tam_torres];
    Boton torres_vender[tam_torres];
    Boton torres_subirlvl[tam_torres];
    Boton torres_mejorar[tam_torres];
    /// Posiciones de cada boton
    for (i=0; i<tam_torres; i++)
    {
        switch (i)
        {
        case 0:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=236;
            coordenadas_X_Y_torres[1]=114;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 1:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=98;
            coordenadas_X_Y_torres[1]=245;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 2:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=98;
            coordenadas_X_Y_torres[1]=420;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 3:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=194;
            coordenadas_X_Y_torres[1]=331;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 4:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=242;
            coordenadas_X_Y_torres[1]=419;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 5:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=339;
            coordenadas_X_Y_torres[1]=419;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 6:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=434;
            coordenadas_X_Y_torres[1]=419;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 7:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=482;
            coordenadas_X_Y_torres[1]=90;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        case 8:
            /// Espacio para la torre
            coordenadas_X_Y_torres[0]=535;
            coordenadas_X_Y_torres[1]=224;
            /// Torre 1 del menu
            coordenadas_X_Y_torres_t1[0]=coordenadas_X_Y_torres[0]-74;
            coordenadas_X_Y_torres_t1[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 2 del menu
            coordenadas_X_Y_torres_t2[0]=coordenadas_X_Y_torres[0]-15;
            coordenadas_X_Y_torres_t2[1]=coordenadas_X_Y_torres[1]-72;
            /// Torre 3 del menu
            coordenadas_X_Y_torres_t3[0]=coordenadas_X_Y_torres[0]+44;
            coordenadas_X_Y_torres_t3[1]=coordenadas_X_Y_torres[1]-72;
            /// Cruz para cerrar el menu
            coordenadas_X_Y_equis[0]=339;
            coordenadas_X_Y_equis[1]=74;
            /// Boton para vender del menu
            coordenadas_X_Y_vender[0]=339;
            coordenadas_X_Y_vender[1]=92;
            /// Boton para cambiar el menu por el menu de nivel+1
            coordenadas_X_Y_subirlvl[0]=339;
            coordenadas_X_Y_subirlvl[1]=110;
            /// Boton para mejorar la torre
            coordenadas_X_Y_mejorar[0]=339;
            coordenadas_X_Y_mejorar[1]=129;
            break;
        }
        torres[i]=Boton(49,90,coordenadas_X_Y_torres[0],coordenadas_X_Y_torres[1]);
        torres_t1[i]=Boton(59,71,coordenadas_X_Y_torres_t1[0],coordenadas_X_Y_torres_t1[1]);
        torres_t2[i]=Boton(57,71,coordenadas_X_Y_torres_t2[0],coordenadas_X_Y_torres_t2[1]);
        torres_t3[i]=Boton(59,71,coordenadas_X_Y_torres_t3[0],coordenadas_X_Y_torres_t3[1]);
        torres_equis[i]=Boton(19,18,coordenadas_X_Y_equis[0],coordenadas_X_Y_equis[1]);
    }

    /// Declaracion del vector de menues de torres
    bool menu_torre[tam_torres], spawn_torre[tam_torres][3], spawnear[tam_torres], Ocupado[tam_torres];
    for (i=0; i<tam_torres; i++)
    {
        for (te=0; te<3; te++)
        {
            spawn_torre[i][te]=false;
        }
    }
    ponerEnFalso(menu_torre, tam_torres);
    ponerEnFalso(spawnear, tam_torres);
    ponerEnFalso(Ocupado, tam_torres);

    /// Texturas
    Texture textura_menu_torre, textura_torre_1, textura_torre_2, textura_torre_3, rango_torre;
    if (!textura_menu_torre.loadFromFile("img/Menu_Torres.png"))
        return -1;
    textura_menu_torre.setSmooth(true);
    if (!textura_torre_1.loadFromFile("img/T1-1.png"))
        return -1;
    textura_torre_1.setSmooth(true);
    if (!textura_torre_2.loadFromFile("img/T2-1.png"))
        return -1;
    textura_torre_2.setSmooth(true);
    if (!textura_torre_3.loadFromFile("img/T3-1.png"))
        return -1;
    textura_torre_3.setSmooth(true);
    if (!rango_torre.loadFromFile("img/rango.png"))
        return -1;
    rango_torre.setSmooth(true);

    /// Sprites
    Sprite Sprite_menu_torre[tam_torres], Sprite_torre_1[tam_torres], Sprite_torre_2[tam_torres], Sprite_torre_3[tam_torres];
    Sprite Sprite_rango_torres[tam_torres];
    for (x=0; x<tam_torres; x++)
    {
        ///menu
        Sprite_menu_torre[x].setTexture(textura_menu_torre);
        Sprite_menu_torre[x].setPosition(torres[x].getEsix()-75,torres[x].getEsiy()-72);
        ///torre 1
        Sprite_torre_1[x].setTexture(textura_torre_1);
        Sprite_torre_1[x].setPosition(torres[x].getEsix(),torres[x].getEsiy());
        ///torre 2
        Sprite_torre_2[x].setTexture(textura_torre_2);
        Sprite_torre_2[x].setPosition(torres[x].getEsix(),torres[x].getEsiy());
        ///torre 3
        Sprite_torre_3[x].setTexture(textura_torre_3);
        Sprite_torre_3[x].setPosition(torres[x].getEsix(),torres[x].getEsiy());
        ///rango de da�o
        Sprite_rango_torres[x].setTexture(rango_torre);
        Sprite_rango_torres[x].setColor(Color(255,255,255,100));
    }
    int a = 0;
    /// ----------------------------------------------------------------------------------------------------------------------
    ///*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Rect<jojo>::Rect(200,200,50,50);
    */

    int estados[cantidad_bichos];
    for (i=0; i<cantidad_bichos; i++)
    {
        estados[i]=0;
    }
    estados[0]=-1;
    float opacidad_menu=0; ///transparencia del objeto 255=100% porciento
    for (i=0; i<=cantidad_bichos-1; i++)
    {
        ///Seria un corte de control donde por cada vuelta de J se cargara un frame de un tipo de bicho, faltaria la forma
        ///dinamica de indicar a cual tipo de monstruo cargar en cada fila de la matriz
        /*
        for (int j=0;j++<=2;j++) {*/
        /*
        v[i][j]...
        v[i][j]...
        v[i][j]...
        */
        /*
        v[i]=CircleShape(25.f);
        */

        /*
        v[i].setTexture(textura_bicho);
        v[i].setColor(Color(255,255,255,opacidad_objetos[i]));
        v[i].setPosition(285,0);
        */
        /*
        }*/
    }
    int objetos=1;
    int tiempo=1;

    ///Todo lo que se necesita para crear un texto son 2 lineas de codigo, Nueva Clase Texto, Parametros:

    ///1)Formato de texto: ruta donde esta alojado el tipo de texto.
    ///2)variable a convertir, debe ser int, proximamente constructor para texto plano.
    ///3)Tama�o del texto, similar al word cuando pones el tama�o de la letra.
    ///4)Posicion de la pantalla en coordenadas de pixeles en X.
    ///5)Posicion de la pantalla en coordenadas de pixeles en Y.
    ///6)Color: Se debe anteponer Color:: y despues el color dentro de los contenidos por Sfml,

    ///Podriamos agregar using namespace Color, pero seria demasiado exagerado, posiblemente agrege
    ///un constructor para colores en RGB y transparencia, pero mas adelante.

    ///El objeto texto junto con el pasaje de variable a string se hacen simultaneamente.
    ///para cambiar el string, se usa el metodo setVariable(variable), que explico mas abajo con la variable tiempo.

    ///Para todo tipo de carga de archivos se debe verificar la carga con un metodo de confirmacion, que devuelve un verdadero
    ///o falso, en caso de una carga incorrecta el programa se detendra para la visibilidad del error, el constructor no puede
    ///hacerlo por si mismo, dado que no puede devolver ningun valor, es cosa nuestra asegurarlo.

    ///-------------------------
    Texto tiempo_texto("tipos_de_texto/OpenSans-BoldItalic.ttf",tiempo,25,600,300,Color::Black);
    if (!tiempo_texto.getConfirmacion())
        return -1;
    ///-------------------------

    ///-----Vida de los monstruos-----
    int vidas[cantidad_bichos];
    for (i=0; i<cantidad_bichos; i++)
    {
        vidas[i]=100;
    }
    Texto vidas_texto[cantidad_bichos],vida_texto("tipos_de_texto/OpenSans-BoldItalic.ttf",vidas[0],15,v[0].getPosition().x+10, v[0].getPosition().y+25);
    if (!vida_texto.getConfirmacion())
        return -1;
    for (i=0; i<cantidad_bichos; i++)
    {
        vidas_texto[i]=vida_texto;
    }
    ///-------------------------------
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        mousexy[0]=Mouse::getPosition(window).x;
        mousexy[1]=Mouse::getPosition(window).y;
        mousex.setVariable(mousexy[0]);
        mousey.setVariable(mousexy[1]);
        ///Configuracion de los botones dentro del juego
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (habilitacionmouse)
            {
                ///sonido
                if (mousexy[0]>=sonido.getEsix()&&mousexy[0]<=sonido.getEsdx()&&mousexy[1]>=sonido.getEsdy()&&mousexy[1]<=sonido.getEidy())
                {
                    if (boolmusicajuego)
                    {
                        musica_juego.setVolume(0.f);
                        boolmusicajuego=false;
                    }
                    else
                    {
                        musica_juego.setVolume(50.f);
                        boolmusicajuego=true;
                    }
                }
                for (i=0; i<tam_torres; i++)
                {
                    if (mousexy[0]>=torres[i].getEsix()&&mousexy[0]<=torres[i].getEsdx()&&mousexy[1]>=torres[i].getEsiy()&&mousexy[1]<=torres[i].getEidy())
                    {
                        ///SE ABRE EL MENU DE TORRES
                        menu_torre[i]=true;
                        spawnear[i]=true;
                        habilitacionmouse=false;
                        posicion_clickeada=i;
                        contador_de_clicks++;
                    }
                    else
                    {
                        ///SE CIERRA EL MENU DE TORRES
                        menu_torre[i]=false;
                        if (contador_de_clicks>1)
                        {
                            //spawnear[i]=false;
                        }
                        contador_de_clicks++;

                        /// Este for se encarga de cerrar la posibilidad de spawneo a los otros lugares que
                        /// no sea el que se clickeo anteriormente
                        for(int k=0; k<tam_torres; k++)
                        {
                            if (k != posicion_clickeada)
                            {
                                spawnear[k]=false;
                            }
                        }
                    }
                    if (habilitacionmouse)
                    {
                        for(x=0; x<tam_torres; x++)
                        {
                            if (spawnear[i]==true)
                            {
                                if (Ocupado[i]==false&&mousexy[0]>=torres_t1[i].getEsix()&&mousexy[0]<=torres_t1[i].getEsdx()&&mousexy[1]>=torres_t1[i].getEsiy()&&mousexy[1]<=torres_t1[i].getEidy())
                                {
                                    /// Se spawnea la torre 1
                                    spawn_torre[i][0]=true;
                                    /// El espacio de la torre 1 esta siendo ocupado por la torre 1
                                    Ocupado[i]=true;
                                }
                                if (Ocupado[i]==false&&mousexy[0]>=torres_t2[i].getEsix()&&mousexy[0]<=torres_t2[i].getEsdx()&&mousexy[1]>=torres_t2[i].getEsiy()&&mousexy[1]<=torres_t2[i].getEidy())
                                {
                                    /// Se spawnea la torre 2
                                    spawn_torre[i][1]=true;
                                    /// El espacio de la torre 1 esta siendo ocupado por la torre 2
                                    Ocupado[i]=true;
                                }
                                if (Ocupado[i]==false&&mousexy[0]>=torres_t3[i].getEsix()&&mousexy[0]<=torres_t3[i].getEsdx()&&mousexy[1]>=torres_t3[i].getEsiy()&&mousexy[1]<=torres_t3[i].getEidy())
                                {
                                    /// Se spawnea la torre 3
                                    spawn_torre[i][2]=true;
                                    /// El espacio de la torre 1 esta siendo ocupado por la torre 3
                                    Ocupado[i]=true;
                                }
                            }
                        }
                    }
                }
                ///mientras el mouse este presionado no repetira ninguna accion en bucle hasta q se suelte el click izquierdo
                habilitacionmouse=false;
            }
        }
        else
            ///una vez que se solto el mouse, recien se habilita para una nueva accion
            habilitacionmouse=true;

        window.clear();

        for (i=1; i<=objetos; i++)
        {
            if (estados[i-1]!=-1)
            {
                window.draw(mapa);

                window.draw(mousex.getTexto());
                window.draw(mousey.getTexto());

                window.draw(tiempo_texto.getTexto());

                if (!boolmusica)
                {
                    musica_juego.play();
                    boolmusica=true;
                }

                for (d=1; d<=objetos; d++)
                {
                    if (vidas[d-1]>0)
                    {
                        window.draw(v[d-1]);
                        window.draw(vidas_texto[d-1].getTexto());
                    }
                    ///esto serian los mini-estados de los sprites, 3 cases por ser 3 frames o mini-sprites
                    /*
                    switch(mini_estados) {
                    case 1:
                    break;
                    case 2:---------
                    break;
                    case 3:
                    break;
                    }
                    */
                }
///*///////////////////////////////////////////////////////////- Spawnear torres -///////////////////////////////////////////////////////////////////////////
                for (x=0; x<tam_torres; x++)
                {
                    for(int y=0; y<3; y++)
                    {
                        if (spawn_torre[x][y]==true)
                        {
                            switch (y)
                            {
                            case 0:
                                window.draw(Sprite_torre_1[x]);
                                window.draw(Sprite_rango_torres[x]);
                                break;
                            case 1:
                                window.draw(Sprite_torre_2[x]);
                                window.draw(Sprite_rango_torres[x]);
                                break;
                            case 2:
                                window.draw(Sprite_torre_3[x]);
                                window.draw(Sprite_rango_torres[x]);
                                break;
                            }
                            Sprite_rango_torres[x].setPosition(torres[x].getEsix()-92,torres[x].getEsiy()-40);
                        }
                    }
                    if (menu_torre[x]==true)
                    {
                        window.draw(Sprite_menu_torre[x]);
                    }
                }
///*///////////////////////////////////////////////////////////------------------///////////////////////////////////////////////////////////////////////////
                for (int x=0; x<tam_torres; x++)
                {
                    /// Si el enemigo colisiona con el sprite (invisible o no) hace da�o
                    if (PixelPerfectTest(v[i-1],Sprite_rango_torres[x])==true)
                    {
                        if (tiempo%50==0)
                        {
                            vidas[i-1]--;
                            vidas_texto[i-1].setVariable(vidas[i-1]);
                            v[i-1].setColor(Color(50,50,77,opacidad_bichos[i-1]));
                        }
                        else
                        {
                            v[i-1].setColor(Color(255,255,255,opacidad_bichos[i-1]));
                        }
                    }
                }
                vidas_texto[i-1].setPosicion(v[i-1].getPosition().x+10,v[i-1].getPosition().y+25);
            }
            ///Peque�a maquina de estados
            switch (estados[i-1])
            {
            case -1:
                menu.setColor(Color(255,255,255,opacidad_menu));
                window.draw(menu);
                window.draw(nueva_partida.getBoton());
                /// window.draw(texto_prueba);

                window.draw(mousex.getTexto());
                window.draw(mousey.getTexto());

                if (opacidad_menu<255)
                {
                    opacidad_menu+=5;
                }
                else
                {
                    ///Configuracion de los botones en el menu principal
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {

                        ///Nueva partida
                        if (mousexy[0]>=nueva_partida.getEsix()&&mousexy[0]<=nueva_partida.getEsdx()&&mousexy[1]>=nueva_partida.getEsdy()&&mousexy[1]<=nueva_partida.getEidy())
                        {
                            /*
                            volumen_menu-=0.1;
                            musica_menu.setVolume(volumen_menu);
                                */
                            musica_menu.stop();

                            mousex.setColor(Color::Black);
                            mousey.setColor(Color::Black);

                            estados[0]=0;
                        }
                        ///Cargar Partida
                        if (mousexy[0]>=cargar_partida.getEsix()&&mousexy[0]<=cargar_partida.getEsdx()&&mousexy[1]>=cargar_partida.getEsdy()&&mousexy[1]<=cargar_partida.getEidy())
                        {
                            musica_menu.stop();
                            musica_juego.play();

                        }
                        ///Salir
                        if (mousexy[0]>=salir.getEsix()&&mousexy[0]<=salir.getEsdx()&&mousexy[1]>=salir.getEsdy()&&mousexy[1]<=salir.getEidy())
                        {
                            musica_menu.stop();
                            window.close();
                        }

                    }
                }
                break;
            case 0:

                ///el pixelperfectTest del mapa colisionable reemplazara a la tecnica del paint y el limite de pixeles
                ///mientras cambio los limites colisionables sobre el mapa del lvl1, seguimos con los pixeles.
                if (/*PixelPerfectTest(v[i-1],camino1.getSprite())*/v[i-1].getPosition().y<199&&v[i-1].getPosition().x==285)
                {
                    if(opacidad_bichos[i-1]<255)
                    {
                        opacidad_bichos[i-1]+=5;
                        v[i-1].setColor(Color(255,255,255,opacidad_bichos[i-1]));
                        vidas_texto[i-1].setTransparencia(opacidad_bichos[i-1]);
                    }
                    mov_obj_abajo(v,i-1,velocidad);
                }
                else
                    estados[i-1]=1;
                break;

            case 1:
                if (v[i-1].getPosition().x>47)
                {
                    mov_obj_izq(v,i-1,velocidad);
                }
                else
                    estados[i-1]=2;
                break;
            case 2:
                if (v[i-1].getPosition().y<500)
                {
                    mov_obj_abajo(v,i-1,velocidad);
                }
                else
                    estados[i-1]=3;
                break;
            case 3:
                if (v[i-1].getPosition().x<485)
                {
                    mov_derecha(v,i-1,velocidad);
                }
                else
                    estados[i-1]=4;
                break;
            case 4:
                if (v[i-1].getPosition().y>177)
                {
                    mov_obj_arriba(v,i-1,velocidad);
                }
                else
                    estados[i-1]=5;
                break;
            case 5:
                if (v[i-1].getPosition().x<700)
                {
                    mov_derecha(v,i-1,velocidad);
                }
                else
                    estados[i-1]=6;
                break;
            case 6:
                if (opacidad_bichos[i-1]!=0)
                {
                    opacidad_bichos[i-1]-=5;
                    v[i-1].setColor(Color(255,255,255,opacidad_bichos[i-1]));
                    vidas_texto[i-1].setTransparencia(opacidad_bichos[i-1]);
                    mov_derecha(v,i-1,velocidad);
                }
                else
                {
                    estados[i-1]=7;
                    vidas[i-1]=0;
                }
                break;
            case 7:
                break;

                ///movimientos en diagonal
                /*
                case 1:
                    if (circulo1.getPosition().y>171&&circulo1.getPosition().x>35)
                    {
                        mov_diagonal_izq_abajo(&circulo1,0.1,0.038);

                    }
                    else
                        estado=2;
                    break;glorious morning
                case 2:
                    if (circulo1.getPosition().x<35&&circulo1.getPosition().y<429)
                    {
                glorious morning           mov_obj_abajo(v,objetos,0.1);

                    }
                    else
                        estado=10;
                    break;
                case 10:
                    if (circulo1.getPosition().y>429&&circulo1.getPosition().y<500)
                    {
                        mov_diagonal_der_abajo(&circulo1,0.1,0.1);
                    }
                    else
                        estado=3;
                    break;
                case 3:
                    break;
                case 4:
                    if (circulo1.getPosition().x>292&&circulo1.getPosition().x<570)
                    {
                        mov_diagonal_der_arriba(&circulo1,0.1,0.1);
                    }
                    else
                        estado=5;
                    break;
                case 5:
                    if(circulo1.getPosition().x<637)
                    {
                        mov_derecha(&circulo1,0.1);
                    }
                    else
                        estado=6;
                    break;
                case 6:
                    if (circulo1.getPosition().x>637&&circulo1.getPosition().x<700)
                    {
                        mov_derecha(&circulo1,0.1);
                        if(opacidad>0)
                        {
                            opacidad-=0.4;
                            circulo1.setFillColor(Color(255,255,255,opacidad));
                        }
                    }
                    else
                    {
                        circulo1.setPosition(290,0);
                        estado=0;
                    }
                    break;
                */
            }
        }
        if (tiempo%200==0)
        {
            if (objetos<cantidad_bichos)
            {
                objetos++;
                tiempo=1;
            }
        }
        if (estados[0]!=-1)
        {
            tiempo++;

            ///Metodo de clase Texto, para modificar el string porque la variable cambio de valor.

            ///--------
            tiempo_texto.setVariable(tiempo);
            ///--------
        }
        ///Pruebas iniciales con circulos
        /*
        window.draw(circulo1);
        if (circulo1.getPosition().x<600&&circulo1.getPosition().y<=0) {
        x=circulo1.getPosition().x+.1;
        circulo1.setPosition(x,circulo1.getPosition().y);
        }
        if (circulo1.getPosition().x>600&&circulo1.getPosition().y<400) {
        y=circulo1.getPosition().y+.1;
        circulo1.setPosition(circulo1.getPosition().x,y);
        }
        if (circulo1.getPosition().x>0&&circulo1.getPosition().y>400) {
        x=circulo1.getPosition().x-.1;
        circulo1.setPosition(x,circulo1.getPosition().y);
        }
        if (circulo1.getPosition().x<0&&circulo1.getPosition().y>0) {
        y=circulo1.getPosition().y-.1;
        circulo1.setPosition(circulo1.getPosition().x,y);
        }
        */
        window.display();
    }
    return 0;
}


#endif // JUEGO_H_INCLUDED

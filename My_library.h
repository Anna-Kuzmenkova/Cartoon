#include "TXLib.h"

/**
 *file "SeaLib.h"
 *\author Anya Kuzmenkova 8V
 *\date  2019-11-23
 */


/**
 *рисование яйца:
 *\param x x-координата опорной точки = 170

 *\param y y-координата опорной точки = 420
 *опорная точка в нижней части яйца

 *\param x1 очень важный параметр
 *отвечает за тонкости рисования правильного по форме яйца
 *\warning всегда! должно быть значение 450

 *\param egg-рисует яйцо
 *если egg равен 1,то рисуется целое яйцо
 *если egg не равен 1, то рисуется только нижняя часть скорлупы
 *\warning чтобы рисовалась только нижняя часть нужно чтобы параметр scorlupa был не равен 1

 *\param scorlupa-рисование верхней части скорлупы
 *если scorlupa равен 1, то рисуется верхняя часть
 *если scorlupa не равен 1, то рисуется только нижняя часть скорлупы
 *\warning имеет смысл использования только когда параметр egg не равен 1

 *\param sdvigX движение верхней части скарлупы
 *движение верхней части скарлупы вправо и влево
 *Если sdvigX>0, то движение вправо
 *Если sdvigX<0, то движение влево
 *Если sdvigX=0, то скорлупа не движется
 *\warning имеет смысл использования только когда параметр scorlupa равен 1

 *\param sdvigY движение верхней части скарлупы
 *движение верхней части скарлупы вниз и вверх
 *Если sdvigY>0, то движение вверх
 *Если sdvigY<0, то движение вниз (не рекомендую брать такие значения, тк это выглядит странно)
 *Если sdvigY=0, то скорлупа не движется
 *\warning имеет смысл использования только когда параметр scorlupa равен 1

 *\param lines рисование трещен на яйце
 *если lines равен 1, то рисуются трещины на яйце
 *если lines не равен 1, то трещины не рисуются
 *\warning имеет смысл использования только когда параметр egg равен 1

 *\param color цвет яйца
 *рисует яйцо такого цвета, который вы задали

 *\param scale размер яйца
 *рисует яйцо такого размера, который вы задали
 *\warning рекомендуемое значение от 0.1 до 2.5 (для размера окна примерно 1500*900)

 *\param dir отражение яйца по горизонтали
 *Если dir = 1, то яйцо не отражается
 *Если dir = -1, то яйцо отражается по горизонтали
 *\warning использовать отражение только когда параметр egg равен 1

 */
void draw_egg     (int x,int x1,int y,COLORREF color,                                double scale, int egg,     int scorlupa,int dir,       int sdvigX,int sdvigY,int lines);
/**
 *рисование черепахи: x x-координата опорной точки = x x-координата опорной точки =
 *\param x x-координата опорной точки = 600

 *\param y y-координата опорной точки = 245

 *
*/
void draw_turtle  (int x,       int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int hand,    double head, int piatnoshko,int dir                        );

void draw_crab    (int x,       int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int foot,    double smile,int shine,     int dir,   int cleshni         );

void draw_gull    (int x,       int y,COLORREF color,COLORREF color1,                double scale, double wing1,double wing2,int nose2,     int eye,   int dir             );

void draw_dolphin (int x,       int y,COLORREF color,COLORREF color1,                double scale, double smile,int tail,    int blush,     int dir,   double plavnic      );

void draw_egg(int x,int x1,int y,COLORREF color,double scale,int egg,int scorlupa,int dir,int sdvigX,int sdvigY,int lines)
{
    if(egg==1)
    {
        txSetColor(TX_BLACK, 5*scale);
        txSetFillColor(color);
        txEllipse (x-140*scale, y-380*scale*dir, x+200*scale, y);
        txSetFillColor(TX_WHITE);
        txCircle(x-80 *scale, y-200*scale*dir, 7*scale );
        txCircle(x,           y-120*scale*dir, 10*scale);
        txCircle(x+20 *scale, y-220*scale*dir, 6*scale );
        txCircle(x+140*scale, y-180*scale*dir, 8*scale );
        txCircle(x+120*scale, y-80 *scale*dir, 11*scale);    //круги на яйце
        txCircle(x-60 *scale, y-60 *scale*dir, 7*scale );
        txCircle(x+60*scale,  y-340*scale*dir, 9*scale);
        txCircle(x-20*scale,  y-320*scale*dir, 6*scale);
        if(lines==1)
        {
            txLine(x-110*scale, y-300*scale*dir, x-90*scale,  y-260*scale*dir);
            txLine(x-90 *scale, y-260*scale*dir, x-30*scale,  y-300*scale*dir);
            txLine(x-30*scale,  y-300*scale*dir, x+27*scale,  y-260*scale*dir); //линии скорлупы
            txLine(x+27 *scale, y-260*scale*dir, x+85*scale, y-300*scale*dir);
            txLine(x+85*scale, y-300*scale*dir, x+145*scale, y-260*scale*dir);
            txLine(x+145*scale, y-260*scale*dir, x+165*scale, y-300*scale*dir);
        }
    }
    else
    {
        txSetColor(TX_BLACK, 5*scale);
        txSetFillColor(color);
        txChord(x-140*scale, y-380*scale*dir,x+200*scale, y, -220, 260);//нижняя часть скорлупы
        txSetFillColor(TX_WHITE);
        POINT decor[7]={{int(x-111*scale), int(y-300*scale*dir) },
                        {int(x-90*scale) , int(y-260*scale*dir) },
                        {int(x-30*scale) , int(y-300*scale*dir) },
                        {int(x+27*scale) , int(y-260*scale*dir) },
                        {int(x+85*scale) , int(y-300*scale*dir) },
                        {int(x+145*scale), int(y-260*scale*dir) },
                        {int(x+168*scale), int(y-300*scale*dir)}};
        txPolygon (decor,7);
        txSetColor(TX_WHITE,11*scale);
        txLine(x-111*scale, y-302*scale*dir,x+165*scale,y-302*scale*dir);
        txSetColor(TX_BLACK,5*scale);
        txLine(x-110*scale, y-298*scale*dir, x-90*scale,  y-260*scale*dir);
        txLine(x-90 *scale, y-260*scale*dir, x-30*scale,  y-300*scale*dir);
        txLine(x-30*scale,  y-300*scale*dir, x+27*scale,  y-260*scale*dir);
        txLine(x+27 *scale, y-260*scale*dir, x+85*scale, y-300*scale*dir);
        txLine(x+85*scale, y-300*scale*dir, x+145*scale, y-260*scale*dir);
        txLine(x+145*scale, y-260*scale*dir, x+167*scale, y-300*scale*dir);
        txSetColor(TX_BLACK, 5*scale);
        txSetFillColor(TX_WHITE);
        txCircle(x-80 *scale, y-200*scale*dir, 7*scale );
        txCircle(x,           y-120*scale*dir, 10*scale);
        txCircle(x+20 *scale, y-220*scale*dir, 6*scale );
        txCircle(x+140*scale, y-180*scale*dir, 8*scale );
        txCircle(x+120*scale, y-80 *scale*dir, 11*scale);    //круги на яйце
        txCircle(x-60 *scale, y-60 *scale*dir, 7*scale );
        if(scorlupa==1)
        {
            txSetColor(TX_BLACK, 5*scale);
            txSetFillColor(color);
            txChord(x-(140-sdvigX)*scale, y-(380+sdvigY)*scale*dir, x+(200+sdvigX)*scale, y-sdvigY*scale*dir, 40, 100);//верхняя часть скорлупы
            txSetFillColor(TX_WHITE);
            txCircle(x+(60+sdvigX)*scale, y-(340+sdvigY)*scale*dir, 9*scale);
            txCircle(x-(20-sdvigX)*scale, y-(320+sdvigY)*scale*dir, 6*scale);
            txSetFillColor(color);
            POINT decor[7]={{int(x-(111-sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x-(90 -sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x-(30 -sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x+(27 +sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x+(85 +sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x+(145+sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x+(168+sdvigX)*scale), int(y-(300+sdvigY)*scale*dir)}};
            txPolygon (decor,7);
            txSetColor(color,11*scale);
            txLine(x-(99-sdvigX)*scale, y-(302+sdvigY)*scale*dir,x+(155+sdvigX)*scale,y-(302+sdvigY)*scale*dir);
            txSetColor(TX_BLACK,5*scale);
            txLine(x-(110-sdvigX)*scale, y-(298+sdvigY)*scale*dir, x-(90 -sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x-(90 -sdvigX)*scale, y-(260+sdvigY)*scale*dir, x-(30 -sdvigX)*scale, y-(300+sdvigY)*scale*dir);
            txLine(x-(30 -sdvigX)*scale, y-(300+sdvigY)*scale*dir, x+(27 +sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x+(27 +sdvigX)*scale, y-(260+sdvigY)*scale*dir, x+(85 +sdvigX)*scale, y-(300+sdvigY)*scale*dir);
            txLine(x+(85 +sdvigX)*scale, y-(300+sdvigY)*scale*dir, x+(145+sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x+(145+sdvigX)*scale, y-(260+sdvigY)*scale*dir, x+(167+sdvigX)*scale, y-(300+sdvigY)*scale*dir);
        }
    }



}

void draw_turtle(int x, int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int hand, double head, int piatnoshko, int dir)
{
    txSetColor(TX_BLACK, 5*scale);                                                               //параметр head- движение головы
    txSetFillColor(color);                                                                       //head >/=0
    txCircle(x,int(y-(130+30*head)*scale*dir),45*scale); //голова                                //когда head=3, головы не видно
    POINT polygon[8]= {{int(x-45 *scale), int(y- 70       *scale*dir) },                          //рекомендуется брать от -0.5 до -2.5
                       {int(x-90 *scale), int(y-(105-hand)*scale*dir) },
                       {int(x-120*scale), int(y-(105-hand)*scale*dir) },
                       {int(x-180*scale), int(y-(60 -hand)*scale*dir) }, //лапа левая             //параметр hand-движение плавников
                       {int(x-180*scale), int(y-(15 -hand)*scale*dir) },                          //рекомендуется брать от 50 до -50
                       {int(x-135*scale), int(y-(60 -hand)*scale*dir) },                          //при + движение плавников вниз,
                       {int(x-90 *scale), int(y-(75 -hand)*scale*dir) },                          //при - движение плавников вверх
                       {int(x-70 *scale), int(y- 60       *scale*dir)}};
    txPolygon (polygon,8);                                                                        //piatnoshko-появление/исчезновение рисунка на панцире
    POINT polygon1[8]={{int(x+55*scale ),int(y- 70       *scale*dir) },
                       {int(x+100*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+130*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+190*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+190*scale),int(y-(15 -hand)*scale*dir) }, //лапа правая
                       {int(x+145*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+100*scale),int(y-(75 -hand)*scale*dir) },
                       {int(x+70*scale ),int(y- 55       *scale*dir)}};
    txPolygon (polygon1,8);
    POINT polygon2[5]= {{int(x-50*scale),int(y+65 *scale*dir) },
                        {int(x-90*scale),int(y+90 *scale*dir) },
                        {int(x-90*scale),int(y+120*scale*dir) },   //нога левая
                        {int(x-60*scale),int(y+135*scale*dir) },
                        {int(x-30*scale),int(y+75 *scale*dir)}};
    txPolygon (polygon2,5);
    POINT polygon3[5]={{int(x+50*scale),int(y+65 *scale*dir) },
                       {int(x+90*scale),int(y+90 *scale*dir) },
                       {int(x+90*scale),int(y+120*scale*dir) }, //нога правая
                       {int(x+60*scale),int(y+135*scale*dir) },
                       {int(x+30*scale),int(y+75 *scale*dir)}};
    txPolygon (polygon3,5);
    POINT rhomb[4]={{    x,          int(y+80 *scale*dir) },
                    {int(x-15*scale),int(y+105*scale*dir) },  //хвост
                    {    x,          int(y+120*scale*dir) },
                    {int(x+15*scale),int(y+105*scale*dir)}};
    txPolygon (rhomb,4);
    txSetFillColor(TX_BLACK);
    txEllipse(int(x+25*scale),int(y-(155+30*head)*scale*dir ), //глаз правый
              int(x+40*scale),int(y-(125+30*head)*scale*dir));
    txEllipse(int(x-25*scale),int(y-(155+30*head)*scale*dir ),
              int(x-40*scale),int(y-(125+30*head)*scale*dir)); //глаз левый
    txSetFillColor(color1);
    txCircle(x,y,int(90*scale)); //панцирь
    txSetFillColor(color2);

     if (piatnoshko==1)
     {
         POINT draw[6]={{int(x-45*scale),int(y-50*scale*dir) },
                        {int(x-30*scale),    y               },
                        {int(x-45*scale),int(y+50*scale*dir) },   //рисунок на панцире
                        {int(x+45*scale),int(y+50*scale*dir) },
                        {int(x+30*scale),    y               },
                        {int(x+45*scale),int(y-50*scale*dir)}};
         txPolygon(draw,6);
     }
}

void draw_crab(int x, int y,COLORREF color,COLORREF color1,COLORREF color2,double scale,int foot, double smile,int shine, int dir, int cleshni)
{
                                                                                                                    //краб  (1150,325)   //параметр foot-движение ног
    txSetColor(TX_BLACK, 5*scale);                                                                                  //рекомендуемое значение от 30 до -30
    txSetFillColor(color);                                                                                          //при значение + становится тоньще и дальше
    txEllipse(int(x-150*scale),int(y-75*scale*dir),int(x+150*scale),int(y+75*scale*dir));                           //при значении - становятся толще и ближе
    txSetFillColor(color1);
    POINT crab[5]={{int(x+100*scale),int(y+5  *scale*dir) },
                   {int(x+100*scale),int(y-30 *scale*dir) },                                    //параметр smile-улыбка краба
                   {int(x+130*scale),int(y-110*scale*dir) }, //правая клешня нижняя часть       //рекомендуемое значение от 10 до -10
                   {int(x+155*scale),int(y-85 *scale*dir) },                                    //при + значении улыбка вниз
                   {int(x+130*scale),int(y-25 *scale*dir)}};                                    //при - значениях улыбка вверх
    txPolygon (crab,5);
    POINT crab2[5]={{int(x-100*scale),int(y+5  *scale*dir) },                                   //shine-блики в глазах
                    {int(x-100*scale),int(y-30 *scale*dir) },
                    {int(x-130*scale),int(y-110*scale*dir) },  //левая клешня нижняя часть      //cleshni-сжимание/разжимание клешень краба
                    {int(x-155*scale),int(y-85 *scale*dir) },                                   //реком. знач- от 25 до -25
                    {int(x-130*scale),int(y-25 *scale*dir)}};                                   //"-"-сжимается; "+"-разжимается
    txPolygon (crab2,5);
    POINT crabb[10]={{int(x-125*scale),int(y+45 *scale*dir) },
                     {int(x-225*scale),int(y-125*scale*dir) },
                     {int(x-250*scale),int(y-100*scale*dir) },
                     {int(x-235*scale),int(y-65 *scale*dir) },  //три левый ноги верхняя часть
                     {int(x-125*scale),int(y+45 *scale*dir) },
                     {int(x-235*scale),int(y-45 *scale*dir) },
                     {int(x-245*scale),int(y+5  *scale*dir) },
                     {int(x-125*scale),int(y+45 *scale*dir) },
                     {int(x-200*scale),int(y+25 *scale*dir) },
                     {int(x-180*scale),int(y+65 *scale*dir)}};
    txPolygon (crabb,10);
    POINT crabb1[10]={{int(x+125*scale),int(y+45 *scale*dir) },
                      {int(x+225*scale),int(y-125*scale*dir) },
                      {int(x+250*scale),int(y-100*scale*dir) },
                      {int(x+235*scale),int(y-65 *scale*dir) },
                      {int(x+125*scale),int(y+45 *scale*dir) }, //три правые ноги верхняя часть
                      {int(x+235*scale),int(y-45 *scale*dir) },
                      {int(x+245*scale),int(y+5  *scale*dir) },
                      {int(x+125*scale),int(y+45 *scale*dir) },
                      {int(x+200*scale),int(y+25 *scale*dir) },
                      {int(x+180*scale),int(y+65 *scale*dir)}};
    txPolygon (crabb1,10);
    txSetFillColor(color2);
    POINT crab1[10]={{int(x+ 130            *scale),int(y-110*scale*dir) },
                     {int(x+(105+10+cleshni)*scale),int(y-205*scale*dir) },
                     {int(x+(130   -cleshni)*scale),int(y-310*scale*dir) },
                     {int(x+ 130            *scale),int(y-260*scale*dir) },
                     {int(x+ 155            *scale),int(y-235*scale*dir) }, //правая клешня верхняя часть
                     {int(x+ 180            *scale),int(y-260*scale*dir) },
                     {int(x+(180   +cleshni)*scale),int(y-325*scale*dir) },
                     {int(x+ 205            *scale),int(y-300*scale*dir) },
                     {int(x+ 180            *scale),int(y-145*scale*dir) },
                     {int(x+ 155            *scale),int(y-85 *scale*dir)}};
    txPolygon (crab1,10);
    POINT crab3[10]={{int(x- 130            *scale),int(y-110*scale*dir) },
                     {int(x-(105+10+cleshni)*scale),int(y-205*scale*dir) },
                     {int(x-(130   -cleshni)*scale),int(y-310*scale*dir) },
                     {int(x- 130            *scale),int(y-260*scale*dir) },
                     {int(x- 155            *scale),int(y-235*scale*dir) },
                     {int(x- 180            *scale),int(y-260*scale*dir) }, //левая клешня верхняя часть
                     {int(x-(180   +cleshni)*scale),int(y-325*scale*dir) },
                     {int(x- 205            *scale),int(y-300*scale*dir) },
                     {int(x- 180            *scale),int(y-145*scale*dir) },
                     {int(x- 155            *scale),int(y-85 *scale*dir)}};
    txPolygon (crab3,10);
    POINT craab[3]={{int(x- 245      *scale),int(y-105*scale*dir) },
                    {int(x-(370+foot)*scale),int(y+75 *scale*dir) },  //левая крайняя нога нижняя часть
                    {int(x-(290+foot)*scale),int(y+25 *scale*dir)}};
    txPolygon (craab,3);
    POINT craab2[3]={{int(x- 245      *scale),int(y-10 *scale*dir) },
                     {int(x-(245+foot)*scale),int(y+100*scale*dir) }, //правая крайняя нога нижняя часть
                     {int(x-(215+foot)*scale),int(y+50 *scale*dir)}};
    txPolygon (craab2,3);
    POINT craab4[3]={{int(x- 200      *scale),int(y+20*scale*dir) },
                     {int(x-(175+foot)*scale),int(y+120*scale*dir)}, //левая нижняя нога нижняя часть
                     {int(x- 175      *scale),int(y+45*scale*dir)}};
    txPolygon (craab4,3);
    POINT craab1[3]={{int(x+ 245      *scale),int(y-105*scale*dir) },
                     {int(x+(375+foot)*scale),int(y+75 *scale*dir) },  //левая средняя нога нижняя часть
                     {int(x+(295+foot)*scale),int(y+25 *scale*dir)}};
    txPolygon (craab1,3);
    POINT craab3[3]={{int(x+ 245      *scale),int(y-10 *scale*dir) },
                     {int(x+(245+foot)*scale),int(y+100*scale*dir) },  //правая средняя нога нижняя часть
                     {int(x+(215+foot)*scale),int(y+50 *scale*dir)}};
    txPolygon (craab3,3);
    POINT craab5[3]={{int(x+ 200      *scale),int(y+20 *scale*dir) },
                     {int(x+(175+foot)*scale),int(y+120*scale*dir) }, //правая нижняя нога нижняя часть
                     {int(x+ 175      *scale),int(y+45 *scale*dir)}};
    txPolygon (craab5,3);
    txSetColor(TX_BLACK,7*scale);
    txLine(int(x-50*scale),int(y+(15+smile)*scale*dir),int(x-25*scale),int(y+ 15       *scale*dir));
    txLine(int(x-25*scale),int(y+ 15       *scale*dir),int(x+25*scale),int(y+ 15       *scale*dir));  //рот
    txLine(int(x+25*scale),int(y+ 15       *scale*dir),int(x+50*scale),int(y+(15+smile)*scale*dir));
    if (shine==1)
    {
        txSetFillColor(TX_BLACK);
        txEllipse(int(x+40*scale),int(y-145*scale*dir),int(x+90*scale),int(y-35*scale*dir)); //правый глаз
        txEllipse(int(x-80*scale),int(y-145*scale*dir),int(x-30*scale),int(y-35*scale*dir)); //левый глаз
        txSetColor(TX_WHITE);
        txLine(int(x+60*scale),int(y-100*scale*dir),int(x+70*scale),int(y-100*scale*dir));
        txLine(int(x+65*scale),int(y-110*scale*dir),int(x+65*scale),int(y-90*scale*dir ));    //блики в глазах
        txLine(int(x-45*scale),int(y-100*scale*dir),int(x-55*scale),int(y-100*scale*dir));
        txLine(int(x-50*scale),int(y-110*scale*dir),int(x-50*scale),int(y-90*scale*dir ));
    }
    else
    {
        txSetFillColor(TX_BLACK);
        txEllipse(int(x+40*scale),int(y-145*scale*dir),int(x+90*scale),int(y-35*scale*dir));  //глаза
        txEllipse(int(x-80*scale),int(y-145*scale*dir),int(x-30*scale),int(y-35*scale*dir));
    }
}

void draw_gull(int x,int y,COLORREF color,COLORREF color1,double scale,double wing1,double wing2,int nose2,int eye, int dir)
{
                                                                                                           //чайка  (325,835)   //параметр wing1-крыло на переднем плане
    txSetColor(TX_BLACK, 5*scale);                                                                                              //рекомендуемые параметры-от 2 до -2
    txSetFillColor(color);                                                                                                      //при + крыло поднимаются вверх
    POINT gull2[8]={{int(x- 100          *scale*dir),int(y- 35           *scale) },                                             //при - крыло опускаются вниз
                    {int(x-(125+20*wing2)*scale*dir),int(y-(110+40*wing2)*scale) },
                    {int(x-(175+20*wing2)*scale*dir),int(y-(135+40*wing2)*scale) },
                    {int(x-(225+20*wing2)*scale*dir),int(y-(185+40*wing2)*scale) }, //заднее крыло чайки  //параметр wing2-крыло на заднем плане
                    {int(x-(225+20*wing2)*scale*dir),int(y-(235+40*wing2)*scale) },                       //рекомендуемые параметры от 2 до -2
                    {int(x-(125+20*wing2)*scale*dir),int(y-(160+40*wing2)*scale) },                       //при + крыло поднимаются вверх
                    {int(x-(50+20 *wing2)*scale*dir),int(y-(135+40*wing2)*scale) },                       //при - крыло опускаются вниз
                    {int(x- 25           *scale*dir),int(y- 35           *scale)}};
    txPolygon (gull2,8);
    txSetFillColor(color1);                                                                               //параметр nose2- открывание/закрывание клюва
    POINT gull[17]={{int(x- 200         *scale*dir),int(y+15           *scale)  },                        //рекомендуемые параметры от 30 до -10
                    {int(x- 175         *scale*dir),int(y-35           *scale)  },                        //при + клюв открывается
                    {int(x- 50          *scale*dir),int(y-35           *scale)  },                        //при - клюв закрывается
                    {int(x- 25          *scale*dir),int(y-(60+10*wing1)*scale)  },
                    {int(x+(50+10*wing1)*scale*dir),int(y-(185+50*wing1)*scale) },                        //eye-прищуренный и открытый глаз
                    {int(x+ 275         *scale*dir),int(y-(335+60*wing1)*scale) },
                    {int(x+ 275         *scale*dir),int(y-(285+60*wing1)*scale) }, //тело чайки
                    {int(x+ 200         *scale*dir),int(y-(185+40*wing1)*scale) },
                    {int(x+ 150         *scale*dir),int(y-(160+40*wing1)*scale) },
                    {int(x+ 75          *scale*dir),int(y-35            *scale) },
                    {int(x+ 150         *scale*dir),int(y-10            *scale) },
                    {int(x+ 275         *scale*dir),int(y-10            *scale) },
                    {int(x+ 250         *scale*dir),int(y+15            *scale) },
                    {int(x+ 100         *scale*dir),int(y+15            *scale) },
                    {    x,                         int(y+40            *scale) },
                    {int(x- 125         *scale*dir),int(y+40            *scale) },
                    {int(x- 175         *scale*dir),int(y+25            *scale)}};
    txPolygon (gull,17);
    txSetFillColor(RGB(189,102,9));
    POINT nose1[3]={{int(x-175*scale*dir),int(y+25        *scale) },
                    {int(x-235*scale*dir),int(y+(45+nose2)*scale) }, //клюв (нижняя часть)
                    {int(x-215*scale*dir),int(y+(55+nose2)*scale)}};
    txPolygon (nose1,3);
    txSetFillColor(RGB(224,158,16));
    POINT nose[4]={{int(x-200*scale*dir),int(y+15*scale) },
                   {int(x-235*scale*dir),int(y+35*scale) },  //клюв (верхняя часть)
                   {int(x-245*scale*dir),int(y+55*scale) },
                   {int(x-175*scale*dir),int(y+25*scale)}};
    txPolygon (nose,4);

    if (eye==1)
    {
         txSetFillColor(TX_BLACK);
         txCircle(int(x-150*scale*dir),int(y-5*scale),4*scale);     //глаз
         txSetColor(TX_BLACK,5*scale);
    }
    else
    {
          txSetColor(TX_BLACK,5*scale);
          txLine(int(x-160*scale*dir),int(y-5*scale),int(x-130*scale*dir),int(y-5*scale));
    }
}

void draw_dolphin(int x,int y,COLORREF color,COLORREF color1,double scale, double smile, int tail, int blush, int dir, double plavnic)
{
                                                                                                //дельфин  (925,625)   //параметр smile-улыбка
    txSetColor(TX_BLACK, 5*scale);                                                                                     //рекомендуемые значения от 1 до -1
    txSetFillColor(color);                                                                                             //при +1 улыбается, при -1 не улыбается
    POINT dolph1[6]={{int(x-75 *scale*dir),int(y-45 *scale) },
                     {int(x-75 *scale*dir),int(y-75 *scale) },
                     {int(x-125*scale*dir),int(y-100*scale) },                                  //параметр tail-движение хвоста
                     {int(x-75 *scale*dir),int(y-125*scale) }, //верхний плавник                //рекомендуемые значения от 40 до -40
                     {int(x-25 *scale*dir),int(y-125*scale) },                                  //при + движение хвоста влево
                     {int(x+25 *scale*dir),int(y-95 *scale)}};                                  //при - движение хвоста вправо
    txPolygon (dolph1,6);
    POINT dolph2[7]={{int(x+ 150            *scale*dir),int(y-(35 +10*plavnic)*scale) },                                      //blush-румянец
                     {int(x+(175+25*plavnic)*scale*dir),int(y+(25 +10*plavnic)*scale) },
                     {int(x+(175+25*plavnic)*scale*dir),int(y+(75 +10*plavnic)*scale) },                                      //plavnic-плавники
                     {int(x+(150+25*plavnic)*scale*dir),int(y+(125+10*plavnic)*scale) }, //задний (дальный) плавник           //рекомендуется от -0.5 до 1
                     {int(x+(150+25*plavnic)*scale*dir),int(y+(100+10*plavnic)*scale) },                                      //при "-" сужается и уменьшается
                     {int(x+(125+25*plavnic)*scale*dir),int(y+(50 +10*plavnic)*scale) },                                      //при "+" расширяется и увеличивается
                     {int(x+ 100            *scale*dir),int(y+(15 +10*plavnic)*scale)}};
    txPolygon (dolph2,7);
    txSetFillColor(color1);
    POINT dolph[22]={{int(x+ 200      *scale*dir),int(y-75 *scale) },
                     {int(x+ 225      *scale*dir),int(y-75 *scale) },
                     {int(x+ 250      *scale*dir),int(y-50 *scale) },
                     {int(x+ 225      *scale*dir),int(y-25 *scale) },
                     {int(x+ 150      *scale*dir),int(y-25 *scale) },
                     {int(x+ 100      *scale*dir),int(y+25 *scale) },
                     {int(x- 50       *scale*dir),int(y+150*scale) },
                     {int(x- 100      *scale*dir),int(y+275*scale) },
                     {int(x-(50+tail) *scale*dir),int(y+300*scale) },
                     {int(x-(25+tail) *scale*dir),int(y+350*scale) },
                     {int(x-(75+tail) *scale*dir),int(y+350*scale) },
                     {int(x-(100+tail)*scale*dir),int(y+325*scale) }, //тело дельфина
                     {int(x-(125+tail)*scale*dir),int(y+350*scale) },
                     {int(x-(175+tail)*scale*dir),int(y+375*scale) },
                     {int(x-(175+tail)*scale*dir),int(y+325*scale) },
                     {int(x- 125      *scale*dir),int(y+275*scale) },
                     {int(x- 150      *scale*dir),int(y+100*scale) },
                     {int(x- 100      *scale*dir),int(y-25 *scale) },
                     {int(x- 75       *scale*dir),int(y-50 *scale) },
                     {int(x+ 25       *scale*dir),int(y-100*scale) },
                     {int(x+ 100      *scale*dir),int(y-125*scale) },
                     {int(x+ 150      *scale*dir),int(y-125*scale)}};
    txPolygon (dolph,22);
    txSetFillColor(TX_BLACK);
    txCircle(int(x+125*scale*dir),int(y-75*scale),5*scale); //глаз
    txSetFillColor(color);
    POINT dolph3[6]={{int(x+(75+20*plavnic)*scale*dir),int(y-(25 +10*plavnic)*scale) },
                     {int(x+(50+20*plavnic)*scale*dir),int(y+(25 +10*plavnic)*scale) },
                     {    x                           ,int(y+(75 +10*plavnic)*scale) },
                     {int(x-(50+20*plavnic)*scale*dir),int(y+(100+10*plavnic)*scale) }, //передний плавник
                     {    x                           ,int(y+(25 +10*plavnic)*scale) },
                     {    x                           ,    y                        }};
    txPolygon (dolph3,6);
    txSetColor(TX_BLACK,5*scale);
    txLine(int(x+250*scale*dir),int(y- 50          *scale ),
           int(x+200*scale*dir),int(y- 50          *scale));
    txLine(int(x+200*scale*dir),int(y- 50          *scale ),  //улыбка
           int(x+165*scale*dir),int(y-(60+10*smile)*scale));
    if (blush==1)
    {
        txSetColor(TX_PINK,3*scale);
        txLine(int(x+135*scale*dir),int(y-65*scale ),
               int(x+130*scale*dir),int(y-50*scale));
        txLine(int(x+145*scale*dir),int(y-65*scale ),     //румянец на щечках
               int(x+140*scale*dir),int(y-50*scale));
        txLine(int(x+155*scale*dir),int(y-65*scale ),
               int(x+150*scale*dir),int(y-50*scale));
    }
}

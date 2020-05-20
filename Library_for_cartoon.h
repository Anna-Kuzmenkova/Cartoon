#include "TXLib.h"

void draw_Mark(int x, int y,int phase);
void draw_Mark1(int x, int y,int phase1);
void draw_turtle2     (int x,       int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int phase, double head, int piatnoshko,int dir, int kx,    int ky     );
void draw_egg1        (int x,int x1,int y,COLORREF color,                                double scale, int egg,   int scorlupa,int dir,       int sdvigX,int sdvigY,int lines);
void draw_Adam(int x,int y, int phase);
void draw_Adam1(int phase);
void draw_dno(int x, int y);
void draw_dno1(int x, int y);
void draw_turtle1(int x, int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int hand, double head, int piatnoshko, int dir,int kx, int ky);
void draw_Sam(int x, int y,int phase);
void draw_Sem(int x1, int y,int phase);
void draw_Mark2(int x,int y,int phase);
void draw_fissy(int x, int y, int phase1, int num);


void draw_Mark(int x, int y,int phase)
{
    int hand,kx,ky;
    if((phase==0)||(phase==4)||(phase==8))
    {
        hand=0;
        kx=0;
        ky=0;
    }
    if((phase==1)||(phase==3))
    {
        hand=20;
        kx=10;
        ky=-10;
    }
    if(phase==2)
    {
        hand=40;
        kx=20;
        ky=-20;
    }
    if((phase==5)||(phase==7))
    {
        hand=-20;
        kx=-10;
        ky=10;
    }
    if(phase==6)
    {
        hand=-40;
        kx=-20;
        ky=20;
    }

   draw_turtle2(620,y, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.4, hand, 0., -1, 1, kx, ky);

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void draw_Mark1(int x, int y,int phase1)
{
    int hand,kx,ky;
    if((phase1==0)||(phase1==4)||(phase1==8))
    {
        hand=0;
        kx=0;
        ky=0;
    }
    if((phase1==1)||(phase1==3))
    {
        hand=20;
        kx=10;
        ky=-10;
    }
    if(phase1==2)
    {
        hand=40;
        kx=20;
        ky=-20;
    }
    if((phase1==5)||(phase1==7))
    {
        hand=-20;
        kx=-10;
        ky=10;
    }
    if(phase1==6)
    {
        hand=-40;
        kx=-20;
        ky=20;
    }

   draw_turtle1(600,y, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, hand, 0., -1, 1, kx, ky);

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void draw_turtle2(int x, int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int hand, double head, int piatnoshko, int dir,int kx, int ky)
{
    txSetColor(TX_BLACK, 5*scale);                                                               //параметр head- движение головы
    txSetFillColor(color);                                                                       //head >/=0
    txCircle(x,int(y-(130+30*head)*scale*dir),45*scale); //голова                                //когда head=3, головы не видно
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon[8]= {{int(x-45 *scale), int(y- 70       *scale*dir) },                         //рекомендуется брать от -0.5 до -2.5
                       {int(x-90 *scale), int(y-(105-hand)*scale*dir) },
                       {int(x-120*scale), int(y-(105-hand)*scale*dir) },
                       {int(x-180*scale), int(y-(60 -hand)*scale*dir) },  //лапа левая            //параметр hand-движение плавников
                       {int(x-180*scale), int(y-(15 -hand)*scale*dir) },                          //рекомендуется брать от 50 до -50
                       {int(x-135*scale), int(y-(60 -hand)*scale*dir) },                          //при + движение плавников вниз,
                       {int(x-90 *scale), int(y-(75 -hand)*scale*dir) },                          //при - движение плавников вверх
                       {int(x-70 *scale), int(y- 60       *scale*dir)}};
    txPolygon (polygon,8);                                                                        //piatnoshko-появление/исчезновение рисунка на панцире
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon1[8]={{int(x+55*scale ),int(y- 70       *scale*dir) },
                       {int(x+100*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+130*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+190*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+190*scale),int(y-(15 -hand)*scale*dir) },   //лапа правая
                       {int(x+145*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+100*scale),int(y-(75 -hand)*scale*dir) },
                       {int(x+70*scale ),int(y- 55       *scale*dir)}};
    txPolygon (polygon1,8);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon2[5]= {{int(x- 50    *scale),int(y+  65    *scale*dir) },
                        {int(x-(90+kx)*scale),int(y+( 90+ky)*scale*dir) },
                        {int(x-(90+kx)*scale),int(y+(120+ky)*scale*dir) }, //нога левая
                        {int(x-(60+kx)*scale),int(y+(135+ky)*scale*dir) },
                        {int(x- 30    *scale),int(y+  75    *scale*dir)}};
    txPolygon (polygon2,5);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon3[5]={{int(x+50     *scale),int(y+65      *scale*dir) },
                       {int(x+(90+kx)*scale),int(y+(90+ky) *scale*dir) },
                       {int(x+(90+kx)*scale),int(y+(120+ky)*scale*dir) }, //нога правая
                       {int(x+(60+kx)*scale),int(y+(135+ky)*scale*dir) },
                       {int(x+30     *scale),int(y+75      *scale*dir)}};
    txPolygon (polygon3,5);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT rhomb[4]={{    x,          int(y+ 80*scale*dir) },
                    {int(x-15*scale),int(y+105*scale*dir) },  //хвост
                    {    x,          int(y+120*scale*dir) },
                    {int(x+15*scale),int(y+105*scale*dir)}};
    txPolygon (rhomb,4);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    txSetFillColor(TX_BLACK);
    txEllipse(int(x+25*scale),int(y-(155+30*head)*scale*dir ), //глаз правый
              int(x+40*scale),int(y-(125+30*head)*scale*dir));
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    txEllipse(int(x-25*scale),int(y-(155+30*head)*scale*dir ),
              int(x-40*scale),int(y-(125+30*head)*scale*dir)); //глаз левый
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    txSetFillColor(color1);
    txCircle(x,y,int(90*scale)); //панцирь
    txSetFillColor(color2);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


void draw_egg1(int x,int x1,int y,COLORREF color,double scale,int egg,int scorlupa,int dir,int sdvigX,int sdvigY,int lines)
{
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if(egg==1)                                                                                //egg-рисует целое яйцо, если egg=1
    {                                                                                         //sdvigX- движение верхней части скарлупы в право и лево
        txSetColor(TX_BLACK, 5*scale);                                                        //при "+" вправо; при "-" влево;
        txSetFillColor(color);                                                                //sdvigY-движение верхней ЧС вниз и вверх
        txEllipse(x-140*scale, y-380*scale*dir, x+200*scale, y);                              //при "+" вверх; при "-" вниз;
        txSetFillColor(TX_WHITE);                                                             //scorlupa-отделение верхней от нижней части
        txCircle(x-80 *scale, y-200*scale*dir, 7 *scale);                                     //если scorlupa=1, то рисуется верхняя часть, иначе нет
        txCircle(x          , y-120*scale*dir, 10*scale);                                     //lines-трещены на яйце
        txCircle(x+20 *scale, y-220*scale*dir, 6 *scale);                                     //если lines=1, то рисуются трещины, иначе нет
        txCircle(x+140*scale, y-180*scale*dir, 8 *scale);
        txCircle(x+120*scale, y-80 *scale*dir, 11*scale);    //круги на яйце
        txCircle(x-60 *scale, y-60 *scale*dir, 7 *scale);
        txCircle(x+60 *scale, y-340*scale*dir, 9 *scale);
        txCircle(x-20 *scale, y-320*scale*dir, 6 *scale);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        if(lines==1)
        {
            txLine(x-110*scale, y-300*scale*dir, x-90 *scale, y-260*scale*dir);
            txLine(x-90 *scale, y-260*scale*dir, x-30 *scale, y-300*scale*dir);
            txLine(x-30 *scale, y-300*scale*dir, x+27 *scale, y-260*scale*dir); //линии скорлупы
            txLine(x+27 *scale, y-260*scale*dir, x+85 *scale, y-300*scale*dir);
            txLine(x+85 *scale, y-300*scale*dir, x+145*scale, y-260*scale*dir);
            txLine(x+145*scale, y-260*scale*dir, x+165*scale, y-300*scale*dir);
        }
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else
    {
        COLORREF colorfon;
        colorfon=RGB(255,249,179);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        txSetColor(TX_BLACK, 5*scale);     //нижняя часть скорлупы
        txSetFillColor(color);
        txChord(x-140*scale, y-380*scale*dir,x+200*scale, y, -220, 260);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        txSetColor(colorfon, 5*scale);    //дополнительный декор на нижней части скорлупы
        txSetFillColor(colorfon);
        POINT send[15]={{int(x-110*scale), int(y-300*scale*dir) },
                        {int(x-105*scale), int(y-320*scale*dir) },
                        {int(x-100*scale), int(y-305*scale*dir) },
                        {int(x- 90*scale), int(y-335*scale*dir) },
                        {int(x- 70*scale), int(y-310*scale*dir) },
                        {int(x- 20*scale), int(y-320*scale*dir) },
                        {int(x+ 15*scale), int(y-300*scale*dir) },
                        {int(x+ 50*scale), int(y-335*scale*dir) },
                        {int(x+ 70*scale), int(y-320*scale*dir) },
                        {int(x+ 95*scale), int(y-305*scale*dir) },
                        {int(x+110*scale), int(y-335*scale*dir) },
                        {int(x+125*scale), int(y-310*scale*dir) },
                        {int(x+135*scale), int(y-320*scale*dir) },
                        {int(x+150*scale), int(y-315*scale*dir) },
                        {int(x+160*scale), int(y-300*scale*dir)}};
        txPolygon (send,15);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        txCircle(x- 95*scale,y-370*scale*dir,2*scale);
        txCircle(x- 60*scale,y-360*scale*dir,2*scale);
        txCircle(x- 45*scale,y-340*scale*dir,2*scale);
        txCircle(x- 10*scale,y-355*scale*dir,2*scale);
        txCircle(x+ 15*scale,y-365*scale*dir,2*scale);
        txCircle(x+ 35*scale,y-340*scale*dir,2*scale);
        txCircle(x+ 75*scale,y-345*scale*dir,2*scale);
        txCircle(x+125*scale,y-350*scale*dir,2*scale);
        txCircle(x+135*scale,y-365*scale*dir,2*scale);
        txCircle(x+115*scale,y-370*scale*dir,2*scale);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        txSetFillColor(colorfon);
        txSetColor(TX_BLACK, 5*scale);
        POINT decor[7]={{int(x-111*scale), int(y-300*scale*dir) },
                        {int(x- 90*scale), int(y-260*scale*dir) },
                        {int(x- 30*scale), int(y-300*scale*dir) },
                        {int(x+ 27*scale), int(y-260*scale*dir) },
                        {int(x+ 85*scale), int(y-300*scale*dir) },
                        {int(x+145*scale), int(y-260*scale*dir) },
                        {int(x+168*scale), int(y-300*scale*dir)}};
        txPolygon (decor,7);
        txSetColor(colorfon,11*scale);
        txLine(x-111*scale, y-302*scale*dir,x+165*scale,y-302*scale*dir);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        txSetColor(TX_BLACK,5*scale);
        txLine(x-110*scale, y-298*scale*dir, x- 90*scale, y-260*scale*dir);
        txLine(x- 90*scale, y-260*scale*dir, x- 30*scale, y-300*scale*dir);
        txLine(x- 30*scale, y-300*scale*dir, x+ 27*scale, y-260*scale*dir);
        txLine(x+ 27*scale, y-260*scale*dir, x+ 85*scale, y-300*scale*dir);
        txLine(x+ 85*scale, y-300*scale*dir, x+145*scale, y-260*scale*dir);
        txLine(x+145*scale, y-260*scale*dir, x+167*scale, y-300*scale*dir);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        txSetColor(TX_BLACK, 5*scale);
        txSetFillColor(TX_WHITE);
        txCircle(x- 80*scale, y-200*scale*dir,  7*scale);
        txCircle(x          , y-120*scale*dir, 10*scale);
        txCircle(x+ 20*scale, y-220*scale*dir,  6*scale);
        txCircle(x+140*scale, y-180*scale*dir,  8*scale);
        txCircle(x+120*scale, y- 80*scale*dir, 11*scale);    //круги на яйце
        txCircle(x- 60*scale, y- 60*scale*dir,  7*scale);
        //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
        if(scorlupa==1)
        {
            txSetColor(TX_BLACK, 5*scale);
            txSetFillColor(color);
            txChord(x-(140-sdvigX)*scale, y-(380+sdvigY)*scale*dir, x+(200+sdvigX)*scale, y-sdvigY*scale*dir, 40, 100);  //верхняя часть скорлупы
            //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
            txSetFillColor(TX_WHITE);      //круги на скорлупе
            txCircle(x+(60+sdvigX)*scale, y-(340+sdvigY)*scale*dir, 9*scale);
            txCircle(x-(20-sdvigX)*scale, y-(320+sdvigY)*scale*dir, 6*scale);
            //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
            txSetFillColor(color);        //декор на скорлупе
            POINT decor[7]={{int(x-(111-sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x-( 90-sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x-( 30-sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x+( 27+sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x+( 85+sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x+(145+sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x+(168+sdvigX)*scale), int(y-(300+sdvigY)*scale*dir)}};
            txPolygon (decor,7);
            //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
            txSetColor(color,11*scale);
            txLine(x-(99-sdvigX)*scale, y-(302+sdvigY)*scale*dir,x+(155+sdvigX)*scale,y-(302+sdvigY)*scale*dir);
            //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
            txSetColor(TX_BLACK,5*scale);
            txLine(x-(110-sdvigX)*scale, y-(298+sdvigY)*scale*dir, x-( 90-sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x-( 90-sdvigX)*scale, y-(260+sdvigY)*scale*dir, x-( 30-sdvigX)*scale, y-(300+sdvigY)*scale*dir);
            txLine(x-( 30-sdvigX)*scale, y-(300+sdvigY)*scale*dir, x+( 27+sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x+( 27+sdvigX)*scale, y-(260+sdvigY)*scale*dir, x+( 85+sdvigX)*scale, y-(300+sdvigY)*scale*dir);
            txLine(x+( 85+sdvigX)*scale, y-(300+sdvigY)*scale*dir, x+(145+sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x+(145+sdvigX)*scale, y-(260+sdvigY)*scale*dir, x+(167+sdvigX)*scale, y-(300+sdvigY)*scale*dir);
        }
    }
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------


void draw_Adam(int x,int y, int phase)
{
    double wing1, wing2;
    if((phase==0)||(phase==4)||(phase==8))
    {
        wing1=0;
        wing2=0;
    }
    if((phase==1)||(phase==3))
    {
        wing1=1;
        wing2=1;
    }
    if(phase==2)
    {
        wing1=2;
        wing2=2;
    }
    if((phase==5)||(phase==7))
    {
        wing1=-1;
        wing2=-1;
    }
    if(phase==6)
    {
        wing1=-2;
        wing2=-2;
    }
    draw_gull(x, 390, RGB(120, 120, 120), RGB(180,180,180), 0.4, wing1, wing2, 0, 1, 1);

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void draw_Adam1(int phase)
{
    double wing1, wing2;
    int x, dx, y;
    double scale, scalemax, dscale;
    COLORREF colorfon;
    colorfon=RGB(0,182,255);
    if((phase==0)||(phase==4)||(phase==8))
    {
        wing1=0;
        wing2=0;
    }
    if((phase==1)||(phase==3))
    {
        wing1=1;
        wing2=1;
    }
    if(phase==2)
    {
        wing1=2;
        wing2=2;
    }
    if((phase==5)||(phase==7))
    {
        wing1=-1;
        wing2=-1;
    }
    if(phase==6)
    {
        wing1=-2;
        wing2=-2;
    }
    scale=1.;
    dscale=0.005;
    x=600;
    dx=-4;
    for(y=390; y<1200; y+=4)
    {
        scale-=dscale;
        x+=dx;
        txSetFillColor(colorfon);
        txClear();
        draw_gull(x, y, RGB(120, 120, 120), RGB(180,180,180), scale,  0 , 0 ,  0,  -1, 1);
        txSleep(40);
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void draw_dno(int x, int y)
{
    txSetColor(RGB(235, 214, 162),5);
    txSetFillColor(RGB(235, 214, 162));
    POINT polygon[4]= {{int(x-750),int(y+300) },
                       {int(x-750),int(y-100) },
                       {int(x+850),int(y-100) },
                       {int(x+850),int(y+300)}};
    txPolygon (polygon,4);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void draw_dno1(int x, int y)
{
    txSetColor(RGB(235, 214, 162),5);
    txSetFillColor(RGB(235, 214, 162));
    POINT polygon[4]= {{int(x-750),int(y+300) },
                       {int(x-750),int(y-300) },
                       {int(x+850),int(y-300) },
                       {int(x+850),int(y+300)}};
    txPolygon (polygon,4);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


void draw_Sam(int x1, int y,int phase)
{
    int foot;
    if((phase==0)||(phase==6))
    {
        foot=0;
    }
    if((phase==1)||(phase==5))
    {
        foot=10;
    }
    if((phase==2)||(phase==4))
    {
        foot=20;
    }
    if(phase==3)
    {
        foot=30;
    }
    if((phase==7)||(phase==11))
    {
        foot=-10;
    }
     if((phase==8)||(phase==10))
    {
        foot=-20;
    }
    if(phase==9)
    {
        foot=-30;
    }

    draw_crab(x1, 707, RGB(150,13,6), RGB(110,16,11), RGB(92,9,5), 0.4,foot, 0., 2., 1, 0);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void draw_Sem(int x1, int y1,int phase)
{
    int cleshni;
    if((phase==0)||(phase==6))
    {
       cleshni=0;
    }
    if((phase==1)||(phase==5))
    {
       cleshni=10;
    }
    if((phase==2)||(phase==4))
    {
      cleshni=20;
    }
    if(phase==3)
    {
        cleshni=25;
    }
    if((phase==7)||(phase==11))
    {
       cleshni=-10;
    }
     if((phase==8)||(phase==10))
    {
        cleshni=-20;
    }
    if(phase==9)
    {
       cleshni=-25;
    }

    draw_crab(x1, 700, RGB(150,13,6), RGB(110,16,11), RGB(92,9,5), 0.4,0, 0., 2., 1, cleshni);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void draw_turtle1(int x, int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int hand, double head, int piatnoshko, int dir,int kx, int ky)
{
    txSetColor(TX_BLACK, 5*scale);                                                               //параметр head- движение головы
    txSetFillColor(color);                                                                       //head >/=0
    txCircle(x,int(y-(130+30*head)*scale*dir),45*scale); //голова                                //когда head=3, головы не видно
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon[8]= {{int(x-45 *scale), int(y- 70       *scale*dir) },                         //рекомендуется брать от -0.5 до -2.5
                       {int(x-90 *scale), int(y-(105-hand)*scale*dir) },
                       {int(x-120*scale), int(y-(105-hand)*scale*dir) },
                       {int(x-180*scale), int(y-(60 -hand)*scale*dir) },  //лапа левая            //параметр hand-движение плавников
                       {int(x-180*scale), int(y-(15 -hand)*scale*dir) },                          //рекомендуется брать от 50 до -50
                       {int(x-135*scale), int(y-(60 -hand)*scale*dir) },                          //при + движение плавников вниз,
                       {int(x-90 *scale), int(y-(75 -hand)*scale*dir) },                          //при - движение плавников вверх
                       {int(x-70 *scale), int(y- 60       *scale*dir)}};
    txPolygon (polygon,8);                                                                        //piatnoshko-появление/исчезновение рисунка на панцире
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon1[8]={{int(x+55*scale ),int(y- 70       *scale*dir) },
                       {int(x+100*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+130*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+190*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+190*scale),int(y-(15 -hand)*scale*dir) },   //лапа правая
                       {int(x+145*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+100*scale),int(y-(75 -hand)*scale*dir) },
                       {int(x+70*scale ),int(y- 55       *scale*dir)}};
    txPolygon (polygon1,8);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon2[5]= {{int(x- 50    *scale),int(y+  65    *scale*dir) },
                        {int(x-(90+kx)*scale),int(y+( 90+ky)*scale*dir) },
                        {int(x-(90+kx)*scale),int(y+(120+ky)*scale*dir) }, //нога левая
                        {int(x-(60+kx)*scale),int(y+(135+ky)*scale*dir) },
                        {int(x- 30    *scale),int(y+  75    *scale*dir)}};
    txPolygon (polygon2,5);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT polygon3[5]={{int(x+50     *scale),int(y+65      *scale*dir) },
                       {int(x+(90+kx)*scale),int(y+(90+ky) *scale*dir) },
                       {int(x+(90+kx)*scale),int(y+(120+ky)*scale*dir) }, //нога правая
                       {int(x+(60+kx)*scale),int(y+(135+ky)*scale*dir) },
                       {int(x+30     *scale),int(y+75      *scale*dir)}};
    txPolygon (polygon3,5);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    POINT rhomb[4]={{    x,          int(y+ 80*scale*dir) },
                    {int(x-15*scale),int(y+105*scale*dir) },  //хвост
                    {    x,          int(y+120*scale*dir) },
                    {int(x+15*scale),int(y+105*scale*dir)}};
    txPolygon (rhomb,4);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    txSetFillColor(TX_BLACK);
    txEllipse(int(x+25*scale),int(y-(155+30*head)*scale*dir ), //глаз правый
              int(x+40*scale),int(y-(125+30*head)*scale*dir));
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    txEllipse(int(x-25*scale),int(y-(155+30*head)*scale*dir ),
              int(x-40*scale),int(y-(125+30*head)*scale*dir)); //глаз левый
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    txSetFillColor(color1);
    txCircle(x,y,int(90*scale)); //панцирь
    txSetFillColor(color2);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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


void draw_Mark2(int x, int y,int phase)
{
    int hand;
    if((phase==0)||(phase==4)||(phase==8))
    {
        hand=0;
    }
    if((phase==1)||(phase==3))
    {
        hand=20;
    }
    if(phase==2)
    {
        hand=40;
    }
    if((phase==5)||(phase==7))
    {
        hand=-20;
    }
    if(phase==6)
    {
        hand=-40;
    }

   draw_turtle(445, y, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.4, hand, 0., 1, -1);

}


void draw_fissy(int x, int y, int phase1, int num)
{
    int mov;
    if((phase1==0)||(phase1==10))
    {
        mov=0;
    }
    if((phase1==1)||(phase1==9))
    {
        mov=2;
    }
    if((phase1==2)||(phase1==8))
    {
        mov=4;
    }
    if((phase1==3)||(phase1==7))
    {
        mov=6;
    }
    if((phase1==4)||(phase1==6))
    {
        mov=8;
    }
    if(phase1==5)
    {
        mov=10;
    }

    if (num=1)
    {
        draw_Fish(x,150,1.5,RGB(186,148,255),RGB(102,102,255),mov,-1);
    }
    if (num=2)
    {
        draw_Fish(x,770,1.,RGB(214,214,77),RGB(204,131,22),mov,-1);
    }
}


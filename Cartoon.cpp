/// \author Anya Kuzmenkova

#include "TXLib.h"
#include "MKLib.h"
#include "SeaLib.h"
#include "CartoonLib.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void title();
void draw_first_scene();
void draw_second_scene();
void draw_third_scene();
void draw_fourth_scene();
void final_titles1();
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    txCreateWindow(1200,900);
    txClear();
    title();
    draw_first_scene();
    draw_second_scene();
    draw_third_scene();
    draw_fourth_scene();
    final_titles1();
    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void final_titles1()
{
    COLORREF colorfon;
    colorfon=RGB(255,249,179);
    txSetColor(TX_BLACK);
    txSetFillColor(colorfon);
    int y,dy,ymax;
    double sizeO;
    ymax=1000;dy=5;sizeO=70.;
    for(y=ymax;y>-1200;y-=dy)
    {
        txClear();
        txSelectFont ("Comic Sans MS",sizeO, sizeO-50., true);
        txDrawText  (0, y, 1150, y+1200, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" "Конец мультфильма!\n" "Над мультфильмом работала Кузьменкова Анна.\n"  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" "Отдельная благодарность Льву Горбушину за предоставленных персонажей:\n"
        "прекрасных рыбок и гусеницу;\n" "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" "На мультик было затрачено:\n" "2 месяца 22 дня;\n" "(с 22 сентября по 14 декабря);\n"
        "Множество часов работы;\n" "Огромное количество сил;\n" "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" "Спасибо за внимание!)))\n" "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"  );
        txSleep(40);
    }

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void title()
{
    int y,dy,ymax;
    ymax=800;
    dy=7;
    for(y=-300;y<ymax;y+=dy)
    {
        txSetFillColor(RGB(255,249,179));
        txClear();
        txSetColor(TX_BLACK);
        txSelectFont ("Comic Sans MS", 80, 40, true);
        txDrawText  (0, y, 1150, y+300, "Вашему вниманию\n" "представляется:");
        txSleep(40);
    }
    txClear();
    HDC titulname = txLoadImage ("фон_заставка.bmp");
    txBitBlt (txDC(), -100, 0, 1300, 1400,titulname, 0, 0);
    txDeleteDC (titulname);
    txSleep(3000);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void draw_first_scene ()
{
    COLORREF colorfon;
    double scale , scalemax, dscale ,head, headmax, dh           ;
    int    sdvigY, sdvigYmax, dsdvigY, y, dy, y1, y1max, dy1, phase;
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    colorfon=RGB(255,249,179);
    sdvigYmax= 700   ;
    dsdvigY  =   5   ;
    dscale   =   0.01;
    scalemax =   0.7 ;
    dy       =   3   ;
    y        = 620   ;
    headmax  =  -1.5 ;
    dh       =   0.1 ;
    y1max    =1200   ;
    dy1      =   5   ;
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    for(scale=0.2; scale<scalemax; scale+=dscale)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_egg1(600, 450, 700, RGB(201,201,201), scale, 1, 1, 1, 0, 0, 0);
        txSleep(40);
    }
    draw_egg1(600, 450, 700, RGB(201,201,201), scalemax, 1, 1, 1, 0, 0, 1);
    txSleep(800);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    phase=0;
    for(sdvigY=0; sdvigY<sdvigYmax; sdvigY+=dsdvigY)
    {
        if (sdvigY>200)
        {
            y-=dy;
            phase+=1;
            phase%=8;
            txSetFillColor(colorfon);
            txClear();
            draw_Mark(615, y, phase);
        }
        draw_egg1(600, 450, 700, RGB(201,201,201), scalemax, 0, 1, 1, 0, sdvigY, 0);
        txSleep(40);
        txSetFillColor(colorfon);
        txClear();
    }
    draw_egg1   (600, 450, 700, RGB(201,201,201), scalemax, 0, 0, 1, 0, 0, 0                     );
    draw_turtle2(620, y, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.4, 0, 0., -1, 1, 0, 0);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    for(head=0; head>headmax; head-=dh)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_turtle2(620, y, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.4, 0, head, -1, 1, 0, 0);
        draw_egg1   (600, 450, 700, RGB(201,201,201), scalemax, 0, 0, 1, 0, 0, 0                       );
        txSleep(60);
    }
    txSleep(560);
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    for(head=headmax; head<0; head+=dh)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_turtle2(620 ,y, RGB(131,161,22),   RGB(4,77,16 ),   RGB(232,196,77), 0.4,  0,  head, -1, 1, 0,0);
        draw_egg1   (600, 450, 700, RGB(201,201,201), scalemax, 0, 0, 1, 0, 0, 0                            );
        txSleep(60);
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    phase=0;
    scale=0.4;
    for(y1=700; y1<y1max; y1+=dy1)
    {
        phase+=1;
        phase%=8;
        scale+=0.001;
        txSetFillColor(colorfon);
        txClear();
        draw_Mark(620, y, phase                                             );
        draw_egg1 (600, 450, y1, RGB(201,201,201), scalemax, 0, 0, 1, 0, 0, 0);
        txSleep(60);
     }
     //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
     phase=0;
     for(y1=y; y1>-100; y1-=dy1)
     {
        phase+=1;
        phase%=8;
        txSetFillColor(colorfon);
        txClear();
        draw_Mark(620, y1, phase);
        txSleep(60);
     }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void draw_second_scene()
{
    COLORREF colorfon;
    int        x, dx, xmax, phase, y;
    double scale, scalemax, dscale  ;
    colorfon=RGB(0,182,255);
    xmax    =1200   ;
    dx      =   5   ;
    phase   =   0   ;
    scalemax=   0.9 ;
    dscale  =   0.01;
    for(x=xmax; x>600;x-=dx)
        {
            phase+=1;
            phase%=8;
            txSetFillColor(colorfon);
            txClear();
            draw_Adam(x, 390, phase);
            txSleep(60);
        }
    txSetFillColor(colorfon);
    txClear();
    draw_gull(600, 390, RGB(120, 120, 120), RGB(180,180,180), 0.4,  0 , 0 ,  0,  1, 1);
    txSleep(560);
    txSetFillColor(colorfon);
    txClear();
    draw_gull(600, 390, RGB(120, 120, 120), RGB(180,180,180), 0.4,  0 , 0 ,  0,  2, 1);
    for(scale=0.4;scale<scalemax;scale+=dscale)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_gull(600, 390, RGB(120, 120, 120), RGB(180,180,180), scale,  0 , 0 ,  0,  2, 1);
        txSleep(40);
    }

    for(y=390; y>-100; y+=-5)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_gull(600, y, RGB(120, 120, 120), RGB(180,180,180), scalemax,  0 , 0 ,  0,  2, 1);
        txSleep(40);
    }
    for(y=1100; y>700; y+=-5)
    {
          txSetFillColor(colorfon);
          txClear();
          draw_dno(600,y);
          draw_turtle(600 ,y+150, RGB(131,161,22 ), RGB(4,77,16 ), RGB(232,196,77), 0.2, 0, -1., -1, 1);
          txSleep(40);
    }
    for(y=700; y>600; y+=-3)
    {
          txSetFillColor(colorfon);
          txClear();
          draw_dno(600,700);
          draw_turtle(600 ,y+150, RGB(131,161,22 ), RGB(4,77,16 ), RGB(232,196,77), 0.2, 0, -1., -1, 1);
          txSleep(40);
    }
    for(y=700; y<1100; y+=5)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_dno(600,y);
        draw_turtle(600 ,y+50, RGB(131,161,22 ), RGB(4,77,16 ), RGB(232,196,77), 0.2, 0, -1., -1, 1);
        txSleep(40);
    }
    for(y=-100; y<390; y+=5)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_gull(600, y, RGB(120, 120, 120), RGB(180,180,180), scalemax,  0 , 0 ,  0,  2, 1);
        txSleep(40);
    }
    draw_Adam1(0);

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void draw_third_scene()
{
    COLORREF colorfon;
    int    x, dx, xmax, phase, y, dy, ymax, nose, x1,  y1, n, k, k1, phase1;
    double scale, scalemax, dscale, head, smile                            ;
    colorfon=RGB(0,182,255);
    ymax= 1000;
    dy  =-3;
    txSetFillColor(colorfon);
    txClear();
    draw_dno1(600,600);
    phase1=0;
    for(y=ymax; y>700; y+=dy)
    {
        phase1+=1;
        phase1%=8;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_Mark1(600, y, phase1);
        txSleep(50);
    }
    x = 1200;
    dx=-   3;
    for(y=0; y<400; y+=4)
    {
        x+=dx;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_gull(x, y, RGB(120, 120, 120), RGB(180,180,180), 0.6,  0 , 0 ,  0,  1, 1);
        draw_turtle1(600,700, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, 0., -1, 1,0,0);
        txSleep(40);
    }
    for(nose=0; nose<30; nose+=1)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_gull(x, y, RGB(120, 120, 120), RGB(180,180,180), 0.6,  0 , 0 ,  nose,  1, 1);
        draw_turtle1(600,700, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, 0., -1, 1,0,0);
        txSleep(40);
    }
    y    =400;
    x    =900;
    phase=  0;
    dx   =- 1;
    head =  0;
    y1   =700;
    for(x1=0; x1<450; x1+=4)
    {
        x+=dx;
        y+=1;
        y1+=1;
        head-=0.01;
        phase+=1;
        phase%=12;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_gull(x, y, RGB(120, 120, 120), RGB(180,180,180), 0.6,  0 , 0 ,  30,  1, 1);
        draw_turtle1(600,y1, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, head, -1, 1,0,0);
        draw_Sam(x1,700,phase);
        txSleep(40);
    }
    for(x1=448; x1<555; x1+=4)
    {
        phase+=1;
        phase%=12;
        x+=dx;
        y+=1;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_gull(x, y, RGB(120, 120, 120), RGB(180,180,180), 0.6,  0 , 0 ,  30,  1, 1);
        draw_turtle1(600,812, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, head, -1, 1,0,0);
        draw_Sam(x1,707,phase);
        txSleep(40);
    }
    phase=0;
    for(n=0; n<12; n+=1)
    {
        phase+=1;
        phase%=12;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_gull(x, y, RGB(120, 120, 120), RGB(180,180,180), 0.6,  0 , 0 ,  30,  1, 1);
        draw_turtle1(600,812, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, head, -1, 1,0,0);
        draw_Sem(x1,707,phase);
        txSleep(100);
    }
    k1  =120;
    nose= 30;
    for(k=180; k<255; k+=1)
    {
        k1+=1;
        nose-=1;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        if (nose<0)
        {
            draw_gull(x, y, RGB(k1, 120, 120), RGB(k,180,180), 0.6,  0 , 0 , 0,  1, 1);
        }
        else
        {
            draw_gull(x, y, RGB(k1, 120, 120), RGB(k,180,180), 0.6,  0 , 0 , nose,  1, 1);
        }
        draw_turtle1(600,812, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, head, -1, 1,0,0);
        draw_Sem(x1,707,phase);
        txSleep(30);
    }
    dx  = -3;
    phase= 0;
    for(y; y>-100; y-=4)
    {
        phase+=1;
        phase%=12;
        x+=dx;
        x1-=1;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_gull(x, y, RGB(k1, 120, 120), RGB(k,180,180), 0.6,  0 , 0 ,  0,  1, 1);
        draw_turtle1(600,812, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, head, -1, 1,0,0);
        draw_Sam(x1,707,phase);
        txSleep(40);
    }
    for(smile=0;smile>-10.; smile-=0.1)
    {
        head+=0.01;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_turtle1(600,812, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.3, 0, head, -1, 1,0,0);
        draw_crab(x1, 707, RGB(150,13,6), RGB(110,16,11), RGB(92,9,5), 0.4,0, smile, 2., 1, 0);
        txSleep(20);
    }
    y1    =707;
    phase1=  0;
    for(y=812;y>400;y-=4)
    {
        phase1+=1;
        phase1%=8;
        y1-=4;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_Mark1(600,y,phase1);
        draw_crab(x1, y1+20, RGB(150,13,6), RGB(110,16,11), RGB(92,9,5), 0.4,0, smile, 2., 1, 0);
        txSleep(50);
    }
    phase1=0;
    for(y; y>200; y-=3)
    {
        phase1+=1;
        phase1%=8;
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_crab(x1, y1+20, RGB(150,13,6), RGB(110,16,11), RGB(92,9,5), 0.4,0, smile, 2., 1, 0);
        draw_Mark1(600,y,phase1);
        txSleep(50);
    }
    for(scale=0.3; scale>0.005; scale-=0.01)
    {
        txSetFillColor(colorfon);
        txClear();
        draw_dno1(600,600);
        draw_crab(x1, y1+20, RGB(150,13,6), RGB(110,16,11), RGB(92,9,5), 0.4,0, smile, 2., 1, 0);
        draw_turtle1(600,y, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), scale, 0, 0, -1, 1,0,0);
        txSleep(30);
    }
    txSetFillColor(colorfon);
    txClear();
    draw_dno1(600,600);
    draw_crab(x1, y1+20, RGB(150,13,6), RGB(110,16,11), RGB(92,9,5), 0.4,0, smile, 2., 1, 0);

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void draw_fourth_scene()
{
    COLORREF colorfon;
    colorfon=RGB(171,245,247);
    int x, xmax, dx, y, ymax, dy, x1, y1, d, y2, x2,y3, x3,kx, phase, phase1;
    xmax  =1250;
    dx    =  10;
    ymax  = 300;
    y     =   0;
    dy    =   4;
    x1    =1000;
    y1    = 650;
    d     =  -4;
    y2    = 300;
    x2    = 445;
    x3    = 700;
    y3    = 420;
    phase =   0;
    phase1=   0;
    for(x=-250; x<xmax; x+=dx)
    {
        txSetFillColor(colorfon);
        txClear();
        y+=dy;
        if(y<ymax)
        {
           phase+=1;
           phase%=8;
           draw_Mark2(245, y, phase);
           draw_dolphin(1000, 650, RGB(35,133,153 ), RGB(143,181,189), 0.6, 0, 0, -1, -1, 1.);
        }
        phase1+=1;
        phase1%=10;
        draw_fissy(x,150,phase1,1);
        draw_fissy(x,770,phase1,2);
        if(y>=ymax)
        {
           draw_turtle(445, ymax, RGB(131,161,22), RGB(4,77,16 ), RGB(232,196,77), 0.4, 0, 0., 1, -1);
           if(x1>700)
           {
                x1+=d;
                y1+=d+1;
                draw_dolphin(x1, y1, RGB(35,133,153 ), RGB(143,181,189), 0.6, 0, 0, -1, -1, 1.);
            }
            else
            {
                draw_dolphin(700, 420, RGB(35,133,153 ), RGB(143,181,189), 0.6, 0, 0, -1, -1, 1.);
            }
        }
        txSleep(40);
    }

    txSetColor(TX_WHITE,3);
    txSetFillColor(RGB(63, 135, 138));
    txCircle(560,300,8 );
    txSleep (440       );
    txCircle(610,260,10);
    txSleep (440       );
    txCircle(550,240,12);
    txSleep (640       );
    txSetColor  (colorfon,3);
    txSetFillColor(colorfon);
    txCircle(560,300,11);
    txSleep (440       );
    txCircle(610,260,13);
    txSleep (440       );
    txCircle(550,240,15);
    xmax=-100;
    dx  =- 10;
    for(x=1250; x>xmax; x+=dx)
    {
        txSetFillColor(colorfon);
        txClear();
        if(y2<1000)
        {
            x2+=-5;
            y2+= 5;
            x3+=-5;
            y3+= 5;
            draw_turtle (x2, y2, RGB(131,161,22),  RGB(4,77,16    ), RGB(232,196,77), 0.4, 0, 0., 1, -1);
            draw_dolphin(x3, y3, RGB(35,133,153 ), RGB(143,181,189),              0.6, 0, 0, -1, -1, 1.);
        }
        draw_Fish(x,150,1.7,RGB(186,186,56),RGB(125,42,19),5,1);
        txSleep(40);
    }
    for(y=1100; y>900; y+=-5)
    {
          txSetFillColor(colorfon);
          txClear();
          draw_dno(400,y);
          txSleep(40);
    }

    x1=0;
    kx=1250;
    for(x=0; x<600; x+=5)
    {
        x1+=12;
        kx+=-11;
        txSetFillColor(colorfon);
        txClear();
        draw_dno(400,900);
        draw_Fish(x1,200,1.7,RGB(186,148,255),RGB(102,102,255),5,-1);
        draw_Fish(x1,650,1.3,RGB(214,214,77 ),RGB(204,131,22 ),0,-1);
        draw_Fish(kx,370,1.6,RGB(52,56,87   ),RGB(374,81,152 ),0, 1);
        draw_Caterpillar(x,800,1.,RGB(153,255,102),RGB(255,255,102),2,-2,1 );
        txSleep(40);
    }
    txSleep(440);
    txSetColor(TX_WHITE,5);
    txSetFillColor(TX_WHITE);
    txEllipse (600, 650, 800, 750);
    POINT polygon[3]= {{630,720 },
                       {630,780 },
                       {660,720}};
    txPolygon (polygon,3);
    txSetColor(TX_BLACK,5);
    txSelectFont ("Comic Sans MS", 40, 15, true);
    txDrawText  (630, 670, 770, 720, "The end!");
    txSleep(1040);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


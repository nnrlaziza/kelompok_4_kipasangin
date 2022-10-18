// E1E121050 - ANNISA AZ'ZAHRA TARIMANA
// LINE 1 SAMPAI LINE 55

#include <windows.h>
#include <GL/glut.h>

    //buat 3 buah method
    void cylinder(float rbase,float rtop,float height);
    void blok(float tebal,int ratiol,int ratiop);
    void bilah (float r_inner,float r_outer,float tebal,int batang);

    //atur layar
    int screen_width=500;//mengatur lebar screen
    int screen_height=600;//mengatur tinggi screen
    //int button_up=0,button_down=0;
    int Turn=0;//mengatur gerakan pada kipas agar stabil

    //atur variabel awal untuk pergerakan
    double rotation_y=0,rotation_y_plus=-15,direction;// mengatur rotasi agar searah jarum jam
    double Rhead=0,Rheadplus=0;
    double rotate_All=0,All_plus=0;
    double Angguk=0,Anggukplus=0;
    double press=0,pressplus,pressplus1=180,pressplus2=0,pressplus3=0,pressplus4=0,pressplus5=0;

    bool Toleh=true,Tolehpress=true;
    bool RightTurn=true;
    bool speed1=true,speed2=false,speed3=false,speed4=false,speed5=true;

    //seting pencahayaan
    //GLfloat ambient_light[]={0.3,0.3,0.45,1.0};
    GLfloat ambient_light[]={0.0,0.0,0.45,1.0};//GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3
    //GLfloat  source_light[]={0.9,0.8,0.8,1.0};
    GLfloat  source_light[]={0.8,0.8,0.8,1.0};
    //GLfloat     light_pos[]={7.0,0.0,1.0,1.0};
    GLfloat     light_pos[]={5.0,0.0,6.0,1.0};

    void init(void)
    {

    glShadeModel(GL_SMOOTH);
    glViewport(0,0,screen_width,screen_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,1.0f,1000.0f);

    glEnable (GL_DEPTH_TEST);
    glPolygonMode   (GL_FRONT_AND_BACK,GL_FILL);
    glEnable (GL_LIGHTING); // pemanggilan parameter lihghting
    glLightModelfv  (GL_LIGHT_MODEL_AMBIENT,ambient_light);
    glLightfv (GL_LIGHT0,GL_DIFFUSE,source_light);
    glLightfv (GL_LIGHT0,GL_POSITION,light_pos);
    glEnable (GL_LIGHT0);
    glEnable (GL_COLOR_MATERIAL);
    glColorMaterial (GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
    }


//E1E121074 - MUHAMMAD AZRIEL SAKTIAWAN
// LINE 61 SAMPAI 109

//membuat method risize agar saat layar di maxzimize gambar mengikuti layar sehingga tidak merubah ukuran dari kipasnya
    void resize(int width,int height)
    {
    screen_width=width;
    screen_height=height;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,screen_width,screen_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,1.0f,1000.0f);

    glutPostRedisplay();
    }

    //buat method display(method penampilan gambar
    void display(void)
    {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //membersihkan layar latar belakang
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0,-15,-70);
    glPushMatrix();
    glRotatef(270,1.0,0.0,0.0);
    rotate_All+=All_plus;
    glRotatef(rotate_All,0.0,0.0,1.0);
    cylinder(2.5,1.5,16); // cilinder btang bawah2
    cylinder(2.5,2.5,6); // cilinder batang bawah1
   glPushMatrix();
   glTranslatef(0.0,0.0,14);
    glRotatef(90,0.0,1.0,0.0);
    Angguk+=Anggukplus; // page up page down
    glRotatef(Angguk,0.0,0.0,1.0);
        Anggukplus=0;
     glPushMatrix();
     glRotatef(270,0.0,1.0,0.0);
     glTranslatef(0.0,0.0,1);
     cylinder(0.5,1,4);// cilinder batang atas
     glPopMatrix();
    glutSolidTorus(1.5,2,6,16);
    glTranslatef(0.0,0.0,-2);
    cylinder(1,1,4.3);//silinder penghubung batang atas dan batang bawah
    glTranslatef(0.0,0.0,2);
    glRotatef(270,0.0,1.0,0.0);
         glPushMatrix();
         glTranslatef(0.0,0.0,10);
         glRotatef(90,1.0,0.0,0.0);
     //turn left-right for fan head  10/9/2003
    

//lukman awal
//E1E121004 LA ODE LUKMANA
    // definisikan kondisi pergerakan penolehan
     if ( Toleh==true)
     {
     if(Turn >= 60)      // max degrees right
        RightTurn =false;
     if(Turn <=-60)  // max degrees left
        RightTurn =true;
     if(RightTurn == true )
     {
     Rheadplus++;
     Turn++;
     }
     else
     {
     Rheadplus--;
     Turn--;
     }
     }
     Rhead=Rhead+Rheadplus;
     glRotatef(Rhead,0.0,1.0,0.0);
     Rheadplus=0;
     // end turn left-right for fan head

     glTranslatef(0.0,0.0,-3.0);
     cylinder(4,4,6);// silinder belakang kipas
     cylinder(1,0.5,15);//silinder tonjolan di depan kipas
     glRotatef(270,1.0,0.0,0.0);
     if(Tolehpress==true)  // press down turn left-right head button
     cylinder(0.3,0.5,6);
     else // pull up turn left-right head button
     cylinder(0.3,0.5,7);
     glRotatef(90,1.0,0.0,0.0);
         glPushMatrix();
       glTranslatef(0.0,0.0,11);
       glutWireTorus(5,7,10,64);
       glutSolidTorus(0.5,12,10,64);
       rotation_y+=rotation_y_plus;
       if(rotation_y>359)rotation_y=0;
       glRotatef(rotation_y,0.0,0.0,1.0);
       bilah(3,10,3,5); // bilah(inner radius, outer radius, thickness, qty bilah)
         glPopMatrix();
       glPopMatrix();
     glPopMatrix();
     glRotatef(90,1.0,0.0,0.0);
     glTranslatef(0.0,-1.0,-4);
     blok(2,7,10);// blok bawah(papan kontrol)


//lukman akhir



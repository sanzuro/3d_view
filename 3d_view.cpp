
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>


  union REGS i , o ;

   class vector
   {   public :
       vector ( float  a , float  b , float c )
       {
	   x = a ;
	   y = b ;
	   z = c ;
       }
       float x , y, z , _screen_x , _screen_y ;

   }
    view ( -10,0,1000) , track ( 0,1,0) ;

		void locate (vector & );
  void track_calc ( void );
  float mod ( vector ) ;
   vector minus ( vector , vector );

  vector unit ( vector );
  float  vec_cos ( vector , vector );

//showingvectors on the graph

   vector first ( 100,100,100 );
   vector second (100,100 ,200 );
   vector third ( 200,100 ,100 );
   vector eigth ( 200,100 ,200 );
   vector forth ( 100,200 ,100 );
   vector fifth ( 100,200,200 );
   vector sixth ( 200,200,100 );
   vector seventh (200,200,200 );


  void main ()
  {
      int86  ( 0x33 , &i , &o );
      i.x.ax = 3 ;


      int gm = 0 , gd = 0 ;
      initgraph ( &gm ,&gd , "C:\\TURBOC3\\BGI");

      float midx = 0;
      float midy = getmaxy()/2 ;


      while (!kbhit())
      {
	 int86 ( 0x33, &i , &o );
	 view.x =  o.x.cx*0.5 ;
	 view.y =  o.x.dx*0.5 ;
	 track_calc ();
	 locate( first );
      locate ( second );
	 locate ( third );
    locate ( forth );
   locate  (fifth );
     locate (sixth );
     locate  (seventh);
	 locate  (eigth );

		 line (midx + first._screen_x ,    midy - first._screen_y ,     midx +second._screen_x , midy -second._screen_y );
		line (midx + first._screen_x ,   midy -first. _screen_y ,    midx + third._screen_x, midy -third._screen_y );
	      line (midx + third._screen_x ,    midy - third._screen_y,      midx + eigth._screen_x , midy -eigth._screen_y  );
	      line (midx + eigth._screen_x ,     midy - eigth._screen_y ,     midx + second._screen_x , midy - second._screen_y);


	      line (midx + forth._screen_x ,      midy - forth._screen_y ,     midx + sixth._screen_x, midy -sixth._screen_y  );
  	     // line (midx + fifth._screen_x ,     midy - fifth._screen_y ,      midx + sixth._screen_x , midy - sixth._screen_y);
	    line (midx +fifth._screen_x ,      midy -fifth._screen_y ,      midx + seventh._screen_x, midy -seventh._screen_y);
	      line(midx +seventh._screen_x ,midy-seventh._screen_y,midx+sixth._screen_x,midy-sixth._screen_y);
	      line (midx +fifth._screen_x ,    midy -fifth._screen_y ,    midx + forth._screen_x, midy -forth._screen_y );
	      line ( midx + first._screen_x  ,   midy - first._screen_y ,     midx + forth._screen_x, midy - forth._screen_y );
	      line ( midx + second._screen_x ,   midy - second._screen_y ,    midx + fifth._screen_x , midy - fifth._screen_y );
	      line ( midx + third._screen_x ,   midy - third._screen_y ,      midx + sixth._screen_x , midy - sixth._screen_y);
	      line ( midx + eigth._screen_x ,    midy - eigth ._screen_y ,    midx + seventh._screen_x , midy - seventh._screen_y );


	    delay (50);
	 cleardevice();

      }

  }
  void track_calc ( void )
  { 

     float thita = acos (view.x  / mod (  view   )) ;
     track.x = - cos  ( thita );
     track.y = sin ( thita );

  }

  float mod ( vector a )
  {
      return pow (a.x * a.x + a.y * a.y + a.z * a.z ,0.5);
  }


   void locate  (   vector &  a )
  {
    
      vector _unit = unit (  minus (view , a) );
      float lembda = vec_cos ( _unit , a );
      vector temp (0,0,0) ;
      temp.x = a.x - lembda * _unit.x;
      temp.y = a.y - lembda * _unit.y;
      temp.z = a.z - lembda * _unit.z;

      float mag = mod (temp)  ;

      float thita = acos ( vec_cos ( temp , track) / mag );

      a._screen_x = mag  * sin (thita) ;
      a._screen_y = mag   * cos (thita) ;
      }
 
  vector unit (  vector  a )
  {
     vector temp (0,0,0) ;
      float k = mod ( a );
      temp.x = a.x / k ;
      temp.y = a.y / k ;
      temp.z = a.z / k ;
      return temp;
  }
  
  float vec_cos ( vector a , vector b )
  {
      return a.x * b.x + a.y * b.y + a.z * b.z ;
  }
  vector minus ( vector a , vector b )
  {
      vector temp (0,0,0);
      temp.x = a.x - b.x ;
      temp.y = a.y - b.y ;
      temp.z = a.z - b.x ;
      return temp;
  }

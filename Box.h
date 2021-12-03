



#ifndef BOX_H
#define BOX_H

class Box
{

   public:

      Box(int l, int r, int t, int b);
      
      Box ();

      ~Box();

      int l();

      int r();

      int t();

      int b();

      void l(int l);

      void r(int r);

      void t(int t);

      void b(int b);


   private:

    int left;

    int right;

    int top;

    int bottom;

      

};
 
#endif


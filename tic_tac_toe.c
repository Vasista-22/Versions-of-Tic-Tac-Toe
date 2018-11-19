/*this is a tic tac toe game*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int level;

display(char a[10])
 {
  
  int i;

   printf("\n\n\n\n\n\n\n\n                           ");

  for(i=1;i<=9;i++)
   {

    printf("%c ",a[i]);

    if(i%3==0)
     {
      printf("\n                           ");
     }

   }

    printf("\n\n                           ");
    
 }


////////////////////////////////////////////////////////////////////


key()
 {
  
  int i; 
 
  for(i=1;i<=9;i++)
   {

    printf("%d ",i);

    if(i%3==0)
     {
      printf("\n                           ");
     }

   }

    printf("\n           enter the value of the place where you wish to enter : ");
      
 } 


///////////////////////////////////////////////////////////////////


int check(char a[10])
 {
  
  int i,chk=0;

  for(i=1;i<=9;i++)
   {
    
    if(a[i]=='_')
     {
      chk=1;
      break;
     }
   }

  return chk;
 }
  

//////////////////////////////////////////////////////////////////


int check_free(char a[10],int n)
 {
  
  if((n>0)&&(n<10))
   {
        
    if(a[n]=='_')  
      return 1;

    else 
      return 0;

   }
  
  else
    return 2;
 }
      


//////////////////////////////////////////////////////////////////


int play2(char a[10],char c)
 {
  
  int ent;
  //time_t t;
 
//  srand((unsigned)time(0));

  ent=random()%10;

  //ent=rand()%10;

  if(ent==0)
   ent++;

  if(a[ent]=='_')
   a[ent]=c;

  else 
     play2(a,c);

  return ent;

 }



//////////////////////////////////////////////////////////////////



int game(char a[10],char y,char c)
 {
   
  int result=2,i,j;

  for(i=1,j=1;i<=3;i++,j+=3)
   {
   
    if((a[i]==y)&&(a[i+3]==y)&&(a[i+6]==y))
     {
      result=1;
      break;
     }  

    else if((a[i]==c)&&(a[i+3]==c)&&(a[i+6]==c))
     {
      result=0;
      break;
     }

    else if((a[j]==y)&&(a[j+1]==y)&&(a[j+2]==y))
     {
      result=1;
      break;
     }
  
    else if((a[j]==c)&&(a[j+1]==c)&&(a[j+2]==c))
     {
      result=0;
      break;
     }
  
   }

  
   if((a[1]==y)&&(a[5]==y)&&(a[9]==y))
    result=1;

   else if((a[1]==c)&&(a[5]==c)&&(a[9]==c))
    result=0;

   if((a[3]==y)&&(a[5]==y)&&(a[7]==y))
    result=1;

   else if((a[3]==c)&&(a[5]==c)&&(a[7]==c))
    result=0; 

  
  return result; 
 

 }



////////////////////////////////////////////////////////////////////



char choose()
 {

  char y,num=0;

  printf("\n\n                Choose your entry x or o : ");

  scanf("%c",&y);

  if((y=='x')||(y=='o')||(y=='X')||(y=='O'))
   {
    num=1;
   }

  if(num==0)
   {
    system("clear");
    
    printf("\nsorry wrong input. please enter again\n");

    y=choose();
   }

 return y;

 }



///////////////////////////////////////////////////////////////////////


int think(char a[10],char y,char c,int d[])
{
 
  int result=0,i,j;

  for(i=1,j=1;i<=3;i++,j+=3)
   {

    if(((a[i]==c)&&(a[i+3]==c)&&(a[i+6]=='_'))||((a[i]==c)&&(a[i+3]=='_')&&(a[i+6]==c))||((a[i]=='_')&&(a[i+3]==c)&&(a[i+6]==c)))
     {
      if(a[i]=='_')
       {
        a[i]=c;
        if(level==2)
         put(d,i);
       }

      else if(a[i+3]=='_')
       {
        a[i+3]=c;
        if(level==2)
         put(d,i+3);
       }

      else if(a[i+6]=='_')
       {
        a[i+6]=c;
        if(level==2)
         put(d,i+6);
       }

     if(level==2 && is_full(d))
       a[give(d)]='_';

      result=1;

      break;
     }



    else if(((a[j]==c)&&(a[j+1]==c)&&(a[j+2]=='_'))||((a[j]==c)&&(a[j+1]=='_')&&(a[j+2]==c))||((a[j]=='_')&&(a[j+1]==c)&&(a[j+2]==c)))
     {
      if(a[j]=='_')
       {
        a[j]=c;
        if(level==2)
         put(d,j);
       }

      else if(a[j+1]=='_')
       {
        a[j+1]=c;
        if(level==2)
         put(d,j+1);
       }

      else if(a[j+2]=='_')
       {
        a[j+2]=c;
        if(level==2)
         put(d,j+2);
       }

     if(level==2 && is_full(d))
       a[give(d)]='_';

       result=1;

      break;
     }


   }


 if(result==0)
  {
 
   if(((a[1]==c)&&(a[5]==c)&&(a[9]=='_'))||((a[1]==c)&&(a[5]=='_')&&(a[9]==c))||((a[1]=='_')&&(a[5]==c)&&(a[9]==c)))
    {
     if(a[1]=='_')
      {
       a[1]=c;
        if(level==2)
         put(d,1);
      }
     
     else if(a[5]=='_')
      {
       a[5]=c;
        if(level==2)
         put(d,5);
      }

     else if(a[9]=='_')
      {
       a[9]=c;
        if(level==2)
         put(d,9);
      }

     if(level==2 && is_full(d))
       a[give(d)]='_';
   
     result=1;
    }


   else if(((a[3]==c)&&(a[5]==c)&&(a[7]=='_'))||((a[3]==c)&&(a[5]=='_')&&(a[7]==c))||((a[3]=='_')&&(a[5]==c)&&(a[7]==c)))
    {
     if(a[3]=='_')
      {
       a[3]=c;
        if(level==2)
         put(d,3);
      }

     else if(a[5]=='_')
      {
       a[5]=c;
        if(level==2)
         put(d,5);
      }

     else if(a[7]=='_')
      {
       a[7]=c;
        if(level==2)
         put(d,7);
      }

     if(level==2 && is_full(d))
       a[give(d)]='_';

     result=1;
    }

  }

  if(result==0)
   { 
    for(i=1,j=1;i<=3;i++,j+=3)
     {
      if(((a[i]==y)&&(a[i+3]==y)&&(a[i+6]=='_'))||((a[i]==y)&&(a[i+3]=='_')&&(a[i+6]==y))||((a[i]=='_')&&(a[i+3]==y)&&(a[i+6]==y)))
     {
      if(a[i]=='_')
       {
        a[i]=c;
        if(level==2)
         put(d,i);
       }

      else if(a[i+3]=='_')
       {
        a[i+3]=c;
        if(level==2)
         put(d,i+3);
       }

      else if(a[i+6]=='_')
       {
        a[i+6]=c;
        if(level==2)
         put(d,i+6);
       }

     if(level==2 && is_full(d))
       a[give(d)]='_';

      result=1;

      break;
     }



   else if(((a[j]==y)&&(a[j+1]==y)&&(a[j+2]=='_'))||((a[j]==y)&&(a[j+1]=='_')&&(a[j+2]==y))||((a[j]=='_')&&(a[j+1]==y)&&(a[j+2]==y)))
     {
      if(a[j]=='_')
       {
        a[j]=c;
        if(level==2)
         put(d,j);
       }

      else if(a[j+1]=='_')
       {
        a[j+1]=c;
        if(level==2)
         put(d,j+1);
       }

      else if(a[j+2]=='_')
       {
        a[j+2]=c;
        if(level==2)
         put(d,j+2);
       }

     if(level==2 && is_full(d))
       a[give(d)]='_';

        result=1;

       break;
     }

    }

  }  

  if(result==0)
   {

    if(((a[1]==y)&&(a[5]==y)&&(a[9]=='_'))||((a[1]==y)&&(a[5]=='_')&&(a[9]==y))||((a[1]=='_')&&(a[5]==y)&&(a[9]==y)))
    {
     if(a[1]=='_')
      {
       a[1]=c;
        if(level==2)
         put(d,1);
      }

     else if(a[5]=='_')
      {
       a[5]=c;
        if(level==2)
         put(d,5);
      }

     else if(a[9]=='_')
      {
       a[9]=c;
        if(level==2)
         put(d,9);
      }

     if(level==2 && is_full(d))
       a[give(d)]='_';

     result=1;
    }


   else if(((a[3]==y)&&(a[5]==y)&&(a[7]=='_'))||((a[3]==y)&&(a[5]=='_')&&(a[7]==y))||((a[3]=='_')&&(a[5]==y)&&(a[7]==y)))
    {
     if(a[3]=='_')
      {
       a[3]=c;
        if(level==2)
         put(d,3);
      }
 
     else if(a[5]=='_')
      {
       a[5]=c;
        if(level==2)
         put(d,5);
      }

     else if(a[7]=='_')
      {
       a[7]=c;
        if(level==2)
         put(d,7);
      }

     if(level==2 && is_full(d))
       a[give(d)]='_';

     result=1;
    }

  }

  /*if(result==0)
   play2(a,c);*/

  return result;

}


///////////////////////////////////////////////////////////////////////


centre(char a[10],char y,char c,int d[])
{

  int r,k=0,chec=1,result=2,i,t_result,chk;
  
  time_t t;
 
  srand((unsigned)time(&t));  

 do
  {
 //  r=random()%10;

     r=rand()%10;

   if((r%2==1)&&(r!=5))
    {
     a[r]=c;
    
     if(level==2)
      put(d,r);
   
     k=1;
    }

  }while(k==0);


 for( ;chec==1 && result==2; )
  {

   if(level==2 && is_full(d))
    {
     a[give(d)]='_';
    }

   system("clear");
   display(a);
   key();
 
   scanf("%d",&i);

   chk=check_free(a,i);

  if(chk==1)
   {
    a[i]=y;
   
    if(level==2)
     {
      put(d,i);

      if(is_full(d))
       a[give(d)]='_';

     }
     
    result=game(a,y,c);
    chec=check(a);
   
   if(result==1)
    {
     system("clear");

     display(a);

     printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");

     break;
    }

   else if(result==0)
    {
     system("clear");

     display(a);

     printf("\n\n             BETTER LUCK NEXT TIME");

     break;
    }
     
   else if(chec==1)
    {
     t_result=think(a,y,c,d);
 
     if(t_result==0)
      {
       if(a[1]=='_' || a[3]=='_' || a[7]=='_' || a[9]=='_')
        {
         k=0;

         do
          {
         //  r=random()%10;
             r=rand()%10;
         
           if(r%2==1 && r!=5)
            {
             if(a[r]=='_')
              {
               a[r]=c;
               
               if(level==2)
                {
                 put(d,r);

                 if(is_full(d))
                  a[give(d)]='_';
                }
               
               k=1;
              }
            }
          }while(k==0);
            
        }

       else
        { 
         if(level==2)
          {
           put(d,play2(a,c));
   
           if(is_full(d))
           a[give(d)]='_';
          }

         else
           play2(a,c);
        }
       
      }
     
     result=game(a,y,c);
 
    if(result==1)
     {
      system("clear");
 
      display(a);
 
      printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");
 
      break;
     }

    else if(result==0)
     {
      system("clear");
 
      display(a);
  
      printf("\n\n             BETTER LUCK NEXT TIME");
 
      break;
     }

    }

   }
  
  else
     printf("\n\n sorry invalid input\n\n");

   
   chec=check(a);

  }


  if(result==2)
   {
    system("clear");

    display(a);

    printf("\n\n               MATCH DRAWN");
   }
  


} 



//////////////////////////////////////////////////////////////////////



diagonal(char a[10],char y,char c,int num,int start,int d[])
{

 int chec=1,result=2,chk,i,t_result,r,k=0,b[4],moves=3;

 time_t t;

 srand((unsigned)time(&t));

 b[0]=2;b[1]=4;b[2]=6;b[3]=8;


 if(a[5]=='_')
  {
   a[5]=c;
  
   if(level==2)
    put(d,5);
  }

 else
  {
   do
    {
    // r=random()%10;

      r=rand()%10;

     if((r%2==1)&&(r!=5))
      {
       a[r]=c;
      
       if(level==2)
        put(d,5); 
 
       k=1;
      }

    }while(k==0);
  }

 if(start==2)
  moves++;  


 for( ;chec==1 && result==2;moves++)
  {
      
   if(level==2 && is_full(d))
    a[give(d)]='_';  

   system("clear");
   display(a);
   key();

   scanf("%d",&i);

   chk=check_free(a,i);

  if(chk==1)
   {

     a[i]=y;

     if(level==2)
      {
       put(d,i);

       if(is_full(d))
        a[give(d)]='_';
      }

    result=game(a,y,c);
    chec=check(a);

   if(result==1)
    {
     system("clear");

     display(a);

     printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");

     break;
    }

   else if(result==0)
    {
     system("clear");

     display(a);

     printf("\n\n             BETTER LUCK NEXT TIME");

     break;
    }

   else if(chec==1)
    {
     t_result=think(a,y,c,d);

     if(t_result==0)
      {

       if(i%2==1)
        {
         k=0;
        
         while(k==0)
          {
           r=random()%4;
    
           if(a[b[r]]=='_')
            {
             a[b[r]]=c;

             if(level==2)
              {
               put(d,b[r]);

               if(is_full(d))
                a[give(d)]='_';
              }
             k=1;
            }
          }
        }

       else if((i%2==0)&&(moves<=4))
        {

         if((num==3 || num==7)&&(i<=4))
          {
           a[1]=c;
             if(level==2)
              {
               put(d,1);

               if(is_full(d))
                a[give(d)]='_';
              }
          }

         else if((num==3 || num==7)&&(i<=8))
          {
           a[9]=c;
             if(level==2)
              {
               put(d,9);
 
               if(is_full(d))
                a[give(d)]='_';
              }
          }

         else if((num==1 || num==9)&&(i<=6))
          {
           a[3]=c;
             if(level==2)
              {
               put(d,3);

               if(is_full(d))
                a[give(d)]='_';
              }
          }
                    
         else if((num==1 || num==9)&&(i<=8))
          { 
           a[7]=c;
             if(level==2)
              {
               put(d,7);

               if(is_full(d))
                a[give(d)]='_';
              }
          }

        }

       else
        {
         if(level==2)
          {
           put(d,play2(a,c));

           if(is_full(d))
           a[give(d)]='_';
          }

         else
           play2(a,c);
        }

      }

     result=game(a,y,c);

    if(result==1)
     {
      system("clear");

      display(a);

      printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");

      break;
     }

    else if(result==0)
     {
      system("clear");

      display(a);

      printf("\n\n             BETTER LUCK NEXT TIME");

      break;
     }

    }

   }

  else
     printf("\n\n sorry invalid input\n\n");


   chec=check(a);

  }


  if(result==2)
   {
    system("clear");

    display(a);

    printf("\n\n               MATCH DRAWN");
   }

} 


//////////////////////////////////////////////////////////////////////


middle(char a[10],char y,char c,int num,int start,int d[])
{

 int chec=1,result=2,k=0,i,r,t_result,chk,moves=3;

 time_t t;

 srand((unsigned)time(&t));

 if(a[5]=='_') 
  {
   a[5]=c;
  
   if(level==2)
    put(d,5);
  }

 else
  {
   do
    {
     //r=random()%10;
       r=rand()%10;

     if((r%2==1)&&(r!=5))
      {
       a[r]=c;

       if(level==2)
        put(d,r);

       k=1;
      }

    }while(k==0);
  }


 if(start==2)
  moves++;


 for( ;chec==1 && result==2;moves++)
  {
   
   if(level==2 && is_full(d))
    {
     a[give(d)]='_';
    }

   system("clear");
   display(a);
   key();

   scanf("%d",&i);

   chk=check_free(a,i);

  if(chk==1)
   {
    
     a[i]=y;

     if(level==2)
      {
       put(d,i);
    
       if(is_full(d))
        a[give(d)]='_';
      }

    result=game(a,y,c);
    chec=check(a);
   
   if(result==1)
    {
     system("clear");

     display(a);

     printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");

     break;
    }

   else if(result==0)
    {
     system("clear");

     display(a);

     printf("\n\n             BETTER LUCK NEXT TIME");

     break;
    }

   else if(chec==1)
    {
     t_result=think(a,y,c,d);

     if(t_result==0)
      {
        
       if((num==2 || num==4 || num==6)&&(i==2 || i==4 || i==6)&&(moves<=4))
        {
       //  r=random()%2;
           r=rand()%2;

         if(r==0)
          {
           a[1]=c;
         
           if(level==2)
            put(d,1);
          }            

         else if(r==1)
          {
           a[3]=c;
          
           if(level==2)
            put(d,3);
          }
        }

       else if((num==4 || num==6 || num==8)&&(i==4 || i==6 || i==8)&&(moves<=4))
        {
        // r=random()%2;
           r=rand()%2;

         if(r==0)
          {
           a[7]=c;

           if(level==2)
            put(d,7);
          }

         else if(r==1)
          {
           a[9]=c;

           if(level==2)
            put(d,9);
          }

        }
 
       else if(num==2 && i==8 && moves<=4)
        {

          k=0;

         do
          {
          // r=random()%10;
             r=rand()%2;
        
           if((r%2==1) && (r!=5))
            {
             if(a[r]=='_')
              {
               a[r]=c;
                
               if(level==2)
                put(d,r);    

               k=1;
              }
            }
          }while(k==0);
        }

       else if((i%2==1)&&(moves<=4))
        {
         if((num==2 || num==4)&&(i==3 || i==7))
          {
            a[1]=c;
 
            if(level==2)
             put(d,1);
          }

         else if((num==2 || num==6)&&(i==1 || i==9))
          {
            a[3]=c;
  
            if(level==2)
             put(d,3);
          }
 
         else if((num==6 || num==8)&&(i==3 || i==7))
          {
            a[9]=c;
 
            if(level==2)
             put(d,9);
          }   

         else if((num==4 || num==8)&&(i==1 ||i==9))
          {
            a[7]=c;

            if(level==2)
             put(d,7);
          }
        }


       else
        {
         if(level==2)
          {
           put(d,play2(a,c));

           if(is_full(d))
           a[give(d)]='_';
          }

         else
           play2(a,c);
        }

      }

     result=game(a,y,c);

    if(result==1)
     {
      system("clear");

      display(a);

      printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");

      break;
     }

    else if(result==0)
     {
      system("clear");

      display(a);

      printf("\n\n             BETTER LUCK NEXT TIME");

      break;
     }
           
    }

   }

  else
     printf("\n\n sorry invalid input\n\n");


   chec=check(a);

  }


  if(result==2)
   {
    system("clear");

    display(a);

    printf("\n\n               MATCH DRAWN");
   }

}
         

//////////////////////////////////////////////////////////////////////


int is_full(int d[])
{
 int i=0;

 while(d[i]!=0 && i<7)
  i++;

 if(i<7)
  return 0;

 else
  return 1;
}
        

//////////////////////////////////////////////////////////////////////


int give(int d[])
{
 int i,ret;

 ret=d[0];

 for(i=1;i<7;i++)
  d[i-1]=d[i];

 d[6]=0;

 return ret;
}


//////////////////////////////////////////////////////////////////////


put(int d[],int r)
{
 int i;

 for(i=0;i<=6;i++)
  {
   if(d[i]==0)
    {
     d[i]=r;
     break;
    }
  }

} 
     
//////////////////////////////////////////////////////////////////////



main()
{
char a[10];
int d[7];
char y,c;
int i;
int chec=1;
int chk;
int result;
int t_result;
int start;
int mode;
int flag;
char name[100];

time_t start_t,end_t;
double diff_t; 

 system("clear");
 
 printf("\n\n\n\n\n\n        PLAYER NAME PLEASE\n\n          ");

 gets(name);

 system("clear");

 printf("\n\n\n\n\n\n                         TIC TAC TOE");

 y=choose();

  if(y=='x')
        c='o';

  else if(y=='o')
        c='x';

  else if(y=='X')
        c='O';

  else if(y=='O')
        c='X';    



 for(i=1;i<=9;i++)
  {
   a[i]='_';
  }


 for(i=0;i<7;i++)
  {
   d[i]=0;
  }

      /////////////////////////////

 flag=0;

 do
  {
   system("clear");

   printf("\n\n\n         WHICH LEVEL YOU WISH TO PLAY?\n\n          1.CLASSICAL\n          2.TRICKY (here after every 6 moves the first move disappears)\n\n            choice =  ");

   scanf("%d",&level);

   if(level==1 || level==2 )
    flag=1;

  }while(flag==0);


      ////////////////////////////

      /////////////////////////////  
   
 flag=0;

 do
  {
   system("clear");

   printf("\n\n\n         WHICH MODE YOU WISH TO PLAY?\n\n          1.EASY\n          2.MEDIUM\n          3.DIFFICULT\n\n            choice =  ");

   scanf("%d",&mode);
 
   if(mode==1 || mode==2 || mode==3)
    flag=1;

  }while(flag==0);


      ////////////////////////////
 
   flag=0;

 do
  {
   system("clear");
 
   printf("\n\n\n\n\n           1.YOU START THE GAME   2.COMPUTER STARTS THE GAME\n\n\n              ENTER YOUR CHOICE : ");

   scanf("%d",&start);
 
   if(start==1 || start==2)
    flag=1;

  }while(flag==0);

  
     //////////////////////////////
  
    time(&start_t);
 
    //////////////////////////////

if(mode==1)
 {

  if(start==2)
   {
    if(level==2)
     put(d,play2(a,c));

    else
     play2(a,c);
   }

  result=game(a,y,c);

  chec=check(a);

 for( ;(result==2)&&(chec==1); )
  {

   if(level==2 && is_full(d))
    a[give(d)]='_';

   system("clear");

   display(a);

   key();

   scanf("%d",&i);

   chk=check_free(a,i);


   if(chk==1)
    {
     a[i]=y;

     if(level==2)
      {
       put(d,i);
      
       if(is_full(d))
        a[give(d)]='_';
      }
    }

   else
    {
     printf("\n\nsorry wrong input.please enter again\n\n");
     continue;
    }

   result=game(a,y,c);

   if(result==1)
    {
     system("clear");

     display(a);

     printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");

     break;
    }


   chec=check(a);

  if(chec==1)
   {
    if(level==2)   
      put(d,play2(a,c));

    else
      play2(a,c);
   }


   result=game(a,y,c);
   
   if(result==0)
    {
     system("clear");

     display(a);

     printf("\n\n             BETTER LUCK NEXT TIME");

     break;
    }


   chec=check(a);


  }


  if(result==2)
   {
    system("clear");

    display(a);

    printf("\n\n               MATCH DRAWN");
   }

}

///////////////////////////////////////////////////////////

else if(mode==2)
 {

  if(start==2)
   {
    if(level==2) 
     put(d,play2(a,c));

    else
      play2(a,c);
   }

  result=game(a,y,c);

  chec=check(a);
  
 for( ;(result==2)&&(chec==1); )
  {
 
   if(is_full(d) && level==2)
    a[give(d)]='_';
   
   system("clear");
    
   display(a);

   key();
 
   scanf("%d",&i);

   chk=check_free(a,i);  
  
   
   if(chk==1)
    {
     a[i]=y;

     if(level==2)
      {
       put(d,i);
       
       if(is_full(d))
        a[give(d)]='_';  
      }
    }

   else
    { 
     printf("\n\nsorry wrong input.please enter again\n\n");
     continue;
    }
 
 
   result=game(a,y,c);

   if(result==1)
    {
     system("clear");

     display(a);

     printf("\n\n          :) :) :) CONGRATULATIONS!!!  YOU WIN  ;) ;) ;)");

     break;
    }


   chec=check(a);

  if(chec==1)
   {
    t_result=think(a,y,c,d);

     if(t_result==0)
      {
       if(level==2)
        put(d,play2(a,c));
 
       else
         play2(a,c);
      }
   }


   result=game(a,y,c);

   if(result==0)
    {
     system("clear");

     display(a);

     printf("\n\n             BETTER LUCK NEXT TIME");

     break;
    }


   chec=check(a);

    
  }

  
  if(result==2)
   {
    system("clear");

    display(a);

    printf("\n\n               MATCH DRAWN");
   }

}


////////////////////////////////////////////////////////////////////


else if(mode==3)
 {
  int opt=0;

  if(start==2)
   {
    if(level==2)
     put(d,play2(a,c));
 
    else
     play2(a,c); 
   }


  while(opt==0)
   {
    system("clear");

    display(a);

    if(opt!=0)
     printf("sorry your choice was wrong\n\n");

    key();

    scanf("%d",&i);

    if((i==5)&&(a[i]=='_'))
     {
      a[i]=y;
      if(level==2)
       put(d,i);
      centre(a,y,c,d);
      opt=1;
     }

    else if((i%2==0)&&(a[i]=='_'))
     {
      a[i]=y;
      if(level==2)
       put(d,i);
      middle(a,y,c,i,start,d);
      opt=1;
     }

    else if((i==1 || i==3 || i==7 || i==9)&&(a[i]=='_'))
     {
      a[i]=y;
      if(level==2)
       put(d,i);
      diagonal(a,y,c,i,start,d);
      opt=1;
     }

   }


 }


////////////////////////////////////////////////////////////////

 
 time(&end_t);

 diff_t=difftime(end_t,start_t);
 
  if(diff_t>=60)
   {
    diff_t/=60;

    printf("\n\n dear ");  

    puts(name);

    printf("                your playtime was  %lf minutes",diff_t);
   }

  else
   {
    printf("\n\n dear  ");

    puts(name);

    printf("                your playtime was  %lf seconds",diff_t);
   }
   
}


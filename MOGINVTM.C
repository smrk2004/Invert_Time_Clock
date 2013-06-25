
#include<string.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include  <time.h>

char sub1(char c);         //10-//sub-fn
char sub3(char c);         //04-//sub-fn
char sub4(char c);         //14-//sub-fn
char sub5(char c);         //0-2//sub-fn
char sub6(char c);         //1=9//0=8//conv
char sub7(char c);         //0-1//sub-fn
char sub2(char c,char d);  //06-//sub-fn

void main()
{
   time_t t;
   int i;
   char s[35];
   clrscr();

   time(&t);
   strcpy(s,ctime(&t));
//*//
   printf("\nSTD Time:\n\n");
   printf("%s\n",ctime(&t));
//*/

   //TEST Input Section

/*//
   s[11]='2';   s[12]='3';   s[14]='1';   s[15]='0';   s[17]='3';   s[18]='5';

   printf("\nOld:\n");
   printf("%c\t",s[11]);
   printf("%c:\t",s[12]);
   printf("%c\t",s[14]);
   printf("%c:\t",s[15]);
   printf("%c\t",s[17]);
   printf("%c\n",s[18]);
//*/

   //ascii()//0=48:1=49:2=50:3=51:4=52:5=53:6=54:7=55:8=56:9=57

   //Extra Space Intro
   for(i=27;i>=22;i--)
   {
   s[i]=s[i-2];
   s[26]=s[24];
   }

   //Space intro btw am/pm field and yr field
   for(i=27;i>=21;i--)
   {
   s[i]=s[i-1];
   s[21]=' ';
   }

   //default definition as AM
   s[20]='A';
   s[21]='M';

   //---------------------CONVERSION---------------------------
   //conversion of hours field to invert time
   //PM conversion
   if(s[11]==49&&s[12]>=50)
   s[20]='P';
   else if(s[11]==50)
   s[20]='P';


   //Hours conversion//without edge value tapering

   if(s[11]==48&&s[12]<=52)
   {
   s[11]='2';
   s[12]=sub3(s[12]);
   }
   else if(s[11]==48&&s[12]>52&&s[12]<=57)
   {
   s[11]='1';
   s[12]=sub4(s[12]);
   }
   else if(s[11]==49&&s[12]<=52)
   {
   s[12]=sub3(s[12]);
   }
   else if(s[11]==49&&s[12]>52&&s[12]<=57)
   {
   s[11]='0';
   s[12]=sub4(s[12]);
   }
   else if(s[11]==50&&s[12]<=52)
   {
   s[11]='0';
   s[12]=sub3(s[12]);
   }

//*//

   //12 format conversion//without edge value tapering
   //case xx:00:00
   if(s[11]==50&&s[12]==52)
   {
   s[11]='1';
   s[12]='2';
   }
   else if(s[11]==50&&s[12]>=50)
   {

   s[11]='1';
   s[12]=sub5(s[12]);
   }
   else if(s[11]==50&&s[12]>=48&&s[12]<50)
   {
   s[11]='0';
   s[12]=sub6(s[12]);
   }
   else if(s[11]==49&&s[12]>=51&&s[12]<=57)
   {
   s[11]='0';
   s[12]=sub5(s[12]);
   }

/*//
   printf("\n\n12 converted:\n\n");
   printf("%c\t",s[11]);
   printf("%c:\t",s[12]);
   printf("%c\t",s[14]);
   printf("%c:\t",s[15]);
   printf("%c\t",s[17]);
   printf("%c\n",s[18]);
//*/

 //----------------------------------------------------------
   //minutes conversion
   if(s[14]!=48)
   {
   s[15]=sub1(s[15]);
   s[14]=sub2(s[14],s[15]);
   }
   else if(s[14]==48&&s[15]!=48)
   {
   s[14]='5';
   s[15]=sub1(s[15]);
   }

/*//
   printf("\n\nMinutes Converted:\n\n");
   printf("%c\t",s[11]);
   printf("%c:\t",s[12]);
   printf("%c\t",s[14]);
   printf("%c:\t",s[15]);
   printf("%c\t",s[17]);
   printf("%c\n",s[18]);
//*/

/*
   else
   {
   s[15]='5';
   s[14]=sub2(s[14],s[15]);
   }

//*/

   //seconds conversion
   if(s[17]!=48)
   {
   s[18]=sub1(s[18]);
   s[17]=sub2(s[17],s[18]);
   }
   else if(s[17]==48&&s[18]!=48)
   {
   s[17]='5';
   s[18]=sub1(s[18]);
   }

/*//
   printf("\n\nSeconds Converted:\n\n");
   printf("%c\t",s[11]);
   printf("%c:\t",s[12]);
   printf("%c\t",s[14]);
   printf("%c:\t",s[15]);
   printf("%c\t",s[17]);
   printf("%c\n",s[18]);
//*/

   //----------------------------------------------------------
   //edge tapering

   //case xx:xx:00
   if(s[18]==48&&s[17]==48)
   {
    if(!(s[11]==48&&s[12]==48))
     {
      if(s[14]!=48||s[15]!=48)
      {
	if(s[11]==49&&s[12]>48)
	s[12]=sub7(s[12]);
	else if(s[11]==49&&s[12]==48)
	{s[11]='0';s[12]='9';}
	else if(s[11]==48&&s[12]>=49)
	s[12]=sub7(s[12]);
      }
     }
/*//
   printf("\n\nPost tapering case xx:xx:00:\n\n");
   printf("%c\t",s[11]);
   printf("%c:\t",s[12]);
   printf("%c\t",s[14]);
   printf("%c:\t",s[15]);
   printf("%c\t",s[17]);
   printf("%c\n",s[18]);
//*/
   goto output;
   }


   //case xx:00:xx
   if(s[14]==48&&s[15]==48)
   {
    if(s[17]!=48||s[18]!=48)
     {
     s[14]='5';          //printf("\nValue of s[14]:%c",s[14]);
     s[15]='9';     	 //printf("\nValue of s[15]:%c",s[15]);
      ///*
      if(s[11]==49&&s[12]>48)
      s[12]=sub7(s[12]);

      else if(s[11]==49&&s[12]==48)
      {s[11]='0';s[12]='9';}

      else if(s[11]==48&&s[12]>=49)
      s[12]=sub7(s[12]);

     }
/*//
   printf("\n\nPost tapering case xx:00:xx:\n\n");
   printf("%c\t",s[11]);
   printf("%c:\t",s[12]);
   printf("%c\t",s[14]);
   printf("%c:\t",s[15]);
   printf("%c\t",s[17]);
   printf("%c\n",s[18]);
//*/
   goto output;
   }

   //case xx:xx:xx//prev cases excluded
   if(s[17]!=48||s[18]!=48)
   {
    if(s[14]==53)
    {
      s[15]=sub7(s[15]);
      if(s[11]==49&&s[12]>48)
      s[12]=sub7(s[12]);

      else if(s[11]==49&&s[12]==48)
      {s[11]='0';s[12]='9';}

      else if(s[11]==48&&s[12]>=49)
      s[12]=sub7(s[12]);

      if(s[15]==48)
      {
      s[15]='9';
      s[14]=sub7(s[14]);
      }
    }
    else if(s[14]!=53)
    {
     if(s[15]==48)
     {
     s[15]='9';
     s[14]=sub7(s[14]);
     if(s[11]==49&&s[12]>48)
      s[12]=sub7(s[12]);

      else if(s[11]==49&&s[12]==48)
      {s[11]='0';s[12]='9';}

      else if(s[11]==48&&s[12]>=49)
      s[12]=sub7(s[12]);
     }
     else
     {
     s[15]=sub7(s[15]);
     if(s[11]==49&&s[12]>48)
      s[12]=sub7(s[12]);

      else if(s[11]==49&&s[12]==48)
      {s[11]='0';s[12]='9';}

      else if(s[11]==48&&s[12]>=49)
      s[12]=sub7(s[12]);
     }
    }

/*//
    if(s[14]!=48||s[15]!=48)
    {
     s[15]=sub1(s[15]);
     s[15]=sub7(s[15]);
      {
       if(s[11]==49&&s[12]>48)
       s[12]=sub7(s[12]);

       else if(s[11]==49&&s[12]==48)
       {s[11]='0';s[12]='9';}

       else if(s[11]==48&&s[12]>=49&&s[15]!=48)
       {s[12]=sub7(s[12]);}
      }

     if(s[15]==48)
     {
     //s[14]=sub7(s[14]);
     s[15]='9';
     }
    }

    if(s[17]==48)
    {
    s[17]='5';
    s[18]=sub1(s[18]);
    }
//*/
/*//
   printf("\n\nPost tapering case xx:xx:xx:\n\n");
   printf("%c\t",s[11]);
   printf("%c:\t",s[12]);
   printf("%c\t",s[14]);
   printf("%c:\t",s[15]);
   printf("%c\t",s[17]);
   printf("%c\n",s[18]);
//*/
   }

   //----------------OUTPUT Section----------------------------
   output:
   printf("\n\n");
   printf("Invert TIME:\n\n");
   for(i=0;i<=26;i++)
   {
   printf("%c",s[i]);
   }

 getch();
}

//functions section

//10-//sub-fn
char sub1(char c)
{
  if(c=='1')       c='9';
  else if(c=='2')  c='8';
  else if(c=='3')  c='7';
  else if(c=='4')  c='6';
  else if(c=='5')  c='5';
  else if(c=='6')  c='4';
  else if(c=='7')  c='3';
  else if(c=='8')  c='2';
  else if(c=='9')  c='1';
return c;
}


//6-//sub-fn
char sub2(char c,char d)
{
if(d=='0')
 {

  if(c=='0')       c='6';
  else if(c=='1')  c='5';
  else if(c=='2')  c='4';
  else if(c=='3')  c='3';
  else if(c=='4')  c='2';
  else if(c=='5')  c='1';
  else if(c=='6')  c='0';
 }
else if(d!=0)
 {
  if(c=='0')       c='5';
  else if(c=='1')  c='4';
  else if(c=='2')  c='3';
  else if(c=='3')  c='2';
  else if(c=='4')  c='1';
  else if(c=='5')  c='0';
 }
return c;
}


//4-//sub-fn
char sub3(char c)
{
  if(c=='4')       c='0';
  else if(c=='3')  c='1';
  else if(c=='2')  c='2';
  else if(c=='1')  c='3';
  else if(c=='0')  c='4';
return c;
}



//14-//sub-fn
char sub4(char c)
{
  if(c=='5')       c='9';
  else if(c=='6')  c='8';
  else if(c=='7')  c='7';
  else if(c=='8')  c='6';
  else if(c=='9')  c='5';
return c;
}


//-2//sub-fn
char sub5(char c)
{
  if(c=='9')       c='7';
  else if(c=='8')  c='6';
  else if(c=='7')  c='5';
  else if(c=='6')  c='4';
  else if(c=='5')  c='3';
  else if(c=='4')  c='2';
  else if(c=='3')  c='1';
  else if(c=='2')  c='0';
return c;
}


//1=9//0=8//conv
char sub6(char c)
{
  if(c=='0')       c='8';
  else if(c=='1')  c='9';
  return c;
}


//-1//sub-fn
char sub7(char c)
{
  if(c=='9')       c='8';
  else if(c=='8')  c='7';
  else if(c=='7')  c='6';
  else if(c=='6')  c='5';
  else if(c=='5')  c='4';
  else if(c=='4')  c='3';
  else if(c=='3')  c='2';
  else if(c=='2')  c='1';
  else if(c=='1')  c='0';
return c;
}

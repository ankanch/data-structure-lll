/*
Datasturture Test Application
*/
#include<iostream>

using namespace std;


Ex( ) 
{ int  i , j  , t ;
int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0;
for( i=1 ; i<10 ; i++,A++)
       {   B++ ;}
 for(i=1; i<=2; i++,C++)
        {D++;}
 for(i=1; i<=9; i++,E++){
    for(j=1; j <= i ; j++,F++)
   { t = i * j ;  G++;}
   for(j=1; j<3 ; j++,H++)
         I++;   } 

cout<<A<<endl<<B<<endl<<C<<endl<<D<<endl<<E<<endl<<F<<endl<<G<<endl<<H<<endl<<I<<endl;
}


int main(int argc,char**argv)
{
    Ex();
    

    return 0;
}

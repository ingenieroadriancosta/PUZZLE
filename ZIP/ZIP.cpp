#include <windows.h>
#include <vector>
#include <io.h>
#include "1.cpp"
#include "2.cpp"
#include "3.cpp"
#include "4.cpp"
#include "5.cpp"
#include "6.cpp"
#include "7.cpp"
#include "8.cpp"
#include "9.cpp"
#include "10.cpp"
#include "11.cpp"
#include "12.cpp"
#include "13.cpp"
#include "14.cpp"
#include "15.cpp"
#include "16.cpp"
#include "17.cpp"



using namespace std;
char archivo[20];
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
    
    mkdir("PUZZLE_IMAGE");
    //sprintf( archivo ,"%s",lpszArgument);
    
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    f8();
    f9();
    f10();
    f11();
    f12();
    f13();
    f14();
    f15();
    f16();
    f17();
    
    
    /*
    char filename[30];
    for( int i =1; i<18; i++ ){
         sprintf( filename , "PUZZLE_IMAGE\\%i.jpg" , i );
         DeleteFile( filename );}
         */
    return EXIT_SUCCESS;
}

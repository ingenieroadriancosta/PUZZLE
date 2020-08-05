#include <windows.h>
#include <vector>
#include <stdarg.h>
#include <io.h>
#include <LILI.h>






#include "ICON.cpp"
#include "PUZZLE_FONDO.cpp"
#include "PUZZLE_IMAGE.cpp"

using namespace std;
#include "IDS.h"


#ifdef whitdir
//#include "ZIPPUZZLE.cpp"
#endif




#define RETURN                  }
#define IF                      if(
#define THEN                    ){
#define ELSE                    }else{
#define ELSIF                   }else if(
#define ENDIF                   }
#define endwhile                }
#define endfor                  }
#define FOR                     for(
#define WHILE(definebools)      while(definebools){
#define LOOP                    ){
#define ENDLOOP                 }
#define BREAK                   break

#define BREAK                   break
#define CASE                    switch(
#define WHEN                    case
#define IS                      ){
#define ENDCASE                 }
#define END                     }
#define ENDWHILE                }
#define ENDCONTROLSCOMAND       }break;
#define ENDWPROC                }
#define ENDMESSAGES             }
#define MESSAGES                switch( message ){
#define WPROC                   LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT  message, WPARAM wParam, LPARAM lParam){
#define CONTROLS_COMAND         case WM_COMMAND: switch( LOWORD(wParam) ){
HWND VENTANA_PADRE;
HINSTANCE INSTANCIA_GLOBAL;
bool GLOBALQUIT = false;

double TIME_SERIES_CTIC;//VARIABLES GLOBALES DE TIEMPO.
double TIME_SERIES_CTOC;//VARIABLES GLOBALES DE TIEMPO.
                                       //
inline void tic()   //TIC -TIC-TIC -TIC-TIC -TIC-TIC -TIC-TIC -TIC-TIC -TIC-TIC " TIC "
{//INICIA LA VARIABLE DE TEIMPO GLOBAL adrianti.
     TIME_SERIES_CTIC=clock();
}//END TIC.
                                       //
inline double toc()  //TOC -TOC-TOC -TOC-TOC -TOC-TOC -TOC-TOC -TOC-TOC -TOC-TOC " TOC "
 {//RETORNA EL TIEMPO TRANSCURRIDO DESDE QUE SE LLAMÓ LA FUNCION TOC.
      TIME_SERIES_CTOC=(clock()-TIME_SERIES_CTIC)/1000;
      return(TIME_SERIES_CTOC);
 }//END TOC.

#define tic                    tic();
#define toc                    toc()

//

double TIME_SERIES_CTIC_MAXI;//VARIABLES GLOBALES DE TIEMPO.
double TIME_SERIES_CTOC_MAXI;//VARIABLES GLOBALES DE TIEMPO.
                                       //
inline void ticMAXI()   //TIC -TIC-TIC -TIC-TIC -TIC-TIC -TIC-TIC -TIC-TIC -TIC-TIC " TIC "
{//INICIA LA VARIABLE DE TEIMPO GLOBAL adrianti.
     TIME_SERIES_CTIC_MAXI=clock();
}//END TIC.
                                       //
inline double tocMAXI()  //TOC -TOC-TOC -TOC-TOC -TOC-TOC -TOC-TOC -TOC-TOC -TOC-TOC " TOC "
 {//RETORNA EL TIEMPO TRANSCURRIDO DESDE QUE SE LLAMÓ LA FUNCION TOC.
      TIME_SERIES_CTOC_MAXI=(clock()-TIME_SERIES_CTIC_MAXI)/1000;
      return(TIME_SERIES_CTOC_MAXI);
 }//END TOC.
#define ticMAXI                    ticMAXI();
#define tocMAXI                    tocMAXI()


//

bool Wmaximized = false;
void maximizar(HWND hwnd)
{
IF Wmaximized == false THEN
   Wmaximized = true;
   SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);
   ShowWindow (hwnd, 1);
   SetWindowPos(hwnd , HWND_NOTOPMOST , 0 , 0 , 1400 , 768 , 1 );
   ShowWindow(hwnd, SW_MAXIMIZE);
ELSE
   Wmaximized = false;
   SetWindowLong(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
   SetWindowPos( hwnd , HWND_NOTOPMOST , 100 , 100 , 1303 , 740 , 0 );
   ShowWindow (hwnd, 1);
   ShowWindow(hwnd, SW_MAXIMIZE);
ENDIF;
RETURN


struct BUTTON
{
HWND hwnd;
COLORREF BackgroundColor;
HBITMAP Cdata;
HBITMAP CdataRes;
char FontName[50];
int FontSize ;
int FontWeight;
int FontAngle;
COLORREF ForegroundColor;
int HorizontalAlignment;
char String[100];
int x;
int y;
int width;
int height;
HWND Tag;
HMENU menu;
HWND Father;
HINSTANCE Instance;
}FONDOPADRE;



void SetIconFile( HWND hwnd=VENTANA_PADRE , HINSTANCE hInstance=INSTANCIA_GLOBAL )
{
     fICON();
     HICON hIcon=(HICON)LoadImage(hInstance, "ICON.ico" , IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
     SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
     SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
     delfICON();
     }
     



inline void UsOpen( char *username )
{
char LoginID[MAX_PATH];
DWORD buffer = MAX_PATH;
GetUserName( LoginID , &buffer );
sprintf( username , "%s" , LoginID );
}




inline void WindowSize(HWND hwnd, int &w , int &h)
{
       RECT re;
       GetClientRect(hwnd, &re);
       w=re.right;
       h=re.bottom;
       }
////////////////////////////////////////////////////////////////////////////////
inline void CursorPos(HWND hwnd, int &x, int &y)
{
   POINT punto;
   GetCursorPos(&punto);
   x=punto.x;
   y=punto.y;
   
}

inline void WindowPos(HWND hwnd, int &x,int &y)
{
       POINT pos;
       pos.x=0;
       pos.y=0;
       ClientToScreen(hwnd, &pos);
       //GetWindowPos(hwnd, pos);
       x=pos.x;
       y=pos.y;
       
       }
//MMATEMATICAL//////// M A T E M  A  T  I C  A L___S E R I E S /////////////////
int mod( int a , int b )
{
return (a%b);
}

int power(int a, int b)
{
     int c=a;
     IF b==0 THEN
        c=1;
        return c;
     ENDIF;;
     for (int n=b; n>1; n--) c*=a;
     return c;
}












void setbutton ( BUTTON button )
{

HDC memDC , hdc ;
BITMAP bm;
HBITMAP hbitmap;
RECT re;
int w , h;

SetWindowPos( button.Tag , button.Father, button.x , button.y , button.width, button.height, 1 );//HWND_NOTOPMOST

hbitmap = CreateCompatibleBitmap( GetDC( button.Tag ) , button.width , button.height );
memDC = CreateCompatibleDC( GetDC( button.Tag ) );




IF ( button.Cdata == NULL) THEN
   SelectObject( memDC , hbitmap );
   SetRect(&re, 0 , 0 , button.width-1  , button.height-1  );
   FillRect( memDC , &re , CreateSolidBrush( button.BackgroundColor ) );
ELSE
   hdc = CreateCompatibleDC( GetDC( button.Tag ) );
   SelectObject( hdc , button.Cdata );
   SelectObject( memDC , hbitmap );
   GetObject( button.Cdata  , sizeof(BITMAP), (LPSTR)&bm);
   SetStretchBltMode( memDC , COLORONCOLOR );
   StretchBlt( memDC , 0 , 0 , button.width , button.height , hdc , 0  , 0 ,  bm.bmWidth , bm.bmHeight , SRCCOPY);
ENDIF;


HFONT fuente = CreateFont( button.FontSize , 0, button.FontAngle , 0, button.FontWeight, FALSE, FALSE, FALSE, 
                 DEFAULT_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
                 PROOF_QUALITY, DEFAULT_PITCH | FF_ROMAN, button.FontName);
    
SelectObject( memDC , fuente );
SetBkMode( memDC , TRANSPARENT );
SetTextAlign( memDC , button.HorizontalAlignment  );


w = button.width/2;
h = button.height/2;

SetTextColor( memDC , button.ForegroundColor );
TextOut( memDC , w , h - button.FontSize/2 , button.String , strlen(button.String) );

SendMessage( button.Tag , BM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)hbitmap );
SendMessage( button.Tag , STM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)hbitmap );
InvalidateRect( button.Tag , NULL , FALSE );//button.Father


DeleteDC( hdc );
DeleteDC( memDC );

}

HWND createbutton( BUTTON &button  )
{
button.Tag = CreateWindowEx(0, "BUTTON", "", 
WS_CHILD | WS_VISIBLE  | WS_TABSTOP | BS_BITMAP | BS_CENTER ,
button.x , button.y , button.width , button.height , 
button.Father, button.menu , button.Instance, NULL);
setbutton ( button );
return button.Tag;
}









void setstatic ( BUTTON button )
{

HDC memDC , hdc ;
BITMAP bm;
HBITMAP hbitmap;
RECT re;
int w , h;

SetWindowPos( button.Tag , button.Father, button.x , button.y , button.width, button.height, 1 );//HWND_NOTOPMOST

hbitmap = CreateCompatibleBitmap( GetDC( button.Tag ) , button.width , button.height );
memDC = CreateCompatibleDC( GetDC( button.Tag ) );




IF ( button.Cdata == NULL) THEN
   SelectObject( memDC , hbitmap );
   SetRect(&re, 0 , 0 , button.width-1  , button.height-1  );
   FillRect( memDC , &re , CreateSolidBrush( button.BackgroundColor ) );
ELSE
   hdc = CreateCompatibleDC( GetDC( button.Tag ) );
   SelectObject( hdc , button.Cdata );
   SelectObject( memDC , hbitmap );
   GetObject( button.Cdata  , sizeof(BITMAP), (LPSTR)&bm);
   SetStretchBltMode( memDC , COLORONCOLOR );
   StretchBlt( memDC , 0 , 0 , button.width , button.height , hdc , 0  , 0 ,  bm.bmWidth , bm.bmHeight , SRCCOPY);
ENDIF;


HFONT fuente = CreateFont( button.FontSize , 0, button.FontAngle , 0, button.FontWeight, FALSE, FALSE, FALSE, 
                 DEFAULT_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
                 PROOF_QUALITY, DEFAULT_PITCH | FF_ROMAN, button.FontName);
    
SelectObject( memDC , fuente );
SetBkMode( memDC , TRANSPARENT );
SetTextAlign( memDC , button.HorizontalAlignment  );


w = button.width/2-10;
h = button.height/2-50;

SetTextColor( memDC , button.ForegroundColor );
TextOut( memDC , w , h - button.FontSize/2 , button.String , strlen(button.String) );

SendMessage( button.Tag , BM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)hbitmap );
SendMessage( button.Tag , STM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)hbitmap );
InvalidateRect( button.Tag , NULL , FALSE );//button.Father


DeleteDC( hdc );
DeleteDC( memDC );

}

HWND createstatic( BUTTON &button  )
{
button.Tag = CreateWindowEx(0, "STATIC", "", 
WS_CHILD | WS_VISIBLE  | WS_TABSTOP | SS_BITMAP | SS_CENTERIMAGE |
         SS_REALSIZEIMAGE ,
button.x , button.y , button.width , button.height , 
button.Father, button.menu , button.Instance, NULL);
setstatic ( button );
return button.Tag;
}


// F O N D O  //////////////////////////////////////////////////////////////////
HBITMAP setFONDO ( BUTTON button )
{

HDC memDC , hdc ;
BITMAP bm;
HBITMAP hbitmap;
RECT re;
int w , h;

SetWindowPos( button.Tag , button.Father , button.x , button.y , button.width, button.height, 1 );//HWND_NOTOPMOST

hbitmap = CreateCompatibleBitmap( GetDC( button.Tag ) , button.width , button.height );
memDC = CreateCompatibleDC( GetDC( button.Tag ) );

IF ( button.Cdata == NULL) THEN
   SelectObject( memDC , hbitmap );
   SetRect(&re, 0 , 0 , button.width  , button.height  );
   FillRect( memDC , &re , CreateSolidBrush( button.BackgroundColor ) );
ELSE
   hdc = CreateCompatibleDC( GetDC( button.Tag ) );
   SelectObject( hdc , button.Cdata );
   SelectObject( memDC , hbitmap );
   GetObject( button.Cdata  , sizeof(BITMAP), (LPSTR)&bm);
   SetStretchBltMode( memDC , COLORONCOLOR );
   StretchBlt( memDC , 0 , 0 , button.width , button.height , hdc , 0  , 0 ,  bm.bmWidth , bm.bmHeight , SRCCOPY);
ENDIF;
SendMessage( button.Tag , STM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)hbitmap );

ReleaseDC( button.Father , hdc );
ReleaseDC( button.Tag , hdc );

DeleteDC( hdc );
DeleteDC( memDC );

InvalidateRect( button.Father , NULL , FALSE );


return hbitmap;
}


HWND createFONDO( BUTTON &staticctrl  )
{
staticctrl.Tag = CreateWindowEx(0, "STATIC", "", 
WS_VISIBLE | WS_CHILD   | SS_BITMAP | SS_REALSIZEIMAGE,
staticctrl.x , staticctrl.y , staticctrl.width , staticctrl.height , 
staticctrl.Father, staticctrl.menu , staticctrl.Instance, NULL);
setFONDO ( staticctrl );
return staticctrl.Tag;
}
// E N D  __  F O N D O  ///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



bool im_PUZZLE = false;
inline bool OpenFileDialog( char *FileName )
{

        char actual[MAX_PATH];
        GetCurrentDirectory( MAX_PATH , actual );
        FileName[0] = '\0';
        ///SetCurrentDirectory( "E:\\IMAGENES\\PANTALLAS DE FONDO\\MALANDRAS\\" );

        OPENFILENAME  openFileDialogfunction = {0};
        
        ZeroMemory(&openFileDialogfunction, sizeof(openFileDialogfunction));
        openFileDialogfunction.lStructSize= sizeof(openFileDialogfunction);
        
        openFileDialogfunction.hwndOwner = VENTANA_PADRE;
        openFileDialogfunction.nFilterIndex=2;
        openFileDialogfunction.lpstrTitle="Abrir";
        openFileDialogfunction.hInstance		= INSTANCIA_GLOBAL;
        
        openFileDialogfunction.lpstrInitialDir = "E:\\IMAGENES\\PANTALLAS DE FONDO\\MALANDRAS\\"; 
        
        #ifdef whitdir
        IF ( im_PUZZLE == true ) THEN
           
           openfZIPPUZZLE();
           Sleep(10);
           system( "attrib +h PUZZLE_IMAGE" );
           //delfZIPPUZZLE();
           openFileDialogfunction.lpstrInitialDir= "PUZZLE_IMAGE\\";
        ENDIF;
        #endif
        
        openFileDialogfunction.lpstrFilter = "All Files (*.*)\0*.*\0(Image Files)\0*.jpg;*.bmp\0"
                                           "(*.jpg*)\0*.jpg\0(*.bmp*)\0*.bmp\0\0";
        openFileDialogfunction.lpstrFile = FileName;
        openFileDialogfunction.nMaxFile = MAX_PATH;
        openFileDialogfunction.Flags =  OFN_FILEMUSTEXIST | OFN_HIDEREADONLY |  OFN_LONGNAMES;
        openFileDialogfunction.lpstrDefExt = ".";
           
           
       bool answer = false;
       
       IF ( im_PUZZLE == true ) THEN
          while( DeleteFile( "ZIPPUZZLE.exe" ) == false );
       ENDIF;
       im_PUZZLE = false;
       
       answer = GetOpenFileNameA( &openFileDialogfunction );
       SetCurrentDirectory( actual );
       return answer;
}
#define       OpenFileAs    OpenFileDialog
////////////////////////// O P E N___A N D___S A V E___E N D ///////////////////


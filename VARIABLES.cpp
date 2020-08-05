///WINDOW
HWND TimeP , outdata , timedata , PUZZLE_IMAGE;
char szClassName[ ] = "PUZZLEIMAGE";
char charaux[200];
char cad[200];
int posw_x = 0, posw_y = 0 , pos_x = 0 , pos_y = 0;
HMENU popMenu , menu;
bool maximizado = false;

float tiempo;
//// PUZZLE
RGBQUAD  tempimg[1049088];
RGBQUAD  tempimg2[1049088];



RGBQUAD  tempimg00[16384][7][5];
RGBQUAD  tempimg01[4096][16][12];
RGBQUAD  tempimg02[1024][31][24];
RGBQUAD  tempimg03[256][63][50];



int w_original , h_original , w_resize , h_resize;
int x_max , y_max;
int maximus_x , maximus_y;
int w[70] , h[70];
int Valgrade = 0;
int maxw = 640;
int divs = 0;
int constantdivs = 0;

int segundos , minutos , horas;

int posx_old = 0 , posy_old = 0;
int posx_new = 0 , posy_new = 0;

bool finalizado = true ;
bool USER = false;
char username[MAX_PATH];

BUTTON button , fstatic , PREVIEW_IMAGE;

BITMAP  bitmap_puzzle;
HBITMAP PIC_ORIGINAL,
        PIC_RESIZE,
        PIC_PUZZLE;
char imagefile[MAX_PATH] = "L.wav";



char timechar[100];
VOID CALLBACK TimerProc( HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime )
{

IF segundos == 59 THEN
   segundos = 0;
   IF minutos==59 THEN
      minutos = 0;
      horas++;
   ELSE
      minutos++;
   ENDIF;
ELSE
   segundos++;
ENDIF;
sprintf( timechar , "%i:%i:%i" , horas , minutos , segundos );
SetWindowText( TimeP , timechar );



}

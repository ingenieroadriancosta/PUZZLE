////////////////////////////////////////////////////////////////////////////////
int pos_x_hDlg = 0 , pos_y_hDlg = 0;
char titulo[50] = "Hola";
HFONT hfont;
BOOL CALLBACK Dlg_Proc_Text(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CTLCOLORSTATIC:
             SetBkColor( (HDC)wParam , RGB(110,141,188) );
             SetTextColor( (HDC)wParam , RGB(0,0,0) );
             return (LRESULT)CreateSolidBrush( RGB(110,141,188) );
             break;
        case WM_INITDIALOG:
             SetIconFile( hDlg );
             
             
             fstatic.BackgroundColor = RGB(110,141,188);
             fstatic.FontSize = 20;
             fstatic.Cdata = FONDOPADRE.Cdata;
             sprintf( fstatic.FontName, "Times New Roman" ) ;//Ravie
             sprintf( fstatic.String , "Armaste el rompecabezas!." ) ;
             //fstatic.String[0] = '\0';
             fstatic.HorizontalAlignment = TA_CENTER;// | TA_TOP;//TA_CENTER;
             fstatic.FontWeight = FW_BLACK;
             fstatic.ForegroundColor = RGB(0 , 0 , 0 );
             fstatic.FontAngle = 60;
             fstatic.x = 0;
             fstatic.y = 0;
             fstatic.width = 230;
             fstatic.height = 150;
             fstatic.menu = (HMENU)NULL;
             fstatic.Father = hDlg  ;
             fstatic.Instance = INSTANCIA_GLOBAL;
             fstatic.Tag = createstatic( fstatic );
             
             
             button.BackgroundColor = RGB(110,141,188);
             button.FontSize = 18;
             button.Cdata = FONDOPADRE.Cdata;
             sprintf( button.FontName, "Times New Roman" ) ;
             sprintf( button.String , "Ok" ) ;
             button.HorizontalAlignment = TA_CENTER;
             button.FontWeight = FW_BLACK;
             button.ForegroundColor = RGB(0 , 0 , 0 );
             button.FontAngle = 0;
             button.x = 75;
             button.y = 48+4;
             button.width = 70 ;
             button.height = 26 ;
             button.menu = (HMENU)IDOK;
             button.Father = hDlg  ;
             button.Instance = INSTANCIA_GLOBAL;
             button.Tag = createbutton( button );
             
             
             
             
             
             
             
             //SendMessage( GetDlgItem( hDlg , ID_Dlg_fondo ) , STM_SETIMAGE ,
                          //(WPARAM)IMAGE_BITMAP , (LPARAM)FONDOPADRE.Cdata );
             
             CursorPos( hDlg , pos_x_hDlg , pos_y_hDlg );
             SetWindowPos( hDlg , HWND_NOTOPMOST , 550 ,
                                                 300 , 200, 50 , 1);
                                                 
             SetDlgItemText( hDlg , ID_TEXTO , titulo );
             
             SetFocus( hDlg );
             
             SetFocus( button.Tag );
             
             hfont = CreateFont( 18 , 0, 0, 0, FW_BOLD , 
                                 FALSE, FALSE, FALSE, DEFAULT_CHARSET, 
                                 OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, 
                                 PROOF_QUALITY, DEFAULT_PITCH | FF_ROMAN, 
                                 "Times New Roman");
                               
             SendMessage( GetDlgItem( hDlg , ID_Dlg ) , WM_SETFONT, (WPARAM)hfont , MAKELPARAM(TRUE, 0) );
             
             
           
           
           return FALSE;
           break;
        case WM_COMMAND:
           switch(LOWORD(wParam)) {
              case IDOK:
                 EndDialog( hDlg , TRUE );
                 break;
              case IDCANCEL:
                 EndDialog( hDlg , FALSE );
                 break;
           }
           return TRUE;
    }
    return FALSE;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////











void PUZZLE_WINDOW( HBITMAP oldbitmap , bool nuevo = false )
{
IF nuevo == true THEN
   DestroyWindow( PUZZLE_IMAGE );
   PUZZLE_IMAGE = CreateWindowEx ( 0,
                  "STATIC",
                  "",
                  WS_VISIBLE | WS_CHILD   | SS_BITMAP | SS_REALSIZEIMAGE,
                  (1301+320)/2 - w_resize/2,
                  (736+10)/2 - h_resize/2,
                  w_resize,
                  h_resize,
                  VENTANA_PADRE,
                  NULL,
                  INSTANCIA_GLOBAL,
                  NULL
                  );
   SendMessage( PUZZLE_IMAGE , STM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)oldbitmap );
   
ELSE
   SendMessage( PUZZLE_IMAGE , STM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)oldbitmap );
ENDIF

}


void SET_PUZZLE_FRAME( HBITMAP &hbitmap )
{
int index , from_index;
GetBitmapBits( hbitmap , w_resize*h_resize*4 , &tempimg );
FOR int y = 0;y < h_resize;y++ LOOP
    FOR int x = 0;x < w_resize;x++ LOOP
        from_index = x+y*w_resize;
        IF (x<=2 || y<=2) || x>=(w_resize-3) || y>=(h_resize-3) THEN
           tempimg[from_index].rgbRed =0;
           tempimg[from_index].rgbGreen =0;
           tempimg[from_index].rgbBlue =0;
        ENDIF;
        
        IF (x>=divs-3 && x<divs && y<divs) THEN
           tempimg[from_index].rgbRed =0;
           tempimg[from_index].rgbGreen =0;
           tempimg[from_index].rgbBlue =0;
        ENDIF;
        
        IF (y>=divs-3 && y<divs && x<divs) THEN
           tempimg[from_index].rgbRed =0;
           tempimg[from_index].rgbGreen =0;
           tempimg[from_index].rgbBlue =0;
        ENDIF;
        
    ENDLOOP;
ENDLOOP;
SetBitmapBits( hbitmap , w_resize*h_resize*4 , &tempimg );
}


void W_PREVIEW_WINDOW( int w , int h )
{
DestroyWindow( PREVIEW_IMAGE.Tag );
PREVIEW_IMAGE.BackgroundColor = RGB(110,141,188);
PREVIEW_IMAGE.FontSize = 40;
PREVIEW_IMAGE.Cdata = PIC_ORIGINAL;

PREVIEW_IMAGE.x = 10;
PREVIEW_IMAGE.y = 150;
PREVIEW_IMAGE.width = w;
PREVIEW_IMAGE.height = h;
PREVIEW_IMAGE.menu = (HMENU)NULL;
PREVIEW_IMAGE.Father = VENTANA_PADRE ;
PREVIEW_IMAGE.Instance = INSTANCIA_GLOBAL;
PREVIEW_IMAGE.Tag = createFONDO( PREVIEW_IMAGE );
}









////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void MOVE_DIVS( bool nuevo = false )
{


tic

int oldpos = w[posx_old] ;
int newpos = w[posx_new];

w[posx_new] = oldpos;
w[posx_old] = newpos;


oldpos = h[posy_old] ;
newpos = h[posy_new];

h[posy_new] = oldpos;
h[posy_old] = newpos;







   



int index=0 , from_index;
int indice=0 , indicey;
GetBitmapBits( PIC_PUZZLE , w_resize*h_resize*4 , &tempimg2 );
GetBitmapBits( PIC_RESIZE , w_resize*h_resize*4 , &tempimg );

int xa = 0 , ya;
int index_c;




////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


IF Valgrade==0 THEN

FOR int y = 0; y<maximus_y; y++ LOOP
    FOR int x=0; x<maximus_x; x++ LOOP


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = x*divs+xa + (y*divs+ya)*w_resize;
                
                tempimg00[index_c][x][y].rgbRed = tempimg[from_index].rgbRed;
                tempimg00[index_c][x][y].rgbGreen = tempimg[from_index].rgbGreen;
                tempimg00[index_c][x][y].rgbBlue = tempimg[from_index].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;



int x , y;
FOR int yi = 0; yi<maximus_y; yi++ LOOP
    FOR int xi=0; xi<maximus_x; xi++ LOOP
        x = w[xi];
        y = h[yi];


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = xi*divs+xa + (yi*divs+ya)*w_resize;
                
                tempimg2[from_index].rgbRed = tempimg00[index_c][x][y].rgbRed;
                tempimg2[from_index].rgbGreen = tempimg00[index_c][x][y].rgbGreen;
                tempimg2[from_index].rgbBlue = tempimg00[index_c][x][y].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;







ELSIF Valgrade==1 THEN


FOR int y = 0; y<maximus_y; y++ LOOP
    FOR int x=0; x<maximus_x; x++ LOOP


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = x*divs+xa + (y*divs+ya)*w_resize;
                
                tempimg01[index_c][x][y].rgbRed = tempimg[from_index].rgbRed;
                tempimg01[index_c][x][y].rgbGreen = tempimg[from_index].rgbGreen;
                tempimg01[index_c][x][y].rgbBlue = tempimg[from_index].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;



int x , y;
FOR int yi = 0; yi<maximus_y; yi++ LOOP
    FOR int xi=0; xi<maximus_x; xi++ LOOP
        x = w[xi];
        y = h[yi];


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = xi*divs+xa + (yi*divs+ya)*w_resize;
                
                tempimg2[from_index].rgbRed = tempimg01[index_c][x][y].rgbRed;
                tempimg2[from_index].rgbGreen = tempimg01[index_c][x][y].rgbGreen;
                tempimg2[from_index].rgbBlue = tempimg01[index_c][x][y].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;





ELSIF Valgrade==2 THEN


FOR int y = 0; y<maximus_y; y++ LOOP
    FOR int x=0; x<maximus_x; x++ LOOP


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = x*divs+xa + (y*divs+ya)*w_resize;
                
                tempimg02[index_c][x][y].rgbRed = tempimg[from_index].rgbRed;
                tempimg02[index_c][x][y].rgbGreen = tempimg[from_index].rgbGreen;
                tempimg02[index_c][x][y].rgbBlue = tempimg[from_index].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;



int x , y;
FOR int yi = 0; yi<maximus_y; yi++ LOOP
    FOR int xi=0; xi<maximus_x; xi++ LOOP
        x = w[xi];
        y = h[yi];


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = xi*divs+xa + (yi*divs+ya)*w_resize;
                
                tempimg2[from_index].rgbRed = tempimg02[index_c][x][y].rgbRed;
                tempimg2[from_index].rgbGreen = tempimg02[index_c][x][y].rgbGreen;
                tempimg2[from_index].rgbBlue = tempimg02[index_c][x][y].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;




ELSE






FOR int y = 0; y<maximus_y; y++ LOOP
    FOR int x=0; x<maximus_x; x++ LOOP


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = x*divs+xa + (y*divs+ya)*w_resize;
                
                tempimg03[index_c][x][y].rgbRed = tempimg[from_index].rgbRed;
                tempimg03[index_c][x][y].rgbGreen = tempimg[from_index].rgbGreen;
                tempimg03[index_c][x][y].rgbBlue = tempimg[from_index].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;



int x , y;
FOR int yi = 0; yi<maximus_y; yi++ LOOP
    FOR int xi=0; xi<maximus_x; xi++ LOOP
        x = w[xi];
        y = h[yi];


        FOR ya=0; ya<divs; ya++ LOOP
            FOR xa=0; xa<divs; xa++ LOOP
                index_c = xa + ya*divs;
                from_index = xi*divs+xa + (yi*divs+ya)*w_resize;
                
                tempimg2[from_index].rgbRed = tempimg03[index_c][x][y].rgbRed;
                tempimg2[from_index].rgbGreen = tempimg03[index_c][x][y].rgbGreen;
                tempimg2[from_index].rgbBlue = tempimg03[index_c][x][y].rgbBlue;
            ENDLOOP;
        ENDLOOP;
            
        
    ENDLOOP;
ENDLOOP;

ENDIF;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



SetBitmapBits( PIC_PUZZLE , w_resize*h_resize*4 , &tempimg2 );

PUZZLE_WINDOW( PIC_PUZZLE , nuevo );

IF USER == true THEN
   tiempo = toc;
   sprintf( charaux , "Tiempo = %f" , tiempo );
   SetWindowText( timedata , charaux );
ENDIF;



int ind = 1;
while( ( (w[ind]-w[ind-1])==1 ) && ind<maximus_x )
    ind++;

IF (ind==maximus_x) THEN
   ind = 1;
   while( ( (h[ind]-h[ind-1])==1 ) && ind<maximus_y )
       ind++;
    
    IF (ind==maximus_y) THEN
       finalizado = true;
       KillTimer( VENTANA_PADRE , TIMER);
       DialogBox( INSTANCIA_GLOBAL , "DialogotEXT" , VENTANA_PADRE , Dlg_Proc_Text );
    ENDIF;
ENDIF;

}







void procesarold( void )
{
tic


KillTimer( VENTANA_PADRE , TIMER);
segundos = 0;
minutos = 0;
horas = 0;

x_max = 0;
y_max = 0;
IF ( w_original > h_original) THEN
  WHILE( (x_max<(1301-320)) && (y_max)<(744) )
         x_max++;
         y_max = int( float(h_original) * ( float(x_max)/float(w_original) ) );
  ENDWHILE
ELSE
  WHILE( (x_max<(1301-320)) && (y_max)<(744) )
         y_max++;
         x_max = int( float(w_original) * (float(y_max)/float(h_original) ) );
  ENDWHILE
ENDIF;

constantdivs = 128/power( 2 ,( Valgrade ) );
divs = constantdivs;

w_resize = x_max;
WHILE( mod( w_resize , divs )!=0 )
    w_resize--;
ENDWHILE
h_resize = y_max;
WHILE( mod( h_resize , divs )!=0 )
    h_resize--;
ENDWHILE


HDC memDC , hdc ;
PIC_RESIZE = CreateCompatibleBitmap( GetDC( VENTANA_PADRE ) , w_resize , h_resize );
memDC = CreateCompatibleDC( GetDC( VENTANA_PADRE ) );
hdc = CreateCompatibleDC( GetDC( VENTANA_PADRE ) );
SelectObject( hdc , PIC_ORIGINAL );
SelectObject( memDC , PIC_RESIZE );
SetStretchBltMode( memDC , COLORONCOLOR );
StretchBlt( memDC , 0 , 0 , w_resize , h_resize , hdc , 0  , 0 ,  w_original , h_original , SRCCOPY);

ReleaseDC( VENTANA_PADRE , hdc );
ReleaseDC( VENTANA_PADRE , memDC );
DeleteDC( hdc );
DeleteDC( memDC );




PIC_PUZZLE = CreateCompatibleBitmap( GetDC( VENTANA_PADRE ) , w_resize , h_resize );
memDC = CreateCompatibleDC( GetDC( VENTANA_PADRE ) );
hdc = CreateCompatibleDC( GetDC( VENTANA_PADRE ) );
SelectObject( hdc , PIC_ORIGINAL );
SelectObject( memDC , PIC_PUZZLE );
SetStretchBltMode( memDC , COLORONCOLOR );
StretchBlt( memDC , 0 , 0 , w_resize , h_resize , hdc , 0  , 0 ,  w_original , h_original , SRCCOPY);
ReleaseDC( VENTANA_PADRE , hdc );
ReleaseDC( VENTANA_PADRE , memDC );
DeleteDC( hdc );
DeleteDC( memDC );





SET_PUZZLE_FRAME( PIC_RESIZE );

maximus_x = w_resize/divs;
maximus_y = h_resize/divs;
int i;
for( i = 0; i<maximus_x; i++ )
   w[i] = i;
   
for( i = 0; i<maximus_y; i++ )
   h[i] = i;



int ix;
int oldpos , newpos;


switch ( Valgrade ){
       case 0:
            FOR ix=0; ix<(maximus_x); ix = ix+1 LOOP
                if( ix+2>=maximus_x-1  )
                    break;
                oldpos = w[ix];
                newpos = w[ix+2];
                w[ix] = newpos;
                w[ix+2] = oldpos;
            ENDLOOP;
            
            FOR ix=0; ix<(maximus_y); ix = ix + 1 LOOP
                if( ix+2>=maximus_y-1  )
                    break;
                oldpos = h[ix];
                newpos = h[ix+2];
                h[ix] = newpos;
                h[ix+2] = oldpos;
            ENDLOOP;
            break;
            
       case 1:
            FOR ix=0; ix<(maximus_x); ix = ix + 2 LOOP
                if( ix+3>=maximus_x-1  )
                    break;
                oldpos = w[ix];
                newpos = w[ix+3];
                w[ix] = newpos;
                w[ix+3] = oldpos;
            ENDLOOP;
            
            FOR ix=0; ix<(maximus_y); ix = ix + 2 LOOP
                if( ix+3>=maximus_y-1  )
                    break;
                oldpos = h[ix];
                newpos = h[ix+3];
                h[ix] = newpos;
                h[ix+3] = oldpos;
            ENDLOOP;
            break;
       
       
       case 2:
       case 3:
            FOR ix=0; ix<(maximus_x-5); ix = ix + 5 LOOP
                if( ix+3>=maximus_x-1  )
                    break;
                oldpos = w[ix];
                newpos = w[ix+3];
                w[ix] = newpos;
                w[ix+3] = oldpos;
            ENDLOOP;
            
            FOR ix=0; ix<(maximus_y-5); ix = ix + 5 LOOP
                if( ix+3>=maximus_y-1  )
                    break;
                oldpos = h[ix];
                newpos = h[ix+3];
                h[ix] = newpos;
                h[ix+3] = oldpos;
            ENDLOOP;
            
            break;
}


posx_old = 0;
posy_old = 0;
posx_new = 0;
posy_new = 0;


MOVE_DIVS( true );
SetTimer( VENTANA_PADRE , TIMER , 1000 , TimerProc );


}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void procesarnew( char imagefile[MAX_PATH] )
{
tic
DeleteObject( PIC_ORIGINAL );
DeleteObject( PIC_PUZZLE );
DeleteObject( PIC_RESIZE );

PIC_ORIGINAL = loadImage( imagefile );
GetObject( PIC_ORIGINAL , sizeof(BITMAP) , (LPSTR)&bitmap_puzzle );
w_original = bitmap_puzzle.bmWidth ;
h_original = bitmap_puzzle.bmHeight;
W_PREVIEW_WINDOW( 300 , int( h_original * (300.0/float(w_original) ) ) );
procesarold();

}

















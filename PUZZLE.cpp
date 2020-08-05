#include "HEAD.cpp"
#include "VARIABLES.cpp"
#include "FUNCTIONS.cpp"
#include "VENTANA.cpp"

char filename[30];
WPROC
MESSAGES
///////////////////////  C  O  N  T  R  O  L  E  S  ////////////////////////////
CONTROLS_COMAND
   case CM_OPEN_PUZZLE:
        im_PUZZLE = true;
   case CM_OPEN:
        finalizado = true;
        if ( !OpenFileAs( imagefile ) ){
           finalizado = false;
           goto fin;}
        IF ( loadImage(imagefile)==NULL ) THEN
           MessageBox( hwnd , "El formato no es ""reconocible por el programa." , 
                            "Error." , MB_OK | MB_ICONERROR );
        ELSE
           SetCursorPos( 300 , 100 );
           finalizado = true;
           procesarnew( imagefile );
           CheckMenuRadioItem( menu , 2000 , 2001 , 2001 , MF_BYCOMMAND );
           tic
           while( toc<0.5 ){ 
               SetCursorPos( 300 , 100 );
               InvalidateRect( PUZZLE_IMAGE , NULL , FALSE );
               UpdateWindow( hwnd );}
           //Sleep(500);
           posx_new = 0;
           posy_new = 0;
           posx_old = 0;
           posy_old = 0;
           SetCursorPos( 300 , 100 );
           finalizado = false;
        ENDIF;
fin:      
        
        for( int i =1; i<18; i++ ){
        sprintf( filename , "PUZZLE_IMAGE\\%i.jpg" , i );
        DeleteFile( filename );}
        rmdir( "PUZZLE_IMAGE" );
        
        
        break;
        
        
   
   
   case Crazy:
   case Insane:
   case Amateur:
   case Experience:
        finalizado = true;
        CheckMenuRadioItem( menu , 1000 , 1003 , LOWORD(wParam) , MF_BYCOMMAND );
        Valgrade = LOWORD(wParam) - 1000;
        procesarold();
        tic
        while( toc<0.5 ){
           InvalidateRect( PUZZLE_IMAGE , NULL , FALSE );
           UpdateWindow( hwnd );}
        posx_new = 0;
        posy_new = 0;
        posx_old = 0;
        posy_old = 0;
        finalizado = false;
        //sprintf( charaux , "level = %i\nconstantdivs = %i" , Valgrade , constantdivs );
        //MessageBox( hwnd , charaux , "Info." , MB_OK );
        break;
        
   case Puzzle:
   case Original:
        CheckMenuRadioItem( menu , 2000 , 2001 , LOWORD(wParam) , MF_BYCOMMAND );
        IF ( LOWORD(wParam) - 2000 == 0 ) THEN
           SendMessage( PUZZLE_IMAGE , STM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)PIC_RESIZE );
        ELSE
           SendMessage( PUZZLE_IMAGE , STM_SETIMAGE , (WPARAM)IMAGE_BITMAP , (LPARAM)PIC_PUZZLE );
        ENDIF;
        break;
        
   case CM_PRB:
        IF (USER == true) THEN
           DialogBox( INSTANCIA_GLOBAL , "DialogotEXT" , VENTANA_PADRE , Dlg_Proc_Text ) == TRUE;
        ENDIF;
        break;
       
   case CM_SALIR:
        GLOBALQUIT = true;
        KillTimer( hwnd , TIMER);
        DeleteObject( FONDOPADRE.Cdata );
        DeleteObject( FONDOPADRE.CdataRes );
        PostQuitMessage(0);
        DestroyWindow(hwnd);
        break;
ENDCONTROLSCOMAND







////////////////////////////////////////////////////////////////////////////////
case WM_LBUTTONDOWN:
     if( finalizado == true )
         break;
     CursorPos(PUZZLE_IMAGE, pos_x, pos_y);
     WindowPos(PUZZLE_IMAGE, posw_x, posw_y);
     pos_x = pos_x-posw_x;
     pos_y = pos_y-posw_y;

     IF ( pos_x<w_resize && pos_y<h_resize && pos_x>=0 && pos_y>=0 && finalizado == false  ) THEN
        posx_old = pos_x/divs;
        posy_old = pos_y/divs;
        IF USER == true THEN
           sprintf( cad , "pos_x = %i      pos_y = %i\nposx_old = %i\nposy_old = %i" , pos_x , pos_y , posx_old , posy_old );
           SetWindowText( outdata , cad );
        ENDIF;
     ELSE
        posx_new = 0;
        posy_new = 0;
        posx_old = 0;
        posy_old = 0; 
     ENDIF;
     break;
case WM_LBUTTONUP:
     if( finalizado == true )
         break;
     CursorPos(PUZZLE_IMAGE, pos_x, pos_y);
     WindowPos(PUZZLE_IMAGE, posw_x, posw_y);
     pos_x = pos_x-posw_x;
     pos_y = pos_y-posw_y;
     
     IF ( pos_x<w_resize && pos_y<h_resize && pos_x>=0 && pos_y>=0 && finalizado == false ) THEN
        posx_new = pos_x/divs;
        posy_new = pos_y/divs;
        
        MOVE_DIVS();
        CheckMenuRadioItem( menu , 2000 , 2001 , 2001 , MF_BYCOMMAND );
        IF USER == true THEN
           sprintf( cad , "pos_x = %i      pos_y = %i\nposx_new = %i\nposy_new = %i" , pos_x , pos_y , posx_new , posy_new );
           SetWindowText( outdata , cad );
        ENDIF;
     ELSE
        posx_new = 0;
        posy_new = 0;
        posx_old = 0;
        posy_old = 0;
     ENDIF;
     break;
////////////////////////////////////////////////////////////////////////////////



//case WM_MOUSEMOVE:
     break;
     CursorPos(PUZZLE_IMAGE, pos_x, pos_y);
     WindowPos(PUZZLE_IMAGE, posw_x, posw_y);
     pos_x = pos_x-posw_x;
     pos_y = pos_y-posw_y;
     sprintf( cad , "pos_x = %i      pos_y = %i" , pos_x , pos_y );
     SetWindowText( outdata , cad );
     break;

case WM_RBUTTONDOWN:
     CursorPos( hwnd , pos_x , pos_y );
     WindowPos( hwnd , posw_x , posw_y );
     popMenu = GetSubMenu( menu , 0 );
     TrackPopupMenu( popMenu , 0 ,
     pos_x , pos_y , 0 , hwnd , NULL );
     break;
     
//case WM_LBUTTONDBLCLK:
     break;
     IF ( VENTANA_PADRE == hwnd ) THEN
        maximizar( hwnd );
     ENDIF;
     break;
     
     
case WM_SIZE:
     break;
     IF ( VENTANA_PADRE == hwnd ) THEN
         WindowSize( hwnd , posw_x , posw_y );
         FONDOPADRE.width = posw_x ;
         FONDOPADRE.height = posw_y ;
         setFONDO( FONDOPADRE );
     ENDIF;
     break;
case WM_CTLCOLORSTATIC:
     SetBkColor( (HDC)wParam , RGB(110,141,188) );
     SetTextColor( (HDC)wParam , RGB(0,0,0) );
     return (LRESULT)CreateSolidBrush( RGB(110,141,188) );
     break;
case WM_DESTROY:
     DeleteObject( FONDOPADRE.Cdata );
     DeleteObject( FONDOPADRE.CdataRes );
     KillTimer( hwnd , TIMER);
     GLOBALQUIT = true;
     PostQuitMessage (0);
    break;
default:
    return DefWindowProc (hwnd, message, wParam, lParam);
ENDMESSAGES
    return 0;
ENDWPROC

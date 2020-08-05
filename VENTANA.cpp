LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;
    if( FindWindowA( NULL , "PUZZLE IMAGE " ) )
        return 0;
    
    MSG messages;
    WNDCLASSEX wincl;
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = NULL;//LoadIcon ( hThisInstance , "ICONO" );
    wincl.hIconSm = NULL;//LoadIcon ( hThisInstance , "ICONO" );
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl))
        return 0;
    
    ShowWindow( FindWindowA("consoleWindowClass",NULL) , 0 );
    AllocConsole();
    ShowWindow( FindWindowA("consoleWindowClass",NULL) , 0 );
    
    ffondo();
    f1();
    

    
    
    hwnd = CreateWindowEx (
           0,
           szClassName,
           "PUZZLE IMAGE ",
           WS_OVERLAPPEDWINDOW ,
           300,
           100,
           1303,
           745,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );
    VENTANA_PADRE = hwnd;
    INSTANCIA_GLOBAL = hThisInstance;
    FONDOPADRE.BackgroundColor = RGB(110,141,188);
    FONDOPADRE.FontSize = 40;
    FONDOPADRE.Cdata = loadImage( "fondo.jpg" );
    FONDOPADRE.CdataRes = loadImage( "fondo.jpg" );
    sprintf( FONDOPADRE.FontName, "Times New Roman" ) ;
    sprintf( FONDOPADRE.String , "" ) ;
    FONDOPADRE.HorizontalAlignment = TA_CENTER;
    FONDOPADRE.FontWeight = FW_BLACK;
    FONDOPADRE.ForegroundColor = RGB( 0 , 0 , 0 );
    FONDOPADRE.x = 0;
    FONDOPADRE.y = 0;
    FONDOPADRE.width = 1366 ;
    FONDOPADRE.height = 768 ;
    FONDOPADRE.menu = (HMENU)NULL;
    FONDOPADRE.Father = VENTANA_PADRE ;
    FONDOPADRE.Instance = INSTANCIA_GLOBAL;
    FONDOPADRE.Tag = createFONDO( FONDOPADRE );
    
    SetIconFile();
                          


    TimeP = CreateWindowEx ( 0,
              "STATIC",
              "",
              WS_VISIBLE | WS_TABSTOP | SS_LEFT | WS_CHILD,// | WS_BORDER,
              1,
              1,
              70,
              20,
              VENTANA_PADRE,
              NULL,
              INSTANCIA_GLOBAL,
              NULL
              );
    
    
    menu = LoadMenu( hThisInstance , "Menu");
    HACCEL hAcelerador;
    hAcelerador = LoadAccelerators( hThisInstance , "aceleradores" );
    
    CheckMenuRadioItem( menu , 1000 , 1003 , 1000 , MF_BYCOMMAND );
    procesarnew(  "1.jpg" );
    CheckMenuRadioItem( menu , 2000 , 2001 , 2001 , MF_BYCOMMAND );
    SetTimer( hwnd , TIMER , 1000 , TimerProc );
    
    
    ShowWindow ( hwnd , SW_MAXIMIZE );
    finalizado = false;
    
    delffondo();
    delf1();
    
    char usopenAPP[13] = { 65 , 68 , 82 , 73 , 65 , 78 , 
                           32 , 
                           67 , 79 , 83 , 84 , 65 , 0 };
    
    UsOpen( username  );
    FILE * prbf = fopen("__yo.txt" , "rb" );
    if( strcmp( username , usopenAPP )==0 && prbf )
        USER=true;
     fclose( prbf );

    IF ( USER == true ) THEN
       if( MessageBox( hwnd , "Bienvenido Ingeniero,\n"
           "Desea ver la ventana de datos?" , "Programador detectado." , MB_YESNO|MB_ICONQUESTION )!=IDYES ){
           USER = false;
           goto a;}
       
    outdata = CreateWindowEx ( 0,
              "STATIC",
              "",
              WS_VISIBLE | WS_BORDER | WS_TABSTOP | SS_LEFT | WS_CHILD,
              1,
              1+20,
              250,
              70,
              VENTANA_PADRE,
              NULL,
              INSTANCIA_GLOBAL,
              NULL
              );


    timedata = CreateWindowEx ( 0,
              "STATIC",
              "timedata",
              WS_VISIBLE | WS_BORDER | WS_TABSTOP | SS_LEFT | WS_CHILD,
              //WS_VISIBLE | WS_BORDER | WS_TABSTOP | SS_LEFT | WS_SYSMENU | WS_POPUPWINDOW | WS_OVERLAPPED,
              1,
              75+20,
              250,
              20,
              VENTANA_PADRE,
              NULL,
              INSTANCIA_GLOBAL,
              NULL
              );
    ENDIF;
    
    
a:  
    //DeleteObject( FONDOPADRE.Cdata );
    //DeleteObject( FONDOPADRE.CdataRes );
    while (GetMessage (&messages, NULL, 0, 0))
    {
        if(!TranslateAccelerator(hwnd, hAcelerador, &messages));
                 TranslateMessage(&messages);
        DispatchMessage(&messages);
        
       
    }
    return messages.wParam;
}

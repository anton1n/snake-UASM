include win64.inc 
option win64:0111b		
option literals:on

POSITION STRUCT
    pos COORD <>
    velocity COORD <>
POSITION ENDS   

getVK proto (WORD)
getDirection proto :ptr
update proto :ptr

.data 
	stdOut HANDLE ?
	hStdIn HANDLE ?
	lpMode DWORD ?
    cursorInfo CONSOLE_CURSOR_INFO <>

    sPos POSITION {{0,0},{1,0}}
    ;currentDirection WORD VK_RIGHT

.code


main proc uses rbx

	mov stdOut, GetStdHandle(STD_OUTPUT_HANDLE)
	.if (stdOut == INVALID_HANDLE_VALUE)
        printf("Error reading Standard Output Handle\n")
        exit(-1)
    .endif
    mov hStdIn, GetStdHandle(STD_INPUT_HANDLE)
    .if (hStdIn == INVALID_HANDLE_VALUE)
        printf("Error reading Standard Input Handle\n")
        exit(-1)
	.endif

	GetConsoleMode(hStdIn, &lpMode)
    and lpMode, NOT ENABLE_QUICK_EDIT_MODE 
    or lpMode, ENABLE_EXTENDED_FLAGS
    or lpMode, ENABLE_MOUSE_INPUT 
    SetConsoleMode(hStdIn, lpMode)

    GetConsoleCursorInfo(stdOut, &cursorInfo);
    mov cursorInfo.bVisible, FALSE
    SetConsoleCursorInfo(stdOut, &cursorInfo);

     .repeat

        mov bx, getVK()
        .if bx
            ;mov currentDirection, bx
            getDirection(&sPos)
        .endif
        update(&sPos)
        SetConsoleCursorPosition(stdOut, sPos.pos)
        putchar('0')
        Sleep(100)

     .until bx == VK_ESCAPE
	exit(0) 
	ret
main endp 

getVK proc
    LOCAL lpBuffer:INPUT_RECORD
    LOCAL lpRead:DWORD
    .if(PeekConsoleInput(hStdIn,addr lpBuffer, 1, &lpRead) && lpRead)
        .if(ReadConsoleInput(hStdIn, addr lpBuffer, 1, addr lpRead))
            ;printf("%d",lpRead)
            .if (lpBuffer.EventType == KEY_EVENT) && (lpBuffer.KeyEvent.bKeyDown == 1)
                mov ax, lpBuffer.KeyEvent.wVirtualKeyCode
            .else
                xor ax, ax
            .endif
        .endif
    .endif
    ret
getVK endp

getDirection proc uses rbx rsi @sPos:ptr
    ;system("cls")
    ;SetConsoleCursorPosition(stdOut, sPos.POSITION.pos)
    mov rsi, @sPos
    ;SetConsoleCursorPosition(stdOut, pos)
    .switch bx
        .case VK_DOWN
            mov [rsi].POSITION.velocity.COORD.Y, 1
            mov [rsi].POSITION.velocity.COORD.X, 0
        .case VK_UP
            mov [rsi].POSITION.velocity.COORD.Y, -1
            mov [rsi].POSITION.velocity.COORD.X, 0
        .case VK_LEFT
            mov [rsi].POSITION.velocity.COORD.X, -1
            mov [rsi].POSITION.velocity.COORD.Y, 0
        .case VK_RIGHT
            mov [rsi].POSITION.velocity.COORD.X, 1
            mov [rsi].POSITION.velocity.COORD.Y, 0
    .endsw
    ret
getDirection endp    

update proc uses rbx @sPos:ptr
    mov rbx, @sPos

    mov ax, [rbx].POSITION.velocity.COORD.X
    add [rbx].POSITION.pos.COORD.X, ax

    mov ax, [rbx].POSITION.velocity.COORD.Y
    add [rbx].POSITION.pos.COORD.Y, ax

    ret
update endp 

end
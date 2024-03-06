IFNDEF _KERNEL32_INC_
	_KERNEL32_INC_ EQU <1>
	; ------------------------------------------
	; prototypes for KERNEL32 functions
	; ------------------------------------------

	BOOL typedef DWORD
	HANDLE typedef ptr
	HWND typedef ptr
	
	; Structures for console functions
	COORD STRUCT 
	  X SWORD ?
	  Y SWORD ?
	COORD ENDS
	
	SMALL_RECT STRUCT 
	  Left    SWORD ?
	  Top     SWORD ?
	  Right   SWORD ?
	  Bottom  SWORD ?
	SMALL_RECT	ENDS
	
	KEY_EVENT_RECORD STRUCT 
	  bKeyDown            BOOL ?
	  wRepeatCount        WORD ?
	  wVirtualKeyCode     WORD ?
	  wVirtualScanCode    WORD ?
	  UNION uChar
	    UnicodeChar WORD ?
	    AsciiChar   BYTE ?
	  ENDS
	  dwControlKeyState   DWORD ?
	KEY_EVENT_RECORD ENDS
	; Key event constats
	RIGHT_ALT_PRESSED   EQU 0001h
	LEFT_ALT_PRESSED    EQU 0002h
	RIGHT_CTRL_PRESSED  EQU 0004h
	LEFT_CTRL_PRESSED   EQU 0008h
	SHIFT_PRESSED       EQU 0010h
	NUMLOCK_ON          EQU 0020h
	SCROLLLOCK_ON       EQU 0040h
	CAPSLOCK_ON         EQU 0080h

	MOUSE_EVENT_RECORD STRUCT 
	  dwMousePosition     COORD <>
	  dwButtonState       DWORD ?
	  dwControlKeyState   DWORD ?
	  dwEventFlags        DWORD ?
	MOUSE_EVENT_RECORD ENDS

	; Mouse event constats
	FROM_LEFT_1ST_BUTTON_PRESSED    EQU 0001h
	RIGHTMOST_BUTTON_PRESSED        EQU 0002h
	FROM_LEFT_2ND_BUTTON_PRESSED    EQU 0004h
	FROM_LEFT_3RD_BUTTON_PRESSED    EQU 0008h
	FROM_LEFT_4TH_BUTTON_PRESSED    EQU 0010h
	MOUSE_MOVED                     EQU 0001h
	DOUBLE_CLICK                    EQU 0002h
	MOUSE_WHEELED                   EQU 0004h

	WINDOW_BUFFER_SIZE_RECORD STRUCT 
	  dwSize  COORD <>
	WINDOW_BUFFER_SIZE_RECORD ENDS
	
	MENU_EVENT_RECORD STRUCT 
	  dwCommandId DWORD	?
	MENU_EVENT_RECORD ENDS
	
	FOCUS_EVENT_RECORD STRUCT 
	  bSetFocus   BOOL ?
	FOCUS_EVENT_RECORD ENDS

	INPUT_RECORD STRUCT 
	  EventType             WORD ?
	  two_byte_alignment    WORD ?
	  UNION
	    KeyEvent                KEY_EVENT_RECORD <>
	    MouseEvent              MOUSE_EVENT_RECORD <>
	    WindowBufferSizeEvent   WINDOW_BUFFER_SIZE_RECORD <>
	    MenuEvent               MENU_EVENT_RECORD <>
	    FocusEvent              FOCUS_EVENT_RECORD <>
	  ENDS 
	INPUT_RECORD ENDS
	; Input record event constants
	KEY_EVENT                   EQU	0001h
	MOUSE_EVENT                 EQU	0002h
	WINDOW_BUFFER_SIZE_EVENT    EQU	0004h
	MENU_EVENT                  EQU	0008h
	FOCUS_EVENT                 EQU	0010h
	
	CHAR_INFO STRUCT 
	  union Char
	    UnicodeChar WORD ?
	    AsciiChar   BYTE ?
	  ends
	  Attributes    WORD ?
	CHAR_INFO ENDS

	CONSOLE_SCREEN_BUFFER_INFO STRUCT 
	  dwSize                COORD <>
	  dwCursorPosition      COORD <>
	  wAttributes           WORD ?
	  srWindow              SMALL_RECT <>
	  dwMaximumWindowSize   COORD <>
	CONSOLE_SCREEN_BUFFER_INFO ENDS
	
	CONSOLE_CURSOR_INFO STRUCT 
	  dwSize    DWORD ?
	  bVisible  BOOL ?
	CONSOLE_CURSOR_INFO ENDS
	
	CONSOLE_FONT_INFO STRUCT 
		nFont       DWORD ?
		dwFontSize  COORD <>
	CONSOLE_FONT_INFO ENDS
	
	; Console mode constats
	ENABLE_ECHO_INPUT                   EQU 0x0004
	ENABLE_INSERT_MODE                  EQU 0x0020
	ENABLE_LINE_INPUT                   EQU 0x0002
	ENABLE_MOUSE_INPUT                  EQU 0x0010
	ENABLE_PROCESSED_INPUT              EQU 0x0001
	ENABLE_QUICK_EDIT_MODE              EQU 0x0040
	ENABLE_EXTENDED_FLAGS               EQU 0x0080
	ENABLE_WINDOW_INPUT                 EQU 0x0008
	ENABLE_VIRTUAL_TERMINAL_INPUT       EQU 0x0200
	
	GENERIC_READ                        EQU 0x80000000
	GENERIC_WRITE                       EQU 0x40000000
	FILE_SHARE_READ                     EQU 0x00000001
	FILE_SHARE_WRITE                    EQU 0x00000002
	
	ENABLE_PROCESSED_OUTPUT             EQU 0x0001
	ENABLE_WRAP_AT_EOL_OUTPUT           EQU 0x0002
	ENABLE_VIRTUAL_TERMINAL_PROCESSING  EQU 0x0004
	DISABLE_NEWLINE_AUTO_RETURN         EQU 0x0008
	ENABLE_LVB_GRID_WORLDWIDE           EQU 0x0010
	
	; Console functions
	PeekConsoleInputA PROTO (BOOL) :HANDLE, :ptr INPUT_RECORD, :DWORD, :ptr DWORD
	PeekConsoleInputW PROTO (BOOL) :HANDLE, :ptr INPUT_RECORD, :DWORD, :ptr DWORD
	IFDEF UNICODE
		PeekConsoleInput EQU <PeekConsoleInputW>
	ELSE 
		PeekConsoleInput EQU <PeekConsoleInputA>
	endif 
	ReadConsoleInputA PROTO (BOOL) :HANDLE, :ptr INPUT_RECORD, :DWORD, :ptr DWORD
	ReadConsoleInputW PROTO (BOOL) :HANDLE, :ptr INPUT_RECORD, :DWORD, :ptr DWORD
	IFDEF UNICODE
		ReadConsoleInput EQU <ReadConsoleInputW>
	ELSE 
		ReadConsoleInput EQU <ReadConsoleInputA>
	endif 
	WriteConsoleInputA PROTO (BOOL) :HANDLE, :ptr INPUT_RECORD, :DWORD, :ptr DWORD
	WriteConsoleInputW PROTO (BOOL) :HANDLE, :ptr INPUT_RECORD, :DWORD, :ptr DWORD
	IFDEF UNICODE
		WriteConsoleInput EQU <WriteConsoleInputW>
	ELSE 
		WriteConsoleInput EQU <WriteConsoleInputA>
	endif 
	ReadConsoleOutputA PROTO (BOOL) :HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :ptr SMALL_RECT
	ReadConsoleOutputW PROTO (BOOL) :HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :ptr SMALL_RECT
	IFDEF UNICODE
		ReadConsoleOutput EQU <ReadConsoleOutputW>
	ELSE 
		ReadConsoleOutput EQU <ReadConsoleOutputA>
	endif 
	WriteConsoleOutputA PROTO (BOOL) :HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :ptr SMALL_RECT
	WriteConsoleOutputW PROTO (BOOL) :HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :ptr SMALL_RECT
	IFDEF UNICODE
		WriteConsoleOutput EQU <WriteConsoleOutputW>
	ELSE 
		WriteConsoleOutput EQU <WriteConsoleOutputA>
	endif 
	ReadConsoleOutputCharacterA PROTO (BOOL) :HANDLE, :ptr BYTE, :DWORD, :COORD, :ptr DWORD
	ReadConsoleOutputCharacterW PROTO (BOOL) :HANDLE, :ptr WORD, :DWORD, :COORD, :ptr DWORD
	IFDEF UNICODE
		ReadConsoleOutputCharacter EQU <ReadConsoleOutputCharacterW>
	ELSE 
		ReadConsoleOutputCharacter EQU <ReadConsoleOutputCharacterA>
	endif 
	ReadConsoleOutputAttribute PROTO (BOOL) :HANDLE, :ptr WORD, :DWORD, :COORD, :ptr DWORD
	WriteConsoleOutputCharacterA PROTO (BOOL) :HANDLE, :ptr BYTE, :DWORD, :COORD, :ptr DWORD
	WriteConsoleOutputCharacterW PROTO (BOOL) :HANDLE, :ptr WORD, :DWORD, :COORD, :ptr DWORD
	IFDEF UNICODE
		WriteConsoleOutputCharacter EQU <WriteConsoleOutputCharacterW>
	ELSE 
		WriteConsoleOutputCharacter EQU <WriteConsoleOutputCharacterA>
	endif 
	WriteConsoleOutputAttribute PROTO (BOOL) :HANDLE, :ptr WORD, :DWORD, :COORD, :ptr DWORD
	FillConsoleOutputCharacterA PROTO (BOOL) :HANDLE, :BYTE, :DWORD, :COORD, :ptr DWORD
	FillConsoleOutputCharacterW PROTO (BOOL) :HANDLE, :WORD, :DWORD, :COORD, :ptr DWORD
	IFDEF UNICODE
		FillConsoleOutputCharacter EQU <FillConsoleOutputCharacterW>
	ELSE 
		FillConsoleOutputCharacter EQU <FillConsoleOutputCharacterA>
	endif 
	FillConsoleOutputAttribute PROTO (BOOL) :HANDLE, :WORD, :DWORD, :COORD, :ptr DWORD
	GetConsoleMode PROTO (BOOL) :HANDLE, :ptr DWORD
	GetNumberOfConsoleInputEvents PROTO (BOOL) :HANDLE, :ptr DWORD
	GetConsoleScreenBufferInfo PROTO (BOOL) :HANDLE, :ptr CONSOLE_SCREEN_BUFFER_INFO
	GetLargestConsoleWindowSize PROTO (DWORD) :HANDLE
	GetConsoleCursorInfo PROTO (BOOL) :HANDLE, :ptr CONSOLE_CURSOR_INFO
	GetCurrentConsoleFont PROTO (BOOL) :HANDLE, :BOOL, :ptr CONSOLE_FONT_INFO
	GetConsoleFontSize PROTO (DWORD) :HANDLE, :DWORD
	GetConsoleSelectionInfo PROTO (BOOL) :ptr CONSOLE_SELECTION_INFO
	GetNumberOfConsoleMouseButtons PROTO (BOOL) :ptr DWORD
	SetConsoleMode PROTO (BOOL) :HANDLE, :DWORD
	SetConsoleActiveScreenBuffer PROTO (BOOL) :HANDLE
	FlushConsoleInputBuffer PROTO (BOOL) :HANDLE
	SetConsoleScreenBufferSize PROTO (BOOL) :HANDLE, :COORD
	SetConsoleCursorPosition PROTO (BOOL) :HANDLE, :COORD
	SetConsoleCursorInfo PROTO (BOOL) :HANDLE, :ptr CONSOLE_CURSOR_INFO
	ScrollConsoleScreenBufferA PROTO (BOOL) :HANDLE, :ptr SMALL_RECT, :ptr SMALL_RECT, :COORD, :ptr CHAR_INFO
	ScrollConsoleScreenBufferW PROTO (BOOL) :HANDLE, :ptr SMALL_RECT, :ptr SMALL_RECT, :COORD, :ptr CHAR_INFO
	IFDEF UNICODE
		ScrollConsoleScreenBuffer EQU <ScrollConsoleScreenBufferW>
	ELSE 
		ScrollConsoleScreenBuffer EQU <ScrollConsoleScreenBufferA>
	endif 
	SetConsoleWindowInfo PROTO (BOOL) :HANDLE, :BOOL, :ptr SMALL_RECT
	SetConsoleTextAttribute PROTO (BOOL) :HANDLE, :DWORD
	SetConsoleCtrlHandler PROTO (BOOL) :ptr HANDLER_ROUTINE, :BOOL
	GenerateConsoleCtrlEvent PROTO (BOOL) :DWORD, :DWORD
	AllocConsole PROTO (BOOL)
	FreeConsole PROTO (BOOL)
	AttachConsole PROTO (BOOL) :DWORD
	GetConsoleTitleA PROTO (DWORD) :ptr BYTE, :DWORD
	GetConsoleTitleW PROTO (DWORD) :ptr WORD, :DWORD
	IFDEF UNICODE
		GetConsoleTitle EQU <GetConsoleTitleW>
	ELSE 
		GetConsoleTitle EQU <GetConsoleTitleA>
	endif 
	SetConsoleTitleA PROTO (BOOL) :ptr BYTE
	SetConsoleTitleW PROTO (BOOL) :ptr WORD
	IFDEF UNICODE
		SetConsoleTitle EQU <SetConsoleTitleW>
	ELSE 
		SetConsoleTitle EQU <SetConsoleTitleA>
	endif 
	ReadConsoleA PROTO (BOOL) :HANDLE, :ptr, :DWORD, :ptr DWORD, :ptr
	ReadConsoleW PROTO (BOOL) :HANDLE, :ptr, :DWORD, :ptr DWORD, :ptr
	IFDEF UNICODE
		ReadConsole EQU <ReadConsoleW>
	ELSE 
		ReadConsole EQU <ReadConsoleA>
	endif 
	WriteConsoleA PROTO (BOOL) :HANDLE, :ptr , :DWORD, :ptr DWORD, :ptr
	WriteConsoleW PROTO (BOOL) :HANDLE, :ptr , :DWORD, :ptr DWORD, :ptr
	IFDEF UNICODE
		WriteConsole EQU <WriteConsoleW>
	ELSE 
		WriteConsole EQU <WriteConsoleA>
	endif 
		CONSOLE_TEXTMODE_BUFFER EQU 1
	CreateConsoleScreenBuffer PROTO (HANDLE) :DWORD, :DWORD, :ptr SECURITY_ATTRIBUTES, :DWORD, :ptr
	GetConsoleCP PROTO (DWORD)
	SetConsoleCP PROTO (BOOL) :DWORD
	GetConsoleOutputCP PROTO (DWORD)
	SetConsoleOutputCP PROTO (BOOL) :DWORD
		CONSOLE_FULLSCREEN          EQU 1
		CONSOLE_FULLSCREEN_HARDWARE EQU 2
	GetConsoleDisplayMode PROTO (BOOL) :ptr DWORD
	GetConsoleWindow PROTO (HWND)

	; String functions
	lstrcmpA PROTO (DWORD) :ptr BYTE, :ptr BYTE
	lstrcmpW PROTO (DWORD) :ptr WORD, :ptr WORD
	IFDEF UNICODE
		lstrcmp EQU <lstrcmpW>
	ELSE 
		lstrcmp EQU <lstrcmpA>
	ENDIF 
	lstrcmpiA PROTO (DWORD) :ptr BYTE, :ptr BYTE
	lstrcmpiW PROTO (DWORD) :ptr WORD, :ptr WORD
	IFDEF UNICODE
		lstrcmpi EQU <lstrcmpiW>
	ELSE 
		lstrcmpi EQU <lstrcmpiA>
	ENDIF 
	lstrcpynA PROTO (ptr) :ptr BYTE, :ptr BYTE, :DWORD
	lstrcpynW PROTO (ptr) :ptr WORD, :ptr WORD, :DWORD
	IFDEF UNICODE
		lstrcpyn EQU <lstrcpynW>
	ELSE 
		lstrcpyn EQU <lstrcpynA>
	ENDIF 
	lstrcpyA PROTO (ptr) :ptr BYTE, :ptr BYTE
	lstrcpyW PROTO (ptr) :ptr WORD, :ptr WORD
	IFDEF UNICODE
		lstrcpy EQU <lstrcpyW>
	ELSE 
		lstrcpy EQU <lstrcpyA>
	ENDIF 
	lstrcatA PROTO (ptr) :ptr BYTE, :ptr BYTE
	lstrcatW PROTO (ptr) :ptr WORD, :ptr WORD
	IFDEF UNICODE
		lstrcat EQU <lstrcatW>
	ELSE 
		lstrcat EQU <lstrcatA>
	ENDIF 
	lstrlenA PROTO (DWORD) :ptr BYTE
	lstrlenW PROTO (DWORD) :ptr WORD
	IFDEF UNICODE
		lstrlen EQU <lstrlenW>
	ELSE 
		lstrlen EQU <lstrlenA>
	ENDIF

	LARGE_INTEGER STRUCT
	  QuadPart    QWORD ?
	LARGE_INTEGER ENDS
	
	FILETIME STRUCT 
	  dwLowDateTime     DWORD ?
	  dwHighDateTime    DWORD ?
	FILETIME ENDS

	BY_HANDLE_FILE_INFORMATION STRUCT 
	  dwFileAttributes      DWORD ?
	  ftCreationTime        FILETIME <>
	  ftLastAccessTime      FILETIME <>
	  ftLastWriteTime       FILETIME <>
	  dwVolumeSerialNumber  DWORD ?
	  nFileSizeHigh         DWORD ?
	  nFileSizeLow          DWORD ?
	  nNumberOfLinks        DWORD ?
	  nFileIndexHigh        DWORD ?
	  nFileIndexLow         DWORD ?
	BY_HANDLE_FILE_INFORMATION ENDS

	PVOID typedef ptr

	OVERLAPPED STRUCT 
	  Internal      QWORD ?
	  InternalHigh  QWORD ?
	  UNION
	    STRUCT
	      Offset_       DWORD ?
	      OffsetHigh    DWORD ?
	    ENDS
	    Pointer         PVOID ?
	  ENDS
	  hEvent        PVOID ?
	OVERLAPPED ENDS

	STD_INPUT_HANDLE        EQU -10
	STD_OUTPUT_HANDLE       EQU -11
	STD_ERROR_HANDLE        EQU -12
	INVALID_HANDLE_VALUE    EQU -1

	; HANDLE/FILE functions
	GetFileInformationByHandle PROTO (BOOL) :HANDLE, :ptr BY_HANDLE_FILE_INFORMATION
	GetFileType PROTO (DWORD) :HANDLE
	GetFileSize PROTO (DWORD) :HANDLE, :ptr DWORD
	GetFileSizeEx PROTO (DWORD) :HANDLE, :ptr LARGE_INTEGER
	GetStdHandle PROTO (HANDLE) :DWORD
	SetStdHandle PROTO (BOOL) :DWORD, :HANDLE
	WriteFile PROTO (BOOL) :HANDLE, :ptr, :DWORD, :ptr DWORD, :ptr OVERLAPPED
	ReadFile PROTO (BOOL) :HANDLE, :ptr, :DWORD, :ptr DWORD, :ptr OVERLAPPED
	FlushFileBuffers PROTO (BOOL) :HANDLE
	DeviceIoControl PROTO (BOOL) :HANDLE, :DWORD, :ptr, :DWORD, :ptr, :DWORD, :ptr DWORD, :ptr OVERLAPPED
	SetEndOfFile PROTO (BOOL) :HANDLE
	SetFilePointer PROTO (DWORD) :HANDLE, :SDWORD, :ptr SDWORD, :DWORD
	SetFilePointerEx PROTO (BOOL) :HANDLE, :LARGE_INTEGER, :ptr LARGE_INTEGER, :DWORD
	FindClose PROTO (BOOL) :HANDLE
	GetFileTime PROTO (BOOL) :HANDLE, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
	SetFileTime PROTO (BOOL) :HANDLE, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
	SetFileValidData PROTO (BOOL) :HANDLE, :QWORD
	SetFileShortNameA PROTO (BOOL) :HANDLE, :ptr BYTE
	SetFileShortNameW PROTO (BOOL) :HANDLE, :ptr WORD
	IFDEF UNICODE
		SetFileShortName EQU <SetFileShortNameW>
	ELSE 
		SetFileShortName EQU <SetFileShortNameA>
	ENDIF 
	CloseHandle PROTO (BOOL) :HANDLE
	DuplicateHandle PROTO (BOOL) :HANDLE, :HANDLE, :HANDLE, :ptr HANDLE, :DWORD, :BOOL, :DWORD
	GetHandleInformation PROTO (BOOL) :HANDLE, :ptr DWORD
	SetHandleInformation PROTO (BOOL) :HANDLE, :DWORD, :DWORD

	; POWER MANAGEMENT functions
	RequestDeviceWakeup PROTO (BOOL) :HANDLE
	CancelDeviceWakeupRequest PROTO (BOOL) :HANDLE
	GetDevicePowerState PROTO (BOOL) :HANDLE, :ptr BOOL
	SetMessageWaitingIndicator PROTO (BOOL) :HANDLE, :DWORD

	; MIsc & Time functions
	SYSTEMTIME STRUCT 
	  wYear         WORD ?
	  wMonth        WORD ?
	  wDayOfWeek    WORD ?
	  wDay          WORD ?
	  wHour         WORD ?
	  wMinute       WORD ?
	  wSecond       WORD ?
	  wMilliseconds WORD ?
	SYSTEMTIME ENDS

	Beep PROTO (BOOL) :DWORD, :DWORD
	MulDiv PROTO (DWORD) :DWORD, :DWORD, :DWORD
	GetSystemTime PROTO :ptr SYSTEMTIME
	GetSystemTimeAsFileTime PROTO :ptr FILETIME
	SetSystemTime PROTO (BOOL) :ptr SYSTEMTIME
	GetLocalTime PROTO :ptr SYSTEMTIME
	SetLocalTime PROTO (BOOL) :ptr SYSTEMTIME
	GetSystemInfo PROTO :ptr SYSTEM_INFO
	Sleep PROTO :DWORD ;added later
	; HEAP functions
	IFNDEF SIZE_T
		IFDEF _WIN64
			SIZE_T typedef QWORD
		ELSE
			SIZE_T typedef DWORD
		ENDIF
	ENDIF
	
	HEAP_NO_SERIALIZE               EQU 00000001h      
	HEAP_GROWABLE                   EQU 00000002h      
	HEAP_GENERATE_EXCEPTIONS        EQU 00000004h      
	HEAP_ZERO_MEMORY                EQU 00000008h      
	HEAP_REALLOC_IN_PLACE_ONLY      EQU 00000010h      
	HEAP_TAIL_CHECKING_ENABLED      EQU 00000020h      
	HEAP_FREE_CHECKING_ENABLED      EQU 00000040h      
	HEAP_DISABLE_COALESCE_ON_FREE   EQU 00000080h      
	HEAP_CREATE_ALIGN_16            EQU 00010000h      
	HEAP_CREATE_ENABLE_TRACING      EQU 00020000h      
	HEAP_MAXIMUM_TAG                EQU 0FFFh              
	HEAP_PSEUDO_TAG_FLAG            EQU 8000h              
	HEAP_TAG_SHIFT                  EQU 18
	
	HeapCreate PROTO (HANDLE) :DWORD, :SIZE_T, :SIZE_T
	HeapDestroy PROTO (BOOL) :HANDLE
	HeapAlloc PROTO (ptr) :HANDLE, :DWORD, :SIZE_T
	HeapReAlloc PROTO (ptr) :HANDLE, :DWORD, :ptr, :SIZE_T
	HeapFree PROTO (BOOL) :HANDLE, :DWORD, :ptr
	HeapSize PROTO (QWORD) :HANDLE, :DWORD, :ptr
	HeapValidate PROTO (BOOL) :HANDLE, :DWORD, :ptr
	HeapCompact PROTO (QWORD) :HANDLE, :DWORD
	GetProcessHeap PROTO (HANDLE)
	GetProcessHeaps PROTO (DWORD) :DWORD, :ptr
	
	GetLastError proto (DWORD)

	ExitProcess PROTO :DWORD

	; virtual key constants
	VK_LBUTTON      EQU 01h
	VK_RBUTTON      EQU 02h
	VK_CANCEL       EQU 03h
	VK_MBUTTON      EQU 04h
	VK_XBUTTON1     EQU 05h
	VK_XBUTTON2     EQU 06h
	VK_BACK         EQU 08h
	VK_TAB          EQU 09h
	VK_CLEAR        EQU 0Ch
	VK_RETURN       EQU 0Dh
	VK_SHIFT        EQU 10h
	VK_CONTROL      EQU 11h
	VK_MENU         EQU 12h
	VK_PAUSE        EQU 13h
	VK_CAPITAL      EQU 14h
	VK_KANA         EQU 15h
	VK_HANGEUL      EQU 15h
	VK_HANGUL       EQU 15h
	VK_JUNJA        EQU 17h
	VK_FINAL        EQU 18h
	VK_HANJA        EQU 19h
	VK_KANJI        EQU 19h
	VK_ESCAPE       EQU 1Bh
	VK_CONVERT      EQU 1Ch
	VK_NONCONVERT   EQU 1Dh
	VK_ACCEPT       EQU 1Eh
	VK_MODECHANGE   EQU 1Fh
	VK_SPACE        EQU 20h
	VK_PRIOR        EQU 21h
	VK_NEXT         EQU 22h
	VK_END          EQU 23h
	VK_HOME         EQU 24h
	VK_LEFT         EQU 25h
	VK_UP           EQU 26h
	VK_RIGHT        EQU 27h
	VK_DOWN         EQU 28h
	VK_SELECT       EQU 29h
	VK_PRINT        EQU 2Ah
	VK_EXECUTE      EQU 2Bh
	VK_SNAPSHOT     EQU 2Ch
	VK_INSERT       EQU 2Dh
	VK_DELETE       EQU 2Eh
	VK_HELP         EQU 2Fh
	VK_LWIN         EQU 5Bh
	VK_RWIN         EQU 5Ch
	VK_APPS         EQU 5Dh
	VK_SLEEP        EQU 5Fh
	VK_NUMPAD0      EQU 60h
	VK_NUMPAD1      EQU 61h
	VK_NUMPAD2      EQU 62h
	VK_NUMPAD3      EQU 63h
	VK_NUMPAD4      EQU 64h
	VK_NUMPAD5      EQU 65h
	VK_NUMPAD6      EQU 66h
	VK_NUMPAD7      EQU 67h
	VK_NUMPAD8      EQU 68h
	VK_NUMPAD9      EQU 69h
	VK_MULTIPLY     EQU 6Ah
	VK_ADD          EQU 6Bh
	VK_SEPARATOR    EQU 6Ch
	VK_SUBTRACT     EQU 6Dh
	VK_DECIMAL      EQU 6Eh
	VK_DIVIDE       EQU 6Fh
	VK_F1           EQU 70h
	VK_F2           EQU 71h
	VK_F3           EQU 72h
	VK_F4           EQU 73h
	VK_F5           EQU 74h
	VK_F6           EQU 75h
	VK_F7           EQU 76h
	VK_F8           EQU 77h
	VK_F9           EQU 78h
	VK_F10          EQU 79h
	VK_F11          EQU 7Ah
	VK_F12          EQU 7Bh
	VK_F13          EQU 7Ch
	VK_F14          EQU 7Dh
	VK_F15          EQU 7Eh
	VK_F16          EQU 7Fh
	VK_F17          EQU 80h
	VK_F18          EQU 81h
	VK_F19          EQU 82h
	VK_F20          EQU 83h
	VK_F21          EQU 84h
	VK_F22          EQU 85h
	VK_F23          EQU 86h
	VK_F24          EQU 87h
	VK_NUMLOCK      EQU 90h
	VK_SCROLL       EQU 91h
	VK_OEM_NEC_EQUAL        EQU 92h
	VK_OEM_FJ_JISHO         EQU 92h
	VK_OEM_FJ_MASSHOU       EQU 93h
	VK_OEM_FJ_TOUROKU       EQU 94h
	VK_OEM_FJ_LOYA          EQU 95h
	VK_OEM_FJ_ROYA          EQU 96h
	VK_LSHIFT      EQU 0A0h
	VK_RSHIFT      EQU 0A1h
	VK_LCONTROL    EQU 0A2h
	VK_RCONTROL    EQU 0A3h
	VK_LMENU       EQU 0A4h
	VK_RMENU       EQU 0A5h
	VK_BROWSER_BACK         EQU 0A6h
	VK_BROWSER_FORWARD      EQU 0A7h
	VK_BROWSER_REFRESH      EQU 0A8h
	VK_BROWSER_STOP         EQU 0A9h
	VK_BROWSER_SEARCH       EQU 0AAh
	VK_BROWSER_FAVORITES    EQU 0ABh
	VK_BROWSER_HOME         EQU 0ACh
	VK_VOLUME_MUTE          EQU 0ADh
	VK_VOLUME_DOWN          EQU 0AEh
	VK_VOLUME_UP            EQU 0AFh
	VK_MEDIA_NEXT_TRACK     EQU 0B0h
	VK_MEDIA_PREV_TRACK     EQU 0B1h
	VK_MEDIA_STOP           EQU 0B2h
	VK_MEDIA_PLAY_PAUSE     EQU 0B3h
	VK_LAUNCH_MAIL          EQU 0B4h
	VK_LAUNCH_MEDIA_SELECT  EQU 0B5h
	VK_LAUNCH_APP1          EQU 0B6h
	VK_LAUNCH_APP2          EQU 0B7h
	VK_OEM_1                EQU 0BAh
	VK_OEM_PLUS             EQU 0BBh
	VK_OEM_COMMA            EQU 0BCh
	VK_OEM_MINUS            EQU 0BDh
	VK_OEM_PERIOD           EQU 0BEh
	VK_OEM_2                EQU 0BFh
	VK_OEM_3                EQU 0C0h
	VK_OEM_4                EQU 0DBh
	VK_OEM_5                EQU 0DCh
	VK_OEM_6                EQU 0DDh
	VK_OEM_7                EQU 0DEh
	VK_OEM_8                EQU 0DFh
	VK_OEM_AX               EQU 0E1h
	VK_OEM_102              EQU 0E2h
	VK_ICO_HELP             EQU 0E3h
	VK_ICO_00               EQU 0E4h
	VK_PROCESSKEY           EQU 0E5h
	VK_ICO_CLEAR            EQU 0E6h
	VK_PACKET               EQU 0E7h
	VK_OEM_RESET            EQU 0E9h
	VK_OEM_JUMP             EQU 0EAh
	VK_OEM_PA1              EQU 0EBh
	VK_OEM_PA2              EQU 0ECh
	VK_OEM_PA3              EQU 0EDh
	VK_OEM_WSCTRL           EQU 0EEh
	VK_OEM_CUSEL            EQU 0EFh
	VK_OEM_ATTN             EQU 0F0h
	VK_OEM_FINISH           EQU 0F1h
	VK_OEM_COPY             EQU 0F2h
	VK_OEM_AUTO             EQU 0F3h
	VK_OEM_ENLW             EQU 0F4h
	VK_OEM_BACKTAB          EQU 0F5h
	VK_ATTN                 EQU 0F6h
	VK_CRSEL                EQU 0F7h
	VK_EXSEL                EQU 0F8h
	VK_EREOF                EQU 0F9h
	VK_PLAY                 EQU 0FAh
	VK_ZOOM                 EQU 0FBh
	VK_NONAME               EQU 0FCh
	VK_PA1                  EQU 0FDh
	VK_OEM_CLEAR            EQU 0FEh


ELSE
	echo --------------------------------------------
	echo WARNING Duplicate include file kernel32.inc 
	echo --------------------------------------------
ENDIF
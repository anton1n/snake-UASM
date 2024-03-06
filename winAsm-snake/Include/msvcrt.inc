IFNDEF _MSVCRT_INC_
	_MSVCRT_INC_ EQU <1>

	IFNDEF SIZE_T
		IFDEF _WIN64
			SIZE_T typedef QWORD
		ELSE
			SIZE_T typedef DWORD
		ENDIF
	ENDIF

	NULL            EQU 0
	FALSE           EQU 0
	TRUE            EQU (NOT FALSE)
	RAND_MAX        EQU 7FFFh
	EXIT_SUCCESS    EQU 0
	EXIT_FAILURE    EQU 1
	
	; Standard console I/O functions

	getchar PROTO (DWORD)
	gets PROTO (PTR) :ptr BYTE
	printf PROTO (DWORD) :ptr BYTE, :VARARG
	putchar PROTO (DWORD) :DWORD
	puts PROTO (DWORD) :ptr BYTE
	scanf PROTO (DWORD) :ptr BYTE, :VARARG
	sprintf PROTO (DWORD) :ptr BYTE, :ptr BYTE, :VARARG
	sscanf PROTO (DWORD) :ptr BYTE, :ptr BYTE, :VARARG
	perror PROTO :ptr BYTE
	wprintf PROTO (DWORD) :ptr WORD, :VARARG

	; Memory function
	calloc PROTO (PTR) :SIZE_T, :SIZE_T
	malloc PROTO (PTR) :SIZE_T
	realloc PROTO (PTR) :ptr , :SIZE_T
	free PROTO :ptr 
	memcpy PROTO (PTR) :ptr , :ptr , :SIZE_T
	memcmp PROTO (DWORD) :ptr , :ptr , :SIZE_T
	memset PROTO (PTR) :ptr , :DWORD, :SIZE_T

	; String functions
	_strset PROTO (PTR) :ptr BYTE, :DWORD
	strcpy PROTO (PTR) :ptr BYTE, :ptr BYTE
	strcat PROTO (PTR) :ptr BYTE, :ptr BYTE
	strcmp PROTO (DWORD) :ptr BYTE, :ptr BYTE
	strlen PROTO (SIZE_T) :ptr BYTE
	strchr PROTO (PTR) :ptr BYTE, :DWORD
	_strcmpi PROTO (DWORD) :ptr BYTE, :ptr BYTE
	_stricmp PROTO (DWORD) :ptr BYTE, :ptr BYTE
	strcoll PROTO (DWORD) :ptr BYTE, :ptr BYTE
	_stricoll PROTO (DWORD) :ptr BYTE, :ptr BYTE
	_strncoll PROTO (DWORD) :ptr BYTE, :ptr BYTE, :SIZE_T
	_strnicoll PROTO (DWORD) :ptr BYTE, :ptr BYTE, :SIZE_T
	strcspn PROTO (SIZE_T) :ptr BYTE, :ptr BYTE
	_strdup PROTO (PTR) :ptr BYTE
	_strerror PROTO (PTR) :ptr BYTE
	strerror PROTO (PTR) :DWORD
	_strlwr PROTO (PTR) :ptr BYTE
	strncat PROTO (PTR) :ptr BYTE, :ptr BYTE, :SIZE_T
	strncmp PROTO (DWORD) :ptr BYTE, :ptr BYTE, :SIZE_T
	_strnicmp PROTO (DWORD) :ptr BYTE, :ptr BYTE, :SIZE_T
	strncpy PROTO (DWORD) :ptr BYTE, :ptr BYTE, :SIZE_T
	_strnset PROTO (PTR) :ptr BYTE, :DWORD, :SIZE_T
	strpbrk PROTO (PTR) :ptr BYTE, :ptr BYTE
	strrchr PROTO (PTR) :ptr BYTE, :DWORD
	_strrev PROTO (PTR) :ptr BYTE
	strspn PROTO (SIZE_T) :ptr BYTE, :ptr BYTE
	strstr PROTO (PTR) :ptr BYTE, :ptr BYTE
	strtok PROTO (PTR) :ptr BYTE, :ptr BYTE
	_strupr PROTO (PTR) :ptr BYTE
	strxfrm PROTO (SIZE_T) :ptr BYTE, :ptr BYTE, :SIZE_T
	memccpy PROTO (PTR) :ptr , :ptr , :DWORD, :DWORD
	memicmp PROTO (DWORD) :ptr , :ptr , :DWORD
	strcmpi PROTO (DWORD) :ptr BYTE, :ptr BYTE
	stricmp PROTO (DWORD) :ptr BYTE, :ptr BYTE
	strdup PROTO (PTR) :ptr BYTE
	strlwr PROTO (PTR) :ptr BYTE
	strnicmp PROTO (DWORD) :ptr BYTE, :ptr BYTE, :SIZE_T
	strnset PROTO (PTR) :ptr BYTE, :DWORD, :SIZE_T
	strrev PROTO (PTR) :ptr BYTE

	; Wide string functions
	wcscat PROTO (PTR) :ptr WORD, :ptr WORD
	wcschr PROTO (PTR) :ptr WORD, :WORD
	wcscmp PROTO (DWORD) :ptr WORD, :ptr WORD
	wcscpy PROTO (PTR) :ptr WORD, :ptr WORD
	wcscspn PROTO (SIZE_T):ptr WORD, :ptr WORD
	wcslen PROTO (SIZE_T) :ptr WORD
	wcsncat PROTO (PTR) :ptr WORD, :ptr WORD, :SIZE_T
	wcsncmp PROTO (DWORD) :ptr WORD, :ptr WORD, :SIZE_T
	wcsncpy PROTO (PTR) :ptr WORD, :ptr WORD, :SIZE_T
	wcspbrk PROTO (PTR) :ptr WORD, :ptr WORD
	wcsrchr PROTO (PTR) :ptr WORD, :WORD
	wcsspn PROTO (SIZE_T) :ptr WORD, :ptr WORD
	wcsstr PROTO (PTR) :ptr WORD, :ptr WORD
	wcstok PROTO (PTR) :ptr WORD, :ptr WORD
	_wcsdup PROTO (PTR) :ptr WORD
	_wcsicmp PROTO (DWORD) :ptr WORD, :ptr WORD
	_wcsnicmp PROTO (DWORD) :ptr WORD, :ptr WORD, :SIZE_T
	_wcsnset PROTO (PTR) :ptr WORD, :WORD, :SIZE_T
	_wcsrev PROTO (PTR) :ptr WORD
	_wcsset PROTO (PTR) :ptr WORD, :WORD
	_wcslwr PROTO (PTR) :ptr WORD
	_wcsupr PROTO (PTR) :ptr WORD
	wcsxfrm PROTO (SIZE_T) :ptr WORD, :ptr WORD, :SIZE_T
	wcscoll PROTO (DWORD) :ptr WORD, :ptr WORD
	_wcsicoll PROTO (DWORD) :ptr WORD, :ptr WORD
	_wcsncoll PROTO (DWORD) :ptr WORD, :ptr WORD, :SIZE_T
	_wcsnicoll PROTO (DWORD) :ptr WORD, :ptr WORD, :SIZE_T
	wcsdup PROTO (PTR) :ptr WORD
	wcsicmp PROTO (DWORD) :ptr WORD, :ptr WORD
	wcsnicmp PROTO (DWORD) :ptr WORD, :ptr WORD, :SIZE_T
	wcsnset PROTO (PTR) :ptr WORD, :WORD, :SIZE_T
	wcsrev PROTO (PTR) :ptr WORD
	wcsset PROTO (PTR) :ptr WORD, :WORD
	wcslwr PROTO (PTR) :ptr WORD
	wcsupr PROTO (PTR) :ptr WORD
	wcsicoll PROTO (DWORD) :ptr WORD, :ptr WORD

	; Conversion functions
	atof PROTO (REAL8) :ptr BYTE
	atoi PROTO (DWORD) :ptr BYTE
	atol PROTO (DWORD) :ptr BYTE
	_atold PROTO (REAL8) :ptr BYTE
	_itoa PROTO (PTR) :DWORD, :ptr BYTE, :DWORD
	_i64toa PROTO (PTR) :QWORD, :ptr BYTE, :DWORD
	_ui64toa PROTO (PTR) :QWORD, :ptr BYTE, :DWORD
	_atoi64 PROTO (QWORD) :ptr BYTE
	_ltoa PROTO (PTR) :SDWORD, :ptr BYTE, :DWORD
	mblen PROTO (DWORD) :ptr BYTE, :SIZE_T
	_mbstrlen PROTO (SIZE_T) :ptr BYTE
	mbtowc PROTO (DWORD) :ptr WORD, :ptr BYTE, :SIZE_T
	mbstowcs PROTO (QWORD) :ptr WORD, :ptr BYTE, :SIZE_T
	_set_error_mode PROTO (DWORD) :DWORD
	strtod PROTO (REAL8) :ptr BYTE, :ptr ptr BYTE
	strtol PROTO (DWORD) :ptr BYTE, :ptr ptr BYTE, :DWORD
	_strtold PROTO (REAL8) :ptr BYTE, :ptr ptr BYTE
	strtoul PROTO (DWORD) :ptr BYTE, :ptr ptr BYTE, :DWORD
	system PROTO (DWORD) :ptr BYTE
	_ultoa PROTO (PTR) :DWORD, :ptr BYTE, :DWORD
	wctomb PROTO (QWORD) :ptr BYTE, :WORD
	wcstombs PROTO (QWORD) :ptr BYTE, :ptr WORD, :SIZE_T
	_itow PROTO (PTR) :DWORD, :ptr WORD, :DWORD
	_ltow PROTO (PTR) :SDWORD, :ptr WORD, :DWORD
	_ultow PROTO (PTR) :DWORD, :ptr WORD, :DWORD
	wcstod PROTO (REAL8) :ptr WORD, :ptr ptr WORD
	wcstol PROTO (DWORD) :ptr WORD, :ptr ptr WORD, :DWORD
	wcstoul PROTO (DWORD) :ptr WORD, :ptr ptr WORD, :DWORD
	_wgetenv PROTO (PTR) :ptr WORD
	_wsystem PROTO (DWORD) :ptr WORD
	_wtoi PROTO (DWORD) :ptr WORD
	_wtol PROTO (DWORD) :ptr WORD
	_i64tow PROTO (PTR) :QWORD, :ptr WORD, :DWORD
	_ui64tow PROTO :QWORD, :ptr WORD, :DWORD
	_wtoi64 PROTO (QWORD) :ptr WORD
	itoa PROTO (PTR) :DWORD, :ptr BYTE, :DWORD
	ltoa PROTO (PTR) :SDWORD, :ptr BYTE, :DWORD
	ultoa PROTO (PTR) :DWORD, :ptr BYTE, :DWORD
	tolower PROTO (DWORD) :DWORD
	toupper PROTO (DWORD) :DWORD

	rand PROTO (DWORD)
	srand PROTO :DWORD

	; nonstandard function
	_beep PROTO (BOOL) :DWORD, :DWORD
	beep EQU _beep
	_sleep PROTO :DWORD
	sleep EQU _sleep
	_getch PROTO (DWORD)
	getch EQU _getch
	_kbhit PROTO (DWORD)
	kbhit EQU _kbhit
	
	abort PROTO
	exit PROTO :DWORD

ELSE
	echo --------------------------------------------
	echo WARNING Duplicate include file msvcrt.inc 
	echo --------------------------------------------
ENDIF

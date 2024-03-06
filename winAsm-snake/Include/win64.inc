; In 16-bit, "TYPE near" should return 0FF02h, in 32-bit 0FF04h and in 64-bit 0FF08h

IFNDEF _WIN64
	IF TYPE near eq 0ff08h   ; 64-bit enabled?
		_WIN64 EQU <>
	ENDIF
ENDIF

IFNDEF _WIN64_INC_
	_WIN64_INC_ EQU <1>

	 OPTION casemap:none    ; case sensitive for symbols

	; ------------------------
	; system API library files
	; ------------------------
	includelib kernel32.lib
	includelib msvcrt.lib



	; ------------------------------------------
	; system API include files
	; ------------------------------------------

	include kernel32.inc
	include msvcrt.inc



ELSE
	echo -----------------------------------------
	echo WARNING Duplicate include file win64.inc
	echo -----------------------------------------
ENDIF
// Copyright (c) 2002 - 2018, Kit10 Studios LLC
// All Rights Reserved

#pragma once

#include <port/sanity.h>

#if defined(PORT_WINDOWS)
#include <Windows.h>
#include <string>
#endif

#if defined(PORT_WINDOWS)
#if defined(PORT_WIN32)

#	define COMPAT_SIZE(A)				(A)
#	define COMPAT_PSTR(A)				A
#	define COMPAT_LRESULT_TO_INT(A)		(int)(A)
#	define COMPAT_GetWindowLong(A, B)	GetWindowLong(A, B)
#	define COMPAT_GetClassInfo(A, B, C)	GetClassInfo( A, B, C )
#	define COMPAT_GWL_HINSTANCE			GWL_HINSTANCE
#	define WindowsStringPtr				CHAR

#elif defined(PORT_X64)

#	define COMPAT_SIZE(A)				(UINT_PTR)(A)
#	define COMPAT_PSTR(A)				(LPSTR)(UINT_PTR)(A)
#	define COMPAT_PWSTR(A)				(LPWSTR)(UINT_PTR)(A)
#	define COMPAT_LRESULT_TO_INT(A)		*(int*)(UINT_PTR)(A)
#	define COMPAT_GetWindowLong(A, B)	(UINT_PTR)(GetWindowLong(A, B))
#	define COMPAT_GetClassInfo(A, B, C)	GetClassInfo( A, (LPSTR)(UINT_PTR)B, C )
#	define COMPAT_GWL_HINSTANCE			GWLP_HINSTANCE
#	define WindowsStringPtr LPSTR

#endif
#endif

namespace port::win
{
#if defined(PORT_WINDOWS)
#if defined(PORT_X64)

	std::string ToWindowsString(std::wstring text);

#elif defined(PORT_WIN32(// Windows 32)

	std::string ToWindowsString(std::wstring text);

#endif
#endif
}
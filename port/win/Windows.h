/*
 * Unify Library
 * https://github.com/kit10us/unify
 * Copyright (c) 2002, Kit10 Studios LLC
 *
 * This file is part of Unify Library (a.k.a. Unify)
 *
 * Unify is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Unify is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Unify.  If not, see <https://www.gnu.org/licenses/>.
 */


#pragma once

#include <port/sanity.h>

#if defined(PORT_WINDOWS)

#define WIN32_LEAN_AND_MEAN // For winsock.
#include <windows.h>


#pragma warning( push )
#pragma warning( disable:4005 ) // Ignore "warning C4005: 'MAKEFOURCC': macro redefinition" due to mmsyscom.h(153) and dds.h(62).
#include <atlbase.h>
// For:
//		CComPtr
#pragma warning( pop )
 
 // Undefine Microsoft clashing defines.

#ifdef CreateWindow
#undef CreateWindow
#endif

#ifdef GetObject
#undef GetObject
#endif

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef FAILED
#undef FAILED
#define WIN_FAILED(hr) (((HRESULT)(hr)) < 0)
#endif

#endif // defined(PORT_WINDOWS)
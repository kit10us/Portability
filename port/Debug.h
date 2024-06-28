/*
 * Portability Library
 * https://github.com/kit10us/Portability
 * Copyright (c) 2024, Kit10 Studios LLC
 *
 * This file is part of Portability Library (a.k.a. Port)
 *
 * Port is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Port is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Port.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <port/sanity.h>
#include <string>

#if defined(PORT_WINDOWS)

#include <port/win/Windows.h>

#endif // defined(PORT_WINDOWS)


#if defined(PORT_WINDOWS)

namespace port
{
	void DebugBreak()
	{
		::DebugBreak();
	}

	void DebugLogMessage(std::string text)
	{
		OutputDebugStringA(std::string(text + "\n").c_str());
	}
}

#endif // defined(PORT_WINDOWS)
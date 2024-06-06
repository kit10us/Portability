// Copyright (c) 2002 - 2018, Kit10 Studios LLC
// All Rights Reserved

#include <port/win/general.h>
#include <algorithm>
#include <iterator>

namespace port::win
{
#ifdef _WIN64
	std::string ToWindowsString(std::wstring text)
	{
		std::string tempString;
		std::transform(text.begin(), text.end(), std::back_inserter(tempString), [](wchar_t c) {
			return reinterpret_cast<char*>(&c)[0];
			});
		return tempString;
	}

#else
	std::wstring ToWindowsString(std::wstring text)
	{
		/*
		WCHAR finalText[256]; // wchar_t
		wcscpy(finalText, text.c_str());
		*/
		return text;
	}

#endif
}
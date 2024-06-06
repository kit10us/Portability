#include "port/win/WindowsPlatform.h"

std::string port::win::Platform::GetOS() const
{
	return "Windows";
}

std::string port::win::Platform::GetBuildTarget() const
{
#ifdef _DEBUG
	return "Debug";
#else
	return "Release";
#endif
}

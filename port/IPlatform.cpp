#include "port/IPlatform.h"

#ifdef PORT_WINDOWS
#include "port/win/WindowsPlatform.h"
#endif

port::IPlatform::ptr CreatePlatform()
{
#ifdef PORT_WINDOWS
	return std::make_shared<port::win::Platform>();
#endif
}
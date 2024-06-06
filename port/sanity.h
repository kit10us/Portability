#pragma once

// OS
#if defined(PORT_WINDOWS)

// Platform
#	if defined(PORT_WIN32)
#	elif defined(PORT_X64)
#	else
#		error Invalid portability Platform
#	endif
#else

#error Invalid portability OS

#endif
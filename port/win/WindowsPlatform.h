#pragma once

#include "port/IPlatform.h"

namespace port::win
{
	class Platform : public IPlatform
	{
	public: // class IPlatform
		virtual std::string GetOS() const;
		virtual std::string GetBuildTarget() const;
	};
}
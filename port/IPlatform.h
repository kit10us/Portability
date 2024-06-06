#pragma once

#include <string>
#include <memory>

namespace port
{
	class IPlatform
	{
	public:
		typedef std::shared_ptr<IPlatform> ptr;

		virtual std::string GetOS() const = 0;
		virtual std::string GetBuildTarget() const = 0;
	};

	IPlatform::ptr CreatePlatform();
}
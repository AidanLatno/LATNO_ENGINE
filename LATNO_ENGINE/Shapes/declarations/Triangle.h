#pragma once
#include "../../engine/declarations/LOS.h"
namespace Latno
{
	class Triangle : public LOS
	{
		using LOS::LOS;
	public:
		char ch;
	};
}
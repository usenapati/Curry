#pragma once

#include "Core.h"

namespace Curry {
	class CURRY_API Application
	{

	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// TBD in CLIENT
	Application* CreateApplication();
}


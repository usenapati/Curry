#pragma once


#ifdef CRRY_PLATFORM_WINDOWS

extern Curry::Application* Curry::CreateApplication();

int main(int argc, char** argv)
{
	Curry::Log::Init();
	CURRY_CORE_WARN("Initialized Log!");
	CURRY_INFO("Hello");
	auto app = Curry::CreateApplication();
	app->Run();
	delete app;
}
#endif // CRRY_PLATFORM_WINDOWS

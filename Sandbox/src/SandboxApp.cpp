#include <Curry.h>

class Sandbox : public Curry::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Curry::Application* Curry::CreateApplication()
{
	return new Sandbox();
}
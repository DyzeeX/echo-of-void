#include <iostream>

#include "Source/Core/Application.hpp"
#include "Source/Core/Config.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/GpuPreference.hpp>

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

int main()
{
	const auto application = new Application("SFML window is started");
	application->Run();
	
	return 0;
}

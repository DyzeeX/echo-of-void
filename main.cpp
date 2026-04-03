#include <iostream>

#include "Source/Core/Application.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/GpuPreference.hpp>

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

int main()
{
	const auto application = new Application;

	application->Run();
	
	return 0;
}

#ifdef __WAND__

target[
	name[
		imgedit-test.exe
	]
	type[
		application
	]
	platform[
		;Windows
	]
]

target[
	name[
		imgedit-test
	]
	type[
		application
	]
]
#endif


#include "test.h"

#include <herbs/maindefault/maindefault.h>

Herbs::Application* Herbs::Application::instanceCreate()
	{
	return new Test();
	}

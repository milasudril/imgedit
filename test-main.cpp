#ifdef __WAND_IGNORE__

target[
	name[
		Test.exe
	]
	type[
		application
	]
	platform[
		win32
	]
]
#endif
#ifdef __WAND_IGNORE__

target[
	name[
		Gui
	]
	type[
		application
	]
]
#endif


#include "test.h"

#include <herbs/maindefault.h>

Herbs::Application* Herbs::Application::instanceCreate()
	{
	return new Test();
	}

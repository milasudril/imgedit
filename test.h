#ifdef __WAND_IGNORE__

dependencies[
	test.o
]
target[
	name[
		test.h
	]
	type[
		include
	]
]
#endif

#ifndef guard_test_H
#define guard_test_H

#include <gui/gui.h>
#include <gui/blitter.h>

class MyImgEdit;
	
class Test:public Gui::Gui
	{
	public:
		Test():image(1,1){}
		
		void init(Herbs::Directory&& dir);
			
		/**Lets the object commit suicide.
		*/
		void destroy();
		
		/**Frees all resources.
		*/
		~Test();

	private:
		Herbs::MatrixStorage< ::Gui::Blitter::PixelBGRA<float> > image;
		MyImgEdit* mainwin;
	};

#endif

#ifdef __WAND__
dependencies[imgedit.o]
target[name[imgedit.h] type[include]]
#endif

#ifndef IMGEDIT_H
#define IMGEDIT_H
	
#include <gui/viewsplit.h>
#include <gui/blitter.h>

namespace Gui
	{
	class Toolbar;
	}

class ImgEdit:public Gui::ViewSplit
	{
	public:
		static void init();

		static ImgEdit* create(Gui::Gui& gui_obj,uint32_t style_0
			,uint32_t style_1,Gui::Window* parent)
			{return new ImgEdit(gui_obj,style_0,style_1,parent);}
		
		void imageSet(Herbs::MatrixStorage<Gui::Blitter::PixelBGRA<float> >& img)
			{image_view->pixelsSet(img);}

	protected:
		ImgEdit(Gui::Gui& gui_obj,uint32_t style_0,uint32_t style_1,Gui::Window* parent);

		Gui::Toolbar* commands;
		Gui::Blitter* image_view;
		
	};

#endif

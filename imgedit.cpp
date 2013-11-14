#ifdef __WAND__
target[name[imgedit.o] type[object]]
#endif

#include "imgedit.h"
#include <gui/toolbar.h>

ImgEdit::ImgEdit(Gui::Gui& gui_obj,uint32_t style_0,uint32_t style_1,Gui::Window* parent):
	Gui::ViewSplit(gui_obj,style_0,style_1,parent)
	{
	commands=Gui::Toolbar::create(gui_obj,0
		,Window::StyleChild|Window::StyleVisible,this);
	
	image_view=Gui::Blitter::create(gui_obj
					,Window::StyleEx_clientedge
					,Window::StyleChild|Window::StyleVisible
					,this);
	
	firstSet(*commands);
	secondSet(*image_view);
	}

void ImgEdit::init()
	{
	Gui::ViewSplit::init();
	Gui::Toolbar::init();	
	}

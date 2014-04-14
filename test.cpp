#ifdef __WAND__

target[
	name[
		test.o
	]
	type[
		object
	]
]
#endif

#include "imgedit.h"
#include "test.h"
#include <gui/toolbar.h>
#include <herbs/intformat/intformat.h>
#include <herbs/string/string.h>

class MyImgEdit:public ImgEdit
	{
	public:
		static MyImgEdit* create(Test& gui_obj,uint32_t style_0
			,uint32_t style_1,Gui::Window* parent)
			{return new MyImgEdit(gui_obj,style_0,style_1,parent);}
			
		void onCommand(uint32_t event_status,uint32_t command_id,Window& source)
			{
			switch(source.idGet())
				{
				case 1:
					data.syserr().print(Herbs::String(Herbs::IntFormat<int>(command_id,10))
						,Herbs::MessagePrinter::Type::INFORMATION);
					break;
				}
			}
		
	protected:
		MyImgEdit(Test& gui_obj,uint32_t style_0,uint32_t style_1,Gui::Window* parent):
			ImgEdit(gui_obj,style_0,style_1,parent),data(gui_obj)
			{
			commands->buttonAdd(STR("Open state")).buttonAdd(STR("Save state"))
				.buttonAdd(STR("Start")).buttonAdd(STR("Stop")).buttonAdd(STR("Reset"));
			commands->idSet(1);
			}
			
	private:
		Test& data;
	};

namespace
	{
	void fill(Vector::MatrixStorage<Gui::Blitter::PixelBGRA<float> >& img)
		{
		for(size_t k=0;k<img.nRowsGet();++k)
			{
			for(size_t l=0;l<img.nColsGet();++l)
				{
				img(k,l).blue=float(l)/img.nColsGet();
				img(k,l).green=0;
				img(k,l).red=0;
				}
			}
		}
	}

void Test::init(Herbs::Directory&& dir)
	{
	MyImgEdit::init();
	mainwin=MyImgEdit::create(*this,0,0,nullptr);
	mainwin->popup();
	mainwin->sizeRelative(0.61,0.61);
	mainwin->titleSet(STR("Gui test"));
	mainwin->moveRelative(Vector::Vector2d<float>(0,0)
		,Vector::Vector2d<float>(0.5,0.5));
	mainwin->show(::Gui::Window::DisplayNormal);
	image.resize(256,256);
	fill(image);
	mainwin->imageSet(image);
	}

Test::~Test()
	{
	}
	
void Test::destroy()
	{
	delete this;
	}


	

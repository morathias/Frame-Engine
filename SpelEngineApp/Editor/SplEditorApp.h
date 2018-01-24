#ifndef SPLEDITORAPP_H
#define SPLEDITORAPP_H

#include "QtWidgets\qwidget.h"
#include "QtWidgets\qapplication.h"
#include "QtWidgets\qpushbutton.h"
//========================================
namespace SplEditor{

	class SplEditorApp
	{
	public:
		SplEditorApp(int argc, char* argv[]);
		~SplEditorApp();

		int open();

	private:
		const int DESKTOP_TOOLBAR_HEIGHT = 38;

		QApplication* _application;
		bool _isFullScreen;

		QWidget* _mainWindow;
		QPushButton* _closeBtn;
		QPushButton* _maxMinBtn;
		QPushButton* _hideBtn;
	};

}
//========================================
#endif
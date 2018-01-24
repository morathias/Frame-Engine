#include "SplEditorApp.h"
#include "QtWidgets\qdesktopwidget.h"
#include "QtCore\qrect.h"
#include <iostream>

using namespace SplEditor;
using namespace std;
//==================================================
SplEditorApp::SplEditorApp(int argc, char* argv[])
{
	_isFullScreen = true;
	//creates qtApplication;
	_application = new QApplication(argc, argv);

	//creates main window, controls the whole app
	_mainWindow = new QWidget(NULL);
	_mainWindow->setWindowFlag(Qt::FramelessWindowHint);
	_mainWindow->resize(QApplication::desktop()->screenGeometry().width(),
						QApplication::desktop()->screenGeometry().height() - DESKTOP_TOOLBAR_HEIGHT);
	_mainWindow->setStyleSheet("background-color: rgb(50,69,80)");
	
	//creates three basic Windows buttons
	QString buttonStyle =   "QPushButton "
							"{"
							"background-color: rgba(255, 255, 255, 0);"
							"border: none;"
							"}";

	_closeBtn = new QPushButton("", _mainWindow);
	_closeBtn->setGeometry(_mainWindow->size().width() - 20, 10, 10, 10);
	_closeBtn->setIcon(QIcon("Resources/Icons/015-close.png"));
	_closeBtn->setStyleSheet(buttonStyle);
	QObject::connect(_closeBtn, &QPushButton::clicked, qApp, QApplication::quit);

	_maxMinBtn = new QPushButton("", _mainWindow);
	_maxMinBtn->setGeometry(_mainWindow->size().width() - 60, 10, 10, 10);
	_maxMinBtn->setIcon(QIcon("Resources/Icons/011-fullscreen.png"));
	_maxMinBtn->setStyleSheet(buttonStyle);
	QObject::connect(_maxMinBtn, &QPushButton::clicked, qApp, QApplication::quit);

	_mainWindow->show();
}
//==================================================
SplEditorApp::~SplEditorApp()
{
	delete _mainWindow;
	delete _application;
}
//==================================================
int SplEditorApp::open()
{
	return _application->exec();
}
//==================================================
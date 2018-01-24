#include "QtWidgets\qapplication.h"
#include "QtWidgets\qwidget.h"
#include "QtWidgets\qpushbutton.h"
#include "Importer.h"
#include "Editor\SplEditorApp.h"

class Button : public QWidget
{
public:
	Button(QWidget* parent = 0);
};

Button::Button(QWidget* parent):
QWidget(parent)
{
	QPushButton* quitButton = new QPushButton("Quit", this);
	quitButton->setGeometry(50, 40, 100, 20);
	quitButton->setStyleSheet("QPushButton "
							  "{"
									"background-color: rgb(38, 53, 62); "
									"color: rgb(210, 210, 210);"
									"border: none;"
									"font: bold"
							  "}"
								);
	
	QFont font;
	font.setPixelSize(10);
	font.setFamily("Montserrat");
	quitButton->setFont(font);
	connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char* argv[])
{
	SplEditor::SplEditorApp* editor = new SplEditor::SplEditorApp(argc, argv);

	/*Button window;

	window.resize(1360,730);
	window.move(0, 0);
	window.setWindowTitle("Spel Engine");
	window.setWindowFlag(Qt::FramelessWindowHint);
	window.setToolTip("QWidget");
	window.show();
	window.setStyleSheet("background-color: rgb(50,69,80)");*/

	Importer importer;
	importer.importMesh("pepe");

	return editor->open();
}
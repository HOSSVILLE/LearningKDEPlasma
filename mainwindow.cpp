#include "mainwindow.h"

#include <QApplication>
#include <QAction>
#include <KTextEdit>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>

MainWindow::MainWindow(QWidget *parent) : KXmlGuiWindow(parent)
{
  textArea = new KTextEdit();
  setCentralWidget(textArea);
  setupActions();
}

void MainWindow::setupActions()
{
    QAction* clearAction = new QAction(this);
    clearAction->setText(i18n("&Clear"));
    clearAction->setIcon(QIcon::fromTheme("document-new"));
    actionCollection()->setDefaultShortcut(clearAction, Qt::CTRL + Qt::Key_W);
    actionCollection()->addAction("clear", clearAction);
    connect(clearAction, SIGNAL(triggered(bool)), textArea, SLOT(clear()));
    KStandardAction::quit(qApp, SLOT(quit()), actionCollection());
    setupGUI(Default, "tutorial3ui.rc");
}


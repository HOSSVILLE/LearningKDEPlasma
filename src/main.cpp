#include <QApplication>
#include <QCommandLineParser>
#include <KAboutData>
#include <KLocalizedString>
#include <KMessageBox>
#include "mainwindow.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("tutorial1");

    
    KAboutData aboutData(
                         // The program name used internally. (componentName)
                         QStringLiteral("tutorial3"),
                         // A displayable program name string. (displayName)
                         i18n("Tutorial 1"),
                         // The program version string. (version)
                         QStringLiteral("1.0"),
                         // Short description of what the app does. (shortDescription)
                         i18n("Displays a KMessageBox popup"),
                         // The license this code is released under
                         KAboutLicense::GPL,
                         // Copyright Statement (copyrightStatement = QString())
                         i18n("(c) 2015"),
                         // Optional text shown in the About box.
                         // Can contain any information desired. (otherText)
                         i18n("Some text..."),
                         // The program homepage string. (homePageAddress = QString())
                         QStringLiteral("http://example.com/"),
                         // The bug report email address
                         // (bugsEmailAddress = QLatin1String("submit@bugs.kde.org")
                         QStringLiteral("submit@bugs.kde.org"));
    aboutData.addAuthor(i18n("Name"), i18n("Task"), QStringLiteral("your@email.com"),
                         QStringLiteral("http://your.website.com"), QStringLiteral("OSC Username"));
    KAboutData::setApplicationData(aboutData);

    
    KGuiItem yesButton( i18n( "Hello" ), QString(),
                        i18n( "This is a tooltip" ),
                        i18n( "This is a WhatsThis help text." ) );

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);
    
    MainWindow* window = new MainWindow();
    window->show();
    
    return app.exec();
}

#include "fenconfig.h"
#include "../Monde/monde.h"
#include "../GUI/fencarte.h"

#include <QtCore/QLibraryInfo>
#include <QtCore/QLocale>
#include <QtCore/QTextCodec>
#include <QtCore/QTranslator>
#include <QtGlobal>
#include <QtGui/QApplication>
#include <time.h>

int main(int argc, char** argv) {
    // Initialisation de la graîne aléatoire
    qsrand(time(NULL));
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("IUT Blagnac");
    QCoreApplication::setOrganizationDomain("code.google.com/p/bel-o-kan");
    QCoreApplication::setApplicationName("Bel-O-Kan");

    // Réglage de l'encodage
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    // Application de la traduction
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    // De l'application elle même
    translator.load(QString("icare_") + locale);
    a.installTranslator(&translator);
    // Et de Qt
    if (translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        a.installTranslator(&translator);
    else {
        translator.load(QString("qt_") + locale);
        a.installTranslator(&translator);
    }

    // Initialisation des modules
    Monde *monde = Monde::instance();
    FenCarte *fenCarte = new FenCarte();

    FenConfig *fen = new FenConfig(fenCarte, monde);
    fen->show();

    QObject::connect(fenCarte, SIGNAL(signalQuitter()), qApp, SLOT(quit()));
    QObject::connect(fenCarte, SIGNAL(tourSuivant()), monde, SLOT(tour()));

    return a.exec();
}

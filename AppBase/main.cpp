#include "fenconfig.h"
#include "../Monde/monde.h"
#include "../GUI/fencarte.h"
#include "../Stats/stats.h"

#include <QtCore/QLibraryInfo>
#include <QtCore/QLocale>
#include <QtCore/QTextCodec>
#include <QtCore/QTranslator>
#include <QtGlobal>
#include <QtWidgets/QApplication>
#include <time.h>

int main(int argc, char** argv) {
    // Initialisation de la graîne aléatoire
    qsrand(time(NULL));
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("IUT Blagnac");
    QCoreApplication::setOrganizationDomain("code.google.com/p/bel-o-kan");
    QCoreApplication::setApplicationName("Bel-O-Kan");

    // Réglage de l'encodage
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

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
    Stats *stats = new Stats();

    FenConfig *fen = new FenConfig(fenCarte, monde, stats);
    fen->show();

    QObject::connect(monde, SIGNAL(sigTour(ParametresMonde::ParamsMonde)), fenCarte, SIGNAL(tourSuivantMonde()));
    QObject::connect(monde, SIGNAL(finDuMonde(int)), fenCarte, SLOT(finDuMonde(int)));
    QObject::connect(fenCarte, SIGNAL(signalQuitter()), qApp, SLOT(quit()));
    QObject::connect(fenCarte, SIGNAL(tourSuivant()), monde, SLOT(tour()));
    QObject::connect(monde, SIGNAL(afficherElement(ParametresMonde::typeElement,int,int)), fenCarte, SIGNAL(afficherElement(ParametresMonde::typeElement,int,int)));
    QObject::connect(monde, SIGNAL(supprimerElement(ParametresMonde::typeElement,int,int)), fenCarte, SIGNAL(supprimerElement(ParametresMonde::typeElement,int,int)));
    QObject::connect(monde, SIGNAL(deplacerElement(ParametresMonde::typeElement,int,int,int,int)), fenCarte, SIGNAL(deplacerElement(ParametresMonde::typeElement,int,int,int,int)));
    QObject::connect(monde, SIGNAL(ajoutBrindilles(int)), fenCarte, SIGNAL(ajoutBrindilles(int)));
    QObject::connect(monde, SIGNAL(ajoutNourriture(int)), fenCarte, SIGNAL(ajoutNourriture(int)));
    QObject::connect(monde, SIGNAL(sigTour(ParametresMonde::ParamsMonde)), stats, SLOT(tour(ParametresMonde::ParamsMonde)));
    QObject::connect(monde, SIGNAL(finDuMonde(int)), stats, SLOT(fin()));
    QObject::connect(monde, SIGNAL(afficherInfos(ParametresMonde::typeInfo)), fenCarte, SIGNAL(afficherInfos(ParametresMonde::typeInfo)));

    return a.exec();
}

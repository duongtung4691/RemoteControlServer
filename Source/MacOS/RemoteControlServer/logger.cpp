#include "logger.h"

Logger* Logger::instance = NULL;

Logger* Logger::Instance()
{
    if (!instance)
    {
        instance = new Logger();
    }
    return instance;
}

Logger::Logger() :
  URL_TRACKER("http://remote-control-collection.com/api/tracker/"),
  trackEvents(true),
//  showDebug(true),
  maxItems(100)
{
//    dispatcherActive = false;
    lastEntry = "";

    lastUpdate = QDateTime().currentDateTime();
    logMessages = new QStringList();
}

void Logger::add(QString message)
{
    QString timestamp = QTime().currentTime().toString();
    lastEntry = message;
    logMessages->append(timestamp + ": " + message);
    Logger::trim();

    // Update UI log
//    if (QDateTime().currentMSecsSinceEpoch() > lastUpdate.toMSecsSinceEpoch() + 500) // if 500 Milliseconds have passed by sind last update
//    {
//        this->invalidateLog();
//    }
//    else
//    {
//        this->startInvalidateTimer();
//    }
}

//void Logger::add(QString message, bool isDebug)
//{
//    if (showDebug || !isDebug)
//    {
//        this->add(message);
//    }
//}

//void Logger::invalidateLog()
//{
//    //tbd
//}

//void Logger::startInvalidateTimer()
//{
//    if (!dispatcherActive)
//    {
//        // Creates a Timer that invokes the invalidateTimerTick method every 1000 milliseconds
//        int timerRunTimeInMillis = 1000;
//        dispatcherTimer = new QTimer(this);
//        connect(dispatcherTimer, SIGNAL(timeout()), this, SLOT(InvalidateTimerTick()));
//        dispatcherTimer->start(timerRunTimeInMillis);
//    }
//}

//void Logger::InvalidateTimerTick()
//{
//    this->invalidateLog();
//}

void Logger::trim()
{
    if (logMessages->size() > maxItems) logMessages->removeAt(0);
}

//QString Logger::getString()
//{
//    QString result = "";
//    foreach (QString message, *logMessages) {
//        result += " " + message + "\n";
//    }
//    return result;
//}

//QString Logger::getLastEntry()
//{
//    const int maxLength = 30;
//    QString entry = lastEntry;

//    while (entry.length() > maxLength)
//    {
//        if (entry.contains(" "))
//        {
//            entry.truncate(entry.lastIndexOf(" "));
//        }
//        else
//        {
//            entry.truncate(maxLength - 3);
//        }
//        entry.append("...");
//    }
//    return entry;
//}

void Logger::trackLaunchEvent()
{
    Logger::trackEvent("Server", "Launch", APP_VERSION);
}

void Logger::trackEvent(QString category, QString action, QString label)
{
    if (trackEvents)
    {
       QString url = URL_TRACKER
                    + "?category=" + category
                    + "&action=" + action
                    + "&label=" + label;
       //Network::Instance()->loadInBrowser(url);
    }
}


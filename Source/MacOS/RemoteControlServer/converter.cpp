#include "converter.h"

Converter* Converter::instance = NULL;

Converter* Converter::Instance()
{
    if (!instance)
    {
        instance = new Converter();
    }
    return instance;
}

Converter::Converter()
{
}

QString Converter::byteToString(QByteArray &value, int index)
{
    return value.right(value.length() - index);
}

QString Converter::boolToString(bool value)
{
    return value ? "1" : "0";
}

bool Converter::stringToBool(QString &value)
{
    return (value == "1") ? true : false;
}

QString Converter::commandToString(Command &command)
{
    QString commandString = "[ ";
    for (int i = 0; i < command.data->length(); ++i)
    {
        commandString += command.data->at(i) + " ";
    }
    commandString += "]";
    return commandString;
}

#ifndef CPUINFOREADER_H
#define CPUINFOREADER_H

#include <QString>
#include <QtCore>
#include <QObject>

const QString STR_DEFAULT = "UNINITIALIZED";

struct CPUinfo
{
    QString processor;
    QString vendor_id;
    QString cpu_family;
    QString model;
    QString model_name;
    QString stepping;
    QString microcode;
    QString cpu_MHz;
    QString cache_size;
    QString physical_id;
    QString siblings;
    QString core_id;
    QString cpu_cores;
    QString apicid;
    QString initial_apicid;
    QString fpu;
    QString fpu_exception;
    QString cpuid_level;
    QString wp;
    QString flags;
    QString bogomips;
    QString clflush_size;
    QString cache_alignment;
    QString address_sizes;
    QString power_management;
};


class CPUinfoReader : public QObject
{
Q_OBJECT

QList <CPUinfo*> CPUlist;
CPUinfo CPUinformation;     // development only... replace this with list in final version

public:

CPUinfoReader(); // Konstruktor
~CPUinfoReader(); //Destruktor

Q_INVOKABLE void initializeCPUinfo_developmentOnly()
{
    qDebug() << "function called: initializeCPUinfo_developmentOnly";
    CPUinfo* currentCPU = &CPUinformation; // Development only
    setToDefault(currentCPU);
}

Q_INVOKABLE QString readCPUinfo(int CPUproperty, int processorNumber)
    {

    qDebug() << "function called: readCPUinfo";
    //CPUinfo* currentCPU = &CPUinformation; // Development only

    if (CPUlist.empty())
    {
        qDebug() << "Warning! Function CPUinfoReader::readCPUinfo tried to access an empty list: CPUlist not initialized";
    }
    else if (processorNumber > CPUlist.size())
    {
        qDebug() << "Warning! Function CPUinfoReader::readCPUinfo tried to invalid access to CPUlist: processorNumber > CPUlist.size()";
    }
    else
    {
        switch (CPUproperty) {

        case 1 :
            return CPUlist.at(processorNumber)->processor;
            break;

        case 2 :
            return CPUlist.at(processorNumber)->vendor_id ;
            break;

        case 3:
            return CPUlist.at(processorNumber)->cpu_family ;
            break;

        case 4 :
            return CPUlist.at(processorNumber)->model ;
            break;

        case 5 :
            return CPUlist.at(processorNumber)->model_name ;
            break;

        case 6 :
            return CPUlist.at(processorNumber)->stepping ;
            break;

        case 7 :
            return CPUlist.at(processorNumber)->microcode ;
            break;

        case 8 :
            return CPUlist.at(processorNumber)->cpu_MHz ;
            break;

        case 9 :
            return CPUlist.at(processorNumber)->cache_size ;
            break;

        case 10 :
            return CPUlist.at(processorNumber)->physical_id ;
            break;

        case 11 :
            return CPUlist.at(processorNumber)->siblings ;
            break;

        case 12 :
            return CPUlist.at(processorNumber)->core_id ;
            break;

        case 13 :
            return CPUlist.at(processorNumber)->cpu_cores ;
            break;

        case 14 :
            return CPUlist.at(processorNumber)->apicid ;
            break;

        case 15 :
            return CPUlist.at(processorNumber)->initial_apicid ;
            break;

        case 16 :
            return CPUlist.at(processorNumber)->fpu ;
            break;

        case 17 :
            return CPUlist.at(processorNumber)->fpu_exception ;
            break;

        case 18 :
            return CPUlist.at(processorNumber)->cpuid_level ;
            break;

        case 19 :
            return CPUlist.at(processorNumber)->wp ;
            break;

        case 20 :
            return CPUlist.at(processorNumber)->flags ;
            break;

        case 21 :
            return CPUlist.at(processorNumber)->bogomips ;
            break;

        case 22 :
            return CPUlist.at(processorNumber)->clflush_size ;
            break;

        case 23 :
            return CPUlist.at(processorNumber)->cache_alignment ;
            break;

        case 24 :
            return CPUlist.at(processorNumber)->address_sizes ;
            break;

        case 25 :
            return CPUlist.at(processorNumber)->power_management ;
            break;

        default :
            const QString errorMsgPart1 = "ERROR: invalid argument (";
            const QString errorMsgPart2 = ") in function CPUinfoReader::readCPUinfo";
            return errorMsgPart1 + QString::number(CPUproperty) +  errorMsgPart2;
        }
    }
 }

Q_INVOKABLE QString readCPUinfoFile(QString Filename)
    {
        qDebug() << "function called: readCPUinfoFile";
        //setToDefault(CPUinformation);
        QFile file(Filename);

        qDebug() << "function called: readCPUinfoFile";

        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "could not open file";
            return "Error: File " + Filename + " could not be opened!";
            // don't forget to initialize CPUinfo somehow
        }

        QTextStream in(&file);
        //int i = 1;
        //int processorNumber = 0;    // DEVELOPMENT ONLY!

        while (!in.atEnd()) {

            int i = 1;
            CPUinfo* currentCPU = new CPUinfo;
            setToDefault(currentCPU);
            CPUlist.append(currentCPU);

             while (!in.atEnd()) {
                 QString line = in.readLine();
                 if (line.contains("Break here"))  //DEVELOPMENT ONLY!!
                 {
                     break;
                 }
                 else
                 {
                     writeCPUinfo(line,i,CPUlist.size()-1);
                     i++;
                 }
             }
        }

        file.close();
        if (CPUlist.empty())
        {
            return "No valid CPU information found in file " + Filename;
        }
        else
        {
            return  "CPU Information read successfully: " + QString::number(CPUlist.size()) + " CPUs were found!";
        }
    }

private:


CPUinfo* getCurrentCPU(int processorNumber)
{
}

void setToDefault (CPUinfo* CPU)
{
    qDebug() << "function called: setToDefault";
    CPU->processor       = "default_cpu";
    CPU->vendor_id       = "default_vendor";
    CPU->cpu_family      = STR_DEFAULT;
    CPU->model           = STR_DEFAULT;
    CPU->model_name      = STR_DEFAULT;
    CPU->stepping        = STR_DEFAULT;
    CPU->microcode       = STR_DEFAULT;
    CPU->cpu_MHz         = STR_DEFAULT;
    CPU->cache_size      = STR_DEFAULT;
    CPU->physical_id     = STR_DEFAULT;
    CPU->siblings        = STR_DEFAULT;
    CPU->core_id         = STR_DEFAULT;
    CPU->cpu_cores       = STR_DEFAULT;
    CPU->apicid          = STR_DEFAULT;
    CPU->initial_apicid  = STR_DEFAULT;
    CPU->fpu             = STR_DEFAULT;
    CPU->fpu_exception   = STR_DEFAULT;
    CPU->cpuid_level     = STR_DEFAULT;
    CPU->wp              = STR_DEFAULT;
    CPU->flags           = STR_DEFAULT;
    CPU->bogomips        = STR_DEFAULT;
    CPU->clflush_size    = STR_DEFAULT;
    CPU->cache_alignment = STR_DEFAULT;
    CPU->address_sizes   = STR_DEFAULT;
    CPU->power_management = STR_DEFAULT;
}

void writeCPUinfo(QString line, int CPUproperty, int processorNumber)
    {

    qDebug() << "function called: writeCPUinfo";
    qDebug() << "processor: " << QString::number(processorNumber);
    qDebug() << "List size: " << QString::number(CPUlist.size());
    qDebug() << "List empty?: " << QString(CPUlist.empty() ? "1" : "0");



    //CPUinfo* currentCPU = &CPUinformation; // Development only
    // tbd
    // CPUinfo* currentCPU = getCurrentCPU(int processorNumber);

    if (CPUlist.empty())
    {
        qDebug() << "Warning! Function CPUinfoReader::readCPUinfo tried to access an empty list: CPUlist not initialized";
        return;
    }
    else if (processorNumber > CPUlist.size())
    {
        qDebug() << "Warning! Function CPUinfoReader::readCPUinfo tried to invalid access to CPUlist: processorNumber > CPUlist.size()";
        return;
    }
    else
    {
        switch (CPUproperty) {

        case 1 :
            CPUlist.at(processorNumber)->processor = line;
            break;

        case 2 :
            CPUlist.at(processorNumber)->vendor_id = line ;
            break;

        case 3:
            CPUlist.at(processorNumber)->cpu_family = line ;
            break;

        case 4 :
            CPUlist.at(processorNumber)->model = line ;
            break;

        case 5 :
            CPUlist.at(processorNumber)->model_name = line ;
            break;

        case 6 :
            CPUlist.at(processorNumber)->stepping = line ;
            break;

        case 7 :
            CPUlist.at(processorNumber)->microcode = line ;
            break;

        case 8 :
            CPUlist.at(processorNumber)->cpu_MHz = line ;
            break;

        case 9 :
            CPUlist.at(processorNumber)->cache_size = line ;
            break;

        case 10 :
            CPUlist.at(processorNumber)->physical_id = line ;
            break;

        case 11 :
            CPUlist.at(processorNumber)->siblings = line ;
            break;

        case 12 :
            CPUlist.at(processorNumber)->core_id = line ;
            break;

        case 13 :
            CPUlist.at(processorNumber)->cpu_cores = line ;
            break;

        case 14 :
            CPUlist.at(processorNumber)->apicid = line ;
            break;

        case 15 :
            CPUlist.at(processorNumber)->initial_apicid = line ;
            break;

        case 16 :
            CPUlist.at(processorNumber)->fpu = line ;
            break;

        case 17 :
            CPUlist.at(processorNumber)->fpu_exception = line ;
            break;

        case 18 :
            CPUlist.at(processorNumber)->cpuid_level = line ;
            break;

        case 19 :
            CPUlist.at(processorNumber)->wp = line ;
            break;

        case 20 :
            CPUlist.at(processorNumber)->flags = line ;
            break;

        case 21 :
            CPUlist.at(processorNumber)->bogomips = line ;
            break;

        case 22 :
            CPUlist.at(processorNumber)->clflush_size = line ;
            break;

        case 23 :
            CPUlist.at(processorNumber)->cache_alignment = line ;
            break;

        case 24 :
            CPUlist.at(processorNumber)->address_sizes = line ;
            break;

        case 25 :
            CPUlist.at(processorNumber)->power_management = line ;
            break;

        default :
            qDebug() << "invalid argument " + QString::number(CPUproperty) + " in function CPUinfoReader::writeCPUinfo";
        }
        return;
    }
}

signals:


public slots:


};


#endif // CPUINFOREADER_H






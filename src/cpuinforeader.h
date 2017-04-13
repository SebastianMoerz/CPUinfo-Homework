#ifndef CPUINFOREADER_H
#define CPUINFOREADER_H


// Add information here


#include <QString>
#include <QtCore>
#include <QStringList>
#include <QObject>


// Column-Separator in /proc/cpuinfo
const QString SEPARATOR     = ":";


// this structure contains information for one CPU
struct CPUinfo
{
    QList <QString*> labellist;     //information left of separator-sign
    QList <QString*> contentlist;   //information right of separator-sign
};


class CPUinfoReader : public QObject
    {
    Q_OBJECT

    QList <CPUinfo*> CPUlist;           // the main data store: a list of all CPUs found in /proc/cpuinfo


    public:

    CPUinfoReader();                    // constructor
    ~CPUinfoReader();                   // destructor

    Q_INVOKABLE void strLog (QString log) {
        qDebug() << log;
    }

    Q_INVOKABLE void intLog (int log) {
        qDebug() << QString::number(log);
    }

    // returns the number of lines containing information for the CPU with the index CPUnumber
    // NOT WORKING PROPERLY!
    Q_INVOKABLE int getNumberOfEntries (int CPUnumber)
    {
        qDebug() << "getNumberOfEntries called";
        if (CPUlist.empty()) {
             return 0;
        }
        else {
            qDebug() << "Entries in CPU number " + QString::number(CPUnumber) + " of " + QString::number(CPUlist.size()-1) + ": " + QString::number(CPUlist.at(CPUnumber)->labellist.size());

            // ERROR!
            // this function returns always 10!
            // argument CPUnumber (from qml) is always 0!
            return CPUlist.at(CPUnumber)->labellist.size();


        }
    }


    // returns the number of CPUs found in /proc/cpuinfo
    Q_INVOKABLE int getNumberOfCPUs()
    {
        qDebug() << "getNumberOfCPUs called";
        if(!CPUlist.empty()) {
            return CPUlist.size();
        }
        else {
            return -1;
        }
    }

    // returns the string containing the Xth content (=information) of CPU number "processorNumber" with X = propertyNumber    
    Q_INVOKABLE QString getLabelText(int propertyNumber, int processorNumber)
    {
        // handle errors
        if (CPUlist.empty())
        {
            qDebug() << "Warning! Function CPUinfoReader::getLabelText tried to access an empty list: CPUlist not initialized";
            return "error: list empty";
        }
        else if (processorNumber >= CPUlist.size())
        {
            qDebug() << "Warning! Function CPUinfoReader::getLabelText tried to invalid access to CPUlist: processorNumber >= CPUlist.size()";
            return "error: index overflow";
        }
        else if (CPUlist.at(processorNumber)->labellist.empty())
        {
            qDebug() << "Warning! Function CPUinfoReader::getLabelText tried to access an empty list: CPUlist.at(processorNumber)-> labellist is empty";
            return "error: list empty";
        }
        else if (propertyNumber >= CPUlist.at(processorNumber)->labellist.size())
        {
            qDebug() << "Warning! Function CPUinfoReader::getLabelText tried to invalid access to CPUlist: propertyNumber >= CPUlist.at(processorNumber)->labellist.size()";
            return "error: index overflow";
        }
        // if required list element exists
        else
        {
            // ERROR!
            // Programm crashs if CPUlist.at(processorNumber)->labellist.at(propertyNumber) is returned!

            //return "Content Test";
            int len = CPUlist.at(processorNumber)->labellist.at(propertyNumber)->length();
            return CPUlist.at(processorNumber)->labellist.at(propertyNumber)->left(len);

        }
    }

    // returns the string containing the Xth label of CPU number "processorNumber" with X = propertyNumber   
    Q_INVOKABLE QString getContentText(int propertyNumber, int processorNumber)
    {
        // handle errors
        if (CPUlist.empty())
        {
            qDebug() << "Warning! Function CPUinfoReader::getContentText tried to access an empty list: CPUlist not initialized";
            return "error: list empty";
        }
        else if (processorNumber >= CPUlist.size())
        {
            qDebug() << "Warning! Function CPUinfoReader::getContentText tried to invalid access to CPUlist: processorNumber >= CPUlist.size()";
            return "error: index overflow";
        }
        else if (CPUlist.at(processorNumber)->contentlist.empty())
        {
            qDebug() << "Warning! Function CPUinfoReader::getContentText tried to access an empty list: CPUlist.at(processorNumber)-> contentlist is empty";
            return "error: list empty";
        }
        else if (propertyNumber >= CPUlist.at(processorNumber)->contentlist.size())
        {
            qDebug() << "Warning! Function CPUinfoReader::getContentText tried to invalid access to CPUlist: propertyNumber >= CPUlist.at(processorNumber)->contentlist.size()";
            return "error: index overflow";
        }
        // if required list element exists
        else
        {
            // ERROR!
            // Programm crashs if CPUlist.at(processorNumber)->contentlist.at(propertyNumber) is returned!

            //return "Label Test";
            int len = CPUlist.at(processorNumber)->contentlist.at(propertyNumber)->length();
            return CPUlist.at(processorNumber)->contentlist.at(propertyNumber)->right(len);
        }
    }

    // Main function for reading /proc/cpuinfo
    // the content of the file is processed line by line
    // a new CPU is appended to CPUlist whenever the string "processor" is found in the file.
    // the result (success/failure) is returned as string
    Q_INVOKABLE QString readCPUinfoFile(QString Filename)
        {
            qDebug() << "function called: readCPUinfoFile";

            // clear CPUlist it already exists, i.e. Read-Button was previously pressed
            if (!CPUlist.empty()) {
                CPUlist.clear();
            }

            QFile file(Filename);

            // check if file can be opened
            // abort function on error
            if(!file.open(QFile::ReadOnly | QFile::Text))
            {
                qDebug() << "could not open file";
                return "Error: File " + Filename + " could not be opened!";
                // don't forget to initialize CPUinfo somehow
            }

            // stream the file
            QTextStream in(&file);

            // variables for storing the parsed information
            QString labeltext;
            QString contenttext;

            // process each line until end-of-file is found
            while (!in.atEnd()) {

                QString line = in.readLine();
                //qDebug() <<line;

                // create new CPU if the string "processor" is found
                if (CPUlist.empty() || line.contains("processor"))
                {
                    // qDebug() << "create new cpu";
                    CPUinfo* newCPU = new CPUinfo;
                    CPUlist.append(newCPU);                    
                }

                // the format of each line in /proc/cpuinfo is "label" + "SEPARATOR" + ": " + "content"
                // to process the information, split the line at "SEPARATOR" (one per line)
                //
                QStringList list = line.split(SEPARATOR, QString::SkipEmptyParts);

                if(!list.empty()) {
                    if (list.size() == 2) {
                        labeltext = list.at(0);
                        contenttext = list.at(1);
                    }
                    // handle corrupt lines
                    else {

                        labeltext = "invalid";
                        contenttext = "invalid";
                   }
                }
                // handle empty lines
                else {
                        labeltext = "";
                        contenttext = "";
                }


                QString* newlabel = new QString;
                QString* newcontent = new QString;

                *newlabel = labeltext;
                *newcontent = contenttext;


                // if the line is not empty, append the current line to the data structure
                // note that corrupted lines will still be added (marked as "invalid"
                if (labeltext != "") {   CPUlist.at(CPUlist.size()-1)->labellist.append(newlabel); }
                if (contenttext != "") { CPUlist.at(CPUlist.size()-1)->contentlist.append(newcontent); }

                }

            //qDebug() << "file end reached";
            file.close();

            // delete first element of CPUlist if the file contains a header of any type (i.e. the first line does not contain the string "processor"
            if (!CPUlist.empty())
            {
                if (CPUlist.first()->labellist.empty())
                {                    
                    CPUlist.removeFirst();
                }
                else if (!CPUlist.first()->labellist.first()->contains("processor"))
                {
                    CPUlist.removeFirst();
                }
            }


            // return status
            if (CPUlist.empty())
            {
                qDebug() << "No valid CPU information found in file";
                return "No valid CPU information found in file!";
            }
            else
            {
                qDebug() << "CPU Information read successfully";
                return  "CPU Information read successfully: " + QString::number(CPUlist.size()) + " CPUs found!";
            }
    }



    private:


    signals:


    public slots:


};


#endif // CPUINFOREADER_H






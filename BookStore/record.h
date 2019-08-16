#ifndef RECORD_H
#define RECORD_H
#include"AString.h"
class Record{
protected:
    AString recordNumber;
public:

    Record(const AString & number ="0000"){
        recordNumber = number;
    }
    bool setRecordNumber(const AString& numberValue){
        recordNumber = numberValue;
        return true;
    }
    AString getRecordNumber()const{
        return recordNumber;
    }
};
#endif // RECORD_H

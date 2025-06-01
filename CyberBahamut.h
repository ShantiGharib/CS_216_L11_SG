#ifndef CYBERBAHAMUT_H
#define CYBERBAHAMUT_H
#include "Bahamut.h"

class CyberBahamut : public Bahamut {
public:
    CyberBahamut();
    CyberBahamut(const CyberBahamut& source);

    ~CyberBahamut();

    virtual int GetDamage() const override;
    virtual std::string ToString() const override;

};


#endif

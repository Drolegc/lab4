#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>

class Fabrica {
    private:
        static ISistema* instance;
        Fabrica();
    public:
        static ISistema* getInstance();
};

#endif /* FABRICA_H */


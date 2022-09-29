#ifndef contenitore_hpp
#define contenitore_hpp

#include <iostream>

class contenitore {
    private:
        int qt;
    public:
        contenitore();
        void versa(int);
        void togli(int);
        int getQt() const;
};

#endif
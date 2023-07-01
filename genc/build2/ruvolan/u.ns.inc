// ruvolan/u.n
#pragma once
namespace u {
    struct Application;
    struct File;
}
#include "u/Word.hpp"
namespace u {
    typedef ::vas::DerivedSharedPtr<Application, ::u::File > ApplicationShp;
    typedef ::vas::DerivedWeakPtr<Application, ::u::File > ApplicationWkp;
#include "u/Word.hpp"
    extern const Word words[];
}

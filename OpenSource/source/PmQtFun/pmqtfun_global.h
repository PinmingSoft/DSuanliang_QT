#ifndef PMQTFUN_GLOBAL_H
#define PMQTFUN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef PMQTFUN_LIB
# define PMQTFUN_EXPORT Q_DECL_EXPORT
#else
# define PMQTFUN_EXPORT Q_DECL_IMPORT
#endif

#endif // PMQTFUN_GLOBAL_H

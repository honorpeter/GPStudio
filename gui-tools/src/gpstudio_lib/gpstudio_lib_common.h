#ifndef GPSTUDIO_LIB_COMMON_H
#define GPSTUDIO_LIB_COMMON_H

#include <Qt>

#if defined(GPSTUDIO_LIB_EXPORT_LIB)
#  define GPSTUDIO_LIB_EXPORT Q_DECL_EXPORT
#else
#  define GPSTUDIO_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // GPSTUDIO_LIB_COMMON_H


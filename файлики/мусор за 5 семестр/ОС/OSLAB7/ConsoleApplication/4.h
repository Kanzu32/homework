#pragma once

#if !defined(__4_H__)
#define __4_H__
#ifdef DLL4_EXPORTS
#define DLL4_API __declspec(dllexport)
#else
#define DLL4_API __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C" {
#endif

DLL4_API void printParameters();

#ifdef __cplusplus
}
#endif

#endif

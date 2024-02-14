#pragma once

#if !defined(__3_H__)
#define __3_H__
#ifdef DLL3_EXPORTS
#define DLL3_API __declspec(dllexport)
#else
#define DLL3_API __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C" {
#endif

DLL3_API void printMetrics();

#ifdef __cplusplus
}
#endif

#endif
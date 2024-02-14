#pragma once

#if !defined(__2_H__)
#define __2_H__
#ifdef SAMPLEDLL_EXPORTS
#define SAMPLEDLL_API __declspec(dllexport)
#else
#define SAMPLEDLL_API __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C" {
#endif

SAMPLEDLL_API void printAllPaths();
SAMPLEDLL_API void printWindowsVersion();
SAMPLEDLL_API void printTime();

#ifdef __cplusplus
}
#endif

#endif
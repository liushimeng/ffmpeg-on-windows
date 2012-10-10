/**   
 *	StrongFFplugin ²å¼þ
 */
#ifndef STRONGFFPLUGIN_H_2012_10_10_LSM
#define STRONGFFPLUGIN_H_2012_10_10_LSM

#ifdef STRONGFFPLUGIN_EXPORTS
#define STRONGFFPLUGIN_DLL_API __declspec(dllexport)
#else
#define STRONGFFPLUGIN_DLL_API __declspec(dllimport)
#pragma comment(lib, "StrongFFplugin.lib")
#endif

extern "C" STRONGFFPLUGIN_DLL_API int av_register_strongffplugin();

#endif
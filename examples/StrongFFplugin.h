/**   
 *	StrongFFplugin 插件
 */
#ifndef STRONGFFPLUGIN_H_2012_10_10_LSM
#define STRONGFFPLUGIN_H_2012_10_10_LSM

#ifdef STRONGFFPLUGIN_EXPORTS
#define STRONGFFPLUGIN_DLL_API __declspec(dllexport)
#else
#define STRONGFFPLUGIN_DLL_API __declspec(dllimport)
#pragma comment(lib, "StrongFFplugin.lib")
#endif

#define X264_ENCODER_NAME					"x264Encoder"		//x264视频编码器
#define LIBAACPLUS_ENCODER_NAME				"libaacplus"		//aacplus音频编码器
#define LIBFAAC_ENCODER_NAME				"libfaac"			//faac音频编码器
#define STICK_FIGURE_NAME					"stickfigure"		//stickfigure视频特效
#define FILE_PROTOCOL_NAME					"file"				//file协议（文件名采用多字符集）

extern "C" STRONGFFPLUGIN_DLL_API int av_register_strongffplugin(void * module);

#endif
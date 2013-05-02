/**   
 *	-----------------------------------------------------------------------------
 *								StrongFFplugin
 *					 Copyright(C) 2010-2013 lsm 版本所有
 *	-----------------------------------------------------------------------------
 */

#ifndef STRONGFFPLUGIN_H_2012_10_10_LSM
#define STRONGFFPLUGIN_H_2012_10_10_LSM

#ifdef __cplusplus
#define ECTERN_C extern "C" 
extern "C" {
#include <stdint.h>
}
#else
#define ECTERN_C
#include <stdint.h>
#endif

#if STRONGFFPLUGIN_EXPORTS
#define STRONGFFPLUGIN_DLL_API __declspec(dllexport)
#else
#define STRONGFFPLUGIN_DLL_API __declspec(dllimport)
#pragma comment(lib, "StrongFFplugin.lib")
#endif


#define STRONGFFPLUGIN_VALID_DATE_YEAR		2013		//有效期 年
#define STRONGFFPLUGIN_VALID_DATE_MONTH		6			//有效期 月
#define STRONGFFPLUGIN_VALID_DATE_DAY		1			//有效期 日 


#define X264_ENCODER_NAME					"x264Encoder"		//x264视频编码器	
#define X265_ENCODER_NAME					"x265Encoder"		//x265视频编码器	
#define INTEL_AVC_DECODER_NAME				"intelAVCDecoder"	//intel视频解码器
#define INTEL_ENCODER_NAME					"intelEncoder"		//intel视频编码器
#define LIBAACPLUS_ENCODER_NAME				"libaacplus"		//aacplus音频编码器
#define LIBFAAC_ENCODER_NAME				"libfaac"			//faac音频编码器
#define STICK_FIGURE_NAME					"stickfigure"		//stickfigure视频特效
#define FILE_PROTOCOL_NAME					"file"				//file协议
#define SUBHANG_AVFILTER_NAME				"subHang"			//subHang字幕视频滤器
#define PIPE_PROTOCOL_NAME					"pipe"				//pipe命名管道协议
#define AVFS_FORMAT_NAME					"avfs"				//avfs文件容器
#define H265_FORMAT_NAME					"h265"				//h265文件容器



#define AV_REGISTER_SFFPLUGIN_FLAG_FORCE_INTEL_HARDWARE			0x01	//强制注册intel硬件编解码器，没有硬件将使用intel软件编解码

/**
 *	插件注册
 *	flag : 注册时参数
 *			AV_REGISTER_SFFPLUGIN_FLAG_FORCE_INTEL_HARDWARE
 */
ECTERN_C STRONGFFPLUGIN_DLL_API int av_register_strongffplugin(void * module,int reg_flag = 0);


#endif

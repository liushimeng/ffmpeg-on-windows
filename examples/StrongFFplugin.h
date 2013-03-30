/**   
 *	StrongFFplugin and FEEServer 
 *	Copyright(C) 2010-2013 lsm 版本所有
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

#ifdef STRONGFFPLUGIN_EXPORTS
#define STRONGFFPLUGIN_DLL_API __declspec(dllexport)
#else
#define STRONGFFPLUGIN_DLL_API __declspec(dllimport)
#pragma comment(lib, "StrongFFplugin.lib")
#endif

/**
 *	-----------------------------------------------------------------------------
 *								StrongFFplugin
 *	-----------------------------------------------------------------------------
 */

#define X264_AVC_ENCODER_NAME				"x264AVCEncoder"	//x264视频编码器		
#define INTEL_AVC_DECODER_NAME				"intelAVCDecoder"	//intel视频解码器
#define INTEL_AVC_ENCODER_NAME				"intelAVCEncoder"	//intel视频编码器
#define LIBAACPLUS_ENCODER_NAME				"libaacplus"		//aacplus音频编码器
#define LIBFAAC_ENCODER_NAME				"libfaac"			//faac音频编码器
#define STICK_FIGURE_NAME					"stickfigure"		//stickfigure视频特效
#define FILE_PROTOCOL_NAME					"file"				//file协议
#define SUBHANG_AVFILTER_NAME				"subHang"			//subHang字幕视频滤器
#define PIPE_PROTOCOL_NAME					"pipe"				//pipe命名管道协议
#define AVFS_FORMAT_NAME					"avfs"				//avfs文件容器



#define AV_REGISTER_SFFPLUGIN_FLAG_FORCE_INTEL_HARDWARE			0x01	//强制注册intel硬件编解码器，没有硬件将使用intel软件编解码
/**
 *	插件注册
 *	flag : 注册时参数
 */
ECTERN_C STRONGFFPLUGIN_DLL_API int av_register_strongffplugin(void * module,int reg_flag = 0);


















/**
 *	-----------------------------------------------------------------------------
 *	                      Fast Easy Efficient Media Server
 *	-----------------------------------------------------------------------------
 *
 *	开发中。。。 。。。
 *
 */

#define FEEMSERVER_FREE_VERSION 1
#define FEESERVER_NOFREE_VERSION_AD "正式版本:StrongFFplugin无模块限制;FEEMServer无次数限制;ffparse源码等等."
#define FEEMSERVER_NOFREE_VERSION_STRING "仅在正式版本支持"
#define MAX_USE_REGISTER_APP_NUMBER 10

enum enFEEMSError
{
	enFEEMSError_NotFree = -3,
	enFEEMSError_LOG_CONFIG = -2,
	enFEEMSError_Param = -1,
	enFEEMSError_No = 0,
};

/**
 *	初始化库
 *	Param:
 *		log_dir_path			日志文件所在文件夹，NULL is current dir
 */
ECTERN_C STRONGFFPLUGIN_DLL_API int InitFEEMServer(char * log_dir_path);


/**
 *	释放库
 */
ECTERN_C STRONGFFPLUGIN_DLL_API void DestroyFEEMServer();


#endif
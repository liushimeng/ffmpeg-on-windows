/*
	作者:				lsm
	最后修改时间:		2012-6-19

	为修改ffmpeg库而创建的头文件
	注释有：(由ffmpeg引用)

	有注释都是有待参考的，不确定的
*/
#ifndef FILE_FFMPEG_G_COMMON_H
#define FILE_FFMPEG_G_COMMON_H

#pragma once

//临时
#define COMPILER_VC_WINDOWS				1		//操作系统

#define CONFIG_AVUTIL					1
#define CONFIG_AVFORMAT					1
#define CONFIG_AVCODEC					1
#define CONFIG_AVFILTER					1
#define CONFIG_SWSCALE					1
#define CONFIG_SWRESAMPLE				1
#define CONFIG_AVDEVICE					1
#define CONFIG_POSTPROC					1
#ifndef CONFIG_NETWORK
#define CONFIG_NETWORK					0
#endif
#define HAVE_ALTIVEC_H					0

#define FFMPEG_CONFIGURATION			""
#define FFMPEG_VERSION					""
#define FFMPEG_DATADIR					"/usr/local/ffmpeg"
#define AVCONV_DATADIR					"/usr/home/ffmpeg"

#define CONFIG_NONFREE					1		//非公开授权
#define CONFIG_GPL						0		//GPL授权
#define CONFIG_GPLV3					0		//GPLV3授权
#define CONFIG_LGPLV3					0		//LGPLV3授权

//#define AV_PIX_FMT_ABI_GIT_MASTER		0		//不支持 高色区空间
#define HAVE_GETRUSAGE					0		//linux		使用外部时间
#define HAVE_SYS_RESOURCE_H				0		//linux		system time out
#define HAVE_GETPROCESSTIMES			0		//windows	使用外部时间
#define HAVE_TERMIOS_H					0		//term ios
#define HAVE_KBHIT						1		//key board control
#define HAVE_PEEKNAMEDPIPE				0		//peek pipe control
#define HAVE_COMMANDLINETOARGVW			1		//commandline

#define CONFIG_RTSP_DEMUXER				1		//RTSP Demuxer
#define CONFIG_MMSH_PROTOCOL			0		//MMSH Protocol

//宏开关
#if CONFIG_LIBX264_ENCODER
#include "./libavutil/libm.h"
#endif

#if (COMPILER_VC_WINDOWS)

#ifdef __cplusplus
extern "C" {
#endif

	//Windows 添加处理
#define inline __inline 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stddef.h>
#include <float.h>
#include <windows.h>
#include <math.h>

#define		PRIu16			"I16u"
#define		PRIu32			"I32u"
#define		PRIX64			"I64X"
#define		PRId64			"I64d"
#define		PRIu64			"I64u"
#define		PRIx64			"I64x"
#define 	usleep			Sleep
//#define		isnan			_isnan
#define		snprintf		_snprintf
#define		strcasecmp		_stricmp
#define		strncasecmp		strncmp 
#define		pid_t			DWORD
#define		CC_TYPE			"vc"
#define		CC_VERSION		"vc10"
#define     CC_IDENT		"ms-cl"

#define HAVE_GETPROCESSMEMORYINFO		0		//pro info
#if HAVE_GETPROCESSMEMORYINFO
#pragma comment(lib,"Psapi.lib")
#endif

//math function
#define		HAVE_ATANF		1
#define		HAVE_POWF		1
#define		HAVE_ATAN2F		1
#define		HAVE_COSF		1
#define		HAVE_EXPF		1
#define		HAVE_LDEXPF		1
#define		HAVE_SINF		1

int isinf_i386(double x);

#include <time.h>
#if !WINVER
#include <sys/time.h>
#endif

int gettimeofday(struct timeval *tp, void *tzp);

#ifdef __cplusplus
}
#endif

#elif (COMPILER_GCC_LINUX)
#include <inttypes.h>
#include <stdint.h>
#define CC_TYPE "gcc"
#define CC_VERSION __VERSION__
#define restrict restrict
#elif (COMPILER_XCODE_IOS)
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stddef.h>
#elif (COMPILER_GCC_ANDROID)
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stddef.h>
#define CC_TYPE "gcc"
#define CC_VERSION __VERSION__
#define restrict __restrict
#endif

#endif

//Other example if you need .
//#define EXTERN_PREFIX "_"
//#define EXTERN_ASM _
//#define SLIBSUF ".dll"
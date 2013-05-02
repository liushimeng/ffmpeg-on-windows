/*
	作者:				lsm
	最后修改时间:		2012-04-28
	文件头
	lib文件夹加入到附加目录中
*/
#ifndef FILE_FFMPEG_G_INCLUDE_H
#define FILE_FFMPEG_G_INCLUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "./g_common.h"

/* -------------- 头文件 ------------- */
#if CONFIG_AVUTIL
#include "./libavutil/avutil.h"
#include "./libavutil/mem.h"
#include "./libavutil/fifo.h"
#include "./libavutil/pixdesc.h"
#include "./libavutil/imgutils.h"
#include "./libavutil/avassert.h"
#include "./libavutil/opt.h"
#include "./libavutil/avstring.h"
#include "./libavutil/intreadwrite.h"
#include "./libavutil/parseutils.h"
#include "./libavutil/bprint.h"
#include "./libavutil/time.h"
#include "./libavutil/intfloat.h"
#include "./libavutil/timecode.h"
#include "./libavutil/timestamp.h"	//extern include
#include "./libavutil/libm.h"			//not public API
#include "./libavutil/eval.h"
#include "./libavutil/colorspace.h"
#endif

#if CONFIG_AVFORMAT
#include "./libavformat/avformat.h"
#include "./libavformat/avio.h"
#include "./libavformat/url.h"
#include "./libavformat/internal.h"
#include "./libavformat/flv.h"
#if CONFIG_NETWORK
#include "./libavformat/rtsp.h"
#endif
#endif

#if CONFIG_AVFILTER
#include "./libavfilter/avfilter.h"
#include "./libavfilter/avfiltergraph.h"
#include "./libavfilter/buffersink.h"
#include "./libavfilter/buffersrc.h"
#include "./libavfilter/avcodec.h"
#include "./libavfilter/formats.h"
#endif

#if CONFIG_AVCODEC
#include "./libavcodec/avcodec.h"
#include "./libavcodec/internal.h"
#include "./libavcodec/parser.h"
#endif

#if CONFIG_SWSCALE
#include "./libswscale/swscale.h"
#include "./libswscale/swscale_internal.h"
#endif

#if CONFIG_SWRESAMPLE
#include "./libswresample/swresample.h"
#include "./libswresample/swresample_internal.h"
#endif

#if CONFIG_AVDEVICE
#include "./libavdevice/avdevice.h"
#endif

#if CONFIG_POSTPROC
#include "./libpostproc/postprocess.h"
#endif

/* -------------- 导入库 --------------*/
#if CONFIG_AVUTIL
#pragma comment(lib,"avutil.lib")
#endif
#if CONFIG_AVFORMAT
#pragma comment(lib,"avformat.lib")
#endif
#if CONFIG_AVCODEC
#pragma comment(lib,"avcodec.lib")
#endif
#if CONFIG_AVFILTER
#pragma comment(lib,"avfilter.lib")
#endif
#if CONFIG_SWSCALE
#pragma comment(lib,"swscale.lib")
#endif
#if CONFIG_SWRESAMPLE
#pragma comment(lib,"swresample.lib")
#endif
#if CONFIG_AVDEVICE
#pragma comment(lib,"avdevice.lib")
#endif
#if CONFIG_POSTPROC
#pragma comment(lib,"postproc.lib")
#endif

#ifdef __cplusplus
}
#endif

#endif
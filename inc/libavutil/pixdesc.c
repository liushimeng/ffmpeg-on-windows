/*
 * pixel format descriptor
 * Copyright (c) 2009 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stdio.h>
#include <string.h>
#include "pixfmt.h"
#include "pixdesc.h"

#include "intreadwrite.h"

const AVPixFmtDescriptor av_pix_fmt_descriptors[PIX_FMT_NB] = {
    {//[PIX_FMT_YUV420P] = 0
       "yuv420p",// .name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUYV422] = 1
        "yuyv422",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		0,
        {//.comp = 
            { 0, 1, 1, 0, 7 },        /* Y */
            { 0, 3, 2, 0, 7 },        /* U */
            { 0, 3, 4, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_RGB24] = 2
        "rgb24",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 2, 1, 0, 7 },        /* R */
            { 0, 2, 2, 0, 7 },        /* G */
            { 0, 2, 3, 0, 7 },        /* B */
        },
    },
    {//[PIX_FMT_BGR24] = 3
        "bgr24",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 2, 3, 0, 7 },        /* R */
            { 0, 2, 2, 0, 7 },        /* G */
            { 0, 2, 1, 0, 7 },        /* B */
        },
    },
    {//[PIX_FMT_YUV422P] = 4
        "yuv422p",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P] = 5
        "yuv444p",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,// .flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUV410P] = 6
        "yuv410p",//.name = 
        3,//.nb_components = 
        2,//.log2_chroma_w = 
        2,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUV411P] = 7
        "yuv411p",//.name = 
        3,//.nb_components = 
        2,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_GRAY8] = 8
        "gray",//.name = 
        1,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PSEUDOPAL,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
        },
    },
    {//[PIX_FMT_MONOWHITE] = 9
        "monow",//.name = 
        1,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BITSTREAM,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 0 },        /* Y */
        },
    },
    {//[PIX_FMT_MONOBLACK] = 10
        "monob",//.name = 
        1,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BITSTREAM,//.flags = 
        {//.comp = 
            { 0, 0, 1, 7, 0 },        /* Y */
        },
    },
    {//[PIX_FMT_PAL8] = 11
        "pal8",//.name = 
        1,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PAL,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },
        },
    },
    {//[PIX_FMT_YUVJ420P] = 12
        "yuvj420p",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUVJ422P] = 13
        "yuvj422p",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUVJ444P] = 14
        "yuvj444p",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_XVMC_MPEG2_MC] = 15
        "xvmcmc",//.name = 
		0,
		0,
		0,
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_XVMC_MPEG2_IDCT] = 16
        "xvmcidct",//.name = 
		0,
		0,
		0,
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_UYVY422] = 17
        "uyvy422",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		0,
        {//.comp = 
            { 0, 1, 2, 0, 7 },        /* Y */
            { 0, 3, 1, 0, 7 },        /* U */
            { 0, 3, 3, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_UYYVYY411] = 18
        "uyyvyy411",//.name = 
        3,//.nb_components = 
        2,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		0,
        {//.comp = 
            { 0, 3, 2, 0, 7 },        /* Y */
            { 0, 5, 1, 0, 7 },        /* U */
            { 0, 5, 4, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_BGR8] = 19
        "bgr8",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB | PIX_FMT_PSEUDOPAL,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 2 },        /* R */
            { 0, 0, 1, 3, 2 },        /* G */
            { 0, 0, 1, 6, 1 },        /* B */
        },
    },
    {//[PIX_FMT_BGR4] = 20
        "bgr4",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BITSTREAM | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 4, 0, 0 },        /* R */
            { 0, 3, 2, 0, 1 },        /* G */
            { 0, 3, 1, 0, 0 },        /* B */
        },
    },
    {//[PIX_FMT_BGR4_BYTE] = 21
        "bgr4_byte",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB | PIX_FMT_PSEUDOPAL,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 0 },        /* R */
            { 0, 0, 1, 1, 1 },        /* G */
            { 0, 0, 1, 3, 0 },        /* B */
        },
    },
    {//[PIX_FMT_RGB8] = 22
        "rgb8",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB | PIX_FMT_PSEUDOPAL,//.flags = 
        {//.comp = 
            { 0, 0, 1, 6, 1 },        /* R */
            { 0, 0, 1, 3, 2 },        /* G */
            { 0, 0, 1, 0, 2 },        /* B */
        },
    },
    {//[PIX_FMT_RGB4] = 23
        "rgb4",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BITSTREAM | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 1, 0, 0 },        /* R */
            { 0, 3, 2, 0, 1 },        /* G */
            { 0, 3, 4, 0, 0 },        /* B */
        },
    },
    {//[PIX_FMT_RGB4_BYTE] = 24
        "rgb4_byte",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB | PIX_FMT_PSEUDOPAL,//.flags = 
        {//.comp = 
            { 0, 0, 1, 3, 0 },        /* R */
            { 0, 0, 1, 1, 1 },        /* G */
            { 0, 0, 1, 0, 0 },        /* B */
        },
    },
    {//[PIX_FMT_NV12] = 25
        "nv12",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 1, 1, 0, 7 },        /* U */
            { 1, 1, 2, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_NV21] = 26
        "nv21",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 1, 2, 0, 7 },        /* U */
            { 1, 1, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_ARGB] = 27
        "argb",//.name = 
        4,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 2, 0, 7 },        /* R */
            { 0, 3, 3, 0, 7 },        /* G */
            { 0, 3, 4, 0, 7 },        /* B */
            { 0, 3, 1, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_RGBA] = 28
        "rgba",//.name = 
        4,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 1, 0, 7 },        /* R */
            { 0, 3, 2, 0, 7 },        /* G */
            { 0, 3, 3, 0, 7 },        /* B */
            { 0, 3, 4, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_ABGR] = 29
        "abgr",//.name = 
        4,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 4, 0, 7 },        /* R */
            { 0, 3, 3, 0, 7 },        /* G */
            { 0, 3, 2, 0, 7 },        /* B */
            { 0, 3, 1, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_BGRA] = 30
        "bgra",//.name = 
        4,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 3, 0, 7 },        /* R */
            { 0, 3, 2, 0, 7 },        /* G */
            { 0, 3, 1, 0, 7 },        /* B */
            { 0, 3, 4, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_GRAY16BE] = 31
        "gray16be",//.name = 
        1,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 15 },       /* Y */
        },
    },
    {//[PIX_FMT_GRAY16LE] = 32
        "gray16le",//.name = 
        1,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		0,
        {//.comp = 
            { 0, 1, 1, 0, 15 },       /* Y */
        },
    },
    {//[PIX_FMT_YUV440P] = 33
        "yuv440p",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUVJ440P] = 34
        "yuvj440p",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
        },
    },
    {//[PIX_FMT_YUVA420P] = 35
        "yuva420p",//.name = 
        4,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
            { 3, 0, 1, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_VDPAU_H264] = 36
        "vdpau_h264",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_VDPAU_MPEG1] = 37
        "vdpau_mpeg1",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_VDPAU_MPEG2] = 38
        "vdpau_mpeg2",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_VDPAU_WMV3] = 39
        "vdpau_wmv3",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_VDPAU_VC1] = 40
        "vdpau_vc1",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_RGB48BE] = 41
        "rgb48be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB | PIX_FMT_BE,//.flags = 
        {//.comp = 
            { 0, 5, 1, 0, 15 },       /* R */
            { 0, 5, 3, 0, 15 },       /* G */
            { 0, 5, 5, 0, 15 },       /* B */
        },
    },
    {//[PIX_FMT_RGB48LE] = 42
        "rgb48le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 5, 1, 0, 15 },       /* R */
            { 0, 5, 3, 0, 15 },       /* G */
            { 0, 5, 5, 0, 15 },       /* B */
        },
    },
    {//[PIX_FMT_RGB565BE] = 43
        "rgb565be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 0, 3, 4 },        /* R */
            { 0, 1, 1, 5, 5 },        /* G */
            { 0, 1, 1, 0, 4 },        /* B */
        },
    },
    {//[PIX_FMT_RGB565LE] = 44
        "rgb565le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 2, 3, 4 },        /* R */
            { 0, 1, 1, 5, 5 },        /* G */
            { 0, 1, 1, 0, 4 },        /* B */
        },
    },
    {//[PIX_FMT_RGB555BE] = 45
        "rgb555be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 0, 2, 4 },        /* R */
            { 0, 1, 1, 5, 4 },        /* G */
            { 0, 1, 1, 0, 4 },        /* B */
        },
    },
    {//[PIX_FMT_RGB555LE] = 46
        "rgb555le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 2, 2, 4 },        /* R */
            { 0, 1, 1, 5, 4 },        /* G */
            { 0, 1, 1, 0, 4 },        /* B */
        },
    },
    {//[PIX_FMT_BGR565BE] = 47
        "bgr565be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 4 },        /* R */
            { 0, 1, 1, 5, 5 },        /* G */
            { 0, 1, 0, 3, 4 },        /* B */
        },
    },
    {//[PIX_FMT_BGR565LE] = 48
        "bgr565le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 4 },        /* R */
            { 0, 1, 1, 5, 5 },        /* G */
            { 0, 1, 2, 3, 4 },        /* B */
        },
    },
    {//[PIX_FMT_BGR555BE] = 49
        "bgr555be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 4 },       /* R */
            { 0, 1, 1, 5, 4 },       /* G */
            { 0, 1, 0, 2, 4 },       /* B */
        },
     },
    {//[PIX_FMT_BGR555LE] = 50
        "bgr555le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 4 },        /* R */
            { 0, 1, 1, 5, 4 },        /* G */
            { 0, 1, 2, 2, 4 },        /* B */
        },
    },
    {//[PIX_FMT_VAAPI_MOCO] = 51
        "vaapi_moco",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_VAAPI_IDCT] = 52
        "vaapi_idct",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_VAAPI_VLD] = 53
        "vaapi_vld",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_YUV420P16LE] = 54
        "yuv420p16le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 15 },        /* Y */
            { 1, 1, 1, 0, 15 },        /* U */
            { 2, 1, 1, 0, 15 },        /* V */
        },
    },
    {//[PIX_FMT_YUV420P16BE] = 55
        "yuv420p16be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 15 },        /* Y */
            { 1, 1, 1, 0, 15 },        /* U */
            { 2, 1, 1, 0, 15 },        /* V */
        },
    },
    {//[PIX_FMT_YUV422P16LE] = 56
        "yuv422p16le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 15 },        /* Y */
            { 1, 1, 1, 0, 15 },        /* U */
            { 2, 1, 1, 0, 15 },        /* V */
        },
    },
    {//[PIX_FMT_YUV422P16BE] = 57
        "yuv422p16be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 15 },        /* Y */
            { 1, 1, 1, 0, 15 },        /* U */
            { 2, 1, 1, 0, 15 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P16LE] = 58
        "yuv444p16le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 15 },        /* Y */
            { 1, 1, 1, 0, 15 },        /* U */
            { 2, 1, 1, 0, 15 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P16BE] = 59
        "yuv444p16be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 15 },        /* Y */
            { 1, 1, 1, 0, 15 },        /* U */
            { 2, 1, 1, 0, 15 },        /* V */
        },
    },
    {//[PIX_FMT_VDPAU_MPEG4] = 60
        "vdpau_mpeg4",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_DXVA2_VLD] = 61
        "dxva2_vld",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
	{//[PIX_FMT_RGB444LE] = 62
        "rgb444le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 2, 0, 3 },        /* R */
            { 0, 1, 1, 4, 3 },        /* G */
            { 0, 1, 1, 0, 3 },        /* B */
        },
    },
    {//[PIX_FMT_RGB444BE] = 63
        "rgb444be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 0, 0, 3 },        /* R */
            { 0, 1, 1, 4, 3 },        /* G */
            { 0, 1, 1, 0, 3 },        /* B */
        },
    },
    {//[PIX_FMT_BGR444LE] = 64
        "bgr444le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 3 },        /* R */
            { 0, 1, 1, 4, 3 },        /* G */
            { 0, 1, 2, 0, 3 },        /* B */
        },
    },
    {//[PIX_FMT_BGR444BE] = 65
        "bgr444be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 3 },       /* R */
            { 0, 1, 1, 4, 3 },       /* G */
            { 0, 1, 0, 0, 3 },       /* B */
        },
     },
     {//[PIX_FMT_GRAY8A] = 66
        "gray8a",//.name = 
        2,//.nb_components = 
		0,
		0,
		0,
        {//.comp = 
            { 0, 1, 1, 0, 7 },        /* Y */
            { 0, 1, 2, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_BGR48BE] = 67
        "bgr48be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 5, 5, 0, 15 },       /* R */
            { 0, 5, 3, 0, 15 },       /* G */
            { 0, 5, 1, 0, 15 },       /* B */
        },
    },
    {//[PIX_FMT_BGR48LE] = 68
        "bgr48le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 5, 5, 0, 15 },       /* R */
            { 0, 5, 3, 0, 15 },       /* G */
            { 0, 5, 1, 0, 15 },       /* B */
        },
    },

    {//[PIX_FMT_YUV420P9BE] = 69
        "yuv420p9be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 8 },        /* Y */
            { 1, 1, 1, 0, 8 },        /* U */
            { 2, 1, 1, 0, 8 },        /* V */
        },
    },
    {//[PIX_FMT_YUV420P9LE] = 70
        "yuv420p9le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 8 },        /* Y */
            { 1, 1, 1, 0, 8 },        /* U */
            { 2, 1, 1, 0, 8 },        /* V */
        },
    },
    {//[PIX_FMT_YUV420P10BE] = 71
        "yuv420p10be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 9 },        /* Y */
            { 1, 1, 1, 0, 9 },        /* U */
            { 2, 1, 1, 0, 9 },        /* V */
        },
    },
    {//[PIX_FMT_YUV420P10LE] = 72
        "yuv420p10le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 9 },        /* Y */
            { 1, 1, 1, 0, 9 },        /* U */
            { 2, 1, 1, 0, 9 },        /* V */
        },
    },
    {//[PIX_FMT_YUV422P10BE] = 73
        "yuv422p10be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 9 },        /* Y */
            { 1, 1, 1, 0, 9 },        /* U */
            { 2, 1, 1, 0, 9 },        /* V */
        },
    },
    {//[PIX_FMT_YUV422P10LE] = 74
        "yuv422p10le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 9 },        /* Y */
            { 1, 1, 1, 0, 9 },        /* U */
            { 2, 1, 1, 0, 9 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P9BE] = 75
        "yuv444p9be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 8 },        /* Y */
            { 1, 1, 1, 0, 8 },        /* U */
            { 2, 1, 1, 0, 8 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P9LE] = 76
        "yuv444p9le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 8 },        /* Y */
            { 1, 1, 1, 0, 8 },        /* U */
            { 2, 1, 1, 0, 8 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P10BE] = 77
        "yuv444p10be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 9 },        /* Y */
            { 1, 1, 1, 0, 9 },        /* U */
            { 2, 1, 1, 0, 9 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P10LE] = 78
        "yuv444p10le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 9 },        /* Y */
            { 1, 1, 1, 0, 9 },        /* U */
            { 2, 1, 1, 0, 9 },        /* V */
        },
    },
    {//[PIX_FMT_YUV422P9BE] = 79
        "yuv422p9be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 8 },        /* Y */
            { 1, 1, 1, 0, 8 },        /* U */
            { 2, 1, 1, 0, 8 },        /* V */
        },
    },
    {//[PIX_FMT_YUV422P9LE] = 80
        "yuv422p9le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 8 },        /* Y */
            { 1, 1, 1, 0, 8 },        /* U */
            { 2, 1, 1, 0, 8 },        /* V */
        },
    },
    {//[PIX_FMT_VDA_VLD] = 81
        "vda_vld",//.name = 
		0,
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_HWACCEL,//.flags = 
		0,
    },
    {//[PIX_FMT_GBRP] = 82
        "gbrp",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 0, 1, 0, 7 },        /* R */
            { 0, 0, 1, 0, 7 },        /* G */
            { 1, 0, 1, 0, 7 },        /* B */
        },
    },
    {//[PIX_FMT_GBRP9BE] = 83
        "gbrp9be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 8 },        /* R */
            { 0, 1, 1, 0, 8 },        /* G */
            { 1, 1, 1, 0, 8 },        /* B */
        },
    },
    {//[PIX_FMT_GBRP9LE] = 84
        "gbrp9le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 8 },        /* R */
            { 0, 1, 1, 0, 8 },        /* G */
            { 1, 1, 1, 0, 8 },        /* B */
        },
    },
    {//[PIX_FMT_GBRP10BE] = 85
        "gbrp10be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 9 },        /* R */
            { 0, 1, 1, 0, 9 },        /* G */
            { 1, 1, 1, 0, 9 },        /* B */
        },
    },
    {//[PIX_FMT_GBRP10LE] = 86
        "gbrp10le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 9 },        /* R */
            { 0, 1, 1, 0, 9 },        /* G */
            { 1, 1, 1, 0, 9 },        /* B */
        },
    },
    {//[PIX_FMT_GBRP16BE] = 87
        "gbrp16be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 15 },       /* R */
            { 0, 1, 1, 0, 15 },       /* G */
            { 1, 1, 1, 0, 15 },       /* B */
        },
    },
    {//[PIX_FMT_GBRP16LE] = 88
        "gbrp16le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 15 },       /* R */
            { 0, 1, 1, 0, 15 },       /* G */
            { 1, 1, 1, 0, 15 },       /* B */
        },
    },
	{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
	{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},
    {//[PIX_FMT_RGBA64BE] = 291
        "rgba64be",//.name = 
        4,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_RGB | PIX_FMT_BE,//.flags = 
        {//.comp = 
            { 0, 7, 1, 0, 15 },       /* R */
            { 0, 7, 3, 0, 15 },       /* G */
            { 0, 7, 5, 0, 15 },       /* B */
            { 0, 7, 7, 0, 15 },       /* A */
        },
    },
    {//[PIX_FMT_RGBA64LE] = 292
        "rgba64le",//.name = 
        4,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 7, 1, 0, 15 },       /* R */
            { 0, 7, 3, 0, 15 },       /* G */
            { 0, 7, 5, 0, 15 },       /* B */
            { 0, 7, 7, 0, 15 },       /* A */
        },
    },
    {//[PIX_FMT_BGRA64BE] = 293
        "bgra64be",//.name = 
        4,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_BE | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 7, 5, 0, 15 },       /* R */
            { 0, 7, 3, 0, 15 },       /* G */
            { 0, 7, 1, 0, 15 },       /* B */
            { 0, 7, 7, 0, 15 },       /* A */
        },
    },
    {//[PIX_FMT_BGRA64LE] = 294
        "bgra64le",//.name = 
        4,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 7, 5, 0, 15 },       /* R */
            { 0, 7, 3, 0, 15 },       /* G */
            { 0, 7, 1, 0, 15 },       /* B */
            { 0, 7, 7, 0, 15 },       /* A */
        },
    },
    {//[PIX_FMT_0RGB] = 295
        "0rgb",//.name = 
        3,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 2, 0, 7 },        /* R */
            { 0, 3, 3, 0, 7 },        /* G */
            { 0, 3, 4, 0, 7 },        /* B */
        },
    },
    {//[PIX_FMT_RGB0] = 296
        "rgb0",//.name = 
        3,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 1, 0, 7 },        /* R */
            { 0, 3, 2, 0, 7 },        /* G */
            { 0, 3, 3, 0, 7 },        /* B */
            { 0, 3, 4, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_0BGR] = 297
        "0bgr",//.name = 
        3,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 4, 0, 7 },        /* R */
            { 0, 3, 3, 0, 7 },        /* G */
            { 0, 3, 2, 0, 7 },        /* B */
        },
    },
    {//[PIX_FMT_BGR0] = 298
        "bgr0",//.name = 
        3,//.nb_components= 
        0,//.log2_chroma_w= 
        0,//.log2_chroma_h= 
        PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 0, 3, 3, 0, 7 },        /* R */
            { 0, 3, 2, 0, 7 },        /* G */
            { 0, 3, 1, 0, 7 },        /* B */
            { 0, 3, 4, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_YUVA444P] = 299
        "yuva444p",//.name = 
        4,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
            { 3, 0, 1, 0, 7 },        /* A */
        },
    },
    {//[PIX_FMT_YUVA422P] = 300
        "yuva422p",//.name = 
        4,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 0, 1, 0, 7 },        /* Y */
            { 1, 0, 1, 0, 7 },        /* U */
            { 2, 0, 1, 0, 7 },        /* V */
            { 3, 0, 1, 0, 7 },        /* A */
        },
    },
	{//[PIX_FMT_YUV420P12BE] = 301
        "yuv420p12be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
		PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
       {// .comp = 
            { 0, 1, 1, 0, 11 },        /* Y */
            { 1, 1, 1, 0, 11 },        /* U */
            { 2, 1, 1, 0, 11 },        /* V */
        },
    },
	{//[PIX_FMT_YUV420P12LE] = 302
        "yuv420p12le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
		PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 11 },        /* Y */
            { 1, 1, 1, 0, 11 },        /* U */
            { 2, 1, 1, 0, 11 },        /* V */
        },
	},
	{//[PIX_FMT_YUV420P14BE] = 303
        "yuv420p14be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
		PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 13 },        /* Y */
            { 1, 1, 1, 0, 13 },        /* U */
            { 2, 1, 1, 0, 13 },        /* V */
        },
    },
    {//[PIX_FMT_YUV420P14LE] = 304
        "yuv420p14le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        1,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 13 },        /* Y */
            { 1, 1, 1, 0, 13 },        /* U */
            { 2, 1, 1, 0, 13 },        /* V */
        },
    },
	{//[PIX_FMT_YUV422P12BE] = 305
        "yuv422p12be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 11 },        /* Y */
            { 1, 1, 1, 0, 11 },        /* U */
            { 2, 1, 1, 0, 11 },        /* V */
        },
    },
	{//[PIX_FMT_YUV422P12LE] = 306
        "yuv422p12le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 11 },        /* Y */
            { 1, 1, 1, 0, 11 },        /* U */
            { 2, 1, 1, 0, 11 },        /* V */
        },
    },
	{//[PIX_FMT_YUV422P14BE] = 307
        "yuv422p14be",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
       {//.comp = 
            { 0, 1, 1, 0, 13 },        /* Y */
            { 1, 1, 1, 0, 13 },        /* U */
            { 2, 1, 1, 0, 13 },        /* V */
        },
    },
    {//[PIX_FMT_YUV422P14LE] = 308
        "yuv422p14le",//.name = 
        3,//.nb_components = 
        1,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 13 },        /* Y */
            { 1, 1, 1, 0, 13 },        /* U */
            { 2, 1, 1, 0, 13 },        /* V */
        },
    },
	{//[PIX_FMT_YUV444P12BE] = 309
        "yuv444p12be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
	    PIX_FMT_BE | PIX_FMT_PLANAR,// .flags = 
        {//.comp = 
            { 0, 1, 1, 0, 11 },        /* Y */
            { 1, 1, 1, 0, 11 },        /* U */
            { 2, 1, 1, 0, 11 },        /* V */
        },
    },
	{//[PIX_FMT_YUV444P12LE] = 310
        "yuv444p12le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 11 },        /* Y */
            { 1, 1, 1, 0, 11 },        /* U */
            { 2, 1, 1, 0, 11 },        /* V */
        },
    },
	{//[PIX_FMT_YUV444P14BE] = 311
        "yuv444p14be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 13 },        /* Y */
            { 1, 1, 1, 0, 13 },        /* U */
            { 2, 1, 1, 0, 13 },        /* V */
        },
    },
    {//[PIX_FMT_YUV444P14LE] = 312
        "yuv444p14le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR,//.flags = 
        {//.comp = 
            { 0, 1, 1, 0, 13 },        /* Y */
            { 1, 1, 1, 0, 13 },        /* U */
            { 2, 1, 1, 0, 13 },        /* V */
        },
    },
	{//[PIX_FMT_GBRP12BE] = 313
        "gbrp12be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_BE | PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 11 },        /* R */
            { 0, 1, 1, 0, 11 },        /* G */
            { 1, 1, 1, 0, 11 },        /* B */
        },
    },
	{//[PIX_FMT_GBRP12LE] = 314
        "gbrp12le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
        PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 11 },        /* R */
            { 0, 1, 1, 0, 11 },        /* G */
            { 1, 1, 1, 0, 11 },        /* B */
        },
    },
	{//[PIX_FMT_GBRP14BE] = 315
        "gbrp14be",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		PIX_FMT_BE | PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 13 },        /* R */
            { 0, 1, 1, 0, 13 },        /* G */
            { 1, 1, 1, 0, 13 },        /* B */
        },
    },
    {//[PIX_FMT_GBRP14LE] = 316
        "gbrp14le",//.name = 
        3,//.nb_components = 
        0,//.log2_chroma_w = 
        0,//.log2_chroma_h = 
		PIX_FMT_PLANAR | PIX_FMT_RGB,//.flags = 
        {//.comp = 
            { 2, 1, 1, 0, 13 },        /* R */
            { 0, 1, 1, 0, 13 },        /* G */
            { 1, 1, 1, 0, 13 },        /* B */
        },
    },

};

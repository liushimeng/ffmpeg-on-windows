
// ffparseDlg.cpp : 实现文件
//

#include "stdafx_ffparse.h"
#include "ffparse.h"
#include "ffparseDlg.h"
#include "afxdialogex.h"
#include "../inc/g_include.h"

enum enFFElement
{
	enFFVideoDecoder = 0,
	enFFVideoEncoder,
	enFFAudioDecoder,
	enFFAudioEncoder,
	enFFSubtitleDecoder,
	enFFSubtitleEncoder,
	enFFFormatInput,
	enFFFormatOutput,
	enFFFilterVideo,
	enFFFilterAudio,
	enFFFilterOthers,
	enFFGeneralParam,
	enFFColorSpace,
	enFFAudioSampleFormat,
	enFFAudioChannelFormat,
	enFFAudioChannelLayout,
	enFFCodecParse,
	enFFBitstreamFilter,
	enFFHwaccel,
	enFFProtocol,
	enFFVersion,
	enFFConfiguration,
	enFFOthers,
};

char * str_enFFName[] = {
	"视频解码","视频编码","音频解码","音频编码","字幕解码","字幕编码","输入格式","输出格式",
	"视频滤器","音频滤器","其他滤器","通用参数","视频色彩空间","音频采样格式","音频声道类型","音频声道布局",
	"编解码解析器","比特流滤器","硬件加速","协议","版本信息",
	"编译配置","其他"
};

enum enFFGeneralParamType
{
	enFFCodecParams = 0,
	enFFAVFormatParams,
	enFFVedioColorSpaceParams,
	enFFAudioSampleFormatParams,
	enFFAVFrameParams,
	enFFSubtitleParams,
	enFFOtherParams,
};

char * str_enFFParamName[] = {
	"编解码上下文","容器格式上下文","视频色彩空间上下文","音频采样格式上下文","音视频帧","字幕处理","其他"
};

uint64_t channel_format_id[] = {
	AV_CH_FRONT_LEFT,
	AV_CH_FRONT_RIGHT,
	AV_CH_FRONT_CENTER,
	AV_CH_LOW_FREQUENCY,
	AV_CH_BACK_LEFT,
	AV_CH_BACK_RIGHT,
	AV_CH_FRONT_LEFT_OF_CENTER,
	AV_CH_FRONT_RIGHT_OF_CENTER,
	AV_CH_BACK_CENTER,
	AV_CH_SIDE_LEFT,
	AV_CH_SIDE_RIGHT,
	AV_CH_TOP_CENTER,
	AV_CH_TOP_FRONT_LEFT,
	AV_CH_TOP_FRONT_CENTER,
	AV_CH_TOP_FRONT_RIGHT,
	AV_CH_TOP_BACK_LEFT,
	AV_CH_TOP_BACK_CENTER,
	AV_CH_TOP_BACK_RIGHT,
	AV_CH_STEREO_LEFT,
	AV_CH_STEREO_RIGHT,
	AV_CH_WIDE_LEFT,
	AV_CH_WIDE_RIGHT,
	AV_CH_SURROUND_DIRECT_LEFT,
	AV_CH_SURROUND_DIRECT_RIGHT,
	AV_CH_LOW_FREQUENCY_2};

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CffparseDlg 对话框




CffparseDlg::CffparseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CffparseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CffparseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MAIN, m_CMainListBox);
	DDX_Control(pDX, IDC_LIST_SECOND, m_CSecondListBox);
	DDX_Control(pDX, IDC_LIST_THIRD, m_CThirdListBox);
	DDX_Control(pDX, IDC_EDIT_SHOW, m_CShowEdit);
	DDX_Control(pDX, IDC_STATIC_THIRD, m_CThirdStatic);
	DDX_Control(pDX, IDC_STATIC_SECOND, m_CSecondStatic);
	DDX_Control(pDX, IDC_STATIC_MAIN, m_CMainStatic);
}

BEGIN_MESSAGE_MAP(CffparseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_LIST_MAIN, &CffparseDlg::OnLbnDblclkListMain)
	ON_LBN_DBLCLK(IDC_LIST_SECOND, &CffparseDlg::OnLbnDblclkListSecond)
	ON_LBN_SELCHANGE(IDC_LIST_THIRD, &CffparseDlg::OnLbnSelchangeListThird)
END_MESSAGE_MAP()


// CffparseDlg 消息处理程序

BOOL CffparseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	//Version
	if(LIBAVUTIL_BUILD != avutil_version())
	{
		::MessageBoxA(m_hWnd,"ffmpeg dll version is validate!\r\n",NULL,MB_OK);
		exit(1);
	}
	else
	{
		for(int i = PIX_FMT_YUV420P;i<PIX_FMT_NB;i++)
		{
			const char * str = av_get_pix_fmt_name((PixelFormat)i);
			if(str && strcmp(av_pix_fmt_descriptors[i].name,str)>0)
			{
				AfxMessageBox("ffmpeg dll version fmt is validate!\r\n");
				exit(1);
			}
		}
	}

	//register
	avcodec_register_all();
#if CONFIG_AVDEVICE
    avdevice_register_all();
#endif
    avfilter_register_all();
    av_register_all();
    avformat_network_init();

	//StrongFFplugin.dll
	bool isload = false;
	CString strShow = "";
	HMODULE hStrongFFplugin = ::LoadLibraryA("StrongFFplugin.dll");
	if(hStrongFFplugin)
	{
		typedef int (__cdecl * RESTRONGFFPLUGIN)(void * module);
		RESTRONGFFPLUGIN av_register_strongffplugin = NULL;
		av_register_strongffplugin = (RESTRONGFFPLUGIN)::GetProcAddress(hStrongFFplugin,"av_register_strongffplugin");
		if(av_register_strongffplugin)
		{
			int plugin_num = 0;
			plugin_num = av_register_strongffplugin(GetModuleHandle(NULL));
			if(plugin_num < 0)
			{AfxMessageBox("Register StrongFFplugin Failed!\r\n");exit(2);}
			else
			{
				CString strNum;
				strNum.Format("Register Number %d\r\n",plugin_num);
				strShow += strNum;
				isload = true;
			}
		}
	}
	if(isload == false)
	{strShow += "Cann't Find StrongFFplugin.dll\r\n";}

	index_first = 0;
	index_second = 0;
	index_third = 0;

	//一级分类
	m_CMainListBox.ResetContent();
	int num = 0;
	for(num = 0;num<=enFFOthers;num++)
	{m_CMainListBox.InsertString(num,str_enFFName[num]);}
	CString strFormat;
	strFormat.Format("一级分类【%d】",num);
	m_CMainStatic.SetWindowTextA(strFormat);

	//二级分类
	m_CSecondListBox.ResetContent();
	num = 0;
	strFormat.Format("二级分类【%d】",num);
	m_CSecondStatic.SetWindowTextA(strFormat);

	//三级分类
	m_CThirdListBox.ResetContent();
	num = 0;
	strFormat.Format("三级分类【%d】",num);
	m_CThirdStatic.SetWindowTextA(strFormat);

	//模块信息
	m_CShowEdit.SetWindowTextA(strShow);

	//主界面
	this->SetWindowTextA("ffparse 【仅供ffmpeg、ffplay、mplayer、vlc等Windows开发人员使用】");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CffparseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CffparseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CffparseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

AVCodec * GetAVCodec(int i)
{
	AVCodec * codec = NULL;
	for(int j = 0;(codec = av_codec_next(codec))!=NULL;j++)
	{
		if(j==i)
		{return codec;}
	}
	return codec;
}

AVFilter * GetAVFilter(int i)
{
	AVFilter ** avFilter = NULL;
	for(int j = 0; (avFilter = av_filter_next(avFilter)) != NULL && (*avFilter);j++)
	{
		if(j==i && avFilter && (*avFilter))
		{return *avFilter;}
	}
	return NULL;
}

const AVClass * GetGeneralAVClass(int i)
{
	const AVClass * pAVClass = NULL;
	switch(i)
	{
	case enFFCodecParams:{
		pAVClass = avcodec_get_class();
							}break;
	case enFFAVFormatParams:{
		pAVClass = avformat_get_class();
							}break;
	case enFFVedioColorSpaceParams:{
		pAVClass = sws_get_class();
								   }break;
	case enFFAudioSampleFormatParams:{
		pAVClass = swr_get_class();
							   }break;
	case enFFAVFrameParams:{
		pAVClass = avcodec_get_frame_class();
							}break;
	case enFFSubtitleParams:{
		pAVClass = avcodec_get_subtitle_rect_class();
							}break;
	case enFFOtherParams:{
							}break;
	}
	return pAVClass;
}

void CffparseDlg::OnLbnDblclkListMain()
{
	index_first = m_CMainListBox.GetCurSel();
	CString strShowText = "";
	m_CSecondListBox.ResetContent();
	m_CThirdListBox.ResetContent();
	vec_SecondIndex.clear();
	vec_ThirdIndex.clear();
	int numSecond = 0;
	switch(index_first)
	{
	case enFFVideoDecoder:
		{
			AVCodec * codec = NULL;
			for(int i = 0;(codec = av_codec_next(codec))!=NULL;i++)
			{
				if(codec && codec->name && codec->type == AVMEDIA_TYPE_VIDEO && av_codec_is_decoder(codec))
				{
					m_CSecondListBox.InsertString(numSecond,codec->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFVideoEncoder:
		{
			AVCodec * codec = NULL;
			for(int i = 0;(codec = av_codec_next(codec))!=NULL;i++)
			{
				if(codec && codec->name && codec->type == AVMEDIA_TYPE_VIDEO && av_codec_is_encoder(codec))
				{
					m_CSecondListBox.InsertString(numSecond,codec->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFAudioDecoder:
		{
			AVCodec * codec = NULL;
			for(int i = 0;(codec = av_codec_next(codec))!=NULL;i++)
			{
				if(codec && codec->name && codec->type == AVMEDIA_TYPE_AUDIO && av_codec_is_decoder(codec))
				{
					m_CSecondListBox.InsertString(numSecond,codec->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFAudioEncoder:
		{
			AVCodec * codec = NULL;
			for(int i = 0;(codec = av_codec_next(codec))!=NULL;i++)
			{
				if(codec && codec->name && codec->type == AVMEDIA_TYPE_AUDIO && av_codec_is_encoder(codec))
				{
					m_CSecondListBox.InsertString(numSecond,codec->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFSubtitleDecoder:
		{
			AVCodec * codec = NULL;
			for(int i = 0;(codec = av_codec_next(codec))!=NULL;i++)
			{
				if(codec && codec->name && codec->type == AVMEDIA_TYPE_SUBTITLE && av_codec_is_decoder(codec))
				{
					m_CSecondListBox.InsertString(numSecond,codec->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFSubtitleEncoder:
		{
			AVCodec * codec = NULL;
			for(int i = 0;(codec = av_codec_next(codec))!=NULL;i++)
			{
				if(codec && codec->name && codec->type == AVMEDIA_TYPE_SUBTITLE && codec->encode_sub!=NULL)
				{
					m_CSecondListBox.InsertString(numSecond,codec->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFFormatInput:
		{
			AVInputFormat * iformat = NULL;
			for(int i = 0;(iformat = av_iformat_next(iformat))!=NULL;i++)
			{
				if(iformat && iformat->name)
				{
					m_CSecondListBox.InsertString(numSecond,iformat->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFFormatOutput:
		{
			AVOutputFormat * oformat = NULL;
			for(int i = 0;(oformat = av_oformat_next(oformat))!=NULL;i++)
			{
				if(oformat && oformat->name)
				{
					m_CSecondListBox.InsertString(numSecond,oformat->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFFilterVideo:
		{
			AVFilter ** avFilter = NULL;
			for(int i = 0; (avFilter = av_filter_next(avFilter)) != NULL && (*avFilter);i++)
			{
				if(avFilter && (*avFilter) && 
					(((*avFilter)->inputs && (*avFilter)->inputs->type == AVMEDIA_TYPE_VIDEO) ||
					((*avFilter)->outputs && (*avFilter)->outputs->type == AVMEDIA_TYPE_VIDEO)))
				{
					m_CSecondListBox.InsertString(numSecond,(*avFilter)->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFFilterAudio:
		{
			AVFilter ** avFilter = NULL;
			for(int i = 0; (avFilter = av_filter_next(avFilter)) != NULL && (*avFilter);i++)
			{
				if(avFilter && (*avFilter) && 
					(((*avFilter)->inputs && (*avFilter)->inputs->type == AVMEDIA_TYPE_AUDIO) ||
					((*avFilter)->outputs && (*avFilter)->outputs->type == AVMEDIA_TYPE_AUDIO)))
				{
					m_CSecondListBox.InsertString(numSecond,(*avFilter)->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFFilterOthers:
		{
			AVFilter ** avFilter = NULL;
			for(int i = 0; (avFilter = av_filter_next(avFilter)) != NULL && (*avFilter);i++)
			{
				if(avFilter && (*avFilter) && 
					(((*avFilter)->inputs && (*avFilter)->inputs->type != AVMEDIA_TYPE_VIDEO && (*avFilter)->inputs->type != AVMEDIA_TYPE_AUDIO) ||
					((*avFilter)->outputs && (*avFilter)->outputs->type != AVMEDIA_TYPE_VIDEO  && (*avFilter)->outputs->type != AVMEDIA_TYPE_AUDIO)))
				{
					m_CSecondListBox.InsertString(numSecond,(*avFilter)->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFGeneralParam:
		{
			for(int i=0;i<=enFFOtherParams;i++)
			{
				m_CSecondListBox.InsertString(numSecond,str_enFFParamName[i]);
				vec_SecondIndex.push_back(i);
				numSecond++;
			}
		}break;
	case enFFColorSpace:
		{
			for(int i = PIX_FMT_YUV420P;i<PIX_FMT_NB;i++)
			{
				const char * str = av_get_pix_fmt_name((PixelFormat)i);
				if(str)
				{
					m_CSecondListBox.InsertString(numSecond,str);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFAudioSampleFormat:
		{
			for(int i = AV_SAMPLE_FMT_U8;i<AV_SAMPLE_FMT_NB;i++)
			{
				const char * str = av_get_sample_fmt_name((AVSampleFormat)i);
				if(str)
				{
					m_CSecondListBox.InsertString(numSecond,str);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFAudioChannelFormat:
		{
			for(int i = 0;i < sizeof(channel_format_id)/sizeof(channel_format_id[0]);i++)
			{
				const char * str_channel_name = av_get_channel_name(channel_format_id[i]);
				if(str_channel_name)
				{
					m_CSecondListBox.InsertString(numSecond,str_channel_name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFAudioChannelLayout:
		{
			for(int i = 0;true;i++)
			{
				uint64_t channel_layout = 0;
				const char * str_channel_layout = NULL;
				if(!av_get_standard_channel_layout(i,&channel_layout,&str_channel_layout))
				{
					if(str_channel_layout)
					{
						m_CSecondListBox.InsertString(numSecond,str_channel_layout);
						vec_SecondIndex.push_back(i);
						numSecond++;
					}
				}
				else
				{
					break;
				}
			}
		}break;
	case enFFCodecParse:
		{
			AVCodecParser * parse = NULL;
			for(int i = 0;parse = av_parser_next(parse);i++)
			{
				CString str_parse_name = "ids:";
				for(int j = 0;j<(sizeof(parse->codec_ids)/sizeof(parse->codec_ids[0]));j++)
				{
					if(parse->codec_ids[j] == 0)
					{break;}
					else
					{
						CString tstr_parse_name;
						tstr_parse_name.Format("【0x%X】",parse->codec_ids[j]);
						str_parse_name += tstr_parse_name;
					}
				}
				m_CSecondListBox.InsertString(numSecond,str_parse_name);
				vec_SecondIndex.push_back(i);
				numSecond++;
			}
		}break;
	case enFFBitstreamFilter:
		{
			AVBitStreamFilter * bitfilter = NULL;
			for(int i = 0;bitfilter = av_bitstream_filter_next(bitfilter);i++)
			{
				CString str_bitfilter = bitfilter->name;
				m_CSecondListBox.InsertString(numSecond,str_bitfilter);
				vec_SecondIndex.push_back(i);
				numSecond++;
			}
		}break;
	case enFFHwaccel:
		{
			AVHWAccel * hw = NULL;
			for(int i = 0;hw = av_hwaccel_next(hw);i++)
			{
				CString str_hw = hw->name;
				m_CSecondListBox.InsertString(numSecond,str_hw);
				vec_SecondIndex.push_back(i);
				numSecond++;
			}
		}break;
	case enFFProtocol:
		{
			URLProtocol * pFileControl = NULL;
			for(int i = 0;avio_enum_protocols((void **)&pFileControl,1);i++)
			{
				if(pFileControl->name)
				{
					m_CSecondListBox.InsertString(numSecond,pFileControl->name);
					vec_SecondIndex.push_back(i);
					numSecond++;
				}
			}
		}break;
	case enFFVersion:
		{
			CString strVersion;
			const char * pch_String = NULL;
			unsigned version = 0;
			version = avutil_version();
			pch_String = avutil_license();
			if(pch_String)
			{strVersion.Format("avutil: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
			version = avcodec_version();
			pch_String = avcodec_license();
			if(pch_String)
			{strVersion.Format("avcodec: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
			version = avformat_version();
			pch_String = avformat_license();
			if(pch_String)
			{strVersion.Format("avformat: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
			version = avfilter_version();
			pch_String = avfilter_license();
			if(pch_String)
			{strVersion.Format("avfilter: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
			version = swresample_version();
			pch_String = swresample_license();
			if(pch_String)
			{strVersion.Format("swresample: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
			version = swscale_version();
			pch_String = swscale_license();
			if(pch_String)
			{strVersion.Format("swscale: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
			version = postproc_version();
			pch_String = postproc_license();
			if(pch_String)
			{strVersion.Format("postproc: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
			version = avdevice_version();
			pch_String = avdevice_license();
			if(pch_String)
			{strVersion.Format("avdevice: version【%d-%d-%d】 license【",(version>>16)&0xFFFF,(version>>8)&0xFF,version&0xFF);strShowText += strVersion;strShowText += pch_String;strShowText += "】\r\n";}
		}break;
	case enFFConfiguration:
		{
			const char * pch_String = NULL;
			pch_String = avutil_configuration();
			if(pch_String)
			{strShowText += "avutil:\r\n";strShowText += pch_String;strShowText += "\r\n";}
			pch_String = avcodec_configuration();
			if(pch_String)
			{strShowText += "avcodec:\r\n";strShowText += pch_String;strShowText += "\r\n";}
			pch_String = avformat_configuration();
			if(pch_String)
			{strShowText += "avformat:\r\n";strShowText += pch_String;strShowText += "\r\n";}
			pch_String = avfilter_configuration();
			if(pch_String)
			{strShowText += "avfilter:\r\n";strShowText += pch_String;strShowText += "\r\n";}
			pch_String = swresample_configuration();
			if(pch_String)
			{strShowText += "swresample:\r\n";strShowText += pch_String;strShowText += "\r\n";}
			pch_String = swscale_configuration();
			if(pch_String)
			{strShowText += "swscale:\r\n";strShowText += pch_String;strShowText += "\r\n";}
			pch_String = postproc_configuration();
			if(pch_String)
			{strShowText += "postproc:\r\n";strShowText += pch_String;strShowText += "\r\n";}
			pch_String = avdevice_configuration();
			if(pch_String)
			{strShowText += "avdevice:\r\n";strShowText += pch_String;strShowText += "\r\n";}
		}break;
	case enFFOthers:
		{
			strShowText += "this is ffparse.【库解析器】\r\n";
		}break;
	}
	CString strSecond ;
	strSecond.Format("二级分类【%d】",numSecond);
	m_CSecondStatic.SetWindowTextA(strSecond);
	m_CThirdStatic.SetWindowTextA("三级分类【0】");
	m_CShowEdit.SetWindowTextA(strShowText);
}


void CffparseDlg::OnLbnDblclkListSecond()
{
	m_CMainListBox.SetCurSel(index_first);
	index_second = m_CSecondListBox.GetCurSel();
	CString strShowText = "";
	m_CThirdListBox.ResetContent();
	vec_ThirdIndex.clear();
	CString strSecondIndex;
	m_CSecondListBox.GetText(index_second,strSecondIndex);
	int numThird = 0;
	CString strThirdClassName = "";
	switch(index_first)
	{
	case enFFVideoDecoder:
	case enFFVideoEncoder:
	case enFFAudioDecoder:
	case enFFAudioEncoder:
	case enFFSubtitleDecoder:
	case enFFSubtitleEncoder:
		{
			AVCodec * codec = GetAVCodec(vec_SecondIndex[index_second]);
			if(codec && !strcmp(strSecondIndex,codec->name))
			{
				strShowText.Format("ID:【0x%X】 Cap:0x%X\r\n",codec->id,codec->capabilities);
				if(codec->priv_class)
				{
					AVClass * pAVClass = (AVClass *)codec->priv_class;
					if(pAVClass->class_name)
					{strShowText += pAVClass->class_name;strShowText += "\r\n";}
					if(pAVClass->option)
					{
						strThirdClassName = "参数";
						AVOption * opt = (AVOption *)pAVClass->option;
						for(int i=0;opt->name;i++,opt++)
						{
							m_CThirdListBox.InsertString(numThird,opt->name);
							vec_ThirdIndex.push_back(i);
							numThird++;
						}
					}
				}
				if(codec->long_name)
				{strShowText += codec->long_name;strShowText += "\r\n";}
				if(codec->pix_fmts)
				{
					strShowText += "Support PixFormat:";
					for(int i = 0;*(codec->pix_fmts+i) != PIX_FMT_NONE;i++)
					{
						const char * str = av_get_pix_fmt_name(*(codec->pix_fmts+i));//(codec->pix_fmts+i)
						if(str)
						{strShowText +=" ";strShowText += str;}
					}
					strShowText += "\r\n";
				}
				if(codec->sample_fmts)
				{
					strShowText += "Support SampleFormat:";
					for(int i = 0;*(codec->sample_fmts+i) != AV_SAMPLE_FMT_NONE;i++)
					{
						const char * str = av_get_sample_fmt_name(*(codec->sample_fmts+i));//(codec->pix_fmts+i)
						if(str)
						{strShowText +=" ";strShowText += str;}
					}
					strShowText += "\r\n";
				}
			}
		}break;
	case enFFFormatInput:
		{
			AVInputFormat * iformat = NULL;
			for(int i = 0;(iformat = av_iformat_next(iformat))!=NULL;i++)
			{
				if(i == vec_SecondIndex[index_second] && !strcmp(strSecondIndex,iformat->name))
				{
					strShowText.Format("ID:【0x%X】 FLAGS:0x%X\r\n",iformat->raw_codec_id,iformat->flags);
					if(iformat->priv_class)
					{
						AVClass * pAVClass = (AVClass *)iformat->priv_class;
						if(pAVClass->class_name)
						{strShowText += pAVClass->class_name;strShowText += "\r\n";}
						if(pAVClass->option)
						{
							strThirdClassName = "参数";
							AVOption * opt = (AVOption *)pAVClass->option;
							for(int i=0;opt->name;i++,opt++)
							{
								m_CThirdListBox.InsertString(numThird,opt->name);
								vec_ThirdIndex.push_back(i);
								numThird++;
							}
						}
					}
					if(iformat->long_name)
					{
						strShowText += iformat->long_name;
						strShowText += "\r\n";
					}
					if(iformat->extensions)
					{
						strShowText += iformat->extensions;
						strShowText += "\r\n";
					}
				}
			}
		}break;
	case enFFFormatOutput:
		{
			AVOutputFormat * oformat = NULL;
			for(int i = 0;(oformat = av_oformat_next(oformat))!=NULL;i++)
			{
				if(i == vec_SecondIndex[index_second] && !strcmp(strSecondIndex,oformat->name))
				{
					strShowText.Format("Name:0x%X FLAGS:0x%X\r\n",oformat->name,oformat->flags);
					if(oformat->priv_class)
					{
						AVClass * pAVClass = (AVClass *)oformat->priv_class;
						if(pAVClass->class_name)
						{strShowText += pAVClass->class_name;strShowText += "\r\n";}
						if(pAVClass->option)
						{
							strThirdClassName = "参数";
							AVOption * opt = (AVOption *)pAVClass->option;
							for(int i=0;opt->name;i++,opt++)
							{
								m_CThirdListBox.InsertString(numThird,opt->name);
								vec_ThirdIndex.push_back(i);
								numThird++;
							}
						}
					}
					if(oformat->long_name)
					{
						strShowText += oformat->long_name;
						strShowText += "\r\n";
					}
					if(oformat->mime_type)
					{
						strShowText += "Type:";
						strShowText += oformat->mime_type;
						strShowText += "\r\n";
					}
					if(oformat->extensions)
					{
						strShowText += oformat->extensions;
						strShowText += "\r\n";
					}
					if(oformat->video_codec != CODEC_ID_NONE)
					{
						CString strFormat;
						strFormat.Format("Support Video ID=0x%X encoder=%s decoder=%s\r\n",oformat->video_codec,
							avcodec_find_encoder(oformat->video_codec)?(avcodec_find_encoder(oformat->video_codec))->name:"",
							avcodec_find_decoder(oformat->video_codec)?(avcodec_find_decoder(oformat->video_codec))->name:"");
						strShowText += strFormat;
					}
					if(oformat->audio_codec != CODEC_ID_NONE)
					{
						CString strFormat;
						strFormat.Format("Support Audio ID=0x%X encoder=%s decoder=%s\r\n",oformat->audio_codec,
							avcodec_find_encoder(oformat->audio_codec)?(avcodec_find_encoder(oformat->audio_codec))->name:"",
							avcodec_find_decoder(oformat->audio_codec)?(avcodec_find_decoder(oformat->audio_codec))->name:"");
						strShowText += strFormat;
					}
					if(oformat->subtitle_codec != CODEC_ID_NONE)
					{
						CString strFormat;
						strFormat.Format("Support Subtitle ID=0x%X encoder=%s decoder=%s\r\n",oformat->subtitle_codec,
							avcodec_find_encoder(oformat->subtitle_codec)?(avcodec_find_encoder(oformat->subtitle_codec))->name:"",
							avcodec_find_decoder(oformat->subtitle_codec)?(avcodec_find_decoder(oformat->subtitle_codec))->name:"");
						strShowText += strFormat;
					}
				}
			}
		}break;
	case enFFFilterVideo:
	case enFFFilterAudio:
	case enFFFilterOthers:
		{
			AVFilter * avFilter = GetAVFilter(vec_SecondIndex[index_second]);
			if(avFilter && !strcmp(strSecondIndex,avFilter->name))
			{
				if(avFilter->priv_class)
				{
					AVClass * pAVClass = (AVClass *)avFilter->priv_class;
					if(pAVClass->class_name)
					{strShowText += pAVClass->class_name;strShowText += "\r\n";}
					if(pAVClass->option)
					{
						strThirdClassName = "参数";
						AVOption * opt = (AVOption *)pAVClass->option;
						for(int i=0;opt->name;i++,opt++)
						{
							m_CThirdListBox.InsertString(numThird,opt->name);
							vec_ThirdIndex.push_back(i);
							numThird++;
						}
					}
				}
				if(avFilter->description)
				{strShowText += avFilter->description;strShowText += "\r\n";}
			}
		}break;
	case enFFGeneralParam:
		{
			for(int i=0;i<=enFFOtherParams;i++)
			{
				if(i == vec_SecondIndex[index_second] && !strcmp(strSecondIndex,str_enFFParamName[i]))
				{
					const AVClass * pAVClass = GetGeneralAVClass(i);
					if(pAVClass)
					{
						if(pAVClass->class_name)
						{strShowText += pAVClass->class_name;strShowText += "\r\n";}
						if(pAVClass->option)
						{
							strThirdClassName = "参数";
							AVOption * opt = (AVOption *)pAVClass->option;
							for(int i=0;opt->name;i++,opt++)
							{
								m_CThirdListBox.InsertString(numThird,opt->name);
								vec_ThirdIndex.push_back(i);
								numThird++;
							}
						}
					}
				}
			}
		}break;
	case enFFColorSpace:
		{
			if(index_second > 0)
			{
				const AVPixFmtDescriptor * descriptor = NULL;
				descriptor = av_pix_fmt_desc_get((enum AVPixelFormat)index_second);
				if(descriptor)
				{
					CString strFormat;
					strShowText = "name:";
					if(descriptor->name)
					{strShowText += descriptor->name;}
					strShowText += "\r\n";
					strFormat.Format("nb=0x%02x:",descriptor->nb_components);
					strShowText += strFormat;
					strFormat.Format("chroma_w=0x%02x:",descriptor->log2_chroma_w);
					strShowText += strFormat;
					strFormat.Format("chroma_h=0x%02x:",descriptor->log2_chroma_h);
					strShowText += strFormat;
					strFormat.Format("flags=0x%02x\r\n",descriptor->flags);
					strShowText += strFormat;
					for(int i = 0;i<(sizeof(descriptor->comp)/sizeof(descriptor->comp[0]));i++)
					{
						strFormat.Format("{ %02x, %02x, %02x, %02x, %02x }\r\n",
							descriptor->comp[i].plane,
							descriptor->comp[i].step_minus1,
							descriptor->comp[i].offset_plus1,
							descriptor->comp[i].shift,
							descriptor->comp[i].depth_minus1);
						strShowText += strFormat;
					}
				}
			}
		}break;
	case enFFAudioSampleFormat:
		{
			const char * text = NULL;
			text = av_get_sample_fmt_name((enum AVSampleFormat)index_second);
			if(text)
			{
				strShowText.Format("id=0x%X",index_second);
				strShowText += text;
			}
		}break;
	case enFFAudioChannelFormat:
		{
			if(index_second >= 0 && index_second <= sizeof(channel_format_id)/sizeof(channel_format_id[0]))
			{
				const char * str_channel_description = av_get_channel_description(channel_format_id[index_second]);
				if(str_channel_description)
				{
					strShowText.Format("id=0x%I64dX\r\n",channel_format_id[index_second]);
					strShowText += str_channel_description;
				}
			}
		}break;
	case enFFAudioChannelLayout:
		{
			for(int i = 0;true;i++)
			{
				uint64_t channel_layout = 0;
				const char * str_channel_layout = NULL;
				if(!av_get_standard_channel_layout(i,&channel_layout,&str_channel_layout))
				{
					if(i == index_second)
					{
						strShowText.Format("id=0x%I64X\r\n",channel_layout);
						if(str_channel_layout)
						{strShowText+=str_channel_layout;}
					}
				}
				else
				{
					break;
				}
			}
		}break;
	case enFFProtocol:
		{
			URLProtocol * pFileControl = NULL;
			for(int j = 0;avio_enum_protocols((void **)&pFileControl,1);j++)
			{
				if(pFileControl->name && vec_SecondIndex[index_second] == j && !strcmp(strSecondIndex,pFileControl->name))
				{
					strShowText += pFileControl->name;strShowText += "\r\n";
					if(pFileControl->priv_data_class)
					{
						AVClass * pAVClass = (AVClass *)pFileControl->priv_data_class;
						if(pAVClass->class_name)
						{strShowText += pAVClass->class_name;strShowText += "\r\n";}
						if(pAVClass->option)
						{
							strThirdClassName = "参数";
							AVOption * opt = (AVOption *)pAVClass->option;
							for(int i=0;opt->name;i++,opt++)
							{
								m_CThirdListBox.InsertString(numThird,opt->name);
								vec_ThirdIndex.push_back(i);
								numThird++;
							}
						}
					}
					break;
				}
			}
		}break;
	case enFFVersion:
		{}break;
	case enFFConfiguration:
		{}break;
	case enFFOthers:
		{}break;
	}
	CString strThird;
	strThird.Format("三级分类【%d】【%s】",numThird,strThirdClassName);
	m_CThirdStatic.SetWindowTextA(strThird);
	m_CShowEdit.SetWindowTextA(strShowText);
}

void ShowOpt(AVOption * opt,CString & strText)
{
	CString strFormat;
	strText += "Opt:";
	strText += opt->name;
	strText += "\r\n";
	switch(opt->type)
	{
	case AV_OPT_TYPE_FLAGS:
	case AV_OPT_TYPE_INT:
		{
			strFormat.Format("Type:int/flags\r\nFlags:0x%X\r\nDefault:%d\r\nMin:%d\r\nMax:%d\r\n",opt->flags,(int)(opt->default_val.i64),(int)opt->min,(int)opt->max);
			strText += strFormat;
		}break;
	case AV_OPT_TYPE_INT64:
		{
			strFormat.Format("Type:int64\r\nFlags:0x%X\r\nDefault:%I64d\r\nMin:%I64d\r\nMax:%I64d\r\n",opt->flags,(__int64)opt->default_val.i64,(__int64)opt->min,(__int64)opt->max);
			strText += strFormat;
		}break;
	case AV_OPT_TYPE_DOUBLE:
		{
			strFormat.Format("Type:double\r\nFlags:0x%X\r\nDefault:%lf\r\nMin:%lf\r\nMax:%lf\r\n",opt->flags,(double)opt->default_val.dbl,(double)opt->min,(double)opt->max);
			strText += strFormat;
		}break;
	case AV_OPT_TYPE_FLOAT:
		{
			strFormat.Format("Type:float\r\nFlags:0x%X\r\nDefault:%f\r\nMin:%f\r\nMax:%f\r\n",opt->flags,(float)opt->default_val.dbl,(float)opt->min,(float)opt->max);
			strText += strFormat;
		}break;
	case AV_OPT_TYPE_STRING:
		{
			strFormat.Format("Type:string\r\nFlags:0x%X\r\nDefault:%s\r\nMin:%s\r\nMax:%s\r\n",opt->flags,opt->default_val.str?opt->default_val.str:"","","");
			strText += strFormat;
		}break;
	case AV_OPT_TYPE_RATIONAL:
		{
			strFormat.Format("Type:rational\r\nFlags:0x%X\r\nDefault:%d/%d\r\nMin:%s\r\nMax:%s\r\n",opt->flags,opt->default_val.q.num,opt->default_val.q.den,"","");
			strText += strFormat;
		}break;
	case AV_OPT_TYPE_BINARY:
		{
			strFormat.Format("Type:binary\r\nFlags:0x%X\r\nDefault:0x%I64X\r\nMin:0x%I64X\r\nMax:0x%I64X\r\n",opt->flags,opt->default_val.i64,opt->min,opt->max);
			strText += strFormat;
		}break;
    case AV_OPT_TYPE_CONST:
		{
			strFormat.Format("Type:const\r\nFlags:0x%X\r\nDefault:%I64d\r\nMin:%I64d\r\nMax:%I64d\r\n",opt->flags,(__int64)opt->default_val.i64,(__int64)opt->min,(__int64)opt->max);
			strText += strFormat;
		}break;
	case AV_OPT_TYPE_IMAGE_SIZE:
		{
			strFormat.Format("Type:imagesize\r\nFlags:0x%X\r\nDefault:%s\r\nMin:%s\r\nMax:%s\r\n",opt->flags,opt->default_val.str?opt->default_val.str:"","","");
			strText += strFormat;
		}break;
    //AV_OPT_TYPE_PIXEL_FMT
	default:
		{
			strFormat.Format("Type:Unknow(0x%X)\r\nFlags:0x%X\r\nDefault:0x%I64X\r\nMin:0x%I64X\r\nMax:0x%I64X\r\n",opt->type,opt->flags,opt->default_val.i64,opt->min,opt->max);
			strText += strFormat;
		}break;
	}
	if(opt->help)
	{strText += "Description:";strText += opt->help;strText += "\r\n";}
	if(opt->unit)
	{strText += "Logical unit:";strText += opt->unit;strText += "\r\n";}
}

void CffparseDlg::OnLbnSelchangeListThird()
{
	m_CMainListBox.SetCurSel(index_first);
	m_CSecondListBox.SetCurSel(index_second);
	index_third = m_CThirdListBox.GetCurSel();
	CString strShowText = "";
	switch(index_first)
	{
	case enFFVideoDecoder:
	case enFFVideoEncoder:
	case enFFAudioDecoder:
	case enFFAudioEncoder:
	case enFFSubtitleDecoder:
	case enFFSubtitleEncoder:
		{
			AVCodec * codec = GetAVCodec(vec_SecondIndex[index_second]);
			if(codec && codec->priv_class)
			{
				AVClass * pAVClass = (AVClass *)codec->priv_class;
				if(pAVClass->option)
				{
					AVOption * opt = (AVOption *)pAVClass->option;
					for(int j=0;opt->name;j++,opt++)
					{
						if(j == vec_ThirdIndex[index_third])
						{ShowOpt(opt,strShowText);break;}
					}
				}
			}
		}break;
	case enFFFormatInput:
		{
			AVInputFormat * iformat = NULL;
			for(int i = 0;(iformat = av_iformat_next(iformat))!=NULL;i++)
			{
				if(iformat && i == vec_SecondIndex[index_second])
				{
					if(iformat->priv_class)
					{
						AVClass * pAVClass = (AVClass *)iformat->priv_class;
						if(pAVClass->option)
						{
							AVOption * opt = (AVOption *)pAVClass->option;
							for(int j=0;opt->name;j++,opt++)
							{
								if(j == vec_ThirdIndex[index_third])
								{ShowOpt(opt,strShowText);break;}
							}
						}
					}
				}
			}
		}break;
	case enFFFormatOutput:
		{
			AVOutputFormat * oformat = NULL;
			for(int i = 0;(oformat = av_oformat_next(oformat))!=NULL;i++)
			{
				if(i == vec_SecondIndex[index_second])
				{
					if(oformat->priv_class)
					{
						AVClass * pAVClass = (AVClass *)oformat->priv_class;
						if(pAVClass->option)
						{
							AVOption * opt = (AVOption *)pAVClass->option;
							for(int j=0;opt->name;j++,opt++)
							{
								if(j == vec_ThirdIndex[index_third])
								{ShowOpt(opt,strShowText);break;}
							}
						}
					}
				}
			}
		}break;
	case enFFFilterVideo:
	case enFFFilterAudio:
	case enFFFilterOthers:
		{
			AVFilter * avFilter = GetAVFilter(vec_SecondIndex[index_second]);
			if(avFilter)
			{
				if(avFilter->priv_class)
				{
					AVClass * pAVClass = (AVClass *)avFilter->priv_class;
					if(pAVClass->option)
					{
						AVOption * opt = (AVOption *)pAVClass->option;
						for(int j=0;opt->name;j++,opt++)
						{
							if(j == vec_ThirdIndex[index_third])
							{ShowOpt(opt,strShowText);break;}
						}
					}
				}
			}
		}break;
	case enFFGeneralParam:
		{
			const AVClass * pAVClass = GetGeneralAVClass(vec_SecondIndex[index_second]);
			if(pAVClass)
			{
				if(pAVClass->option)
				{
					AVOption * opt = (AVOption *)pAVClass->option;
					for(int j=0;opt->name;j++,opt++)
					{
						if(j == vec_ThirdIndex[index_third])
						{ShowOpt(opt,strShowText);break;}
					}
				}
			}
		}break;
	case enFFColorSpace:
		{
		}break;
	case enFFAudioSampleFormat:
		{
		}break;
	case enFFAudioChannelFormat:
		{}break;
	case enFFAudioChannelLayout:
		{}break;
	case enFFProtocol:
		{
			URLProtocol * pFileControl = NULL;
			for(int i = 0;avio_enum_protocols((void **)&pFileControl,1);i++)
			{
				if(vec_SecondIndex[index_second] == i)
				{
					if(pFileControl->priv_data_class)
					{
						AVClass * pAVClass = (AVClass *)pFileControl->priv_data_class;
						if(pAVClass->option)
						{
							AVOption * opt = (AVOption *)pAVClass->option;
							for(int j=0;opt->name;j++,opt++)
							{
								if(j == vec_ThirdIndex[index_third])
								{ShowOpt(opt,strShowText);break;}
							}
						}
					}
				}
			}
		}break;
	case enFFVersion:
		{
		}break;
	case enFFConfiguration:
		{
		}break;
	case enFFOthers:
		{
		}break;
	}
	m_CShowEdit.SetWindowTextA(strShowText);
}

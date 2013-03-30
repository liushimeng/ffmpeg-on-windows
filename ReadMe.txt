bin       文件夹   是对应使用的DLL
doc       文件夹   是帮助文档说明
examples  文件夹   是库使用样例
inc       文件夹   是头文件，只要包含 g_include.h 文件即可
lib       文件夹   是链接库文件
src       文件夹   是ffmpeg source版本

ffmpeg当前版本：ffmpeg 1.1.3

protected:  	lsm
e-mail:	    	109117198lsm@163.com
time-version: 	2013-3-30

说明：
x264AVCEncoder			x264视频编码器		
intelAVCDecoder			intel视频解码器
intelAVCEncoder			intel视频编码器		（实验阶段）
libaacplus			aacplus音频编码器
libfaac				faac音频编码器
stickfigure			stickfigure视频特效
file				file协议
subHang				subHang字幕视频滤器
pipe				pipe命名管道协议
avfs				avfs文件容器		(包括封装和解封装)

例子1：播放文件在时间10秒到20秒之间加入特效
ffplay -i "D:\AVTestFile\AVNormal\太空一号BD中字.rmvb" -vf stickfigure=q=0:c=0:s=10000:e=20000

简要说明：
ffmpeg/libav 加入了 StrongFFplugin 之后就称为StrongFFmpeg ，它是跨平台的，除StrongFFplugin第三方插件以外包括：framework、ffmpeg、ffplay、ffprobe、ffpars等相关程序都是开源的，从1.1.3版本起将开启StrongFFplugin商业化道路，以个人和学习者身份可以任意使用，以商业为目的的使用将不在免费。
使用StrongFFmpeg请购买正版，x64性能更加卓越！

详细介绍：
http://hi.baidu.com/109117198lsm/item/e27a1a1d34546c001994ec5e

源码下载地址：
https://github.com/liushimeng/ffmpeg-on-windows

联系方式：
QQ群28785698 phone：13520647302   e-mail：109117198lsm@163.com
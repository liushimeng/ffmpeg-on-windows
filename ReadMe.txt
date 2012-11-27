bin       文件夹   是对应使用的DLL
doc       文件夹   是帮助文档说明
examples  文件夹   是库使用样例
inc       文件夹   是头文件，只要包含 g_include.h 文件即可
lib       文件夹   是链接库文件
src       文件夹   是ffmpeg source版本

ffmpeg当前版本：ffmpeg 1.0.0

protected:  	lsm
e-mail:	    	109117198lsm@163.com
time-version: 	2012-11-27

说明：
add ffparse			开发人员专用工具
add x264Encoder			视频编码器
add stickfigure filter		视频特效滤器
add libfaac			音频编码器
add aacplus			音频编码器

例子1：播放文件在时间10秒到20秒之间加入特效
StrongFFplay -i "D:\AVTestFile\AVNormal\太空一号BD中字.rmvb" -vf stickfigure=q=0:c=0:s=10000:e=20000

/**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: target.c
**描        述: lpc210x（飞利浦的ARM）目标板特殊的代码，包括异常处理程序和目标板初始化程序
**              每个工程应当具有这个文件的拷贝，用户根据程序的需要修改本文件。
**注        意：本文件必须以ARM（32位代码）方式编译，否则，必须更改init.s和vector.s文件
**              别的C代码不必使用ARM（32位代码）方式编译
********************************************************************************************************/

#define IN_TARGET
#include "config.h"

/*********************************************************************************************************
** 函数名称: IRQ_Exception
** 功能描述: 中断异常处理程序，用户根据需要自己改变程序
**
********************************************************************************************************/
void __irq IRQ_Exception(void)
	{
    while(1);                   // 这一句替换为自己的代码
	}

/*********************************************************************************************************
** 函数名称: FIQ_Exception
** 功能描述: 快速中断异常处理程序，用户根据需要自己改变程序
**           
********************************************************************************************************/
        void FIQ_Exception(void)
{
    while(1);                   // 这一句替换为自己的代码
}

/*********************************************************************************************************
** 函数名称: TargetInit
** 功能描述: 目标板初始化代码，在需要的地方调用，根据需要改变

********************************************************************************************************/
        void TargetInit(void)
{
    /* 添加自己的代码 */
}

/*********************************************************************************************************
** 函数名称: TargetResetInit
** 功能描述: 调用main函数前目标板初始化代码，根据需要改变，不能删除

********************************************************************************************************/
        void TargetResetInit(void)
{

    /* 设置系统各部分时钟 */
/*    PLLCON = 1;
#if ((Fcclk / 4) / Fpclk) == 1
    VPBDIV = 0;
#endif

#if ((Fcclk / 4) / Fpclk) == 2
    VPBDIV = 2;
#endif

#if ((Fcclk / 4) / Fpclk) == 4
    VPBDIV = 1;
#endif

#if (Fcco / Fcclk) == 2
    PLLCFG = ((Fcclk / Fosc) - 1) | (0 << 5);
#endif
#if (Fcco / Fcclk) == 4
    PLLCFG = ((Fcclk / Fosc) - 1) | (1 << 5);
#endif
#if (Fcco / Fcclk) == 8
    PLLCFG = ((Fcclk / Fosc) - 1) | (2 << 5);
#endif
#if (Fcco / Fcclk) == 16
    PLLCFG = ((Fcclk / Fosc) - 1) | (3 << 5);
#endif
    PLLFEED = 0xaa;
    PLLFEED = 0x55;
    while((PLLSTAT & (1 << 10)) == 0);
    PLLCON = 3;
    PLLFEED = 0xaa;
    PLLFEED = 0x55;
*/  
    
    /* 设置存储器加速模块 */
    MAMCR = 2;		//MAMCR 8u2 00－MAM 功能被禁止、01－MAM功能部分使能、10－MAM功能完全使能
    /* MAMTIM 8u3
    000＝0－保留
    001＝1－一段时间内只有 1 个处理器时钟（cclk）用于 MAM 取指。
    010＝2－一段时间内只有2个处理器时钟（cclk）用于MAM取指。
    011＝3－一段时间内只有 3 个处理器时钟（cclk）用于 MAM 取指。
    100＝4－一段时间内只有4个处理器时钟（cclk）用于 MAM 取指。
    101＝5－一段时间内只有5 个处理器时钟（cclk）用于 MAM 取指。
    110＝6－一段时间内只有 6 个处理器时钟（cclk）用于 MAM 取指。
    111＝7－一段时间内只有7个处理器时钟（cclk）用于 MAM 取指。
     */
#if Fcclk < 20000000
    MAMTIM = 1;
#else
#if Fcclk < 40000000
    MAMTIM = 2;
#else
    MAMTIM = 3;
#endif
#endif
       
    /* 初始化VIC */
    VICIntEnClr = 0xffffffff;//清所有中断使能，即关中断
    VICVectAddr = 0;//默认向量地址寄存器
    VICIntSelect = 0;//1：对应的中断请求分配为FIQ。0：对应的中断请求分配为IRQ。

    /* 添加自己的代码 */

}
#include "rt_sys.h"
#include "stdio.h"

#pragma import(__use_no_semihosting_swi)
#pragma import(__use_two_region_memory)

        int __rt_div0(int a)
{
    a = a;
    return 0;
}

        int fputc(int ch,FILE *f)
{
    ch = ch;
    f = f;
    return 0;
}

    int fgetc(FILE *f)
{
    f = f;
    return 0;
}


        int _sys_close(FILEHANDLE fh)
{
    fh = fh;
    return 0;
}

        int _sys_write(FILEHANDLE fh, const unsigned char * buf,
                      unsigned len, int mode)
{
    fh = fh;
    buf = buf;
    len =len;
    mode = mode;
    return 0;
}
        int _sys_read(FILEHANDLE fh, unsigned char * buf,
                     unsigned len, int mode)
{
    fh = fh;
    buf = buf;
    len =len;
    mode = mode;
    
    return 0;
}

       void _ttywrch(int ch)
{
    ch = ch;
}

        int _sys_istty(FILEHANDLE fh)
{
    fh = fh;
    return 0;
}
        int _sys_seek(FILEHANDLE fh, long pos)
{
    fh = fh;
    return 0;
}
        int _sys_ensure(FILEHANDLE fh)
{
    fh = fh;
    return 0;
}

        long _sys_flen(FILEHANDLE fh)
{
    fh = fh;
    return 0;
}
       int _sys_tmpnam(char * name, int sig, unsigned maxlen)
{
    name = name;
    sig = sig;
    maxlen = maxlen;
    return 0;
}

        void _sys_exit(int returncode)
{
    returncode = returncode;
}

        char *_sys_command_string(char * cmd, int len)
{
    cmd = cmd;
    len = len;
    return 0;
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/

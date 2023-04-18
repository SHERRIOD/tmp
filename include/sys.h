#ifndef SYS_H
#define SYS_H

// 系统启动与退出功能
int         InitSys();
int         ExitSys();

// 系统功能接口
void        LoginIF();
void        InitIF();
void        ExitIF();
void        SignUpIF();
void        SysSettingIF();

#endif
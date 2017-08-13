/*************************************************
*
*	Author: Yoohoo Niu
*	Mail  :	wand_niu@live.com
*	Detial: cross platform thread
***************************************************/

#ifndef __XTHREAD__
#define __XTHREAD__

#include <iostream>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <process.h>
typedef HANDLE			Niu_thread;
#define Niu_returnType	unsigned int
#define Niu_Call		__stdcall	
#else
#include <pthread.h>  
#include <unistd.h> 
typedef pthread_t		Niu_thread;
#define Niu_returnType	void*
#define Niu_Call	
#endif

class IWork
{
public:
	virtual void startWork() = 0;
};

class XThread
{
public:
	XThread();
	~XThread();
	void execute();
	void join();
	void setWork(IWork* wk);
	static void sleep(const unsigned int mSecond);
	virtual void work();
private:
	IWork*	_work;
	Niu_thread	_threadInstance;
	static Niu_returnType Niu_Call proc(void* param);
};

#endif
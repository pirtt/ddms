/***********************************************
*
*	Author: Yoohoo Niu
*	Mail  :	wand_niu@live.com
*	Detial: mutex for thread lock
*************************************************/
#ifndef __XMUTEX__
#define __XMUTEX__
#ifdef _WIN32
#include <windows.h>
typedef  CRITICAL_SECTION Niu_mutex;
#else
#include <pthread.h>
typedef pthread_mutex_t Niu_mutex;
#endif

class XMutex
{
public:
	XMutex();
	~XMutex();
	Niu_mutex getMutex() const;
	void lock();
	void unlock();
private:
	Niu_mutex _mutex;
	void init();
	void release();
};


class XAutoMutex
{
public:
	explicit XAutoMutex(const XMutex&);
	~XAutoMutex();
	void autolock();
private:
	XMutex _xmutex;
};

#endif
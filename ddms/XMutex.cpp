#include "XMutex.h"


XMutex::XMutex()
{
	init();
}


XMutex::~XMutex()
{
	release();
}

void XMutex::init()
{
#ifdef _WIN32
	InitializeCriticalSection(&_mutex);
#else
	pthread_mutex_init(&_mutex,NULL);
#endif
}

void XMutex::lock()
{
#ifdef _WIN32
	EnterCriticalSection(&_mutex);
#else
	pthread_mutex_lock(&_mutex);
#endif
}

void XMutex::unlock()
{
#ifdef _WIN32
	LeaveCriticalSection(&_mutex);
#else
	pthread_mutex_unlock(&_mutex);
#endif
}
void XMutex::release()
{
#ifdef _WIN32
	DeleteCriticalSection(&_mutex);
#else
	pthread_mutex_destroy(&_mutex);
#endif
}


XAutoMutex::XAutoMutex(const XMutex& ins):
_xmutex(ins)
{

}

XAutoMutex::~XAutoMutex()
{
	_xmutex.unlock();
}

void XAutoMutex::autolock()
{
	_xmutex.lock();
}
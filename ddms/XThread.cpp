#include "XThread.h"


XThread::XThread():
_work(0)
{
}

XThread::~XThread()
{
}

void XThread::setWork(IWork* wk)
{
	_work = wk;
}

void XThread::execute()
{
#ifdef _WIN32
	unsigned int thrdaddr;
	_threadInstance = (Niu_thread)_beginthreadex(NULL, 0, XThread::proc, (void*)this, 0, &thrdaddr);
	if (!_threadInstance)
	{
		CloseHandle(_threadInstance);
		_threadInstance = NULL;
		throw ("create thread error!");
	}
	XThread::sleep(1);
	//std::cout << "create Thread OK" << std::endl;
#else
	if (pthread_create(&_threadInstance, NULL, XThread::proc, this) < 0)
	{
		throw ("create thread error");
	}
#endif
}


void XThread::join()
{
#ifdef _WIN32
	WaitForSingleObject(_threadInstance, INFINITY);
	CloseHandle(_threadInstance);
	_threadInstance = NULL;
#else
	pthread_join(_threadInstance, NULL);
	_threadInstance = NULL;
#endif
}

void XThread::sleep(const unsigned int mSecond)
{
#ifdef _WIN32
	::Sleep(mSecond);
#else
	timespec ts;
	ts.tv_sec = msecond / 1000;
	ts.tv_nsec = (msecond % 1000) * 1000000;
	nanosleep(&ts, NULL);
#endif
}

void XThread::work()
{
	if (_work)
	{
		_work->startWork();
	}
}

Niu_returnType Niu_Call XThread::proc(void* param)
{
	if (param)
	{
		XThread* xth = (XThread*)param;
		xth->work();
	}

	return 0;
}
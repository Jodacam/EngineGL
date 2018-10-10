#pragma once

class IEventCallback
{
public:
	virtual void operator() () = 0;
};

template<typename T>
class EventCallback : public IEventCallback
{
public:
	EventCallback(T* instance, void (T::*function)()): instance(instance), function(function) {}
	virtual void operator () () override { (instance->*function)(); }
private:
	void (T::*function)();
	T* instance;
};
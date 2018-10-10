#pragma once
#ifndef IEVENT_H_
#define IEVENT_H_


struct ClickInfomation
{
	int button;
	int x;
	int y;
	int state;
};
//Interface for custom render event, you can set up a new class that implements 
//IRenderEvent and the () operator will be called each after drawing if you binded them with EngineGL::BindRenderEvent(IRenderEvent).
//Remember to not make a lot of operations between renders.
class IRenderEvent
{
public:
	virtual void operator() () = 0;
};

//Generic class to bind events, reciberObject is the object that you are going to bind, and funtion is the Member function
//that the event is going to call. To bind the event you probably going to use EngineGL::BindRenderEvent()
template<typename EventReciber>
class OnRenderEvent : public IRenderEvent {
private:
	EventReciber* eventObject;
	void (EventReciber::*function)();
public:
	OnRenderEvent(EventReciber* reciberObject, void (EventReciber::*function)()) : eventObject(reciberObject),function(function)
	{}
	virtual void operator() () override { (eventObject->*function)(); }

};


class IClickEvent {
public:
	virtual void operator() (ClickInfomation info) = 0;

};


template<typename EventReciber>
class OnClickEvent {
private:
	EventReciber eventObject;
	void (EventReciber::*function)(ClickInfomation info);
	OnClickEvent(EventReciber* reciberObject, void (EventReciber::*function)(ClickInfomation info)) : eventObject(reciberObject), function(function)
	{}
	virtual void operator() (ClickInfomation info) override { (eventObject->*function)(info); }
};




#endif // !IRENDEREVENT_H_

#ifndef ECHO_RESPONDER_EH_HPP
#define ECHO_RESPONDER_EH_HPP

#include "../EventEngines/Reactor.hpp"
#include "MessageES.hpp"

class EchoResponderEH : public EventHandler
{
public:
  EchoResponderEH(MessageES::Ptr, Reactor&);
  virtual ~EchoResponderEH();

public:
  virtual void handle(const EventSource::EventTypes&);

private:
  Reactor& m_reactor;
};

#endif

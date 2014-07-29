#ifndef ECHO_RESPONDER_EH_HPP
#define ECHO_RESPONDER_EH_HPP

#include "../EventEngines/EventHandler.hpp"
#include "MessageES.hpp"

class EchoResponderEH : public EventHandler
{
public:
  explicit EchoResponderEH(MessageES::Ptr);
  virtual ~EchoResponderEH();

public:
  virtual void handle(const EventSource::EventTypes&);

private:
  MessageES::Ptr m_messageES;
};

#endif

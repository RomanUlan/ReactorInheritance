#include "EchoResponderEH.hpp"
#include "../IO/Epoll.hpp"

#include <boost/algorithm/string.hpp>

EchoResponderEH::EchoResponderEH(MessageES::Ptr p_messageES, Reactor& p_reactor)
  : EventHandler(p_messageES), m_reactor(p_reactor)
{
}

EchoResponderEH::~EchoResponderEH()
{
}

void EchoResponderEH::handle(const EventSource::EventTypes& p_eventTypes)
{
  EventSource::EventTypes::const_iterator iIn = p_eventTypes.find(Epoll::EventType::In);
  if ( (iIn != p_eventTypes.end()) && (p_eventTypes.size() == 1) )
  {
    MessageES::Ptr mES = boost::dynamic_pointer_cast<MessageES>(m_eventSource);
    std::string data;
    while (!boost::ends_with(data, "\n"))
    {
      std::string part;
      mES->read(part);
      data.append(part);
    }
    mES->getSocket()->write(data);
  }
  else
  {
    m_reactor.remove(m_eventSource->getDescriptor());
  }
}

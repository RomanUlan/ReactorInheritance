#include "EchoResponderEH.hpp"
#include "../IO/Epoll.hpp"

#include <boost/algorithm/string.hpp>

EchoResponderEH::EchoResponderEH(MessageES::Ptr p_messageES)
  : EventHandler(p_messageES), m_messageES(p_messageES)
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
    std::string data;
    while (!boost::ends_with(data, "\n"))
    {
      std::string part;
      m_messageES->read(part);
      data.append(part);
    }
    m_messageES->getSocket()->write(data);
  }
  else
  {
    throw std::runtime_error("Bad event for for responder");
  }
}

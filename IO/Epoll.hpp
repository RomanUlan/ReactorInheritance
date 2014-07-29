#ifndef EPOLL_HPP
#define EPOLL_HPP

#include "Socket.hpp"

#include <set>
#include <vector>

class Epoll
{
public:
  typedef boost::shared_ptr<Epoll> Ptr;

  struct EventType
  {
    static int Error;
    static int In;
    static int Out;
    static int Hup;
    static int RdHup;
  };
  typedef std::set<int> EventTypes;

  struct Event
  {
    Event(const EventTypes&, Socket::Descriptor);
    EventTypes eventTypes;
    Socket::Descriptor descriptor;
  };
  typedef std::vector<Event> Events;

public:
  Epoll(int p_size = 100);
  virtual ~Epoll();

private:
  Epoll(const Epoll&);
  Epoll& operator=(const Epoll&);

public:
  virtual void add(Socket::Ptr, const EventTypes&) const;
  virtual void modify(Socket::Ptr, const EventTypes&) const;
  virtual void remove(Socket::Descriptor) const;
  virtual void wait(Events&) const;

private:
  const int m_size;
  const int m_epollFd;
};

#endif

#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>
#include <boost/shared_ptr.hpp>

class Socket
{
public:
  typedef boost::shared_ptr<Socket> Ptr;
  typedef int Descriptor;

public:
  virtual ~Socket();

public:
  Descriptor getDescriptor() const;
  void setNonBlocking() const;
  void read(std::string&) const;
  void write(const std::string&) const;

protected:
  Socket(int, int, int);
  explicit Socket(int);
  Socket(const Socket&);
  Socket& operator=(const Socket&);

protected:
  Descriptor m_fd;
};

#endif

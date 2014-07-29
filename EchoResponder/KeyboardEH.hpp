#ifndef KEYBOARD_EH_HPP
#define KEYBOARD_EH_HPP

#include "../EventEngines/EventHandler.hpp"
#include "KeyboardES.hpp"
#include <fstream>

class KeyboardEH : public EventHandler
{
public:
  KeyboardEH(const std::string&, KeyboardES::Ptr);
  virtual ~KeyboardEH();

public:
  virtual void handle(const EventSource::EventTypes&);

private:
  std::ofstream m_file;
};

#endif

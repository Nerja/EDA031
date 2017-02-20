#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"
#include <vector>

class VNS : public NameServerInterface {
 public:
  virtual void insert(const HostName&, const IPAddress&);
  virtual bool remove(const HostName&);
  virtual IPAddress lookup(const HostName&) const;

 private:
  std::vector<std::pair<HostName, IPAddress>> db;

};

#endif

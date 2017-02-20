#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include <map>

class MNS : public NameServerInterface {
 public:
  virtual void insert(const HostName&, const IPAddress&);
  virtual bool remove(const HostName&);
  virtual IPAddress lookup(const HostName&) const;

 private:
  std::map<HostName, IPAddress> db;

};

#endif

#ifndef HNS_H
#define HNS_H
#include "nameserverinterface.h"
#include <vector>
class HNS : public NameServerInterface {
public:
  HNS(size_t size);
  void insert(const HostName&, const IPAddress&);
  bool remove(const HostName&);
  IPAddress lookup(const HostName&) const;
private:
  std::vector<std::vector<std::pair<HostName, IPAddress>>> data;
  size_t compute_index(const HostName& name) const;
};
#endif

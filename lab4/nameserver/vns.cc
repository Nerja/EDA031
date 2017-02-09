#include "vns.h"
#include <algorithm>

using namespace std;

void VNS::insert(const HostName& name, const IPAddress& ip) {
  data.push_back(make_pair(name, ip));
}

bool VNS::remove(const HostName& name) {
  auto it = find_if(data.begin(), data.end(), [name](const pair<HostName, IPAddress>&p){return p.first == name;});
  if(it != data.end()) {
    data.erase(it);
    return true;
  }
  return false;
}

IPAddress VNS::lookup(const HostName& name) const {
  auto it = find_if(data.begin(), data.end(), [name](const pair<HostName, IPAddress>& p){return p.first == name;});
  if(it != data.end())
    return it->second;
  else
    return NON_EXISTING_ADDRESS;
}

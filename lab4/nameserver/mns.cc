#include "mns.h"

using namespace std;

void MNS::insert(const HostName& name, const IPAddress& ip) {
  data.insert(make_pair(name, ip));
}

bool MNS::remove(const HostName& name) {
  auto it = data.find(name);
  if(it != data.end()) {
    data.erase(it);
    return true;
  }
  return false;
}

IPAddress MNS::lookup(const HostName& name) const {
  auto it = data.find(name);
  return it != data.end() ? it->second : NON_EXISTING_ADDRESS;
}

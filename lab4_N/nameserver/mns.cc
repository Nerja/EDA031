#include "mns.h"

void MNS::insert(const HostName& hostName, const IPAddress& ipAddress) {
  db.insert(make_pair(hostName, ipAddress));
}

bool MNS::remove(const HostName& hostName) {
  auto index = db.find(hostName);
  if(index != db.end()) {
    db.erase(index);
    return true;
  }
  return false;
}

IPAddress MNS::lookup(const HostName& hostName) const {
  auto index = db.find(hostName);
  if (index == db.end()) {
    return NON_EXISTING_ADDRESS;
  } else {
    return index->second;
  }
}

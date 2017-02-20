#include "vns.h"
#include <algorithm>

using namespace std;

void VNS::insert(const HostName& hostName, const IPAddress& ipAddress) {
  db.push_back(make_pair(hostName, ipAddress));
}

bool VNS::remove(const HostName& hostName){
  auto index =
    find_if(db.begin(), db.end(), [hostName](std::pair<HostName, IPAddress> p) {
      return p.first == hostName;
    });
    if(index != db.end()){
      db.erase(index);
      return true;
    }
    return false;
}

IPAddress VNS::lookup(const HostName& hostName) const {
  IPAddress lookup_result = NON_EXISTING_ADDRESS;
  auto index =
    find_if(db.begin(), db.end(), [hostName](std::pair<HostName, IPAddress> p) {
      return p.first == hostName;
    });

  if(index != db.end())
    lookup_result = index->second;

  return lookup_result;
}

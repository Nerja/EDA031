#include "hns.h"
#include <iostream>
#include <algorithm>

using namespace std;

HNS::HNS(int size) {
  db.resize(size);
}

void HNS::insert(const HostName& hostName, const IPAddress& ipAddress) {
  pair<HostName, IPAddress> node = make_pair(hostName, ipAddress);
  size_t index = hasher(hostName) % db.size();
  db[index].push_back(node);
}

bool HNS::remove(const HostName& hostName) {
  size_t index = hasher(hostName) % db.size();
  auto ind =
    find_if(db[index].begin(), db[index].end(), [hostName](pair<HostName, IPAddress> p) {
      return p.first == hostName;
    });

  if(ind != db[index].end()) {
    db[index].erase(ind);
    return true;
  }
  return false;
}

IPAddress HNS::lookup(const HostName& hostName) const {
  IPAddress lookup_result = NON_EXISTING_ADDRESS;
  size_t index = hasher(hostName) % db.size();
  auto ind =
    find_if(db[index].begin(), db[index].end(), [hostName](pair<HostName, IPAddress> p) {
      return p.first == hostName;
    });

  if(ind != db[index].end())
    lookup_result = ind->second;

  return lookup_result;
}

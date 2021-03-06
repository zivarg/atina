#ifndef ATINA_INOTIFY_H
#define ATINA_INOTIFY_H

#include "atinafd.h"

#include "atinapipefd.h"

#include <sys/epoll.h>

namespace Atina {

class Inotify {
public:
  Inotify();

  ~Inotify();

  bool open();

  void close();
  //
  //  bool addWatch(const std::string &aPathName, std::uint32_t aEventMask);
  //
  //  void removeWatch(const std::string &aPathName);
  //
  //  void removeAllWatches();

protected:
  static bool initFd(Fd &aFd);

  static bool initEpollFd(Fd &aEpollFd);

  static bool initPipeFd(PipeFd &aPipeFd);

//  static bool addEpollCtl(const int &aEpollFd, const int &aFd,
//                          epoll_event &aEpollEvent);
//
//  static void delEpollCtl(const int &aEpollFd, const int &aFd);

//  static epoll_event collectEpollEvent(const int &aEpollFd, const int &aFd);

  //  void removeWatch(int aWd, bool aIsRemoveFromCollection = true);
  //
  //  std::string wdToPathName(int aWd);
  //
  //  int pathNameToWd(const std::string &aPathName);

protected:
  Fd mFd{"Inotify file descriptor"};

  Fd mEpollFd{"Epoll file descriptor"};

  epoll_event mEpollEvent;

  PipeFd mStopPipeFd{"Stop pipe file descriptor"};

  epoll_event mStopPipeEpollEvent;
  //
  //  std::unordered_map<int, std::string> mWds;
};

} // namespace Atina

#endif // ATINA_INOTIFY_H

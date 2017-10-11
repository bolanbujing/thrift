#ifndef _MESSAGE_QUEUE_MANAGER_H_
#define _MESSAGE_QUEUE_MANAGER_H_ 1

#include <thrift/stdcxx.h>
#include <thrift/concurrency/MessageFifo.h>
#include <vector>

namespace apache {
namespace thrift {
namespace concurrency {

using stdcxx::shared_ptr;
class MessageQueueManager;
class Worker : public Runnable {
public:
  Worker(MessageQueueManager* manager, size_t id);
  void run();

private:
  MessageQueueManager* manager_;
  size_t id_;
};


class MessageQueueManager{
public:
  MessageQueueManager(stdcxx::shared_ptr<ThreadFactory> tf, size_t queue_num = 4, size_t capacity = 10000);

  ~MessageQueueManager();
  bool addTask(size_t id ,const stdcxx::shared_ptr<Runnable>& t);

  bool getTask(size_t id, stdcxx::shared_ptr<Runnable>& t);

  void start();
private:
  size_t queue_num_;
  size_t capacity_;
  std::vector<shared_ptr<Fifo>> queue_;
  shared_ptr<ThreadFactory> threadFactory_;
  std::vector<shared_ptr<Thread>> newThreads_;
};
}
}
}

#endif

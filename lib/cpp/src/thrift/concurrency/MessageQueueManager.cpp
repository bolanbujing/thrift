#include <thrift/concurrency/MessageQueueManager.h>

namespace apache {
namespace thrift {
namespace concurrency {
 
Worker::Worker(MessageQueueManager* manager, size_t id):
	manager_(manager),id_(id){}

void Worker::run(){
  for(;;){
    manager_->getTask(id_)->run();
  }
}


MessageQueueManager::MessageQueueManager(shared_ptr<ThreadFactory> tf, size_t queue_num, size_t capacity)
	:queue_num_(queue_num)
	,capacity_(capacity)
	,threadFactory_(tf){
  try{
	for(size_t i=0; i<queue_num;i++){
	  queue_.push_back(stdcxx::make_shared<Fifo>(capacity));
	}
  }catch(std::exception& e){
	throw std::runtime_error("new fail!");
	exit(0);
  }
}

MessageQueueManager::~MessageQueueManager(){
}


void MessageQueueManager::addTask(size_t id, stdcxx::shared_ptr<Runnable> t){
  thread_local static size_t k = 0;
  size_t index = 2*id+k;
  queue_[index]->addTask(t);
  k++;
  k = k%2;
}

stdcxx::shared_ptr<Runnable> MessageQueueManager::getTask(size_t id){
  return queue_[id]->getTask(); 
}

void MessageQueueManager::start(){
  for (size_t ix = 0; ix < queue_num_; ix++) {
    shared_ptr<Worker> worker
        = shared_ptr<Worker>(new Worker(this ,ix));
    newThreads_.push_back(threadFactory_->newThread(worker));
  }

  for (std::vector<shared_ptr<Thread>>::iterator ix = newThreads_.begin(); ix != newThreads_.end();++ix) {
    shared_ptr<Worker> worker = stdcxx::dynamic_pointer_cast<Worker, Runnable>((*ix)->runnable());
    (*ix)->start();
  }
}

}
}
}

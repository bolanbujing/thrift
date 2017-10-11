#include <thrift/concurrency/MessageQueueManager.h>
#include <chrono>
#include <thread>

namespace apache {
namespace thrift {
namespace concurrency {
 
Worker::Worker(MessageQueueManager* manager, size_t id):
	manager_(manager),id_(id){}

void Worker::run(){
  for(;;){
    stdcxx::shared_ptr<Runnable> t;
    if(manager_->getTask(id_, t)){
	t->run();
    }else{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
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


bool MessageQueueManager::addTask(size_t id, const stdcxx::shared_ptr<Runnable>& t){
  thread_local static size_t k = 0;
  size_t index = 2*id+k;
  if(queue_[index]->addTask(t)){
  	k++;
  	k = k%2;
	return true;
  }
  return false;
}

bool MessageQueueManager::getTask(size_t id, stdcxx::shared_ptr<Runnable>& t){
  return queue_[id]->getTask(t); 
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

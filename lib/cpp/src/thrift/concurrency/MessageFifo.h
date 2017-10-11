#ifndef _MESSAGE_FIFO_H_
#define _MESSAGE_FIFO_H_ 1

#include <vector>
#include <thrift/stdcxx.h>
#include <thrift/concurrency/Semaphore.h>
#include <thrift/concurrency/Thread.h>

namespace apache {
namespace thrift {
namespace concurrency {


class Fifo{
public:
  Fifo(size_t capacity):
	read_sema_(0), 
	write_sema_(capacity), 
	capacity_(capacity),
	read_pos_(0), 
	write_pos_(0){
    try{
    	deque_ = new stdcxx::shared_ptr<Runnable>[capacity];
    }catch(std::exception& e){
	
    }
  }

  ~Fifo(){
    if(deque_ != nullptr){
	delete []deque_;
	deque_ = nullptr;
    }
  }

  bool addTask(const stdcxx::shared_ptr<Runnable>& t){
    if(write_sema_.trywait()){
	deque_[write_pos_] = t;
	write_pos_ = (++write_pos_)%capacity_;
	read_sema_.post();
	return true;
    }
    return false;
  }

  bool getTask(stdcxx::shared_ptr<Runnable>& t){
    if(read_sema_.trywait()){
	t = deque_[read_pos_];
	read_pos_ = (++read_pos_)%capacity_;
	write_sema_.post();
	return true;
    }
    return false;
  }

private:
  SemaType read_sema_;
  SemaType write_sema_;
  size_t capacity_;
  stdcxx::shared_ptr<Runnable>* deque_;
  size_t read_pos_;
  size_t write_pos_;
};

}
}
}

#endif

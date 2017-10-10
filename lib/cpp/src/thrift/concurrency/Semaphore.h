#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_ 1

#include <boost/noncopyable.hpp>
#include <stdlib.h>
#include <stdint.h>
#include <stdexcept>
#include <semaphore.h>

namespace apache {
namespace thrift {
namespace concurrency {

class SemaType : public boost::noncopyable {
 public:
  SemaType(uint32_t count) {
    int ret = sem_init(&sema_, 0, count);
    if (ret != 0) throw std::runtime_error("failed: sem_init()");
  }

  ~SemaType() {
    sem_destroy(&sema_);
  }

  bool post() {
    return (sem_post(&sema_) == 0);
  }

  bool wait(double seconds) {
    if (seconds < 0) {
      return (sem_wait(&sema_) == 0);
    }
 /*   if (seconds > 0) {
      struct timespec ts;
      TimespecConvert(seconds, &ts);
      return (sem_timedwait(&sema_, &ts) == 0);
    }*/
    return (sem_trywait(&sema_) == 0);
  }

  bool trywait() {
    return sem_trywait(&sema_) == 0;
  }

 private:
  sem_t sema_;
};

}
} 
}

#endif

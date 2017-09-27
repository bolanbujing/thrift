#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "./gen-cpp/Calculator.h"
#include "binary_protocol.h"

using boost::shared_ptr;                                                                                        

void tserver();

int main() {
  tserver();
  return 0;
}
void tserver(){
  std::cout << "t server" << std::endl;

  const char* ip = "127.0.0.1";
  int port = 9090;
  int backlog = 5;

  std::cout << "ip=" << ip << " port="<<port << " backlog=" << backlog  << std::endl;

  int fd;
  int check_ret;

  fd = socket(AF_INET,SOCK_STREAM , 0);
  assert(fd >= 0);

  int sendbuf = 4096;
  int len = sizeof( sendbuf );
  setsockopt( fd, SOL_SOCKET, SO_SNDBUF, &sendbuf, sizeof( sendbuf ) );
  getsockopt( fd, SOL_SOCKET, SO_SNDBUF, &sendbuf, ( socklen_t* )&len );
  printf( "the send buffer size after settting is %d\n", sendbuf );

  struct sockaddr_in address;
  bzero(&address,sizeof(address));

  //转换成网络地址
  address.sin_port = htons(port);
  address.sin_family = AF_INET;
  //            //地址转换
  inet_pton(AF_INET, ip, &address.sin_addr);
  check_ret = connect(fd, (struct sockaddr*) &address, sizeof(address));
  assert(check_ret >= 0);
  //发送数据
  boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> strBuffer(new apache::thrift::transport::TMemoryBuffer());
  boost::shared_ptr<apache::thrift::protocol::TBinaryProtocol> binaryProtcol(new apache::thrift::protocol::TBinaryProtocol(strBuffer));
  //int32_t version = ((int32_t)0x80010000) | ((int32_t)TMessageType::T_CALL);
  binaryProtcol->writeMessageBegin("add", apache::thrift::protocol::T_CALL, 0);
  tutorial::Calculator_add_args args;
  args.num1 = 10;
  args.num2 = 20;
  args.write(binaryProtcol.get());
  binaryProtcol->writeMessageEnd();
  std::string serialized = strBuffer->getBufferAsString();
  char buff[1024];
  memset(buff, 0, sizeof(buff));
  /*uint32_t size = htonl(serialized.size());
  memcpy(buff,(char*)&size, sizeof(uint32_t));
  memcpy(buff+sizeof(uint32_t), serialized.c_str(), serialized.size());
*/
  memcpy(buff, serialized.c_str(), serialized.size());

  //
  int rets = send(fd, buff, serialized.size(), 0);
  std::cout << "send:" << rets << std::endl;
  //send(fd, oob_data, strlen(oob_data), MSG_OOB);
  //send(fd, normal_data, strlen(normal_data), 0);
  char RecvBuf[1024];
  memset(RecvBuf, 0, sizeof(RecvBuf));
  int retr = recv(fd, RecvBuf, 1024, 0);
  if(retr <= 0){std::cout << "over" << std::endl;} 
  else {std::cout <<"recv:"<<retr << std::endl;}
  {
    boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> strBuffer(new apache::thrift::transport::TMemoryBuffer((uint8_t*)(RecvBuf), retr));
    boost::shared_ptr<apache::thrift::protocol::TBinaryProtocol> binaryProtcol(new apache::thrift::protocol::TBinaryProtocol(strBuffer));
    std::string name;
    apache::thrift::protocol::TMessageType mtype;
    int32_t seqid;
    int xfer = binaryProtcol->readMessageBegin(name, mtype, seqid);
    std::cout << xfer << ", " << name<<" , " << mtype<< " , " << seqid << std::endl;
    tutorial::Calculator_add_result result;
    result.read(binaryProtcol.get());
    std::cout << " result = "<<result.success << std::endl;
    binaryProtcol->readMessageEnd();
  }

  close(fd);
}


# ddms
distributed directional manager system 

-------------------------------------------------------------------------

Master主机做分发，其他节点主机之间进行check，
Ver 1.0 Master主机固定，实现文件同步功能
Ver 2.0 Master根据具体的任务优先级进行轮流最master节点，可以对文件进行分类，分情况传输
Ver 3.0 传输协议和通讯协议标准化，考虑安全传输，防丢，防劫持，防篡改等
ver 4.0 根据情况，开发跨平台客户端或者web端实现节点的可用性和性能性监控


                    +----------+
                    |  Master  |
                    +----+-----+
                         |
                         |
                         | dispatch
                         |
                         |
                         |
                         |
+---------+              |                  +---------+
|  Node1  | <---------------------------->  |  Node2  |
+-+-------+              |                  +----+----+
  |                      |                       |
  |                      |                       |
  |                      |                       |
  |                      |                       |
  |                      |                       |
  |    check        +----v----+      check       |
  +-----------------+  Node3  +------------------+
                    +---------+

					
					
					
--------------------------------------------------------------------------

基本完成ddms之后

加入IP数据报转发功能。
1、正常转发ip数据报，到其他节点，进行处理
2、负载过高，转发到其他节点处理
3、通过ip转发进行负载均衡
前期可只考虑同局域网中IP转发（较简单）后期可考虑跨路由Nat转化，IP通道，VPN，或者socket打洞等实现跨路由，直接连接到internet













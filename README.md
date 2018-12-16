- bitcask   ![Build Status](https://travis-ci.com/miaogen123/bitcask.svg?branch=master)

  实现一个bitcask 型的存储

  ------

  ## Points

  - 定时merge
  - CRC冗余
  - hash算法使用了BKDRhash
  - hash的实现与持久化
  - (可选) hintfile的实现
  - (扩展)时间轮的实现,用来实现expire

  ## Usage

  - get()与put() 的接口
  - 非阻塞接口

  ------

  ## 参考文章/献

  1. [Bitcask存储系统架构设计思想](https://blog.csdn.net/chdhust/article/details/77801890)

  ## 遇到的问题：

  - windows不支持posix，多线程追加同一文件会造成竞争, linux不会,但是要注意多线程不能同时使用一个static对象读写
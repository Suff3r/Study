hello world!
int open(const char *pathname, int flags, mode_t mode)

其中flag代表文件的打开方式
O_RDONLY: 以只读方式打开文件
O_WRONLY：以只写的方式打开文件
O_RDWR：以读写的方式打开文件
O_CREAT：若打开的文件不存在，则创建该文件
O_EXCL：如果打开文件是设置了O_CREAT，但是该文件存在，则导致调用失败
O_TRUNC：如果以只写或只读方式打开一个已存在的文件，将该文件截至0
O_APPEND：追加的方式打开文件
O_NONBLOCK：用于非堵塞接口i/o
O_NODELAY
O_SYNC:当数据被写入外存或者其他设备后，操作才返回。
其中mode是打开的权限
S_IRWXU 00700 设置文件所有者的读，写，执行权限
S_IRWXG 00070 设置文件所在用户组的读，写，执行权限
S_IRWXO 00007 设置其他用户的读，写，执行权限
S_IRUSR 00400 设置文件所有者的读权限
S_IWUSR 00200 设置文件所有的写权限
S_IXUSR 00100 设置文件所有者的执行权限
S_IRGRP 00040 设置用户组的读权限
S_IWGRP 00020 设置用户组的写权限
S_IXGRP 00010 设置用户组的执行权限
S_IROTH 00004 设置其他用户的读权限
S_IWOTH 00002 设置其他用户的写权限
S_IXOTH 00001 设置其他用户的执行权限

文件的读操作：
ssize_t read(int fd,void *buf,size_t count);
fd代表文件描述符，buf代表读取的数据存放的buf指针所指向的缓冲区，count代表读取数据的字节数
函数调用成功，返回为读取的字节数，否则返回-1

文件读和写的例子
void open_and_read_file()
{

	int fd,n;
	char buf[100];
	char *path="/home/zhf/zhf/c_prj/c_test.txt";
	fd=open(path,O_RDWR);
	n=read(fd,buf,20);
	printf("the content is %s\n",buf);
}

在这里文件都是从头开始读的，那么如果我想从某个位置比如第N个字节开始读取的时候该如何操作呢，这里就需要用到文件定位函数lseek
off_t lseek(int fildes,off_t offset,int whence);\
		  fildes是文件描述符
		  offset是偏移量
		  whence代表用于偏移时的相对位置，可以取如下的几个值
		  SEEK_SET: 从文件的开头位置计算偏移量
		  SEEK_CUR: 从当前的位置开始计算偏移量
		  SEEK_END: 从文件的结尾开始计算偏移量
		  函数修改如下： 首先采用lseek函数将文件定位到从第11个字节开始，然后read将从第11个字节开始读取。
		  对于写操作也是一样的。"")""
}
          hello world!

# openssl-test
openssl学习过程代码

openssl版本:OpenSSL 1.1.1-dev  xx XXX xxxx

	stack.c 堆栈结构测试学习
	lhash.c	哈希结构测试学习
	mem_alloc.c  openssl内存分配函数测试
	dso.c	测试openssl的动态库加载功能，DSO,测试用例有问题
	membio.c openssl的抽象IO测试，内存IO。
	fileBio.c openssl file BIO
	sock_bio_ser.c	socket BIO server
	sock_bio_cli.c	socket BIO client
	mdbio.c	 md、NULL BIO 测试学习
	cipher_bio.c 加/解密 BIO
	ssl_bio.c  ssl BIO
	fileBio2.c 文件BIO
	conf1.c	 openssl配置文件加载测试
	conf_test.txt 配置文件，测试文件
	conf_session.c  给定配置段信息，从堆栈获取所有值
	rand.c 	随机数,额...

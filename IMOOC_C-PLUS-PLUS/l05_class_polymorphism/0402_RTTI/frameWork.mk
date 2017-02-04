OBJS = $(SRCS:.cpp=.o) # 把源文件列表中美歌文件名的 .c 替换为 .o

ifdef DEBUG
CLAAGS = -O -g
else
CFLAGS = -O
endif

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ # $@ 当前规则的左半边， $^ 当前规则的右半边
main.o: Plane.h Bird.h
Plane.o Bird.o: Flyable.h # 规则名部分可以是多个文件，用空格分开
Plane.o: Plane.h
Bird.o: Bird.h
clean: # 没有任何依赖，因此不检查时间戳，每次都执行该任务
	rm -f $(OBJS) $(PROG)
install:
	cp $(PROG) $(INSTALL_ROOT)/bin
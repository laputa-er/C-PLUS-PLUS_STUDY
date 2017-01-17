class Array
{
public:
	Array(int len);
	~Array();
	int getLen();
	Array& setLen(int len);
	Array& printInfo();
private:
	int len;
};
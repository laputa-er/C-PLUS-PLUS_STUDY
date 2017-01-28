class Array
{
public:
	Array(int len)
	{
		this->len = len;
	}
	int getLen()
	{
		return len;
	}
	void setLen(int len)
	{
		this->len = len;
	}
private:
	int len;
}
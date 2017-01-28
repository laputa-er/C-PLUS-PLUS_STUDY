class Array
{
public:
	Array(int count = 0);
	Array(const Array& array);
	~Array();
	void setCount(int count);
	int getCount();
	void printArr();
private:
	int m_iCount;
	int *m_pArr;
};

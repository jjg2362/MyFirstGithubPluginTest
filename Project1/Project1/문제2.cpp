#include <iostream>
using namespace std;

class Circle
{
private:
	int m_rad;
public:
	Circle(const int &rad_in = 0) : m_rad{ rad_in } {}
	int getRad() const { return m_rad; }
};

template <class T>
class MyVector_BASE
{
protected:
	T * m_data;
	int m_size;
	int m_capacity;
public:
	MyVector_BASE()
	{
		m_data = new T[3];
		m_capacity = 3;
		m_size = 0;
	}
	~MyVector_BASE()
	{
		delete[] m_data;
	}

	MyVector_BASE &pushBack(const T &data_in)
	{
		if (m_size < m_capacity)
		{
			cout << "push : " << data_in << endl;
			m_data[m_size++] = data_in;
		}
		else
		{
			cout << "MyVector 확장!" << endl;
			cout << "push : " << data_in << endl;

			T *temp = m_data;				
			m_data = new T[m_capacity + 3];		
			for (int i = 0; i < m_size; i++)	
				m_data[i] = temp[i];

			m_data[m_size++] = data_in;
			m_capacity += 3;

			delete[] temp;
		}
		return (*this);
	}

	void print()
	{
		for (int i = 0; i < m_size; i++)
			cout << m_data[i];
		cout << endl << endl;
	}
};

template <class T>
class MyVector : public MyVector_BASE<T>
{
};

template <>
class MyVector<Circle> : public MyVector_BASE<Circle>
{
public :
	MyVector &pushBack(const Circle &data_in)
	{
		if (m_size < m_capacity)
		{
			cout << "radius : " << data_in.getRad() << endl;
			m_data[m_size++] = data_in;
		}
		else
		{
			cout << "MyVector 확장!" << endl;
			cout << "radius : " << data_in.getRad() << endl;

			Circle *temp = m_data;
			m_data = new Circle[m_capacity + 3];
			for (int i = 0; i < m_size; i++)
				m_data[i] = temp[i];

			m_data[m_size++] = data_in;
			m_capacity += 3;

			delete[] temp;
		}
		return (*this);
	}

	void print()
	{
		int sum = 0;
		for (int i = 0; i < m_size; i++)
			sum += m_data[i].getRad();
		cout << "반지름의 총합 : " << sum << endl << endl;
	}
};

int main()
{
	MyVector<int> iVectorList;
	iVectorList
		.pushBack(1)
		.pushBack(2)
		.pushBack(3)
		.pushBack(4)
		.pushBack(5)
		.print();

	MyVector<char> cVectorList;
	cVectorList
		.pushBack('A')
		.pushBack('B')
		.pushBack('C')
		.pushBack('D')
		.pushBack('E')
		.print();

	MyVector<Circle> circleVectorList;
	circleVectorList
		.pushBack(Circle(1))
		.pushBack(Circle(2))
		.pushBack(Circle(3))
		.pushBack(Circle(4))
		.pushBack(Circle(5))
		.print();

	return 0;
}
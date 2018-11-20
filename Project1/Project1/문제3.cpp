#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class People
{
private :
	string m_name;
public : 
	People(const string &name_in = "") : m_name{ name_in } {}
	string getName() const { return m_name; }

	bool operator <(const People &people_in)
	{
		return ((*this).getName() < people_in.getName());
	}
};

template<class T>
class SortedArray_BASE
{
protected :
	vector<T> m_data;
public :
	SortedArray_BASE(){}
	~SortedArray_BASE(){}

	SortedArray_BASE &insert(const T &data_in)
	{
		cout << "insert : " << data_in << endl;
		m_data.push_back(data_in);
		sort(m_data.begin(), m_data.end());
		print();

		return (*this);
	}

	void remove(const T &data_in)
	{
		cout << "remove : " << data_in << endl;
		int count = 0;
		for (int i = 0; i < m_data.size() - 1; i++)
		{
			if (m_data[i] == data_in)
			{
				for (int j = i; j < m_data.size() - 1; j++)
					m_data[j] = m_data[j + 1];
				--i;
				++count;
			}
		}
		m_data.resize(m_data.size() - count);
		print();
	}

	void print()
	{
		for (auto & e : m_data)
			cout << e << " ";
		cout << endl << endl;
	}
};

template<class T>
class SortedArray : public SortedArray_BASE<T>
{
};

template<>
class SortedArray<People> : public SortedArray_BASE<People>
{
public : 
	SortedArray &insert(const People &data_in)
	{
		cout << "insert : " << data_in.getName() << endl;
		m_data.push_back(data_in);
		sort(m_data.begin(), m_data.end());
		print();

		return (*this);
	}

	void remove(const People &data_in)
	{
		cout << "remove : " << data_in.getName() << endl;
		int count = 0;
		for (int i = 0; i < m_data.size() - 1; i++)
		{
			if (m_data[i].getName() == data_in.getName())
			{
				for (int j = i; j < m_data.size() - 1; j++)
					m_data[j] = m_data[j + 1];
				--i;
				++count;
			}
		}
		m_data.resize(m_data.size() - count);
		print();
	}

	void print()
	{
		for (auto & e : m_data)
			cout << e.getName() << " ";
		cout << endl << endl;
	}
};

int main()
{
	SortedArray<int> iSortedArray;
	iSortedArray
		.insert(2)
		.insert(1)
		.insert(4)
		.insert(6)
		.insert(5)
		.insert(2)
		.insert(5);

	iSortedArray.remove(2);
	iSortedArray.remove(5);

	SortedArray<People> pSortedArray;
	pSortedArray
		.insert(People("Alax"))
		.insert(People("Berry"))
		.insert(People("Mary"))
		.insert(People("Harry"))
		.insert(People("Eric"))
		.insert(People("Alonzo"))
		.insert(People("Edward"));

	pSortedArray.remove(People("Alax"));
	pSortedArray.remove(People("Edward"));

	return 0;
}
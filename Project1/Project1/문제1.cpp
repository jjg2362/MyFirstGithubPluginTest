#include <iostream>
using namespace std;

class Circle
{
private :
	int m_rad;
public :
	Circle(const int &rad_in = 0) : m_rad{rad_in}{}
	int getRad() const { return m_rad; }
};

template <typename T>
T* concat(T list1[], const int &list1_len, T list2[], const int &list2_len)
{
	T * result = new T[list1_len + list2_len];
	for (int i = 0; i < list1_len; i++)
		result[i] = list1[i];
	for (int i = 0; i < list2_len; i++)
		result[i + list1_len] = list2[i];
	return result;
}

template<typename T>
void printList(T list[], const int &list_len)
{
	for (int i = 0; i < list_len; i++)
		cout << list[i];
	cout << endl << endl;
}

template<>
void printList(char list[], const int &list_len)
{
	for (int i = 0; i < list_len; i++)
		cout << list[i] << " ";
	cout << endl << endl;
}

template<>
void printList(Circle list[], const int &list_len)
{
	for (int i = 0; i < list_len; i++)
		cout << "radius : "<< list[i].getRad() << endl;
	cout << endl;
}

int main()
{
	int iList1[] = { 1, 2, 3 };
	int iList2[] = { 4, 5, 6 };
	int * iListResult = concat<int>(iList1, 3, iList2, 3);
	printList(iListResult, 6);

	char cList1[] = { 'A','B','C' };
	char cList2[] = { 'D', 'E', 'F' };
	char * cListResult = concat<char>(cList1, 3, cList2, 3);
	printList(cListResult, 6);

	Circle circleList1[] = { Circle(1), Circle(2), Circle(3) };
	Circle circleList2[] = { Circle(4), Circle(5), Circle(6) };
	Circle *circleListResult = concat<Circle>(circleList1, 3, circleList2, 3);
	printList(circleListResult, 6);

	return 0;
}

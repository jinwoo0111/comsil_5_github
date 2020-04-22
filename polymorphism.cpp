#include<iostream>
#include<string>
using namespace std;

//Linked List Node
template <class T>
class Node{
public:
	T data;
	Node *link;
	Node(T element)
	{
		data = element;
		link = 0;
	}
};

//Linked List Class
template <class T>
class LinkedList
{
protected:
	Node<T> *first;
	int current_size;
public:
	LinkedList()
	{
		first = 0;
		current_size = 0;
	};
	int Getsize() { return current_size;}; // 리스트의 노드 개수를 리턴
	void Insert(T element); // 맨 앞에 원소를 삽입
	virtual bool Delete(T &element);//맨뒤의 원소를 삭제
	void Print();  //리스트를 출력
};

template <class T>
void LinkedList<T>::Insert(T element)
{
	Node<T> *newnode = new Node<T>(element);
	newnode->link = first;
	first = newnode;
	current_size++;
}

template <class T>
bool LinkedList<T>::Delete(T &element)
{
	if(first == 0)
		return false;
	Node<T> *current = first;
	Node<T> *previous = 0;
	while(1)
	{
		if(current->link == 0) //find end node
		{
			if(previous) previous->link = current->link;
			else first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	
	element = current->data;
	delete current;

	current_size--;
	return true;
}

template <class T>
void LinkedList<T>::Print()
{
	if(first==0)
		return;
	Node<T> *current = first;
	int num = 1;
	
	while(current)
	{
		if(num!=1)
			cout<<"->";
		cout<<"["<<num<<"|"<<current->data<<"]";
		current = current->link;
		num++;
	}

	cout<<endl;
}

//Stack Class
template <class T>
class Stack : public LinkedList<T>
{
	public:
		bool Delete(T &element);  //맨 앞의 원소를 삭제
};


template <class T>
bool Stack<T>::Delete(T &element)
{
	if(this->first ==0)
		return false;
	Node<T> *tmp;

	tmp =this-> first;
	this->first = this-> first->link;
	element = tmp->data;
	delete tmp;
	this->current_size--;
	return true;	
}


//함수의 선어
void prnMenu()
{
	cout<<"*********************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제   3. 출력    4. 종료 *"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main()
{
/*
	//연결리스트 테스트용 코드
	double dVal;
	string strVal;
	LinkedList<double> dList;
	LinkedList<string> strList;
	dList.Insert(3.14);
	dList.Insert(123456);
	dList.Insert(-0.987654);
	dList.Print();
	dList.Delete(dVal);
	cout<<"삭제된 마지막 원소:"<<dVal<<endl;
	dList.Print();
	dList.Insert(777.777);
	dList.Print();
	dList.Delete(dVal);
	cout<<"삭제된 마지막 원소 :"<<dVal<<endl;
	dList.Delete(dVal);
	cout<<"삭제된 마지막 원소 :"<<dVal<<endl;
	dList.Print();
	dList.Delete(dVal);
	cout<<"삭제된 마지막 원소 :"<<dVal<<endl;
	dList.Print();

	strList.Insert("This");
	strList.Insert("is a");
	strList.Insert("Template");
	strList.Insert("Example");
	strList.Print();
	strList.Delete(strVal);
	cout<<"삭제된 마지막 원소 : "<<strVal<<endl;
	strList.Insert("Class");
	strList.Print();

	return 0;
*/
	//스택 및 연결 리스트 테스트용 코드
	int mode,selectNumber, tmpItem;
	LinkedList<int> *p;
	bool flag = false;

	cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
	cin>>mode;

	//기반 클래스의 포인터를 사용하여 기반 클래스뿐만 아니라
	//파생 클래스의 인스턴스 또한 접근할 수 있다.
	if(mode == 1)
		p = new Stack<int>();//정수를 저장하는 스택
	else
		p = new LinkedList<int>();//정수를 저장하는 연결 리스트

	do{
		prnMenu();
		cin>>selectNumber;
		switch(selectNumber)
		{
		case 1:
			cout<<"원하시는 값을 입력해주세요: ";
			cin>>tmpItem;
			p->Insert(tmpItem);
			cout<<tmpItem<<"가 삽입되었습니다."<<endl;
			break;
		case 2:
			if(p->Delete(tmpItem)==true)
				cout<<tmpItem<<"가 삭제되었습니다."<<endl;
			else
				cout<<"비었습니다. 삭제 실패"<<endl;
			break;
		case 3:
			cout<<"크기: "<<p->Getsize()<<endl;
			p->Print();
			break;
		case 4:
			flag = true;
			break;
		default:
			cout<<"잘못 입력하셨습니다."<<endl;
			break;
		}
		if(flag)
			break;
	}
	while(1);
	
	return 0;
}


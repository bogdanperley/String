#pragma once
#include<cstring>
#include <iostream>
class String
{
public:
	class iterator{
	public:
		iterator(char* str);
		iterator& operator++ ();
		iterator operator++ (int);
		iterator& operator-- ();
		iterator operator-- (int);
		iterator operator+ (int position)const;
		iterator& operator- (int position);
		iterator& operator+= (int position);
		iterator& operator-= (int position);
		bool operator==(const char ch)const;
		char& operator*();

	private:
		char* ptr_str{};
	};

	iterator begin();
	iterator end();
	String() = default;//default constructor
	~String();// destructor
	String(const String&copy);// constructor copy 
	explicit String(const char* str); // users  constructor
	void concate (const String& copy);
	void print () const;
	void size() const;
	bool compare(const String& copy) const;
	long long find_str(const char* str) const;
	void upent(const char* str);
	String sub_str(int position, int len_copy);
	void replace(int position, int len_copy, const String& copy);
	//void copy(const char* dest, int count, int position);
	String& operator=(const String& copy);  
	String& operator+=(const String& copy);
	String& operator+= (const char* copy);
	String operator+(const String& copy) const;
	String operator+(const char* copy) const ;
	char& operator[] (int position);
	bool operator==(const String& copy) const;
	bool operator!=(const String& copy) const;
	bool contains(const String& copy) const; 
	bool contains(const char* str) const;
	bool start_with(const String& copy) const;
	bool start_with(const char* str) const;
	//bool end_with(const String& copy) const;
	//bool end_with(const char* str) const;
	void erase(int position, int len_del);
private:
	char* str_{};
	int capacity_{};
	int leght_{};
};


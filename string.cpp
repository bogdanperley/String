#include "string.h"

char& String::iterator::operator*()
{
	return *ptr_str; 
} 

String::iterator& String::iterator::operator++()
{
	ptr_str++;
	return *this;
}

String::iterator String::iterator::operator++(int)
{
	iterator tmp{ ptr_str };
	ptr_str++;
	return tmp;
}

String::iterator& String::iterator::operator--() {
	ptr_str--;
	return *this;
}

String::iterator String::iterator::operator--(int) {
	iterator tmp{ ptr_str };
	ptr_str--;
	return tmp;
}

String::iterator String::iterator::operator+(int position) const{
	iterator tmp{ ptr_str + position };
	return tmp;
}



String::iterator& String::iterator::operator-(int position) {
	ptr_str - position;
	return *this;
}

String::iterator& String::iterator::operator+=(int position) {
	
	ptr_str += position;
	return *this;
}

String::iterator& String::iterator::operator-=(int position) {
	
	ptr_str -= position;
	return *this;

}

bool String::iterator::operator==(const char ch) const
{
	return *ptr_str == ch;
}


String::iterator::iterator(char* str) {
	ptr_str = str;
}

String::iterator String::begin()
{	
	return String::iterator(str_);
}

String::iterator String::end()
{
	return String::iterator(str_ + leght_);
}


String::String(const String& copy )
{
	str_ = new char[copy.capacity_];
	strcpy_s(str_, copy.leght_, copy.str_ );
	capacity_ = copy.capacity_;
	leght_ = copy.leght_;

}

String::String(const char* str)
{
	capacity_ = leght_ = strlen(str) + 1; 
	str_ = new char[leght_];
	strcpy_s(str_,leght_, str);
}

String::~String()
{
	delete[] str_;
}


void String::print() const
{
	std::cout << str_ << std::endl;
}

void String::size() const
{
	std::cout << strlen(str_) << std::endl;
}

void String::concate(const String& copy)
{
	if (capacity_ > copy.leght_ + leght_) {
		strcat_s(str_, leght_, copy.str_);
		leght_ = leght_ + copy.leght_;
		return;
	}
	capacity_ = copy.leght_ + leght_ + 1;
	char* str = new char[capacity_];
	strcpy_s(str, leght_, str_);  
	leght_ = leght_ + copy.leght_;
	strcat_s(str, copy.leght_, copy.str_);
	str_ = str;

	//leght_ = capacity_ = strlen(copy.str_) + leght_ +1;
	//int size{ copy.capacity_ + copy.capacity }; 
	//str_ = new char[copy.capacity_ + copy.capacity];
	////strcpy_s(str_, copy.leght_, copy.str_);
	//capacity_ = copy.capacity_;
	//leght_ = copy.leght_;
 //	 strcat(str_, copy.str_);
}

void String::upent(const char* str)
{
	auto len_str{ strlen(str) };
	if (capacity_ > len_str + leght_) {
		strcat_s(str_, leght_, str);
		leght_ = leght_ + len_str;
		return;
	}
	capacity_ = len_str + leght_ + 1;
	char* str1 = new char[capacity_];
	strcpy_s(str1, leght_, str_);
	leght_ = leght_ + len_str;
	strcat_s(str1, len_str, str );
	str_ = str1;
}

bool String::compare(const String& copy) const
{
	return strcmp(str_, copy.str_) == 0;

	/*auto len_1{strlen(str_)};
	auto len_2{ strlen(copy.str_) };
	if (len_1 != len_2) {
		return false;
	}
	for (int it{}; it < len_1; it++) {
		if (str_[it] != copy.str_[it]) {
			return false;
		}

	}

	return true;
	*/
	/*				
	*  if(strcmp(str_, copy.str_) == 0 ){
        return true;
    }
    return false;
	*/
}

long long  String::find_str(const char* str) const{
	auto len{ strlen(str_) };
	int error{ -1 };
	char* index{ strstr(str_, str) };
	if (index == nullptr) { // if not found
		return error;
	}
	return  { index - str };
}

String String::sub_str(int position, int len_copy)
{
	if (len_copy == 0) {
		return String{};
	}
	String str1{};
	str1.capacity_ = len_copy +1;
	str1.str_ = new char[str1.capacity_];
	str1.leght_ = len_copy;
	strcpy_s(str1.str_, len_copy, (str_ + position ) );
	return  str1 ;	
}

//void String::copy(const char* dest, int count, int position)
//{	
//	strcpy_s (dest,  count, (str_ + position));
//}
 

void String::replace(int position, int len_copy, const String& copy)
{	
	 strcpy_s(str_ + position , len_copy, (copy.str_));

}


String& String::operator=(const String& copy)
{ 
	this->capacity_ = copy.capacity_;
	this->leght_ = copy.leght_;
	delete[] str_;
	this->str_ = new char[capacity_];
	strcpy_s(str_, copy.leght_, copy.str_);
	return *this;
}

String& String::operator+=(const String& copy)
{
	String t{ *this };
	this->capacity_ = copy.capacity_ + capacity_;
	this->leght_ = copy.leght_ + leght_;
	delete[] str_;
	this->str_ = new char[this->capacity_];
	strcat_s(this->str_, t.leght_, t.str_);
	strcat_s(this->str_, copy.leght_, copy.str_);
	return *this;
}

bool String::operator==(const String& copy) const
{
	return strcmp(this->str_, copy.str_) == 0;
}

bool String::operator!=(const String& copy) const
{
	return !(*this == copy);
}

String& String::operator+=(const char* copy) 
{
	String t{ *this };
	this->capacity_ += strlen(copy) + 1;
	this->leght_ += strlen(copy);
	delete[] str_;
	this->str_ = new char[this->capacity_];
	strcat_s(this->str_, t.leght_, t.str_);
	strcat_s(this->str_, strlen(copy), copy);
	return *this;
}

String String::operator+(const String&  copy) const 
{
	String ret_tem;
	//ret_tem.str_ = str_ + copy.str_;
	strcat_s(ret_tem.str_, leght_, str_);
	strcat_s(ret_tem.str_, copy.leght_, copy.str_);
	return ret_tem;
}	

String String::operator+(const char* copy) const // 3 met
{
	String ret_tem;
	//ret_tem.str_ = str_ + copy;
	strcat_s(ret_tem.str_, leght_, str_);
	strcat_s(ret_tem.str_, strlen(copy), copy);
	return ret_tem;
}

char& String::operator[](int position)
{
	return str_[position];
}


bool String::contains(const String& copy) const
{
	return strstr(str_,copy.str_ ) != nullptr;
}

bool String::contains(const char* str) const
{
	return strstr(str_, str) != nullptr;
}

bool String::start_with(const char* str) const 
{
	if (str == nullptr ) {
		return false;
	}
	const auto len_str{ strlen(str) };
	
	if (str_[0] != str[0] || leght_ < len_str ) {
		return false;
	}
	

	for (auto i{1}; i < len_str; i++)
	{
		if (str_[i] != str[i]) {
			return false;
		}
	}
	return true;
}

bool String::start_with(const String& copy) const
{
	if (copy.str_ == nullptr) {
		return false;
	}

	if (str_[0] != copy.str_[0] || leght_ < copy.leght_) {
		return false;
	}

	for (auto i{ 1 }; i < copy.leght_; i++)
	{
		if (str_[i] != copy.str_[i]) {
			return false;
		}
	}
	return true;
}

//bool String::end_with(const String& copy) const
//{	
//	
//	if (copy.leght_ > leght_) {
//		return false;
//	}
//	for (int  it_1{ leght_ - 1 }, it_2{ copy.leght_ - 1 }; it_1 >= 0 || it_2 >= 0; it_1--, it_2--) {
//		if (str_[it_1] != copy.str_[it_2]) {
//			return false;
//		}
//	}
//	return true;
//	/*auto len_copy_str{ strlen(copy.str_) };
//	auto  position_str_{ strlen(str_) - strlen(copy.str_) };
//	if (str_[position_str_] != copy.str_[0]) {
//		return false;
//	}
//	for (auto i{0}; i > len_copy_str; i++ ){
//		if (str_[position_str_ + i] != copy.str_[i]){
//				return false;
//		}
//	}
//	return true;*/
//}

//bool String::end_with(const char* str) const
//{
//	const auto len_str{ strlen(str)};
//	if (len_str > leght_) {
//		return false;
//	}
//	for (size_t it_1{ leght_ - 1 }, it_2{ len_str - 1 }; it_1 >= 0 || it_2 >= 0; it_1--, it_2--) {
//		if (str_[it_1] != str[it_2]) {
//			return false;
//		}
//	}
//	return true;
//}
	/*const auto len_copy_str{ strlen(str) };
	auto  position_str_{ leght_ - len_copy_str };
	if (position_str_ < 0) {
		return false;
	}

	if (str_[position_str_] != str[0]) {
		return false;
	}

	for (auto i{ 0 }; i > len_copy_str; i++) {
		if (str_[position_str_ + i] != str_[i]) {
			return false;
		}
	}
	return true;*/

     
void String::erase(int position, int len_del)
{
	if (capacity_ < position || len_del > leght_ ) {
		return;
	}

	auto count{ leght_ - len_del - position };

	for (; position <  count; position++) 
	{
		str_[position] = str_[position + len_del];
	}

	leght_ -= len_del; 

	str_[leght_] = '\0';
} 




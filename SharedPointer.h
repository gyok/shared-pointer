#pragma once
template <typename T>
class SharedPointer
{
	size_t* mp_pointer_count;
	T* mp_data;
public:
	SharedPointer(T*);
	SharedPointer(const SharedPointer<T>&);
	~SharedPointer();

	T* Get() const;
	T& operator*() const;
	T* operator->() const;
	friend SharedPointer<T> MakeShared(Args&&...);
};


template<typename T>
SharedPointer<T>::SharedPointer(T* ip_data)
{
	std::cout << "SharedPointer(T* ip_data)" << std::endl;
	mp_pointer_count = new size_t{ 1 };
	mp_data = ip_data;
}


template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& ip_sp) {
	std::cout << "SharedPointer(const SharedPointer<T>&)" << std::endl;
	mp_pointer_count = ip_sp.mp_pointer_count;
	++*mp_pointer_count;
	mp_data = ip_sp.mp_data;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
	std::cout << "~SharedPointer [" << *mp_pointer_count << " -> " << *mp_pointer_count - 1 << "]" << std::endl;
	if (--*mp_pointer_count < 1) {
		delete mp_data;
	}
}

template<typename T>
T* SharedPointer<T>::Get() const
{
	return mp_data;
}

template<typename T>
T& SharedPointer<T>::operator*() const
{
	return mp_data;
}

template<typename T>
T* SharedPointer<T>::operator->() const
{
	return mp_data;
}
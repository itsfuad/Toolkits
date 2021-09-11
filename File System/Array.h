#pragma once
#include <iostream>

/*
@brief
Dynamic Array Class
*/
template <typename T>
class Vector {
public:
	Vector() {
		/// allocate 2 elements
		ReAlloc(2);
	}
	~Vector() {
		delete[] m_Data;
	}
	void PopBack() {
		if (m_size > 0) {
			m_size--;
			m_Data[m_size].~T();
		}
	}
	void Clear() {
		for (int i = 0; i < m_size; ++i) {
			m_Data[i].~T();
		}
		m_size = 0;
	}
	void PushBack(const T& value) {
		if (m_size >= m_Capacity) {
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_size] = value;
		m_size++;
	}
	void PushBack(T&& value) {
		if (m_size >= m_Capacity) {
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_size] = std::move(value);
		m_size++;
	}

	template<typename... Args>
	void  EmplaceBack(Args&&... args) {
		if (m_size >= m_Capacity) {
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		new(&m_Data[m_size]) T(std::forward<Args>(args)...);
		m_size++;
	}

	[[nodiscard]] size_t size() const { return m_size; }
	const T& operator[] (size_t index) const {
		if (index >= m_size || index < 0) {
			std::cout << "Out of bounds" << std::endl;
		}
		return m_Data[index];
	}
	T& operator[] (size_t index) {
		if (index >= m_size || index < 0) {
			std::cout << "Out of bounds" << std::endl;
		}
		return m_Data[index];
	}
	[[nodiscard]] const T* begin() const {
		return m_Data;
	}
	T* begin() {
		return m_Data;
	}
	[[nodiscard]] const T* end() const {
		return (m_Data + m_size);
	}
	const T* end() {
		return (m_Data + m_size);
	}
private:
	void ReAlloc(size_t newCapacity) {
		/// 1. allocate a new block of memory
		/// 2. copy/move old elements into new block
		/// 3. Delete

		T* newBlock = new T[newCapacity];

		if (newCapacity < m_size) {
			m_size = newCapacity;
		}
		for (size_t i = 0; i < m_size; ++i) {
			newBlock[i] = std::move(m_Data[i]);
		}
		delete[] m_Data;
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}
private:
	T* m_Data = nullptr;
	size_t m_size = 0;
	size_t m_Capacity = 0;
};

class Vector3 {
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
	Vector3() = default;
	explicit Vector3(float scaler)
		:x(scaler), y(scaler), z(scaler) {}
	Vector3(float x, float y, float z)
		:x(x), y(y), z(z) {}

	Vector3(const Vector3& other) = default;
	Vector3(Vector3&& other)noexcept
		:x(other.x), y(other.y), z(other.z) {
	}
	~Vector3() = default;
	Vector3& operator=(const Vector3& other) = default;
	Vector3& operator=(Vector3&& other) noexcept {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};
template<typename T>
void print(const Vector<T>& vector) {
	for (auto& v : vector) {
		std::cout << v << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
}
template<>
void print(const Vector<Vector3>& vector) {
	for (auto& v : vector) {
		std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
}
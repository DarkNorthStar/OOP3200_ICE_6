#pragma once
#ifndef __VECTOR3D__
#define __VECTOR3D__

#include <string>
#include <iostream>
#include "Vector2D.h"
#include <cassert>

template <class T>
class Vector3D
{
public:
	Vector3D(T x = static_cast<T>(0.0), T y = static_cast<T>(0.0), T z = static_cast<T>(0.0));
	Vector3D(const std::string& x, const std::string& y, const std::string& z);
	Vector3D(const Vector2D<float>& vector_2d);
	~Vector3D();

	// accessors
	T GetX() const;
	T GetY() const;
	T GetZ() const;

	// mutators
	void setX(const T x);
	void setY(const T y);
	void setZ(const T z);
	void set(const T x, const T y, const T z);

	// input/output operator overloads
	friend std::ostream& operator<<(std::ostream& out, const Vector3D& rhs)
	{
		out << rhs.ToString();
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Vector3D& rhs)
	{
		in >> rhs.m_x;
		in.ignore();
		in >> rhs.m_y;
		in.ignore();
		in >> rhs.m_z;

		return in;
	}

	std::string ToString() const;
	
private:
	T m_x;
	T m_y;
	T m_z;
};

/* Implementation Section */

template <class T>
Vector3D<T>::Vector3D(const T x, const T y, const T z) : m_x(x), m_y(y), m_z(z)
{
}

template <class T>
Vector3D<T>::Vector3D(const std::string& x, const std::string& y, const std::string& z)
{
	if(typeid(T) == typeid(int))
	{
		m_x = std::stoi(x);
		m_y = std::stoi(y);
		m_z = std::stoi(z);
	}

	if (typeid(T) == typeid(float))
	{
		m_x = std::stof(x);
		m_y = std::stof(y);
		m_z = std::stof(z);
	}

	if (typeid(T) == typeid(double))
	{
		m_x = std::stod(x);
		m_y = std::stod(y);
		m_z = std::stod(z);
	}

	assert((typeid(T) == typeid(double)) || (typeid(T) == typeid(float)) || (typeid(T) == typeid(int)), 
		"error encountered");

}

template <class T>
Vector3D<T>::Vector3D(const Vector2D<float>& vector_2d)
{
	m_x = static_cast<T>(vector_2d.GetX());
	m_y = static_cast<T>(vector_2d.GetY());
	m_z = static_cast<T>(0.0);
}

template <class T>
Vector3D<T>::~Vector3D()
{}

template <class T>
T Vector3D<T>::GetX() const
{
	return m_x;
}

template <class T>
T Vector3D<T>::GetY() const
{
	return m_y;
}

template <class T>
T Vector3D<T>::GetZ() const
{
	return m_z;
}

template <class T>
void Vector3D<T>::setX(const T x)
{
	m_x = x;
}

template <class T>
void Vector3D<T>::setY(const T y)
{
	m_y = y;
}

template <class T>
void Vector3D<T>::setZ(const T z)
{
	m_z = z;
}

template <class T>
void Vector3D<T>::set(const T x, const T y, const T z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

template <class T>
std::string Vector3D<T>::ToString() const
{
	return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ", " + std::to_string(m_z) + ")";
}

#endif /* defined (__VECTOR3D__) */


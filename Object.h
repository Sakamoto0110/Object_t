#pragma once
#include "Primitives.h"

typedef class OBJECT_t
{
	union
	{
		Byte uByte;
		Int uInt;
		Uint uUint;
		Double uDouble;
		LPVoid uPtr;
	};

	enum TYPE_e
	{
		eNullobj = 0,
		eByte,
		eInt,
		eUint,
		eDouble,
		eLPVoid,
	};

public:
	Byte type;
	bool valid;

	inline OBJECT_t()
	{
		*this = 0;
		this->type = 0;
		this->valid = false;
	}
	
	inline bool IsEquals(OBJECT_t other)
	{
		if(this->type == other.type)
		{
			switch(this->type)
			{
			case eByte: return (Byte)*this == (Byte)other;
			case eInt: return (Int)*this == (Int)other;
			case eUint: return (Uint)*this == (Uint)other;
			case eDouble: return (Double)*this == (Double)other;
			case eLPVoid: return (LPVoid)*this == (LPVoid)other;
			}
		}
		return false;
	}
	// Implicit type casts
	// * * *
	// ReSharper disable CppNonExplicitConvertingConstructor
	// ReSharper disable CppNonExplicitConversionOperator
	
	// * * *
	inline OBJECT_t(const int v) : uInt(v), type(eInt), valid(true) { }
	inline operator int() const { return uInt; }


	bool IsValid() const
	{
		return valid;
	}

	OBJECT_t& operator=(const OBJECT_t obj)
	{
		switch (obj.type)
		{
		case eByte: return *this = static_cast<Byte>(obj);
		case eInt: return *this = static_cast<Int>(obj);
		case eUint: return *this = static_cast<Uint>(obj);
		case eDouble: return *this = static_cast<Double>(obj);
		case eLPVoid: return *this = static_cast<LPVoid>(obj);
		}
		return *this;
	}

	OBJECT_t& operator=(const Byte v)
	{
		this->uByte = v;
		this->type = eByte;
		this->valid = true;
		return *this;
	}

	OBJECT_t& operator=(const Int v)
	{
		this->uInt = v;
		this->type = eInt;
		this->valid = true;
		return *this;
	}

	OBJECT_t& operator=(const Uint v)
	{
		this->uUint = v;
		this->type = eUint;
		this->valid = true;
		return *this;
	}

	OBJECT_t& operator=(const Double v)
	{
		this->uDouble = v;
		this->type = eDouble;
		this->valid = true;
		return *this;
	}

	OBJECT_t& operator=(const LPVoid v)
	{
		this->uPtr = v;
		this->type = eLPVoid;
		this->valid = true;
		return *this;
	}

	


	OBJECT_t(const Byte v) : uByte(v), type(eByte), valid(true) { }             // NOLINT(cppcoreguidelines-pro-type-member-init)
	operator Byte() const { return uByte; }
	//
	// * * * * *
	//
	//OBJECT_t::OBJECT_t(const int v) : uInt(v), type(eInt), valid(true) { }                // NOLINT(cppcoreguidelines-pro-type-member-init)
	//OBJECT_t::operator int() const { return uInt; }
	//
	// * * * * *
	//
	OBJECT_t(const Uint v) : uUint(v), type(eUint), valid(true) { }             // NOLINT(cppcoreguidelines-pro-type-member-init)
	operator Uint() const { return uUint; }
	//
	// * * * * *
	//
	OBJECT_t(const Double v) : uDouble(v), type(eDouble), valid(true) { }       // NOLINT(cppcoreguidelines-pro-type-member-init)
	operator Double() const { return uDouble; }
	//
	// * * * * *
	//
	OBJECT_t(LPVoid v) : uPtr(v), type(eLPVoid), valid(true) { }                // NOLINT(cppcoreguidelines-pro-type-member-init)
	operator LPVoid () const { return uPtr; }
	//
	// * * * * *
	//
	//OBJECT_t(LPChar v) : uCharPtr(v), type(eLPChar), valid(true) { }            // NOLINT(cppcoreguidelines-pro-type-member-init)
	//operator LPChar () const { return uCharPtr; }
	////
	//// * * * * *
	////
	//OBJECT_t(LPCChar v) : uCcharPtr(v), type(eLPCChar), valid(true) { }         // NOLINT(cppcoreguidelines-pro-type-member-init)
	//operator LPCChar () const { return uCcharPtr; }
	
	// * * *
	template<typename T> 
	operator T&() { return *((T*)uPtr); }
	//template<typename T> inline operator T* () { return (T*)_ptr; }
	// * * *
	// ReSharper restore CppNonExplicitConvertingConstructor
	// ReSharper restore CppNonExplicitConversionOperator
}Object;


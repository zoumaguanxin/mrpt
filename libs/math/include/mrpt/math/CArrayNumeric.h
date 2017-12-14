/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */
#pragma once

#include <mrpt/math/types_math.h>  // Eigen
#include <mrpt/typemeta/TTypeName.h>

namespace mrpt
{
namespace math
{
/** CArrayNumeric is an array for numeric types supporting several mathematical
 * operations (actually, just a wrapper on Eigen::Matrix<T,N,1>)
  * \sa CArrayFloat, CArrayDouble, CArray
  */
template <typename T, std::size_t N>
class CArrayNumeric : public Eigen::Matrix<T, N, 1>
{
   public:
	typedef T value_type;
	typedef Eigen::Matrix<T, N, 1> Base;

	/** Default constructor */
	CArrayNumeric() {}
	/** Constructor from initial values ptr[0]-ptr[N-1] */
	CArrayNumeric(const T* ptr) : Eigen::Matrix<T, N, 1>(ptr) {}

	/** Initialization from a vector-like source, that is, anything implementing
	 * operator[]. */
	template <class ARRAYLIKE>
	explicit CArrayNumeric(const ARRAYLIKE& obj) : Eigen::Matrix<T, N, 1>(obj)
	{
	}

	template <typename OtherDerived>
	inline CArrayNumeric<T, N>& operator=(
		const Eigen::MatrixBase<OtherDerived>& other)
	{
		Base::operator=(other);
		return *this;
	}
};

// --------------  Partial specializations of CArrayNumeric -----------

/** A partial specialization of CArrayNumeric for float numbers.
  * \sa CArrayNumeric, CArray */
template <std::size_t N>
class CArrayFloat : public CArrayNumeric<float, N>
{
   public:
	typedef CArrayNumeric<float, N> Base;
	typedef CArrayFloat<N> mrpt_autotype;

	/** Default constructor */
	CArrayFloat() {}
	/** Constructor from initial values ptr[0]-ptr[N-1] */
	CArrayFloat(const float* ptr) : CArrayNumeric<float, N>(ptr) {}

	/** Initialization from a vector-like source, that is, anything implementing
	 * operator[]. */
	template <class ARRAYLIKE>
	explicit CArrayFloat(const ARRAYLIKE& obj) : CArrayNumeric<float, N>(obj)
	{
	}
	MRPT_EIGEN_DERIVED_CLASS_CTOR_OPERATOR_EQUAL(CArrayFloat)  // Implements
	// ctor and
	// "operator ="
	// for any other
	// Eigen class
};

/** A partial specialization of CArrayNumeric for double numbers.
  * \sa CArrayNumeric, CArray */
template <std::size_t N>
class CArrayDouble : public CArrayNumeric<double, N>
{
   public:
	typedef CArrayNumeric<double, N> Base;
	typedef CArrayDouble<N> mrpt_autotype;

	/** Default constructor */
	CArrayDouble() {}
	/** Constructor from initial values ptr[0]-ptr[N-1] */
	CArrayDouble(const double* ptr) : CArrayNumeric<double, N>(ptr) {}

	/** Initialization from a vector-like source, that is, anything implementing
	 * operator[]. */
	template <class ARRAYLIKE>
	explicit CArrayDouble(const ARRAYLIKE& obj) : CArrayNumeric<double, N>(obj)
	{
	}
	MRPT_EIGEN_DERIVED_CLASS_CTOR_OPERATOR_EQUAL(CArrayDouble)  // Implements
	// ctor and
	// "operator ="
	// for any other
	// Eigen class
};

/** A partial specialization of CArrayNumeric for int numbers.
  * \sa CArrayNumeric, CArray */
template <std::size_t N>
class CArrayInt : public CArrayNumeric<int, N>
{
   public:
	typedef CArrayNumeric<int, N> Base;
	typedef CArrayInt<N> mrpt_autotype;

	/** Default constructor */
	CArrayInt() {}
	/** Constructor from initial values ptr[0]-ptr[N-1] */
	CArrayInt(const int* ptr) : CArrayNumeric<int, N>(ptr) {}
	MRPT_EIGEN_DERIVED_CLASS_CTOR_OPERATOR_EQUAL(CArrayInt)  // Implements ctor
	// and "operator ="
	// for any other
	// Eigen class
};

/** A partial specialization of CArrayNumeric for unsigned int numbers.
  * \sa CArrayNumeric, CArray */
template <std::size_t N>
class CArrayUInt : public CArrayNumeric<unsigned int, N>
{
   public:
	typedef CArrayNumeric<unsigned int, N> Base;
	typedef CArrayUInt<N> mrpt_autotype;

	/** Default constructor */
	CArrayUInt() {}
	/** Constructor from initial values ptr[0]-ptr[N-1] */
	CArrayUInt(const unsigned int* ptr) : CArrayNumeric<unsigned int, N>(ptr) {}
	MRPT_EIGEN_DERIVED_CLASS_CTOR_OPERATOR_EQUAL(CArrayUInt)  // Implements ctor
	// and "operator
	// =" for any
	// other Eigen
	// class
};

}  // End of namespace

namespace typemeta
{
// Extensions to mrpt::typemeta::TTypeName for matrices:
template <typename T, size_t N>
struct TTypeName<mrpt::math::CArrayNumeric<T, N>>
{
	constexpr static auto get()
	{
		return literal("CArrayNumeric<") + TTypeName<T>::get() +
			literal(",") + literal(num_to_string<N>::value) + literal(">");
	}
};
template <size_t N>
struct TTypeName<mrpt::math::CArrayDouble<N>>
{
	constexpr static auto get()
	{
		return literal("CArrayDouble<") + literal(num_to_string<N>::value) + literal(">");
	}
};
template <size_t N>
struct TTypeName<mrpt::math::CArrayFloat<N>>
{
	constexpr static auto get()
	{
		return literal("CArrayFloat<") + literal(num_to_string<N>::value) + literal(">");
	}
};
}
}  // End of namespace

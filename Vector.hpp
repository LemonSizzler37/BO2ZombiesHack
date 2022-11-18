#pragma once

#include <sstream>

struct Vec3
{
public:
	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		x = ix; y = iy; z = iz;
	}

	bool operator==(const Vec3& src) const
	{
		return (src.x == x) && (src.y == y) && (src.z == z);
	}
	bool operator!=(const Vec3& src) const
	{
		return (src.x != x) || (src.y != y) || (src.z != z);
	}

	Vec3& operator+=(const Vec3& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	Vec3& operator-=(const Vec3& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}
	Vec3& operator*=(float fl)
	{
		x *= fl;
		y *= fl;
		z *= fl;
		return *this;
	}
	Vec3& operator*=(const Vec3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}
	Vec3& operator/=(const Vec3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}
	Vec3& operator+=(float fl)
	{
		x += fl;
		y += fl;
		z += fl;
		return *this;
	}
	Vec3& operator/=(float fl)
	{
		x /= fl;
		y /= fl;
		z /= fl;
		return *this;
	}
	Vec3& operator-=(float fl)
	{
		x -= fl;
		y -= fl;
		z -= fl;
		return *this;
	}

	Vec3 operator*(float fl) const
	{
		return { x * fl, y * fl, z * fl };
	}

	Vec3 operator/(float fl) const
	{
		return { x / fl, y / fl, z / fl };
	}

	Vec3 operator+(float fl) const
	{
		return { x + fl, y + fl, z + fl };
	}

	Vec3 operator-(float fl) const
	{
		return { x - fl, y - fl, z - fl };
	}

	Vec3 operator+(Vec3 fl) const
	{
		return { x + fl.x, y + fl.y, z + fl.z };
	}

	Vec3 operator-(Vec3 fl) const
	{
		return { x - fl.x, y - fl.y, z - fl.z };
	}

	void NormalizeInPlace()
	{
		*this = Normalized();
	}
	Vec3 Normalized() const
	{
		Vec3 res = *this;
		float l = res.Length();
		if (l != 0.0f) {
			res /= l;
		}
		else {
			res.x = res.y = res.z = 0.0f;
		}
		return res;
	}

	float DistTo(const Vec3& vOther) const
	{
		Vec3 delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;

		return delta.Length();
	}
	float DistToSqr(const Vec3& vOther) const
	{
		Vec3 delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;

		return delta.LengthSqr();
	}
	float Dot(const Vec3& vOther) const
	{
		return (x * vOther.x + y * vOther.y + z * vOther.z);
	}
	float Length() const
	{
		return sqrt(x * x + y * y + z * z);
	}
	float LengthSqr(void) const
	{
		return (x * x + y * y + z * z);
	}
	float Length2D() const
	{
		return sqrt(x * x + y * y);
	}

	void Normalize()
	{
		while (y > 180) y -= 360;
		while (y < -180) y += 360;
		if (x > 89) x = 89;
		if (x < -89) x = -89;
	}

	float x, y, z;
};

typedef float vec_t;
// 3D Vector4D
struct Vec4
{
	vec_t x, y, z, w;

	bool operator==(const Vec4& v) const;
	bool operator!=(const Vec4& v) const;

	// arithmetic operations
	Vec4& operator+=(const Vec4& v)
	{
		x += v.x; y += v.y; z += v.z; w += v.w;
		return *this;
	}

	Vec4& operator-=(const Vec4& v)
	{
		x -= v.x; y -= v.y; z -= v.z; w -= v.w;
		return *this;
	}

	Vec4& operator*=(float fl)
	{
		x *= fl;
		y *= fl;
		z *= fl;
		w *= fl;
		return *this;
	}

	Vec4& operator*=(const Vec4& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return *this;
	}

	Vec4& operator/=(const Vec4& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		w /= v.w;
		return *this;
	}

	// this ought to be an opcode.
	Vec4& operator+=(float fl)
	{
		x += fl;
		y += fl;
		z += fl;
		w += fl;
		return *this;
	}

	// this ought to be an opcode.
	Vec4& operator/=(float fl)
	{
		x /= fl;
		y /= fl;
		z /= fl;
		w /= fl;
		return *this;
	}
	Vec4& operator-=(float fl)
	{
		x -= fl;
		y -= fl;
		z -= fl;
		w -= fl;
		return *this;
	}

	// negate the vector components
	void Negate();

	// Get the vector's magnitude.
	vec_t Length() const;

	// Get the vector's magnitude squared.
	vec_t LengthSqr(void) const
	{
		return (x * x + y * y + z * z);
	}

	// return true if this vector is (0,0,0) within tolerance
	bool IsZero(float tolerance = 0.01f) const
	{
		return (x > -tolerance && x < tolerance&&
			y > -tolerance && y < tolerance&&
			z > -tolerance && z < tolerance&&
			w > -tolerance && w < tolerance);
	}

	vec_t NormalizeInPlace();
	Vec4 Normalized() const;
	bool IsLengthGreaterThan(float val) const;
	bool IsLengthLessThan(float val) const;

	// check if a vector is within the box defined by two other vectors
	bool WithinAABox(Vec4 const& boxmin, Vec4 const& boxmax);

	// Get the distance from this vector to the other one.
	vec_t DistTo(const Vec4& vOther) const;

	// Get the distance from this vector to the other one squared.
	// NJS: note, VC wasn't inlining it correctly in several deeply nested inlines due to being an 'out of line' .  
	// may be able to tidy this up after switching to VC7
	vec_t DistToSqr(const Vec4& vOther) const
	{
		Vec4 delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;
		delta.w = w - vOther.w;

		return delta.LengthSqr();
	}

	// Copy
	void CopyToArray(float* rgfl) const;

	// Multiply, add, and assign to this (ie: *this = a + b * scalar). This
	// is about 12% faster than the actual vector equation (because it's done per-component
	// rather than per-vector).
	void MulAdd(const Vec4& a, const Vec4& b, float scalar);

	// Dot product.
	vec_t Dot(const Vec4& vOther) const;

	// assignment
	Vec4& operator=(const Vec4& vOther);

	// 2d
	vec_t Length2D(void) const;
	vec_t Length2DSqr(void) const;

	/// Get the component of this vector parallel to some other given vector
	Vec4  ProjectOnto(const Vec4& onto);

	// copy constructors
	// Vector4D(const Vector4D &vOther);

	// arithmetic operations
	Vec4 operator-(void) const;

	Vec4 operator+(const Vec4& v) const;
	Vec4 operator-(const Vec4& v) const;
	Vec4 operator*(const Vec4& v) const;
	Vec4 operator/(const Vec4& v) const;
	Vec4 operator*(float fl) const;
	Vec4 operator/(float fl) const;

	// Returns a vector with the min or max in X, Y, and Z.
	Vec4 Min(const Vec4& vOther) const;
	Vec4 Max(const Vec4& vOther) const;
};

struct Vec2
{
	float x, y;

	Vec2& operator+=(const Vec2& v)
	{
		x += v.x; y += v.y;
		return *this;
	}
	Vec2& operator-=(const Vec2& v)
	{
		x -= v.x; y -= v.y;
		return *this;
	}
	Vec2& operator*=(float fl)
	{
		x *= fl;
		y *= fl;
		return *this;
	}
	Vec2& operator*=(const Vec2& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}
	Vec2& operator/=(const Vec2& v)
	{
		x /= v.x;
		y /= v.y;
		return *this;
	}
	Vec2& operator+=(float fl)
	{
		x += fl;
		y += fl;
		return *this;
	}
	Vec2& operator/=(float fl)
	{
		x /= fl;
		y /= fl;
		return *this;
	}
	Vec2& operator-=(float fl)
	{
		x -= fl;
		y -= fl;
		return *this;
	}

	Vec2 operator*(float fl) const
	{
		return { x * fl, y * fl };
	}

	Vec2 operator/(float fl) const
	{
		return { x / fl, y / fl };
	}

	Vec2 operator+(float fl) const
	{
		return { x + fl, y + fl };
	}

	Vec2 operator-(float fl) const
	{
		return { x - fl, y - fl };
	}

	Vec2 operator+(Vec2 fl) const
	{
		return { x + fl.x, y + fl.y };
	}

	Vec2 operator-(Vec2 fl) const
	{
		return { x - fl.x, y - fl.y };
	}
};

class __declspec(align(16)) VectorAligned : public Vec3
{
public:
	inline VectorAligned(void) {};
	inline VectorAligned(float X, float Y, float Z)
	{
		Init(X, Y, Z);
	}

public:
	explicit VectorAligned(const Vec3& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
	}

	VectorAligned& operator=(const Vec3& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
		return *this;
	}

	VectorAligned& operator=(const VectorAligned& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
		return *this;
	}

	float w = 0;
};
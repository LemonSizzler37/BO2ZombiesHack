#pragma once

#include "Vector.hpp"
#include <math.h>

struct QAngle
{
public:
	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		pitch = ix; yaw = iy; roll = iz;
	}

	bool operator==(const QAngle& src) const
	{
		return (src.pitch == pitch) && (src.yaw == yaw) && (src.roll == roll);
	}
	bool operator!=(const QAngle& src) const
	{
		return (src.pitch != pitch) || (src.yaw != yaw) || (src.roll != roll);
	}

	QAngle& operator+=(const QAngle& v)
	{
		pitch += v.pitch; yaw += v.yaw; roll += v.roll;
		return *this;
	}
	QAngle& operator-=(const QAngle& v)
	{
		pitch -= v.pitch; yaw -= v.yaw; roll -= v.roll;
		return *this;
	}
	QAngle& operator*=(float fl)
	{
		pitch *= fl;
		yaw *= fl;
		roll *= fl;
		return *this;
	}
	QAngle& operator*=(const QAngle& v)
	{
		pitch *= v.pitch;
		yaw *= v.yaw;
		roll *= v.roll;
		return *this;
	}
	QAngle& operator/=(const QAngle& v)
	{
		pitch /= v.pitch;
		yaw /= v.yaw;
		roll /= v.roll;
		return *this;
	}
	QAngle& operator+=(float fl)
	{
		pitch += fl;
		yaw += fl;
		roll += fl;
		return *this;
	}
	QAngle& operator/=(float fl)
	{
		pitch /= fl;
		yaw /= fl;
		roll /= fl;
		return *this;
	}
	QAngle& operator-=(float fl)
	{
		pitch -= fl;
		yaw -= fl;
		roll -= fl;
		return *this;
	}

	QAngle operator*(float fl) const
	{
		return { pitch * fl, yaw * fl, roll * fl };
	}

	QAngle operator/(float fl) const
	{
		return { pitch / fl, yaw / fl, roll / fl };
	}

	QAngle operator+(QAngle fl) const
	{
		return { pitch + fl.pitch, yaw + fl.yaw, roll + fl.roll };
	}

	QAngle operator-(QAngle fl) const
	{
		return { pitch - fl.pitch, yaw - fl.yaw, roll - fl.roll };
	}

	void NormalizeInPlace()
	{
		*this = Normalized();
	}
	QAngle Normalized() const
	{
		QAngle res = *this;
		float l = res.Length();
		if (l != 0.0f) {
			res /= l;
		}
		else {
			res.pitch = res.yaw = res.roll = 0.0f;
		}
		return res;
	}

	float DistTo(const QAngle& vOther) const
	{
		QAngle delta;

		delta.pitch = pitch - vOther.pitch;
		delta.yaw = yaw - vOther.yaw;
		delta.roll = roll - vOther.roll;

		return delta.Length();
	}
	float DistToSqr(const QAngle& vOther) const
	{
		QAngle delta;

		delta.pitch = pitch - vOther.pitch;
		delta.yaw = yaw - vOther.yaw;
		delta.roll = roll - vOther.roll;

		return delta.LengthSqr();
	}
	float Dot(const QAngle& vOther) const
	{
		return (pitch * vOther.pitch + yaw * vOther.yaw + roll * vOther.roll);
	}
	float Length() const
	{
		return sqrt(pitch * pitch + yaw * yaw + roll * roll);
	}
	float LengthSqr(void) const
	{
		return (pitch * pitch + yaw * yaw + roll * roll);
	}
	float Length2D() const
	{
		return sqrt(pitch * pitch + yaw * yaw);
	}

	void Normalize()
	{
		while (yaw > 180) yaw -= 360;
		while (yaw < -180) yaw += 360;
		if (pitch > 89) pitch = 89;
		if (pitch < -89) pitch = -89;
	}

	float pitch, yaw, roll;
};